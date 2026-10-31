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

#include "SettingsStorage.h"

/// Stores a report LOGFONT together with the DPI at which it was selected.
struct SavedFont {
    LOGFONTW font;
    UINT dpi;
};

/// Matches native monitor information for dynamically resolved work-area queries.
struct NativeMonitorInfo {
    DWORD size;
    RECT monitor;
    RECT work;
    DWORD flags;
};

/// Optional monitor-selection and work-area entry points.
typedef HANDLE(WINAPI* MonitorFromRectFunction)(const RECT*, DWORD);
typedef BOOL(WINAPI* GetMonitorInfoFunction)(HANDLE, NativeMonitorInfo*);

/// Shared option bits, trace-level mask and the mutex protecting combined updates.
static const DWORD fullParsingOption = 0x01;
static const DWORD advancedModeOption = 0x02;
static const DWORD multipleInstancesOption = 0x04;
static const DWORD traceLevelMask = 0x18;
static const DWORD wordWrapOption = 0x20;
static const char optionsMutexName[] = "FortSoft.MediaInfo.Options";

/// Current-user registry location for viewer preferences and recent-file history.
static const wchar_t settingsKey[] = L"Software\\FortSoft\\MediaInfo";

/// Reads a typed application setting from the current user registry key.
static bool ReadSetting(const wchar_t* name, DWORD type, void* data, DWORD* bytes) {
    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, settingsKey, 0, KEY_QUERY_VALUE, &key) != ERROR_SUCCESS) {
        return false;
    }
    DWORD actualType = 0;
    LONG result = RegQueryValueExW(key, name, nullptr, &actualType, static_cast<BYTE*>(data), bytes);
    RegCloseKey(key);
    return result == ERROR_SUCCESS && actualType == type;
}

/// Writes a typed application setting to the current user registry key.
static bool WriteSetting(const wchar_t* name, DWORD type, const void* data, DWORD bytes) {
    HKEY key = nullptr;
    DWORD disposition = 0;
    if (RegCreateKeyExW(HKEY_CURRENT_USER, settingsKey, 0, nullptr, 0, KEY_SET_VALUE, nullptr, &key,
            &disposition) != ERROR_SUCCESS) {
        return false;
    }
    LONG result = RegSetValueExW(key, name, 0, type, static_cast<const BYTE*>(data), bytes);
    RegCloseKey(key);
    return result == ERROR_SUCCESS;
}

/// Reads the shared Boolean options, with every switch disabled by default.
static DWORD LoadOptions() {
    DWORD value = 0;
    DWORD bytes = sizeof(value);
    return ReadSetting(L"Options", REG_DWORD, &value, &bytes) && bytes == sizeof(value) ? value : 0;
}

/// Changes selected option bits while preserving concurrent changes to the remaining bits.
static bool SaveOption(DWORD mask, DWORD bits) {
    HANDLE mutex = CreateMutexA(nullptr, FALSE, optionsMutexName);
    if (!mutex) {
        return false;
    }
    DWORD wait = WaitForSingleObject(mutex, INFINITE);
    bool saved = false;
    if (wait == WAIT_OBJECT_0 || wait == WAIT_ABANDONED) {
        DWORD value = LoadOptions();
        value = value & ~mask | bits & mask;
        saved = WriteSetting(L"Options", REG_DWORD, &value, sizeof(value));
        ReleaseMutex(mutex);
    }
    CloseHandle(mutex);
    return saved;
}

/// Loads one consistent saved combination for newly opened tabs, with all options disabled by default.
void LoadReportOptionsSetting(bool& fullParsing, bool& advancedMode, UINT& traceLevel) {
    DWORD options = LoadOptions();
    fullParsing = (options & fullParsingOption) != 0;
    advancedMode = (options & advancedModeOption) != 0;
    traceLevel = (options & traceLevelMask) >> 3;
}

/// Persists the full report-option combination for newly opened tabs in one shared-option update.
bool SaveReportOptionsSetting(bool fullParsing, bool advancedMode, UINT traceLevel) {
    DWORD bits =
        (fullParsing ? fullParsingOption : 0) | (advancedMode ? advancedModeOption : 0) | traceLevel << 3;
    return traceLevel < 4 && SaveOption(fullParsingOption | advancedModeOption | traceLevelMask, bits);
}

/// Loads the remembered wrapping default for new report tabs, disabled by default.
bool LoadWordWrapSetting() {
    return (LoadOptions() & wordWrapOption) != 0;
}

