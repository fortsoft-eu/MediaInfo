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
 * Last modified for version 1.2.1.4
 */

#pragma once

#include "MediaInfo.h"
#include "MediaInfoLibrary.h"
#include "PersistWindowState.h"
#include "AboutForm.h"
#include "HelpForm.h"
#include "FindForm.h"
#include "RecentFiles.h"
#include "PrintSettings.h"

/// Temporary context owned by the active tab popup.
struct FileMenuContext;
class ModernPrintDialog;
struct IUnknown;

/// Symbols used while compiling for the Windows NT 4.0 API target.
#ifndef IDC_HAND
#define IDC_HAND MAKEINTRESOURCE(32649)
#endif

#ifndef ICC_LINK_CLASS
#define ICC_LINK_CLASS 0x00008000
#endif

#ifndef WC_LINK
#define WC_LINK L"SysLink"
#endif

#ifndef LM_GETIDEALHEIGHT
#define LM_GETIDEALHEIGHT (WM_USER+0x301)
#endif

#ifndef LM_GETIDEALSIZE
#define LM_GETIDEALSIZE (LM_GETIDEALHEIGHT)
#endif

#ifndef WM_THEMECHANGED
#define WM_THEMECHANGED 0x031A
#endif

#ifndef WM_DPICHANGED
#define WM_DPICHANGED 0x02E0
#endif

/// Report-cache slots for two parsing flags combined with four trace levels.
static const UINT reportVariantCount = 16;

/// Owns one report tab, its cached variants and the metadata used to detect source-file changes.
struct FileTab {
    HWND edit;
    FileTab* next;
    wchar_t* report;
    BYTE* richText;
    ULONG richTextSize;
    HRESULT(*formatLayout)(const PrintJob* job, IUnknown* layout, IUnknown* context, UINT start, UINT length);
    wchar_t* reports[reportVariantCount];
    BY_HANDLE_FILE_INFORMATION source;
    wchar_t path[MAX_PATH];
    wchar_t error[512];
    UINT id;
    UINT traceLevel;
    LibraryCommand command;
    bool sourceKnown;
    bool advancedMode;
    bool fullParsing;
    bool started;
    bool ready;
    bool refreshing;
    bool wordWrap;
};

/// Carries one report request and its result between the viewer and its background thread.
struct ReportJob {
    HWND target;
    MediaInfoLibrary* library;
    wchar_t* report;
    BYTE* richText;
    ULONG richTextSize;
    HRESULT(*formatLayout)(const PrintJob* job, IUnknown* layout, IUnknown* context, UINT start, UINT length);
    BY_HANDLE_FILE_INFORMATION source;
    wchar_t path[MAX_PATH];
    wchar_t error[512];
    UINT id;
    UINT traceLevel;
    LibraryCommand command;
    bool sourceKnown;
    bool success;
    bool advancedMode;
    bool fullParsing;
};

/// Owns a printer context and a report snapshot for one cancellable background print job.
struct PrintJob {
    HWND target;
    HDC printer;
    wchar_t* report;
    BYTE* richText;
    ULONG richTextSize;
    HRESULT(*formatLayout)(const PrintJob* job, IUnknown* layout, IUnknown* context, UINT start, UINT length);
    LOGFONTW font;
    RECT margins;
    UINT fontDpi;
    wchar_t title[MAX_PATH];
    volatile LONG canceled;
    bool printToFile;
    bool success;
};

/// Identifies committed preferences that require refreshing reports, tab captions or the window title.
struct PreferencesChanges {
    bool reportsChanged;
    UINT tabNameLength;
    UINT titleNameLength;
    bool closeTabsOnDoubleClick;
};

/// Connects the modal Preferences dialog to viewer state and immediate recent-file actions.
struct PreferencesCallbacks {
    /// Caller-owned state passed to every Preferences callback.
    void* context;

    /// Applies committed settings to the viewer.
    void(*applied)(void* context, const PreferencesChanges& changes);

    /// Reports whether current work prevents replacing the library.
    bool(*busy)(void* context);

    /// Reports whether the recent-file list can be cleared.
    bool(*hasRecentFiles)(void* context);

    /// Clears recent files immediately and reports whether their saved state was updated.
    bool(*clearRecentFiles)(void* context);

    /// Publishes the start or end of library loading to the viewer.
    void(*loading)(void* context, bool loading);
};

/// Owns the main viewer, report tabs and asynchronous report and print jobs.
class MainForm {

private:
    /// Main window and native child controls.
    HWND window;
    HWND tabs;
    HWND status;
    HWND lastFocusedControl;
    HWND searchWindow;
    HWND printOwner;
    HWND printDialog;

    /// Native fonts, accelerators and background-thread handles.
    HFONT uiFont;
    HFONT reportFont;
    HACCEL accelerators;
    HANDLE reportThread;
    HANDLE printThread;

