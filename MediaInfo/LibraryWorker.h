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
#include "CurlLibrary.h"
#include <stddef.h>

/// Loads MediaInfo in an isolated process and services requests over inherited pipes.
class LibraryWorker {

private:
    /// Unicode MediaInfo C-export signatures.
    typedef void* (__stdcall* NewFunction)();
    typedef void(__stdcall* DeleteFunction)(void*);
    typedef size_t(__stdcall* OpenFunction)(void*, const wchar_t*);
    typedef void(__stdcall* CloseFunction)(void*);
    typedef const wchar_t* (__stdcall* InformFunction)(void*, size_t);
    typedef const wchar_t* (__stdcall* OptionFunction)(void*, const wchar_t*, const wchar_t*);

    /// Loaded library, request and response pipes, resolved exports and optional curl support.
    HMODULE module;
    HANDLE input;
    HANDLE output;
    NewFunction create;
    DeleteFunction destroy;
    OpenFunction open;
    CloseFunction close;
    InformFunction inform;
    OptionFunction option;
    CurlLibrary curl;

    /// Sends the next library-operation stage to the parent process before invoking the DLL.
    bool Stage(LibraryOperation operation);

    /// Writes a worker result and its Unicode text to the parent response pipe.
    bool Reply(bool success, const wchar_t* text);

    /// Loads and validates MediaInfo exports, configures optional curl and language data and reports
    /// its version.
    bool Load(const wchar_t* filename, const wchar_t* curlPath, const wchar_t* reportLanguage);

    /// Opens one media path through the DLL, copies its unchanged report and closes the media handle.
    bool Read(const wchar_t* filename, bool advancedMode, bool fullParsing, UINT traceLevel);

    /// Returns a library-supplied list of known formats, codecs or parameters.
    bool Query(LibraryCommand command);

public:
    /// Initializes the isolated worker pipes, export pointers and unloaded library state.
    LibraryWorker(HANDLE requests, HANDLE responses);

    /// Releases the MediaInfo handle, loaded libraries and worker-owned report state.
    ~LibraryWorker();

    /// Services report requests from the parent until the protocol ends or a pipe fails.
    int Run(const wchar_t* filename, const wchar_t* curlPath, const wchar_t* reportLanguage);
};

/// Recognizes the internal worker command line and runs it without creating the viewer interface.
bool DispatchLibraryWorker(int count, wchar_t** arguments, int* result);
