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
 * Last modified for version 1.2.1.2
 */

#include "Localization.h"
#include "MainForm.h"
#include "ModernPrintDialog.h"
#include "TabControl.h"
#include "SelectionEdit.h"
#include "SettingsStorage.h"
#include "resource.h"
#include <commctrl.h>
#include <commdlg.h>
#include <objbase.h>
#include <shellapi.h>
#include <windowsx.h>

/// Associates a menu command with its submenu and localized caption identifier.
struct MenuCaption {
    int menu;
    UINT id;
    TextId text;
};

/// Borrows a file path and owns availability data shared by the File menu and tab popup.
struct FileMenuContext {
    HMENU menu;
    const wchar_t* path;
    wchar_t folder[MAX_PATH];
    bool fileExists;
    bool folderExists;
};

/// Command captions refreshed when the interface language changes.
static const MenuCaption menuCaptions[] = {
    { 0, ID_FILE_OPEN, TXT_OPEN },
    { 0, ID_FILE_OPEN_FOLDER, TXT_OPEN_FOLDER },
    { 0, ID_FILE_CLOSE, TXT_CLOSE_TAB },
    { 0, ID_FILE_CLOSE_ALL, TXT_CLOSE_ALL },
    { 0, ID_FILE_EXPORT, TXT_EXPORT },
    { 0, ID_FILE_LAUNCH, TXT_LAUNCH_FILE },
    { 0, ID_FILE_SHOW_IN_FOLDER, TXT_SHOW_IN_CONTAINING_FOLDER },
    { 0, ID_FILE_PAGE_SETUP, TXT_PAGE_SETUP },
    { 0, ID_FILE_PRINT, TXT_PRINT },
    { 0, ID_FILE_EXIT, TXT_EXIT },
    { 1, ID_EDIT_COPY, TXT_COPY_SELECTION },
    { 1, ID_EDIT_SELECT_ALL, TXT_SELECT_ALL },
    { 1, ID_EDIT_FIND, TXT_FIND_MENU },
    { 1, ID_EDIT_FIND_NEXT, TXT_FIND_NEXT_MENU },
    { 1, ID_EDIT_FIND_PREVIOUS, TXT_FIND_PREVIOUS_MENU },
    { 1, ID_EDIT_COPY_FILE_NAME, TXT_COPY_FILE_NAME },
    { 1, ID_EDIT_COPY_FULL_PATH, TXT_COPY_FULL_PATH },
    { 2, ID_FULL_PARSING, TXT_FULL_PARSING },
    { 2, ID_ADVANCED_MODE, TXT_ADVANCED_MODE },
    { 2, ID_TRACE_LEVEL_0, TXT_TRACE_LEVEL_0 },
    { 2, ID_TRACE_LEVEL_5, TXT_TRACE_LEVEL_5 },
    { 2, ID_TRACE_LEVEL_9, TXT_TRACE_LEVEL_9 },
    { 2, ID_TRACE_LEVEL_10, TXT_TRACE_LEVEL_10 },
    { 2, ID_WORD_WRAP, TXT_WORD_WRAP },
    { 2, ID_PREFERENCES, TXT_PREFERENCES_MENU },
    { 3, ID_TOOLS_CREATE_HEADER, TXT_CREATE_HEADER },
    { 4, ID_HELP_CONTENTS, TXT_HELP },
    { 4, ID_HELP_FORMATS, TXT_KNOWN_FORMATS },
    { 4, ID_HELP_CODECS, TXT_KNOWN_CODECS },
    { 4, ID_HELP_PARAMETERS, TXT_KNOWN_PARAMETERS },
    { 4, ID_HELP_ABOUT, TXT_ABOUT }
};

/// Private messages for background completion, forwarded files and deferred library startup.
static const UINT reportCompleteMessage = WM_APP + 1;
static const UINT instanceFilesMessage = WM_APP + 3;
static const UINT initializeLibraryMessage = WM_APP + 4;
static const UINT printCompleteMessage = WM_APP + 5;

/// Command returned by the status pane context menu.
static const UINT statusCopyCommand = 1;

static HHOOK modalFindHook;
static MainForm* modalFindOwner;
static bool modalFindFiltering;

