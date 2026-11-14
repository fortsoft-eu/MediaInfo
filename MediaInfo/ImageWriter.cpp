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

#include "Localization.h"
#include "ImageWriter.h"
#include "PngWriter.h"
#include "JpegEncoder.h"
#include "WebpEncoder.h"

/// Buffers GIF data sub-blocks, packed LZW codes and the output status.
struct GifWriter {
    HANDLE file;
    BYTE block[255];
    DWORD packed;
    int bits;
    int count;
    bool success;
};

/// Maps one exact RGB color to its GIF palette index.
struct GifColor {
    DWORD color;
    BYTE index;
};

/// Defines the TIFF directory layout and the start of its auxiliary values.
static const WORD tiffTagCount = 14;
static const DWORD tiffValuesOffset = 8 + 2 + tiffTagCount * 12 + 4;

/// Stores the source diagnostics resolved through application-specific localization.
static const wchar_t* imageErrors[] = {
    L"The PNG image could not be saved. Check the destination and available memory and disk space.",
    L"GIF export failed. Exact GIF output requires at most 256 colors.",
    L"JPEG export failed. A working GDI+ JPEG encoder is required.",
    L"The BMP image could not be saved. Check the destination and available memory and disk space.",
    L"The TIFF image could not be saved. Check the destination and available memory and disk space.",
    L"The WebP image could not be saved. Check the destination and available memory and disk space."
};

/// Writes the complete image-output buffer, handling partial writes and propagating file errors.
static bool WriteBytes(HANDLE file, const void* data, DWORD bytes) {
    const BYTE* cursor = static_cast<const BYTE*>(data);
    while (bytes) {
        DWORD written = 0;
        if (!WriteFile(file, cursor, bytes, &written, nullptr) || !written) {
            return false;
        }
        cursor += written;
        bytes -= written;
    }
    return true;
}

/// Stores a 16-bit value in little-endian byte order.
static void LittleEndian16(BYTE* output, WORD value) {
    output[0] = static_cast<BYTE>(value);
    output[1] = static_cast<BYTE>(value >> 8);
}

/// Stores a 32-bit value in little-endian byte order.
static void LittleEndian32(BYTE* output, DWORD value) {
    LittleEndian16(output, static_cast<WORD>(value));
    LittleEndian16(output + 2, static_cast<WORD>(value >> 16));
}

/// Writes the rendered report as an uncompressed 24-bit Windows bitmap.
static bool WriteBmp(HANDLE file, const BYTE* pixels, int width, int height, int dpiX, int dpiY) {
    DWORD stride = width * 3 + 3 & ~3UL;
    BITMAPFILEHEADER header = BITMAPFILEHEADER{};
    BITMAPINFOHEADER info = BITMAPINFOHEADER{};
    header.bfType = 0x4D42;
    header.bfOffBits = sizeof(header) + sizeof(info);
    header.bfSize = header.bfOffBits + stride * height;
    info.biSize = sizeof(info);
    info.biWidth = width;
    info.biHeight = height;
    info.biPlanes = 1;
    info.biBitCount = 24;
    info.biCompression = BI_RGB;
    info.biSizeImage = stride * height;
    info.biXPelsPerMeter = MulDiv(dpiX, 10000, 254);
    info.biYPelsPerMeter = MulDiv(dpiY, 10000, 254);
    BYTE* row = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, stride));
    if (!row) {
        return false;
    }
    bool success = WriteBytes(file, &header, sizeof(header)) && WriteBytes(file, &info, sizeof(info));
    for (int y = height - 1; y >= 0 && success; --y) {
        const BYTE* source = pixels + static_cast<SIZE_T>(y) * width * 4;
        for (int x = 0; x < width; ++x) {
            row[x * 3] = source[x * 4];
            row[x * 3 + 1] = source[x * 4 + 1];
            row[x * 3 + 2] = source[x * 4 + 2];
        }
        success = WriteBytes(file, row, stride);
    }
    HeapFree(GetProcessHeap(), 0, row);
    return success;
}

/// Appends one little-endian TIFF directory entry and advances the output pointer.
static void TiffEntry(BYTE*& entry, WORD tag, WORD type, DWORD count, DWORD value) {
    LittleEndian16(entry, tag);
    LittleEndian16(entry + 2, type);
    LittleEndian32(entry + 4, count);
    LittleEndian32(entry + 8, value);
    entry += 12;
}

