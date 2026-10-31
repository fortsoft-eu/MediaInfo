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

#include "LibraryWorker.h"
#include "Localization.h"

/// MediaInfo option values corresponding to the four displayed trace levels.
static const wchar_t* traceLevels[] = { L"0", L"0.5", L"0.9", L"1" };

/// Initializes the isolated worker pipes, export pointers and unloaded library state.
LibraryWorker::LibraryWorker(HANDLE requests, HANDLE responses)
        : module(nullptr), input(requests), output(responses), create(nullptr), destroy(nullptr),
        open(nullptr), close(nullptr), inform(nullptr), option(nullptr) {}

/// Releases the MediaInfo handle, loaded libraries and worker-owned report state.
LibraryWorker::~LibraryWorker() {
    if (module) {
        Stage(LibraryOperation::Unload);
        FreeLibrary(module);
    }
    CloseHandle(input);
    CloseHandle(output);
}

/// Sends the next library-operation stage to the parent process before invoking the DLL.
bool LibraryWorker::Stage(LibraryOperation operation) {
    LibraryReply message = LibraryReply{ librarySignature, LibraryMessageKind::Stage, operation, 0 };
    return WriteLibraryBytes(output, &message, sizeof(message));
}

/// Writes a worker result and its Unicode text to the parent response pipe.
bool LibraryWorker::Reply(bool success, const wchar_t* text) {
    DWORD length = lstrlenW(text);
    LibraryReply message = LibraryReply{
        librarySignature,
        success ? LibraryMessageKind::Success : LibraryMessageKind::Error,
        LibraryOperation::Load,
        length
    };
    return WriteLibraryBytes(output, &message, sizeof(message))
        && WriteLibraryBytes(output, text, length * sizeof(wchar_t));
}

/// Loads and validates MediaInfo exports, configures optional curl and language data and reports its version.
bool LibraryWorker::Load(const wchar_t* filename, const wchar_t* curlPath, const wchar_t* reportLanguage) {
    if (!Stage(LibraryOperation::Load)) {
        return false;
    }
    module = LoadLibraryExW(filename, nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (!module) {
        wchar_t error[256];
        wsprintfW(error, T(TXT_MEDIALIB_LOAD_FAILED), GetLastError());
        Reply(false, error);
        return false;
    }
    create = reinterpret_cast<NewFunction>(GetProcAddress(module, "MediaInfo_New"));
    destroy = reinterpret_cast<DeleteFunction>(GetProcAddress(module, "MediaInfo_Delete"));
    open = reinterpret_cast<OpenFunction>(GetProcAddress(module, "MediaInfo_Open"));
    close = reinterpret_cast<CloseFunction>(GetProcAddress(module, "MediaInfo_Close"));
    inform = reinterpret_cast<InformFunction>(GetProcAddress(module, "MediaInfo_Inform"));
    option = reinterpret_cast<OptionFunction>(GetProcAddress(module, "MediaInfo_Option"));
    if (!create || !destroy || !open || !close || !inform || !option) {
        Reply(false, T(TXT_MEDIALIB_EXPORTS_MISSING));
        return false;
    }
    if (!Stage(LibraryOperation::Version)) {
        return false;
    }
    const wchar_t* version = option(nullptr, L"Info_Version", L"");
    if (!version || !*version) {
        Reply(false, T(TXT_MEDIALIB_VERSION_MISSING));
        return false;
    }
    wchar_t copy[256];
    lstrcpynW(copy, version, 256);
    if (lstrcmpW(copy, L"MediaInfoLib - v0.7.60")) {
        if (!Stage(LibraryOperation::CurlLoad)) {
            return false;
        }
        if (!curl.Discover(filename, curlPath, !lstrcmpW(copy, L"MediaInfoLib - v21.03")) && curlPath[0]) {
            Reply(false, curl.GetError());
            return false;
        }
    }
    if (reportLanguage[0]) {
        if (!Stage(LibraryOperation::Language)) {
            return false;
        }
        wchar_t error[512];
        wchar_t* translation = LoadReportLanguage(reportLanguage, error, 512);
        if (!translation) {
            Reply(false, error);
            return false;
        }
        const wchar_t* result = option(nullptr, L"Language", translation);
        bool accepted = result && !*result;
        HeapFree(GetProcessHeap(), 0, translation);
        if (!accepted) {
            Reply(false, T(TXT_REPORT_LANGUAGE_REJECTED));
            return false;
        }
    }
    return Reply(true, copy);
}

/// Opens one media path through the DLL, copies its unchanged report and closes the media handle.
bool LibraryWorker::Read(const wchar_t* filename, bool advancedMode, bool fullParsing, UINT traceLevel) {
    if (!Stage(LibraryOperation::Option)) {
        return false;
    }
    const wchar_t* parsing = option(nullptr, L"ParseSpeed", fullParsing ? L"1" : L"0.5");
    if (!parsing || *parsing) {
        return Reply(false, T(TXT_PARSING_REJECTED));
    }
    const wchar_t* configured = option(nullptr, L"Complete", advancedMode ? L"1" : L"");
    if (!configured || *configured) {
        return Reply(false, T(TXT_REPORT_DETAIL_REJECTED));
    }
    if (traceLevel >= ARRAYSIZE(traceLevels)) {
        return Reply(false, T(TXT_REPORT_DETAIL_REJECTED));
    }
    const wchar_t* trace = option(nullptr, L"Trace_Level", traceLevels[traceLevel]);
    if (!trace || *trace) {
        return Reply(false, T(TXT_REPORT_DETAIL_REJECTED));
    }
    if (!Stage(LibraryOperation::New)) {
        return false;
    }
    void* handle = create();
    if (!handle) {
        return Reply(false, T(TXT_MEDIA_FILE_HANDLE_FAILED));
    }
    bool success = false;
    wchar_t* copy = nullptr;
    const wchar_t* error = T(TXT_MEDIA_FILE_UNRECOGNIZED);
    if (!Stage(LibraryOperation::Open)) {
        return false;
    }
    if (open(handle, filename)) {
        if (!Stage(LibraryOperation::Inform)) {
            return false;
        }
        const wchar_t* report = inform(handle, 0);
        error = T(TXT_REPORT_COPY_FAILED);
        if (report) {
            if (!Stage(LibraryOperation::Copy)) {
                return false;
            }
            SIZE_T bytes = (static_cast<SIZE_T>(lstrlenW(report)) + 1) * sizeof(wchar_t);
            copy = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0, bytes));
            if (copy) {
                CopyMemory(copy, report, bytes);
                success = true;
            }
        }
    }
    if (!Stage(LibraryOperation::Close)) {
        return false;
    }
    close(handle);
    if (!Stage(LibraryOperation::Delete)) {
        return false;
    }
    destroy(handle);
    bool sent = Reply(success, success ? copy : error);
    if (copy) {
        HeapFree(GetProcessHeap(), 0, copy);
    }
    return sent;
}

