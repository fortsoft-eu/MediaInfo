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

#include "MediaInfoLibrary.h"
#include "LibrarySupport.h"
#include "SettingsStorage.h"
#include "Localization.h"
#include "resource.h"

/// Carries discovery configuration and whether a rejected setting should stop the search.
struct LibrarySearchData {
    MediaInfoLibrary* library;
    const wchar_t* curlPath;
    const wchar_t* reportLanguage;
    bool configurationFailure;
};

/// Tries a discovery candidate and stops retrying after a manual curl or report-language configuration
/// failure.
bool MediaInfoLibrary::TryCandidate(const wchar_t* path, void* context) {
    LibrarySearchData* data = static_cast<LibrarySearchData*>(context);
    if (data->configurationFailure) {
        return false;
    }
    bool success = data->library->Load(path, data->curlPath, data->reportLanguage);
    data->configurationFailure = !success
        && (data->curlPath[0] && data->library->operation == LibraryOperation::CurlLoad
            || data->library->operation == LibraryOperation::Language);
    return success;
}

/// Creates a worker pipe while keeping only its child endpoint inheritable.
static bool CreateWorkerPipe(HANDLE* read, HANDLE* write, bool childReads) {
    SECURITY_ATTRIBUTES attributes = SECURITY_ATTRIBUTES{ sizeof(SECURITY_ATTRIBUTES), nullptr, TRUE };
    if (!CreatePipe(read, write, &attributes, 65536)) {
        return false;
    }
    HANDLE parent = childReads ? *write : *read;
    HANDLE copy = nullptr;
    if (!DuplicateHandle(GetCurrentProcess(), parent, GetCurrentProcess(), &copy, 0, FALSE,
            DUPLICATE_SAME_ACCESS)) {
        CloseHandle(*read);
        CloseHandle(*write);
        *read = nullptr;
        *write = nullptr;
        return false;
    }
    CloseHandle(parent);
    if (childReads) {
        *write = copy;
    } else {
        *read = copy;
    }
    return true;
}

/// Initializes an unloaded MediaInfo worker connection and empty diagnostics.
MediaInfoLibrary::MediaInfoLibrary()
        : process(nullptr), requests(nullptr), responses(nullptr), failed(0),
        operation(LibraryOperation::Load) {
    path[0] = 0;
    version[0] = 0;
    error[0] = 0;
}

/// Stops the isolated worker and closes its pipe and process handles.
MediaInfoLibrary::~MediaInfoLibrary() {
    Unload();
}

/// Creates hidden worker-process pipes and starts the same executable in internal worker mode.
bool MediaInfoLibrary::Start(const wchar_t* filename, const wchar_t* curlPath, const wchar_t* reportLanguage) {
    HANDLE childInput = nullptr;
    HANDLE childOutput = nullptr;
    bool pipes = CreateWorkerPipe(&childInput, &requests, true)
        && CreateWorkerPipe(&responses, &childOutput, false);
    bool started = false;
    if (pipes) {
        wchar_t executable[MAX_PATH];
        DWORD length = GetModuleFileNameW(nullptr, executable, MAX_PATH);
        if (length && length < MAX_PATH) {
            wchar_t command[4 * MAX_PATH + 160];
            wsprintfW(command, L"\"%s\" --mediainfo-worker %lu %lu \"%s\" \"%s\" \"%s\" %d", executable,
                reinterpret_cast<DWORD>(childInput), reinterpret_cast<DWORD>(childOutput), filename, curlPath,
                reportLanguage, GetApplicationLanguage());
            STARTUPINFOW startup = STARTUPINFOW{};
            startup.cb = sizeof(startup);
            startup.dwFlags = STARTF_USESHOWWINDOW | STARTF_FORCEOFFFEEDBACK;
            startup.wShowWindow = SW_HIDE;
            PROCESS_INFORMATION worker = PROCESS_INFORMATION{};
            if (CreateProcessW(executable, command, nullptr, nullptr, TRUE,
                    CREATE_DEFAULT_ERROR_MODE | DETACHED_PROCESS, nullptr, nullptr, &startup, &worker)) {
                process = worker.hProcess;
                CloseHandle(worker.hThread);
                started = true;
            }
        }
    }
    if (childInput) {
        CloseHandle(childInput);
    }
    if (childOutput) {
        CloseHandle(childOutput);
    }
    if (!started) {
        wsprintfW(error, T(TXT_LIBRARY_WORKER_START_FAILED), GetLastError());
    }
    return started;
}

/// Marks the worker unavailable and records a localized exit or timeout diagnostic.
void MediaInfoLibrary::Fail() {
    InterlockedExchange(&failed, 1);
    DWORD code = 0;
    bool exited = process && WaitForSingleObject(process, 0) == WAIT_OBJECT_0;
    if (exited) {
        GetExitCodeProcess(process, &code);
    }
    if (exited) {
        wsprintfW(error, T(TXT_LIBRARY_WORKER_FAILED), LibraryOperationName(operation), code);
    } else {
        wsprintfW(error, T(TXT_LIBRARY_WORKER_TIMEOUT), LibraryOperationName(operation));
        if (process) {
            TerminateProcess(process, 1);
        }
    }
}

