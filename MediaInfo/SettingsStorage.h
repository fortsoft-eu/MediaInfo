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

/// Default and supported bounds for shortened tab captions.
static const UINT defaultTabNameLength = 80;
static const UINT minimumTabNameLength = 8;
static const UINT maximumTabNameLength = 255;

/// Loads one consistent saved combination for newly opened tabs, with all options disabled by default.
void LoadReportOptionsSetting(bool& fullParsing, bool& advancedMode, UINT& traceLevel);

/// Persists the full report-option combination for newly opened tabs in one shared-option update.
bool SaveReportOptionsSetting(bool fullParsing, bool advancedMode, UINT traceLevel);

/// Loads the optional permission for multiple instances, disabled by default.
bool LoadMultipleInstancesSetting();

/// Persists the committed permission for multiple application instances.
bool SaveMultipleInstancesSetting(bool enabled);

/// Loads and bounds the saved tab-caption length, defaulting to eighty characters.
UINT LoadTabNameLengthSetting();

/// Persists the validated tab-caption length.
bool SaveTabNameLengthSetting(UINT length);

/// Reports whether saved recent-file paths are present in the registry.
bool HasRecentFilesSetting();

/// Loads the saved manual MediaInfo DLL path or leaves automatic discovery selected.
void LoadLibrarySetting(wchar_t* path, DWORD capacity);

/// Persists the manual MediaInfo DLL path.
bool SaveLibrarySetting(const wchar_t* path);

/// Loads the saved optional manual curl DLL path.
void LoadCurlSetting(wchar_t* path, DWORD capacity);

/// Persists the optional manual curl DLL path.
bool SaveCurlSetting(const wchar_t* path);

/// Loads a saved supported interface-language index or indicates system detection.
int LoadApplicationLanguageSetting();

/// Persists the selected application-interface language index.
bool SaveApplicationLanguageSetting(int language);

/// Loads the independent report-language code or custom table path, defaulting to original English.
void LoadReportLanguageSetting(wchar_t* selection, DWORD capacity);

/// Persists the independent report-language code or custom table path.
bool SaveReportLanguageSetting(const wchar_t* selection);

/// Loads the report font and its saved DPI while preserving default-font selection.
bool LoadFontSetting(LOGFONTW* font, UINT* dpi);

/// Persists the report font and the DPI at which it was selected.
bool SaveFontSetting(const LOGFONTW& font, UINT dpi);

/// Loads the shared folder most recently selected through Open or Open Folder.
void LoadOpenFolderSetting(wchar_t* folder, DWORD capacity);

/// Persists a selected folder or the containing folder of a selected media file.
bool SaveOpenFolderSetting(const wchar_t* path, bool filename = false);

/// Loads the most recent export folder and output format.
void LoadExportSetting(wchar_t* folder, DWORD capacity, DWORD* type);

/// Persists the successful export destination folder and selected output format.
void SaveExportSetting(const wchar_t* filename, DWORD type);

/// Loads the saved double-null-terminated recent-file buffer with size validation.
DWORD LoadRecentFilesSetting(wchar_t* paths, DWORD capacity);

/// Persists the complete recent-file buffer, including its final terminators.
bool SaveRecentFilesSetting(const wchar_t* paths, DWORD length);

/// Returns the nearest monitor work area, with the system work-area API retained for older Windows.
RECT WindowWorkArea(const RECT& rectangle);
