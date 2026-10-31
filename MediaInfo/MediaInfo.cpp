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

#include "MediaInfo.h"
#include "MainForm.h"
#include "LibraryWorker.h"
#include "Localization.h"
#include "SettingsStorage.h"
#include "SystemDialogTemplate.h"
#include "SelectionEdit.h"
#include "ComboBoxSupport.h"
#include "ModernFileDialog.h"
#include "JpegEncoder.h"
#include "WebpEncoder.h"
#include "resource.h"
#include <commdlg.h>
#include <commctrl.h>
#include <shellapi.h>
#include <shlobj.h>
#include <usp10.h>

#undef small

/// Dynamically resolved DPI and visual-style entry points.
typedef UINT(WINAPI* GetDpiFunction)(HWND);
typedef BOOL(WINAPI* IsThemeActiveFunction)();
typedef HANDLE(WINAPI* GetWindowThemeFunction)(HWND);
typedef HANDLE(WINAPI* OpenThemeFunction)(HWND, LPCWSTR);
typedef HRESULT(WINAPI* CloseThemeFunction)(HANDLE);
typedef HRESULT(WINAPI* ThemeContentFunction)(HANDLE, HDC, int, int, const RECT*, RECT*);
typedef HRESULT(WINAPI* ThemePartSizeFunction)(HANDLE, HDC, int, int, const RECT*, int, SIZE*);

/// Optional system API used to detect the interface language.
typedef LANGID(WINAPI* GetUserDefaultUiLanguageFunction)();

/// Pairs an interface locale code with its Windows language identifier.
struct ApplicationLanguageEntry {
    const wchar_t* code;
    LANGID id;
};

/// Retains Unicode line-break analysis and its source text for the information edit.
struct InformationWordBreakState {
    SCRIPT_STRING_ANALYSIS analysis;
    wchar_t* text;
    int length;
};

/// Stores ascent, descent and spacing for text-baseline and line-height calculations.
struct UiTextLine {
    LONG ascent;
    LONG descent;
    LONG gap;
};

/// Buffers GIF data blocks and packed codes while retaining the output-write status.
struct GifWriter {
    HANDLE file;
    BYTE block[255];
    DWORD packed;
    int bits;
    int count;
    bool success;
};

/// Maps a rendered RGB color to its exact GIF palette index.
struct GifColor {
    DWORD color;
    BYTE index;
};

/// Retains dialog layout, pending settings and committed values used by Apply and Cancel.
struct PreferencesData {
    HWND window;
    HFONT uiFont;
    MediaInfoLibrary* library;
    LOGFONTW* appliedFont;
    UINT* appliedDpi;
    const PreferencesCallbacks* callbacks;
    SIZE buttonSize;
    LOGFONTW font;
    UINT dpi;
    int widthReduction;
    int contentHeight;
    int scrollPosition;
    int wheelRemainder;
    int originalLanguage;
    int language;
    UINT originalTabNameLength;
    bool originalMultipleInstances;
    bool ownsUiFont;
    bool applied;
    bool applyPending;
    bool reportLanguageChanged;
    wchar_t originalPath[MAX_PATH];
    wchar_t originalCurlPath[MAX_PATH];
    wchar_t originalReportLanguage[MAX_PATH];
    wchar_t reportLanguage[MAX_PATH];
};

/// Associates a stable export identifier with its caption, filter pattern and default extension.
struct ExportChoice {
    DWORD type;
    TextId label;
    const wchar_t* pattern;
    const wchar_t* extension;
};

/// Stores only the export choices available to the current Save dialog.
struct ExportDialogData {
    const ExportChoice* choices[11];
    UINT count;
};

/// Optional Uniscribe entry points and cached analysis for information-edit word wrapping.
static HMODULE informationUniscribe;
static decltype(&ScriptStringAnalyse) informationStringAnalyse;
static decltype(&ScriptStringFree) informationStringFree;
static decltype(&ScriptString_pLogAttr) informationStringLogAttr;
static InformationWordBreakState informationWordBreakState;

/// Current interface-language index shared by localization lookups.
static LONG currentLanguage = LANG_EN_US;

/// Supported interface locale codes and Windows identifiers in AppLanguage order.
static constexpr ApplicationLanguageEntry applicationLanguages[] = {
    { L"cs-CZ", 0x0405 },
    { L"en-US", 0x0409 },
    { L"en-GB", 0x0809 },
    { L"en-AU", 0x0C09 },
    { L"de-DE", 0x0407 },
    { L"fr-FR", 0x040C },
    { L"es-ES", 0x0C0A },
    { L"it-IT", 0x0410 },
    { L"pt-PT", 0x0816 },
    { L"pl-PL", 0x0415 },
    { L"sk-SK", 0x041B },
    { L"da-DK", 0x0406 },
    { L"fi-FI", 0x040B },
    { L"is-IS", 0x040F },
    { L"nb-NO", 0x0414 },
    { L"sv-SE", 0x041D },
    { L"tr-TR", 0x041F },
    { L"et-EE", 0x0425 },
    { L"ga-IE", 0x083C },
    { L"lt-LT", 0x0427 },
    { L"lv-LV", 0x0426 },
    { L"hu-HU", 0x040E },
    { L"mt-MT", 0x043A },
    { L"nl-NL", 0x0413 },
    { L"ro-RO", 0x0418 },
    { L"el-GR", 0x0408 },
    { L"bs-Latn-BA", 0x141A },
    { L"hr-HR", 0x041A },
    { L"sl-SI", 0x0424 },
    { L"cnr-Latn-ME", 0x301A },
    { L"be-BY", 0x0423 },
    { L"bg-BG", 0x0402 },
    { L"mk-MK", 0x042F },
    { L"sr-Cyrl-RS", 0x281A },
    { L"uk-UA", 0x0422 },
    { L"ru-RU", 0x0419 },
};

/// System-library path suffixes appended to the Windows system directory.
static const wchar_t themeLibrarySuffix[] = L"\\uxtheme.dll";
static const wchar_t uniscribeLibrarySuffix[] = L"\\usp10.dll";

/// Native button-caption measurement message.
static const UINT buttonGetIdealSize = 0x1601;

/// Maximum number of source bytes copied by Create a Header File.
static const DWORD headerByteLimit = 524288;

/// TIFF directory layout and the start of values stored after its entries.
static const WORD tiffTagCount = 14;
static const DWORD tiffValuesOffset = 8 + 2 + tiffTagCount * 12 + 4;

/// Image-export diagnostics indexed in the same order as the six image formats.
static const TextId imageErrors[] = {
    TXT_BMP_EXPORT_FAILED,
    TXT_GIF_EXPORT_FAILED,
    TXT_JPEG_EXPORT_FAILED,
    TXT_PNG_EXPORT_FAILED,
    TXT_TIFF_EXPORT_FAILED,
    TXT_WEBP_EXPORT_FAILED
};

/// Preferences refresh timer, control-subclass property and label-to-field keyboard routing.
static const UINT_PTR preferencesTimer = 1;
static const wchar_t preferencesControlProperty[] = L"Preferences.OriginalProc";
static const int preferencesLabelFields[][2] = {
    { IDC_DLL_LABEL, IDC_DLL_PATH },
    { IDC_CURL_LABEL, IDC_CURL_PATH },
    { IDC_FONT_LABEL, IDC_FONT_CHOOSE },
    { IDC_SMOOTHING_LABEL, IDC_SMOOTHING },
    { IDC_LANGUAGE_LABEL, IDC_LANGUAGE },
    { IDC_REPORT_LABEL, IDC_REPORT_LANGUAGE },
    { IDC_TAB_NAME_LABEL, IDC_TAB_NAME_LENGTH }
};

/// Stable export identifiers and their native Save-dialog filters.
static const ExportChoice exportChoices[] = {
    { 1, TXT_TEXT_FORMAT, L"*.txt", L"txt" },
    { 2, TXT_TEXT_UTF8_FORMAT, L"*.txt", L"txt" },
    { 3, TXT_TEXT_UTF8_BOM_FORMAT, L"*.txt", L"txt" },
    { 4, TXT_TEXT_UTF16_BE_FORMAT, L"*.txt", L"txt" },
    { 5, TXT_TEXT_UTF16_LE_FORMAT, L"*.txt", L"txt" },
    { 6, TXT_BMP_FORMAT, L"*.bmp", L"bmp" },
    { 7, TXT_GIF_FORMAT, L"*.gif", L"gif" },
    { 8, TXT_JPEG_FORMAT, L"*.jpg", L"jpg" },
    { 9, TXT_PNG_FORMAT, L"*.png", L"png" },
    { 10, TXT_TIFF_FORMAT, L"*.tif", L"tif" },
    { 11, TXT_WEBP_FORMAT, L"*.webp", L"webp" }
};

/// Native file-dialog filter templates whose captions use the interface translations.
const LocalizedFileFilter mediaFilters[] = {
    { TXT_MEDIA_FILES,
    L"*.avi;*.mkv;*.mp4;*.mov;*.mpg;*.mpeg;*.ts;*.m2ts;*.wmv;*.webm;*.mp3;*.flac;*.wav;*.ogg;*.m4a;"
    L"*.aac" },
    { TXT_ALL_FILES, L"*.*" },
    { TXT_COUNT, nullptr }
};

const LocalizedFileFilter libraryFilters[] = {
    { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
    { TXT_DLL_FILES, L"*.dll" },
    { TXT_ALL_FILES, L"*.*" },
    { TXT_COUNT, nullptr }
};

const LocalizedFileFilter curlFilters[] = {
    { TXT_CURL_LIBRARY, L"libcurl.dll" },
    { TXT_DLL_FILES, L"*.dll" },
    { TXT_ALL_FILES, L"*.*" },
    { TXT_COUNT, nullptr }
};

const LocalizedFileFilter reportLanguageFilters[] = {
    { TXT_CSV_FORMAT, L"*.csv" },
    { TXT_ALL_FILES, L"*.*" },
    { TXT_COUNT, nullptr }
};

const LocalizedFileFilter headerInputFilters[] = {
    { TXT_ALL_FILES, L"*.*" },
    { TXT_COUNT, nullptr }
};

const LocalizedFileFilter headerOutputFilters[] = {
    { TXT_HEADER_FORMAT, L"*.header" },
    { TXT_ALL_FILES, L"*.*" },
    { TXT_COUNT, nullptr }
};

/// Main-window class and the mutex that serializes concurrent startup attempts.
const wchar_t viewerWindowClass[] = L"FortSoft.MediaInfo.Window";

static const char startupMutexName[] = "FortSoft.MediaInfo.Startup";

/// Maps a Windows language identifier to one of the supported interface variants.
int ApplicationLanguageFromLangId(LANGID language) {
    if (PRIMARYLANGID(language) == LANG_ENGLISH) {
        if (SUBLANGID(language) == SUBLANG_ENGLISH_UK) {
            return LANG_EN_GB;
        }
        if (SUBLANGID(language) == SUBLANG_ENGLISH_AUS) {
            return LANG_EN_AU;
        }
        return LANG_EN_US;
    }
    if (PRIMARYLANGID(language) == LANG_CROATIAN) {
        switch (SUBLANGID(language)) {
            case 5:
            case 8:
                return LANG_BS;
            case 11:
            case 12:
                return LANG_CNR;
            case 2:
            case 3:
            case 6:
            case 7:
            case 9:
            case 10:
                return LANG_SR;
            default:
                return LANG_HR;
        }
    }
    for (int index = 0; index < applicationLanguageCount; ++index) {
        if (PRIMARYLANGID(language) == PRIMARYLANGID(applicationLanguages[index].id)) {
            return index;
        }
    }
    return LANG_EN_US;
}

/// Loads a saved interface choice or detects the Windows language with the legacy API path.
void InitializeApplicationLanguage() {
    int language = LoadApplicationLanguageSetting();
    if (language < 0 || language >= applicationLanguageCount) {
        HMODULE kernel = GetModuleHandleW(L"kernel32.dll");
        GetUserDefaultUiLanguageFunction getLanguage =
            reinterpret_cast<GetUserDefaultUiLanguageFunction>(GetProcAddress(kernel,
                "GetUserDefaultUILanguage"));
        language = ApplicationLanguageFromLangId(getLanguage ? getLanguage() : GetUserDefaultLangID());
    }
    SetApplicationLanguage(language);
}

/// Returns the active application-interface language index.
int GetApplicationLanguage() {
    return currentLanguage;
}

/// Sets the active interface variant while constraining invalid indices to the default.
void SetApplicationLanguage(int language) {
    InterlockedExchange(&currentLanguage,
        language >= 0 && language < applicationLanguageCount ? language : LANG_EN_US);
}

/// Returns the native display name of a supported interface language.
const wchar_t* ApplicationLanguageName(int language) {
    return GetLocalizedText(static_cast<AppLanguage>(
        language >= 0 && language < applicationLanguageCount ? language : LANG_EN_US), TXT_LANGUAGE_NAME);
}

/// Returns the locale code of a supported interface language.
const wchar_t* ApplicationLanguageCode(int language) {
    int index = language >= 0 && language < applicationLanguageCount ? language : LANG_EN_US;
    return applicationLanguages[index].code;
}

/// Returns a borrowed localized UI string in the current application language.
const wchar_t* T(TextId id) {
    return GetLocalizedText(static_cast<AppLanguage>(GetApplicationLanguage()), id);
}

/// Recognizes Unicode whitespace in information text.
bool IsTextWhitespace(wchar_t character) {
    WORD type = 0;
    return GetStringTypeW(CT_CTYPE1, &character, 1, &type) && type & C1_SPACE;
}

/// Releases the cached Unicode boundary analysis and its retained text.
void ResetInformationWordBreak() {
    if (informationWordBreakState.analysis) {
        informationStringFree(&informationWordBreakState.analysis);
        informationWordBreakState.analysis = nullptr;
    }
    if (informationWordBreakState.text) {
        HeapFree(GetProcessHeap(), 0, informationWordBreakState.text);
        informationWordBreakState.text = nullptr;
    }
    informationWordBreakState.length = 0;
}

/// Supplies the same native Unicode word and cluster boundaries to the Help and About edits.
static int CALLBACK InformationWordBreakProc(wchar_t* text, int position, int length, int code) {
    if (length <= 0) {
        return 0;
    }
    if (position < 0) {
        position = 0;
    } else if (position > length) {
        position = length;
    }
    bool matches = informationWordBreakState.length == length;
    if (matches) {
        for (int index = 0; index < length; ++index) {
            if (informationWordBreakState.text[index] != text[index]) {
                matches = false;
                break;
            }
        }
    }
    if (!matches) {
        ResetInformationWordBreak();
        SIZE_T bytes = static_cast<SIZE_T>(length) * sizeof(wchar_t);
        informationWordBreakState.text = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0, bytes));
        if (informationWordBreakState.text) {
            CopyMemory(informationWordBreakState.text, text, bytes);
            informationWordBreakState.length = length;
            HRESULT status = informationStringAnalyse(nullptr, informationWordBreakState.text,
                length, 0, -1, SSA_BREAK, 0, nullptr, nullptr, nullptr, nullptr, nullptr,
                &informationWordBreakState.analysis);
            if (FAILED(status)) {
                ResetInformationWordBreak();
            }
        }
    }
    const SCRIPT_LOGATTR* attributes = informationWordBreakState.analysis
        ? informationStringLogAttr(informationWordBreakState.analysis)
        : nullptr;
    if (!attributes) {
        ResetInformationWordBreak();
        if (code == WB_ISDELIMITER) {
            return position < length && IsTextWhitespace(text[position]);
        }
        return code == WB_LEFT ? 0 : length;
    }
    if (code == WB_ISDELIMITER) {
        return position < length && attributes[position].fWhiteSpace;
    }
    if (code == WB_LEFT) {
        if (position == length) {
            position--;
        }
        while (position > 0 && (!attributes[position].fCharStop
                || !attributes[position].fSoftBreak && !attributes[position - 1].fWhiteSpace)) {
            position--;
        }
    } else if (code == WB_RIGHT) {
        if (position < length) {
            position++;
        }
        while (position < length && (!attributes[position].fCharStop
                || !attributes[position].fSoftBreak && !attributes[position - 1].fWhiteSpace)) {
            position++;
        }
    }
    return position;
}

/// Installs Unicode wrapping when system Uniscribe is available without requiring it on Windows NT 4.0.
void InstallInformationWordBreak(HWND edit) {
    if (!informationUniscribe) {
        wchar_t path[MAX_PATH];
        UINT length = GetSystemDirectoryW(path, MAX_PATH);
        if (!length || length + lstrlenW(uniscribeLibrarySuffix) >= MAX_PATH) {
            return;
        }
        lstrcatW(path, uniscribeLibrarySuffix);
        informationUniscribe = LoadLibraryW(path);
        if (!informationUniscribe) {
            return;
        }
        informationStringAnalyse =
            reinterpret_cast<decltype(informationStringAnalyse)>(GetProcAddress(informationUniscribe,
                "ScriptStringAnalyse"));
        informationStringFree =
            reinterpret_cast<decltype(informationStringFree)>(GetProcAddress(informationUniscribe,
                "ScriptStringFree"));
        informationStringLogAttr =
            reinterpret_cast<decltype(informationStringLogAttr)>(GetProcAddress(informationUniscribe,
                "ScriptString_pLogAttr"));
        if (!informationStringAnalyse || !informationStringFree || !informationStringLogAttr) {
            FreeLibrary(informationUniscribe);
            informationUniscribe = nullptr;
            return;
        }
    }
    SendMessageW(edit, EM_SETWORDBREAKPROC, 0, reinterpret_cast<LPARAM>(InformationWordBreakProc));
}

/// Reads the window DPI dynamically, retaining device-context metrics on older Windows.
UINT WindowDpi(HWND window) {
    GetDpiFunction function =
        reinterpret_cast<GetDpiFunction>(GetProcAddress(GetModuleHandleW(L"user32.dll"), "GetDpiForWindow"));
    if (function && window) {
        return function(window);
    }
    HDC dc = GetDC(window);
    UINT dpi = dc ? GetDeviceCaps(dc, LOGPIXELSY) : 96;
    if (dc) {
        ReleaseDC(window, dc);
    }
    return dpi ? dpi : 96;
}

/// Reports whether visual styles are active for Windows and the current application.
bool AreVisualStylesActive() {
    wchar_t path[MAX_PATH];
    UINT length = GetSystemDirectoryW(path, MAX_PATH);
    if (!length || length + lstrlenW(themeLibrarySuffix) >= MAX_PATH) {
        return false;
    }
    lstrcatW(path, themeLibrarySuffix);
    HMODULE module = LoadLibraryW(path);
    if (!module) {
        return false;
    }
    IsThemeActiveFunction themeActive =
        reinterpret_cast<IsThemeActiveFunction>(GetProcAddress(module, "IsThemeActive"));
    IsThemeActiveFunction appThemed =
        reinterpret_cast<IsThemeActiveFunction>(GetProcAddress(module, "IsAppThemed"));
    bool active = themeActive && appThemed && themeActive() && appThemed();
    FreeLibrary(module);
    return active;
}

/// Creates the current system message font at the window DPI.
HFONT CreateUiFont(HWND window) {
    NONCLIENTMETRICSW metrics = NONCLIENTMETRICSW{};
    metrics.cbSize = sizeof(metrics);
    if (SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, sizeof(metrics), &metrics, 0)) {
        HDC dc = GetDC(nullptr);
        int systemDpi = dc ? GetDeviceCaps(dc, LOGPIXELSY) : 96;
        if (dc) {
            ReleaseDC(nullptr, dc);
        }
        metrics.lfMessageFont.lfHeight =
            MulDiv(metrics.lfMessageFont.lfHeight, WindowDpi(window), systemDpi ? systemDpi : 96);
        return CreateFontIndirectW(&metrics.lfMessageFont);
    }
    LOGFONTW font = LOGFONTW{};
    font.lfHeight = -MulDiv(8, WindowDpi(window), 72);
    font.lfCharSet = DEFAULT_CHARSET;
    lstrcpyW(font.lfFaceName, L"MS Shell Dlg");
    return CreateFontIndirectW(&font);
}

