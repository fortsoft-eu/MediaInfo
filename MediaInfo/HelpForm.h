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
 * Last modified for version 1.1.0.1
 */

#pragma once

#include <windows.h>
#include "PersistWindowState.h"

/// Hosts modeless Help with saved placement and one visible instance across viewer processes.
class HelpForm {

private:
    /// Native dialog, its font and the Close-button size supplied by the resource template.
    HWND window;
    HFONT uiFont;
    SIZE buttonSize;
    bool ownsUiFont;

    /// Help-window placement and cross-process instance handling.
    PersistWindowState placement;

    /// Refreshes caption icons and applies the current system message font to the text and Close button.
    void SetFonts(bool updateUi);

    /// Fits the Help edit, Close button and size grip to the current client area.
    void Layout();

    /// Applies the suggested DPI-change bounds, rebuilds fonts and updates the dialog layout.
    INT_PTR HandleDpiChange(LPARAM lParam);

    /// Loads Help text, installs native edit behavior and attaches persisted placement.
    bool Initialize();

    /// Handles native dialog commands, sizing, theme changes and closing.
    static INT_PTR CALLBACK DialogProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

public:
    /// Initializes an unopened modeless Help form and its font state.
    HelpForm();

    /// Closes Help and releases its owned font.
    ~HelpForm();

    /// Shows the independently minimizable Help form or activates its existing instance.
    void Show(HWND owner);

    /// Closes the active modeless dialog.
    void Close();

    /// Refreshes the localized title, Close button and Help contents.
    void RefreshLanguage();

    /// Routes modeless keyboard input through the native dialog manager.
    bool Translate(MSG* message);

    /// Returns the dialog handle, or null when it is closed.
    HWND GetWindow() const;
};