/// Persists the last manually selected wrapping state for new report tabs.
bool SaveWordWrapSetting(bool enabled) {
    return SaveOption(wordWrapOption, enabled ? wordWrapOption : 0);
}

/// Loads the optional permission for multiple instances, disabled by default.
bool LoadMultipleInstancesSetting() {
    return (LoadOptions() & multipleInstancesOption) != 0;
}

/// Persists the committed permission for multiple application instances.
bool SaveMultipleInstancesSetting(bool enabled) {
    return SaveOption(multipleInstancesOption, enabled ? multipleInstancesOption : 0);
}

/// Loads the saved manual MediaInfo DLL path or leaves automatic discovery selected.
void LoadLibrarySetting(wchar_t* path, DWORD capacity) {
    DWORD bytes = capacity * sizeof(wchar_t);
    if (!ReadSetting(L"LibraryPath", REG_SZ, path, &bytes)) {
        path[0] = 0;
    }
    path[capacity - 1] = 0;
}

/// Loads and bounds the saved tab-caption length, defaulting to eighty characters.
UINT LoadTabNameLengthSetting() {
    DWORD length = 0;
    DWORD bytes = sizeof(length);
    return ReadSetting(L"TabNameLength", REG_DWORD, &length, &bytes)
        && bytes == sizeof(length)
        && length >= minimumTabNameLength
        && length <= maximumTabNameLength ? length : defaultTabNameLength;
}

/// Persists the validated tab-caption length.
bool SaveTabNameLengthSetting(UINT length) {
    DWORD value = length;
    return WriteSetting(L"TabNameLength", REG_DWORD, &value, sizeof(value));
}

/// Reports whether saved recent-file paths are present in the registry.
bool HasRecentFilesSetting() {
    DWORD bytes = 0;
    return ReadSetting(L"RecentFiles", REG_MULTI_SZ, nullptr, &bytes) && bytes > 2 * sizeof(wchar_t);
}

/// Persists the manual MediaInfo DLL path.
bool SaveLibrarySetting(const wchar_t* path) {
    return WriteSetting(L"LibraryPath", REG_SZ, path, (lstrlenW(path) + 1) * sizeof(wchar_t));
}

/// Loads the saved optional manual curl DLL path.
void LoadCurlSetting(wchar_t* path, DWORD capacity) {
    DWORD bytes = capacity * sizeof(wchar_t);
    if (!ReadSetting(L"CurlPath", REG_SZ, path, &bytes)) {
        path[0] = 0;
    }
    path[capacity - 1] = 0;
}

/// Persists the optional manual curl DLL path.
bool SaveCurlSetting(const wchar_t* path) {
    return WriteSetting(L"CurlPath", REG_SZ, path, (lstrlenW(path) + 1) * sizeof(wchar_t));
}

/// Loads a saved supported interface-language index or indicates system detection.
int LoadApplicationLanguageSetting() {
    DWORD language = 0;
    DWORD bytes = sizeof(language);
    return ReadSetting(L"Language", REG_DWORD, &language, &bytes)
        && bytes == sizeof(language)
        && language < 36 ? static_cast<int>(language) : -1;
}

/// Persists the selected application-interface language index.
bool SaveApplicationLanguageSetting(int language) {
    DWORD value = static_cast<DWORD>(language);
    return WriteSetting(L"Language", REG_DWORD, &value, sizeof(value));
}

/// Loads the independent report-language code or custom table path, defaulting to original English.
void LoadReportLanguageSetting(wchar_t* selection, DWORD capacity) {
    DWORD bytes = capacity * sizeof(wchar_t);
    if (!ReadSetting(L"ReportLanguage", REG_SZ, selection, &bytes)) {
        selection[0] = 0;
    }
    selection[capacity - 1] = 0;
}

/// Persists the independent report-language code or custom table path.
bool SaveReportLanguageSetting(const wchar_t* selection) {
    return WriteSetting(L"ReportLanguage", REG_SZ, selection, (lstrlenW(selection) + 1) * sizeof(wchar_t));
}

/// Loads the report font and its saved DPI while preserving default-font selection.
bool LoadFontSetting(LOGFONTW* font, UINT* dpi) {
    SavedFont saved = SavedFont{};
    DWORD bytes = sizeof(saved);
    if (!ReadSetting(L"ReportFont", REG_BINARY, &saved,
            &bytes) || bytes != sizeof(saved) || !saved.dpi || saved.dpi > 960) {
        return false;
    }
    saved.font.lfFaceName[LF_FACESIZE - 1] = 0;
    *font = saved.font;
    *dpi = saved.dpi;
    return true;
}

