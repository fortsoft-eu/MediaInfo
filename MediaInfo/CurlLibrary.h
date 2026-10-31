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

/// Owns the optional curl DLL selected for the isolated MediaInfo worker.
class CurlLibrary {

private:
    HMODULE module;
    wchar_t error[512];

    /// Validates an x86 curl image, loads it and checks the exports required by MediaInfo.
    bool Load(const wchar_t* path);

    /// Tries one curl discovery candidate with the current loader instance.
    static bool TryCandidate(const wchar_t* path, void* context);

    /// Prevents copying ownership of the native resources held by this object.
    CurlLibrary(const CurlLibrary&) = delete;

    /// Prevents assigning ownership of the native resources held by another object.
    CurlLibrary& operator=(const CurlLibrary&) = delete;

public:
    /// Initializes an unloaded optional curl library.
    CurlLibrary();

    /// Unloads the optional curl library when the worker releases its loader.
    ~CurlLibrary();

    /// Searches external locations and then extracts the curl resource matching the selected MediaInfo
    /// version.
    bool Discover(const wchar_t* mediaInfoPath, const wchar_t* configuredPath, bool xp);

    /// Returns the most recent curl loading diagnostic.
    const wchar_t* GetError() const;
};
