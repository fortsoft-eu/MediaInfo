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

#include "MediaInfo.h"
#include "PersistWindowState.h"

/// Stores one session-only search expression together with its five matching options.
struct FindHistoryEntry {
    wchar_t* text;
    DWORD options;
};

/// Identifies one UTF-16 match without retaining pointers into the report buffer.
struct FindTextMatch {
    int start;
    int length;
};

/// Owns the modeless search form, session history and matching state for the active report.
class FindForm {

private:
    HWND window;
    HWND ownerWindow;
    HWND target;
    HWND lastTarget;

    HFONT uiFont;
    PersistWindowState placement;
    SIZE buttonSize;
    UINT templateDpi;
    LONG minimumWidth;
    LONG fixedHeight;
    wchar_t* query;
    FindHistoryEntry history[30];
    FindTextMatch* matches;
    UINT historyCount;
    UINT matchCount;
    UINT matchCapacity;
    int lastMatchStart;
    int lastMatchLength;
    bool ownsUiFont;
    bool matchCase;
    bool backward;
    bool startsWith;
    bool endsWith;
    bool regularExpression;

    /// Initializes the editable combo, native controls, icons and persisted form placement.
    bool Initialize();

    /// Applies the system font and recalculates native font- and DPI-aware geometry.
    void SetFonts(bool updateUi);

    /// Measures the minimum width and anchors controls without clipping localized option captions.
    void Layout();

    /// Enables Find Next only when a report and a nonempty search expression are available.
    void UpdateFindButton();

    /// Disables line-start and line-end options while regular-expression matching is selected.
    void UpdateRegexOptions();

    /// Copies pending search text and options, retaining the last query if allocation fails.
    bool ReadOptions();

    /// Returns the five matching options stored with a session history entry.
    DWORD Options() const;

    /// Restores matching options when a search-history item is selected.
    void ApplyOptions(DWORD options);

    /// Moves the current expression to the front of the bounded session history.
    bool RememberSearch();

    /// Repopulates the editable combo without changing its current text or text selection.
    void PopulateHistory();

    /// Appends one match while checking process-heap allocation and buffer size limits.
    bool AddMatch(int start, int length);

    /// Collects literal matches, optionally restricted to the beginning or end of logical lines.
    bool FindLiteral(wchar_t* report);

    /// Collects bounded Unicode multiline PCRE2 matches, including zero-length expressions.
    bool FindRegex(const wchar_t* report);

    /// Selects the next or previous collected match, wrapping once at the ends of the report.
    void SelectMatch(bool reverse);

    /// Applies the Always on Top checkbox immediately and preserves its native saved state.
    void ChangeTopMost();

    /// Restores history options during navigation and selects the text after the choice is committed.
    void ChooseHistory(bool selectText);

    /// Closes a user-dismissed form and restores ordinary report-selection visibility.
    INT_PTR HandleClose();

    /// Handles combo notifications, search options, Find Next and Close commands.
    INT_PTR HandleCommand(WPARAM wParam);

    /// Applies suggested DPI bounds and refreshes native fonts and geometry.
    INT_PTR HandleDpiChange(LPARAM lParam);

    /// Supplies the measured minimum width while PersistWindowState fixes the form's height.
    INT_PTR HandleMinMax(LPARAM lParam);

    /// Preserves the reference form's Insert overwrite mode through native edit selection.
    void PrepareOverwrite(MSG* message);

    /// Dispatches native modeless form messages without changing the shared selection component.
    static INT_PTR CALLBACK DialogProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

public:
    /// Initializes forward literal searching and an empty thirty-item session history.
    FindForm();

    /// Closes the form and releases its font, expression, history and match buffers.
    ~FindForm();

    /// Uses only the active loaded report and invalidates the last zero-length match after retargeting.
    void SetTarget(HWND edit);

    /// Retains logical search state when an existing report edit is replaced for native style changes.
    void ReplaceTarget(HWND original, HWND replacement);

    /// Opens or activates this viewer's search form without blocking its main window.
    void Show(HWND owner);

    /// Closes the form while retaining expressions and options only in this running instance.
    void Close();

    /// Searches the active report, reversing the selected direction for Find Previous or Shift.
    void FindNext(HWND owner, bool reverse);

    /// Refreshes all captions and their geometry after a committed interface-language change.
    void RefreshLanguage();

    /// Routes search shortcuts and native dialog navigation only for this form and its children.
    bool Translate(MSG* message);

    /// Returns this viewer's search form or null when it is closed.
    HWND GetWindow() const;
};
