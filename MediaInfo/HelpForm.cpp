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
 * Last modified for version 1.2.2.3
 */

#include "HelpForm.h"
#include "MainForm.h"
#include "Localization.h"
#include "SelectionEdit.h"
#include "SystemDialogTemplate.h"
#include "resource.h"
#include <commctrl.h>

/// Initializes an unopened modeless Help form and its font state.
HelpForm::HelpForm()
        : window(nullptr), 
        ownerWindow(nullptr),
        uiFont(nullptr),
        ownsUiFont(false),
        initialized(false) {}

/// Closes Help and releases its owned font.
HelpForm::~HelpForm() {
    Close();
    if (ownsUiFont) {
        DeleteObject(uiFont);
    }
}

/// Applies the effective application font and theme to the Help controls.
bool HelpForm::ApplyStyle(bool updateFont) {
    if (window == nullptr) {
        return false;
    }
    HFONT font = uiFont;
    if (updateFont) {
        font = CreateSystemDialogFont(window);
    }
    if (font == nullptr) {
        return false;
    }
    HFONT previousFont = ownsUiFont ? uiFont : nullptr;
    uiFont = font;
    ownsUiFont = updateFont;
    SendMessageW(window, WM_SETFONT, reinterpret_cast<WPARAM>(font), FALSE);
    const int ids[] = {
        IDC_INFO_TEXT,
        IDOK,
        IDC_INFO_GRIP
    };
    for (int id : ids) {
        HWND control = GetDlgItem(window, id);
        if (control == nullptr) {
            continue;
        }
        SendMessageW(control, WM_SETFONT, reinterpret_cast<WPARAM>(font), FALSE);
    }
    if (previousFont != nullptr) {
        DeleteObject(previousFont);
    }
    UpdateWindowIcons(window, IDI_MEDIAINFO);
    Layout();
    RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_FRAME | RDW_ALLCHILDREN);
    return true;
}

/// Fits the Help edit, Close button and size grip to the current client area.
void HelpForm::Layout() {
    if (!initialized || IsIconic(window)) {
        return;
    }
    RECT client = RECT{};
    GetClientRect(window, &client);
    SIZE margin = DialogUnits(uiFont, 8, 8);
    SIZE button = DialogResourceControlSize(IDD_HELP, IDOK, uiFont);
    button.cx = PreferredButtonSize(GetDlgItem(window, IDOK), button).cx;
    SIZE gap = DialogUnits(uiFont, 4, 6);
    int textTop = margin.cy;
    int buttonY = client.bottom - margin.cy - button.cy;
    PlaceControl(GetDlgItem(window, IDOK), client.right - margin.cx - button.cx, buttonY, button.cx,
        button.cy);
    PlaceControl(GetDlgItem(window, IDC_INFO_TEXT), margin.cx, textTop, client.right - 2 * margin.cx,
        buttonY - gap.cy - textTop);
    int gripWidth = GetSystemMetrics(SM_CXVSCROLL);
    int gripHeight = GetSystemMetrics(SM_CYHSCROLL);
    SetWindowPos(GetDlgItem(window, IDC_INFO_GRIP), HWND_BOTTOM,
        client.right - gripWidth, client.bottom - gripHeight, gripWidth, gripHeight,
        SWP_NOACTIVATE | (IsZoomed(window) ? SWP_HIDEWINDOW : SWP_SHOWWINDOW));
}

/// Refreshes the localized title, Close button and Help contents.
void HelpForm::RefreshLanguage() {
    if (!window) {
        return;
    }
    wchar_t title[512];
    wsprintfW(title, T(TXT_HELP_TITLE), GetApplicationName());
    SetWindowTextW(window, title);
    SetDlgItemTextW(window, IDOK, T(TXT_CLOSE));
    SetDlgItemTextW(window, IDC_INFO_TEXT, LocalizedHelpText());
    Layout();
}

/// Loads Help text, installs native edit behavior and attaches persisted placement.
bool HelpForm::Initialize() {
    uiFont = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    initialized = true;
    HWND edit = GetDlgItem(window, IDC_INFO_TEXT);
    if (!InstallSelectionEditHandler(edit) || !ApplyStyle(false)) {
        return false;
    }
    SendMessageW(edit, EM_SETLIMITTEXT, 0x7FFFFFFE, 0);
    InstallInformationWordBreak(edit);
    SetWindowTextW(edit, LocalizedHelpText());
    RefreshLanguage();
    placement.SetSingleInstance(true);
    placement.SetUseWindowsDefaultSize(false);
    if (!placement.Attach(window, "HelpWindow")) {
        return false;
    }
    Layout();
    return true;
}

