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

/// Owns an optional lossless WebP encoder and its DLL lifetime.
class WebpEncoder {

private:
    /// Matching WebP encoder and allocation-release signatures.
    typedef SIZE_T(__cdecl* EncodeFunction)(const BYTE*, int, int, int, BYTE**);
    typedef void(__cdecl* FreeFunction)(void*);

    /// Loaded encoder and its matching allocation-release function.
    HMODULE module;
    EncodeFunction encode;
    FreeFunction freeMemory;

    /// Loads one x86 DLL silently and verifies the lossless encoder, matching allocator and version export.
    bool Load(const wchar_t* path);

    /// Tries one discovered library path with the current encoder.
    static bool TryCandidate(const wchar_t* path, void* context);

public:
    /// Searches external encoders and extracts the bundled DLL only when every system import is available.
    WebpEncoder();

    /// Releases the dynamically loaded optional encoder.
    ~WebpEncoder();

    /// Reports whether a compatible lossless WebP encoder is loaded.
    bool IsAvailable() const;

    /// Makes the rendered GDI pixels opaque and writes their exact colors as lossless WebP.
    bool Save(HANDLE file, BYTE* pixels, int width, int height);
};