    /// Library connection, information forms, placement and recent-file history.
    MediaInfoLibrary library;
    PersistWindowState placement;
    PersistWindowState preferencesPlacement;
    HelpForm helpForm;
    AboutForm aboutForm;
    FindForm findForm;
    RecentFiles recentFiles;
    PrintSettings printSettings;

    /// Owned tab records and the currently active report and print requests.
    FileTab* files;
    ReportJob* activeJob;
    PrintJob* activePrintJob;
    ModernPrintDialog* modernPrint;

    /// Borrows the context while the native tab popup is active.
    FileMenuContext* tabMenuContext;

    /// Report font, caption preferences and identifiers for queued work.
    LOGFONTW reportFontSpec;
    UINT reportFontDpi;
    UINT nextId;
    UINT tabNameLength;
    UINT titleNameLength;
    UINT traceLevel;

    /// Shutdown, loading, theme and report-option state.
    bool closing;
    bool printDialogOpen;
    bool libraryLoading;
    bool unicodeTabs;
    bool visualStylesActive;
    bool advancedMode;
    bool fullParsing;
    bool defaultWordWrap;
    bool closeTabsOnDoubleClick;

    /// Session-only header-tool folder and the ANSI tab-tooltip conversion buffer.
    wchar_t headerFolder[MAX_PATH];
    char tabTooltipPath[MAX_PATH * 4];

    /// Creates the status bar and tabs and loads the interface and report preferences.
    bool Initialize();

    /// Finds and loads a compatible library after the main window and its status bar are visible.
    void InitializeLibrary();

    /// Refreshes caption icons and recreates the interface and report fonts for the current window DPI.
    void RebuildFonts();

    /// Refreshes main-menu captions, recent files and information windows for the active interface language.
    void ApplyLanguage();

    /// Fits the status bar and tab workspace to the current main-window client area.
    void Layout();

    /// Places current paths and messages on the left and shows the loaded DLL version when space permits.
    void UpdateStatus();

    /// Restores focus to the previous available child control or the active report edit.
    void RestoreFocus();

    /// Selects the edit in the last active searchable form while retaining it during search-form input.
    void UpdateFindTarget();

    /// Keeps modeless search input available while the modal About dialog is open.
    void ShowAbout();

    /// Routes search and print shortcuts from native modal loops.
    static LRESULT CALLBACK ModalFindFilter(int code, WPARAM wParam, LPARAM lParam);

    /// Shows Copy for the clicked status pane and copies its complete Unicode text.
    void ShowStatusContextMenu(POINT point);

    /// Shows file commands for the tab header selected by the mouse or keyboard.
    void ShowTabContextMenu(POINT point);

    /// Refreshes the file commands when the File menu or a tab popup opens.
    void InitializeFileMenu(HMENU menu);

    /// Executes a file command for the supplied tab path or the currently selected file tab.
    void ExecuteFileCommand(UINT command, const wchar_t* path = nullptr);

    /// Opens the file or its containing folder, selecting the file when it is available.
    void OpenTabFile(const wchar_t* path, const wchar_t* folder, bool selectFile);

    /// Displays the selected report edit and refreshes its status information.
    void SelectTab(int index);

    /// Removes one file tab and its report data, then selects the remaining active report.
    void CloseTab(int index = -1);

    /// Closes every file tab and returns the viewer to its empty workspace.
    void CloseAllTabs();

    /// Moves a successfully opened file to the recent-files list and refreshes its menu.
    void RememberFile(const wchar_t* path);

    /// Selects an adjacent tab with wraparound for keyboard tab navigation.
    void SwitchTab(int direction);

    /// Opens the native media-file picker and processes its selected paths in order.
    void OpenFiles();

    /// Opens files directly inside the selected folder, reusing existing tabs.
    void OpenFolder();

    /// Changes only the active tab's report options and saves the complete combination for new tabs.
    void ChangeReportOptions(UINT command);

    /// Refreshes the active variant or invalidates and refreshes every tab after a library change.
    void RefreshReports(bool discardCached = false);

    /// Selects a matching file or information tab through the shared activation path.
    bool SelectExistingTab(LibraryCommand command, const wchar_t* path);

    /// Creates a report edit with the established selection handler and selected line-wrapping style.
    HWND CreateReportEdit(bool wordWrap, bool showSelection = false);

    /// Replaces one native edit while preserving report text, selection, viewport and focus.
    bool ReplaceReportEdit(FileTab* file, bool wordWrap, bool showSelection);

    /// Synchronizes report selection visibility after the modeless search form opens or closes.
    LRESULT HandleFindVisibility();

    /// Shows the active search selection while restoring normal hiding in all other report edits.
    bool UpdateSearchSelection();

    /// Refreshes report-edit and focused-source search command availability before menus or shortcuts.
    void UpdateEditMenu();