/// Returns a library-supplied list of known formats, codecs or parameters.
bool LibraryWorker::Query(LibraryCommand command) {
    const wchar_t* name = nullptr;
    switch (command) {
        case LibraryCommand::Formats:
            name = L"Info_Capacities";
            break;
        case LibraryCommand::Codecs:
            name = L"Info_Codecs";
            break;
        case LibraryCommand::Parameters:
            name = L"Info_Parameters";
            break;
        default:
            break;
    }
    if (!name || !Stage(LibraryOperation::Option)) {
        return false;
    }
    const wchar_t* result = option(nullptr, name, L"");
    return result && *result ? Reply(true, result) : Reply(false, T(TXT_KNOWN_INFO_FAILED));
}

/// Services report requests from the parent until the protocol ends or a pipe fails.
int LibraryWorker::Run(const wchar_t* filename, const wchar_t* curlPath, const wchar_t* reportLanguage) {
    if (!Load(filename, curlPath, reportLanguage)) {
        return 1;
    }
    LibraryRequest request = LibraryRequest{};
    while (ReadLibraryBytes(input, &request, sizeof(request)) && request.command != LibraryCommand::Shutdown) {
        request.path[MAX_PATH - 1] = 0;
        bool replied = request.command == LibraryCommand::Read
            ? Read(request.path, request.advancedMode != 0, request.fullParsing != 0, request.traceLevel)
            : Query(request.command);
        if (!replied) {
            return 1;
        }
    }
    return 0;
}

/// Recognizes the internal worker command line and runs it without creating the viewer interface.
bool DispatchLibraryWorker(int count, wchar_t** arguments, int* result) {
    if (count < 2 || lstrcmpW(arguments[1], L"--mediainfo-worker")) {
        return false;
    }
    *result = 1;
    if (count != 8) {
        return true;
    }
    DWORD values[2] = {};
    for (int index = 0; index < 2; ++index) {
        const wchar_t* cursor = arguments[index + 2];
        if (!*cursor) {
            return true;
        }
        while (*cursor) {
            if (*cursor < L'0' || *cursor > L'9' || values[index] > (0xFFFFFFFF - (*cursor - L'0')) / 10) {
                return true;
            }
            values[index] = values[index] * 10 + *cursor++ - L'0';
        }
    }
    DWORD language = 0;
    for (const wchar_t* cursor = arguments[7]; *cursor; ++cursor) {
        if (*cursor < L'0' || *cursor > L'9' || language >= applicationLanguageCount) {
            return true;
        }
        language = language * 10 + *cursor - L'0';
    }
    if (language >= applicationLanguageCount) {
        return true;
    }
    SetApplicationLanguage(static_cast<int>(language));
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
    LibraryWorker worker(reinterpret_cast<HANDLE>(values[0]), reinterpret_cast<HANDLE>(values[1]));
    *result = worker.Run(arguments[4], arguments[5], arguments[6]);
    return true;
}
