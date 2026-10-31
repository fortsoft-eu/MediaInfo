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

class MediaInfoLibrary;
struct PrintJob;
struct PreferencesCallbacks;

/// Supported interface locales in the same order as the language selection list.
enum AppLanguage {
    LANG_CS,
    LANG_EN_US,
    LANG_EN_GB,
    LANG_EN_AU,
    LANG_DE,
    LANG_FR,
    LANG_ES,
    LANG_IT,
    LANG_PT,
    LANG_PL,
    LANG_SK,
    LANG_DA,
    LANG_FI,
    LANG_IS,
    LANG_NB,
    LANG_SV,
    LANG_TR,
    LANG_ET,
    LANG_GA,
    LANG_LT,
    LANG_LV,
    LANG_HU,
    LANG_MT,
    LANG_NL,
    LANG_RO,
    LANG_EL,
    LANG_BS,
    LANG_HR,
    LANG_SL,
    LANG_CNR,
    LANG_BE,
    LANG_BG,
    LANG_MK,
    LANG_SR,
    LANG_UK,
    LANG_RU,
    LANG_COUNT
};

/// Stable identifiers for interface captions, diagnostics and Help text.
enum TextId {
    TXT_LANGUAGE_NAME,
    TXT_ABOUT_WEBSITE_APPEND,
    TXT_FILE_OPEN_FAILED,
    TXT_BROWSE_DLL,
    TXT_BROWSE_REPORT,
    TXT_CLOSE,
    TXT_CLOSE_TAB,
    TXT_FONT_DEFAULT,
    TXT_EXPORT,
    TXT_FILE_MENU,
    TXT_REPORT_FONT,
    TXT_HELP_MENU,
    TXT_HELP,
    TXT_LANGUAGE,
    TXT_OPEN_WEBSITE,
    TXT_OPEN,
    TXT_SETTINGS_MENU,
    TXT_PREFERENCES_MENU,
    TXT_ABOUT,
    TXT_ABOUT_TITLE,
    TXT_ALL_FILES,
    TXT_FONT_BOLD,
    TXT_FONT_BOLD_ITALIC,
    TXT_BROWSE_CURL,
    TXT_CANCEL,
    TXT_MEDIALIB_LOAD_FAILED,
    TXT_CURL_LOAD_FAILED,
    TXT_CLOSE_ALL,
    TXT_GIF_FORMAT,
    TXT_COPY_URL,
    TXT_COPY_INFORMATION,
    TXT_DLL_FILES,
    TXT_EXIT,
    TXT_EMBEDDED_MEDIALIB,
    TXT_EMBEDDED_CURL,
    TXT_EXPORT_TITLE,
    TXT_FONT_ANTIALIASING,
    TXT_GIF_EXPORT_FAILED,
    TXT_FONT_ITALIC,
    TXT_JPEG_FORMAT,
    TXT_JPEG_EXPORT_FAILED,
    TXT_LICENSE_UNAVAILABLE,
    TXT_MEDIA_FILES,
    TXT_APPLICATION_DESCRIPTION,
    TXT_HELP_TITLE,
    TXT_MEDIA_FILE_HANDLE_FAILED,
    TXT_MEDIA_FILE_UNRECOGNIZED,
    TXT_CSV_FORMAT,
    TXT_MEDIALIB_TITLE,
    TXT_MEDIALIB_PATH,
    TXT_MEDIALIB_REQUIRED,
    TXT_MEDIALIB_NOT_LOADED,
    TXT_NO_COMPATIBLE_MEDIALIB,
    TXT_ANTIALIASING_NONE,
    TXT_OK,
    TXT_OPEN_TITLE,
    TXT_PLATFORM,
    TXT_PNG_FORMAT,
    TXT_PREFERENCES_TITLE,
    TXT_READY,
    TXT_FONT_REGULAR,
    TXT_REPORT_LANGUAGE,
    TXT_REPORT_LANGUAGE_TABLES,
    TXT_SELECT_MEDIALIB,
    TXT_SELECT_REPORT_LANGUAGE,
    TXT_INVALID_MEDIA_PATH,
    TXT_SELECTED_PATHS_TOO_LONG,
    TXT_SELECT_CURL,
    TXT_TIFF_FORMAT,
    TXT_TEXT_FORMAT,
    TXT_BMP_EXPORT_FAILED,
    TXT_LIBRARY_WORKER_START_FAILED,
    TXT_REPORT_COPY_FAILED,
    TXT_VIEWER_CREATE_FAILED,
    TXT_MEDIALIB_PATH_INVALID,
    TXT_PNG_EXPORT_FAILED,
    TXT_TIFF_EXPORT_FAILED,
    TXT_COPY_URL_FAILED,
    TXT_LIBRARY_REQUIRES_X86,
    TXT_LIBRARY_EXTRACTION_FAILED,
    TXT_LIBRARY_DECOMPRESSION_FAILED,
    TXT_LIBRARY_RESOURCE_INVALID,
    TXT_REPORT_IMAGE_TOO_LARGE,
    TXT_CURL_FILENAME_INVALID,
    TXT_FILE_DIALOG_OPEN_FAILED,
    TXT_FILE_DIALOG_SELECTION_FAILED,
    TXT_RECENT_FILE_MISSING,
    TXT_RECENT_FILE_UNAVAILABLE,
    TXT_COPY_INFORMATION_FAILED,
    TXT_CURL_PATH_INVALID,
    TXT_MEDIALIB_VERSION_MISSING,
    TXT_CURL_EXPORTS_MISSING,
    TXT_MEDIALIB_EXPORTS_MISSING,
    TXT_LIBRARY_WORKER_FAILED,
    TXT_LIBRARY_WORKER_TIMEOUT,
    TXT_PREFERENCES_SAVE_FAILED,
    TXT_REPORT_START_FAILED,
    TXT_REPORT_IMAGE_CREATE_FAILED,
    TXT_REPORT_LANGUAGE_LOAD_FAILED,
    TXT_REPORT_THREAD_START_FAILED,
    TXT_REPORT_LANGUAGE_REJECTED,
    TXT_INVALID_WINDOWS_DLL,
    TXT_IMAGE_FORMAT_UNSUPPORTED,
    TXT_TEXT_EXPORT_FAILED,
    TXT_WEBSITE_OPEN_FAILED,
    TXT_TOO_MANY_FILES,
    TXT_LIBRARY_PATH_HINT,
    TXT_VERSION,
    TXT_WEBSITE_TOOLTIP,
    TXT_WAITING_FOR_REPORT,
    TXT_WEBSITE_LABEL,
    TXT_BMP_FORMAT,
    TXT_REPORT_COPY_OPERATION,
    TXT_CURL_LIBRARY,
    TXT_CURL_PATH,
    TXT_MEDIALIB_LOAD_OPERATION,
    TXT_CURL_LOAD_OPERATION,
    TXT_MEDIALIB_UNLOAD_OPERATION,
    TXT_APPLY,
    TXT_TAB_NAME_LENGTH,
    TXT_RECENT_FILES,
    TXT_CLEAR_RECENT_FILES,
    TXT_TAB_NAME_LENGTH_INVALID,
    TXT_RECENT_FILES_SAVE_FAILED,
    TXT_ALLOW_MULTIPLE_INSTANCES,
    TXT_INSTANCE_FORWARD_FAILED,
    TXT_LOADING,
    TXT_LOADING_FILE,
    TXT_APPLICATION_HELP,
    TXT_WEBP_FORMAT,
    TXT_WEBP_EXPORT_FAILED,
    TXT_TEXT_UTF8_FORMAT,
    TXT_TEXT_UTF8_BOM_FORMAT,
    TXT_TEXT_UTF16_BE_FORMAT,
    TXT_TEXT_UTF16_LE_FORMAT,
    TXT_TEXT_ENCODING_FAILED,
    TXT_OPEN_FOLDER,
    TXT_OPEN_FOLDER_TITLE,
    TXT_FOLDER_READ_FAILED,
    TXT_ADVANCED_MODE,
    TXT_REPORT_DETAIL_REJECTED,
    TXT_KNOWN_FORMATS,
    TXT_KNOWN_CODECS,
    TXT_KNOWN_PARAMETERS,
    TXT_KNOWN_FORMATS_TITLE,
    TXT_KNOWN_CODECS_TITLE,
    TXT_KNOWN_PARAMETERS_TITLE,
    TXT_KNOWN_INFO_FAILED,
    TXT_FULL_PARSING,
    TXT_PARSING_REJECTED,
    TXT_TRACE_LEVEL_0,
    TXT_TRACE_LEVEL_5,
    TXT_TRACE_LEVEL_9,
    TXT_TRACE_LEVEL_10,
    TXT_PRINT,
    TXT_PRINTING,
    TXT_PRINT_FAILED,
    TXT_TOOLS_MENU,
    TXT_CREATE_HEADER,
    TXT_CREATE_HEADER_OPEN_TITLE,
    TXT_CREATE_HEADER_SAVE_TITLE,
    TXT_HEADER_FORMAT,
    TXT_HEADER_READ_FAILED,
    TXT_HEADER_SAVE_FAILED,
    TXT_COPY,
    TXT_COPY_FILE_NAME,
    TXT_COPY_FULL_PATH,
    TXT_OPEN_FILE,
    TXT_OPEN_CONTAINING_FOLDER,
    TXT_COUNT
};