/// Applies the suggested DPI-change bounds, rebuilds fonts and updates the dialog layout.
INT_PTR HelpForm::HandleDpiChange(LPARAM lParam) {
    RECT* bounds = reinterpret_cast<RECT*>(lParam);
    SetWindowPos(window, nullptr, bounds->left, bounds->top, bounds->right - bounds->left,
        bounds->bottom - bounds->top, SWP_NOZORDER | SWP_NOACTIVATE);
    ApplyStyle(true);
    return TRUE;
}

/// Handles native dialog commands, sizing, theme changes and closing.
INT_PTR CALLBACK HelpForm::DialogProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    HelpForm* owner = reinterpret_cast<HelpForm*>(GetWindowLongPtrW(window, DWLP_USER));
    if (message == WM_INITDIALOG) {
        owner = reinterpret_cast<HelpForm*>(lParam);
        owner->window = window;
        SetWindowLongPtrW(window, DWLP_USER, reinterpret_cast<LONG_PTR>(owner));
        if (!owner->Initialize()) {
            owner->Close();
            return FALSE;
        }
        SetFocus(GetDlgItem(window, IDOK));
        return FALSE;
    }
    if (!owner) {
        return FALSE;
    }
    switch (message) {
        case WM_GETFONT:
            if (owner->uiFont) {
                SetWindowLongPtrW(window, DWLP_MSGRESULT, reinterpret_cast<LONG_PTR>(owner->uiFont));
                return TRUE;
            }
            break;
        case WM_CTLCOLORDLG:
            if (!AreVisualStylesActive()) {
                return reinterpret_cast<INT_PTR>(GetSysColorBrush(COLOR_BTNFACE));
            }
            break;
        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
                owner->Close();
                return TRUE;
            }
            break;
        case WM_SIZE:
            owner->Layout();
            return TRUE;
        case WM_SETTINGCHANGE:
        case WM_THEMECHANGED:
            owner->ApplyStyle(true);
            return TRUE;
        case WM_DISPLAYCHANGE:
            owner->Layout();
            return TRUE;
        case WM_DPICHANGED:
            return owner->HandleDpiChange(lParam);
        case WM_CLOSE:
            owner->Close();
            return TRUE;
        case WM_NCDESTROY:
            ClearWindowIcons(window);
            ResetInformationWordBreak();
            if (owner->ownsUiFont) {
                DeleteObject(owner->uiFont);
            }
            owner->uiFont = nullptr;
            owner->ownsUiFont = false;
            owner->initialized = false;
            owner->window = nullptr;
            if (IsWindow(owner->ownerWindow)) {
                SendMessageW(owner->ownerWindow, helpVisibilityChangedMessage, 0, 0);
            }
            break;
    }
    return FALSE;
}

/// Shows the independently minimizable Help form or activates its existing instance.
void HelpForm::Show(HWND owner) {
    ownerWindow = owner;
    if (window) {
        placement.BringToFront();
        return;
    }
    HINSTANCE instance = GetModuleHandleW(nullptr);
    DLGTEMPLATE* definition = LoadSystemDialogTemplate(instance, IDD_HELP, owner);
    if (!definition) {
        return;
    }
    HWND created = CreateDialogIndirectParamW(instance, definition, nullptr, DialogProc,
        reinterpret_cast<LPARAM>(this));
    HeapFree(GetProcessHeap(), 0, definition);
    if (created && window) {
        placement.Show();
        SendMessageW(ownerWindow, helpVisibilityChangedMessage, 0, 0);
    }
}

/// Closes the active modeless dialog.
void HelpForm::Close() {
    if (window) {
        DestroyWindow(window);
    }
}

/// Routes modeless keyboard input through the native dialog manager.
bool HelpForm::Translate(MSG* message) {
    return window
        && (message->hwnd == window || IsChild(window, message->hwnd))
        && IsDialogMessageW(window, message);
}

/// Returns the dialog handle, or null when it is closed.
HWND HelpForm::GetWindow() const {
    return window;
}
