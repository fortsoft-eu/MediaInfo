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

#pragma once

#include <windows.h>

/// Writes cropped BGRA pixels as RGB PNG using bounded stored DEFLATE blocks.
class PngWriter {

public:
    /// Writes a validated image crop and replaces the destination only after complete encoding.
    static bool Save(const wchar_t* path, const BYTE* pixels, int width, int height, const RECT& crop);

private:
    /// Retains the output handle and initializes the PNG CRC32 lookup table.
    explicit PngWriter(HANDLE output);

    /// Writes the complete buffer, handling partial writes and propagating failures.
    bool Write(const void* data, DWORD length);

    /// Writes one PNG chunk with its big-endian length and CRC32 checksum.
    bool Chunk(const char* type, const BYTE* data, DWORD length);

    /// Streams RGB scanlines through stored DEFLATE blocks with a bounded working buffer.
    bool Encode(const BYTE* pixels, int width, const RECT& crop);

    /// Updates a CRC32 accumulator using the precomputed PNG lookup table.
    DWORD Crc(DWORD crc, const BYTE* data, DWORD length) const;

    /// Stores a 32-bit value in big-endian byte order.
    static void BigEndian(BYTE* output, DWORD value);

    /// Retains the output stream and the precomputed PNG CRC32 lookup table.
    HANDLE file;
    DWORD crcTable[256];
};