/// Marks a requested installed font as found and stops font enumeration.
static int CALLBACK FindFont(const LOGFONTW*, const TEXTMETRICW*, DWORD, LPARAM parameter) {
    *reinterpret_cast<bool*>(parameter) = true;
    return 0;
}

/// Checks whether the requested font face is installed.
static bool IsFontAvailable(const wchar_t* face) {
    HDC dc = GetDC(nullptr);
    if (!dc) {
        return false;
    }
    LOGFONTW font = LOGFONTW{};
    font.lfCharSet = DEFAULT_CHARSET;
    lstrcpyW(font.lfFaceName, face);
    bool found = false;
    EnumFontFamiliesExW(dc, &font, FindFont, reinterpret_cast<LPARAM>(&found), 0);
    ReleaseDC(nullptr, dc);
    return found;
}

/// Creates the About license font using Consolas with Courier New as its availability fallback.
HFONT CreateAboutFont(HWND window) {
    LOGFONTW font = LOGFONTW{};
    font.lfHeight = -MulDiv(8, WindowDpi(window), 72);
    font.lfWeight = FW_NORMAL;
    font.lfCharSet = ANSI_CHARSET;
    font.lfPitchAndFamily = FIXED_PITCH | FF_MODERN;
    bool consolas = IsFontAvailable(L"Consolas");
    lstrcpyW(font.lfFaceName, consolas ? L"Consolas" : L"Courier New");
    HFONT result = CreateFontIndirectW(&font);
    if (!result && consolas) {
        lstrcpyW(font.lfFaceName, L"Courier New");
        result = CreateFontIndirectW(&font);
    }
    return result;
}

/// Checks the system antialiasing capability and display depth before exposing ClearType.
bool IsClearTypeAvailable() {
    DWORD type = 0;
    if (!SystemParametersInfoW(0x200A, 0, &type, 0)) {
        return false;
    }
    HDC dc = GetDC(nullptr);
    if (!dc) {
        return false;
    }
    bool available = GetDeviceCaps(dc, BITSPIXEL) * GetDeviceCaps(dc, PLANES) > 8;
    ReleaseDC(nullptr, dc);
    return available;
}

/// Chooses ClearType when supported and ordinary GDI antialiasing otherwise.
BYTE DefaultReportFontQuality() {
    return IsClearTypeAvailable() ? 5 : ANTIALIASED_QUALITY;
}

/// Creates the chosen report font or default Consolas/Courier New at the current window DPI.
HFONT CreateReportFont(HWND window, const LOGFONTW* saved, UINT savedDpi) {
    LOGFONTW font = LOGFONTW{};
    if (saved && saved->lfFaceName[0]) {
        font = *saved;
        font.lfHeight = MulDiv(font.lfHeight, WindowDpi(window), savedDpi ? savedDpi : 96);
        font.lfWidth = MulDiv(font.lfWidth, WindowDpi(window), savedDpi ? savedDpi : 96);
    } else {
        font.lfHeight = -MulDiv(9, WindowDpi(window), 72);
        font.lfCharSet = DEFAULT_CHARSET;
        font.lfPitchAndFamily = FIXED_PITCH | FF_MODERN;
        bool consolas = IsFontAvailable(L"Consolas");
        lstrcpyW(font.lfFaceName, consolas ? L"Consolas" : L"Courier New");
    }
    BYTE quality = saved ? saved->lfQuality : 0;
    font.lfQuality = quality == 5 || quality == ANTIALIASED_QUALITY || quality == NONANTIALIASED_QUALITY
        ? quality
        : DefaultReportFontQuality();
    return CreateFontIndirectW(&font);
}

/// Loads the small or large application icon at the native system icon dimensions.
HICON LoadApplicationIcon(bool small) {
    int width = GetSystemMetrics(small ? SM_CXSMICON : SM_CXICON);
    int height = GetSystemMetrics(small ? SM_CYSMICON : SM_CYICON);
    return static_cast<HICON>(LoadImageW(GetModuleHandleW(nullptr),
        MAKEINTRESOURCEW(IDI_MEDIAINFO), IMAGE_ICON, width, height, LR_SHARED));
}

/// Converts dialog units using the supplied font metrics rather than fixed pixel assumptions.
SIZE DialogUnits(HFONT font, int x, int y) {
    HDC dc = GetDC(nullptr);
    SIZE extent = SIZE{};
    TEXTMETRICW metrics = TEXTMETRICW{};
    if (!dc) {
        return SIZE{ x, y };
    }
    HGDIOBJ old = SelectObject(dc, font);
    GetTextExtentPoint32W(dc, L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", 52, &extent);
    GetTextMetricsW(dc, &metrics);
    SelectObject(dc, old);
    ReleaseDC(nullptr, dc);
    int baseX = (extent.cx / 26 + 1) / 2;
    return SIZE{ MulDiv(x, baseX, 4), MulDiv(y, metrics.tmHeight, 8) };
}

/// Expands a native button only as needed for its current localized text and native padding.
SIZE PreferredButtonSize(HWND button, const SIZE& minimum) {
    SIZE size = SIZE{};
    if (!SendMessageW(button, buttonGetIdealSize, 0, reinterpret_cast<LPARAM>(&size))) {
        wchar_t* text = CopyControlText(button);
        HDC dc = GetDC(button);
        if (text && dc) {
            HFONT font = reinterpret_cast<HFONT>(SendMessageW(button, WM_GETFONT, 0, 0));
            HGDIOBJ previous = font ? SelectObject(dc, font) : nullptr;
            RECT bounds = RECT{};
            DrawTextW(dc, text, -1, &bounds, DT_CALCRECT | DT_SINGLELINE);
            SIZE padding = DialogUnits(font, 12, 0);
            size.cx = bounds.right + padding.cx + 2 * GetSystemMetrics(SM_CXEDGE);
            size.cy = bounds.bottom + 2 * GetSystemMetrics(SM_CYEDGE);
            if (previous) {
                SelectObject(dc, previous);
            }
        }
        if (dc) {
            ReleaseDC(button, dc);
        }
        if (text) {
            HeapFree(GetProcessHeap(), 0, text);
        }
    }
    if (size.cx < minimum.cx) {
        size.cx = minimum.cx;
    }
    if (size.cy < minimum.cy) {
        size.cy = minimum.cy;
    }
    return size;
}

/// Maps a control window rectangle into the requested parent coordinate system.
RECT ControlRect(HWND window, HWND parent) {
    RECT rectangle = RECT{};
    GetWindowRect(window, &rectangle);
    MapWindowPoints(HWND_DESKTOP, parent, reinterpret_cast<POINT*>(&rectangle), 2);
    return rectangle;
}

/// Positions and sizes a control without activation, retaining a positive client size.
void PlaceControl(HWND window, int x, int y, int width, int height) {
    SetWindowPos(window, nullptr, x, y, width > 0 ? width : 1, height > 0 ? height : 1,
        SWP_NOZORDER | SWP_NOACTIVATE);
}

/// Reads text metrics with the font currently assigned to a native control.
bool ReadControlMetrics(HWND control, TEXTMETRICW* metrics) {
    HDC dc = GetDC(control);
    if (!dc) {
        return false;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(control, WM_GETFONT, 0, 0));
    HGDIOBJ old = font ? SelectObject(dc, font) : nullptr;
    bool success = GetTextMetricsW(dc, metrics) != FALSE;
    if (old) {
        SelectObject(dc, old);
    }
    ReleaseDC(control, dc);
    return success;
}

/// Calculates the rendered text baseline from the native control content rectangle and current font.
LONG ControlTextBaseline(HWND control) {
    RECT rectangle = RECT{};
    GetClientRect(control, &rectangle);
    POINT origin = POINT{};
    ClientToScreen(control, &origin);
    TEXTMETRICW metrics = TEXTMETRICW{};
    ReadControlMetrics(control, &metrics);
    wchar_t name[32];
    GetClassNameW(control, name, 32);
    LONG textTop = 0;
    if (!lstrcmpiW(name, L"EDIT")) {
        SendMessageW(control, EM_GETRECT, 0, reinterpret_cast<LPARAM>(&rectangle));
        textTop = rectangle.top;
    } else if (!lstrcmpiW(name, L"COMBOBOX")) {
        if (ComboBoxTextRect(control, &rectangle)) {
            textTop = rectangle.top + (rectangle.bottom - rectangle.top - metrics.tmHeight) / 2;
        }
    } else if (!lstrcmpiW(name, L"BUTTON")) {
        wchar_t systemPath[MAX_PATH];
        UINT length = GetSystemDirectoryW(systemPath, MAX_PATH);
        HMODULE themeModule = nullptr;
        if (length && length + ARRAYSIZE(themeLibrarySuffix) < MAX_PATH) {
            lstrcatW(systemPath, themeLibrarySuffix);
            themeModule = LoadLibraryW(systemPath);
        }
        GetWindowThemeFunction getTheme = themeModule
            ? reinterpret_cast<GetWindowThemeFunction>(GetProcAddress(themeModule, "GetWindowTheme"))
            : nullptr;
        ThemeContentFunction getContent = themeModule
            ? reinterpret_cast<ThemeContentFunction>(GetProcAddress(themeModule,
                "GetThemeBackgroundContentRect"))
            : nullptr;
        ThemePartSizeFunction getPartSize = themeModule
            ? reinterpret_cast<ThemePartSizeFunction>(GetProcAddress(themeModule, "GetThemePartSize"))
            : nullptr;
        HANDLE theme = getTheme ? getTheme(control) : nullptr;
        LONG textHeight = metrics.tmHeight;
        LONG type = GetWindowLongW(control, GWL_STYLE) & BS_TYPEMASK;
        if (!theme) {
            rectangle.bottom -= GetSystemMetrics(SM_CYBORDER);
        } else if ((type == BS_PUSHBUTTON || type == BS_DEFPUSHBUTTON) && getContent) {
            RECT content = RECT{};
            if (SUCCEEDED(getContent(theme, nullptr, 1, 1, &rectangle, &content))) {
                rectangle = content;
            }
        } else if ((type == BS_CHECKBOX || type == BS_AUTOCHECKBOX) && getPartSize) {
            SIZE glyph = SIZE{};
            if (SUCCEEDED(getPartSize(theme, nullptr, 3, 1, nullptr, 1, &glyph)) && glyph.cy > textHeight) {
                textHeight = glyph.cy;
            }
        }
        textTop = rectangle.top + (rectangle.bottom - rectangle.top - textHeight) / 2;
        if (themeModule) {
            FreeLibrary(themeModule);
        }
    } else if (!lstrcmpiW(name, L"STATIC") && GetWindowLongW(control, GWL_STYLE) & SS_CENTERIMAGE) {
        textTop = (rectangle.bottom - rectangle.top - metrics.tmHeight) / 2;
    }
    return origin.y + textTop + metrics.tmAscent;
}

/// Moves one control so its rendered text baseline matches another control.
void AlignControlBaseline(HWND control, HWND reference) {
    LONG distance = ControlTextBaseline(reference) - ControlTextBaseline(control);
    if (distance) {
        RECT bounds = ControlRect(control, GetParent(control));
        SetWindowPos(control, nullptr, bounds.left, bounds.top + distance, 0, 0,
            SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOCOPYBITS);
    }
}

/// Adapts only Preferences edit height and left text margin using current font, theme and native borders.
void UpdateEditMetrics(HWND edit) {
    RECT bounds = RECT{};
    POINT client = POINT{};
    if (!GetWindowRect(edit, &bounds) || !ClientToScreen(edit, &client)) {
        return;
    }
    TEXTMETRICW metrics = TEXTMETRICW{};
    if (!ReadControlMetrics(edit, &metrics)) {
        return;
    }
    LONG contentLeft = GetSystemMetrics(SM_CXEDGE) + GetSystemMetrics(SM_CXBORDER);
    LONG contentTop = GetSystemMetrics(SM_CYEDGE) + GetSystemMetrics(SM_CYBORDER);
    LONG contentBottom = contentTop;
    wchar_t systemPath[MAX_PATH];
    HMODULE module = nullptr;
    UINT length = GetSystemDirectoryW(systemPath, MAX_PATH);
    if (length && length + lstrlenW(themeLibrarySuffix) < MAX_PATH) {
        lstrcatW(systemPath, themeLibrarySuffix);
        module = LoadLibraryW(systemPath);
    }
    GetWindowThemeFunction getTheme = module
        ? reinterpret_cast<GetWindowThemeFunction>(GetProcAddress(module, "GetWindowTheme"))
        : nullptr;
    OpenThemeFunction openTheme = module
        ? reinterpret_cast<OpenThemeFunction>(GetProcAddress(module, "OpenThemeData"))
        : nullptr;
    CloseThemeFunction closeTheme = module
        ? reinterpret_cast<CloseThemeFunction>(GetProcAddress(module, "CloseThemeData"))
        : nullptr;
    ThemeContentFunction getContent = module
        ? reinterpret_cast<ThemeContentFunction>(GetProcAddress(module, "GetThemeBackgroundContentRect"))
        : nullptr;
    if (getTheme && getTheme(edit) && openTheme && closeTheme && getContent) {
        HANDLE theme = openTheme(nullptr, L"Combobox");
        if (theme) {
            RECT frame = RECT{ 0, 0, bounds.right - bounds.left, bounds.bottom - bounds.top };
            RECT content = RECT{};
            if (SUCCEEDED(getContent(theme, nullptr, 5, 1, &frame, &content))) {
                contentLeft = content.left;
                contentTop = content.top;
                contentBottom = frame.bottom - content.bottom;
            }
            closeTheme(theme);
        }
    }
    if (module) {
        FreeLibrary(module);
    }
    LONG borderWidth = client.x - bounds.left;
    LONG leftMargin = contentLeft > borderWidth ? contentLeft - borderWidth : 0;
    DWORD margins = static_cast<DWORD>(SendMessageW(edit, EM_GETMARGINS, 0, 0));
    if (LOWORD(margins) != leftMargin) {
        SendMessageW(edit, EM_SETMARGINS, EC_LEFTMARGIN, MAKELPARAM(leftMargin, 0));
    }
    LONG height = metrics.tmHeight + contentTop + contentBottom + 2 * GetSystemMetrics(SM_CYBORDER);
    if (height != bounds.bottom - bounds.top) {
        SetWindowPos(edit, nullptr, 0, 0, bounds.right - bounds.left, height,
            SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    }
}

/// Copies control text into a null-terminated process-heap buffer owned by the caller.
wchar_t* CopyControlText(HWND control) {
    int length = GetWindowTextLengthW(control);
    wchar_t* text = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0, (static_cast<SIZE_T>(length) + 1)
        * sizeof(wchar_t)));
    if (text) {
        GetWindowTextW(control, text, length + 1);
    }
    return text;
}

/// Identifies native Unicode whitespace while keeping explicit line breaks available to the wrapper.
static bool IsWrappingSpace(wchar_t character) {
    WORD type = 0;
    return GetStringTypeW(CT_CTYPE1, &character, 1, &type) && type & C1_SPACE;
}

/// Measures typographic line spacing and actual glyph bounds for descriptive text.
static UiTextLine GetUiTextLine(HDC dc, const wchar_t* text, const TEXTMETRICW& metrics) {
    UiTextLine line = UiTextLine{ metrics.tmAscent, metrics.tmDescent, metrics.tmExternalLeading };
    UINT size = GetOutlineTextMetricsW(dc, 0, nullptr);
    if (!size) {
        return line;
    }
    OUTLINETEXTMETRICW* outline = static_cast<OUTLINETEXTMETRICW*>(HeapAlloc(GetProcessHeap(), 0, size));
    if (!outline) {
        return line;
    }
    if (!GetOutlineTextMetricsW(dc, size, outline)) {
        HeapFree(GetProcessHeap(), 0, outline);
        return line;
    }
    UiTextLine uiTextL = UiTextLine{
        outline->otmAscent,
        outline->otmDescent < 0 ? -outline->otmDescent : outline->otmDescent,
        static_cast<LONG>(outline->otmLineGap)
    };
    HeapFree(GetProcessHeap(), 0, outline);
    MAT2 transform = MAT2{
        FIXED{ 0, 1 },
        FIXED{ 0, 0 },
        FIXED{ 0, 0 },
        FIXED{ 0, 1 }
    };
    for (const wchar_t* character = text; *character; ++character) {
        if (IsWrappingSpace(*character)) {
            continue;
        }
        GLYPHMETRICS glyph = GLYPHMETRICS{};
        if (GetGlyphOutlineW(dc, *character, GGO_METRICS, &glyph, 0, nullptr, &transform) != GDI_ERROR) {
            if (glyph.gmptGlyphOrigin.y > uiTextL.ascent) {
                uiTextL.ascent = glyph.gmptGlyphOrigin.y;
            }
            LONG descent = static_cast<LONG>(glyph.gmBlackBoxY) - glyph.gmptGlyphOrigin.y;
            if (descent > uiTextL.descent) {
                uiTextL.descent = descent;
            }
        }
    }
    if (uiTextL.ascent + uiTextL.descent + uiTextL.gap < metrics.tmHeight + metrics.tmExternalLeading) {
        line = uiTextL;
    }
    return line;
}

/// Draws or measures descriptive text with whole-word wrapping and typographic line spacing.
int DrawWordWrappedText(HDC dc, const wchar_t* text, const RECT& bounds, UINT flags) {
    TEXTMETRICW metrics = TEXTMETRICW{};
    if (!GetTextMetricsW(dc, &metrics)) {
        return 0;
    }
    int length = lstrlenW(text);
    wchar_t* line = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0,
        (static_cast<SIZE_T>(length) + 1) * sizeof(wchar_t)));
    if (!line) {
        return 0;
    }
    UiTextLine layout = GetUiTextLine(dc, text, metrics);
    int lineHeight = layout.ascent + layout.descent + layout.gap;
    if (lineHeight < 1) {
        lineHeight = 1;
    }
    bool measure = (flags & DT_CALCRECT) != 0;
    int saved = SaveDC(dc);
    if (!measure) {
        IntersectClipRect(dc, bounds.left, bounds.top, bounds.right, bounds.bottom);
    }
    int maximumWidth = bounds.right - bounds.left;
    int y = bounds.top;
    int position = 0;
    int lineLength = 0;
    while (position < length && (measure || y < bounds.bottom)) {
        if (text[position] == L'\r' || text[position] == L'\n') {
            if (!measure && lineLength) {
                RECT lineRect = RECT{
                    bounds.left,
                    y + layout.ascent - metrics.tmAscent,
                    bounds.right,
                    y + layout.ascent + metrics.tmDescent
                };
                DrawTextW(dc, line, lineLength, &lineRect, DT_LEFT | DT_TOP | DT_SINGLELINE | DT_NOPREFIX);
            }
            lineLength = 0;
            wchar_t newline = text[position++];
            if (position < length && newline == L'\r' && text[position] == L'\n') {
                ++position;
            }
            y += lineHeight;
            continue;
        }
        while (position < length
            && IsWrappingSpace(text[position])
            && text[position] != L'\r'
            && text[position] != L'\n') {
            ++position;
        }
        int wordStart = position;
        while (position < length && !IsWrappingSpace(text[position])) {
            ++position;
        }
        int wordLength = position - wordStart;
        if (!wordLength) {
            continue;
        }
        int candidateLength = lineLength;
        if (candidateLength) {
            line[candidateLength++] = L' ';
        }
        CopyMemory(line + candidateLength, text + wordStart, wordLength * sizeof(wchar_t));
        candidateLength += wordLength;
        SIZE extent = SIZE{};
        GetTextExtentPoint32W(dc, line, candidateLength, &extent);
        if (lineLength && extent.cx > maximumWidth) {
            if (!measure) {
                RECT lineRect = RECT{
                    bounds.left,
                    y + layout.ascent - metrics.tmAscent,
                    bounds.right,
                    y + layout.ascent + metrics.tmDescent
                };
                DrawTextW(dc, line, lineLength, &lineRect, DT_LEFT | DT_TOP | DT_SINGLELINE | DT_NOPREFIX);
            }
            y += lineHeight;
            CopyMemory(line, text + wordStart, wordLength * sizeof(wchar_t));
            lineLength = wordLength;
        } else {
            lineLength = candidateLength;
        }
    }
    if (lineLength && (measure || y < bounds.bottom)) {
        if (!measure) {
            RECT lineRect = RECT{
                bounds.left,
                y + layout.ascent - metrics.tmAscent,
                bounds.right,
                y + layout.ascent + metrics.tmDescent
            };
            DrawTextW(dc, line, lineLength, &lineRect, DT_LEFT | DT_TOP | DT_SINGLELINE | DT_NOPREFIX);
        }
        y += lineHeight;
    }
    RestoreDC(dc, saved);
    HeapFree(GetProcessHeap(), 0, line);
    return y - bounds.top;
}

