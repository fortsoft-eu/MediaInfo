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

#include "WebpEncoder.h"
#include "LibrarySupport.h"
#include "resource.h"

/// WebP version-query signature used to validate a candidate encoder.
typedef int(__cdecl* WebpVersionFunction)();

/// System exports required before the bundled WebP library can be extracted and loaded.
static const char* webpSystemImports[] = {
    "CloseHandle",
    "EnterCriticalSection",
    "LeaveCriticalSection",
    "InitializeCriticalSectionEx",
    "DeleteCriticalSection",
    "InitializeConditionVariable",
    "WakeConditionVariable",
    "SleepConditionVariableCS",
    "WaitForSingleObjectEx",
    "SetThreadPriority",
    "IsProcessorFeaturePresent",
    "UnhandledExceptionFilter",
    "SetUnhandledExceptionFilter",
    "GetCurrentProcess",
    "TerminateProcess",
    "QueryPerformanceCounter",
    "GetCurrentProcessId",
    "GetCurrentThreadId",
    "GetSystemTimeAsFileTime",
    "InitializeSListHead",
    "IsDebuggerPresent",
    "GetStartupInfoW",
    "GetModuleHandleW",
    "CreateFileW",
    "InterlockedFlushSList",
    "RtlUnwind",
    "GetLastError",
    "SetLastError",
    "InitializeCriticalSectionAndSpinCount",
    "TlsAlloc",
    "TlsGetValue",
    "TlsSetValue",
    "TlsFree",
    "FreeLibrary",
    "GetProcAddress",
    "LoadLibraryExW",
    "EncodePointer",
    "RaiseException",
    "CreateThread",
    "ExitThread",
    "FreeLibraryAndExitThread",
    "GetModuleHandleExW",
    "ExitProcess",
    "GetModuleFileNameW",
    "HeapAlloc",
    "HeapFree",
    "LCMapStringW",
    "DecodePointer",
    "FindClose",
    "FindFirstFileExW",
    "FindNextFileW",
    "IsValidCodePage",
    "GetACP",
    "GetOEMCP",
    "GetCPInfo",
    "GetCommandLineA",
    "GetCommandLineW",
    "MultiByteToWideChar",
    "WideCharToMultiByte",
    "GetEnvironmentStringsW",
    "FreeEnvironmentStringsW",
    "GetProcessHeap",
    "GetStdHandle",
    "GetFileType",
    "GetStringTypeW",
    "HeapSize",
    "HeapReAlloc",
    "SetStdHandle",
    "FlushFileBuffers",
    "WriteFile",
    "GetConsoleCP",
    "GetConsoleMode",
    "SetFilePointerEx",
    "WriteConsoleW"
};

/// Searches external encoders and extracts the bundled DLL only when every system import is available.
WebpEncoder::WebpEncoder() : module(nullptr), encode(nullptr), freeMemory(nullptr) {
    if (SearchLibraryLocations(webpLibraryName, nullptr, TryCandidate, this)) {
        return;
    }
    HMODULE kernel = GetModuleHandleW(L"kernel32.dll");
    for (UINT index = 0; index < ARRAYSIZE(webpSystemImports); ++index) {
        if (!GetProcAddress(kernel, webpSystemImports[index])) {
            return;
        }
    }
    wchar_t path[MAX_PATH];
    wchar_t error[512];
    if (ExtractBundledLibrary(IDR_LIBRARY_WEBP, L"webp", path, error, ARRAYSIZE(error), webpLibraryName)) {
        Load(path);
    }
}

/// Releases the dynamically loaded optional encoder.
WebpEncoder::~WebpEncoder() {
    if (module) {
        FreeLibrary(module);
    }
}

/// Loads one x86 DLL silently and verifies the lossless encoder, matching allocator and version export.
bool WebpEncoder::Load(const wchar_t* path) {
    wchar_t error[512];
    if (!InspectLibraryImage(path, error, ARRAYSIZE(error), webpLibraryName)) {
        return false;
    }
    DWORD previousMode = SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);
    HMODULE candidate = LoadLibraryExW(path, nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
    SetErrorMode(previousMode);
    if (!candidate) {
        return false;
    }
    EncodeFunction candidateEncode =
        reinterpret_cast<EncodeFunction>(GetProcAddress(candidate, "WebPEncodeLosslessBGRA"));
    FreeFunction candidateFree = reinterpret_cast<FreeFunction>(GetProcAddress(candidate, "WebPFree"));
    WebpVersionFunction version =
        reinterpret_cast<WebpVersionFunction>(GetProcAddress(candidate, "WebPGetEncoderVersion"));
    if (!candidateEncode || !candidateFree || !version || version() <= 0) {
        FreeLibrary(candidate);
        return false;
    }
    module = candidate;
    encode = candidateEncode;
    freeMemory = candidateFree;
    return true;
}

/// Tries one discovered library path with the current encoder.
bool WebpEncoder::TryCandidate(const wchar_t* path, void* context) {
    return static_cast<WebpEncoder*>(context)->Load(path);
}

/// Reports whether a compatible lossless WebP encoder is loaded.
bool WebpEncoder::IsAvailable() const {
    return module != nullptr;
}

/// Makes the rendered GDI pixels opaque and writes their exact colors as lossless WebP.
bool WebpEncoder::Save(HANDLE file, BYTE* pixels, int width, int height) {
    if (!IsAvailable() || !pixels || width < 1 || height < 1 || width > 16383 || height > 16383) {
        return false;
    }
    SIZE_T count = static_cast<SIZE_T>(width) * height;
    for (SIZE_T index = 0; index < count; ++index) {
        pixels[index * 4 + 3] = 255;
    }
    BYTE* encoded = nullptr;
    SIZE_T size = encode(pixels, width, height, width * 4, &encoded);
    bool success = encoded && size && WriteLibraryBytes(file, encoded, static_cast<DWORD>(size));
    if (encoded) {
        freeMemory(encoded);
    }
    return success;
}