/// Receives worker data with progress deadlines and detects crashes, broken pipes and stalled operations.
bool MediaInfoLibrary::ReceiveBytes(void* data, DWORD size) {
    BYTE* cursor = static_cast<BYTE*>(data);
    DWORD lastProgress = GetTickCount();
    DWORD timeout = operation == LibraryOperation::Load
        || operation == LibraryOperation::Version
        || operation == LibraryOperation::CurlLoad
        || operation == LibraryOperation::Language
        || operation == LibraryOperation::Option ? 15000 : 300000;
    while (size) {
        DWORD available = 0;
        if (!PeekNamedPipe(responses, nullptr, 0, nullptr, &available, nullptr)) {
            if (process) {
                WaitForSingleObject(process, 100);
            }
            Fail();
            return false;
        }
        if (available) {
            DWORD received = 0;
            DWORD amount = available < size ? available : size;
            if (!ReadFile(responses, cursor, amount, &received, nullptr) || !received) {
                Fail();
                return false;
            }
            cursor += received;
            size -= received;
            lastProgress = GetTickCount();
        } else {
            DWORD wait = WaitForSingleObject(process, 10);
            if (wait == WAIT_OBJECT_0) {
                if (PeekNamedPipe(responses, nullptr, 0, nullptr, &available, nullptr) && available) {
                    continue;
                }
                Fail();
                return false;
            }
            if (wait == WAIT_FAILED || GetTickCount() - lastProgress >= timeout) {
                Fail();
                return false;
            }
        }
    }
    return true;
}

/// Validates and reads one Unicode result from the isolated library worker.
bool MediaInfoLibrary::Receive(wchar_t** text) {
    *text = nullptr;
    LibraryReply reply = LibraryReply{};
    while (true) {
        if (!ReceiveBytes(&reply, sizeof(reply))) {
            return false;
        }
        if (reply.signature != librarySignature || reply.length > 0x3FFFFFFE) {
            Fail();
            return false;
        }
        if (reply.kind != LibraryMessageKind::Stage) {
            break;
        }
        operation = reply.operation;
    }
    if (reply.kind != LibraryMessageKind::Success && reply.kind != LibraryMessageKind::Error) {
        Fail();
        return false;
    }
    wchar_t* buffer = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
        (static_cast<SIZE_T>(reply.length) + 1) * sizeof(wchar_t)));
    if (!buffer) {
        Fail();
        lstrcpyW(error, T(TXT_REPORT_COPY_FAILED));
        return false;
    }
    if (!ReceiveBytes(buffer, reply.length * sizeof(wchar_t))) {
        HeapFree(GetProcessHeap(), 0, buffer);
        return false;
    }
    if (reply.kind == LibraryMessageKind::Error) {
        lstrcpynW(error, buffer, 512);
        HeapFree(GetProcessHeap(), 0, buffer);
        return false;
    }
    *text = buffer;
    return true;
}

/// Starts an isolated worker for one validated x86 DLL and accepts it only after a successful version reply.
bool MediaInfoLibrary::Load(const wchar_t* filename, const wchar_t* curlPath, const wchar_t* reportLanguage) {
    operation = LibraryOperation::Load;
    wchar_t configuredReport[MAX_PATH];
    if (!reportLanguage) {
        LoadReportLanguageSetting(configuredReport, MAX_PATH);
        reportLanguage = configuredReport;
    }
    wchar_t configured[MAX_PATH];
    if (!curlPath) {
        LoadCurlSetting(configured, MAX_PATH);
        curlPath = configured;
    }
    MediaInfoLibrary candidate;
    DWORD length = GetFullPathNameW(filename, MAX_PATH, candidate.path, nullptr);
    if (!length || length >= MAX_PATH) {
        lstrcpyW(error, T(TXT_MEDIALIB_PATH_INVALID));
        return false;
    }
    if (!InspectLibraryImage(candidate.path, error, 512)) {
        return false;
    }
    if (!candidate.Start(candidate.path, curlPath, reportLanguage)) {
        lstrcpynW(error, candidate.error, 512);
        return false;
    }
    wchar_t* loadedVersion = nullptr;
    if (!candidate.Receive(&loadedVersion)) {
        operation = candidate.operation;
        lstrcpynW(error, candidate.error, 512);
        return false;
    }
    if (!loadedVersion[0]) {
        HeapFree(GetProcessHeap(), 0, loadedVersion);
        lstrcpyW(error, T(TXT_MEDIALIB_VERSION_MISSING));
        return false;
    }
    lstrcpynW(candidate.version, loadedVersion, 256);
    HeapFree(GetProcessHeap(), 0, loadedVersion);
    Unload();
    process = candidate.process;
    requests = candidate.requests;
    responses = candidate.responses;
    operation = candidate.operation;
    InterlockedExchange(&failed, 0);
    lstrcpyW(path, candidate.path);
    lstrcpyW(version, candidate.version);
    error[0] = 0;
    candidate.process = nullptr;
    candidate.requests = nullptr;
    candidate.responses = nullptr;
    return true;
}

