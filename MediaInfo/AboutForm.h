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

/// Hosts modal About and owns its license text, website link, tooltip and context commands.
class AboutForm {

private:
    /// Native dialog, website tooltip, fonts and system cursor resources.
    HWND window;
    HWND tooltip;
    HFONT uiFont;
    HFONT textFont;
    HFONT linkFont;
    HCURSOR hand;
    HMODULE legacyCursorModule;

    /// Native layout measurements and link state.
    SIZE buttonSize;
    SIZE licenseSize;
    UINT licenseDpi;
    bool ownsUiFont;
    bool nativeLink;
    bool initialized;
    wchar_t websiteUrl[MAX_PATH];
    wchar_t tooltipText[256];
    char ansiTooltipText[768];

    /// Applies current interface, license and link fonts and selects the appropriate icon size.
    void SetFonts(bool updateUi);

    /// Builds the natural About layout, fits it to the work area and anchors controls on resize.
    void Layout(bool resize = true) const;

    /// Fits the About window to its monitor work area after its natural layout.
    void FitToWorkArea() const;

    /// Applies the suggested DPI-change bounds, rebuilds fonts and updates the dialog layout.
    INT_PTR HandleDpiChange(LPARAM lParam);

    /// Loads the license text and installs native edit, link, tooltip and context-menu behavior.
    bool Initialize();

    /// Replaces the static website control with a native SysLink when supported.
    void CreateNativeLink();

    /// Installs link and context handlers, the native hand cursor and a localized website tooltip.
    bool AttachControls();

    /// Removes control subclasses and releases the tooltip and legacy cursor module.
    void DetachControls();

    /// Opens the application website in the default browser and reports launch failures.
    void OpenWebsite();

    /// Copies the product information and website address as Unicode text.
    void CopyInformation();

    /// Draws the static link with native GDI and an uninset focus rectangle.
    static void PaintLink(HWND control, HDC dc);

    /// Shows the native context commands appropriate to the product information or website link.
    void ShowContextMenu(HWND source, LPARAM location);

    /// Handles native website-link activation notifications and returns whether the message was processed.
    INT_PTR HandleNotification(LPARAM lParam);

    /// Handles dialog commands, layout, theme changes and website notifications.
    static INT_PTR CALLBACK DialogProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

    /// Handles context commands, cursors and completed mouse or keyboard activation on About controls.
    static LRESULT CALLBACK ControlProc(HWND control, UINT message, WPARAM wParam, LPARAM lParam);

public:
    /// Initializes an unopened modal About form and its owned resources.
    AboutForm();

    /// Closes the dialog and releases its fonts, tooltip and control subclasses.
    ~AboutForm();

    /// Opens About modally without saving its position.
    void Show(HWND owner);

    /// Closes the active modal dialog.
    void Close();

    /// Refreshes the localized title, product header and website label.
    void RefreshLanguage();

    /// Returns the dialog handle, or null when it is closed.
    HWND GetWindow() const;
};
