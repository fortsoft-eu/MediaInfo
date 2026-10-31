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

#include "LibrarySupport.h"

/// Owns the isolated DLL worker and exposes validated reports and library information to the viewer.
class MediaInfoLibrary {

private:
    /// Worker-process and pipe ownership, progress state and retained diagnostics.
    HANDLE process;
    HANDLE requests;
    HANDLE responses;
    volatile LONG failed;
    LibraryOperation operation;
    wchar_t path[MAX_PATH];
    wchar_t version[256];
    wchar_t error[512];

    /// Tries a discovery candidate and stops retrying after a manual curl or report-language configuration
    /// failure.
    static bool TryCandidate(const wchar_t* path, void* context);

    /// Creates hidden worker-process pipes and starts the same executable in internal worker mode.
    bool Start(const wchar_t* filename, const wchar_t* curlPath, const wchar_t* reportLanguage);

    /// Receives worker data with progress deadlines and detects crashes, broken pipes and stalled operations.
    bool ReceiveBytes(void* data, DWORD size);

    /// Validates and reads one Unicode result from the isolated library worker.
    bool Receive(wchar_t** text);

    /// Sends a read or information request and receives the isolated worker result.
    bool Request(const LibraryRequest& request, wchar_t** text);

    /// Marks the worker unavailable and records a localized exit or timeout diagnostic.
    void Fail();

    /// Prevents copying ownership of the native resources held by this object.
    MediaInfoLibrary(const MediaInfoLibrary&) = delete;

    /// Prevents assigning ownership of the native resources held by another object.
    MediaInfoLibrary& operator=(const MediaInfoLibrary&) = delete;

public:
    /// Initializes an unloaded MediaInfo worker connection and empty diagnostics.
    MediaInfoLibrary();

    /// Stops the isolated worker and closes its pipe and process handles.
    ~MediaInfoLibrary();

    /// Starts an isolated worker for one validated x86 DLL and accepts it only after a successful version
    /// reply.
    bool Load(const wchar_t* filename, const wchar_t* curlPath = nullptr,
        const wchar_t* reportLanguage = nullptr);

    /// Tries external DLLs and then the three bundled versions in descending order until one loads.
    bool Discover(const wchar_t* curlPath = nullptr, const wchar_t* reportLanguage = nullptr);

    /// Requests worker shutdown, bounds its exit wait and releases the connection handles.
    void Unload();

    /// Requests the unchanged Unicode report at the selected detail level from the isolated worker.
    bool Read(const wchar_t* filename, wchar_t** text, bool advancedMode = false, bool fullParsing = false,
        UINT traceLevel = 0);

    /// Requests the loaded library's known formats, codecs or parameters.
    bool Query(LibraryCommand command, wchar_t** text);

    /// Reports whether a usable worker remains connected without a recorded failure.
    bool IsLoaded() const;

    /// Returns the path of the selected MediaInfo DLL.
    const wchar_t* GetPath() const;

    /// Returns the version string reported by the selected MediaInfo DLL.
    const wchar_t* GetVersion() const;

    /// Returns the most recent library or worker diagnostic.
    const wchar_t* GetError() const;
};
