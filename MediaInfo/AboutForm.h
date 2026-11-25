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
 * Last modified for version 1.2.2.4
 */

#pragma once

#include <windows.h>
#include "PersistWindowState.h"

/// Initial placement used before restoring a position retained by the form.
enum class DialogPosition {
    Template,
    CenterParent,
    CenterScreen,
    WindowsDefault
};

/// Hosts modal and modeless About with its license text, website link, tooltip and context commands.
class AboutForm {

private:
    /// Native dialog, website tooltip, fonts and system cursor resources.
    HWND window;
    HWND tooltip;
    HWND ownerWindow;
    HFONT uiFont;
    HFONT textFont;
    HFONT linkFont;
    HCURSOR hand;
    HMODULE legacyCursorModule;

    /// Retains the dialog position only for this application instance.
    PersistWindowState placement;
    DialogPosition initialPosition;

    /// Native layout measurements and link state.
    SIZE licenseSize;
    UINT licenseDpi;
    bool ownsUiFont;
    bool nativeLink;
    bool initialized;
    bool modal;
    wchar_t websiteUrl[MAX_PATH];
    wchar_t tooltipText[256];
    char ansiTooltipText[768];

    /// Applies current fonts and refreshes the caption and body icons for the current window DPI.
    bool ApplyStyle(bool updateFont = true);

    /// Builds the natural About layout, fits it to the work area and anchors controls on resize.
    void Layout(bool resize = true) const;

    /// Fits the About window to its monitor work area after its natural layout.
    void FitToWorkArea() const;

    /// Applies the suggested DPI-change bounds, rebuilds fonts and updates the dialog layout.
    INT_PTR HandleDpiChange(LPARAM lParam);

    /// Loads the license, installs native controls and restores the position retained in memory.
    bool Initialize();

    /// Applies the requested initial placement while leaving a retained position to PersistWindowState.
    bool ApplyInitialPosition();

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
    /// Initializes an unopened About form and its owned resources.
    AboutForm();

    /// Closes the dialog and releases its fonts, tooltip and control subclasses.
    ~AboutForm();

    /// Creates or activates About, optionally using the native modal dialog loop.
    void Show(HWND owner, DialogPosition position = DialogPosition::Template, bool modalDialog = false);

    /// Destroys the modeless form or ends its native modal dialog loop.
    void Close() const;

    /// Routes modeless keyboard input through the native dialog manager.
    bool Translate(MSG* message);

    /// Refreshes the localized title, product header and website label.
    void RefreshLanguage();

    /// Returns the dialog handle, or null when it is closed.
    HWND GetWindow() const;
};
