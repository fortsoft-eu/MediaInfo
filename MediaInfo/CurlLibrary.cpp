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

#include "Localization.h"
#include "CurlLibrary.h"
#include "LibrarySupport.h"
#include "resource.h"

/// Curl exports required by the MediaInfo URL reader.
static const char* curlExports[] = {
    "curl_easy_init",
    "curl_easy_setopt",
    "curl_easy_perform",
    "curl_easy_cleanup",
    "curl_easy_getinfo",
    "curl_slist_append",
    "curl_slist_free_all",
    "curl_easy_duphandle",
    "curl_easy_strerror",
    "curl_version_info",
    "curl_multi_init",
    "curl_multi_add_handle",
    "curl_multi_remove_handle",
    "curl_multi_perform",
    "curl_multi_cleanup"
};

/// Initializes an unloaded optional curl library.
CurlLibrary::CurlLibrary() : module(nullptr) {
    error[0] = 0;
}

/// Unloads the optional curl library when the worker releases its loader.
CurlLibrary::~CurlLibrary() {
    if (module) {
        FreeLibrary(module);
    }
}

/// Validates an x86 curl image, loads it and checks the exports required by MediaInfo.
bool CurlLibrary::Load(const wchar_t* path) {
    wchar_t filename[MAX_PATH];
    DWORD length = GetFullPathNameW(path, MAX_PATH, filename, nullptr);
    if (!length || length >= MAX_PATH) {
        lstrcpyW(error, T(TXT_CURL_PATH_INVALID));
        return false;
    }
    if (!InspectLibraryImage(filename, error, 512, curlLibraryName)) {
        return false;
    }
    const wchar_t* name = filename;
    for (const wchar_t* cursor = filename; *cursor; ++cursor) {
        if (*cursor == L'\\' || *cursor == L'/') {
            name = cursor + 1;
        }
    }
    if (lstrcmpiW(name, curlLibraryName)) {
        lstrcpyW(error, T(TXT_CURL_FILENAME_INVALID));
        return false;
    }
    HMODULE candidate = LoadLibraryExW(filename, nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (!candidate) {
        wsprintfW(error, T(TXT_CURL_LOAD_FAILED), GetLastError());
        return false;
    }
    for (int index = 0; index < static_cast<int>(sizeof(curlExports) / sizeof(curlExports[0])); ++index) {
        if (!GetProcAddress(candidate, curlExports[index])) {
            FreeLibrary(candidate);
            lstrcpyW(error, T(TXT_CURL_EXPORTS_MISSING));
            return false;
        }
    }
    module = candidate;
    error[0] = 0;
    return true;
}

/// Tries one curl discovery candidate with the current loader instance.
bool CurlLibrary::TryCandidate(const wchar_t* path, void* context) {
    return static_cast<CurlLibrary*>(context)->Load(path);
}

/// Searches external locations and then extracts the curl resource matching the selected MediaInfo version.
bool CurlLibrary::Discover(const wchar_t* mediaInfoPath, const wchar_t* configuredPath, bool xp) {
    if (configuredPath[0]) {
        return Load(configuredPath);
    }
    if (SearchLibraryLocations(curlLibraryName, mediaInfoPath, TryCandidate, this)) {
        return true;
    }
    wchar_t path[MAX_PATH];
    return ExtractBundledLibrary(xp ? IDR_LIBRARY_CURL_XP : IDR_LIBRARY_CURL, xp ? L"curl-XP" : L"curl", path,
        error, 512, curlLibraryName) && Load(path);
}

/// Returns the most recent curl loading diagnostic.
const wchar_t* CurlLibrary::GetError() const {
    return error;
}
