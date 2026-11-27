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

#include "HelpForm.h"
#include "MainForm.h"
#include "Localization.h"
#include "SelectionEdit.h"
#include "SystemDialogTemplate.h"
#include "resource.h"
#include <commctrl.h>

#ifndef BCM_GETIDEALSIZE
#define BCM_GETIDEALSIZE 0x1601
#endif

/// Refreshes layout after Windows completes native dialog DPI scaling.
static const UINT nativeDialogDpiChangedMessage = WM_APP + 25;

/// Skips a native dialog-template string or ordinal resource identifier.
static const WORD* SkipDialogTemplateString(const WORD* value) {
    if (*value == 0xFFFF) {
        return value + 2;
    }
    while (*value != 0) {
        value++;
    }
    return value + 1;
}

/// Lets Windows map authored control dimensions using the current native dialog font.
static SIZE DialogResourceControlSize(HWND window, int resourceId, int id) {
    HINSTANCE hInstance = GetModuleHandleW(nullptr);
    HRSRC resource = FindResourceW(hInstance, MAKEINTRESOURCEW(resourceId), RT_DIALOG);
    HGLOBAL loaded = resource == nullptr ? nullptr : LoadResource(hInstance, resource);
    const WORD* definition = loaded == nullptr ? nullptr : static_cast<const WORD*>(LockResource(loaded));
    if (definition == nullptr || SizeofResource(hInstance, resource) < 26 || definition[1] != 0xFFFF) {
        return SIZE{};
    }
    WORD count = definition[8];
    const WORD* item = SkipDialogTemplateString(definition + 13);
    item = SkipDialogTemplateString(item);
    item = SkipDialogTemplateString(item);
    if ((definition[6] & DS_SETFONT) != 0) {
        item = SkipDialogTemplateString(item + 3);
    }
    for (WORD index = 0; index < count; index++) {
        item = reinterpret_cast<const WORD*>(reinterpret_cast<UINT_PTR>(item) + 3 & ~UINT_PTR{ 3 });
        int controlId = item[10] | item[11] << 16;
        if (controlId == id) {
            RECT bounds = RECT{ 0, 0, static_cast<short>(item[8]), static_cast<short>(item[9]) };
            MapDialogRect(window, &bounds);
            return SIZE{ bounds.right, bounds.bottom };
        }
        item = SkipDialogTemplateString(item + 12);
        item = SkipDialogTemplateString(item);
        WORD bytes = *item++;
        item = reinterpret_cast<const WORD*>(reinterpret_cast<const BYTE*>(item) + bytes);
    }
    return SIZE{};
}

/// Fits localized button text above its template width while preserving the current native height.
static SIZE DialogButtonSize(HWND button, int resourceId) {
    HWND parent = GetParent(button);
    SIZE minimum = DialogResourceControlSize(parent, resourceId, GetDlgCtrlID(button));
    SIZE size{};
    if (!SendMessageW(button, BCM_GETIDEALSIZE, 0, reinterpret_cast<LPARAM>(&size))) {
        HDC dc = GetDC(button);
        if (dc != nullptr) {
            HFONT font = reinterpret_cast<HFONT>(SendMessageW(button, WM_GETFONT, 0, 0));
            HGDIOBJ previous = font == nullptr ? nullptr : SelectObject(dc, font);
            wchar_t* text = CopyControlText(button);
            RECT bounds{};
            if (text != nullptr) {
                DrawTextW(dc, text, -1, &bounds, DT_CALCRECT | DT_SINGLELINE);
                HeapFree(GetProcessHeap(), 0, text);
            }
            RECT padding = RECT{ 0, 0, 12, 0 };
            MapDialogRect(parent, &padding);
            size.cx = bounds.right + padding.right + 2 * GetSystemMetrics(SM_CXEDGE);
            if (previous != nullptr) {
                SelectObject(dc, previous);
            }
            ReleaseDC(button, dc);
        }
    }
    if (size.cx < minimum.cx) {
        size.cx = minimum.cx;
    }
    RECT bounds{};
    GetWindowRect(button, &bounds);
    size.cy = bounds.bottom - bounds.top;
    if (GetProcAddress(GetModuleHandleW(L"user32.dll"), "GetDialogDpiChangeBehavior") == nullptr) {
        size.cy = minimum.cy;
    }
    return size;
}

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
    HFONT font;
    if (updateFont) {
        font = CreateSystemDialogFont(window);
    } else {
        font = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    }
    if (font == nullptr) {
        return false;
    }
    HFONT previousFont = ownsUiFont && uiFont != font ? uiFont : nullptr;
    ownsUiFont = updateFont || ownsUiFont && uiFont == font;
    uiFont = font;
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
    SIZE button = DialogButtonSize(GetDlgItem(window, IDOK), IDD_HELP);
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
    if (GetProcAddress(GetModuleHandleW(L"user32.dll"), "GetDialogDpiChangeBehavior") != nullptr) {
        PostMessageW(window, nativeDialogDpiChangedMessage, 0, 0);
        return FALSE;
    }
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
        case nativeDialogDpiChangedMessage:
            owner->ApplyStyle(false);
            return TRUE;
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