/// Tries external DLLs and then the three bundled versions in descending order until one loads.
bool MediaInfoLibrary::Discover(const wchar_t* curlPath, const wchar_t* reportLanguage) {
    wchar_t configuredReport[MAX_PATH];
    if (!reportLanguage) {
        LoadReportLanguageSetting(configuredReport, MAX_PATH);
        reportLanguage = configuredReport;
    }
    wchar_t configured[MAX_PATH];
    if (!curlPath) {
        LoadCurlSetting(configured, MAX_PATH);
        curlPath = configured;
    }
    LibrarySearchData search = LibrarySearchData{ this, curlPath, reportLanguage, false };
    if (SearchLibraryLocations(mediaInfoLibraryName, nullptr, TryCandidate, &search)) {
        return true;
    }
    if (search.configurationFailure) {
        return false;
    }
    wchar_t failure[512];
    lstrcpynW(failure, error, 512);
    const UINT resources[] = { IDR_LIBRARY_2610, IDR_LIBRARY_2103, IDR_LIBRARY_0760 };
    for (int index = 0; index < 3; ++index) {
        wchar_t extracted[MAX_PATH];
        if (ExtractBundledLibrary(resources[index], bundledMediaInfoVersions[index], extracted, error, 512)) {
            if (Load(extracted, curlPath, reportLanguage)) {
                return true;
            }
            if (curlPath[0] && operation == LibraryOperation::CurlLoad
                    || operation == LibraryOperation::Language
                    || operation == LibraryOperation::Option) {
                return false;
            }
        }
        lstrcpynW(failure, error, 512);
    }
    lstrcpyW(error, T(TXT_NO_COMPATIBLE_MEDIALIB));
    if (failure[0]) {
        lstrcatW(error, L"\r\n\r\n");
        lstrcpynW(error + lstrlenW(error), failure, 512 - lstrlenW(error));
    }
    return false;
}

/// Requests worker shutdown, bounds its exit wait and releases the connection handles.
void MediaInfoLibrary::Unload() {
    if (requests) {
        LibraryRequest request = LibraryRequest{};
        WriteLibraryBytes(requests, &request, sizeof(request));
        CloseHandle(requests);
    }
    if (process) {
        if (WaitForSingleObject(process, 1000) == WAIT_TIMEOUT) {
            TerminateProcess(process, 1);
            WaitForSingleObject(process, 1000);
        }
        CloseHandle(process);
    }
    if (responses) {
        CloseHandle(responses);
    }
    process = nullptr;
    requests = nullptr;
    responses = nullptr;
    InterlockedExchange(&failed, 0);
    path[0] = 0;
    version[0] = 0;
}

/// Sends a read or information request and receives the isolated worker result.
bool MediaInfoLibrary::Request(const LibraryRequest& request, wchar_t** text) {
    *text = nullptr;
    if (failed) {
        return false;
    }
    if (!IsLoaded()) {
        lstrcpyW(error, T(TXT_MEDIALIB_REQUIRED));
        return false;
    }
    operation = request.command == LibraryCommand::Read ? LibraryOperation::New : LibraryOperation::Option;
    if (!WriteLibraryBytes(requests, &request, sizeof(request))) {
        Fail();
        return false;
    }
    return Receive(text);
}

/// Requests the unchanged Unicode report at the selected detail level from the isolated worker.
bool MediaInfoLibrary::Read(
    const wchar_t* filename, wchar_t** text, bool advancedMode, bool fullParsing, UINT traceLevel) {
    LibraryRequest request = LibraryRequest{};
    request.command = LibraryCommand::Read;
    request.advancedMode = advancedMode ? 1 : 0;
    request.fullParsing = fullParsing ? 1 : 0;
    request.traceLevel = traceLevel;
    lstrcpynW(request.path, filename, MAX_PATH);
    return Request(request, text);
}

/// Requests the loaded library's known formats, codecs or parameters.
bool MediaInfoLibrary::Query(LibraryCommand command, wchar_t** text) {
    LibraryRequest request = LibraryRequest{};
    request.command = command;
    return Request(request, text);
}

/// Reports whether a usable worker remains connected without a recorded failure.
bool MediaInfoLibrary::IsLoaded() const {
    return process && !failed && WaitForSingleObject(process, 0) == WAIT_TIMEOUT;
}

/// Returns the path of the selected MediaInfo DLL.
const wchar_t* MediaInfoLibrary::GetPath() const {
    return path;
}

/// Returns the version string reported by the selected MediaInfo DLL.
const wchar_t* MediaInfoLibrary::GetVersion() const {
    return version;
}

/// Returns the most recent library or worker diagnostic.
const wchar_t* MediaInfoLibrary::GetError() const {
    return error;
}