/// Measures a wrapped label with the same font, word boundaries and line spacing used by its painter.
int WrappedLabelHeight(HWND control, int width) {
    HDC dc = GetDC(control);
    if (!dc) {
        return 0;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(control, WM_GETFONT, 0, 0));
    HGDIOBJ old = font ? SelectObject(dc, font) : nullptr;
    wchar_t* text = CopyControlText(control);
    RECT bounds = RECT{ 0, 0, width, 0 };
    int height = text ? DrawWordWrappedText(dc, text, bounds, DT_CALCRECT) : 0;
    if (text) {
        HeapFree(GetProcessHeap(), 0, text);
    }
    if (old) {
        SelectObject(dc, old);
    }
    ReleaseDC(control, dc);
    return height;
}

/// Paints a whole-word-wrapped dialog label in its current font over the native dialog background.
INT_PTR DrawWrappedTextItem(const DRAWITEMSTRUCT* item) {
    int saved = SaveDC(item->hDC);
    FillRect(item->hDC, &item->rcItem, GetSysColorBrush(COLOR_BTNFACE));
    SetBkMode(item->hDC, TRANSPARENT);
    SetTextColor(item->hDC, GetSysColor(IsWindowEnabled(item->hwndItem) ? COLOR_WINDOWTEXT : COLOR_GRAYTEXT));
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(item->hwndItem, WM_GETFONT, 0, 0));
    if (font) {
        SelectObject(item->hDC, font);
    }
    wchar_t* text = CopyControlText(item->hwndItem);
    if (text) {
        DrawWordWrappedText(item->hDC, text, item->rcItem, 0);
        HeapFree(GetProcessHeap(), 0, text);
    }
    RestoreDC(item->hDC, saved);
    return TRUE;
}

/// Shortens text in the middle without splitting surrogate pairs, optionally retaining a complete file
/// extension.
void FormatMiddleCaption(const wchar_t* name, UINT limit, bool keepExtension, wchar_t* caption,
    DWORD capacity) {
    if (!capacity) {
        return;
    }
    UINT length = static_cast<UINT>(lstrlenW(name));
    if (length <= limit) {
        lstrcpynW(caption, name, capacity);
        return;
    }
    const wchar_t* extension = name + length;
    if (keepExtension) {
        for (const wchar_t* cursor = name + 1; cursor < name + length; ++cursor) {
            if (*cursor == L'.') {
                extension = cursor;
            }
        }
    }
    UINT suffix = static_cast<UINT>(name + length - extension);
    UINT stem = static_cast<UINT>(extension - name);
    UINT kept = limit > suffix + 3 ? limit - suffix - 1 : 2;
    if (kept >= stem) {
        lstrcpynW(caption, name, capacity);
        return;
    }
    UINT left = (kept + 1) / 2;
    UINT right = kept / 2;
    if (left && name[left - 1] >= 0xD800 && name[left - 1] <= 0xDBFF) {
        if (left == 1) {
            ++left;
        } else {
            --left;
        }
    }
    if (extension[-static_cast<int>(right)] >= 0xDC00 && extension[-static_cast<int>(right)] <= 0xDFFF) {
        if (right == 1) {
            ++right;
        } else {
            --right;
        }
    }
    DWORD used = 0;
    for (UINT index = 0; index < left && used + 1 < capacity; ++index) {
        caption[used++] = name[index];
    }
    if (used + 1 < capacity) {
        caption[used++] = L'\u2026';
    }
    for (const wchar_t* cursor = extension - right; *cursor && used + 1 < capacity; ++cursor) {
        caption[used++] = *cursor;
    }
    if (used && caption[used - 1] >= 0xD800 && caption[used - 1] <= 0xDBFF) {
        --used;
    }
    caption[used] = 0;
}

/// Shortens a long filename in the middle while retaining its beginning, stem ending and complete extension.
void FormatFileNameCaption(const wchar_t* path, UINT limit, wchar_t* caption, DWORD capacity) {
    if (!capacity) {
        return;
    }
    const wchar_t* name = path;
    for (const wchar_t* cursor = path; *cursor; ++cursor) {
        if (*cursor == L'\\' || *cursor == L'/') {
            name = cursor + 1;
        }
    }
    FormatMiddleCaption(name, limit, true, caption, capacity);
}

/// Identifies either supported Windows path separator.
static bool IsPathSeparator(wchar_t value) {
    return value == L'\\' || value == L'/';
}

/// Retains the complete drive root or UNC server and share when collapsing ancestor directories.
static UINT PathRootLength(const wchar_t* path) {
    if (path[0] && path[1] == L':' && IsPathSeparator(path[2])) {
        return 3;
    }
    if (IsPathSeparator(path[0]) && IsPathSeparator(path[1])) {
        const wchar_t* cursor = path + 2;
        for (int component = 0; component < 2; ++component) {
            while (*cursor && !IsPathSeparator(*cursor)) {
                ++cursor;
            }
            if (*cursor) {
                ++cursor;
            }
        }
        return static_cast<UINT>(cursor - path);
    }
    return 0;
}

/// Measures the complete candidate in the exact font already selected for the status pane.
static bool PathCaptionFits(HDC dc, const wchar_t* text, int width) {
    SIZE extent = SIZE{};
    return GetTextExtentPoint32W(dc, text, lstrlenW(text), &extent) && extent.cx <= width;
}

/// Combines a retained path prefix, omitted ancestors, parent name and filename using bounded native copies.
static void BuildPathCaption(const wchar_t* path, UINT prefix, bool omitted, const wchar_t* parent,
    const wchar_t* name, wchar_t* caption, DWORD capacity) {
    lstrcpynW(caption, path, prefix + 1 < capacity ? prefix + 1 : capacity);
    DWORD used = static_cast<DWORD>(lstrlenW(caption));
    const wchar_t* parts[] = { omitted ? L"\u2026\\" : L"", parent, parent[0] ? L"\\" : L"", name };
    for (UINT index = 0; index < ARRAYSIZE(parts); ++index) {
        lstrcpynW(caption + used, parts[index], capacity - used);
        used += static_cast<DWORD>(lstrlenW(caption + used));
    }
    if (used && caption[used - 1] >= 0xD800 && caption[used - 1] <= 0xDBFF) {
        caption[--used] = 0;
    }
}

/// Fits an absolute path to its current font and width, retaining the root, parent directory and both
/// filename ends.
void FormatPathCaption(HDC dc, const wchar_t* path, int width, wchar_t* caption, DWORD capacity) {
    if (!capacity) {
        return;
    }
    caption[0] = 0;
    if (width <= 0) {
        return;
    }
    if (PathCaptionFits(dc, path, width)) {
        lstrcpynW(caption, path, capacity);
        return;
    }
    const wchar_t* name = path;
    for (const wchar_t* cursor = path; *cursor; ++cursor) {
        if (IsPathSeparator(*cursor)) {
            name = cursor + 1;
        }
    }
    UINT root = PathRootLength(path);
    const wchar_t* parent = name;
    if (name > path + root) {
        parent = name - 1;
        while (parent > path + root && !IsPathSeparator(parent[-1])) {
            --parent;
        }
    }
    UINT parentLength = name > parent ? static_cast<UINT>(name - parent - 1) : 0;
    UINT nameLength = static_cast<UINT>(lstrlenW(name));
    wchar_t parentCaption[MAX_PATH];
    wchar_t nameCaption[MAX_PATH];
    wchar_t candidate[MAX_PATH + 4];
    lstrcpynW(parentCaption, parent, parentLength + 1);
    lstrcpynW(nameCaption, name, ARRAYSIZE(nameCaption));
    bool omitted = parent > path + root;
    BuildPathCaption(path, root, omitted, parentCaption, nameCaption, candidate, ARRAYSIZE(candidate));
    for (UINT limit = nameLength; !PathCaptionFits(dc, candidate, width) && limit > 3;) {
        FormatMiddleCaption(name, --limit, true, nameCaption, ARRAYSIZE(nameCaption));
        BuildPathCaption(path, root, omitted, parentCaption, nameCaption, candidate, ARRAYSIZE(candidate));
    }
    for (UINT limit = parentLength; !PathCaptionFits(dc, candidate, width) && limit > 3;) {
        lstrcpynW(parentCaption, parent, parentLength + 1);
        FormatMiddleCaption(parentCaption, --limit, false, caption, capacity);
        lstrcpynW(parentCaption, caption, ARRAYSIZE(parentCaption));
        BuildPathCaption(path, root, omitted, parentCaption, nameCaption, candidate, ARRAYSIZE(candidate));
    }
    lstrcpynW(caption, candidate, capacity);
    for (const wchar_t* cursor = path + root; cursor < parent; ++cursor) {
        if (IsPathSeparator(*cursor) && cursor + 1 < parent) {
            UINT prefix = static_cast<UINT>(cursor + 1 - path);
            BuildPathCaption(path, prefix, true, parentCaption, nameCaption, candidate, ARRAYSIZE(candidate));
            if (!PathCaptionFits(dc, candidate, width)) {
                break;
            }
            lstrcpynW(caption, candidate, capacity);
        }
    }
}

/// Writes the complete image-output buffer, handling partial writes and propagating file errors.
static bool WriteBytes(HANDLE file, const void* data, DWORD bytes) {
    const BYTE* cursor = static_cast<const BYTE*>(data);
    while (bytes) {
        DWORD written = 0;
        if (!WriteFile(file, cursor, bytes, &written, nullptr) || !written) {
            return false;
        }
        cursor += written;
        bytes -= written;
    }
    return true;
}

/// Stores a 16-bit value in little-endian byte order.
static void LittleEndian16(BYTE* output, WORD value) {
    output[0] = static_cast<BYTE>(value);
    output[1] = static_cast<BYTE>(value >> 8);
}

/// Stores a 32-bit value in little-endian byte order.
static void LittleEndian32(BYTE* output, DWORD value) {
    LittleEndian16(output, static_cast<WORD>(value));
    LittleEndian16(output + 2, static_cast<WORD>(value >> 16));
}

/// Writes the rendered report as an uncompressed 24-bit Windows bitmap.
static bool WriteBmp(HANDLE file, const BYTE* pixels, int width, int height, int dpiX, int dpiY) {
    DWORD stride = width * 3 + 3 & ~3UL;
    BITMAPFILEHEADER header = BITMAPFILEHEADER{};
    BITMAPINFOHEADER info = BITMAPINFOHEADER{};
    header.bfType = 0x4D42;
    header.bfOffBits = sizeof(header) + sizeof(info);
    header.bfSize = header.bfOffBits + stride * height;
    info.biSize = sizeof(info);
    info.biWidth = width;
    info.biHeight = height;
    info.biPlanes = 1;
    info.biBitCount = 24;
    info.biCompression = BI_RGB;
    info.biSizeImage = stride * height;
    info.biXPelsPerMeter = MulDiv(dpiX, 10000, 254);
    info.biYPelsPerMeter = MulDiv(dpiY, 10000, 254);
    BYTE* row = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, stride));
    if (!row) {
        return false;
    }
    bool success = WriteBytes(file, &header, sizeof(header)) && WriteBytes(file, &info, sizeof(info));
    for (int y = height - 1; y >= 0 && success; --y) {
        const BYTE* source = pixels + static_cast<SIZE_T>(y) * width * 4;
        for (int x = 0; x < width; ++x) {
            row[x * 3] = source[x * 4];
            row[x * 3 + 1] = source[x * 4 + 1];
            row[x * 3 + 2] = source[x * 4 + 2];
        }
        success = WriteBytes(file, row, stride);
    }
    HeapFree(GetProcessHeap(), 0, row);
    return success;
}

/// Appends one little-endian TIFF directory entry and advances the output pointer.
static void TiffEntry(BYTE*& entry, WORD tag, WORD type, DWORD count, DWORD value) {
    LittleEndian16(entry, tag);
    LittleEndian16(entry + 2, type);
    LittleEndian32(entry + 4, count);
    LittleEndian32(entry + 8, value);
    entry += 12;
}

/// Writes the rendered report as an uncompressed RGB TIFF with its physical resolution.
static bool WriteTiff(HANDLE file, const BYTE* pixels, int width, int height, int dpiX, int dpiY) {
    DWORD rowSize = width * 3;
    DWORD rowsPerStrip = 8192 / rowSize;
    if (!rowsPerStrip) {
        rowsPerStrip = 1;
    }
    DWORD stripCount = (height + rowsPerStrip - 1) / rowsPerStrip;
    DWORD tablesSize = stripCount > 1 ? stripCount * 8 : 0;
    DWORD dataOffset = tiffValuesOffset + 22 + tablesSize;
    BYTE* header = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dataOffset));
    BYTE* row = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), 0, rowSize));
    if (!header || !row) {
        if (header) {
            HeapFree(GetProcessHeap(), 0, header);
        }
        if (row) {
            HeapFree(GetProcessHeap(), 0, row);
        }
        return false;
    }
    header[0] = 'I';
    header[1] = 'I';
    LittleEndian16(header + 2, 42);
    LittleEndian32(header + 4, 8);
    LittleEndian16(header + 8, tiffTagCount);
    BYTE* entry = header + 10;
    TiffEntry(entry, 256, 4, 1, width);
    TiffEntry(entry, 257, 4, 1, height);
    TiffEntry(entry, 258, 3, 3, tiffValuesOffset);
    TiffEntry(entry, 259, 3, 1, 1);
    TiffEntry(entry, 262, 3, 1, 2);
    TiffEntry(entry, 273, 4, stripCount, stripCount == 1
        ? dataOffset
        : tiffValuesOffset + 22);
    TiffEntry(entry, 274, 3, 1, 1);
    TiffEntry(entry, 277, 3, 1, 3);
    TiffEntry(entry, 278, 4, 1, rowsPerStrip);
    TiffEntry(entry, 279, 4, stripCount, stripCount == 1
        ? rowSize * height
        : tiffValuesOffset + 22 + stripCount * 4);
    TiffEntry(entry, 282, 5, 1, tiffValuesOffset + 6);
    TiffEntry(entry, 283, 5, 1, tiffValuesOffset + 14);
    TiffEntry(entry, 284, 3, 1, 1);
    TiffEntry(entry, 296, 3, 1, 2);
    for (int component = 0; component < 3; ++component) {
        LittleEndian16(header + tiffValuesOffset + component * 2, 8);
    }
    LittleEndian32(header + tiffValuesOffset + 6, dpiX);
    LittleEndian32(header + tiffValuesOffset + 10, 1);
    LittleEndian32(header + tiffValuesOffset + 14, dpiY);
    LittleEndian32(header + tiffValuesOffset + 18, 1);
    if (stripCount > 1) {
        for (DWORD index = 0; index < stripCount; ++index) {
            DWORD firstRow = index * rowsPerStrip;
            DWORD rows = height - firstRow;
            if (rows > rowsPerStrip) {
                rows = rowsPerStrip;
            }
            LittleEndian32(header + tiffValuesOffset + 22 + index * 4, dataOffset + firstRow * rowSize);
            LittleEndian32(header + tiffValuesOffset + 22 + stripCount * 4 + index * 4, rows * rowSize);
        }
    }
    bool success = WriteBytes(file, header, dataOffset);
    for (int y = 0; y < height && success; ++y) {
        const BYTE* source = pixels + static_cast<SIZE_T>(y) * width * 4;
        for (int x = 0; x < width; ++x) {
            row[x * 3] = source[x * 4 + 2];
            row[x * 3 + 1] = source[x * 4 + 1];
            row[x * 3 + 2] = source[x * 4];
        }
        success = WriteBytes(file, row, rowSize);
    }
    HeapFree(GetProcessHeap(), 0, row);
    HeapFree(GetProcessHeap(), 0, header);
    return success;
}

/// Stores a 32-bit value in big-endian byte order.
static void BigEndian(BYTE* output, DWORD value) {
    output[0] = static_cast<BYTE>(value >> 24);
    output[1] = static_cast<BYTE>(value >> 16);
    output[2] = static_cast<BYTE>(value >> 8);
    output[3] = static_cast<BYTE>(value);
}

/// Updates a PNG CRC32 accumulator with a sequence of bytes.
static DWORD CrcBytes(DWORD crc, const BYTE* bytes, DWORD length) {
    for (DWORD index = 0; index < length; ++index) {
        crc ^= bytes[index];
        for (int bit = 0; bit < 8; ++bit) {
            crc = crc >> 1 ^ (crc & 1 ? 0xEDB88320 : 0);
        }
    }
    return crc;
}

/// Writes a PNG chunk with its length, type, payload and CRC32.
static bool PngChunk(HANDLE file, const char* type, const BYTE* data, DWORD length) {
    BYTE header[8];
    BigEndian(header, length);
    CopyMemory(header + 4, type, 4);
    DWORD crc = CrcBytes(0xFFFFFFFF, header + 4, 4);
    crc = CrcBytes(crc, data, length) ^ 0xFFFFFFFF;
    BYTE checksum[4];
    BigEndian(checksum, crc);
    return WriteBytes(file, header, 8) && WriteBytes(file, data, length) && WriteBytes(file, checksum, 4);
}

