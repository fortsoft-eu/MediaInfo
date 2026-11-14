/**
 * This is open-source software licensed under the terms of the MIT License.
 *
 * Copyright (c) 2026 Petr Červinka - FortSoft <cervinka@fortsoft.eu>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **
 * Last modified for version 1.2.1.8
 */

#include "PngWriter.h"

/// Retains the output handle and initializes the PNG CRC32 lookup table.
PngWriter::PngWriter(HANDLE output) : file(output) {
    for (DWORD index = 0; index < 256; ++index) {
        DWORD value = index;
        for (int bit = 0; bit < 8; ++bit) {
            value = value & 1 ? value >> 1 ^ 0xEDB88320 : value >> 1;
        }
        crcTable[index] = value;
    }
}

/// Stores a 32-bit value in big-endian byte order.
void PngWriter::BigEndian(BYTE* output, DWORD value) {
    output[0] = static_cast<BYTE>(value >> 24);
    output[1] = static_cast<BYTE>(value >> 16);
    output[2] = static_cast<BYTE>(value >> 8);
    output[3] = static_cast<BYTE>(value);
}

/// Updates a CRC32 accumulator using the precomputed PNG lookup table.
DWORD PngWriter::Crc(DWORD crc, const BYTE* data, DWORD length) const {
    for (DWORD index = 0; index < length; ++index) {
        crc = crcTable[(crc ^ data[index]) & 0xFF] ^ crc >> 8;
    }
    return crc;
}

/// Writes the complete buffer, handling partial writes and propagating failures.
bool PngWriter::Write(const void* data, DWORD length) {
    const BYTE* cursor = static_cast<const BYTE*>(data);
    while (length) {
        DWORD written = 0;
        if (!WriteFile(file, cursor, length, &written, NULL) || !written) {
            return false;
        }
        cursor += written;
        length -= written;
    }
    return true;
}

/// Writes one PNG chunk with its big-endian length and CRC32 checksum.
bool PngWriter::Chunk(const char* type, const BYTE* data, DWORD length) {
    BYTE header[8];
    BYTE checksum[4];
    BigEndian(header, length);
    for (int index = 0; index < 4; ++index) {
        header[index + 4] = static_cast<BYTE>(type[index]);
    }
    BigEndian(checksum, Crc(Crc(0xFFFFFFFF, header + 4, 4), data, length) ^ 0xFFFFFFFF);
    return Write(header, sizeof(header)) && Write(data, length) && Write(checksum, sizeof(checksum));
}

/// Streams RGB scanlines through stored DEFLATE blocks with a bounded working buffer.
bool PngWriter::Encode(const BYTE* pixels, int width, const RECT& crop) {
    const BYTE signature[] = { 137, 80, 78, 71, 13, 10, 26, 10 };
    const BYTE zlibHeader[] = { 0x78, 0x01 };
    BYTE info[13] = {};
    BigEndian(info, crop.right - crop.left);
    BigEndian(info + 4, crop.bottom - crop.top);
    info[8] = 8;
    info[9] = 2;
    if (!Write(signature, sizeof(signature)) || !Chunk("IHDR", info, sizeof(info)) ||
        !Chunk("IDAT", zlibHeader, sizeof(zlibHeader))) {
        return false;
    }
    BYTE* block = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), 0, 65540));
    if (!block) {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return false;
    }
    DWORD a = 1;
    DWORD b = 0;
    DWORD count = 0;
    DWORD rowLength = static_cast<DWORD>(crop.right - crop.left) * 3 + 1;
    bool success = true;
    for (int y = crop.top; y < crop.bottom && success; ++y) {
        const BYTE* source = pixels + static_cast<DWORD>(y) * width * 4 + crop.left * 4;
        for (DWORD column = 0; column < rowLength; ++column) {
            BYTE value = 0;
            if (column) {
                DWORD channel = (column - 1) % 3;
                value = source[(column - 1) / 3 * 4 + 2 - channel];
            }
            block[5 + count++] = value;
            a += value;
            if (a >= 65521) {
                a -= 65521;
            }
            b += a;
            if (b >= 65521) {
                b -= 65521;
            }
            bool last = y == crop.bottom - 1 && column == rowLength - 1;
            if (count == 65535 || last) {
                block[0] = last ? 1 : 0;
                block[1] = static_cast<BYTE>(count);
                block[2] = static_cast<BYTE>(count >> 8);
                block[3] = static_cast<BYTE>(~count);
                block[4] = static_cast<BYTE>(~count >> 8);
                success = Chunk("IDAT", block, count + 5);
                count = 0;
                if (!success) {
                    break;
                }
            }
        }
    }
    DWORD error = GetLastError();
    HeapFree(GetProcessHeap(), 0, block);
    if (!success) {
        SetLastError(error);
        return false;
    }
    BYTE adler[4];
    BigEndian(adler, b << 16 | a);
    return Chunk("IDAT", adler, sizeof(adler)) && Chunk("IEND", NULL, 0);
}

/// Writes a validated image crop and replaces the destination only after complete encoding.
bool PngWriter::Save(const wchar_t* path, const BYTE* pixels, int width, int height, const RECT& crop) {
    if (!pixels
            || width <= 0
            || height <= 0
            || width > 0x7FFFFFFF / 4
            || static_cast<DWORD>(height) > 0x7FFFFFFFUL / (static_cast<DWORD>(width) * 4)
            || crop.left < 0
            || crop.top < 0
            || crop.right > width
            || crop.bottom > height
            || IsRectEmpty(&crop)) {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }
    wchar_t absolute[MAX_PATH];
    DWORD length = GetFullPathNameW(path, MAX_PATH, absolute, NULL);
    if (!length || length >= MAX_PATH) {
        SetLastError(ERROR_FILENAME_EXCED_RANGE);
        return false;
    }
    wchar_t directory[MAX_PATH];
    lstrcpyW(directory, absolute);
    while (length && directory[length - 1] != L'\\') {
        --length;
    }
    directory[length] = 0;
    wchar_t temporary[MAX_PATH];
    if (!GetTempFileNameW(directory, L"FSH", 0, temporary)) {
        return false;
    }
    HANDLE output = CreateFileW(temporary, GENERIC_WRITE, 0,
        NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    bool success = false;
    if (output != INVALID_HANDLE_VALUE) {
        PngWriter writer(output);
        success = writer.Encode(pixels, width, crop);
    }
    DWORD error = GetLastError();
    if (output != INVALID_HANDLE_VALUE && !CloseHandle(output)) {
        if (success) {
            error = GetLastError();
        }
        success = false;
    }
    if (success) {
        success = MoveFileExW(temporary, absolute, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)
            != FALSE;
        error = GetLastError();
    }
    if (!success) {
        DeleteFileW(temporary);
        SetLastError(error);
    }
    return success;
}
