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

/// Requests accepted by the isolated MediaInfo worker.
enum class LibraryCommand : DWORD {
    Shutdown,
    Read,
    Formats,
    Codecs,
    Parameters
};

/// Distinguishes progress notifications from successful replies and reported failures.
enum class LibraryMessageKind : DWORD {
    Stage = 1,
    Success = 2,
    Error = 3
};

/// Identifies the current DLL operation for progress deadlines and failure diagnostics.
enum class LibraryOperation : DWORD {
    Load = 0,
    New,
    Open,
    Inform,
    Copy,
    Close,
    Delete,
    Version,
    Unload,
    CurlLoad,
    Language,
    Option
};

/// Fixed-size worker request containing the operation, report options and Unicode source path.
struct LibraryRequest {
    LibraryCommand command;
    DWORD advancedMode;
    DWORD fullParsing;
    DWORD traceLevel;
    wchar_t path[MAX_PATH];
};

/// Worker reply header followed by the declared number of Unicode text characters.
struct LibraryReply {
    DWORD signature;
    LibraryMessageKind kind;
    LibraryOperation operation;
    DWORD length;
};

/// Receives a discovery candidate and returns true when the search should stop.
typedef bool(*LibraryCandidateFunction)(const wchar_t* path, void* context);

/// Filenames used to discover, validate and extract the supported libraries.
extern const wchar_t mediaInfoLibraryName[];
extern const wchar_t curlLibraryName[];
extern const wchar_t webpLibraryName[];

/// Bundled-library versions used by discovery and the About product header.
extern const wchar_t* const bundledMediaInfoVersions[3];
extern const wchar_t bundledCurlVersions[];

/// Signature checked before accepting a worker reply.
static const DWORD librarySignature = 0x4D494650;

/// Writes a complete worker-protocol message buffer, including any partial pipe writes.
bool WriteLibraryBytes(HANDLE pipe, const void* data, DWORD size);

/// Reads a complete worker-protocol message buffer or reports a closed or failed pipe.
bool ReadLibraryBytes(HANDLE pipe, void* data, DWORD size);

/// Returns the localized operation description used in isolated library-failure messages.
const wchar_t* LibraryOperationName(LibraryOperation operation);

/// Checks a PE file for x86 architecture and returns its Windows and subsystem version information.
bool InspectLibraryImage(const wchar_t* path, wchar_t* error, int capacity,
    const wchar_t* name = mediaInfoLibraryName);

/// Searches executable ancestors, Program Files and user installation folders through a candidate callback.
bool SearchLibraryLocations(const wchar_t* name, const wchar_t* beside, LibraryCandidateFunction candidate,
    void* context);

/// Validates a packed resource and decodes it only when its length and CRC32 agree.
bool UnpackLibraryBytes(const BYTE* packed, DWORD packedSize, BYTE** unpacked, DWORD* unpackedSize);

/// Waits for other extractors, reuses a verified cached DLL or extracts it and returns its checked path.
bool ExtractBundledLibrary(UINT resource, const wchar_t* version, wchar_t* path, wchar_t* error, int capacity,
    const wchar_t* name = mediaInfoLibraryName);
