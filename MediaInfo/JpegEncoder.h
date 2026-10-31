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
 * Last modified for version 1.0.0.0
 */

#pragma once

#include <windows.h>

/// Owns optional GDI+ initialization and the installed JPEG encoder.
class JpegEncoder {

private:
    /// Dynamically resolved GDI+ entry-point signatures.
    typedef void (WINAPI* ShutdownFunction)(ULONG_PTR);
    typedef int (WINAPI* FromBitmapFunction)(HBITMAP, HPALETTE, void**);
    typedef int (WINAPI* SaveFunction)(void*, const wchar_t*, const GUID*, const void*);
    typedef int (WINAPI* DisposeFunction)(void*);

    /// GDI+ lifetime, selected encoder and resolved image operations.
    HMODULE module;
    ULONG_PTR token;
    GUID encoder;
    ShutdownFunction shutdown;
    FromBitmapFunction create;
    SaveFunction save;
    DisposeFunction dispose;
    bool available;

public:
    /// Loads optional GDI+ entry points and locates the installed JPEG encoder.
    JpegEncoder();

    /// Shuts down GDI+ and releases its dynamically loaded module.
    ~JpegEncoder();

    /// Reports whether the native JPEG encoder was initialized successfully.
    bool IsAvailable() const;

    /// Writes the rendered report bitmap using the available GDI+ JPEG encoder.
    bool Save(const wchar_t* path, HBITMAP bitmap);
};
