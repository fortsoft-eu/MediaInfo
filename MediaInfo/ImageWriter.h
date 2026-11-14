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

/// Identifies supported image formats using stable one-based output identifiers.
enum ImageFormat {
    ImageBmp = 1,
    ImageGif = 2,
    ImageJpeg = 3,
    ImagePng = 4,
    ImageTiff = 5,
    ImageWebp = 6
};

/// Saves cropped BGRA pixels through the supported native and optional image encoders.
class ImageWriter {

public:
    /// Reports whether the requested image format has an available encoder.
    static bool Available(DWORD type);

    /// Returns the default filename extension, using PNG for an unknown format.
    static const wchar_t* Extension(DWORD type);

    /// Returns the localized Save dialog label, using PNG for an unknown format.
    static const wchar_t* Label(DWORD type);

    /// Saves a cropped BGRA image and replaces the destination only after successful encoding.
    static bool Save(const wchar_t* path, const BYTE* pixels, int width, int height, const RECT& crop,
        DWORD type, wchar_t* error, int capacity);
};