    /// Copies only the selected text of the active report through the native edit control.
    void CopySelection();

    /// Selects the entire active report and focuses its native edit control.
    void SelectAll();

    /// Toggles wrapping only for the active tab and remembers the choice for new tabs.
    void ToggleWordWrap();

    /// Creates the common report edit and tab and queues the selected library operation.
    bool CreateTab(LibraryCommand command, const wchar_t* path);

    /// Opens or activates a library-supplied information list in the main report workspace.
    void ShowKnownInformation(LibraryCommand command);

    /// Shows modal Preferences with callbacks that apply changes to the live viewer.
    void Preferences();

    /// Updates the window title from the active tab using its independent name-length limit.
    void UpdateWindowTitle();

    /// Applies the configured filename-length limit to every open tab caption.
    void UpdateTabNames();

    /// Applies committed interface, font and caption settings and invalidates reports after library changes.
    static void PreferencesApplied(void* context, const PreferencesChanges& changes);

    /// Reports whether library initialization or report work prevents replacement of the active library.
    static bool PreferencesBusy(void* context);

    /// Publishes library-loading progress while Preferences replaces the current library.
    static void PreferencesLoading(void* context, bool loading);

    /// Reports whether the viewer has any recent files available to clear.
    static bool PreferencesHasRecentFiles(void* context);

    /// Immediately clears saved and live recent files and refreshes the main menu.
    static bool PreferencesClearRecentFiles(void* context);

    /// Exports the active report using the selected native file-dialog format.
    void ExportReport();

    /// Opens the system printer dialog for a snapshot of the focused information edit.
    void PrintReport();

    /// Finds the open print dialog and requests foreground focus without creating another print job.
    void ForegroundPrintDialog();

    /// Locates the enabled print popup while excluding the application's information forms.
    static BOOL CALLBACK FindPrintDialog(HWND candidate, LPARAM parameter);

    /// Opens Page Setup for printable content and prevents overlapping print dialogs.
    void PageSetup();

    /// Prints the selected report on its worker thread and posts the result to the viewer.
    static DWORD WINAPI PrintDocument(void* parameter);

    /// Collects the finished print job and releases its snapshot and printer context.
    void CompletePrint(PrintJob* job);

    /// Collects a modern print completion and releases its retained references.
    void CompleteModernPrint(ModernPrintDialog* source);

    /// Starts the next queued report when no report thread is already active.
    void StartNextReport();

    /// Collects a completed report, updates its tab and advances the remaining report queue.
    void CompleteReport(ReportJob* job);

    /// Returns the file record attached to the selected tab, or null when no file is open.
    FileTab* CurrentFile() const;

    /// Reads the requested file report on the background thread and posts its completion to the viewer.
    static DWORD WINAPI ReadReport(void* parameter);

    /// Copies and queues the validated file list received from another viewer instance.
    LRESULT HandleCopyData(LPARAM lParam);

    /// Activates the viewer, opens the queued instance paths and releases their buffer.
    LRESULT HandleInstanceFiles(LPARAM lParam);

    /// Handles status menus, tab selection and Unicode or ANSI tab tooltips.
    LRESULT HandleNotification(WPARAM wParam, LPARAM lParam);

    /// Paints the empty workspace without changing the report controls.
    LRESULT HandlePaint();

    /// Draws the status pane with the current loading text and width-aware path caption.
    LRESULT HandleDrawItem(WPARAM wParam, LPARAM lParam);

    /// Opens the dropped files and releases the native drop handle.
    LRESULT HandleDropFiles(WPARAM wParam);

    /// Applies the suggested window bounds and rebuilds fonts and layout for the new DPI.
    LRESULT HandleDpiChange(LPARAM lParam);

    /// Releases pending print and instance requests, closes information forms and ends the message loop.
    LRESULT HandleDestroy();

    /// Dispatches native main-window input, layout, file, menu and asynchronous report messages.
    static LRESULT CALLBACK WindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

public:
    /// Initializes the viewer window, file lists, fonts and report-worker state.
    MainForm();

    /// Stops outstanding reports and releases tabs, fonts and other viewer-owned resources.
    ~MainForm();

    /// Creates the native main window with its saved placement and queues initial library discovery.
    bool Create();

    /// Displays the main window and its library-loading status through the persisted placement state.
    void Show();

    /// Selects an existing file tab or creates a new tab and queues its MediaInfo report.
    bool AddFile(const wchar_t* filename);

    /// Routes hovered-control wheel input and window keyboard shortcuts before normal native dispatch.
    bool Translate(MSG* message);

    /// Reports whether library initialization or a report operation is pending.
    bool HasPendingReports() const;

    /// Reports whether initial library discovery or a Preferences library change is in progress.
    bool IsLoadingLibrary() const;

    /// Returns the native main-window handle.
    HWND GetWindow() const;
};