/// Writes the rendered report as a lossless PNG using stored DEFLATE blocks.
static bool WritePng(HANDLE file, const BYTE* pixels, int width, int height) {
    const BYTE signature[] = { 137, 80, 78, 71, 13, 10, 26, 10 };
    BYTE info[13] = {};
    BigEndian(info, width);
    BigEndian(info + 4, height);
    info[8] = 8;
    info[9] = 2;
    const BYTE zlib[] = { 0x78, 0x01 };
    if (!WriteBytes(file, signature, 8)
            || !PngChunk(file, "IHDR", info, 13)
            || !PngChunk(file, "IDAT", zlib, 2)) {
        return false;
    }
    DWORD rowLength = 1 + width * 3;
    BYTE* row = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), 0, rowLength + 5));
    if (!row) {
        return false;
    }
    DWORD a = 1;
    DWORD b = 0;
    bool success = true;
    for (int y = 0; y < height && success; ++y) {
        row[0] = y == height - 1 ? 1 : 0;
        row[1] = static_cast<BYTE>(rowLength);
        row[2] = static_cast<BYTE>(rowLength >> 8);
        row[3] = static_cast<BYTE>(~rowLength);
        row[4] = static_cast<BYTE>(~rowLength >> 8);
        row[5] = 0;
        const BYTE* source = pixels + static_cast<SIZE_T>(y) * width * 4;
        for (int x = 0; x < width; ++x) {
            row[6 + x * 3] = source[x * 4 + 2];
            row[7 + x * 3] = source[x * 4 + 1];
            row[8 + x * 3] = source[x * 4];
        }
        for (DWORD index = 5; index < rowLength + 5; ++index) {
            a += row[index];
            if (a >= 65521) {
                a -= 65521;
            }
            b += a;
            if (b >= 65521) {
                b -= 65521;
            }
        }
        success = PngChunk(file, "IDAT", row, rowLength + 5);
    }
    HeapFree(GetProcessHeap(), 0, row);
    BYTE adler[4];
    BigEndian(adler, b << 16 | a);
    return success && PngChunk(file, "IDAT", adler, 4) && PngChunk(file, "IEND", nullptr, 0);
}

/// Buffers one GIF data byte and flushes complete sub-blocks to the output file.
static void GifByte(GifWriter& writer, BYTE value) {
    writer.block[writer.count++] = value;
    if (writer.count == 255) {
        BYTE count = 255;
        writer.success = writer.success
            && WriteBytes(writer.file, &count, 1)
            && WriteBytes(writer.file, writer.block, 255);
        writer.count = 0;
    }
}

/// Packs one GIF LZW code into the buffered image-data stream.
static void GifCode(GifWriter& writer, DWORD code) {
    writer.packed |= code << writer.bits;
    writer.bits += 9;
    while (writer.bits >= 8) {
        GifByte(writer, static_cast<BYTE>(writer.packed));
        writer.packed >>= 8;
        writer.bits -= 8;
    }
}

/// Writes an exact GIF palette image, rejecting reports that require more than 256 colors.
static bool WriteGif(HANDLE file, const BYTE* pixels, int width, int height) {
    GifColor* colors =
        static_cast<GifColor*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 4096 * sizeof(GifColor)));
    if (!colors) {
        return false;
    }
    BYTE palette[768] = {};
    int colorCount = 0;
    SIZE_T count = static_cast<SIZE_T>(width) * height;
    bool success = true;
    for (SIZE_T index = 0; index < count; ++index) {
        DWORD color = pixels[index * 4] | pixels[index * 4 + 1] << 8 | pixels[index * 4 + 2] << 16;
        DWORD slot = color * 2654435761U >> 20;
        while (colors[slot].color && colors[slot].color != color + 1) {
            slot = slot + 1 & 4095;
        }
        if (!colors[slot].color) {
            if (colorCount == 256) {
                success = false;
                break;
            }
            colors[slot].color = color + 1;
            colors[slot].index = static_cast<BYTE>(colorCount);
            palette[colorCount * 3] = static_cast<BYTE>(color >> 16);
            palette[colorCount * 3 + 1] = static_cast<BYTE>(color >> 8);
            palette[colorCount * 3 + 2] = static_cast<BYTE>(color);
            ++colorCount;
        }
    }
    BYTE header[] = { 'G', 'I', 'F', '8', '9', 'a', 0, 0, 0, 0, 0xF7, 0, 0 };
    header[6] = static_cast<BYTE>(width);
    header[7] = static_cast<BYTE>(width >> 8);
    header[8] = static_cast<BYTE>(height);
    header[9] = static_cast<BYTE>(height >> 8);
    BYTE descriptor[] = { 0x2C, 0, 0, 0, 0, header[6], header[7], header[8], header[9], 0, 8 };
    GifWriter writer = GifWriter{};
    writer.file = file;
    writer.success = success
        && WriteBytes(file, header, sizeof(header))
        && WriteBytes(file, palette, sizeof(palette))
        && WriteBytes(file, descriptor, sizeof(descriptor));
    GifCode(writer, 256);
    int literals = 0;
    for (SIZE_T index = 0; index < count && writer.success; ++index) {
        DWORD color = pixels[index * 4] | pixels[index * 4 + 1] << 8 | pixels[index * 4 + 2] << 16;
        DWORD slot = color * 2654435761U >> 20;
        while (colors[slot].color != color + 1) {
            slot = slot + 1 & 4095;
        }
        GifCode(writer, colors[slot].index);
        if (++literals == 250) {
            GifCode(writer, 256);
            literals = 0;
        }
    }
    GifCode(writer, 257);
    if (writer.bits) {
        GifByte(writer, static_cast<BYTE>(writer.packed));
    }
    if (writer.count) {
        BYTE length = static_cast<BYTE>(writer.count);
        writer.success = writer.success
            && WriteBytes(file, &length, 1)
            && WriteBytes(file, writer.block, length);
    }
    const BYTE end[] = { 0, 0x3B };
    writer.success = writer.success && WriteBytes(file, end, 2);
    HeapFree(GetProcessHeap(), 0, colors);
    return writer.success;
}

/// Reports whether the requested image format can be written without substituting another format.
bool IsReportImageTypeAvailable(DWORD type) {
    if (type == 8) {
        JpegEncoder encoder;
        return encoder.IsAvailable();
    }
    if (type == 11) {
        WebpEncoder encoder;
        return encoder.IsAvailable();
    }
    return type >= 6 && type <= 10;
}

/// Saves the supplied image pixels in WebP format.
static bool SaveWebpImage(HANDLE file, BYTE* pixels, int width, int height) {
    WebpEncoder encoder;
    return encoder.Save(file, pixels, width, height);
}

/// Renders the entire report in its selected font and saves it with the requested available encoder.
bool SaveReportImage(HWND edit, const wchar_t* report, const wchar_t* path, DWORD type, wchar_t* error,
        int errorCapacity) {
    if (type < 6 || type > 11) {
        lstrcpynW(error, T(TXT_IMAGE_FORMAT_UNSUPPORTED), errorCapacity);
        return false;
    }
    HDC screen = GetDC(edit);
    HDC dc = screen ? CreateCompatibleDC(screen) : nullptr;
    if (screen) {
        ReleaseDC(edit, screen);
    }
    if (!dc) {
        lstrcpynW(error, T(TXT_REPORT_IMAGE_CREATE_FAILED), errorCapacity);
        return false;
    }
    int dpiX = GetDeviceCaps(dc, LOGPIXELSX);
    int dpiY = GetDeviceCaps(dc, LOGPIXELSY);
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(edit, WM_GETFONT, 0, 0));
    HGDIOBJ oldFont = SelectObject(dc, font);
    RECT measured = RECT{ 0, 0, 1, 0 };
    DrawTextW(dc, report, -1, &measured, DT_CALCRECT | DT_NOPREFIX | DT_EXPANDTABS);
    TEXTMETRICW metrics = TEXTMETRICW{};
    GetTextMetricsW(dc, &metrics);
    int margin = metrics.tmAveCharWidth;
    int width = measured.right + 2 * margin;
    int height = measured.bottom + 2 * margin;
    if (width < 1
            || height < 1
            || width > 16384
            || height > 32767
            || width > 0x10000000 / 4 / height
            || type == 11 && (width > 16383 || height > 16383)) {
        SelectObject(dc, oldFont);
        DeleteDC(dc);
        const wchar_t* message = T(TXT_REPORT_IMAGE_TOO_LARGE);
        lstrcpynW(error, message, errorCapacity);
        return false;
    }
    BITMAPINFO info = BITMAPINFO{};
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = width;
    info.bmiHeader.biHeight = -height;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    BYTE* pixels = nullptr;
    HBITMAP bitmap =
        CreateDIBSection(dc, &info, DIB_RGB_COLORS, reinterpret_cast<void**>(&pixels), nullptr, 0);
    bool success = false;
    if (bitmap) {
        HGDIOBJ oldBitmap = SelectObject(dc, bitmap);
        RECT bounds = RECT{ 0, 0, width, height };
        HWND parent = GetParent(edit);
        HBRUSH background = reinterpret_cast<HBRUSH>(SendMessageW(parent, WM_CTLCOLORSTATIC,
            reinterpret_cast<WPARAM>(dc), reinterpret_cast<LPARAM>(edit)));
        if (!background) {
            background = reinterpret_cast<HBRUSH>(DefWindowProcW(parent, WM_CTLCOLORSTATIC,
                reinterpret_cast<WPARAM>(dc), reinterpret_cast<LPARAM>(edit)));
        }
        FillRect(dc, &bounds, background);
        SetBkMode(dc, OPAQUE);
        bounds = RECT{ margin, margin, width - margin, height - margin };
        DrawTextW(dc, report, -1, &bounds, DT_NOPREFIX | DT_EXPANDTABS);
        GdiFlush();
        wchar_t fullPath[MAX_PATH];
        wchar_t temporary[MAX_PATH];
        wchar_t* name = nullptr;
        DWORD length = GetFullPathNameW(path, MAX_PATH, fullPath, &name);
        if (length && length < MAX_PATH && name) {
            *name = 0;
            if (GetTempFileNameW(fullPath, L"MIV", 0, temporary)) {
                if (type == 8) {
                    SelectObject(dc, oldBitmap);
                    JpegEncoder encoder;
                    success = encoder.Save(temporary, bitmap);
                    SelectObject(dc, bitmap);
                } else {
                    HANDLE file = CreateFileW(temporary, GENERIC_WRITE, 0, nullptr,
                        TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
                    if (file != INVALID_HANDLE_VALUE) {
                        switch (type) {
                            case 9:
                                success = WritePng(file, pixels, width, height);
                                break;
                            case 7:
                                success = WriteGif(file, pixels, width, height);
                                break;
                            case 6:
                                success = WriteBmp(file, pixels, width, height, dpiX, dpiY);
                                break;
                            case 10:
                                success = WriteTiff(file, pixels, width, height, dpiX, dpiY);
                                break;
                            case 11:
                                success = SaveWebpImage(file, pixels, width, height);
                                break;
                        }
                        if (!CloseHandle(file)) {
                            success = false;
                        }
                    }
                }
                if (success) {
                    success = MoveFileExW(temporary, path, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)
                        != FALSE;
                }
                if (!success) {
                    DeleteFileW(temporary);
                }
            }
        }
        SelectObject(dc, oldBitmap);
        DeleteObject(bitmap);
    }
    SelectObject(dc, oldFont);
    DeleteDC(dc);
    if (!success) {
        lstrcpynW(error, T(imageErrors[type - 6]), errorCapacity);
    }
    return success;
}

/// Writes the complete text-export buffer while handling partial writes.
static bool WriteTextBytes(HANDLE file, const void* source, DWORD size) {
    const BYTE* cursor = static_cast<const BYTE*>(source);
    while (size) {
        DWORD written = 0;
        if (!WriteFile(file, cursor, size, &written, nullptr) || !written) {
            return false;
        }
        cursor += written;
        size -= written;
    }
    return true;
}

/// Writes the selected text encoding while preserving characters and original line endings.
static bool WriteEncodedText(HANDLE file, const wchar_t* report, DWORD type, bool* encodingError) {
    int length = lstrlenW(report);
    if (type >= 4) {
        WORD marker = type == 4 ? 0xFFFE : 0xFEFF;
        if (!WriteTextBytes(file, &marker, sizeof(marker))) {
            return false;
        }
        if (type == 5) {
            return WriteTextBytes(file, report, length * sizeof(wchar_t));
        }
        BYTE buffer[4096];
        DWORD used = 0;
        for (int index = 0; index < length; ++index) {
            buffer[used++] = static_cast<BYTE>(report[index] >> 8);
            buffer[used++] = static_cast<BYTE>(report[index]);
            if (used == sizeof(buffer)) {
                if (!WriteTextBytes(file, buffer, used)) {
                    return false;
                }
                used = 0;
            }
        }
        return WriteTextBytes(file, buffer, used);
    }
    UINT codePage = type == 1 ? GetACP() : CP_UTF8;
    if (codePage == CP_UTF8) {
        for (int index = 0; index < length; ++index) {
            WORD value = report[index];
            if (value >= 0xD800 && value <= 0xDBFF) {
                if (++index == length || report[index] < 0xDC00 || report[index] > 0xDFFF) {
                    *encodingError = true;
                    return false;
                }
            } else if (value >= 0xDC00 && value <= 0xDFFF) {
                *encodingError = true;
                return false;
            }
        }
    }
    const BYTE marker[] = { 0xEF, 0xBB, 0xBF };
    if (type == 3 && !WriteTextBytes(file, marker, sizeof(marker))) {
        return false;
    }
    if (!length) {
        return true;
    }
    int size = WideCharToMultiByte(codePage, 0, report, length, nullptr, 0, nullptr, nullptr);
    BYTE* bytes = size > 0 ? static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), 0, size)) : nullptr;
    if (!bytes) {
        return false;
    }
    bool success = WideCharToMultiByte(codePage, 0, report, length, reinterpret_cast<char*>(bytes),
        size, nullptr, nullptr) == size;
    if (success && type == 1) {
        wchar_t* restored = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0, length * sizeof(wchar_t)));
        if (restored) {
            int count = MultiByteToWideChar(codePage, 0,
                reinterpret_cast<const char*>(bytes), size, restored, length);
            *encodingError = count != length;
            for (int index = 0; index < length && !*encodingError; ++index) {
                *encodingError = restored[index] != report[index];
            }
            success = !*encodingError;
            HeapFree(GetProcessHeap(), 0, restored);
        } else {
            success = false;
        }
    }
    if (success) {
        success = WriteTextBytes(file, bytes, size);
    }
    HeapFree(GetProcessHeap(), 0, bytes);
    return success;
}

/// Saves the report in the selected text encoding, replacing the destination only after a complete write.
bool SaveReportText(const wchar_t* report, const wchar_t* path, DWORD type, wchar_t* error,
        int errorCapacity) {
    wchar_t folder[MAX_PATH];
    wchar_t temporary[MAX_PATH];
    wchar_t* name = nullptr;
    DWORD length = GetFullPathNameW(path, MAX_PATH, folder, &name);
    bool success = false;
    bool encodingError = false;
    if (report && type >= 1 && type <= 5 && length && length < MAX_PATH && name) {
        *name = 0;
        if (GetTempFileNameW(folder, L"MIV", 0, temporary)) {
            HANDLE file = CreateFileW(temporary, GENERIC_WRITE, 0, nullptr, TRUNCATE_EXISTING,
                FILE_ATTRIBUTE_NORMAL, nullptr);
            if (file != INVALID_HANDLE_VALUE) {
                success = WriteEncodedText(file, report, type, &encodingError);
                if (!CloseHandle(file)) {
                    success = false;
                }
            }
            if (success) {
                success = MoveFileExW(temporary, path, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)
                    != FALSE;
            }
            if (!success) {
                DeleteFileW(temporary);
            }
        }
    }
    if (!success) {
        lstrcpynW(error, T(encodingError ? TXT_TEXT_ENCODING_FAILED : TXT_TEXT_EXPORT_FAILED), errorCapacity);
    }
    return success;
}

/// Releases a print snapshot and its selected printer device context.
void FreePrintJob(PrintJob* job) {
    if (job) {
        if (job->printer) {
            DeleteDC(job->printer);
        }
        if (job->report) {
            HeapFree(GetProcessHeap(), 0, job->report);
        }
        HeapFree(GetProcessHeap(), 0, job);
    }
}

/// Captures report text and font and opens the native system printer-selection dialog.
PrintJob* ChooseReportPrinter(HWND owner, HWND edit, const wchar_t* report, const wchar_t* title,
    wchar_t* error, int errorCapacity) {
    error[0] = 0;
    PrintJob* job = static_cast<PrintJob*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(PrintJob)));
    if (job) {
        job->target = owner;
        job->fontDpi = WindowDpi(edit);
        HFONT font = reinterpret_cast<HFONT>(SendMessageW(edit, WM_GETFONT, 0, 0));
        SIZE_T bytes = (static_cast<SIZE_T>(lstrlenW(report)) + 1) * sizeof(wchar_t);
        job->report = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0, bytes));
        if (job->report
                && GetObjectW(font, sizeof(job->font), &job->font) == static_cast<int>(sizeof(job->font))) {
            CopyMemory(job->report, report, bytes);
            lstrcpynW(job->title, title, ARRAYSIZE(job->title));
            PRINTDLGW dialog = PRINTDLGW{};
            dialog.lStructSize = sizeof(dialog);
            dialog.hwndOwner = owner;
            dialog.Flags = PD_RETURNDC | PD_USEDEVMODECOPIESANDCOLLATE | PD_NOSELECTION | PD_NOPAGENUMS;
            dialog.nMinPage = 1;
            dialog.nMaxPage = 65535;
            dialog.nFromPage = 1;
            dialog.nToPage = 1;
            dialog.nCopies = 1;
            bool selected = PrintDlgW(&dialog) != FALSE;
            DWORD failure = selected ? 0 : CommDlgExtendedError();
            job->printer = dialog.hDC;
            job->printToFile = (dialog.Flags & PD_PRINTTOFILE) != 0;
            if (dialog.hDevMode) {
                GlobalFree(dialog.hDevMode);
            }
            if (dialog.hDevNames) {
                GlobalFree(dialog.hDevNames);
            }
            if (selected && job->printer) {
                return job;
            }
            if (!selected && !failure) {
                FreePrintJob(job);
                return nullptr;
            }
        }
    }
    FreePrintJob(job);
    lstrcpynW(error, T(TXT_PRINT_FAILED), errorCapacity);
    return nullptr;
}

/// Fits one printed line to the page width, preserving surrogate pairs and complete words when possible.
static int PrintedLineLength(HDC printer, const wchar_t* text, int length, int width) {
    int first = 0;
    int last = length;
    while (first < last) {
        int count = first + (last - first + 1) / 2;
        RECT measured = RECT{ 0, 0, width, 0 };
        if (!DrawTextW(printer, text, count, &measured,
            DT_CALCRECT | DT_SINGLELINE | DT_NOPREFIX | DT_EXPANDTABS)) {
            return 0;
        }
        if (measured.right <= width) {
            first = count;
        } else {
            last = count - 1;
        }
    }
    if (first && text[first - 1] >= 0xD800 && text[first - 1] <= 0xDBFF
        && text[first] >= 0xDC00 && text[first] <= 0xDFFF) {
        --first;
    }
    if (first < length) {
        for (int count = first; count > 0; --count) {
            if (text[count - 1] == L' ' || text[count - 1] == L'\t') {
                return count;
            }
        }
    }
    return first;
}