/// Writes the rendered report as an uncompressed RGB TIFF with its physical resolution.
static bool WriteTiff(HANDLE file, const BYTE* pixels, int width, int height, int dpiX, int dpiY) {
    DWORD rowSize = width * 3;
    DWORD rowsPerStrip = 8192 / rowSize;
    if (!rowsPerStrip) {
        rowsPerStrip = 1;
    }
    DWORD stripCount = (height + rowsPerStrip - 1) / rowsPerStrip;
    DWORD tablesSize = stripCount > 1 ? stripCount * 8 : 0;
    DWORD dataOffset = tiffValuesOffset + 22 + tablesSize;
    BYTE* header = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dataOffset));
    BYTE* row = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), 0, rowSize));
    if (!header || !row) {
        if (header) {
            HeapFree(GetProcessHeap(), 0, header);
        }
        if (row) {
            HeapFree(GetProcessHeap(), 0, row);
        }
        return false;
    }
    header[0] = 'I';
    header[1] = 'I';
    LittleEndian16(header + 2, 42);
    LittleEndian32(header + 4, 8);
    LittleEndian16(header + 8, tiffTagCount);
    BYTE* entry = header + 10;
    TiffEntry(entry, 256, 4, 1, width);
    TiffEntry(entry, 257, 4, 1, height);
    TiffEntry(entry, 258, 3, 3, tiffValuesOffset);
    TiffEntry(entry, 259, 3, 1, 1);
    TiffEntry(entry, 262, 3, 1, 2);
    TiffEntry(entry, 273, 4, stripCount, stripCount == 1
        ? dataOffset
        : tiffValuesOffset + 22);
    TiffEntry(entry, 274, 3, 1, 1);
    TiffEntry(entry, 277, 3, 1, 3);
    TiffEntry(entry, 278, 4, 1, rowsPerStrip);
    TiffEntry(entry, 279, 4, stripCount, stripCount == 1
        ? rowSize * height
        : tiffValuesOffset + 22 + stripCount * 4);
    TiffEntry(entry, 282, 5, 1, tiffValuesOffset + 6);
    TiffEntry(entry, 283, 5, 1, tiffValuesOffset + 14);
    TiffEntry(entry, 284, 3, 1, 1);
    TiffEntry(entry, 296, 3, 1, 2);
    for (int component = 0; component < 3; ++component) {
        LittleEndian16(header + tiffValuesOffset + component * 2, 8);
    }
    LittleEndian32(header + tiffValuesOffset + 6, dpiX);
    LittleEndian32(header + tiffValuesOffset + 10, 1);
    LittleEndian32(header + tiffValuesOffset + 14, dpiY);
    LittleEndian32(header + tiffValuesOffset + 18, 1);
    if (stripCount > 1) {
        for (DWORD index = 0; index < stripCount; ++index) {
            DWORD firstRow = index * rowsPerStrip;
            DWORD rows = height - firstRow;
            if (rows > rowsPerStrip) {
                rows = rowsPerStrip;
            }
            LittleEndian32(header + tiffValuesOffset + 22 + index * 4, dataOffset + firstRow * rowSize);
            LittleEndian32(header + tiffValuesOffset + 22 + stripCount * 4 + index * 4, rows * rowSize);
        }
    }
    bool success = WriteBytes(file, header, dataOffset);
    for (int y = 0; y < height && success; ++y) {
        const BYTE* source = pixels + static_cast<SIZE_T>(y) * width * 4;
        for (int x = 0; x < width; ++x) {
            row[x * 3] = source[x * 4 + 2];
            row[x * 3 + 1] = source[x * 4 + 1];
            row[x * 3 + 2] = source[x * 4];
        }
        success = WriteBytes(file, row, rowSize);
    }
    HeapFree(GetProcessHeap(), 0, row);
    HeapFree(GetProcessHeap(), 0, header);
    return success;
}

/// Buffers one GIF data byte and flushes complete sub-blocks to the output file.
static void GifByte(GifWriter& writer, BYTE value) {
    writer.block[writer.count++] = value;
    if (writer.count == 255) {
        BYTE count = 255;
        writer.success = writer.success
            && WriteBytes(writer.file, &count, 1)
            && WriteBytes(writer.file, writer.block, 255);
        writer.count = 0;
    }
}

/// Packs one GIF LZW code into the buffered image-data stream.
static void GifCode(GifWriter& writer, DWORD code) {
    writer.packed |= code << writer.bits;
    writer.bits += 9;
    while (writer.bits >= 8) {
        GifByte(writer, static_cast<BYTE>(writer.packed));
        writer.packed >>= 8;
        writer.bits -= 8;
    }
}