/// Persists the report font and the DPI at which it was selected.
bool SaveFontSetting(const LOGFONTW& font, UINT dpi) {
    SavedFont saved = SavedFont{ font, dpi };
    return WriteSetting(L"ReportFont", REG_BINARY, &saved, sizeof(saved));
}

/// Loads the shared folder most recently selected through Open or Open Folder.
void LoadOpenFolderSetting(wchar_t* folder, DWORD capacity) {
    DWORD bytes = capacity * sizeof(wchar_t);
    if (!ReadSetting(L"OpenFolder", REG_SZ, folder, &bytes)) {
        folder[0] = 0;
    }
    folder[capacity - 1] = 0;
}

/// Persists a selected folder or the containing folder of a selected media file.
bool SaveOpenFolderSetting(const wchar_t* path, bool filename) {
    wchar_t folder[MAX_PATH];
    lstrcpynW(folder, path, MAX_PATH);
    if (filename) {
        wchar_t* end = nullptr;
        for (wchar_t* cursor = folder; *cursor; ++cursor) {
            if (*cursor == L'\\' || *cursor == L'/') {
                end = cursor;
            }
        }
        if (!end) {
            return false;
        }
        end[1] = 0;
    }
    return WriteSetting(L"OpenFolder", REG_SZ, folder, (lstrlenW(folder) + 1) * sizeof(wchar_t));
}

/// Loads the most recent export folder and output format.
void LoadExportSetting(wchar_t* folder, DWORD capacity, DWORD* type) {
    DWORD bytes = capacity * sizeof(wchar_t);
    if (!ReadSetting(L"ExportFolder", REG_SZ, folder, &bytes)) {
        folder[0] = 0;
    }
    folder[capacity - 1] = 0;
    bytes = sizeof(*type);
    if (!ReadSetting(L"ExportFormat", REG_DWORD, type,
            &bytes) || bytes != sizeof(*type) || *type < 1 || *type > 11) {
        *type = 2;
    }
}

/// Persists the successful export destination folder and selected output format.
void SaveExportSetting(const wchar_t* filename, DWORD type) {
    wchar_t folder[MAX_PATH];
    lstrcpynW(folder, filename, MAX_PATH);
    wchar_t* end = nullptr;
    for (wchar_t* cursor = folder; *cursor; ++cursor) {
        if (*cursor == L'\\' || *cursor == L'/') {
            end = cursor;
        }
    }
    if (end) {
        end[1] = 0;
        WriteSetting(L"ExportFolder", REG_SZ, folder, (lstrlenW(folder) + 1) * sizeof(wchar_t));
    }
    WriteSetting(L"ExportFormat", REG_DWORD, &type, sizeof(type));
}

/// Loads the saved double-null-terminated recent-file buffer with size validation.
DWORD LoadRecentFilesSetting(wchar_t* paths, DWORD capacity) {
    DWORD bytes = capacity * sizeof(wchar_t);
    if (!ReadSetting(L"RecentFiles", REG_MULTI_SZ, paths,
            &bytes) || bytes < 2 * sizeof(wchar_t) || bytes % sizeof(wchar_t)) {
        return 0;
    }
    DWORD length = bytes / sizeof(wchar_t);
    if (paths[length - 1] || paths[length - 2]) {
        return 0;
    }
    return length;
}

/// Persists the complete recent-file buffer, including its final terminators.
bool SaveRecentFilesSetting(const wchar_t* paths, DWORD length) {
    return WriteSetting(L"RecentFiles", REG_MULTI_SZ, paths, length * sizeof(wchar_t));
}

/// Returns the nearest monitor work area, with the system work-area API retained for older Windows.
RECT WindowWorkArea(const RECT& rectangle) {
    NativeMonitorInfo info = NativeMonitorInfo{};
    info.size = sizeof(info);
    HMODULE user = GetModuleHandleW(L"user32.dll");
    MonitorFromRectFunction fromRect =
        reinterpret_cast<MonitorFromRectFunction>(GetProcAddress(user, "MonitorFromRect"));
    GetMonitorInfoFunction getInfo =
        reinterpret_cast<GetMonitorInfoFunction>(GetProcAddress(user, "GetMonitorInfoW"));
    if (fromRect && getInfo && getInfo(fromRect(&rectangle, 2), &info)) {
        return info.work;
    }
    if (!SystemParametersInfoW(SPI_GETWORKAREA, 0, &info.work, 0)) {
        info.work = RECT{ 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
    }
    return info.work;
}