/// Reads the current availability of a file and its containing folder for either menu.
static void ReadFileMenuAvailability(FileMenuContext& context) {
    context.fileExists = false;
    context.folderExists = false;
    context.folder[0] = 0;
    if (!context.path || !context.path[0]) {
        return;
    }
    UINT previousMode = SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);
    DWORD attributes = GetFileAttributesW(context.path);
    context.fileExists = attributes != INVALID_FILE_ATTRIBUTES && !(attributes & FILE_ATTRIBUTE_DIRECTORY);
    wchar_t* name = nullptr;
    DWORD length = GetFullPathNameW(context.path, ARRAYSIZE(context.folder), context.folder, &name);
    if (length && length < ARRAYSIZE(context.folder) && name && *name) {
        name[0] = L'.';
        name[1] = 0;
        HANDLE directory = CreateFileW(context.folder, 0,
            FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
            nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, nullptr);
        if (directory != INVALID_HANDLE_VALUE) {
            BY_HANDLE_FILE_INFORMATION information = BY_HANDLE_FILE_INFORMATION{};
            context.folderExists = GetFileInformationByHandle(directory, &information)
                && information.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
            CloseHandle(directory);
        }
    }
    SetErrorMode(previousMode);
}

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
static bool SameReportFile(const BY_HANDLE_FILE_INFORMATION& first,
        const BY_HANDLE_FILE_INFORMATION& second) {
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
        : window(nullptr), tabs(nullptr), status(nullptr), searchWindow(nullptr), printOwner(nullptr),
        printDialog(nullptr), uiFont(nullptr), reportFont(nullptr), accelerators(nullptr),
        reportThread(nullptr), printThread(nullptr), files(nullptr), activeJob(nullptr),
        activePrintJob(nullptr), modernPrint(nullptr), tabMenuContext(nullptr), reportFontSpec(),
        reportFontDpi(96), nextId(1), tabNameLength(defaultTabNameLength),
        titleNameLength(defaultTitleNameLength), traceLevel(0), closing(false), printDialogOpen(false),
        libraryLoading(true), unicodeTabs(false), visualStylesActive(false), advancedMode(false),
        fullParsing(false), defaultWordWrap(false), closeTabsOnDoubleClick(false) {
    LoadReportOptionsSetting(fullParsing, advancedMode, traceLevel);
    defaultWordWrap = LoadWordWrapSetting();
    closeTabsOnDoubleClick = LoadCloseTabsOnDoubleClickSetting();
    LoadOpenFolderSetting(headerFolder, ARRAYSIZE(headerFolder));
}

/// Stops outstanding reports and releases tabs, fonts and other viewer-owned resources.
MainForm::~MainForm() {
    CloseModernPrint(modernPrint);
    modernPrint = nullptr;
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
    findForm.Close();
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
    cls.hIcon = LoadIconW(instance, MAKEINTRESOURCEW(IDI_MEDIAINFO));
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
    recentFiles.UpdateMenu(GetMenu(window));
    LoadFontSetting(&reportFontSpec, &reportFontDpi);
    tabNameLength = LoadTabNameLengthSetting();
    titleNameLength = LoadTitleNameLengthSetting();
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
    const TextId popups[] = {
        TXT_FILE_MENU,
        TXT_EDIT_MENU,
        TXT_OPTIONS_MENU,
        TXT_TOOLS_MENU,
        TXT_HELP_MENU
    };
    for (int index = 0; index < static_cast<int>(ARRAYSIZE(popups)); ++index) {
        ModifyMenuW(menu, index, MF_BYPOSITION | MF_POPUP,
            reinterpret_cast<UINT_PTR>(GetSubMenu(menu, index)), T(popups[index]));
    }
    for (int index = 0; index < static_cast<int>(sizeof(menuCaptions) / sizeof(menuCaptions[0])); ++index) {
        const MenuCaption& caption = menuCaptions[index];
        ModifyMenuW(GetSubMenu(menu, caption.menu), caption.id, MF_BYCOMMAND | MF_STRING, caption.id,
            T(caption.text));
    }
    DrawMenuBar(window);
    helpForm.RefreshLanguage();
    aboutForm.RefreshLanguage();
    findForm.RefreshLanguage();
    UpdateWindowTitle();
    UpdateStatus();
}

/// Refreshes caption icons and recreates the interface and report fonts for the current window DPI.
void MainForm::RebuildFonts() {
    UpdateWindowIcons(window, IDI_MEDIAINFO);
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
    bool wrap = active ? active->wordWrap : defaultWordWrap;
    UpdateEditMenu();
    EnableMenuItem(GetMenu(window), ID_WORD_WRAP,
        MF_BYCOMMAND | (active && !closing ? MF_ENABLED : MF_GRAYED));
    CheckMenuItem(GetMenu(window), ID_WORD_WRAP,
        MF_BYCOMMAND | (wrap ? MF_CHECKED : MF_UNCHECKED));
    const wchar_t* text = nullptr;
    if (closing) {
        text = T(TXT_WAITING_FOR_REPORT);
    } else if (printThread || modernPrint) {
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
    EnableMenuItem(GetMenu(window), ID_FILE_CLOSE, MF_BYCOMMAND | (active ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(GetMenu(window), ID_FILE_CLOSE_ALL, MF_BYCOMMAND | (files ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(GetMenu(window), ID_FILE_EXPORT,
        MF_BYCOMMAND | (active && active->ready ? MF_ENABLED : MF_GRAYED));
    bool printable = active && active->ready || !files && helpForm.GetWindow();
    EnableMenuItem(GetMenu(window), ID_FILE_PRINT,
        MF_BYCOMMAND | (printable && !closing && !printDialogOpen && !printThread && !modernPrint
            ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(GetMenu(window), ID_FILE_PAGE_SETUP,
        MF_BYCOMMAND | (printable && !closing && !printDialogOpen && !printThread && !modernPrint
            ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(GetMenu(window), ID_PREFERENCES,
        MF_BYCOMMAND | (HasPendingReports() ? MF_GRAYED : MF_ENABLED));
    EnableMenuItem(GetMenu(window), ID_ADVANCED_MODE,
        MF_BYCOMMAND | (HasPendingReports() ? MF_GRAYED : MF_ENABLED));
    CheckMenuItem(GetMenu(window), ID_ADVANCED_MODE,
        MF_BYCOMMAND | ((active ? active->advancedMode : advancedMode) ? MF_CHECKED : MF_UNCHECKED));
    EnableMenuItem(GetMenu(window), ID_FULL_PARSING,
        MF_BYCOMMAND | (HasPendingReports() ? MF_GRAYED : MF_ENABLED));
    CheckMenuItem(GetMenu(window), ID_FULL_PARSING,
        MF_BYCOMMAND | ((active ? active->fullParsing : fullParsing) ? MF_CHECKED : MF_UNCHECKED));
    CheckMenuRadioItem(GetSubMenu(GetMenu(window), 2), ID_TRACE_LEVEL_0, ID_TRACE_LEVEL_10,
        ID_TRACE_LEVEL_0 + (active ? active->traceLevel : traceLevel), MF_BYCOMMAND);
    for (UINT item = ID_TRACE_LEVEL_0; item <= ID_TRACE_LEVEL_10; ++item) {
        EnableMenuItem(GetMenu(window), item, MF_BYCOMMAND | (HasPendingReports() ? MF_GRAYED : MF_ENABLED));
    }
    InvalidateRect(status, nullptr, FALSE);
}

/// Selects the edit in the last active searchable form while retaining it during search-form input.
void MainForm::UpdateFindTarget() {
    HWND active = GetActiveWindow();
    if (active && (active == window || active == helpForm.GetWindow() || active == aboutForm.GetWindow())) {
        searchWindow = active;
    }
    HWND target = nullptr;
    if (!closing) {
        if (searchWindow && (searchWindow == helpForm.GetWindow() || searchWindow == aboutForm.GetWindow())) {
            target = GetDlgItem(searchWindow, IDC_INFO_TEXT);
        } else {
            searchWindow = window;
            FileTab* file = CurrentFile();
            target = file && file->ready ? file->edit : nullptr;
        }
    }
    findForm.SetTarget(target);
}

/// Routes search and print shortcuts from native modal loops.
LRESULT CALLBACK MainForm::ModalFindFilter(int code, WPARAM wParam, LPARAM lParam) {
    if (code == MSGF_DIALOGBOX && modalFindOwner && !modalFindFiltering) {
        modalFindFiltering = true;
        bool handled = modalFindOwner->Translate(reinterpret_cast<MSG*>(lParam));
        modalFindFiltering = false;
        if (handled) {
            return TRUE;
        }
    }
    return CallNextHookEx(modalFindHook, code, wParam, lParam);
}

/// Keeps modeless search input available while the modal About dialog is open.
void MainForm::ShowAbout() {
    modalFindOwner = this;
    modalFindHook = SetWindowsHookExW(WH_MSGFILTER, ModalFindFilter, nullptr, GetCurrentThreadId());
    if (!modalFindHook) {
        modalFindOwner = nullptr;
        MessageBoxW(window, T(TXT_FIND_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
        return;
    }
    aboutForm.Show(window);
    UnhookWindowsHookEx(modalFindHook);
    modalFindHook = nullptr;
    modalFindOwner = nullptr;
    UpdateFindTarget();
}

/// Shows Copy for the clicked status pane and copies its complete Unicode text.
void MainForm::ShowStatusContextMenu(POINT point) {
    POINT clientPoint = point;
    ScreenToClient(status, &clientPoint);
    int parts = static_cast<int>(SendMessageW(status, SB_GETPARTS, 0, 0));
    for (int part = 0; part < parts; ++part) {
        RECT bounds = RECT{};
        if (!SendMessageW(status, SB_GETRECT, part, reinterpret_cast<LPARAM>(&bounds))
                || !PtInRect(&bounds, clientPoint)) {
            continue;
        }
        const wchar_t* caption = reinterpret_cast<const wchar_t*>(SendMessageA(status, SB_GETTEXTA, part, 0));
        if (!caption) {
            return;
        }
        wchar_t text[MAX_PATH + 512];
        if (part == 0
                && activeJob
                && activeJob->command == LibraryCommand::Read
                && caption == T(TXT_LOADING)) {
            wsprintfW(text, T(TXT_LOADING_FILE), activeJob->path);
        } else {
            lstrcpynW(text, caption, ARRAYSIZE(text));
        }
        HMENU menu = CreatePopupMenu();
        if (!menu) {
            return;
        }
        AppendMenuW(menu, MF_STRING | (text[0] ? MF_ENABLED : MF_GRAYED), statusCopyCommand, T(TXT_COPY));
        UINT command = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, point.x, point.y, 0,
            window, nullptr);
        DestroyMenu(menu);
        if (command == statusCopyCommand && !CopyTextToClipboard(window, text)) {
            MessageBoxW(window, T(TXT_COPY_INFORMATION_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
        }
        return;
    }
}

/// Shows file commands for the tab header selected by the mouse or keyboard.
void MainForm::ShowTabContextMenu(POINT point) {
    int index = -1;
    if (point.x == -1 && point.y == -1) {
        index = TabCtrl_GetCurSel(tabs);
        RECT bounds = RECT{};
        if (index < 0 || !TabCtrl_GetItemRect(tabs, index, &bounds)) {
            return;
        }
        point = POINT{ bounds.left, bounds.bottom };
        ClientToScreen(tabs, &point);
    } else {
        TCHITTESTINFO hit = TCHITTESTINFO{};
        hit.pt = point;
        ScreenToClient(tabs, &hit.pt);
        index = TabCtrl_HitTest(tabs, &hit);
        if (index < 0 || !(hit.flags & TCHT_ONITEM)) {
            return;
        }
    }
    FileTab* file = files;
    for (int tab = 0; file && tab < index; ++tab) {
        file = file->next;
    }
    if (!file) {
        return;
    }
    wchar_t path[MAX_PATH] = L"";
    if (file->command == LibraryCommand::Read) {
        lstrcpynW(path, file->path, ARRAYSIZE(path));
    }
    HMENU menu = CreatePopupMenu();
    if (!menu) {
        return;
    }
    UINT copyFlags = MF_STRING | (path[0] ? MF_ENABLED : MF_GRAYED);
    AppendMenuW(menu, copyFlags, ID_EDIT_COPY_FILE_NAME, T(TXT_COPY_FILE_NAME));
    AppendMenuW(menu, copyFlags, ID_EDIT_COPY_FULL_PATH, T(TXT_COPY_FULL_PATH));
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING | MF_GRAYED, ID_FILE_LAUNCH, T(TXT_LAUNCH_FILE));
    AppendMenuW(menu, MF_STRING | MF_GRAYED, ID_FILE_SHOW_IN_FOLDER, T(TXT_SHOW_IN_CONTAINING_FOLDER));
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, ID_FILE_CLOSE, T(TXT_CLOSE_TAB_CONTEXT));
    FileMenuContext context = FileMenuContext{};
    context.menu = menu;
    context.path = path;
    tabMenuContext = &context;
    UINT command = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, point.x, point.y, 0,
        window, nullptr);
    tabMenuContext = nullptr;
    DestroyMenu(menu);
    if (command == ID_FILE_CLOSE) {
        CloseTab(index);
    } else if (command) {
        ExecuteFileCommand(command, path);
    }
}

/// Refreshes the file commands when the File menu or a tab popup opens.
void MainForm::InitializeFileMenu(HMENU menu) {
    FileMenuContext current = FileMenuContext{};
    FileMenuContext* context = tabMenuContext;
    if (!context || context->menu != menu) {
        FileTab* active = CurrentFile();
        if (active && active->command == LibraryCommand::Read) {
            current.path = active->path;
        }
        context = &current;
    }
    ReadFileMenuAvailability(*context);
    EnableMenuItem(menu, ID_FILE_LAUNCH, MF_BYCOMMAND | (context->fileExists ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(menu, ID_FILE_SHOW_IN_FOLDER,
        MF_BYCOMMAND | (context->folderExists ? MF_ENABLED : MF_GRAYED));
}

/// Executes a file command for the supplied tab path or the currently selected file tab.
void MainForm::ExecuteFileCommand(UINT command, const wchar_t* path) {
    if (!path) {
        FileTab* active = CurrentFile();
        if (!active || active->command != LibraryCommand::Read) {
            return;
        }
        path = active->path;
    }
    wchar_t selected[MAX_PATH];
    lstrcpynW(selected, path, ARRAYSIZE(selected));
    if (command == ID_EDIT_COPY_FILE_NAME || command == ID_EDIT_COPY_FULL_PATH) {
        wchar_t name[MAX_PATH];
        FormatFileNameCaption(selected, MAX_PATH, name, ARRAYSIZE(name));
        const wchar_t* text = command == ID_EDIT_COPY_FILE_NAME ? name : selected;
        if (!CopyTextToClipboard(window, text)) {
            MessageBoxW(window, T(TXT_COPY_INFORMATION_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
        }
        return;
    }
    FileMenuContext context = FileMenuContext{};
    context.path = selected;
    ReadFileMenuAvailability(context);
    if (command == ID_FILE_LAUNCH && context.fileExists) {
        OpenTabFile(selected, nullptr, true);
    } else if (command == ID_FILE_SHOW_IN_FOLDER && context.folderExists) {
        OpenTabFile(selected, context.folder, context.fileExists);
    }
}

/// Opens the file or its containing folder, selecting the file when it is available.
void MainForm::OpenTabFile(const wchar_t* path, const wchar_t* folder, bool selectFile) {
    SHELLEXECUTEINFOW execute = SHELLEXECUTEINFOW{};
    execute.cbSize = sizeof(execute);
    execute.fMask = SEE_MASK_FLAG_DDEWAIT;
    execute.hwnd = window;
    execute.lpFile = path;
    execute.nShow = SW_SHOWNORMAL;
    wchar_t explorer[MAX_PATH];
    wchar_t parameters[MAX_PATH + 12];
    if (folder) {
        UINT length = GetWindowsDirectoryW(explorer, ARRAYSIZE(explorer));
        if (!length || length + ARRAYSIZE(L"\\explorer.exe") > ARRAYSIZE(explorer)) {
            wchar_t error[MAX_PATH + 128];
            wsprintfW(error, T(TXT_FILE_OPEN_FAILED), path);
            MessageBoxW(window, error, L"MediaInfo", MB_OK | MB_ICONERROR);
            return;
        }
        lstrcatW(explorer, L"\\explorer.exe");
        if (selectFile) {
            wsprintfW(parameters, L"/select,\"%s\"", path);
        } else {
            wsprintfW(parameters, L"\"%s\"", folder);
        }
        execute.lpFile = explorer;
        execute.lpParameters = parameters;
    }
    HRESULT initialized = CoInitialize(nullptr);
    ShellExecuteExW(&execute);
    if (SUCCEEDED(initialized)) {
        CoUninitialize();
    }
}

/// Displays the selected report edit and refreshes its status information.
void MainForm::SelectTab(int index) {
    if (index >= 0) {
        TabCtrl_SetCurSel(tabs, index);
    }
    FileTab* selected = CurrentFile();
    UpdateWindowTitle();
    if (!UpdateSearchSelection()) {
        MessageBoxW(window, T(TXT_FIND_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
    }
    for (FileTab* file = files; file; file = file->next) {
        SetWindowPos(file->edit, HWND_TOP, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | (file == selected ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
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

/// Creates a report edit with the established selection handler and selected line-wrapping style.
HWND MainForm::CreateReportEdit(bool wordWrap, bool showSelection) {
    DWORD style = WS_CHILD
        | WS_TABSTOP
        | WS_CLIPSIBLINGS
        | WS_VSCROLL
        | ES_MULTILINE
        | ES_READONLY
        | ES_AUTOVSCROLL;
    if (!wordWrap) {
        style |= WS_HSCROLL | ES_AUTOHSCROLL;
    }
    if (showSelection) {
        style |= ES_NOHIDESEL;
    }
    HWND edit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"", style,
        0, 0, 1, 1, window, nullptr, GetModuleHandleW(nullptr), nullptr);
    if (!edit || !InstallSelectionEditHandler(edit)) {
        if (edit) {
            DestroyWindow(edit);
        }
        return nullptr;
    }
    SendMessageW(edit, WM_SETFONT, reinterpret_cast<WPARAM>(reportFont), FALSE);
    SendMessageW(edit, EM_SETLIMITTEXT, 0x7FFFFFFE, 0);
    return edit;
}

/// Replaces one native edit while preserving report text, selection, viewport and focus.
bool MainForm::ReplaceReportEdit(FileTab* file, bool wordWrap, bool showSelection) {
    HWND original = file->edit;
    HWND replacement = CreateReportEdit(wordWrap, showSelection);
    if (!replacement) {
        return false;
    }
    wchar_t* text = CopyControlText(original);
    if (!text) {
        DestroyWindow(replacement);
        return false;
    }
    RECT bounds = ControlRect(original, window);
    PlaceControl(replacement, bounds.left, bounds.top, bounds.right - bounds.left,
        bounds.bottom - bounds.top);
    BOOL copied = SetWindowTextW(replacement, text);
    HeapFree(GetProcessHeap(), 0, text);
    if (!copied) {
        DestroyWindow(replacement);
        return false;
    }
    DWORD start = 0;
    DWORD end = 0;
    SendMessageW(original, EM_GETSEL, reinterpret_cast<WPARAM>(&start), reinterpret_cast<LPARAM>(&end));
    LRESULT firstLine = SendMessageW(original, EM_GETFIRSTVISIBLELINE, 0, 0);
    LRESULT firstCharacter = SendMessageW(original, EM_LINEINDEX, firstLine, 0);
    int horizontal = GetScrollPos(original, SB_HORZ);
    SendMessageW(replacement, EM_SETSEL, start, end);
    if (firstCharacter >= 0) {
        LRESULT line = SendMessageW(replacement, EM_LINEFROMCHAR, firstCharacter, 0);
        LRESULT current = SendMessageW(replacement, EM_GETFIRSTVISIBLELINE, 0, 0);
        SendMessageW(replacement, EM_LINESCROLL, 0, line - current);
    }
    if (!wordWrap && !file->wordWrap && horizontal) {
        SendMessageW(replacement, WM_HSCROLL, MAKEWPARAM(SB_THUMBPOSITION, horizontal), 0);
    }
    bool focused = GetFocus() == original;
    bool visible = (GetWindowLongW(original, GWL_STYLE) & WS_VISIBLE) != 0;
    file->edit = replacement;
    file->wordWrap = wordWrap;
    findForm.ReplaceTarget(original, replacement);
    SetWindowPos(replacement, HWND_TOP, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | (visible ? SWP_SHOWWINDOW : 0));
    DestroyWindow(original);
    if (focused) {
        SetFocus(replacement);
    }
    return true;
}

/// Synchronizes report selection visibility after the modeless search form opens or closes.
LRESULT MainForm::HandleFindVisibility() {
    bool success = UpdateSearchSelection();
    UpdateStatus();
    return success;
}

/// Shows the active search selection while restoring normal hiding in all other report edits.
bool MainForm::UpdateSearchSelection() {
    FileTab* active = CurrentFile();
    bool success = true;
    for (FileTab* file = files; file; file = file->next) {
        bool show = findForm.GetWindow() && file == active;
        bool shown = (GetWindowLongW(file->edit, GWL_STYLE) & ES_NOHIDESEL) != 0;
        if (show != shown && !ReplaceReportEdit(file, file->wordWrap, show)) {
            success = false;
        }
    }
    return success;
}

/// Refreshes report-edit and focused-source search command availability before menus or shortcuts.
void MainForm::UpdateEditMenu() {
    UpdateFindTarget();
    FileTab* active = CurrentFile();
    DWORD start = 0;
    DWORD end = 0;
    int length = 0;
    if (active && active->ready && !closing) {
        SendMessageW(active->edit, EM_GETSEL, reinterpret_cast<WPARAM>(&start),
            reinterpret_cast<LPARAM>(&end));
        length = GetWindowTextLengthW(active->edit);
    }
    HMENU menu = GetMenu(window);
    EnableMenuItem(menu, ID_EDIT_COPY, MF_BYCOMMAND | (start != end ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(menu, ID_EDIT_SELECT_ALL,
        MF_BYCOMMAND | (length && (start || end < static_cast<DWORD>(length)) ? MF_ENABLED : MF_GRAYED));
    bool searchable = findForm.CanSearch();
    EnableMenuItem(menu, ID_EDIT_FIND, MF_BYCOMMAND | (searchable ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(menu, ID_EDIT_FIND_NEXT, MF_BYCOMMAND | (searchable ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(menu, ID_EDIT_FIND_PREVIOUS, MF_BYCOMMAND | (searchable ? MF_ENABLED : MF_GRAYED));
    bool file = active && active->command == LibraryCommand::Read && !closing;
    EnableMenuItem(menu, ID_EDIT_COPY_FILE_NAME, MF_BYCOMMAND | (file ? MF_ENABLED : MF_GRAYED));
    EnableMenuItem(menu, ID_EDIT_COPY_FULL_PATH, MF_BYCOMMAND | (file ? MF_ENABLED : MF_GRAYED));
}

/// Copies only the selected text of the active report through the native edit control.
void MainForm::CopySelection() {
    FileTab* active = CurrentFile();
    if (active && active->ready) {
        SendMessageW(active->edit, WM_COPY, 0, 0);
    }
}

/// Selects the entire active report and focuses its native edit control.
void MainForm::SelectAll() {
    FileTab* active = CurrentFile();
    if (active && active->ready) {
        SetFocus(active->edit);
        SendMessageW(active->edit, EM_SETSEL, 0, -1);
    }
}

/// Toggles wrapping only for the active tab and remembers the choice for new tabs.
void MainForm::ToggleWordWrap() {
    FileTab* file = CurrentFile();
    if (!file || closing) {
        return;
    }
    bool showSelection = (GetWindowLongW(file->edit, GWL_STYLE) & ES_NOHIDESEL) != 0;
    if (!ReplaceReportEdit(file, !file->wordWrap, showSelection)) {
        MessageBoxW(window, T(TXT_WORD_WRAP_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
    } else {
        defaultWordWrap = file->wordWrap;
        if (!SaveWordWrapSetting(defaultWordWrap)) {
            MessageBoxW(window, T(TXT_PREFERENCES_SAVE_FAILED), L"MediaInfo", MB_OK | MB_ICONWARNING);
        }
    }
    UpdateStatus();
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
    file->wordWrap = defaultWordWrap;
    if (path) {
        lstrcpyW(file->path, path);
    }
    file->id = nextId++;
    file->edit = CreateReportEdit(file->wordWrap, findForm.GetWindow() != nullptr);
    if (!file->edit) {
        HeapFree(GetProcessHeap(), 0, file);
        return false;
    }
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
    if (index == selected) {
        findForm.SetTarget(nullptr);
    }
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
    recentFiles.UpdateMenu(GetMenu(window));
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
    ShowPreferences(window, library, preferencesPlacement, &reportFontSpec, &reportFontDpi,
        nullptr, &callbacks);
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
    owner->recentFiles.UpdateMenu(GetMenu(owner->window));
    DrawMenuBar(owner->window);
    return saved;
}

/// Updates the window title from the active tab using its independent name-length limit.
void MainForm::UpdateWindowTitle() {
    FileTab* file = CurrentFile();
    if (!file) {
        SetWindowTextW(window, L"MediaInfo");
        return;
    }
    wchar_t caption[MAX_PATH + 16];
    if (file->command == LibraryCommand::Read) {
        FormatFileNameCaption(file->path, titleNameLength, caption, MAX_PATH);
    } else {
        FormatMiddleCaption(KnownInformationTitle(file->command), titleNameLength, false, caption, MAX_PATH);
    }
    lstrcatW(caption, L" \u2014 MediaInfo");
    SetWindowTextW(window, caption);
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
    owner->titleNameLength = changes.titleNameLength;
    owner->closeTabsOnDoubleClick = changes.closeTabsOnDoubleClick;
    owner->UpdateTabNames();
    if (changes.reportsChanged) {
        owner->RefreshReports(true);
    }
    owner->RebuildFonts();
    owner->ApplyLanguage();
    owner->Layout();
}

/// Exports the active report using the selected native file-dialog format.
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
        : SaveReportImage(active->edit, path, type, error, 512);
    if (saved) {
        SaveExportSetting(path, type);
    } else {
        MessageBoxW(window, error, L"MediaInfo", MB_OK | MB_ICONERROR);
    }
}

/// Opens the system printer dialog for a snapshot of the focused information edit.
void MainForm::PrintReport() {
    if (printDialogOpen || modernPrint) {
        ForegroundPrintDialog();
        return;
    }
    FileTab* active = CurrentFile();
    HWND focused = GetActiveWindow();
    bool about = focused && focused == aboutForm.GetWindow();
    bool help = focused && focused == helpForm.GetWindow() || !about && !files && helpForm.GetWindow();
    HWND dialog = about ? focused : window;
    HWND edit = nullptr;
    if (about) {
        edit = GetDlgItem(dialog, IDC_INFO_TEXT);
    } else if (help) {
        edit = GetDlgItem(helpForm.GetWindow(), IDC_INFO_TEXT);
    } else if (active && active->ready) {
        edit = active->edit;
    }
    if (closing || !edit || printThread) {
        return;
    }
    wchar_t aboutTitle[MAX_PATH] = L"";
    const wchar_t* title;
    if (about) {
        GetWindowTextW(dialog, aboutTitle, ARRAYSIZE(aboutTitle));
        title = aboutTitle;
    } else if (help) {
        title = T(TXT_HELP_TITLE);
    } else if (active->command == LibraryCommand::Read) {
        title = active->path;
    } else {
        title = KnownInformationTitle(active->command);
    }
    printOwner = dialog;
    if (UseModernPrintDialog()) {
        PrintJob* snapshot = CapturePrintJob(window, edit, title, printSettings.GetMargins());
        modernPrint = snapshot ? CreateModernPrint(snapshot, printSettings) : nullptr;
        HRESULT result = modernPrint ? ShowModernPrint(modernPrint, dialog) : E_OUTOFMEMORY;
        if (FAILED(result)) {
            CloseModernPrint(modernPrint);
            modernPrint = nullptr;
            printOwner = nullptr;
            if (result != HRESULT_FROM_WIN32(ERROR_CANCELLED)) {
                MessageBoxW(dialog, T(TXT_PRINT_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
            }
        }
        UpdateStatus();
        return;
    }
    wchar_t error[512];
    printDialogOpen = true;
    UpdateStatus();
    bool ownHook = !modalFindHook;
    if (ownHook) {
        modalFindOwner = this;
        modalFindHook = SetWindowsHookExW(WH_MSGFILTER, ModalFindFilter, nullptr, GetCurrentThreadId());
        if (!modalFindHook) {
            modalFindOwner = nullptr;
            printDialogOpen = false;
            printOwner = nullptr;
            UpdateStatus();
            MessageBoxW(dialog, T(TXT_PRINT_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
            return;
        }
    }
    bool filtering = modalFindFiltering;
    modalFindFiltering = false;
    PrintJob* job = ChooseReportPrinter(dialog, edit, title,
        printSettings, error, ARRAYSIZE(error));
    modalFindFiltering = filtering;
    if (ownHook) {
        UnhookWindowsHookEx(modalFindHook);
        modalFindHook = nullptr;
        modalFindOwner = nullptr;
    }
    printDialogOpen = false;
    printOwner = nullptr;
    printDialog = nullptr;
    if (closing || !window) {
        FreePrintJob(job);
        return;
    }
    if (!job) {
        UpdateStatus();
        if (error[0]) {
            MessageBoxW(window, error, L"MediaInfo", MB_OK | MB_ICONERROR);
        }
        return;
    }
    job->target = window;
    printThread = CreateThread(nullptr, 0, PrintDocument, job, 0, nullptr);
    if (!printThread) {
        FreePrintJob(job);
        MessageBoxW(window, T(TXT_PRINT_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
        return;
    }
    activePrintJob = job;
    UpdateStatus();
}

/// Locates the enabled print popup while excluding the application's information forms.
BOOL CALLBACK MainForm::FindPrintDialog(HWND candidate, LPARAM parameter) {
    MainForm* owner = reinterpret_cast<MainForm*>(parameter);
    if (candidate == owner->window
            || candidate == owner->helpForm.GetWindow()
            || candidate == owner->aboutForm.GetWindow()
            || candidate == owner->findForm.GetWindow()
            || !IsWindowVisible(candidate)
            || !IsWindowEnabled(candidate)) {
        return TRUE;
    }
    HWND parent = ::GetWindow(candidate, GW_OWNER);
    while (parent) {
        if (parent == owner->printOwner) {
            owner->printDialog = candidate;
            return FALSE;
        }
        if (parent == owner->helpForm.GetWindow()
                || parent == owner->aboutForm.GetWindow()
                || parent == owner->findForm.GetWindow()) {
            break;
        }
        parent = ::GetWindow(parent, GW_OWNER);
    }
    return TRUE;
}

/// Finds the open print dialog and requests foreground focus without creating another print job.
void MainForm::ForegroundPrintDialog() {
    printDialog = nullptr;
    EnumWindows(FindPrintDialog, reinterpret_cast<LPARAM>(this));
    if (printDialog) {
        SetForegroundWindow(printDialog);
    }
}

/// Opens Page Setup for printable content and prevents overlapping print dialogs.
void MainForm::PageSetup() {
    FileTab* active = CurrentFile();
    bool printable = active && active->ready || !files && helpForm.GetWindow();
    if (closing || printDialogOpen || printThread || modernPrint || !printable) {
        return;
    }
    wchar_t error[512];
    printDialogOpen = true;
    UpdateStatus();
    bool accepted = printSettings.PageSetup(window, error, ARRAYSIZE(error));
    printDialogOpen = false;
    UpdateStatus();
    if (!accepted && error[0]) {
        MessageBoxW(window, error, L"MediaInfo", MB_OK | MB_ICONERROR);
    }
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

/// Collects a modern print completion and releases its retained references.
void MainForm::CompleteModernPrint(ModernPrintDialog* source) {
    if (source != modernPrint) {
        ReleaseModernPrint(source);
        return;
    }
    bool failed = CloseModernPrint(modernPrint);
    modernPrint = nullptr;
    printOwner = nullptr;
    printDialog = nullptr;
    ReleaseModernPrint(source);
    UpdateStatus();
    if (failed && !closing) {
        MessageBoxW(window, T(TXT_PRINT_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
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
                if (file == CurrentFile()) {
                    findForm.SetTarget(nullptr);
                }
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
            if (file == CurrentFile()) {
                findForm.SetTarget(nullptr);
            }
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

/// Copies and queues the validated file list received from another viewer instance.
LRESULT MainForm::HandleCopyData(LPARAM lParam) {
    const COPYDATASTRUCT* request = reinterpret_cast<const COPYDATASTRUCT*>(lParam);
    if (closing || !ValidateInstanceFiles(request)) {
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

/// Activates the viewer, opens the queued instance paths and releases their buffer.
LRESULT MainForm::HandleInstanceFiles(LPARAM lParam) {
    wchar_t* paths = reinterpret_cast<wchar_t*>(lParam);
    placement.BringToFront();
    const wchar_t* path = paths;
    while (*path) {
        AddFile(path);
        path += lstrlenW(path) + 1;
    }
    HeapFree(GetProcessHeap(), 0, paths);
    return 0;
}

/// Handles status menus, tab selection and Unicode or ANSI tab tooltips.
LRESULT MainForm::HandleNotification(WPARAM wParam, LPARAM lParam) {
    NMHDR* notification = reinterpret_cast<NMHDR*>(lParam);
    if (notification->hwndFrom == status && notification->code == NM_RCLICK) {
        DWORD position = GetMessagePos();
        POINT point = POINT{ GET_X_LPARAM(position), GET_Y_LPARAM(position) };
        ShowStatusContextMenu(point);
        return TRUE;
    }
    if (notification->hwndFrom == tabs && notification->code == TCN_SELCHANGE) {
        SelectTab(TabCtrl_GetCurSel(tabs));
        return 0;
    }
    if ((notification->code == TTN_GETDISPINFOW || notification->code == TTN_GETDISPINFOA)
            && notification->hwndFrom == TabCtrl_GetToolTips(tabs)) {
        FileTab* file = files;
        for (UINT_PTR index = 0; file && index < notification->idFrom; ++index) {
            file = file->next;
        }
        RECT bounds = RECT{};
        GetWindowRect(window, &bounds);
        RECT work = WindowWorkArea(bounds);
        SendMessageW(notification->hwndFrom, TTM_SETMAXTIPWIDTH, 0, work.right - work.left);
        const wchar_t* tooltip = nullptr;
        if (file) {
            tooltip = file->command == LibraryCommand::Read
                ? file->path
                : KnownInformationTitle(file->command);
        }
        if (notification->code == TTN_GETDISPINFOW) {
            reinterpret_cast<NMTTDISPINFOW*>(lParam)->lpszText = const_cast<wchar_t*>(tooltip);
        } else {
            tabTooltipPath[0] = 0;
            if (tooltip) {
                WideCharToMultiByte(CP_ACP, 0, tooltip, -1, tabTooltipPath,
                    sizeof(tabTooltipPath), nullptr, nullptr);
            }
            reinterpret_cast<NMTTDISPINFOA*>(lParam)->lpszText = tabTooltipPath;
        }
        return 0;
    }
    return DefWindowProcW(window, WM_NOTIFY, wParam, lParam);
}

/// Paints the empty workspace without changing the report controls.
LRESULT MainForm::HandlePaint() {
    PAINTSTRUCT paint = PAINTSTRUCT{};
    HDC dc = BeginPaint(window, &paint);
    if (!files) {
        FillRect(dc, &paint.rcPaint, GetSysColorBrush(COLOR_APPWORKSPACE));
    }
    EndPaint(window, &paint);
    return 0;
}

/// Draws the status pane with the current loading text and width-aware path caption.
LRESULT MainForm::HandleDrawItem(WPARAM wParam, LPARAM lParam) {
    DRAWITEMSTRUCT* item = reinterpret_cast<DRAWITEMSTRUCT*>(lParam);
    if (item->hwndItem == status) {
        HGDIOBJ old = SelectObject(item->hDC, uiFont);
        TEXTMETRICW metrics = TEXTMETRICW{};
        GetTextMetricsW(item->hDC, &metrics);
        RECT text = item->rcItem;
        int borders[3] = {};
        SendMessageW(status, SB_GETBORDERS, 0, reinterpret_cast<LPARAM>(borders));
        text.left += borders[2];
        int parts = static_cast<int>(SendMessageW(status, SB_GETPARTS, 0, 0));
        if (item->itemID + 1 == static_cast<UINT>(parts)) {
            text.right -= GetSystemMetrics(SM_CXVSCROLL);
        }
        text.top += (text.bottom - text.top - metrics.tmHeight) / 2;
        SetTextColor(item->hDC, GetSysColor(COLOR_BTNTEXT));
        SetBkMode(item->hDC, TRANSPARENT);
        const wchar_t* caption = reinterpret_cast<const wchar_t*>(item->itemData);
        FileTab* active = item->itemID == 0 ? CurrentFile() : nullptr;
        const wchar_t* loadingFormat = item->itemID == 0
            && activeJob
            && activeJob->command == LibraryCommand::Read
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
            FormatPathCaption(item->hDC, loadingFormat ? activeJob->path : caption, width, pathCaption,
                ARRAYSIZE(pathCaption));
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
    return DefWindowProcW(window, WM_DRAWITEM, wParam, lParam);
}

/// Opens the dropped files and releases the native drop handle.
LRESULT MainForm::HandleDropFiles(WPARAM wParam) {
    HDROP drop = reinterpret_cast<HDROP>(wParam);
    UINT count = DragQueryFileW(drop, 0xFFFFFFFF, nullptr, 0);
    for (UINT index = 0; index < count; ++index) {
        wchar_t path[MAX_PATH];
        UINT length = DragQueryFileW(drop, index, nullptr, 0);
        if (length < MAX_PATH && DragQueryFileW(drop, index, path, MAX_PATH)) {
            AddFile(path);
        }
    }
    DragFinish(drop);
    return 0;
}

/// Applies the suggested window bounds and rebuilds fonts and layout for the new DPI.
LRESULT MainForm::HandleDpiChange(LPARAM lParam) {
    RECT* bounds = reinterpret_cast<RECT*>(lParam);
    SetWindowPos(window, nullptr, bounds->left, bounds->top, bounds->right - bounds->left,
        bounds->bottom - bounds->top, SWP_NOZORDER | SWP_NOACTIVATE);
    RebuildFonts();
    Layout();
    return 0;
}

/// Releases pending print and instance requests, closes information forms and ends the message loop.
LRESULT MainForm::HandleDestroy() {
    CloseModernPrint(modernPrint);
    modernPrint = nullptr;
    MSG pending = MSG{};
    while (PeekMessageW(&pending, window, modernPrintCompleteMessage, modernPrintCompleteMessage,
            PM_REMOVE)) {
        ReleaseModernPrint(reinterpret_cast<ModernPrintDialog*>(pending.lParam));
    }
    while (PeekMessageW(&pending, window, instanceFilesMessage, instanceFilesMessage, PM_REMOVE)) {
        HeapFree(GetProcessHeap(), 0, reinterpret_cast<void*>(pending.lParam));
    }
    helpForm.Close();
    aboutForm.Close();
    findForm.Close();
    PostQuitMessage(0);
    return 0;
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
            return owner->HandleCopyData(lParam);
        case instanceFilesMessage:
            return owner->HandleInstanceFiles(lParam);
        case WM_SIZE:
            owner->Layout();
            return 0;
        case findVisibilityChangedMessage:
            return owner->HandleFindVisibility();
        case helpVisibilityChangedMessage:
            owner->UpdateStatus();
            return 0;
        case findMatchMessage:
            if (reinterpret_cast<HWND>(wParam) == owner->helpForm.GetWindow()) {
                owner->helpForm.Reveal(reinterpret_cast<HWND>(lParam));
            } else if (reinterpret_cast<HWND>(wParam) == owner->aboutForm.GetWindow()) {
                SetWindowPos(owner->aboutForm.GetWindow(), HWND_TOP, 0, 0, 0, 0,
                    SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
                SetWindowPos(reinterpret_cast<HWND>(lParam), HWND_TOP, 0, 0, 0, 0,
                    SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            } else {
                owner->placement.SetVisible(reinterpret_cast<HWND>(lParam));
            }
            return 0;
        case WM_INITMENUPOPUP:
            if (reinterpret_cast<HMENU>(wParam) == GetSubMenu(GetMenu(window), 0)
                || owner->tabMenuContext
                    && reinterpret_cast<HMENU>(wParam) == owner->tabMenuContext->menu) {
                owner->InitializeFileMenu(reinterpret_cast<HMENU>(wParam));
                return 0;
            }
            if (reinterpret_cast<HMENU>(wParam) == GetSubMenu(GetMenu(window), 1)) {
                owner->UpdateEditMenu();
                return 0;
            }
            break;
        case WM_CONTEXTMENU:
            if (reinterpret_cast<HWND>(wParam) == owner->tabs) {
                POINT point = POINT{ GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
                owner->ShowTabContextMenu(point);
                return 0;
            }
            break;
        case WM_NOTIFY:
            return owner->HandleNotification(wParam, lParam);
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
            return owner->HandlePaint();
        case WM_DRAWITEM:
            return owner->HandleDrawItem(wParam, lParam);
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
                            owner->recentFiles.UpdateMenu(GetMenu(window));
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
                case ID_FILE_LAUNCH:
                case ID_FILE_SHOW_IN_FOLDER:
                case ID_EDIT_COPY_FILE_NAME:
                case ID_EDIT_COPY_FULL_PATH:
                    owner->ExecuteFileCommand(LOWORD(wParam));
                    return 0;
                case ID_FILE_PRINT:
                    owner->PrintReport();
                    return 0;
                case ID_FILE_PAGE_SETUP:
                    owner->PageSetup();
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
                case ID_EDIT_COPY:
                    owner->CopySelection();
                    return 0;
                case ID_EDIT_SELECT_ALL:
                    owner->SelectAll();
                    return 0;
                case ID_EDIT_FIND:
                    owner->UpdateFindTarget();
                    owner->findForm.Show(window);
                    return 0;
                case ID_EDIT_FIND_NEXT:
                    owner->UpdateFindTarget();
                    owner->findForm.FindNext(window, false);
                    return 0;
                case ID_EDIT_FIND_PREVIOUS:
                    owner->UpdateFindTarget();
                    owner->findForm.FindNext(window, true);
                    return 0;
                case ID_WORD_WRAP:
                    owner->ToggleWordWrap();
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
                    owner->ShowAbout();
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
        case tabDoubleClickMessage:
            if (reinterpret_cast<HWND>(lParam) == owner->tabs && owner->closeTabsOnDoubleClick) {
                owner->CloseTab(static_cast<int>(wParam));
                return TRUE;
            }
            return 0;
        case WM_DROPFILES:
            return owner->HandleDropFiles(wParam);
        case WM_SYSCOLORCHANGE:
            RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
            return 0;
        case WM_SETTINGCHANGE:
        case WM_THEMECHANGED:
        case WM_DISPLAYCHANGE:
            owner->visualStylesActive = AreVisualStylesActive();
            owner->RebuildFonts();
            owner->Layout();
            RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
            return 0;
        case WM_DPICHANGED:
            return owner->HandleDpiChange(lParam);
        case WM_QUERYENDSESSION:
            return TRUE;
        case WM_CLOSE:
            CloseModernPrint(owner->modernPrint);
            owner->modernPrint = nullptr;
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
            return owner->HandleDestroy();
        case WM_NCDESTROY:
            ClearWindowIcons(window);
            owner->window = nullptr;
            break;
        default:
            if (message == modernPrintCompleteMessage) {
                owner->CompleteModernPrint(reinterpret_cast<ModernPrintDialog*>(lParam));
                return 0;
            }
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
    UpdateFindTarget();
    HWND activeWindow = GetActiveWindow();
    if (message->message == WM_KEYDOWN
        && activeWindow
        && (activeWindow == window
            || activeWindow == helpForm.GetWindow()
            || activeWindow == aboutForm.GetWindow())) {
        if (message->wParam == L'F' && GetKeyState(VK_CONTROL) & 0x8000) {
            findForm.Show(window);
            return true;
        }
        if (message->wParam == L'P' && GetKeyState(VK_CONTROL) & 0x8000) {
            PrintReport();
            return true;
        }
        if (message->wParam == VK_F3) {
            findForm.FindNext(window, (GetKeyState(VK_SHIFT) & 0x8000) != 0);
            return true;
        }
    }
    if (message->message == WM_KEYDOWN
            && GetActiveWindow() == window
            && (message->wParam == L'C' || message->wParam == L'A')
            && GetKeyState(VK_CONTROL) & 0x8000) {
        UpdateEditMenu();
    }
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
    if (findForm.Translate(message) || helpForm.Translate(message)) {
        return true;
    }
    if (message->hwnd != window && !IsChild(window, message->hwnd)) {
        return false;
    }
    return TranslateAcceleratorW(window, accelerators, message)
        || IsDialogMessageW(window, message);
}

/// Reports whether library initialization or a report operation is pending.
bool MainForm::HasPendingReports() const {
    return libraryLoading
        || reportThread != nullptr
        || printDialogOpen
        || printThread != nullptr
        || modernPrint != nullptr;
}

/// Reports whether initial library discovery or a Preferences library change is in progress.
bool MainForm::IsLoadingLibrary() const {
    return libraryLoading;
}

/// Returns the native main-window handle.
HWND MainForm::GetWindow() const {
    return window;
}