/// Prints the complete snapshot with page breaks and printer-scaled report font.
bool PrintReportPages(PrintJob* job) {
    if (job->canceled || !job->fontDpi) {
        return false;
    }
    int dpiX = GetDeviceCaps(job->printer, LOGPIXELSX);
    int dpiY = GetDeviceCaps(job->printer, LOGPIXELSY);
    int left = dpiX / 2;
    int top = dpiY / 2;
    int width = GetDeviceCaps(job->printer, HORZRES) - 2 * left;
    int height = GetDeviceCaps(job->printer, VERTRES) - 2 * top;
    if (dpiX <= 0 || dpiY <= 0 || width <= 0 || height <= 0) {
        return false;
    }
    LOGFONTW description = job->font;
    description.lfHeight = MulDiv(description.lfHeight, dpiY, job->fontDpi);
    description.lfWidth = MulDiv(description.lfWidth, dpiX, job->fontDpi);
    HFONT font = CreateFontIndirectW(&description);
    if (!font) {
        return false;
    }
    HGDIOBJ previous = SelectObject(job->printer, font);
    TEXTMETRICW metrics = TEXTMETRICW{};
    bool success = previous && previous != HGDI_ERROR && GetTextMetricsW(job->printer, &metrics);
    int lineHeight = metrics.tmHeight + metrics.tmExternalLeading;
    int rows = success && lineHeight > 0 ? height / lineHeight : 0;
    DOCINFOW document = DOCINFOW{};
    document.cbSize = sizeof(document);
    document.lpszDocName = job->title;
    document.lpszOutput = job->printToFile ? L"FILE:" : nullptr;
    bool started = success && rows > 0 && !job->canceled && StartDocW(job->printer, &document) > 0;
    success = started;
    bool page = false;
    int row = 0;
    const wchar_t* cursor = job->report;
    if (started) {
        do {
            if (job->canceled) {
                success = false;
                break;
            }
            if (!page) {
                if (StartPage(job->printer) <= 0) {
                    success = false;
                    break;
                }
                page = true;
                HGDIOBJ selected = SelectObject(job->printer, font);
                if (!selected || selected == HGDI_ERROR) {
                    success = false;
                    break;
                }
                SetTextColor(job->printer, RGB(0, 0, 0));
                SetBkMode(job->printer, TRANSPARENT);
            }
            int length = 0;
            while (length < 8192 && cursor[length] && cursor[length] != L'\r' && cursor[length] != L'\n') {
                ++length;
            }
            int count = length ? PrintedLineLength(job->printer, cursor, length, width) : 0;
            if (length && !count) {
                success = false;
                break;
            }
            RECT line = RECT{ left, top + row * lineHeight, left + width, top + (row + 1) * lineHeight };
            if (count && !DrawTextW(job->printer, cursor, count, &line,
                    DT_SINGLELINE | DT_NOPREFIX | DT_EXPANDTABS)) {
                success = false;
                break;
            }
            cursor += count;
            if (count == length) {
                if (*cursor == L'\r') {
                    ++cursor;
                    if (*cursor == L'\n') {
                        ++cursor;
                    }
                } else if (*cursor == L'\n') {
                    ++cursor;
                }
            }
            if (++row == rows) {
                if (EndPage(job->printer) <= 0) {
                    success = false;
                    break;
                }
                page = false;
                row = 0;
            }
        } while (*cursor);
        if (success && page) {
            success = EndPage(job->printer) > 0;
        }
        if (success && !job->canceled) {
            success = EndDoc(job->printer) > 0;
        } else {
            success = false;
        }
    }
    if (!success) {
        DWORD failure = GetLastError();
        if (failure == ERROR_CANCELLED || failure == ERROR_PRINT_CANCELLED) {
            InterlockedExchange(&job->canceled, 1);
        }
        if (started) {
            AbortDoc(job->printer);
        }
    }
    if (previous && previous != HGDI_ERROR) {
        SelectObject(job->printer, previous);
    }
    DeleteObject(font);
    return success;
}

/// Builds native file-dialog label and pattern pairs without changing their wildcard expressions.
static bool LocalizeFileFilters(const LocalizedFileFilter* source, wchar_t* destination, int capacity) {
    wchar_t* cursor = destination;
    while (source->pattern) {
        const wchar_t* label = T(source->text);
        int length = lstrlenW(label) + lstrlenW(source->pattern) + 2;
        if (cursor - destination + length >= capacity) {
            return false;
        }
        lstrcpyW(cursor, label);
        cursor += lstrlenW(cursor) + 1;
        lstrcpyW(cursor, source->pattern);
        cursor += lstrlenW(cursor) + 1;
        ++source;
    }
    *cursor = 0;
    return true;
}

/// Reports file-dialog failures while leaving ordinary user cancellation silent.
static void FileDialogError(HWND owner, HRESULT result) {
    if (FAILED(result) && result != HRESULT_FROM_WIN32(ERROR_CANCELLED)) {
        MessageBoxW(owner, result == HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE)
            ? T(TXT_SELECTED_PATHS_TOO_LONG)
            : T(TXT_FILE_DIALOG_SELECTION_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
    }
}

/// Expands the legacy multi-selection buffer into a double-null-terminated list of full paths.
static wchar_t* ExpandLegacySelection(const wchar_t* selection) {
    const wchar_t* name = selection + lstrlenW(selection) + 1;
    if (!*name) {
        SIZE_T length = lstrlenW(selection) + 2;
        wchar_t* result =
            static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, length * sizeof(wchar_t)));
        if (result) {
            lstrcpyW(result, selection);
        }
        return result;
    }
    SIZE_T capacity = 1;
    int folderLength = lstrlenW(selection);
    for (const wchar_t* cursor = name; *cursor; cursor += lstrlenW(cursor) + 1) {
        capacity += folderLength + lstrlenW(cursor) + 2;
    }
    wchar_t* result =
        static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, capacity * sizeof(wchar_t)));
    if (!result) {
        return nullptr;
    }
    wchar_t* destination = result;
    while (*name) {
        lstrcpyW(destination, selection);
        lstrcatW(destination, L"\\");
        lstrcatW(destination, name);
        destination += lstrlenW(destination) + 1;
        name += lstrlenW(name) + 1;
    }
    return result;
}

/// Chooses media paths with a modern native dialog when available and the legacy dialog otherwise.
wchar_t* ChooseMediaFiles(HWND owner) {
    wchar_t filters[512];
    if (!LocalizeFileFilters(mediaFilters, filters, 512)) {
        FileDialogError(owner, E_OUTOFMEMORY);
        return nullptr;
    }
    wchar_t folder[MAX_PATH];
    LoadOpenFolderSetting(folder, MAX_PATH);
    ModernFileDialog modern(false);
    if (modern.Prepare(filters, 1, T(TXT_OPEN_TITLE), nullptr, folder, nullptr, true)) {
        HRESULT result = modern.Show(owner);
        wchar_t* paths = nullptr;
        if (SUCCEEDED(result)) {
            result = modern.CopyPaths(&paths);
        }
        FileDialogError(owner, result);
        if (paths && *paths) {
            SaveOpenFolderSetting(paths, true);
        }
        return paths;
    }
    const DWORD capacity = 32768;
    wchar_t* buffer =
        static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, capacity * sizeof(wchar_t)));
    if (!buffer) {
        return nullptr;
    }
    OPENFILENAMEW dialog = OPENFILENAMEW{};
    dialog.lStructSize = sizeof(OPENFILENAMEW);
    dialog.hwndOwner = owner;
    dialog.lpstrFilter = filters;
    dialog.lpstrFile = buffer;
    dialog.nMaxFile = capacity;
    dialog.lpstrTitle = T(TXT_OPEN_TITLE);
    dialog.lpstrInitialDir = folder[0] ? folder : nullptr;
    dialog.Flags =
        OFN_EXPLORER | OFN_ALLOWMULTISELECT | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
    wchar_t* paths = nullptr;
    if (GetOpenFileNameW(&dialog)) {
        paths = ExpandLegacySelection(buffer);
    } else {
        DWORD error = CommDlgExtendedError();
        if (error) {
            MessageBoxW(owner, error == 0x3003 ? T(TXT_TOO_MANY_FILES) : T(TXT_FILE_DIALOG_OPEN_FAILED),
                L"MediaInfo", MB_OK | MB_ICONERROR);
        }
    }
    HeapFree(GetProcessHeap(), 0, buffer);
    if (paths && *paths) {
        SaveOpenFolderSetting(paths, true);
    }
    return paths;
}

/// Selects the shared opening folder after the legacy folder browser has initialized.
static int CALLBACK OpenFolderBrowseCallback(HWND window, UINT message, LPARAM, LPARAM folder) {
    if (message == BFFM_INITIALIZED && folder) {
        SendMessageW(window, BFFM_SETSELECTIONW, TRUE, folder);
    }
    return 0;
}

/// Chooses a filesystem folder with the available native Shell dialog.
bool ChooseMediaFolder(HWND owner, wchar_t* path) {
    const wchar_t* title = T(TXT_OPEN_FOLDER_TITLE);
    wchar_t folder[MAX_PATH];
    LoadOpenFolderSetting(folder, MAX_PATH);
    ModernFileDialog modern(false);
    if (modern.PrepareFolder(title, folder)) {
        HRESULT result = modern.Show(owner);
        if (SUCCEEDED(result)) {
            result = modern.CopyPath(path);
        }
        FileDialogError(owner, result);
        if (SUCCEEDED(result)) {
            SaveOpenFolderSetting(path);
        }
        return SUCCEEDED(result);
    }
    HRESULT result = CoInitialize(nullptr);
    if (FAILED(result)) {
        FileDialogError(owner, result);
        return false;
    }
    wchar_t displayName[MAX_PATH];
    BROWSEINFOW browse = BROWSEINFOW{};
    browse.hwndOwner = owner;
    browse.pszDisplayName = displayName;
    browse.lpszTitle = title;
    browse.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
    browse.lpfn = OpenFolderBrowseCallback;
    browse.lParam = folder[0] ? reinterpret_cast<LPARAM>(folder) : 0;
    LPITEMIDLIST item = SHBrowseForFolderW(&browse);
    bool selected = item && SHGetPathFromIDListW(item, path);
    if (item) {
        CoTaskMemFree(item);
        if (!selected) {
            FileDialogError(owner, E_FAIL);
        }
    }
    CoUninitialize();
    if (selected) {
        SaveOpenFolderSetting(path);
    }
    return selected;
}

/// Chooses one path with matching modern and legacy native file-dialog behavior.
static bool ChooseSingleFile(HWND owner, wchar_t* path, const LocalizedFileFilter* sourceFilters,
        const wchar_t* title, bool saving = false, const wchar_t* extension = nullptr) {
    wchar_t filters[512];
    if (!LocalizeFileFilters(sourceFilters, filters, 512)) {
        FileDialogError(owner, E_OUTOFMEMORY);
        return false;
    }
    wchar_t folder[MAX_PATH] = L"";
    const wchar_t* name = path;
    for (const wchar_t* cursor = path; *cursor; ++cursor) {
        if (*cursor == L'\\' || *cursor == L'/') {
            name = cursor + 1;
        }
    }
    if (name != path) {
        lstrcpynW(folder, path, static_cast<int>(name - path) + 1);
    }
    ModernFileDialog modern(saving);
    if (modern.Prepare(filters, 1, title, name, folder, extension, false)) {
        HRESULT result = modern.Show(owner);
        if (SUCCEEDED(result)) {
            result = modern.CopyPath(path);
        }
        FileDialogError(owner, result);
        return SUCCEEDED(result);
    }
    OPENFILENAMEW dialog = OPENFILENAMEW{};
    dialog.lStructSize = sizeof(OPENFILENAMEW);
    dialog.hwndOwner = owner;
    dialog.lpstrFilter = filters;
    dialog.lpstrFile = path;
    dialog.nMaxFile = MAX_PATH;
    dialog.lpstrTitle = title;
    dialog.lpstrDefExt = extension;
    dialog.Flags = OFN_EXPLORER | OFN_HIDEREADONLY | OFN_NOCHANGEDIR
        | (saving ? OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT : OFN_FILEMUSTEXIST);
    bool selected = (saving ? GetSaveFileNameW(&dialog) : GetOpenFileNameW(&dialog)) != FALSE;
    if (!selected && CommDlgExtendedError()) {
        FileDialogError(owner, E_FAIL);
    }
    return selected;
}

/// Reads at most the header limit from the beginning of an already opened binary input.
static bool ReadHeaderBytes(HANDLE file, BYTE* bytes, DWORD* size) {
    *size = 0;
    while (*size < headerByteLimit) {
        DWORD read = 0;
        if (!ReadFile(file, bytes + *size, headerByteLimit - *size, &read, nullptr)) {
            return false;
        }
        if (!read) {
            break;
        }
        *size += read;
    }
    return true;
}

/// Saves captured header bytes, replacing the destination only after a complete write and close.
static bool SaveHeaderBytes(const wchar_t* path, const BYTE* bytes, DWORD size) {
    wchar_t folder[MAX_PATH];
    wchar_t temporary[MAX_PATH];
    wchar_t* name = nullptr;
    DWORD length = GetFullPathNameW(path, ARRAYSIZE(folder), folder, &name);
    if (!length || length >= ARRAYSIZE(folder) || !name) {
        return false;
    }
    *name = 0;
    if (!GetTempFileNameW(folder, L"MIH", 0, temporary)) {
        return false;
    }
    HANDLE file = CreateFileW(temporary, GENERIC_WRITE, 0, nullptr, TRUNCATE_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);
    bool success = false;
    if (file != INVALID_HANDLE_VALUE) {
        success = WriteTextBytes(file, bytes, size);
        if (!CloseHandle(file)) {
            success = false;
        }
    }
    if (success) {
        success = MoveFileExW(temporary, path, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != FALSE;
    }
    if (!success) {
        DeleteFileW(temporary);
    }
    return success;
}

/// Chooses an input and saves its first 512 KiB, remembering only the tool's session opening folder.
void CreateHeaderFile(HWND owner, wchar_t* folder) {
    wchar_t source[MAX_PATH];
    lstrcpynW(source, folder, ARRAYSIZE(source));
    int length = lstrlenW(source);
    if (length && source[length - 1] != L'\\' && length + 1 < MAX_PATH) {
        lstrcatW(source, L"\\");
    }
    if (!ChooseSingleFile(owner, source, headerInputFilters, T(TXT_CREATE_HEADER_OPEN_TITLE))) {
        return;
    }
    const wchar_t* name = source;
    for (const wchar_t* cursor = source; *cursor; ++cursor) {
        if (*cursor == L'\\' || *cursor == L'/') {
            name = cursor + 1;
        }
    }
    if (name != source) {
        lstrcpynW(folder, source, static_cast<int>(name - source) + 1);
    }
    if (lstrlenW(source) + lstrlenW(L".header") >= MAX_PATH) {
        FileDialogError(owner, HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE));
        return;
    }
    HCURSOR previous = SetCursor(LoadCursorW(nullptr, IDC_WAIT));
    BYTE* bytes = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), 0, headerByteLimit));
    HANDLE input = CreateFileW(source, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);
    DWORD size = 0;
    bool success = bytes && input != INVALID_HANDLE_VALUE && ReadHeaderBytes(input, bytes, &size);
    SetCursor(previous);
    if (success) {
        wchar_t destination[MAX_PATH];
        lstrcpyW(destination, source);
        lstrcatW(destination, L".header");
        if (ChooseSingleFile(owner, destination, headerOutputFilters,
            T(TXT_CREATE_HEADER_SAVE_TITLE), true, L"header")) {
            previous = SetCursor(LoadCursorW(nullptr, IDC_WAIT));
            success = SaveHeaderBytes(destination, bytes, size);
            SetCursor(previous);
            if (!success) {
                wchar_t error[MAX_PATH + 256];
                wsprintfW(error, T(TXT_HEADER_SAVE_FAILED), destination);
                MessageBoxW(owner, error, L"MediaInfo", MB_OK | MB_ICONERROR);
            }
        }
    } else {
        wchar_t error[MAX_PATH + 256];
        wsprintfW(error, T(TXT_HEADER_READ_FAILED), source);
        MessageBoxW(owner, error, L"MediaInfo", MB_OK | MB_ICONERROR);
    }
    if (input != INVALID_HANDLE_VALUE) {
        CloseHandle(input);
    }
    if (bytes) {
        HeapFree(GetProcessHeap(), 0, bytes);
    }
}

/// Chooses an x86 MediaInfo or curl DLL path using the corresponding localized file filters.
bool ChooseLibraryFile(HWND owner, wchar_t* path, bool curl) {
    return ChooseSingleFile(owner, path, curl ? curlFilters : libraryFilters,
        curl ? T(TXT_SELECT_CURL) : T(TXT_SELECT_MEDIALIB));
}

/// Chooses a custom MediaInfo translation table using the CSV file filter.
bool ChooseReportLanguageFile(HWND owner, wchar_t* path) {
    return ChooseSingleFile(owner, path, reportLanguageFilters, T(TXT_SELECT_REPORT_LANGUAGE));
}

/// Builds the ordered export-format list from the encoders available on the running system.
static bool BuildExportFilters(wchar_t* filters, DWORD capacity, ExportDialogData* data, DWORD type,
        UINT* selected) {
    wchar_t* cursor = filters;
    *selected = 2;
    for (UINT index = 0; index < ARRAYSIZE(exportChoices); ++index) {
        const ExportChoice& choice = exportChoices[index];
        if (choice.type > 5 && !IsReportImageTypeAvailable(choice.type)) {
            continue;
        }
        const wchar_t* label = T(choice.label);
        DWORD length = lstrlenW(label) + lstrlenW(choice.pattern) + 2;
        if (cursor - filters + length >= capacity) {
            return false;
        }
        data->choices[data->count++] = &choice;
        if (choice.type == type) {
            *selected = data->count;
        }
        lstrcpyW(cursor, label);
        cursor += lstrlenW(cursor) + 1;
        lstrcpyW(cursor, choice.pattern);
        cursor += lstrlenW(cursor) + 1;
    }
    *cursor = 0;
    return data->count != 0;
}

/// Updates the legacy export dialog extension when the selected format changes.
static UINT_PTR CALLBACK ExportSaveHook(HWND window, UINT message, WPARAM, LPARAM lParam) {
    if (message == WM_NOTIFY) {
        OFNOTIFYW* notification = reinterpret_cast<OFNOTIFYW*>(lParam);
        if (notification->hdr.code == CDN_TYPECHANGE) {
            ExportDialogData* data = reinterpret_cast<ExportDialogData*>(notification->lpOFN->lCustData);
            UINT index = notification->lpOFN->nFilterIndex;
            if (data && index >= 1 && index <= data->count) {
                SendMessageW(GetParent(window), CDM_SETDEFEXT, 0,
                    reinterpret_cast<LPARAM>(data->choices[index - 1]->extension));
            }
        }
    }
    return 0;
}

/// Chooses an export destination and an available output format with matching native Save dialogs.
bool ChooseExportFile(HWND owner, wchar_t* path, const wchar_t* title, DWORD* type) {
    wchar_t folder[MAX_PATH];
    LoadExportSetting(folder, MAX_PATH, type);
    if (!folder[0]) {
        LPITEMIDLIST documents = nullptr;
        if (SUCCEEDED(SHGetSpecialFolderLocation(owner, CSIDL_PERSONAL, &documents))) {
            SHGetPathFromIDListW(documents, folder);
            CoTaskMemFree(documents);
        }
    }
    wchar_t exportFilters[1024];
    ExportDialogData data = ExportDialogData{};
    UINT selected = 1;
    if (!BuildExportFilters(exportFilters, 1024, &data, *type, &selected)) {
        FileDialogError(owner, E_FAIL);
        return false;
    }
    const wchar_t* extension = data.choices[selected - 1]->extension;
    if (lstrlenW(path) + 5 < MAX_PATH) {
        lstrcatW(path, L".");
        lstrcatW(path, extension);
    }
    ModernFileDialog modern(true);
    if (modern.Prepare(exportFilters, selected, title, path, folder, extension, false)) {
        HRESULT result = modern.Show(owner);
        if (SUCCEEDED(result)) {
            result = modern.CopyPath(path);
        }
        if (SUCCEEDED(result)) {
            UINT index = modern.GetType();
            if (index >= 1 && index <= data.count) {
                *type = data.choices[index - 1]->type;
            } else {
                result = E_INVALIDARG;
            }
        }
        FileDialogError(owner, result);
        return SUCCEEDED(result);
    }
    OPENFILENAMEW dialog = OPENFILENAMEW{};
    dialog.lStructSize = sizeof(OPENFILENAMEW);
    dialog.hwndOwner = owner;
    dialog.lpstrFilter = exportFilters;
    dialog.nFilterIndex = selected;
    dialog.lpstrFile = path;
    dialog.nMaxFile = MAX_PATH;
    dialog.lpstrInitialDir = folder[0] ? folder : nullptr;
    dialog.lpstrDefExt = extension;
    dialog.lpstrTitle = title;
    dialog.lpfnHook = ExportSaveHook;
    dialog.lCustData = reinterpret_cast<LPARAM>(&data);
    dialog.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT
        | OFN_HIDEREADONLY | OFN_NOCHANGEDIR | OFN_ENABLEHOOK;
    if (!GetSaveFileNameW(&dialog)) {
        return false;
    }
    if (dialog.nFilterIndex < 1 || dialog.nFilterIndex > data.count) {
        FileDialogError(owner, E_INVALIDARG);
        return false;
    }
    *type = data.choices[dialog.nFilterIndex - 1]->type;
    return true;
}

