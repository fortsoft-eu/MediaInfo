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
 * Last modified for version 1.2.3.0
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

/// Manages the About dialog, its controls and fonts, and its saved position.
class AboutForm {

public:
    /// Returns this form's native window, or null while it is closed.
    HWND GetWindow() const;

    /// Creates or activates About, optionally using the native modal dialog loop.
    void Show(HWND owner, DialogPosition position = DialogPosition::Template, bool modalDialog = false);

    /// Updates this form's localized captions and content without changing the other form.
    void RefreshLanguage();

    /// Applies the effective interface font and current theme while keeping the About license in Consolas.
    bool ApplyStyle(bool updateFont = true);

    /// Destroys this form and releases its controls and owned fonts.
    void Close() const;

    /// Initializes an unopened About form and its owned resources.
    AboutForm();

    /// Closes the dialog and releases its fonts, tooltip and control subclasses.
    ~AboutForm();

    /// Routes modeless keyboard input through the native dialog manager.
    bool Translate(MSG* message);

private:
    HWND window = nullptr;
    HWND tooltip = nullptr;
    HWND ownerWindow = nullptr;
    HFONT uiFont = nullptr;
    HFONT licenseFont = nullptr;
    HFONT linkFont;
    HCURSOR hand;
    HMODULE legacyCursorModule;
    PersistWindowState placement;
    DialogPosition initialPosition;
    SIZE referenceLicense = {};
    UINT referenceDpi = 96;
    bool ownsFont = false;
    bool nativeLink;
    bool initialized = false;
    bool modal = false;
    wchar_t websiteUrl[MAX_PATH];
    wchar_t tooltipText[256];
    char ansiTooltipText[768];

    /// Initializes native controls, content and placement for either creation mode.
    bool Initialize();

    /// Builds the natural About layout from its fixed license dimensions, then fits it to the monitor work
    /// area. Resize notifications anchor the edit to the right and bottom edges and the Close button to the
    /// bottom right.
    void Layout(bool resize = true) const;

    /// Handles this form's native commands, layout, theme, DPI changes and resource cleanup.
    INT_PTR HandleMessage(UINT message, WPARAM wParam, LPARAM lParam);

    /// Fits the About window to its monitor work area after its natural layout, without saving the adjusted
    /// size.
    void FitToWorkArea() const;

    /// Loads the license body without its optional title, BOM or outer whitespace and uses native edit line
    /// endings.
    wchar_t* LoadLicenseText() const;

    /// Opens the About website and reports failures in the selected application language.
    void OpenWebsite() const;

    /// Displays the applicable About context commands and handles opening the website or copying its URL or
    /// product information.
    void ShowContextMenu(HWND source, LPARAM location) const;

    /// Adds the About context menu to product and website controls and removes the subclass on destruction.
    static LRESULT CALLBACK ControlSubclassProc(HWND control, UINT message, WPARAM wParam, LPARAM lParam);

    /// Associates the native dialog with its form object and dispatches only this form's messages.
    static INT_PTR CALLBACK DialogProc(HWND dialog, UINT message, WPARAM wParam, LPARAM lParam);

    /// Applies the requested initial placement while leaving a retained position to PersistWindowState.
    bool ApplyInitialPosition();

    /// Replaces the static website control with a native SysLink when supported.
    void CreateNativeLink();

    /// Installs link and context handlers, the native hand cursor and a localized website tooltip.
    bool AttachControls();

    /// Removes control subclasses and releases the tooltip and legacy cursor module.
    void DetachControls();

    /// Copies the product information and website address as Unicode text.
    void CopyInformation() const;

    /// Draws the static link with native GDI and an uninset focus rectangle.
    static void PaintLink(HWND control, HDC dc);
};