/// Localized caption identifier and native wildcard pattern for a file-dialog filter.
struct LocalizedFileFilter {
    TextId text;
    const wchar_t* pattern;
};

/// Native file-dialog filter templates localized before opening a dialog.
extern const LocalizedFileFilter mediaFilters[];
extern const LocalizedFileFilter libraryFilters[];
extern const LocalizedFileFilter curlFilters[];
extern const LocalizedFileFilter reportLanguageFilters[];
extern const LocalizedFileFilter headerInputFilters[];
extern const LocalizedFileFilter headerOutputFilters[];

/// Number of interface locales used by settings validation and language lists.
static const int applicationLanguageCount = LANG_COUNT;

/// Main-window identity and the signature used to recognize cross-instance file requests.
extern const wchar_t viewerWindowClass[];
static const ULONG_PTR instanceFileRequest = 0x4D494E46;

/// Passes absolute Unicode file paths to the existing viewer, or reactivates it for an empty launch.
bool ForwardInstanceFiles(HWND target, int count, wchar_t** arguments);

/// Validates the complete bounded Unicode file list before the viewer reads any supplied path.
bool ValidateInstanceFiles(const COPYDATASTRUCT* request);

/// Starts the viewer or forwards a restricted launch while serializing simultaneous startup attempts.
int RunViewer(int count, wchar_t** arguments);