/// Checks the viewer callback for an operation that prevents applying library changes.
static bool PreferencesBusy(const PreferencesData& data) {
    return data.callbacks && data.callbacks->busy && data.callbacks->busy(data.callbacks->context);
}

/// Checks the live viewer or saved registry state for recent files that can be cleared.
static bool PreferencesHasRecentFiles(const PreferencesData& data) {
    return data.callbacks && data.callbacks->hasRecentFiles
        ? data.callbacks->hasRecentFiles(data.callbacks->context)
        : HasRecentFilesSetting();
}

/// Moves focus through the native dialog manager before disabling a focused Preferences button.
static void EnablePreferencesControl(HWND window, int id, bool enabled) {
    HWND control = GetDlgItem(window, id);
    if (!enabled && GetFocus() == control) {
        HWND next = GetNextDlgTabItem(window, control, FALSE);
        SendMessageW(window, WM_NEXTDLGCTL, reinterpret_cast<WPARAM>(next), TRUE);
    }
    EnableWindow(control, enabled);
}

/// Compares pending controls and font choices with the last successfully applied preferences.
static bool PreferencesChanged(const PreferencesData& data) {
    wchar_t path[MAX_PATH];
    wchar_t curlPath[MAX_PATH];
    GetDlgItemTextW(data.window, IDC_DLL_PATH, path, MAX_PATH);
    GetDlgItemTextW(data.window, IDC_CURL_PATH, curlPath, MAX_PATH);
    if (lstrcmpiW(path, data.originalPath)
        || lstrcmpiW(curlPath, data.originalCurlPath)
        || lstrcmpiW(data.reportLanguage, data.originalReportLanguage)
        || data.language != data.originalLanguage
        || data.dpi != *data.appliedDpi
        || IsDlgButtonChecked(data.window, IDC_MULTIPLE_INSTANCES) == BST_CHECKED
            != data.originalMultipleInstances) {
        return true;
    }
    BOOL valid = FALSE;
    UINT length = GetDlgItemInt(data.window, IDC_TAB_NAME_LENGTH, &valid, FALSE);
    if (!valid || length != data.originalTabNameLength) {
        return true;
    }
    LOGFONTW original = *data.appliedFont;
    if (!original.lfQuality) {
        original.lfQuality = DefaultReportFontQuality();
    }
    const BYTE* before = reinterpret_cast<const BYTE*>(&original);
    const BYTE* after = reinterpret_cast<const BYTE*>(&data.font);
    for (UINT index = 0; index < sizeof(original); ++index) {
        if (before[index] != after[index]) {
            return true;
        }
    }
    return false;
}

/// Retains detected changes until successful explicit Apply, while respecting active library operations.
static void UpdateApplyButton(PreferencesData& data) {
    bool busy = PreferencesBusy(data);
    data.applyPending = data.applyPending || PreferencesChanged(data) || !data.library->IsLoaded();
    EnablePreferencesControl(data.window, IDOK, !busy);
    EnablePreferencesControl(data.window, IDC_PREFERENCES_APPLY, !busy && data.applyPending);
    EnablePreferencesControl(data.window, IDC_RECENT_CLEAR, PreferencesHasRecentFiles(data));
}

/// Lists original English, official report translations and any selected custom translation table.
static void UpdateReportChoices(PreferencesData& data) {
    HWND combo = GetDlgItem(data.window, IDC_REPORT_LANGUAGE);
    SendMessageW(combo, CB_RESETCONTENT, 0, 0);
    int selected = ReportLanguageIndex(data.reportLanguage);
    for (int index = 0; index < ReportLanguageCount(); ++index) {
        LRESULT item = SendMessageW(combo, CB_ADDSTRING, 0,
            reinterpret_cast<LPARAM>(ReportLanguageName(index)));
        if (item >= 0) {
            SendMessageW(combo, CB_SETITEMDATA, item, index);
            if (index == selected) {
                SendMessageW(combo, CB_SETCURSEL, item, 0);
            }
        }
    }
    if (selected < 0) {
        LRESULT item = SendMessageW(combo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(data.reportLanguage));
        if (item >= 0) {
            SendMessageW(combo, CB_SETITEMDATA, item, static_cast<LPARAM>(-1));
            SendMessageW(combo, CB_SETCURSEL, item, 0);
        }
    }
}

/// Populates independent interface-language and report-language choices from their saved selections.
static void PopulateLanguages(PreferencesData& data) {
    HWND combo = GetDlgItem(data.window, IDC_LANGUAGE);
    SendMessageW(combo, CB_RESETCONTENT, 0, 0);
    for (int index = 0; index < applicationLanguageCount; ++index) {
        LRESULT item = SendMessageW(combo, CB_ADDSTRING, 0,
            reinterpret_cast<LPARAM>(ApplicationLanguageName(index)));
        if (item >= 0) {
            SendMessageW(combo, CB_SETITEMDATA, item, index);
            if (index == data.language) {
                SendMessageW(combo, CB_SETCURSEL, item, 0);
            }
        }
    }
    UpdateReportChoices(data);
}

/// Applies translated Preferences captions without changing pending settings.
static void SetPreferencesLabels(PreferencesData& data) {
    SetWindowTextW(data.window, T(TXT_PREFERENCES_TITLE));
    const int controls[] = {
        IDC_DLL_LABEL,
        IDC_DLL_BROWSE,
        IDC_CURL_LABEL,
        IDC_CURL_BROWSE,
        IDC_DLL_NOTE,
        IDC_FONT_LABEL,
        IDC_FONT_DEFAULT,
        IDC_SMOOTHING_LABEL,
        IDC_LANGUAGE_LABEL,
        IDC_REPORT_LABEL,
        IDC_REPORT_BROWSE,
        IDC_TAB_NAME_LABEL,
        IDC_RECENT_LABEL,
        IDC_RECENT_CLEAR,
        IDC_MULTIPLE_INSTANCES,
        IDOK,
        IDCANCEL,
        IDC_PREFERENCES_APPLY
    };
    const TextId labels[] = {
        TXT_MEDIALIB_PATH,
        TXT_BROWSE_DLL,
        TXT_CURL_PATH,
        TXT_BROWSE_CURL,
        TXT_LIBRARY_PATH_HINT,
        TXT_REPORT_FONT,
        TXT_FONT_DEFAULT,
        TXT_FONT_ANTIALIASING,
        TXT_LANGUAGE,
        TXT_REPORT_LANGUAGE,
        TXT_BROWSE_REPORT,
        TXT_TAB_NAME_LENGTH,
        TXT_RECENT_FILES,
        TXT_CLEAR_RECENT_FILES,
        TXT_ALLOW_MULTIPLE_INSTANCES,
        TXT_OK,
        TXT_CANCEL,
        TXT_APPLY
    };
    for (int index = 0; index < static_cast<int>(sizeof(controls) / sizeof(controls[0])); ++index) {
        SetDlgItemTextW(data.window, controls[index], T(labels[index]));
    }
}

/// Measures one Preferences label in its current font with native mnemonic processing.
static LONG PreferenceLabelWidth(HWND window, int control) {
    HWND label = GetDlgItem(window, control);
    wchar_t text[128];
    GetWindowTextW(label, text, 128);
    HDC dc = GetDC(label);
    if (!dc) {
        return 0;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(label, WM_GETFONT, 0, 0));
    HGDIOBJ previous = font ? SelectObject(dc, font) : nullptr;
    RECT bounds = RECT{};
    DrawTextW(dc, text, -1, &bounds, DT_CALCRECT | DT_SINGLELINE);
    if (previous) {
        SelectObject(dc, previous);
    }
    ReleaseDC(label, dc);
    return bounds.right;
}

/// Measures the native text baseline relative to a control window top.
static LONG PreferenceControlAscent(HWND control) {
    RECT bounds = RECT{};
    GetWindowRect(control, &bounds);
    return ControlTextBaseline(control) - bounds.top;
}

