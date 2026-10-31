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

#include "Localization.h"
#include "MainForm.h"
#include "TabControl.h"
#include "SelectionEdit.h"
#include "SettingsStorage.h"
#include "resource.h"
#include <commctrl.h>
#include <commdlg.h>
#include <shellapi.h>
#include <windowsx.h>

 /// Associates a menu command with its submenu and localized caption identifier.
struct MenuCaption {
    int menu;
    UINT id;
    TextId text;
};

/// Command captions refreshed when the interface language changes.
static const MenuCaption menuCaptions[] = {
    { 0, ID_FILE_OPEN, TXT_OPEN },
    { 0, ID_FILE_OPEN_FOLDER, TXT_OPEN_FOLDER },
    { 0, ID_FILE_CLOSE, TXT_CLOSE_TAB },
    { 0, ID_FILE_CLOSE_ALL, TXT_CLOSE_ALL },
    { 0, ID_FILE_EXPORT, TXT_EXPORT },
    { 0, ID_FILE_PRINT, TXT_PRINT },
    { 0, ID_FILE_EXIT, TXT_EXIT },
    { 1, ID_FULL_PARSING, TXT_FULL_PARSING },
    { 1, ID_ADVANCED_MODE, TXT_ADVANCED_MODE },
    { 1, ID_TRACE_LEVEL_0, TXT_TRACE_LEVEL_0 },
    { 1, ID_TRACE_LEVEL_5, TXT_TRACE_LEVEL_5 },
    { 1, ID_TRACE_LEVEL_9, TXT_TRACE_LEVEL_9 },
    { 1, ID_TRACE_LEVEL_10, TXT_TRACE_LEVEL_10 },
    { 1, ID_PREFERENCES, TXT_PREFERENCES_MENU },
    { 2, ID_TOOLS_CREATE_HEADER, TXT_CREATE_HEADER },
    { 3, ID_HELP_CONTENTS, TXT_HELP },
    { 3, ID_HELP_FORMATS, TXT_KNOWN_FORMATS },
    { 3, ID_HELP_CODECS, TXT_KNOWN_CODECS },
    { 3, ID_HELP_PARAMETERS, TXT_KNOWN_PARAMETERS },
    { 3, ID_HELP_ABOUT, TXT_ABOUT }
};

/// Private messages for background completion, forwarded files and deferred library startup.
static const UINT reportCompleteMessage = WM_APP + 1;
static const UINT instanceFilesMessage = WM_APP + 3;
static const UINT initializeLibraryMessage = WM_APP + 4;
static const UINT printCompleteMessage = WM_APP + 5;