/// Shows modal Preferences and returns committed font and report-language changes to the caller.
bool ShowPreferences(HWND owner, MediaInfoLibrary& library, LOGFONTW* font, UINT* dpi,
    bool* reportLanguageChanged = nullptr, const PreferencesCallbacks* callbacks = nullptr);

/// Chooses media paths with a modern native dialog when available and the legacy dialog otherwise.
wchar_t* ChooseMediaFiles(HWND owner);

/// Chooses a filesystem folder with the available native Shell dialog.
bool ChooseMediaFolder(HWND owner, wchar_t* path);

/// Chooses an x86 MediaInfo or curl DLL path using the corresponding localized file filters.
bool ChooseLibraryFile(HWND owner, wchar_t* path, bool curl = false);

/// Chooses a custom MediaInfo translation table using the CSV file filter.
bool ChooseReportLanguageFile(HWND owner, wchar_t* path);

/// Chooses an export destination and an available output format with matching native Save dialogs.
bool ChooseExportFile(HWND owner, wchar_t* path, const wchar_t* title, DWORD* type);

/// Chooses an input and saves its first 512 KiB, remembering only the tool's session opening folder.
void CreateHeaderFile(HWND owner, wchar_t* folder);

/// Captures report text and font and opens the native system printer-selection dialog.
PrintJob* ChooseReportPrinter(HWND owner, HWND edit, const wchar_t* report, const wchar_t* title,
    wchar_t* error, int errorCapacity);

/// Prints the complete snapshot with page breaks and printer-scaled report font.
bool PrintReportPages(PrintJob* job);

/// Releases a print snapshot and its selected printer device context.
void FreePrintJob(PrintJob* job);

/// Reports whether the requested image format can be written without substituting another format.
bool IsReportImageTypeAvailable(DWORD type);

/// Renders the entire report in its selected font and saves it with the requested available encoder.
bool SaveReportImage(HWND edit, const wchar_t* report, const wchar_t* path, DWORD type, wchar_t* error,
    int errorCapacity);

/// Saves the report in the selected text encoding, replacing the destination only after a complete write.
bool SaveReportText(const wchar_t* report, const wchar_t* path, DWORD type, wchar_t* error, int errorCapacity);

/// Reads the window DPI dynamically, retaining device-context metrics on older Windows.
UINT WindowDpi(HWND window);