/// Moves a Preferences control to a shared baseline while retaining its size.
static void PlacePreferenceControlBaseline(HWND control, LONG baseline) {
    HWND parent = GetParent(control);
    RECT bounds = ControlRect(control, parent);
    POINT origin = POINT{};
    ClientToScreen(parent, &origin);
    LONG distance = origin.y + baseline - ControlTextBaseline(control);
    SetWindowPos(control, nullptr, bounds.left, bounds.top + distance, 0, 0,
        SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}

/// Limits the dialog to its monitor work area and exposes a native scrollbar only when content overflows.
static void FitPreferencesHeight(PreferencesData& data, int contentHeight) {
    RECT bounds = RECT{};
    RECT client = RECT{};
    GetWindowRect(data.window, &bounds);
    GetClientRect(data.window, &client);
    RECT work = WindowWorkArea(bounds);
    int fullHeight = contentHeight + bounds.bottom - bounds.top - client.bottom;
    int availableHeight = work.bottom - work.top;
    bool scrolling = fullHeight > availableHeight;
    LONG_PTR style = GetWindowLongPtrW(data.window, GWL_STYLE);
    bool wasScrolling = (style & WS_VSCROLL) != 0;
    int width = bounds.right - bounds.left +
        (static_cast<int>(scrolling) - static_cast<int>(wasScrolling)) * GetSystemMetrics(SM_CXVSCROLL);
    int height = scrolling ? availableHeight : fullHeight;
    if (scrolling != wasScrolling) {
        SetWindowLongPtrW(data.window, GWL_STYLE, scrolling ? style | WS_VSCROLL : style & ~WS_VSCROLL);
    }
    int x = bounds.left;
    int y = bounds.top;
    if (x + width > work.right) {
        x = work.right - width;
    }
    if (x < work.left) {
        x = work.left;
    }
    if (y + height > work.bottom) {
        y = work.bottom - height;
    }
    if (y < work.top) {
        y = work.top;
    }
    UINT flags = SWP_NOZORDER | SWP_NOACTIVATE | (scrolling != wasScrolling ? SWP_FRAMECHANGED : 0);
    SetWindowPos(data.window, nullptr, x, y, width, height, flags);
    data.contentHeight = scrolling ? contentHeight : 0;
    if (scrolling) {
        GetClientRect(data.window, &client);
        SCROLLINFO information = SCROLLINFO{};
        information.cbSize = sizeof(information);
        information.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
        information.nMin = 0;
        information.nMax = contentHeight - 1;
        information.nPage = client.bottom;
        information.nPos = 0;
        SetScrollInfo(data.window, SB_VERT, &information, TRUE);
    }
}

/// Scrolls the dialog's existing child controls within the native vertical scrollbar range.
static bool ScrollPreferences(PreferencesData& data, int request) {
    if (!data.contentHeight) {
        return false;
    }
    SCROLLINFO information = SCROLLINFO{};
    information.cbSize = sizeof(information);
    information.fMask = SIF_ALL;
    if (!GetScrollInfo(data.window, SB_VERT, &information)) {
        return false;
    }
    int position = information.nPos;
    int line = DialogUnits(data.uiFont, 0, 12).cy;
    if (line < 1) {
        line = 1;
    }
    switch (request) {
        case SB_LINEUP:
            position -= line;
            break;
        case SB_LINEDOWN:
            position += line;
            break;
        case SB_PAGEUP:
            position -= information.nPage;
            break;
        case SB_PAGEDOWN:
            position += information.nPage;
            break;
        case SB_THUMBPOSITION:
        case SB_THUMBTRACK:
            position = information.nTrackPos;
            break;
        case SB_TOP:
            position = information.nMin;
            break;
        case SB_BOTTOM:
            position = information.nMax;
            break;
        default:
            return true;
    }
    int maximum = information.nMax - static_cast<int>(information.nPage) + 1;
    if (position < information.nMin) {
        position = information.nMin;
    }
    if (position > maximum) {
        position = maximum;
    }
    if (position == information.nPos) {
        return true;
    }
    int previous = information.nPos;
    information.fMask = SIF_POS;
    information.nPos = position;
    SetScrollInfo(data.window, SB_VERT, &information, TRUE);
    data.scrollPosition = GetScrollPos(data.window, SB_VERT);
    ScrollWindowEx(data.window, 0, previous - data.scrollPosition, nullptr, nullptr, nullptr, nullptr,
        SW_SCROLLCHILDREN | SW_INVALIDATE | SW_ERASE);
    return true;
}

/// Measures translated notes and gives the lower Preferences rows a uniform baseline step.
static void LayoutPreferencesVertically(PreferencesData& data, const SIZE& margin) {
    HWND window = data.window;
    SIZE groupGap = DialogUnits(data.uiFont, 0, 4);
    SIZE rowGap = DialogUnits(data.uiFont, 0, 1);
    LONG top = margin.cy;
    const int pathLabels[] = { IDC_DLL_LABEL, IDC_CURL_LABEL };
    const int pathEdits[] = { IDC_DLL_PATH, IDC_CURL_PATH };
    const int pathButtons[] = { IDC_DLL_BROWSE, IDC_CURL_BROWSE };
    for (int index = 0; index < 2; ++index) {
        HWND label = GetDlgItem(window, pathLabels[index]);
        HWND edit = GetDlgItem(window, pathEdits[index]);
        HWND button = GetDlgItem(window, pathButtons[index]);
        RECT bounds = ControlRect(label, window);
        TEXTMETRICW metrics = TEXTMETRICW{};
        ReadControlMetrics(label, &metrics);
        PlaceControl(label, bounds.left, top, bounds.right - bounds.left, metrics.tmHeight);
        LONG above = PreferenceControlAscent(edit);
        LONG buttonAbove = PreferenceControlAscent(button);
        if (buttonAbove > above) {
            above = buttonAbove;
        }
        LONG baseline = top + metrics.tmHeight + above;
        PlacePreferenceControlBaseline(edit, baseline);
        PlacePreferenceControlBaseline(button, baseline);
        RECT editBounds = ControlRect(edit, window);
        RECT buttonBounds = ControlRect(button, window);
        top = (editBounds.bottom > buttonBounds.bottom ? editBounds.bottom : buttonBounds.bottom)
            + groupGap.cy;
    }
    HWND note = GetDlgItem(window, IDC_DLL_NOTE);
    RECT noteBounds = ControlRect(note, window);
    int noteHeight = WrappedLabelHeight(note, noteBounds.right - noteBounds.left);
    PlaceControl(note, noteBounds.left, top, noteBounds.right - noteBounds.left, noteHeight);
    const int rowLabels[] = {
        IDC_FONT_LABEL,
        IDC_SMOOTHING_LABEL,
        IDC_LANGUAGE_LABEL,
        IDC_REPORT_LABEL,
        IDC_TAB_NAME_LABEL,
        IDC_RECENT_LABEL
    };
    const int rowControls[] = {
        IDC_FONT_CHOOSE,
        IDC_SMOOTHING,
        IDC_LANGUAGE,
        IDC_REPORT_LANGUAGE,
        IDC_TAB_NAME_LENGTH,
        IDC_RECENT_CLEAR
    };
    const int rowExtras[] = {
        IDC_FONT_DEFAULT,
        0,
        0,
        IDC_REPORT_BROWSE,
        0,
        IDC_MULTIPLE_INSTANCES
    };
    LONG above = 0;
    LONG below = 0;
    for (int row = 0; row < 6; ++row) {
        HWND label = GetDlgItem(window, rowLabels[row]);
        RECT bounds = ControlRect(label, window);
        TEXTMETRICW metrics = TEXTMETRICW{};
        ReadControlMetrics(label, &metrics);
        PlaceControl(label, bounds.left, bounds.top, bounds.right - bounds.left, metrics.tmHeight);
        const int controls[] = { rowLabels[row], rowControls[row], rowExtras[row] };
        for (int id : controls) {
            if (!id) {
                continue;
            }
            HWND control = GetDlgItem(window, id);
            bounds = ControlRect(control, window);
            LONG ascent = PreferenceControlAscent(control);
            LONG descent = bounds.bottom - bounds.top - ascent;
            if (ascent > above) {
                above = ascent;
            }
            if (descent > below) {
                below = descent;
            }
        }
    }
    LONG baseline = top + noteHeight + groupGap.cy + above;
    LONG step = above + below + rowGap.cy;
    for (int row = 0; row < 6; ++row) {
        PlacePreferenceControlBaseline(GetDlgItem(window, rowLabels[row]), baseline);
        PlacePreferenceControlBaseline(GetDlgItem(window, rowControls[row]), baseline);
        if (rowExtras[row]) {
            PlacePreferenceControlBaseline(GetDlgItem(window, rowExtras[row]), baseline);
        }
        baseline += step;
    }
    RECT number = ControlRect(GetDlgItem(window, IDC_TAB_NAME_LENGTH), window);
    HWND spin = GetDlgItem(window, IDC_TAB_NAME_SPIN);
    RECT spinBounds = ControlRect(spin, window);
    SetWindowPos(spin, nullptr, spinBounds.left, number.top, spinBounds.right - spinBounds.left,
        number.bottom - number.top, SWP_NOZORDER | SWP_NOACTIVATE);
    LONG buttonsTop = baseline - step + below + DialogUnits(data.uiFont, 0, 6).cy;
    const int buttons[] = { IDOK, IDCANCEL, IDC_PREFERENCES_APPLY };
    LONG bottom = 0;
    for (int id : buttons) {
        HWND button = GetDlgItem(window, id);
        RECT bounds = ControlRect(button, window);
        SetWindowPos(button, nullptr, bounds.left, buttonsTop, 0, 0,
            SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
        if (bounds.bottom - bounds.top > bottom) {
            bottom = bounds.bottom - bounds.top;
        }
    }
    FitPreferencesHeight(data, buttonsTop + bottom + margin.cy);
}

/// Finds the enabled field associated with a localized Preferences label mnemonic.
static HWND PreferenceMnemonicTarget(HWND window, wchar_t key) {
    CharUpperBuffW(&key, 1);
    for (const auto& entry : preferencesLabelFields) {
        wchar_t caption[256];
        GetDlgItemTextW(window, entry[0], caption, ARRAYSIZE(caption));
        for (int index = 0; caption[index]; ++index) {
            if (caption[index] != L'&' || !caption[index + 1]) {
                continue;
            }
            wchar_t character = caption[++index];
            if (character == L'&') {
                continue;
            }
            CharUpperBuffW(&character, 1);
            HWND field = GetDlgItem(window, entry[1]);
            if (character == key && IsWindowEnabled(field) && GetWindowLongW(field, GWL_STYLE) & WS_VISIBLE) {
                return field;
            }
        }
    }
    return nullptr;
}

/// Preserves native field mnemonics when their labels are painted behind foreground controls.
static LRESULT CALLBACK PreferencesControlProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    WNDPROC original = reinterpret_cast<WNDPROC>(GetPropW(window, preferencesControlProperty));
    if (message == WM_NCDESTROY) {
        RemovePropW(window, preferencesControlProperty);
        SetWindowLongPtrW(window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(original));
    }
    if (message == WM_GETDLGCODE) {
        LRESULT result = CallWindowProcW(original, window, message, wParam, lParam);
        const MSG* key = reinterpret_cast<const MSG*>(lParam);
        if (key && key->message == WM_SYSCHAR
                && PreferenceMnemonicTarget(GetParent(window), static_cast<wchar_t>(key->wParam))) {
            result |= DLGC_WANTMESSAGE;
        }
        return result;
    }
    if (message == WM_SYSCHAR) {
        HWND target = PreferenceMnemonicTarget(GetParent(window), static_cast<wchar_t>(wParam));
        if (target) {
            SendMessageW(GetParent(window), WM_NEXTDLGCTL, reinterpret_cast<WPARAM>(target), TRUE);
            return 0;
        }
    }
    return CallWindowProcW(original, window, message, wParam, lParam);
}

/// Installs label mnemonic routing without replacing the tested edit selection handler or native Tab navigation.
static bool InstallPreferencesControlHandlers(HWND window) {
    for (HWND child = GetWindow(window, GW_CHILD); child; child = GetWindow(child, GW_HWNDNEXT)) {
        if (!(GetWindowLongW(child, GWL_STYLE) & WS_TABSTOP)) {
            continue;
        }
        WNDPROC original = reinterpret_cast<WNDPROC>(GetWindowLongPtrW(child, GWLP_WNDPROC));
        if (!SetPropW(child, preferencesControlProperty, reinterpret_cast<HANDLE>(original))) {
            return false;
        }
        SetLastError(0);
        if (!SetWindowLongPtrW(child, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(PreferencesControlProc))
                && GetLastError()) {
            RemovePropW(child, preferencesControlProperty);
            return false;
        }
    }
    return true;
}

/// Keeps full-width native labels beneath fields while retaining the foreground controls' native tab order.
static void OrderPreferencesLabels(HWND window) {
    const int labels[] = {
        IDC_DLL_LABEL,
        IDC_CURL_LABEL,
        IDC_DLL_NOTE,
        IDC_FONT_LABEL,
        IDC_SMOOTHING_LABEL,
        IDC_LANGUAGE_LABEL,
        IDC_REPORT_LABEL,
        IDC_TAB_NAME_LABEL,
        IDC_RECENT_LABEL
    };
    for (int id : labels) {
        SetWindowPos(GetDlgItem(window, id), HWND_BOTTOM, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    }
}

/// Fits Preferences controls to localized labels, native metrics and compact dialog-unit margins.
static void LayoutPreferences(PreferencesData& data) {
    HWND window = data.window;
    if (data.scrollPosition) {
        ScrollWindowEx(window, 0, data.scrollPosition, nullptr, nullptr, nullptr, nullptr,
            SW_SCROLLCHILDREN | SW_INVALIDATE | SW_ERASE);
        data.scrollPosition = 0;
        SetScrollPos(window, SB_VERT, 0, FALSE);
    }
    HWND path = GetDlgItem(window, IDC_DLL_PATH);
    HWND curlPath = GetDlgItem(window, IDC_CURL_PATH);
    HWND curlBrowse = GetDlgItem(window, IDC_CURL_BROWSE);
    HWND language = GetDlgItem(window, IDC_LANGUAGE);
    HWND reportLanguage = GetDlgItem(window, IDC_REPORT_LANGUAGE);
    HWND reportBrowse = GetDlgItem(window, IDC_REPORT_BROWSE);
    HWND font = GetDlgItem(window, IDC_FONT_CHOOSE);
    HWND browse = GetDlgItem(window, IDC_DLL_BROWSE);
    HWND reset = GetDlgItem(window, IDC_FONT_DEFAULT);
    HWND antialiasing = GetDlgItem(window, IDC_SMOOTHING);
    HWND cancel = GetDlgItem(window, IDCANCEL);
    HWND accept = GetDlgItem(window, IDOK);
    HWND apply = GetDlgItem(window, IDC_PREFERENCES_APPLY);
    HWND tabLength = GetDlgItem(window, IDC_TAB_NAME_LENGTH);
    HWND tabSpin = GetDlgItem(window, IDC_TAB_NAME_SPIN);
    HWND clear = GetDlgItem(window, IDC_RECENT_CLEAR);
    HWND multipleInstances = GetDlgItem(window, IDC_MULTIPLE_INSTANCES);
    UpdateEditMetrics(path);
    UpdateEditMetrics(curlPath);
    UpdateEditMetrics(tabLength);
    UpdateComboBoxMetrics(language);
    UpdateComboBoxMetrics(reportLanguage);
    UpdateComboBoxMetrics(antialiasing);
    RECT client = RECT{};
    GetClientRect(window, &client);
    SIZE margin = DialogUnits(data.uiFont, 8, 8);
    SIZE gap = DialogUnits(data.uiFont, 6, 0);
    SIZE button = data.buttonSize;
    const int buttons[] = {
        IDC_DLL_BROWSE,
        IDC_CURL_BROWSE,
        IDC_REPORT_BROWSE,
        IDC_FONT_DEFAULT,
        IDC_RECENT_CLEAR,
        IDOK,
        IDCANCEL,
        IDC_PREFERENCES_APPLY
    };
    for (int index = 0; index < 8; ++index) {
        SIZE preferred = PreferredButtonSize(GetDlgItem(window, buttons[index]), button);
        button.cx = preferred.cx;
    }
    SIZE checkSize = PreferredButtonSize(multipleInstances, SIZE{ 0, button.cy });
    LONG recentWidth = PreferenceLabelWidth(window, IDC_RECENT_LABEL);
    LONG requiredWidth = 2 * margin.cx + checkSize.cx + 2 * gap.cx + recentWidth + button.cx;
    if (requiredWidth > client.right) {
        RECT bounds = RECT{};
        GetWindowRect(window, &bounds);
        SetWindowPos(window, nullptr, 0, 0, bounds.right - bounds.left + requiredWidth - client.right,
            bounds.bottom - bounds.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
        client.right = requiredWidth;
    }
    int rightButton = client.right - margin.cx - button.cx;
    int bottom = client.bottom - margin.cy - button.cy;
    RECT pathBounds = ControlRect(path, window);
    RECT curlBounds = ControlRect(curlPath, window);
    pathBounds.left = margin.cx;
    curlBounds.left = margin.cx;
    RECT curlBrowseBounds = ControlRect(curlBrowse, window);
    RECT reportBounds = ControlRect(reportLanguage, window);
    RECT languageBounds = ControlRect(language, window);
    RECT reportBrowseBounds = ControlRect(reportBrowse, window);
    RECT fontBounds = ControlRect(font, window);
    RECT browseBounds = ControlRect(browse, window);
    RECT resetBounds = ControlRect(reset, window);
    RECT comboBounds = ControlRect(antialiasing, window);
    RECT lengthBounds = ControlRect(tabLength, window);
    RECT clearBounds = ControlRect(clear, window);
    SIZE column = DialogUnits(data.uiFont, 80, 0);
    const int columnLabels[] = {
        IDC_FONT_LABEL,
        IDC_SMOOTHING_LABEL,
        IDC_LANGUAGE_LABEL,
        IDC_REPORT_LABEL,
        IDC_TAB_NAME_LABEL
    };
    int columnLabelCount = static_cast<int>(sizeof(columnLabels) / sizeof(columnLabels[0]));
    for (int index = 0; index < columnLabelCount; ++index) {
        LONG required = margin.cx + PreferenceLabelWidth(window, columnLabels[index]) + gap.cx;
        if (required > column.cx) {
            column.cx = required;
        }
    }
    SIZE fullCombo = DialogUnits(data.uiFont, 180, 0);
    int comboWidth = (fullCombo.cx - data.widthReduction) / 2;
    fontBounds.left = column.cx;
    for (int index = 0; index < columnLabelCount; ++index) {
        HWND label = GetDlgItem(window, columnLabels[index]);
        RECT bounds = ControlRect(label, window);
        PlaceControl(label, margin.cx, bounds.top, client.right - 2 * margin.cx, bounds.bottom - bounds.top);
    }
    PlaceControl(browse, rightButton, browseBounds.top, button.cx, button.cy);
    PlaceControl(curlBrowse, rightButton, curlBrowseBounds.top, button.cx, button.cy);
    PlaceControl(curlPath, curlBounds.left, curlBounds.top, rightButton - gap.cx - curlBounds.left,
        curlBounds.bottom - curlBounds.top);
    PlaceControl(reset, rightButton, resetBounds.top, button.cx, button.cy);
    PlaceControl(reportBrowse, rightButton, reportBrowseBounds.top, button.cx, button.cy);
    PlaceControl(apply, rightButton, bottom, button.cx, button.cy);
    PlaceControl(cancel, rightButton - gap.cx - button.cx, bottom, button.cx, button.cy);
    PlaceControl(accept, rightButton - 2 * (gap.cx + button.cx), bottom, button.cx, button.cy);
    PlaceControl(clear, rightButton, clearBounds.top, button.cx, button.cy);
    SIZE numberWidth = DialogUnits(data.uiFont, 45, 0);
    PlaceControl(tabLength, column.cx, lengthBounds.top, numberWidth.cx,
        lengthBounds.bottom - lengthBounds.top);
    SendMessageW(tabSpin, UDM_SETBUDDY, reinterpret_cast<WPARAM>(tabLength), 0);
    PlaceControl(path, pathBounds.left, pathBounds.top, rightButton - gap.cx - pathBounds.left,
        pathBounds.bottom - pathBounds.top);
    int fontWidth = rightButton - gap.cx - fontBounds.left;
    RECT reportDrop = RECT{};
    RECT languageDrop = RECT{};
    SendMessageW(reportLanguage, CB_GETDROPPEDCONTROLRECT, 0, reinterpret_cast<LPARAM>(&reportDrop));
    SendMessageW(language, CB_GETDROPPEDCONTROLRECT, 0, reinterpret_cast<LPARAM>(&languageDrop));
    PlaceControl(reportLanguage, fontBounds.left, reportBounds.top, fontWidth,
        reportDrop.bottom - reportDrop.top);
    PlaceControl(language, fontBounds.left, languageBounds.top, fontWidth,
        languageDrop.bottom - languageDrop.top);
    PlaceControl(font, fontBounds.left, fontBounds.top, fontWidth, button.cy);
    const int wideLabels[] = { IDC_DLL_LABEL, IDC_CURL_LABEL, IDC_DLL_NOTE };
    for (int index = 0; index < 3; ++index) {
        HWND control = GetDlgItem(window, wideLabels[index]);
        RECT bounds = ControlRect(control, window);
        PlaceControl(control, margin.cx, bounds.top, client.right - 2 * margin.cx, bounds.bottom - bounds.top);
    }
    RECT dropped = RECT{};
    SendMessageW(antialiasing, CB_GETDROPPEDCONTROLRECT, 0, reinterpret_cast<LPARAM>(&dropped));
    PlaceControl(antialiasing, fontBounds.left, comboBounds.top, comboWidth, dropped.bottom - dropped.top);
    AlignControlBaseline(browse, path);
    AlignControlBaseline(curlBrowse, curlPath);
    AlignControlBaseline(GetDlgItem(window, IDC_LANGUAGE_LABEL), language);
    AlignControlBaseline(GetDlgItem(window, IDC_REPORT_LABEL), reportLanguage);
    AlignControlBaseline(reportBrowse, reportLanguage);
    UpdateComboBoxDropDown(language);
    UpdateComboBoxDropDown(reportLanguage);
    AlignControlBaseline(GetDlgItem(window, IDC_FONT_LABEL), font);
    AlignControlBaseline(reset, font);
    AlignControlBaseline(GetDlgItem(window, IDC_SMOOTHING_LABEL), antialiasing);
    UpdateComboBoxDropDown(antialiasing);
    AlignControlBaseline(cancel, accept);
    AlignControlBaseline(apply, accept);
    AlignControlBaseline(GetDlgItem(window, IDC_TAB_NAME_LABEL), tabLength);
    HWND recentLabel = GetDlgItem(window, IDC_RECENT_LABEL);
    RECT recentBounds = ControlRect(recentLabel, window);
    PlaceControl(recentLabel, margin.cx, recentBounds.top, rightButton - gap.cx - margin.cx,
        recentBounds.bottom - recentBounds.top);
    RECT checkBounds = ControlRect(multipleInstances, window);
    PlaceControl(multipleInstances, margin.cx, checkBounds.top, checkSize.cx, checkSize.cy);
    AlignControlBaseline(recentLabel, clear);
    LayoutPreferencesVertically(data, margin);
    OrderPreferencesLabels(window);
}

/// Applies the requested DPI-scaled width reduction once for the current window DPI.
static void ResizePreferencesWidth(PreferencesData& data) {
    int reduction = MulDiv(50, WindowDpi(data.window), 96);
    int difference = reduction - data.widthReduction;
    if (!difference) {
        return;
    }
    RECT bounds = RECT{};
    GetWindowRect(data.window, &bounds);
    SetWindowPos(data.window, nullptr, 0, 0, bounds.right - bounds.left - difference,
        bounds.bottom - bounds.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    data.widthReduction = reduction;
}

/// Lists supported antialiasing choices in order and preserves an available pending selection.
static void UpdateSmoothingChoices(PreferencesData& data) {
    HWND smoothing = GetDlgItem(data.window, IDC_SMOOTHING);
    const wchar_t* labels[] = { L"ClearType", L"GDI", T(TXT_ANTIALIASING_NONE) };
    const BYTE qualities[] = { 5, ANTIALIASED_QUALITY, NONANTIALIASED_QUALITY };
    BYTE quality = data.font.lfQuality ? data.font.lfQuality : DefaultReportFontQuality();
    bool clearType = IsClearTypeAvailable();
    SendMessageW(smoothing, CB_RESETCONTENT, 0, 0);
    for (int index = clearType ? 0 : 1; index < 3; ++index) {
        LRESULT item = SendMessageW(smoothing, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(labels[index]));
        if (item >= 0) {
            SendMessageW(smoothing, CB_SETITEMDATA, item, qualities[index]);
            if (qualities[index] == quality) {
                SendMessageW(smoothing, CB_SETCURSEL, item, 0);
            }
        }
    }
    if (SendMessageW(smoothing, CB_GETCURSEL, 0, 0) == CB_ERR) {
        SendMessageW(smoothing, CB_SETCURSEL, 0, 0);
        quality = static_cast<BYTE>(SendMessageW(smoothing, CB_GETITEMDATA, 0, 0));
    }
    data.font.lfQuality = quality;
}

/// Uses the template font initially or refreshes the system font, then recalculates Preferences geometry.
static void SetPreferencesFont(PreferencesData& data, bool updateUi) {
    HFONT font = updateUi
        ? CreateUiFont(data.window)
        : reinterpret_cast<HFONT>(SendMessageW(data.window, WM_GETFONT, 0, 0));
    if (!font) {
        return;
    }
    if (updateUi) {
        SendMessageW(data.window, WM_SETFONT, reinterpret_cast<WPARAM>(font), FALSE);
        for (HWND control = GetWindow(data.window, GW_CHILD);
                control;
                control = GetWindow(control, GW_HWNDNEXT)) {
            SendMessageW(control, WM_SETFONT, reinterpret_cast<WPARAM>(font), TRUE);
        }
    }
    if (data.ownsUiFont) {
        DeleteObject(data.uiFont);
    }
    data.uiFont = font;
    data.ownsUiFont = updateUi;
    ResizePreferencesWidth(data);
    LayoutPreferences(data);
}

/// Describes the pending report font and disables Default when the default font is already selected.
static void UpdateFontButtons(PreferencesData& data) {
    bool custom = data.font.lfFaceName[0] != 0;
    LOGFONTW description = data.font;
    UINT dpi = data.dpi;
    if (!custom) {
        HFONT font = CreateReportFont(data.window, &data.font, data.dpi);
        if (font) {
            GetObjectW(font, sizeof(description), &description);
            DeleteObject(font);
        }
        dpi = WindowDpi(data.window);
    }
    int height = description.lfHeight < 0 ? -description.lfHeight : description.lfHeight;
    int points = MulDiv(height, 72, dpi ? dpi : 96);
    const wchar_t* style;
    if (description.lfWeight >= FW_BOLD) {
        if (description.lfItalic) {
            style = T(TXT_FONT_BOLD_ITALIC);
        } else {
            style = T(TXT_FONT_BOLD);
        }
    } else if (description.lfItalic) {
        style = T(TXT_FONT_ITALIC);
    } else {
        style = T(TXT_FONT_REGULAR);
    }
    wchar_t text[LF_FACESIZE + 48];
    wchar_t caption[2 * (LF_FACESIZE + 48)];
    wsprintfW(text, L"%s, %d, %s\u2026", description.lfFaceName, points, style);
    int output = 0;
    for (int index = 0; text[index]; ++index) {
        caption[output++] = text[index];
        if (text[index] == L'&') {
            caption[output++] = L'&';
        }
    }
    caption[output] = 0;
    SetDlgItemTextW(data.window, IDC_FONT_CHOOSE, caption);
    EnablePreferencesControl(data.window, IDC_FONT_DEFAULT, custom);
}

/// Copies a native font-dialog selection into pending report-font settings.
static void ChoosePreferencesFont(PreferencesData& data) {
    HFONT current = CreateReportFont(data.window, &data.font, data.dpi);
    if (!current) {
        return;
    }
    LOGFONTW font = LOGFONTW{};
    GetObjectW(current, sizeof(font), &font);
    DeleteObject(current);
    CHOOSEFONTW dialog = CHOOSEFONTW{};
    dialog.lStructSize = sizeof(dialog);
    dialog.hwndOwner = data.window;
    dialog.lpLogFont = &font;
    dialog.Flags = CF_SCREENFONTS | CF_INITTOLOGFONTSTRUCT;
    if (ChooseFontW(&dialog)) {
        font.lfQuality = data.font.lfQuality;
        data.font = font;
        data.dpi = WindowDpi(data.window);
        UpdateFontButtons(data);
    }
}

/// Validates and commits pending settings, refreshes the live viewer and retains successful Apply changes.
static bool ApplyPreferences(PreferencesData& data) {
    if (PreferencesBusy(data)) {
        return false;
    }
    BOOL valid = FALSE;
    UINT tabLength = GetDlgItemInt(data.window, IDC_TAB_NAME_LENGTH, &valid, FALSE);
    if (!valid || tabLength < minimumTabNameLength || tabLength > maximumTabNameLength) {
        MessageBoxW(data.window, T(TXT_TAB_NAME_LENGTH_INVALID), L"MediaInfo", MB_OK | MB_ICONERROR);
        return false;
    }
    wchar_t path[MAX_PATH];
    wchar_t curlPath[MAX_PATH];
    GetDlgItemTextW(data.window, IDC_DLL_PATH, path, MAX_PATH);
    GetDlgItemTextW(data.window, IDC_CURL_PATH, curlPath, MAX_PATH);
    const wchar_t* paths[] = { path, curlPath };
    const int controls[] = { IDC_DLL_PATH, IDC_CURL_PATH };
    for (int index = 0; index < static_cast<int>(ARRAYSIZE(paths)); ++index) {
        if (paths[index][0]) {
            DWORD attributes = GetFileAttributesW(paths[index]);
            if (attributes == INVALID_FILE_ATTRIBUTES || attributes & FILE_ATTRIBUTE_DIRECTORY) {
                wchar_t message[512];
                wsprintfW(message, T(TXT_FILE_OPEN_FAILED), paths[index]);
                MessageBoxW(data.window, message, L"MediaInfo", MB_OK | MB_ICONERROR);
                SetFocus(GetDlgItem(data.window, controls[index]));
                return false;
            }
        }
    }
    if (!PreferencesChanged(data) && data.library->IsLoaded()) {
        return true;
    }
    bool reportChanged = lstrcmpiW(data.reportLanguage, data.originalReportLanguage) != 0;
    SetApplicationLanguage(data.language);
    bool reloadLibrary = lstrcmpiW(path, data.originalPath)
        || lstrcmpiW(curlPath, data.originalCurlPath)
        || reportChanged
        || data.language != data.originalLanguage
        || !data.library->IsLoaded();
    if (reloadLibrary) {
        HCURSOR previous = SetCursor(LoadCursorW(nullptr, IDC_WAIT));
        if (data.callbacks && data.callbacks->loading) {
            data.callbacks->loading(data.callbacks->context, true);
        }
        bool loaded = path[0]
            ? data.library->Load(path, curlPath, data.reportLanguage)
            : data.library->Discover(curlPath, data.reportLanguage);
        SetCursor(previous ? previous : LoadCursorW(nullptr, IDC_ARROW));
        if (!loaded) {
            SetApplicationLanguage(data.originalLanguage);
        }
        if (data.callbacks && data.callbacks->loading) {
            data.callbacks->loading(data.callbacks->context, false);
        }
        if (!loaded) {
            MessageBoxW(data.window, data.library->GetError(), L"MediaInfo", MB_OK | MB_ICONERROR);
            return false;
        }
    }
    bool saved = SaveLibrarySetting(path);
    saved = SaveCurlSetting(curlPath) && saved;
    saved = SaveApplicationLanguageSetting(data.language) && saved;
    saved = SaveReportLanguageSetting(data.reportLanguage) && saved;
    saved = SaveFontSetting(data.font, data.dpi) && saved;
    saved = SaveTabNameLengthSetting(tabLength) && saved;
    bool multipleInstances = IsDlgButtonChecked(data.window, IDC_MULTIPLE_INSTANCES) == BST_CHECKED;
    saved = SaveMultipleInstancesSetting(multipleInstances) && saved;
    PreferencesChanges changes = PreferencesChanges{ reloadLibrary, tabLength };
    *data.appliedFont = data.font;
    *data.appliedDpi = data.dpi;
    lstrcpyW(data.originalPath, path);
    lstrcpyW(data.originalCurlPath, curlPath);
    lstrcpyW(data.originalReportLanguage, data.reportLanguage);
    data.originalLanguage = data.language;
    data.originalTabNameLength = tabLength;
    data.originalMultipleInstances = multipleInstances;
    data.applied = true;
    data.reportLanguageChanged = data.reportLanguageChanged || reportChanged;
    SetPreferencesLabels(data);
    UpdateSmoothingChoices(data);
    UpdateFontButtons(data);
    LayoutPreferences(data);
    if (data.callbacks && data.callbacks->applied) {
        data.callbacks->applied(data.callbacks->context, changes);
    }
    UpdateApplyButton(data);
    if (!saved) {
        MessageBoxW(data.window, T(TXT_PREFERENCES_SAVE_FAILED), L"MediaInfo", MB_OK | MB_ICONWARNING);
    }
    return true;
}

/// Handles modal Preferences input while keeping edits pending until OK or Apply.
static INT_PTR CALLBACK PreferencesProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    PreferencesData* data = reinterpret_cast<PreferencesData*>(GetWindowLongPtrW(window, DWLP_USER));
    if (message == WM_INITDIALOG) {
        data = reinterpret_cast<PreferencesData*>(lParam);
        data->window = window;
        SetWindowLongPtrW(window, DWLP_USER, reinterpret_cast<LONG_PTR>(data));
        RECT buttonBounds = ControlRect(GetDlgItem(window, IDOK), window);
        data->buttonSize = SIZE{
            buttonBounds.right - buttonBounds.left,
            buttonBounds.bottom - buttonBounds.top
        };
        LoadLibrarySetting(data->originalPath, MAX_PATH);
        LoadCurlSetting(data->originalCurlPath, MAX_PATH);
        SetDlgItemTextW(window, IDC_CURL_PATH, data->originalCurlPath);
        SendDlgItemMessageW(window, IDC_CURL_PATH, EM_SETLIMITTEXT, MAX_PATH - 1, 0);
        SetDlgItemTextW(window, IDC_DLL_PATH, data->originalPath);
        SendDlgItemMessageW(window, IDC_DLL_PATH, EM_SETLIMITTEXT, MAX_PATH - 1, 0);
        if (!InstallSelectionEditHandler(GetDlgItem(window, IDC_DLL_PATH))
                || !InstallSelectionEditHandler(GetDlgItem(window, IDC_CURL_PATH))
                || !InstallSelectionEditHandler(GetDlgItem(window, IDC_TAB_NAME_LENGTH))) {
            EndDialog(window, -1);
            return TRUE;
        }
        LoadReportLanguageSetting(data->originalReportLanguage, MAX_PATH);
        lstrcpyW(data->reportLanguage, data->originalReportLanguage);
        SetDlgItemInt(window, IDC_TAB_NAME_LENGTH, data->originalTabNameLength, FALSE);
        SendDlgItemMessageW(window, IDC_TAB_NAME_LENGTH, EM_SETLIMITTEXT, 3, 0);
        SendDlgItemMessageW(window, IDC_TAB_NAME_SPIN, UDM_SETBUDDY,
            reinterpret_cast<WPARAM>(GetDlgItem(window, IDC_TAB_NAME_LENGTH)), 0);
        SendDlgItemMessageW(window, IDC_TAB_NAME_SPIN, UDM_SETRANGE, 0,
            MAKELPARAM(maximumTabNameLength, minimumTabNameLength));
        SendDlgItemMessageW(window, IDC_TAB_NAME_SPIN, UDM_SETPOS, 0,
            MAKELPARAM(data->originalTabNameLength, 0));
        data->originalMultipleInstances = LoadMultipleInstancesSetting();
        CheckDlgButton(window, IDC_MULTIPLE_INSTANCES,
            data->originalMultipleInstances ? BST_CHECKED : BST_UNCHECKED);
        PopulateLanguages(*data);
        SetPreferencesLabels(*data);
        UpdateSmoothingChoices(*data);
        SetPreferencesFont(*data, false);
        UpdateFontButtons(*data);
        if (!InstallPreferencesControlHandlers(window)) {
            EndDialog(window, -1);
            return TRUE;
        }
        data->applyPending = false;
        UpdateApplyButton(*data);
        SetTimer(window, preferencesTimer, 100, nullptr);
        return TRUE;
    }
    if (!data) {
        return FALSE;
    }
    if (message == WM_VSCROLL && !lParam && ScrollPreferences(*data, LOWORD(wParam))) {
        return TRUE;
    }
    if (message == WM_MOUSEWHEEL && data->contentHeight) {
        data->wheelRemainder += static_cast<short>(HIWORD(wParam));
        int steps = data->wheelRemainder / WHEEL_DELTA;
        data->wheelRemainder %= WHEEL_DELTA;
        int count = steps > 0 ? steps : -steps;
        for (int index = 0; index < count * 3; ++index) {
            ScrollPreferences(*data, steps > 0 ? SB_LINEUP : SB_LINEDOWN);
        }
        return TRUE;
    }
    if (message == WM_DRAWITEM && wParam == IDC_DLL_NOTE) {
        return DrawWrappedTextItem(reinterpret_cast<const DRAWITEMSTRUCT*>(lParam));
    }
    if (message == WM_TIMER && wParam == preferencesTimer) {
        UpdateApplyButton(*data);
        return TRUE;
    }
    if (message == WM_SETTINGCHANGE || message == WM_THEMECHANGED || message == WM_DPICHANGED ||
            message == WM_DISPLAYCHANGE) {
        UpdateSmoothingChoices(*data);
        SetPreferencesFont(*data, true);
        UpdateFontButtons(*data);
        UpdateApplyButton(*data);
        return TRUE;
    }
    if (message == WM_COMMAND) {
        switch (LOWORD(wParam)) {
            case IDC_MULTIPLE_INSTANCES:
                UpdateApplyButton(*data);
                return TRUE;
            case IDC_DLL_PATH:
            case IDC_CURL_PATH:
            case IDC_TAB_NAME_LENGTH:
                if (HIWORD(wParam) == EN_CHANGE) {
                    UpdateApplyButton(*data);
                }
                return TRUE;
            case IDC_RECENT_CLEAR:
                if (PreferencesHasRecentFiles(*data)) {
                    bool saved = data->callbacks && data->callbacks->clearRecentFiles
                        ? data->callbacks->clearRecentFiles(data->callbacks->context)
                        : SaveRecentFilesSetting(L"\0", 2);
                    UpdateApplyButton(*data);
                    if (!saved) {
                        MessageBoxW(window, T(TXT_RECENT_FILES_SAVE_FAILED), L"MediaInfo",
                            MB_OK | MB_ICONWARNING);
                    }
                }
                return TRUE;
            case IDC_DLL_BROWSE:
            case IDC_CURL_BROWSE:
            {
                bool curl = LOWORD(wParam) == IDC_CURL_BROWSE;
                int control = curl ? IDC_CURL_PATH : IDC_DLL_PATH;
                wchar_t path[MAX_PATH];
                GetDlgItemTextW(window, control, path, MAX_PATH);
                if (ChooseLibraryFile(window, path, curl)) {
                    SetDlgItemTextW(window, control, path);
                }
                return TRUE;
            }
            case IDC_LANGUAGE:
            {
                HWND combo = GetDlgItem(window, IDC_LANGUAGE);
                if (HIWORD(wParam) == CBN_DROPDOWN) {
                    UpdateComboBoxDropDown(combo);
                } else if (HIWORD(wParam) == CBN_SELCHANGE) {
                    LRESULT item = SendMessageW(combo, CB_GETCURSEL, 0, 0);
                    int language = static_cast<int>(SendMessageW(combo, CB_GETITEMDATA, item, 0));
                    if (language >= 0 && language < applicationLanguageCount) {
                        data->language = language;
                        UpdateApplyButton(*data);
                    }
                }
                return TRUE;
            }
            case IDC_REPORT_LANGUAGE:
            {
                HWND combo = GetDlgItem(window, IDC_REPORT_LANGUAGE);
                if (HIWORD(wParam) == CBN_DROPDOWN) {
                    UpdateComboBoxDropDown(combo);
                } else if (HIWORD(wParam) == CBN_SELCHANGE) {
                    LRESULT item = SendMessageW(combo, CB_GETCURSEL, 0, 0);
                    int index = static_cast<int>(SendMessageW(combo, CB_GETITEMDATA, item, 0));
                    if (index >= 0) {
                        lstrcpynW(data->reportLanguage, ReportLanguageCode(index), MAX_PATH);
                        UpdateApplyButton(*data);
                    }
                }
                return TRUE;
            }
            case IDC_REPORT_BROWSE:
            {
                wchar_t path[MAX_PATH] = L"";
                if (ReportLanguageIndex(data->reportLanguage) < 0) {
                    lstrcpyW(path, data->reportLanguage);
                }
                if (ChooseReportLanguageFile(window, path)) {
                    lstrcpyW(data->reportLanguage, path);
                    UpdateReportChoices(*data);
                    UpdateApplyButton(*data);
                }
                return TRUE;
            }
            case IDC_FONT_CHOOSE:
                ChoosePreferencesFont(*data);
                UpdateApplyButton(*data);
                return TRUE;
            case IDC_SMOOTHING:
                if (HIWORD(wParam) == CBN_DROPDOWN) {
                    UpdateComboBoxDropDown(GetDlgItem(window, IDC_SMOOTHING));
                } else if (HIWORD(wParam) == CBN_SELCHANGE) {
                    HWND combo = GetDlgItem(window, IDC_SMOOTHING);
                    LRESULT index = SendMessageW(combo, CB_GETCURSEL, 0, 0);
                    data->font.lfQuality = static_cast<BYTE>(SendMessageW(combo, CB_GETITEMDATA, index, 0));
                    UpdateApplyButton(*data);
                }
                return TRUE;
            case IDC_FONT_DEFAULT:
            {
                BYTE quality = data->font.lfQuality;
                data->font = LOGFONTW{};
                data->font.lfQuality = quality;
                data->dpi = 96;
                UpdateFontButtons(*data);
                UpdateApplyButton(*data);
                return TRUE;
            }
            case IDOK:
            case IDC_PREFERENCES_APPLY:
                if (ApplyPreferences(*data)) {
                    if (LOWORD(wParam) == IDOK) {
                        EndDialog(window, IDOK);
                    } else {
                        data->applyPending = false;
                        UpdateApplyButton(*data);
                    }
                }
                return TRUE;
            case IDCANCEL:
                EndDialog(window, IDCANCEL);
                return TRUE;
        }
    }
    return FALSE;
}

/// Shows modal Preferences and returns committed font and report-language changes to the caller.
bool ShowPreferences(HWND owner, MediaInfoLibrary& library, LOGFONTW* font, UINT* dpi,
        bool* reportLanguageChanged, const PreferencesCallbacks* callbacks) {
    PreferencesData data = PreferencesData{};
    data.library = &library;
    data.appliedFont = font;
    data.appliedDpi = dpi;
    data.callbacks = callbacks;
    data.font = *font;
    data.dpi = *dpi;
    data.originalLanguage = GetApplicationLanguage();
    data.language = data.originalLanguage;
    data.originalTabNameLength = LoadTabNameLengthSetting();
    HINSTANCE instance = GetModuleHandleW(nullptr);
    DLGTEMPLATE* definition = LoadSystemDialogTemplate(instance, IDD_PREFERENCES, owner);
    if (!definition) {
        return false;
    }
    INT_PTR result = DialogBoxIndirectParamW(instance, definition, owner, PreferencesProc,
        reinterpret_cast<LPARAM>(&data));
    HeapFree(GetProcessHeap(), 0, definition);
    if (data.ownsUiFont) {
        DeleteObject(data.uiFont);
    }
    if (result != IDOK && !data.applied) {
        SetApplicationLanguage(data.originalLanguage);
        return false;
    }
    if (reportLanguageChanged) {
        *reportLanguageChanged = data.reportLanguageChanged;
    }
    return true;
}

/// Passes absolute Unicode file paths to the existing viewer, or reactivates it for an empty launch.
bool ForwardInstanceFiles(HWND target, int count, wchar_t** arguments) {
    SIZE_T capacity = static_cast<SIZE_T>(count > 0 ? count : 1) * MAX_PATH + 2;
    wchar_t* paths =
        static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, capacity * sizeof(wchar_t)));
    if (!paths) {
        return false;
    }
    DWORD length = 0;
    for (int index = 1; index < count; ++index) {
        DWORD written = GetFullPathNameW(arguments[index], MAX_PATH, paths + length, nullptr);
        if (!written || written >= MAX_PATH) {
            HeapFree(GetProcessHeap(), 0, paths);
            return false;
        }
        length += written + 1;
    }
    COPYDATASTRUCT request = COPYDATASTRUCT{};
    request.dwData = instanceFileRequest;
    request.cbData = (length ? length + 1 : 2) * sizeof(wchar_t);
    request.lpData = paths;
    DWORD_PTR accepted = 0;
    bool sent = SendMessageTimeoutW(target, WM_COPYDATA, 0, reinterpret_cast<LPARAM>(&request),
        SMTO_ABORTIFHUNG | SMTO_BLOCK, 10000, &accepted) != 0;
    HeapFree(GetProcessHeap(), 0, paths);
    if (sent && accepted) {
        SetForegroundWindow(target);
        return true;
    }
    return false;
}

/// Validates the complete bounded Unicode file list before the viewer reads any supplied path.
bool ValidateInstanceFiles(const COPYDATASTRUCT* request) {
    if (!request
            || request->dwData != instanceFileRequest
            || !request->lpData
            || request->cbData < 2 * sizeof(wchar_t)
            || request->cbData % sizeof(wchar_t)) {
        return false;
    }
    const wchar_t* paths = static_cast<const wchar_t*>(request->lpData);
    DWORD length = request->cbData / sizeof(wchar_t);
    if (paths[length - 1] || paths[length - 2]) {
        return false;
    }
    DWORD position = 0;
    while (position < length - 1 && paths[position]) {
        DWORD start = position;
        while (position < length && paths[position]) {
            ++position;
        }
        if (position - start >= MAX_PATH) {
            return false;
        }
        ++position;
    }
    return position == length - 1 || length == 2 && !paths[0];
}

/// Starts the viewer or forwards a restricted launch while serializing simultaneous startup attempts.
int RunViewer(int count, wchar_t** arguments) {
    SetCursor(LoadCursorW(nullptr, IDC_APPSTARTING));
    HANDLE startupMutex = CreateMutexA(nullptr, FALSE, startupMutexName);
    DWORD lock = startupMutex ? WaitForSingleObject(startupMutex, INFINITE) : WAIT_FAILED;
    if (lock != WAIT_OBJECT_0 && lock != WAIT_ABANDONED) {
        if (startupMutex) {
            CloseHandle(startupMutex);
        }
        SetCursor(LoadCursorW(nullptr, IDC_ARROW));
        MessageBoxW(nullptr, T(TXT_VIEWER_CREATE_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
        return 1;
    }
    HWND existing = !LoadMultipleInstancesSetting() ? FindWindowW(viewerWindowClass, nullptr) : nullptr;
    MainForm app;
    bool success = existing ? ForwardInstanceFiles(existing, count, arguments) : app.Create();
    if (!success || existing) {
        SetCursor(LoadCursorW(nullptr, IDC_ARROW));
        ReleaseMutex(startupMutex);
        CloseHandle(startupMutex);
        startupMutex = nullptr;
    }
    if (success && !existing) {
        app.Show();
    }
    if (!success) {
        MessageBoxW(nullptr, T(existing ? TXT_INSTANCE_FORWARD_FAILED : TXT_VIEWER_CREATE_FAILED),
            L"MediaInfo", MB_OK | MB_ICONERROR);
        return 1;
    }
    if (existing) {
        return 0;
    }
    for (int index = 1; index < count; ++index) {
        app.AddFile(arguments[index]);
    }
    MSG message = MSG{};
    BOOL received = 0;
    while ((received = GetMessageW(&message, nullptr, 0, 0)) > 0) {
        if (!app.Translate(&message)) {
            TranslateMessage(&message);
            DispatchMessageW(&message);
        }
        if (startupMutex && !app.IsLoadingLibrary()) {
            ReleaseMutex(startupMutex);
            CloseHandle(startupMutex);
            startupMutex = nullptr;
        }
    }
    if (startupMutex) {
        ReleaseMutex(startupMutex);
        CloseHandle(startupMutex);
    }
    return received < 0 ? 1 : static_cast<int>(message.wParam);
}

/// Runs worker mode when requested or initializes the native viewer without the C runtime.
extern "C" void WINAPI Start() {
    InitializeApplicationLanguage();
    int result = 0;
    int count = 0;
    wchar_t** arguments = CommandLineToArgvW(GetCommandLineW(), &count);
    if (!arguments || !DispatchLibraryWorker(count, arguments, &result)) {
        result = RunViewer(arguments ? count : 0, arguments);
    }
    if (arguments) {
        LocalFree(arguments);
    }
    ExitProcess(result);
}