/// Writes an exact GIF palette image, rejecting reports that require more than 256 colors.
static bool WriteGif(HANDLE file, const BYTE* pixels, int width, int height) {
    GifColor* colors = static_cast<GifColor*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
        4096 * sizeof(GifColor)));
    if (!colors) {
        return false;
    }
    BYTE palette[768] = {};
    int colorCount = 0;
    SIZE_T count = static_cast<SIZE_T>(width) * height;
    bool success = true;
    for (SIZE_T index = 0; index < count; ++index) {
        DWORD color = pixels[index * 4] | pixels[index * 4 + 1] << 8 | pixels[index * 4 + 2] << 16;
        DWORD slot = color * 2654435761U >> 20;
        while (colors[slot].color && colors[slot].color != color + 1) {
            slot = slot + 1 & 4095;
        }
        if (!colors[slot].color) {
            if (colorCount == 256) {
                success = false;
                break;
            }
            colors[slot].color = color + 1;
            colors[slot].index = static_cast<BYTE>(colorCount);
            palette[colorCount * 3] = static_cast<BYTE>(color >> 16);
            palette[colorCount * 3 + 1] = static_cast<BYTE>(color >> 8);
            palette[colorCount * 3 + 2] = static_cast<BYTE>(color);
            ++colorCount;
        }
    }
    BYTE header[] = { 'G', 'I', 'F', '8', '9', 'a', 0, 0, 0, 0, 0xF7, 0, 0 };
    header[6] = static_cast<BYTE>(width);
    header[7] = static_cast<BYTE>(width >> 8);
    header[8] = static_cast<BYTE>(height);
    header[9] = static_cast<BYTE>(height >> 8);
    BYTE descriptor[] = { 0x2C, 0, 0, 0, 0, header[6], header[7], header[8], header[9], 0, 8 };
    GifWriter writer = GifWriter{};
    writer.file = file;
    writer.success = success
        && WriteBytes(file, header, sizeof(header))
        && WriteBytes(file, palette, sizeof(palette))
        && WriteBytes(file, descriptor, sizeof(descriptor));
    GifCode(writer, 256);
    int literals = 0;
    for (SIZE_T index = 0; index < count && writer.success; ++index) {
        DWORD color = pixels[index * 4] | pixels[index * 4 + 1] << 8 | pixels[index * 4 + 2] << 16;
        DWORD slot = color * 2654435761U >> 20;
        while (colors[slot].color != color + 1) {
            slot = slot + 1 & 4095;
        }
        GifCode(writer, colors[slot].index);
        if (++literals == 250) {
            GifCode(writer, 256);
            literals = 0;
        }
    }
    GifCode(writer, 257);
    if (writer.bits) {
        GifByte(writer, static_cast<BYTE>(writer.packed));
    }
    if (writer.count) {
        BYTE length = static_cast<BYTE>(writer.count);
        writer.success = writer.success
            && WriteBytes(file, &length, 1)
            && WriteBytes(file, writer.block, length);
    }
    const BYTE end[] = { 0, 0x3B };
    writer.success = writer.success && WriteBytes(file, end, 2);
    HeapFree(GetProcessHeap(), 0, colors);
    return writer.success;
}


/// Reports whether the requested image format has an available encoder.
bool ImageWriter::Available(DWORD type) {
    if (type == ImageJpeg) {
        JpegEncoder encoder;
        return encoder.IsAvailable();
    }
    if (type == ImageWebp) {
        WebpEncoder encoder;
        return encoder.IsAvailable();
    }
    return type >= ImageBmp && type <= ImageWebp;
}

/// Returns the default filename extension, using PNG for an unknown format.
const wchar_t* ImageWriter::Extension(DWORD type) {
    const wchar_t* extensions[] = { L"bmp", L"gif", L"jpg", L"png", L"tif", L"webp" };
    return extensions[type >= ImageBmp && type <= ImageWebp ? type - 1 : ImagePng - 1];
}

/// Returns the localized Save dialog label, using PNG for an unknown format.
const wchar_t* ImageWriter::Label(DWORD type) {
    const wchar_t* labels[] = {
        L"Windows Bitmap BMP (*.bmp)",
        L"CompuServe GIF 89a (*.gif)",
        L"JPEG File Interchange Format (*.jpg)",
        L"Portable Network Graphics PNG (*.png)",
        L"Tagged Image File Format TIFF (*.tif)",
        L"Google WebP (*.webp)"
    };
    return TranslateText(labels[type >= ImageBmp && type <= ImageWebp ? type - 1 : ImagePng - 1]);
}