/// Reports whether visual styles are active for Windows and the current application.
bool AreVisualStylesActive();

/// Checks the system antialiasing capability and display depth before exposing ClearType.
bool IsClearTypeAvailable();

/// Chooses ClearType when supported and ordinary GDI antialiasing otherwise.
BYTE DefaultReportFontQuality();

/// Creates the current system message font at the window DPI.
HFONT CreateUiFont(HWND window);

/// Creates the About license font using Consolas with Courier New as its availability fallback.
HFONT CreateAboutFont(HWND window);

/// Loads the small or large application icon at the native system icon dimensions.
HICON LoadApplicationIcon(bool small);

/// Creates the chosen report font or default Consolas/Courier New at the current window DPI.
HFONT CreateReportFont(HWND window, const LOGFONTW* saved, UINT savedDpi);

/// Converts dialog units using the supplied font metrics rather than fixed pixel assumptions.
SIZE DialogUnits(HFONT font, int x, int y);

/// Expands a native button only as needed for its current localized text and native padding.
SIZE PreferredButtonSize(HWND button, const SIZE& minimum);

/// Maps a control window rectangle into the requested parent coordinate system.
RECT ControlRect(HWND window, HWND parent);

/// Positions and sizes a control without activation, retaining a positive client size.
void PlaceControl(HWND window, int x, int y, int width, int height);

/// Calculates the rendered text baseline from the native control content rectangle and current font.
LONG ControlTextBaseline(HWND control);

/// Moves one control so its rendered text baseline matches another control.
void AlignControlBaseline(HWND control, HWND reference);

/// Adapts only Preferences edit height and left text margin using current font, theme and native borders.
void UpdateEditMetrics(HWND edit);

/// Reads text metrics with the font currently assigned to a native control.
bool ReadControlMetrics(HWND control, TEXTMETRICW* metrics);

/// Copies Unicode text to the clipboard, transferring ownership only after a successful copy.
bool CopyTextToClipboard(HWND owner, const wchar_t* text);

/// Copies control text into a null-terminated process-heap buffer owned by the caller.
wchar_t* CopyControlText(HWND control);

/// Draws or measures descriptive text with whole-word wrapping and typographic line spacing.
int DrawWordWrappedText(HDC dc, const wchar_t* text, const RECT& bounds, UINT flags);

/// Measures a wrapped label with the same font, word boundaries and line spacing used by its painter.
int WrappedLabelHeight(HWND control, int width);

/// Paints a whole-word-wrapped dialog label in its current font over the native dialog background.
INT_PTR DrawWrappedTextItem(const DRAWITEMSTRUCT* item);

/// Shortens a long filename in the middle while retaining its beginning, stem ending and complete extension.
void FormatFileNameCaption(const wchar_t* path, UINT limit, wchar_t* caption, DWORD capacity);

/// Shortens text in the middle without splitting surrogate pairs, optionally retaining a complete file
/// extension.
void FormatMiddleCaption(const wchar_t* name, UINT limit, bool keepExtension, wchar_t* caption,
    DWORD capacity);

/// Fits an absolute path to its current font and width, retaining the root, parent directory and both
/// filename ends.
void FormatPathCaption(HDC dc, const wchar_t* path, int width, wchar_t* caption, DWORD capacity);

/// Recognizes Unicode whitespace in information text.
bool IsTextWhitespace(wchar_t character);

/// Releases the cached Unicode boundary analysis and its retained text.
void ResetInformationWordBreak();

/// Installs Unicode wrapping when system Uniscribe is available without requiring it on Windows NT 4.0.
void InstallInformationWordBreak(HWND edit);

/// Loads a saved interface choice or detects the Windows language with the legacy API path.
void InitializeApplicationLanguage();

/// Maps a Windows language identifier to one of the supported interface variants.
int ApplicationLanguageFromLangId(LANGID language);

/// Returns the active application-interface language index.
int GetApplicationLanguage();

/// Sets the active interface variant while constraining invalid indices to the default.
void SetApplicationLanguage(int language);

/// Returns the native display name of a supported interface language.
const wchar_t* ApplicationLanguageName(int language);

/// Returns the locale code of a supported interface language.
const wchar_t* ApplicationLanguageCode(int language);

/// Returns a borrowed localized UI string in the current application language.
const wchar_t* T(TextId id);