/// Reads file identity, size and write time without reading its media content.
static bool GetReportFileInfo(const wchar_t* path, BY_HANDLE_FILE_INFORMATION& information) {
    HANDLE file = CreateFileW(path,
        FILE_READ_ATTRIBUTES, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        return false;
    }
    bool success = GetFileInformationByHandle(file, &information) != FALSE
        && !(information.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    CloseHandle(file);
    return success;
}

/// Compares the file identity and content-change metadata used by report variants.
static bool SameReportFile(const BY_HANDLE_FILE_INFORMATION& first, const BY_HANDLE_FILE_INFORMATION& second) {
    return first.dwVolumeSerialNumber == second.dwVolumeSerialNumber
        && first.nFileIndexHigh == second.nFileIndexHigh
        && first.nFileIndexLow == second.nFileIndexLow
        && first.nFileSizeHigh == second.nFileSizeHigh
        && first.nFileSizeLow == second.nFileSizeLow
        && first.ftLastWriteTime.dwHighDateTime == second.ftLastWriteTime.dwHighDateTime
        && first.ftLastWriteTime.dwLowDateTime == second.ftLastWriteTime.dwLowDateTime;
}

/// Returns the report slot for the selected parsing, detail and trace settings.
static UINT ReportVariant(LibraryCommand command, bool advancedMode, bool fullParsing, UINT traceLevel) {
    if (command == LibraryCommand::Read) {
        return traceLevel * 4 + (fullParsing ? 2 : 0) + (advancedMode ? 1 : 0);
    }
    return 0;
}

/// Releases every report variant owned by one tab and invalidates its source metadata.
static void ClearReportVariants(FileTab* file) {
    for (UINT index = 0; index < reportVariantCount; ++index) {
        if (file->reports[index]) {
            HeapFree(GetProcessHeap(), 0, file->reports[index]);
            file->reports[index] = nullptr;
        }
    }
    file->report = nullptr;
    file->sourceKnown = false;
}

/// Returns the localized caption for a library-supplied information list.
static const wchar_t* KnownInformationTitle(LibraryCommand command) {
    switch (command) {
        case LibraryCommand::Formats:
            return T(TXT_KNOWN_FORMATS_TITLE);
        case LibraryCommand::Codecs:
            return T(TXT_KNOWN_CODECS_TITLE);
        case LibraryCommand::Parameters:
            return T(TXT_KNOWN_PARAMETERS_TITLE);
        default:
            return L"";
    }
}

/// Formats a file caption or an information-list title for the common tab control.
static void FormatTabCaption(const FileTab* file, UINT limit, wchar_t* caption, int capacity) {
    if (file->command == LibraryCommand::Read) {
        FormatFileNameCaption(file->path, limit, caption, capacity);
    } else {
        lstrcpynW(caption, KnownInformationTitle(file->command), capacity);
    }
}

/// Initializes the viewer window, file lists, fonts and report-worker state.
MainForm::MainForm()
    : window(nullptr), tabs(nullptr), status(nullptr), uiFont(nullptr), reportFont(nullptr),
    accelerators(nullptr), reportThread(nullptr), printThread(nullptr), files(nullptr), activeJob(nullptr),
    activePrintJob(nullptr), reportFontSpec(), reportFontDpi(96), nextId(1),
    tabNameLength(defaultTabNameLength), traceLevel(0), closing(false), libraryLoading(true),
    unicodeTabs(false), visualStylesActive(false), advancedMode(false), fullParsing(false) {
    LoadReportOptionsSetting(fullParsing, advancedMode, traceLevel);
    LoadOpenFolderSetting(headerFolder, ARRAYSIZE(headerFolder));
}

/// Stops outstanding reports and releases tabs, fonts and other viewer-owned resources.
MainForm::~MainForm() {
    if (printThread) {
        InterlockedExchange(&activePrintJob->canceled, 1);
        CancelDC(activePrintJob->printer);
        WaitForSingleObject(printThread, INFINITE);
        CloseHandle(printThread);
    }
    FreePrintJob(activePrintJob);
    if (reportThread) {
        WaitForSingleObject(reportThread, INFINITE);
        CloseHandle(reportThread);
    }
    if (activeJob) {
        if (activeJob->report) {
            HeapFree(GetProcessHeap(), 0, activeJob->report);
        }
        HeapFree(GetProcessHeap(), 0, activeJob);
    }
    helpForm.Close();
    aboutForm.Close();
    if (window && IsWindow(window)) {
        DestroyWindow(window);
    }
    while (files) {
        FileTab* next = files->next;
        ClearReportVariants(files);
        HeapFree(GetProcessHeap(), 0, files);
        files = next;
    }
    if (uiFont) {
        DeleteObject(uiFont);
    }
    if (reportFont) {
        DeleteObject(reportFont);
    }
}

/// Creates the native main window with its saved placement and queues initial library discovery.
bool MainForm::Create() {
    InitCommonControls();
    HINSTANCE instance = GetModuleHandleW(nullptr);
    WNDCLASSW cls = WNDCLASSW{};
    cls.style = CS_DBLCLKS;
    cls.lpfnWndProc = WindowProc;
    cls.hInstance = instance;
    cls.hIcon = LoadApplicationIcon(false);
    cls.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    cls.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
    cls.lpszClassName = viewerWindowClass;
    if (!RegisterClassW(&cls) && GetLastError() != ERROR_CLASS_ALREADY_EXISTS) {
        return false;
    }
    HMENU menu = LoadMenuW(instance, MAKEINTRESOURCEW(IDR_MENU));
    window = CreateWindowExW(0, viewerWindowClass, L"MediaInfo", WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, menu, instance, this);
    if (!window) {
        if (menu) {
            DestroyMenu(menu);
        }
        return false;
    }
    SendMessageW(window, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(LoadApplicationIcon(true)));
    if (!placement.Attach(window, "MainWindow")) {
        return false;
    }
    return PostMessageW(window, initializeLibraryMessage, 0, 0) != 0;
}

/// Creates the status bar and tabs and loads the interface and report preferences.
bool MainForm::Initialize() {
    tabs = CreateWindowExW(0, WC_TABCONTROLW, L"", WS_CHILD | WS_TABSTOP | WS_CLIPSIBLINGS | TCS_TOOLTIPS,
        0, 0, 1, 1, window, reinterpret_cast<HMENU>(10), GetModuleHandleW(nullptr), nullptr);
    status = CreateWindowExW(0, STATUSCLASSNAMEW, L"", WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP,
        0, 0, 1, 1, window, reinterpret_cast<HMENU>(11), GetModuleHandleW(nullptr), nullptr);
    if (!tabs || !status || !InstallBorderlessTabHandler(tabs)) {
        return false;
    }
    HWND tooltip = TabCtrl_GetToolTips(tabs);
    if (!tooltip) {
        return false;
    }
    SetWindowLongW(tooltip, GWL_STYLE, GetWindowLongW(tooltip, GWL_STYLE) | TTS_NOPREFIX);
    SendMessageW(tabs, CCM_SETUNICODEFORMAT, TRUE, 0);
    unicodeTabs = SendMessageW(tabs, CCM_GETUNICODEFORMAT, 0, 0) != 0;
    visualStylesActive = AreVisualStylesActive();
    recentFiles.Load();
    recentFiles.UpdateMenu(GetSubMenu(GetMenu(window), 0));
    LoadFontSetting(&reportFontSpec, &reportFontDpi);
    tabNameLength = LoadTabNameLengthSetting();
    RebuildFonts();
    accelerators = LoadAcceleratorsW(GetModuleHandleW(nullptr), MAKEINTRESOURCEW(IDR_ACCELERATORS));
    DragAcceptFiles(window, TRUE);
    ApplyLanguage();
    Layout();
    return true;
}

/// Finds and loads a compatible library after the main window and its status bar are visible.
void MainForm::InitializeLibrary() {
    if (!libraryLoading) {
        return;
    }
    SetCursor(LoadCursorW(nullptr, IDC_APPSTARTING));
    UpdateStatus();
    UpdateWindow(status);
    wchar_t customPath[MAX_PATH];
    LoadLibrarySetting(customPath, MAX_PATH);
    if (!customPath[0] || !library.Load(customPath)) {
        library.Discover();
    }
    SetCursor(LoadCursorW(nullptr, IDC_ARROW));
    libraryLoading = false;
    StartNextReport();
    UpdateWindow(status);
}

/// Refreshes main-menu captions, recent files and information windows for the active interface language.
void MainForm::ApplyLanguage() {
    HMENU menu = GetMenu(window);
    const TextId popups[] = { TXT_FILE_MENU, TXT_SETTINGS_MENU, TXT_TOOLS_MENU, TXT_HELP_MENU };
    for (int index = 0; index < static_cast<int>(ARRAYSIZE(popups)); ++index) {
        ModifyMenuW(menu, index, MF_BYPOSITION | MF_POPUP, reinterpret_cast<UINT_PTR>(GetSubMenu(menu, index)),
            T(popups[index]));
    }
    for (int index = 0; index < static_cast<int>(sizeof(menuCaptions) / sizeof(menuCaptions[0])); ++index) {
        const MenuCaption& caption = menuCaptions[index];
        ModifyMenuW(GetSubMenu(menu, caption.menu), caption.id, MF_BYCOMMAND | MF_STRING, caption.id,
            T(caption.text));
    }
    DrawMenuBar(window);
    helpForm.RefreshLanguage();
    aboutForm.RefreshLanguage();
    UpdateStatus();
}

/// Recreates the interface and report fonts and applies them to existing controls.
void MainForm::RebuildFonts() {
    HFONT newUi = CreateUiFont(window);
    HFONT newReport = CreateReportFont(window, &reportFontSpec, reportFontDpi);
    if (!newUi || !newReport) {
        if (newUi) {
            DeleteObject(newUi);
        }
        if (newReport) {
            DeleteObject(newReport);
        }
        return;
    }
    SendMessageW(tabs, WM_SETFONT, reinterpret_cast<WPARAM>(newUi), TRUE);
    SendMessageW(status, WM_SETFONT, reinterpret_cast<WPARAM>(newUi), TRUE);
    for (FileTab* file = files; file; file = file->next) {
        SendMessageW(file->edit, WM_SETFONT, reinterpret_cast<WPARAM>(newReport), TRUE);
    }
    if (uiFont) {
        DeleteObject(uiFont);
    }
    if (reportFont) {
        DeleteObject(reportFont);
    }
    uiFont = newUi;
    reportFont = newReport;
}

/// Fits the status bar and tab workspace to the current main-window client area.
void MainForm::Layout() {
    if (!tabs || !status || IsIconic(window)) {
        return;
    }
    RECT client = RECT{};
    GetClientRect(window, &client);
    SendMessageW(status, WM_SIZE, 0, 0);
    RECT statusBounds = ControlRect(status, window);
    SetWindowPos(tabs, nullptr, 0, 0, client.right, statusBounds.top,
        SWP_NOZORDER | SWP_NOACTIVATE | (files ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
    RECT content = GetTabContentRect(tabs);
    for (FileTab* file = files; file; file = file->next) {
        PlaceControl(file->edit, content.left, content.top, content.right - content.left,
            content.bottom - content.top);
    }
    UpdateStatus();
}

/// Returns the file record attached to the selected tab, or null when no file is open.
FileTab* MainForm::CurrentFile() const {
    int index = TabCtrl_GetCurSel(tabs);
    if (index < 0) {
        return nullptr;
    }
    TCITEMW item = TCITEMW{};
    item.mask = TCIF_PARAM;
    if (!SendMessageW(tabs, TCM_GETITEMW, index, reinterpret_cast<LPARAM>(&item))) {
        TCITEMA fallback = TCITEMA{};
        fallback.mask = TCIF_PARAM;
        if (!SendMessageA(tabs, TCM_GETITEMA, index, reinterpret_cast<LPARAM>(&fallback))) {
            return nullptr;
        }
        return reinterpret_cast<FileTab*>(fallback.lParam);
    }
    return reinterpret_cast<FileTab*>(item.lParam);
}

/// Places current paths and messages on the left and shows the loaded DLL version when space permits.
void MainForm::UpdateStatus() {
    RECT client = RECT{};
    GetClientRect(status, &client);
    bool loaded = !libraryLoading && library.IsLoaded();
    const wchar_t* version = loaded ? library.GetVersion() : L"";
    HDC dc = GetDC(status);
    HGDIOBJ old = SelectObject(dc, uiFont);
    SIZE extent = SIZE{};
    GetTextExtentPoint32W(dc, version, lstrlenW(version), &extent);
    SelectObject(dc, old);
    ReleaseDC(status, dc);
    int borders[3] = {};
    SendMessageW(status, SB_GETBORDERS, 0, reinterpret_cast<LPARAM>(borders));
    int versionWidth = extent.cx + 2 * borders[0] + 2 * borders[2]
        + GetSystemMetrics(SM_CXVSCROLL) + MulDiv(15, WindowDpi(status), 96);
    bool showVersion = loaded && client.right > 2 * versionWidth;
    int parts[] = { showVersion ? client.right - versionWidth : -1, -1 };
    SendMessageW(status, SB_SETPARTS, showVersion ? 2 : 1, reinterpret_cast<LPARAM>(parts));
    FileTab* active = CurrentFile();
    const wchar_t* text = nullptr;
    if (closing) {
        text = T(TXT_WAITING_FOR_REPORT);
    } else if (printThread) {
        text = T(TXT_PRINTING);
    } else if (libraryLoading || activeJob) {
        text = T(TXT_LOADING);
    } else if (active && active->error[0]) {
        text = active->error;
    } else if (!loaded) {
        text = T(TXT_MEDIALIB_NOT_LOADED);
    } else if (!active) {
        text = T(TXT_READY);
    } else if (active->command == LibraryCommand::Read) {
        text = active->path;
    } else {
        text = KnownInformationTitle(active->command);
    }
    SendMessageW(status, SB_SETTEXTA, SBT_OWNERDRAW, reinterpret_cast<LPARAM>(text));
    if (showVersion) {
        SendMessageW(status, SB_SETTEXTA, 1 | SBT_OWNERDRAW, reinterpret_cast<LPARAM>(version));
    }
    EnableMenuItem(GetMenu(window), ID_FILE_CLOSE, MF_BYCOMMAND
        | (active ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(GetMenu(window), ID_FILE_CLOSE_ALL, MF_BYCOMMAND
        | (files ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(GetMenu(window), ID_FILE_EXPORT, MF_BYCOMMAND
        | (active && active->ready ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(GetMenu(window), ID_FILE_PRINT, MF_BYCOMMAND
        | (active && active->ready && !printThread ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(GetMenu(window), ID_PREFERENCES, MF_BYCOMMAND
        | (HasPendingReports() ? MF_GRAYED : MF_ENABLED));
    EnableMenuItem(GetMenu(window), ID_ADVANCED_MODE, MF_BYCOMMAND
        | (HasPendingReports() ? MF_GRAYED : MF_ENABLED));
    CheckMenuItem(GetMenu(window), ID_ADVANCED_MODE, MF_BYCOMMAND
        | ((active ? active->advancedMode : advancedMode) ? MF_CHECKED : MF_UNCHECKED));
    EnableMenuItem(GetMenu(window), ID_FULL_PARSING, MF_BYCOMMAND
        | (HasPendingReports() ? MF_GRAYED : MF_ENABLED));
    CheckMenuItem(GetMenu(window), ID_FULL_PARSING,
        MF_BYCOMMAND | ((active ? active->fullParsing : fullParsing) ? MF_CHECKED : MF_UNCHECKED));
    CheckMenuRadioItem(GetSubMenu(GetMenu(window), 1), ID_TRACE_LEVEL_0, ID_TRACE_LEVEL_10,
        ID_TRACE_LEVEL_0 + (active ? active->traceLevel : traceLevel), MF_BYCOMMAND);
    for (UINT item = ID_TRACE_LEVEL_0; item <= ID_TRACE_LEVEL_10; ++item) {
        EnableMenuItem(GetMenu(window), item, MF_BYCOMMAND
            | (HasPendingReports() ? MF_GRAYED : MF_ENABLED));
    }
    InvalidateRect(status, nullptr, FALSE);
}

/// Displays the selected report edit and refreshes its status information.
void MainForm::SelectTab(int index) {
    if (index >= 0) {
        TabCtrl_SetCurSel(tabs, index);
    }
    FileTab* selected = CurrentFile();
    for (FileTab* file = files; file; file = file->next) {
        SetWindowPos(file->edit, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE
            | (file == selected ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
    }
    Layout();
    if (selected) {
        SetFocus(selected->edit);
    }
}

/// Selects an existing file tab or creates a new tab and queues its MediaInfo report.
bool MainForm::AddFile(const wchar_t* filename) {
    if (closing) {
        return false;
    }
    wchar_t path[MAX_PATH];
    DWORD length = GetFullPathNameW(filename, MAX_PATH, path, nullptr);
    if (!length || length >= MAX_PATH) {
        MessageBoxW(window, T(TXT_INVALID_MEDIA_PATH), L"MediaInfo", MB_OK | MB_ICONERROR);
        return false;
    }
    if (SelectExistingTab(LibraryCommand::Read, path)) {
        return true;
    }
    DWORD attributes = GetFileAttributesW(path);
    if (attributes == INVALID_FILE_ATTRIBUTES || attributes & FILE_ATTRIBUTE_DIRECTORY) {
        MessageBoxW(window, T(TXT_INVALID_MEDIA_PATH), L"MediaInfo", MB_OK | MB_ICONERROR);
        return false;
    }
    return CreateTab(LibraryCommand::Read, path);
}

/// Selects a matching file or information tab through the shared activation path.
bool MainForm::SelectExistingTab(LibraryCommand command, const wchar_t* path) {
    int index = 0;
    for (FileTab* existing = files; existing; existing = existing->next, ++index) {
        if (existing->command == command
                && (command != LibraryCommand::Read || !lstrcmpiW(existing->path, path))) {
            SelectTab(index);
            if (command == LibraryCommand::Read && existing->ready) {
                RememberFile(existing->path);
            }
            return true;
        }
    }
    return false;
}

/// Creates the common report edit and tab and queues the selected library operation.
bool MainForm::CreateTab(LibraryCommand command, const wchar_t* path) {
    if (!libraryLoading && !library.IsLoaded()) {
        MessageBoxW(window, library.GetError(), L"MediaInfo", MB_OK | MB_ICONWARNING);
        Preferences();
        if (!library.IsLoaded()) {
            return false;
        }
        UpdateStatus();
    }
    FileTab* file = static_cast<FileTab*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(FileTab)));
    if (!file) {
        return false;
    }
    file->command = command;
    file->advancedMode = advancedMode;
    file->fullParsing = fullParsing;
    file->traceLevel = traceLevel;
    if (path) {
        lstrcpyW(file->path, path);
    }
    file->id = nextId++;
    file->edit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_TABSTOP | WS_CLIPSIBLINGS
        | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_READONLY | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
        0, 0, 1, 1, window, nullptr, GetModuleHandleW(nullptr), nullptr);
    if (!file->edit || !InstallSelectionEditHandler(file->edit)) {
        if (file->edit) {
            DestroyWindow(file->edit);
        }
        HeapFree(GetProcessHeap(), 0, file);
        return false;
    }
    SendMessageW(file->edit, WM_SETFONT, reinterpret_cast<WPARAM>(reportFont), FALSE);
    SendMessageW(file->edit, EM_SETLIMITTEXT, 0x7FFFFFFE, 0);
    wchar_t name[MAX_PATH];
    FormatTabCaption(file, tabNameLength, name, MAX_PATH);
    int index = TabCtrl_GetItemCount(tabs);
    TCITEMW item = TCITEMW{};
    item.mask = TCIF_TEXT | TCIF_PARAM;
    item.pszText = name;
    item.lParam = reinterpret_cast<LPARAM>(file);
    int inserted = unicodeTabs
        ? static_cast<int>(SendMessageW(tabs, TCM_INSERTITEMW, index, reinterpret_cast<LPARAM>(&item)))
        : -1;
    if (inserted < 0) {
        char ansiName[MAX_PATH];
        WideCharToMultiByte(CP_ACP, 0, name, -1, ansiName, MAX_PATH, nullptr, nullptr);
        TCITEMA fallback = TCITEMA{};
        fallback.mask = item.mask;
        fallback.pszText = ansiName;
        fallback.lParam = item.lParam;
        inserted = static_cast<int>(SendMessageA(tabs, TCM_INSERTITEMA, index,
            reinterpret_cast<LPARAM>(&fallback)));
    }
    if (inserted < 0) {
        DestroyWindow(file->edit);
        HeapFree(GetProcessHeap(), 0, file);
        return false;
    }
    FileTab** tail = &files;
    while (*tail) {
        tail = &(*tail)->next;
    }
    *tail = file;
    SelectTab(inserted);
    if (files == file) {
        InvalidateRect(window, nullptr, TRUE);
    }
    StartNextReport();
    return true;
}

/// Removes one file tab and its report data, then selects the remaining active report.
void MainForm::CloseTab(int index) {
    int selected = TabCtrl_GetCurSel(tabs);
    if (index < 0) {
        index = selected;
    }
    if (index < 0 || index >= TabCtrl_GetItemCount(tabs)) {
        return;
    }
    FileTab** cursor = &files;
    for (int position = 0; *cursor && position < index; ++position) {
        cursor = &(*cursor)->next;
    }
    if (!*cursor) {
        return;
    }
    FileTab* removed = *cursor;
    TabCtrl_DeleteItem(tabs, index);
    *cursor = removed->next;
    DestroyWindow(removed->edit);
    ClearReportVariants(removed);
    HeapFree(GetProcessHeap(), 0, removed);
    int count = TabCtrl_GetItemCount(tabs);
    if (index < selected) {
        --selected;
    } else if (index == selected) {
        selected = index < count ? index : count - 1;
    }
    SelectTab(count ? selected : -1);
    if (!files) {
        InvalidateRect(window, nullptr, TRUE);
    }
}

/// Closes every file tab and returns the viewer to its empty workspace.
void MainForm::CloseAllTabs() {
    while (files) {
        CloseTab();
    }
}

/// Moves a successfully opened file to the recent-files list and refreshes its menu.
void MainForm::RememberFile(const wchar_t* path) {
    recentFiles.Add(path);
    recentFiles.Save();
    recentFiles.UpdateMenu(GetSubMenu(GetMenu(window), 0));
    DrawMenuBar(window);
}

/// Selects an adjacent tab with wraparound for keyboard tab navigation.
void MainForm::SwitchTab(int direction) {
    int count = TabCtrl_GetItemCount(tabs);
    if (count) {
        SelectTab((TabCtrl_GetCurSel(tabs) + count + direction) % count);
    }
}

/// Opens the native media-file picker and processes its selected paths in order.
void MainForm::OpenFiles() {
    wchar_t* selection = ChooseMediaFiles(window);
    if (!selection) {
        return;
    }
    for (wchar_t* name = selection; *name; name += lstrlenW(name) + 1) {
        AddFile(name);
    }
    HeapFree(GetProcessHeap(), 0, selection);
}

/// Opens files directly inside the selected folder, reusing existing tabs.
void MainForm::OpenFolder() {
    wchar_t folder[MAX_PATH];
    if (!ChooseMediaFolder(window, folder)) {
        return;
    }
    wchar_t path[MAX_PATH];
    int length = lstrlenW(folder);
    HANDLE search = INVALID_HANDLE_VALUE;
    WIN32_FIND_DATAW entry = WIN32_FIND_DATAW{};
    DWORD error = ERROR_FILENAME_EXCED_RANGE;
    if (length && length + 2 < MAX_PATH) {
        lstrcpyW(path, folder);
        if (path[length - 1] != L'\\') {
            path[length++] = L'\\';
        }
        lstrcpyW(path + length, L"*");
        search = FindFirstFileW(path, &entry);
        error = search == INVALID_HANDLE_VALUE ? GetLastError() : ERROR_SUCCESS;
    }
    if (search != INVALID_HANDLE_VALUE) {
        while (true) {
            if (!(entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                if (length + lstrlenW(entry.cFileName) >= MAX_PATH) {
                    error = ERROR_FILENAME_EXCED_RANGE;
                    break;
                }
                lstrcpyW(path + length, entry.cFileName);
                if (!AddFile(path)) {
                    break;
                }
            }
            if (!FindNextFileW(search, &entry)) {
                error = GetLastError();
                break;
            }
        }
        FindClose(search);
    }
    if (error != ERROR_SUCCESS && error != ERROR_NO_MORE_FILES && error != ERROR_FILE_NOT_FOUND) {
        wchar_t message[MAX_PATH + 512];
        wsprintfW(message, T(TXT_FOLDER_READ_FAILED), folder, error);
        MessageBoxW(window, message, L"MediaInfo", MB_OK | MB_ICONERROR);
    }
}

/// Shows modal Preferences with callbacks that apply changes to the live viewer.
void MainForm::Preferences() {
    PreferencesCallbacks callbacks = PreferencesCallbacks{
        this,
        PreferencesApplied,
        PreferencesBusy,
        PreferencesHasRecentFiles,
        PreferencesClearRecentFiles,
        PreferencesLoading
    };
    ShowPreferences(window, library, &reportFontSpec, &reportFontDpi, nullptr, &callbacks);
    UpdateStatus();
}

/// Reports whether library initialization or report work prevents replacement of the active library.
bool MainForm::PreferencesBusy(void* context) {
    return static_cast<MainForm*>(context)->HasPendingReports();
}

/// Publishes library-loading progress while Preferences replaces the current library.
void MainForm::PreferencesLoading(void* context, bool loading) {
    MainForm* owner = static_cast<MainForm*>(context);
    owner->libraryLoading = loading;
    owner->UpdateStatus();
    UpdateWindow(owner->status);
}

/// Reports whether the viewer has any recent files available to clear.
bool MainForm::PreferencesHasRecentFiles(void* context) {
    return !static_cast<MainForm*>(context)->recentFiles.IsEmpty();
}

/// Immediately clears saved and live recent files and refreshes the main menu.
bool MainForm::PreferencesClearRecentFiles(void* context) {
    MainForm* owner = static_cast<MainForm*>(context);
    owner->recentFiles.Clear();
    bool saved = owner->recentFiles.Save();
    owner->recentFiles.UpdateMenu(GetSubMenu(GetMenu(owner->window), 0));
    DrawMenuBar(owner->window);
    return saved;
}

/// Applies the configured filename-length limit to every open tab caption.
void MainForm::UpdateTabNames() {
    int index = 0;
    for (FileTab* file = files; file; file = file->next, ++index) {
        wchar_t name[MAX_PATH];
        FormatTabCaption(file, tabNameLength, name, MAX_PATH);
        TCITEMW item = TCITEMW{};
        item.mask = TCIF_TEXT;
        item.pszText = name;
        if (!unicodeTabs || !SendMessageW(tabs, TCM_SETITEMW, index, reinterpret_cast<LPARAM>(&item))) {
            char ansiName[MAX_PATH];
            WideCharToMultiByte(CP_ACP, 0, name, -1, ansiName, MAX_PATH, nullptr, nullptr);
            TCITEMA fallback = TCITEMA{};
            fallback.mask = TCIF_TEXT;
            fallback.pszText = ansiName;
            SendMessageA(tabs, TCM_SETITEMA, index, reinterpret_cast<LPARAM>(&fallback));
        }
    }
}

/// Opens or activates a library-supplied information list in the main report workspace.
void MainForm::ShowKnownInformation(LibraryCommand command) {
    if (!closing && !SelectExistingTab(command, nullptr)) {
        CreateTab(command, nullptr);
    }
}

/// Changes only the active tab's report options and saves the complete combination for new tabs.
void MainForm::ChangeReportOptions(UINT command) {
    FileTab* active = CurrentFile();
    if (active) {
        advancedMode = active->advancedMode;
        fullParsing = active->fullParsing;
        traceLevel = active->traceLevel;
    }
    if (command == ID_FULL_PARSING) {
        fullParsing = !fullParsing;
    } else if (command == ID_ADVANCED_MODE) {
        advancedMode = !advancedMode;
    } else {
        traceLevel = command - ID_TRACE_LEVEL_0;
    }
    if (active) {
        active->advancedMode = advancedMode;
        active->fullParsing = fullParsing;
        active->traceLevel = traceLevel;
    }
    if (!SaveReportOptionsSetting(fullParsing, advancedMode, traceLevel)) {
        MessageBoxW(window, T(TXT_PREFERENCES_SAVE_FAILED), L"MediaInfo", MB_OK | MB_ICONWARNING);
    }
    RefreshReports();
}

/// Refreshes the active variant or invalidates and refreshes every tab after a library change.
void MainForm::RefreshReports(bool discardCached) {
    FileTab* selected = CurrentFile();
    for (FileTab* file = files; file; file = file->next) {
        if (!discardCached && file != selected) {
            continue;
        }
        if (discardCached) {
            ClearReportVariants(file);
        }
        file->started = false;
        file->ready = false;
        file->refreshing = true;
        file->error[0] = 0;
    }
    StartNextReport();
}

/// Applies committed interface, font and caption settings and invalidates reports after library changes.
void MainForm::PreferencesApplied(void* context, const PreferencesChanges& changes) {
    MainForm* owner = static_cast<MainForm*>(context);
    owner->tabNameLength = changes.tabNameLength;
    owner->UpdateTabNames();
    if (changes.reportsChanged) {
        owner->RefreshReports(true);
    }
    owner->RebuildFonts();
    owner->ApplyLanguage();
    owner->Layout();
}

/// Exports the entire active report using the selected native file-dialog format.
void MainForm::ExportReport() {
    FileTab* active = CurrentFile();
    if (!active || !active->ready || !active->report) {
        return;
    }
    wchar_t path[MAX_PATH] = L"";
    const wchar_t* name = active->command == LibraryCommand::Read
        ? active->path
        : KnownInformationTitle(active->command);
    for (const wchar_t* cursor = name; *cursor; ++cursor) {
        if (*cursor == L'\\') {
            name = cursor + 1;
        }
    }
    lstrcpynW(path, name, MAX_PATH - 5);
    DWORD type = 2;
    if (!ChooseExportFile(window, path, T(TXT_EXPORT_TITLE), &type)) {
        return;
    }
    wchar_t error[512];
    bool saved = type <= 5
        ? SaveReportText(active->report, path, type, error, 512)
        : SaveReportImage(active->edit, active->report, path, type, error, 512);
    if (saved) {
        SaveExportSetting(path, type);
    } else {
        MessageBoxW(window, error, L"MediaInfo", MB_OK | MB_ICONERROR);
    }
}

/// Opens the system printer dialog and prints a snapshot of the active report without preview.
void MainForm::PrintReport() {
    FileTab* active = CurrentFile();
    if (closing || !active || !active->ready || !active->report || printThread) {
        return;
    }
    const wchar_t* title = active->command == LibraryCommand::Read
        ? active->path
        : KnownInformationTitle(active->command);
    wchar_t error[512];
    PrintJob* job = ChooseReportPrinter(window, active->edit, active->report, title, error, ARRAYSIZE(error));
    if (closing || !window) {
        FreePrintJob(job);
        return;
    }
    if (!job) {
        if (error[0]) {
            MessageBoxW(window, error, L"MediaInfo", MB_OK | MB_ICONERROR);
        }
        return;
    }
    printThread = CreateThread(nullptr, 0, PrintDocument, job, 0, nullptr);
    if (!printThread) {
        FreePrintJob(job);
        MessageBoxW(window, T(TXT_PRINT_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
        return;
    }
    activePrintJob = job;
    UpdateStatus();
}

/// Prints the selected report on its worker thread and posts the result to the viewer.
DWORD WINAPI MainForm::PrintDocument(void* parameter) {
    PrintJob* job = static_cast<PrintJob*>(parameter);
    job->success = PrintReportPages(job);
    PostMessageW(job->target, printCompleteMessage, 0, reinterpret_cast<LPARAM>(job));
    return 0;
}

/// Collects the finished print job and releases its snapshot and printer context.
void MainForm::CompletePrint(PrintJob* job) {
    if (job != activePrintJob) {
        return;
    }
    WaitForSingleObject(printThread, INFINITE);
    CloseHandle(printThread);
    printThread = nullptr;
    activePrintJob = nullptr;
    bool failed = !job->success && !job->canceled;
    FreePrintJob(job);
    if (closing) {
        if (!reportThread) {
            DestroyWindow(window);
        }
    } else {
        UpdateStatus();
        if (failed) {
            MessageBoxW(window, T(TXT_PRINT_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
        }
    }
}

/// Reads the requested file report on the background thread and posts its completion to the viewer.
DWORD WINAPI MainForm::ReadReport(void* parameter) {
    ReportJob* job = static_cast<ReportJob*>(parameter);
    job->success = job->command == LibraryCommand::Read
        ? job->library->Read(job->path, &job->report, job->advancedMode, job->fullParsing, job->traceLevel)
        : job->library->Query(job->command, &job->report);
    if (job->success && job->command == LibraryCommand::Read) {
        BY_HANDLE_FILE_INFORMATION information = BY_HANDLE_FILE_INFORMATION{};
        job->sourceKnown = job->sourceKnown
            && GetReportFileInfo(job->path, information)
            && SameReportFile(job->source, information);
    }
    if (!job->success) {
        lstrcpynW(job->error, job->library->GetError(), 512);
    }
    PostMessageW(job->target, reportCompleteMessage, 0, reinterpret_cast<LPARAM>(job));
    return 0;
}

/// Starts the next queued report when no report thread is already active.
void MainForm::StartNextReport() {
    if (reportThread || libraryLoading || closing) {
        return;
    }
    for (FileTab* file = files; file; file = file->next) {
        if (file->started) {
            continue;
        }
        file->started = true;
        if (file->command == LibraryCommand::Read) {
            BY_HANDLE_FILE_INFORMATION information = BY_HANDLE_FILE_INFORMATION{};
            bool known = GetReportFileInfo(file->path, information);
            if (!known || !file->sourceKnown || !SameReportFile(file->source, information)) {
                ClearReportVariants(file);
                file->source = information;
                file->sourceKnown = known;
            }
        }
        UINT variant = ReportVariant(file->command, file->advancedMode, file->fullParsing, file->traceLevel);
        if (file->reports[variant]) {
            if (file->report != file->reports[variant]) {
                file->report = file->reports[variant];
                SetWindowTextW(file->edit, file->report);
                SendMessageW(file->edit, EM_SETSEL, 0, 0);
            }
            file->ready = true;
            file->refreshing = false;
            continue;
        }
        if (!library.IsLoaded()) {
            lstrcpynW(file->error, library.GetError(), ARRAYSIZE(file->error));
            continue;
        }
        ReportJob* job = static_cast<ReportJob*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
            sizeof(ReportJob)));
        if (!job) {
            lstrcpyW(file->error, T(TXT_REPORT_START_FAILED));
            continue;
        }
        job->target = window;
        job->library = &library;
        job->command = file->command;
        job->id = file->id;
        job->advancedMode = file->advancedMode;
        job->fullParsing = file->fullParsing;
        job->traceLevel = file->traceLevel;
        job->source = file->source;
        job->sourceKnown = file->sourceKnown;
        lstrcpyW(job->path, file->path);
        reportThread = CreateThread(nullptr, 0, ReadReport, job, 0, nullptr);
        if (!reportThread) {
            HeapFree(GetProcessHeap(), 0, job);
            lstrcpyW(file->error, T(TXT_REPORT_THREAD_START_FAILED));
            continue;
        }
        activeJob = job;
        break;
    }
    UpdateStatus();
}

/// Collects a completed report, updates its tab and advances the remaining report queue.
void MainForm::CompleteReport(ReportJob* job) {
    if (job != activeJob) {
        return;
    }
    WaitForSingleObject(reportThread, INFINITE);
    CloseHandle(reportThread);
    reportThread = nullptr;
    activeJob = nullptr;
    for (FileTab* file = files; file; file = file->next) {
        if (file->id == job->id) {
            UINT variant = ReportVariant(job->command, job->advancedMode, job->fullParsing, job->traceLevel);
            if (file->reports[variant]) {
                HeapFree(GetProcessHeap(), 0, file->reports[variant]);
            }
            file->reports[variant] = job->report;
            file->report = job->report;
            job->report = nullptr;
            if (job->success && job->command == LibraryCommand::Read) {
                file->sourceKnown = job->sourceKnown;
            }
            file->ready = job->success;
            if (job->success && !file->refreshing && file->command == LibraryCommand::Read) {
                RememberFile(file->path);
            }
            file->refreshing = false;
            lstrcpynW(file->error, job->success ? L"" : job->error, ARRAYSIZE(file->error));
            SetWindowTextW(file->edit, job->success ? file->report : L"");
            SendMessageW(file->edit, EM_SETSEL, 0, 0);
            break;
        }
    }
    if (job->report) {
        HeapFree(GetProcessHeap(), 0, job->report);
    }
    HeapFree(GetProcessHeap(), 0, job);
    if (closing) {
        if (!printThread) {
            DestroyWindow(window);
        }
    } else {
        StartNextReport();
        UpdateStatus();
    }
}

/// Dispatches native main-window input, layout, file, menu and asynchronous report messages.
LRESULT CALLBACK MainForm::WindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    MainForm* owner = reinterpret_cast<MainForm*>(GetWindowLongPtrW(window, GWLP_USERDATA));
    if (message == WM_NCCREATE) {
        owner = static_cast<MainForm*>(reinterpret_cast<CREATESTRUCTW*>(lParam)->lpCreateParams);
        owner->window = window;
        SetWindowLongPtrW(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(owner));
    }
    if (!owner) {
        return DefWindowProcW(window, message, wParam, lParam);
    }
    switch (message) {
        case initializeLibraryMessage:
            owner->InitializeLibrary();
            return 0;
        case WM_SETCURSOR:
            if (owner->libraryLoading && IsWindowEnabled(window) && LOWORD(lParam) == HTCLIENT) {
                SetCursor(LoadCursorW(nullptr, IDC_APPSTARTING));
                return TRUE;
            }
            break;
        case WM_CREATE:
            return owner->Initialize() ? 0 : -1;
        case WM_COPYDATA:
        {
            const COPYDATASTRUCT* request = reinterpret_cast<const COPYDATASTRUCT*>(lParam);
            if (owner->closing || !ValidateInstanceFiles(request)) {
                return FALSE;
            }
            void* paths = HeapAlloc(GetProcessHeap(), 0, request->cbData);
            if (!paths) {
                return FALSE;
            }
            CopyMemory(paths, request->lpData, request->cbData);
            if (!PostMessageW(window, instanceFilesMessage, 0, reinterpret_cast<LPARAM>(paths))) {
                HeapFree(GetProcessHeap(), 0, paths);
                return FALSE;
            }
            return TRUE;
        }
        case instanceFilesMessage:
        {
            wchar_t* paths = reinterpret_cast<wchar_t*>(lParam);
            owner->placement.BringToFront();
            const wchar_t* path = paths;
            while (*path) {
                owner->AddFile(path);
                path += lstrlenW(path) + 1;
            }
            HeapFree(GetProcessHeap(), 0, paths);
            return 0;
        }
        case WM_SIZE:
            owner->Layout();
            return 0;
        case WM_NOTIFY:
        {
            NMHDR* notification = reinterpret_cast<NMHDR*>(lParam);
            if (notification->hwndFrom == owner->tabs && notification->code == TCN_SELCHANGE) {
                owner->SelectTab(TabCtrl_GetCurSel(owner->tabs));
                return 0;
            }
            if ((notification->code == TTN_GETDISPINFOW || notification->code == TTN_GETDISPINFOA)
                    && notification->hwndFrom == TabCtrl_GetToolTips(owner->tabs)) {
                FileTab* file = owner->files;
                for (UINT_PTR index = 0; file && index < notification->idFrom; ++index) {
                    file = file->next;
                }
                RECT bounds = RECT{};
                GetWindowRect(window, &bounds);
                RECT work = WindowWorkArea(bounds);
                SendMessageW(notification->hwndFrom, TTM_SETMAXTIPWIDTH, 0, work.right - work.left);
                const wchar_t* tooltip = !file ? nullptr : file->command == LibraryCommand::Read
                    ? file->path
                    : KnownInformationTitle(file->command);
                if (notification->code == TTN_GETDISPINFOW) {
                    reinterpret_cast<NMTTDISPINFOW*>(lParam)->lpszText = const_cast<wchar_t*>(tooltip);
                } else {
                    owner->tabTooltipPath[0] = 0;
                    if (tooltip) {
                        WideCharToMultiByte(CP_ACP, 0, tooltip, -1, owner->tabTooltipPath,
                            sizeof(owner->tabTooltipPath), nullptr, nullptr);
                    }
                    reinterpret_cast<NMTTDISPINFOA*>(lParam)->lpszText = owner->tabTooltipPath;
                }
                return 0;
            }
            break;
        }
        case WM_CTLCOLORSTATIC:
            if (!owner->visualStylesActive) {
                break;
            }
            for (FileTab* file = owner->files; file; file = file->next) {
                if (reinterpret_cast<HWND>(lParam) == file->edit) {
                    SetTextColor(reinterpret_cast<HDC>(wParam), RGB(0, 0, 0));
                    SetBkColor(reinterpret_cast<HDC>(wParam), RGB(255, 255, 255));
                    return reinterpret_cast<LRESULT>(GetStockObject(WHITE_BRUSH));
                }
            }
            break;
        case WM_ERASEBKGND:
        case WM_PRINTCLIENT:
            if (!owner->files) {
                RECT client = RECT{};
                GetClientRect(window, &client);
                FillRect(reinterpret_cast<HDC>(wParam), &client, GetSysColorBrush(COLOR_APPWORKSPACE));
                return TRUE;
            }
            break;
        case WM_PAINT:
        {
            PAINTSTRUCT paint = PAINTSTRUCT{};
            HDC dc = BeginPaint(window, &paint);
            if (!owner->files) {
                FillRect(dc, &paint.rcPaint, GetSysColorBrush(COLOR_APPWORKSPACE));
            }
            EndPaint(window, &paint);
            return 0;
        }
        case WM_DRAWITEM:
        {
            DRAWITEMSTRUCT* item = reinterpret_cast<DRAWITEMSTRUCT*>(lParam);
            if (item->hwndItem == owner->status) {
                HGDIOBJ old = SelectObject(item->hDC, owner->uiFont);
                TEXTMETRICW metrics = TEXTMETRICW{};
                GetTextMetricsW(item->hDC, &metrics);
                RECT text = item->rcItem;
                int borders[3] = {};
                SendMessageW(owner->status, SB_GETBORDERS, 0, reinterpret_cast<LPARAM>(borders));
                text.left += borders[2];
                int parts = static_cast<int>(SendMessageW(owner->status, SB_GETPARTS, 0, 0));
                if (item->itemID + 1 == static_cast<UINT>(parts)) {
                    text.right -= GetSystemMetrics(SM_CXVSCROLL);
                }
                text.top += (text.bottom - text.top - metrics.tmHeight) / 2;
                SetTextColor(item->hDC, GetSysColor(COLOR_BTNTEXT));
                SetBkMode(item->hDC, TRANSPARENT);
                const wchar_t* caption = reinterpret_cast<const wchar_t*>(item->itemData);
                FileTab* active = item->itemID == 0 ? owner->CurrentFile() : nullptr;
                const wchar_t* loadingFormat = item->itemID == 0
                    && owner->activeJob
                    && owner->activeJob->command == LibraryCommand::Read
                    && caption == T(TXT_LOADING) ? T(TXT_LOADING_FILE) : nullptr;
                wchar_t pathCaption[MAX_PATH + 4];
                wchar_t loadingCaption[MAX_PATH + 128];
                UINT flags = DT_SINGLELINE | DT_NOPREFIX | DT_END_ELLIPSIS;
                if (loadingFormat || active && caption == active->path) {
                    int width = text.right - text.left;
                    if (loadingFormat) {
                        wsprintfW(loadingCaption, loadingFormat, L"");
                        SIZE extent = SIZE{};
                        GetTextExtentPoint32W(item->hDC, loadingCaption, lstrlenW(loadingCaption), &extent);
                        width -= extent.cx;
                    }
                    FormatPathCaption(item->hDC, loadingFormat ? owner->activeJob->path : caption, width,
                        pathCaption, ARRAYSIZE(pathCaption));
                    caption = pathCaption;
                    if (loadingFormat) {
                        wsprintfW(loadingCaption, loadingFormat, pathCaption);
                        caption = loadingCaption;
                    }
                    flags &= ~DT_END_ELLIPSIS;
                }
                DrawTextW(item->hDC, caption, -1, &text, flags);
                SelectObject(item->hDC, old);
                return TRUE;
            }
            break;
        }
        case WM_MOUSEWHEEL:
            if (ScrollTabHeaders(window, owner->tabs, wParam, lParam)) {
                return 0;
            }
            break;
        case WM_COMMAND:
            if (LOWORD(wParam) >= ID_FILE_RECENT_FIRST
                    && LOWORD(wParam) < ID_FILE_RECENT_FIRST + RecentFiles::Capacity) {
                int index = LOWORD(wParam) - ID_FILE_RECENT_FIRST;
                const wchar_t* recent = owner->recentFiles.Get(index);
                if (recent) {
                    wchar_t path[MAX_PATH];
                    lstrcpyW(path, recent);
                    DWORD attributes = GetFileAttributesW(path);
                    if (attributes == INVALID_FILE_ATTRIBUTES || attributes & FILE_ATTRIBUTE_DIRECTORY) {
                        DWORD failure = attributes == INVALID_FILE_ATTRIBUTES
                            ? GetLastError()
                            : ERROR_SUCCESS;
                        const wchar_t* prompt = failure == ERROR_FILE_NOT_FOUND
                            || failure == ERROR_PATH_NOT_FOUND
                                ? T(TXT_RECENT_FILE_MISSING)
                                : T(TXT_RECENT_FILE_UNAVAILABLE);
                        wchar_t question[MAX_PATH + 512];
                        wsprintfW(question, prompt, path);
                        if (MessageBoxW(window, question, L"MediaInfo",
                            MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) == IDYES) {
                            owner->recentFiles.Remove(path);
                            owner->recentFiles.Save();
                            owner->recentFiles.UpdateMenu(GetSubMenu(GetMenu(window), 0));
                            DrawMenuBar(window);
                        }
                    } else {
                        owner->AddFile(path);
                    }
                }
                return 0;
            }
            switch (LOWORD(wParam)) {
                case ID_FILE_OPEN:
                    owner->OpenFiles();
                    return 0;
                case ID_FILE_OPEN_FOLDER:
                    owner->OpenFolder();
                    return 0;
                case ID_FILE_CLOSE:
                    owner->CloseTab();
                    return 0;
                case ID_FILE_CLOSE_ALL:
                    owner->CloseAllTabs();
                    return 0;
                case ID_FILE_PRINT:
                    owner->PrintReport();
                    return 0;
                case ID_FILE_EXPORT:
                    owner->ExportReport();
                    return 0;
                case ID_FILE_EXIT:
                    SendMessageW(window, WM_CLOSE, 0, 0);
                    return 0;
                case ID_FULL_PARSING:
                case ID_ADVANCED_MODE:
                case ID_TRACE_LEVEL_0:
                case ID_TRACE_LEVEL_5:
                case ID_TRACE_LEVEL_9:
                case ID_TRACE_LEVEL_10:
                    if (!owner->HasPendingReports()) {
                        owner->ChangeReportOptions(LOWORD(wParam));
                    }
                    return 0;
                case ID_PREFERENCES:
                    if (!owner->HasPendingReports()) {
                        owner->Preferences();
                    }
                    return 0;
                case ID_TOOLS_CREATE_HEADER:
                    CreateHeaderFile(window, owner->headerFolder);
                    return 0;
                case ID_HELP_CONTENTS:
                    owner->helpForm.Show(window);
                    return 0;
                case ID_HELP_FORMATS:
                    owner->ShowKnownInformation(LibraryCommand::Formats);
                    return 0;
                case ID_HELP_CODECS:
                    owner->ShowKnownInformation(LibraryCommand::Codecs);
                    return 0;
                case ID_HELP_PARAMETERS:
                    owner->ShowKnownInformation(LibraryCommand::Parameters);
                    return 0;
                case ID_HELP_ABOUT:
                    owner->aboutForm.Show(window);
                    return 0;
                case ID_NEXT_TAB:
                    owner->SwitchTab(1);
                    return 0;
                case ID_PREVIOUS_TAB:
                    owner->SwitchTab(-1);
                    return 0;
            }
            break;
        case tabCloseMessage:
            if (reinterpret_cast<HWND>(lParam) == owner->tabs) {
                owner->CloseTab(static_cast<int>(wParam));
            }
            return 0;
        case WM_DROPFILES:
        {
            HDROP drop = reinterpret_cast<HDROP>(wParam);
            UINT count = DragQueryFileW(drop, 0xFFFFFFFF, nullptr, 0);
            for (UINT index = 0; index < count; ++index) {
                wchar_t path[MAX_PATH];
                UINT length = DragQueryFileW(drop, index, nullptr, 0);
                if (length < MAX_PATH && DragQueryFileW(drop, index, path, MAX_PATH)) {
                    owner->AddFile(path);
                }
            }
            DragFinish(drop);
            return 0;
        }
        case WM_SYSCOLORCHANGE:
            RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
            return 0;
        case WM_SETTINGCHANGE:
        case WM_THEMECHANGED:
            owner->visualStylesActive = AreVisualStylesActive();
            owner->RebuildFonts();
            owner->Layout();
            RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
            return 0;
        case WM_DPICHANGED:
        {
            RECT* bounds = reinterpret_cast<RECT*>(lParam);
            SetWindowPos(window, nullptr, bounds->left, bounds->top, bounds->right - bounds->left,
                bounds->bottom - bounds->top, SWP_NOZORDER | SWP_NOACTIVATE);
            owner->RebuildFonts();
            owner->Layout();
            return 0;
        }
        case WM_QUERYENDSESSION:
            return TRUE;
        case WM_CLOSE:
            if (owner->printThread) {
                InterlockedExchange(&owner->activePrintJob->canceled, 1);
                CancelDC(owner->activePrintJob->printer);
            }
            if (owner->reportThread || owner->printThread) {
                owner->closing = true;
                owner->UpdateStatus();
                return 0;
            }
            DestroyWindow(window);
            return 0;
        case WM_DESTROY:
        {
            MSG pending = MSG{};
            while (PeekMessageW(&pending, window, instanceFilesMessage, instanceFilesMessage, PM_REMOVE)) {
                HeapFree(GetProcessHeap(), 0, reinterpret_cast<void*>(pending.lParam));
            }
            owner->helpForm.Close();
            owner->aboutForm.Close();
            PostQuitMessage(0);
            return 0;
        }
        case WM_NCDESTROY:
            owner->window = nullptr;
            break;
        default:
            if (message == printCompleteMessage) {
                owner->CompletePrint(reinterpret_cast<PrintJob*>(lParam));
                return 0;
            }
            if (message == reportCompleteMessage) {
                owner->CompleteReport(reinterpret_cast<ReportJob*>(lParam));
                return 0;
            }
            break;
    }
    return DefWindowProcW(window, message, wParam, lParam);
}

/// Displays the main window and its library-loading status through the persisted placement state.
void MainForm::Show() {
    placement.Show();
    UpdateWindow(window);
    if (libraryLoading) {
        SetCursor(LoadCursorW(nullptr, IDC_APPSTARTING));
    }
}

/// Routes hovered-control wheel input and window keyboard shortcuts before normal native dispatch.
bool MainForm::Translate(MSG* message) {
    if (message->message == WM_MOUSEWHEEL) {
        if (ScrollTabHeaders(window, tabs, message->wParam, message->lParam)) {
            return true;
        }
        FileTab* active = CurrentFile();
        if (active
                && message->hwnd != active->edit
                && GetActiveWindow() == window
                && IsWindowEnabled(window)) {
            POINT point = POINT{ GET_X_LPARAM(message->lParam), GET_Y_LPARAM(message->lParam) };
            if (WindowFromPoint(point) == active->edit) {
                SendMessageW(active->edit, WM_MOUSEWHEEL, message->wParam, message->lParam);
                return true;
            }
        }
        return false;
    }
    return helpForm.Translate(message)
        || TranslateAcceleratorW(window, accelerators, message)
        || IsDialogMessageW(window, message);
}

/// Reports whether library initialization or a report operation is pending.
bool MainForm::HasPendingReports() const {
    return libraryLoading || reportThread != nullptr || printThread != nullptr;
}

/// Reports whether initial library discovery or a Preferences library change is in progress.
bool MainForm::IsLoadingLibrary() const {
    return libraryLoading;
}

/// Returns the native main-window handle.
HWND MainForm::GetWindow() const {
    return window;
}