/// Saves a cropped BGRA image and replaces the destination only after successful encoding.
bool ImageWriter::Save(const wchar_t* path, const BYTE* source, int sourceWidth, int sourceHeight,
    const RECT& crop, DWORD type, wchar_t* error, int capacity) {
    if (type == ImagePng) {
        bool success = PngWriter::Save(path, source, sourceWidth, sourceHeight, crop);
        if (!success) {
            lstrcpynW(error, TranslateText(imageErrors[0]), capacity);
        }
        return success;
    }
    int width = crop.right - crop.left;
    int height = crop.bottom - crop.top;
    if (!source
            || crop.left < 0
            || crop.top < 0
            || width <= 0
            || height <= 0
            || crop.right > sourceWidth
            || crop.bottom > sourceHeight
            || width > 0x1FFFFFFF
            || static_cast<DWORD>(height) > 0x1FFFFFFFUL / width
            || !Available(type)) {
        SetLastError(ERROR_INVALID_PARAMETER);
        lstrcpynW(error, TranslateText(type == ImageJpeg ? imageErrors[2] : imageErrors[0]), capacity);
        return false;
    }
    if ((type == ImageGif || type == ImageJpeg) && (width > 0xFFFF || height > 0xFFFF)) {
        SetLastError(ERROR_INVALID_PARAMETER);
        lstrcpynW(error, TranslateText(
            L"The selected image format cannot exceed 65535 pixels in either dimension."), capacity);
        return false;
    }
    BITMAPINFO info = {};
    info.bmiHeader.biSize = sizeof(info.bmiHeader);
    info.bmiHeader.biWidth = width;
    info.bmiHeader.biHeight = -height;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    BYTE* pixels = NULL;
    HBITMAP bitmap = CreateDIBSection(NULL, &info, DIB_RGB_COLORS,
        reinterpret_cast<void**>(&pixels), NULL, 0);
    if (!bitmap) {
        lstrcpynW(error, TranslateText(imageErrors[0]), capacity);
        return false;
    }
    for (int y = 0; y < height; ++y) {
        CopyMemory(pixels + static_cast<SIZE_T>(y) * width * 4,
            source + (static_cast<SIZE_T>(crop.top + y) * sourceWidth + crop.left) * 4, width * 4);
    }
    wchar_t folder[MAX_PATH];
    lstrcpynW(folder, path, MAX_PATH);
    wchar_t* separator = NULL;
    for (wchar_t* cursor = folder; *cursor; ++cursor) {
        if (*cursor == L'\\' || *cursor == L'/') {
            separator = cursor;
        }
    }
    if (separator) {
        separator[1] = 0;
    } else {
        lstrcpyW(folder, L".");
    }
    wchar_t temporary[MAX_PATH] = {};
    bool success = GetTempFileNameW(folder, L"FSH", 0, temporary) != 0;
    if (success && type == ImageJpeg) {
        JpegEncoder encoder;
        success = encoder.Save(temporary, bitmap);
    } else if (success) {
        HANDLE file = CreateFileW(temporary, GENERIC_WRITE, 0, NULL,
            CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        success = file != INVALID_HANDLE_VALUE;
        if (success) {
            if (type == ImageWebp) {
                WebpEncoder encoder;
                success = encoder.Save(file, pixels, width, height);
            } else if (type == ImageBmp) {
                success = WriteBmp(file, pixels, width, height, 96, 96);
            } else if (type == ImageGif) {
                success = WriteGif(file, pixels, width, height);
            } else {
                success = WriteTiff(file, pixels, width, height, 96, 96);
            }
            if (!CloseHandle(file)) {
                success = false;
            }
        }
    }
    DWORD failure = GetLastError();
    if (success) {
        success = MoveFileExW(temporary, path, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != FALSE;
        failure = GetLastError();
    }
    if (!success) {
        if (*temporary) {
            DeleteFileW(temporary);
        }
        int message = 4;
        if (type == ImageGif) {
            message = 1;
        } else if (type == ImageJpeg) {
            message = 2;
        } else if (type == ImageBmp) {
            message = 3;
        } else if (type == ImageWebp) {
            message = 5;
        }
        lstrcpynW(error, TranslateText(imageErrors[message]), capacity);
    }
    DeleteObject(bitmap);
    SetLastError(failure);
    return success;
}
