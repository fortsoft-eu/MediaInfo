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

#include "ComboBoxSupport.h"
#include "SettingsStorage.h"
#include "MainForm.h"

/// Matches the native combo-box information layout used to locate and measure its dropdown list.
struct NativeComboInfo {
    DWORD size;
    RECT item;
    RECT button;
    DWORD buttonState;
    HWND combo;
    HWND edit;
    HWND list;
};

/// Links the dropdown list subclass to its combo box and original window procedure.
struct ComboListState {
    HWND combo;
    WNDPROC original;
};

/// Optional combo-box information entry point.
typedef BOOL(WINAPI* ComboInfoFunction)(HWND, NativeComboInfo*);

/// Dropdown subclass state and the native maximum-visible-item setting.
static const wchar_t comboListProperty[] = L"MediaInfo.ComboList";
static const UINT comboSetMinVisible = 0x1701;
static const int maximumVisibleComboItems = 13;

/// Queries native combo child windows when GetComboBoxInfo is available on the running Windows version.
static bool ReadComboInfo(HWND combo, NativeComboInfo* info) {
    info->size = sizeof(*info);
    ComboInfoFunction function = reinterpret_cast<ComboInfoFunction>(
        GetProcAddress(GetModuleHandleW(L"user32.dll"), "GetComboBoxInfo"));
    return function && function(combo, info);
}

/// Obtains the native selected-text rectangle, retaining the item-height path for older Windows.
bool ComboBoxTextRect(HWND combo, RECT* rectangle) {
    NativeComboInfo info = NativeComboInfo{};
    if (ReadComboInfo(combo, &info)) {
        *rectangle = info.item;
        return true;
    }
    GetClientRect(combo, rectangle);
    LRESULT height = SendMessageW(combo, CB_GETITEMHEIGHT, static_cast<WPARAM>(-1), 0);
    if (height == CB_ERR) {
        return false;
    }
    rectangle->top = (rectangle->bottom - static_cast<LONG>(height)) / 2;
    rectangle->bottom = rectangle->top + static_cast<LONG>(height);
    return true;
}

/// Fits native combo selection and list-item heights to its current font and system borders.
void UpdateComboBoxMetrics(HWND combo) {
    LRESULT selectionHeight = SendMessageW(combo, CB_GETITEMHEIGHT, static_cast<WPARAM>(-1), 0);
    TEXTMETRICW metrics = TEXTMETRICW{};
    if (selectionHeight == CB_ERR || !ReadControlMetrics(combo, &metrics)) {
        return;
    }
    LONG height = metrics.tmHeight + 2 * GetSystemMetrics(SM_CYBORDER);
    if (selectionHeight != height) {
        SendMessageW(combo, CB_SETITEMHEIGHT, static_cast<WPARAM>(-1), height);
    }
    if (SendMessageW(combo, CB_GETITEMHEIGHT, 0, 0) != metrics.tmHeight) {
        SendMessageW(combo, CB_SETITEMHEIGHT, 0, metrics.tmHeight);
    }
}

/// Fits a dropdown to the monitor work area and releases its subclass state when destroyed.
static LRESULT CALLBACK ComboListProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    ComboListState* state = reinterpret_cast<ComboListState*>(GetPropW(window, comboListProperty));
    if (message == WM_WINDOWPOSCHANGING) {
        WINDOWPOS* position = reinterpret_cast<WINDOWPOS*>(lParam);
        RECT current = RECT{};
        RECT combo = RECT{};
        if (GetWindowRect(window, &current) && GetWindowRect(state->combo, &combo)) {
            RECT work = WindowWorkArea(combo);
            LONG workWidth = work.right - work.left;
            if (workWidth > 0) {
                LONG currentWidth = position->flags & SWP_NOSIZE ? current.right - current.left : position->cx;
                LONG minimumWidth = combo.right > combo.left ? combo.right - combo.left : 1;
                LONG width = currentWidth < workWidth ? currentWidth : workWidth;
                if (width < minimumWidth) {
                    width = minimumWidth;
                }
                LONG left = position->flags & SWP_NOMOVE ? current.left : position->x;
                LONG maximumLeft = work.right - width;
                LONG minimumLeft = work.left < maximumLeft ? work.left : maximumLeft;
                LONG fittedLeft = left < minimumLeft ? minimumLeft : left > maximumLeft ? maximumLeft : left;
                if (width != currentWidth) {
                    position->cx = width;
                    if (position->flags & SWP_NOSIZE) {
                        position->cy = current.bottom - current.top;
                    }
                    position->flags &= ~SWP_NOSIZE;
                }
                if (fittedLeft != left) {
                    position->x = fittedLeft;
                    if (position->flags & SWP_NOMOVE) {
                        position->y = current.top;
                    }
                    position->flags &= ~SWP_NOMOVE;
                }
            }
        }
    } else if (message == WM_NCDESTROY) {
        WNDPROC original = state->original;
        SetWindowLongPtrW(window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(original));
        RemovePropW(window, comboListProperty);
        HeapFree(GetProcessHeap(), 0, state);
        return CallWindowProcW(original, window, message, wParam, lParam);
    }
    return CallWindowProcW(state->original, window, message, wParam, lParam);
}

/// Measures native dropdown width and sends the thirteen-row preference before the list opens.
void UpdateComboBoxDropDown(HWND combo) {
    SendMessageW(combo, comboSetMinVisible, maximumVisibleComboItems, 0);
    NativeComboInfo info = NativeComboInfo{};
    ReadComboInfo(combo, &info);
    int count = static_cast<int>(SendMessageW(combo, CB_GETCOUNT, 0, 0));
    HWND list = info.list ? info.list : combo;
    if (info.list && !GetPropW(info.list, comboListProperty)) {
        ComboListState* state = static_cast<ComboListState*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
            sizeof(ComboListState)));
        if (state) {
            state->combo = combo;
            if (SetPropW(info.list, comboListProperty, state)) {
                state->original = reinterpret_cast<WNDPROC>(SetWindowLongPtrW(info.list, GWLP_WNDPROC,
                    reinterpret_cast<LONG_PTR>(ComboListProc)));
                if (!state->original) {
                    RemovePropW(info.list, comboListProperty);
                    HeapFree(GetProcessHeap(), 0, state);
                }
            } else {
                HeapFree(GetProcessHeap(), 0, state);
            }
        }
    }
    HDC dc = GetDC(list);
    if (!dc) {
        return;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(list, WM_GETFONT, 0, 0));
    if (!font) {
        font = reinterpret_cast<HFONT>(SendMessageW(combo, WM_GETFONT, 0, 0));
    }
    HGDIOBJ old = font ? SelectObject(dc, font) : nullptr;
    LONG maximum = 0;
    for (int index = 0; index < count; ++index) {
        LRESULT length = SendMessageW(combo, CB_GETLBTEXTLEN, index, 0);
        if (length <= 0) {
            continue;
        }
        wchar_t* text = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0, (length + 1) * sizeof(wchar_t)));
        if (!text) {
            continue;
        }
        if (SendMessageW(combo, CB_GETLBTEXT, index, reinterpret_cast<LPARAM>(text)) != CB_ERR) {
            SIZE size = SIZE{};
            if (GetTextExtentPoint32W(dc, text, static_cast<int>(length), &size)) {
                ABC spacing = ABC{};
                wchar_t last = text[length - 1];
                if (GetCharABCWidthsW(dc, last, last, &spacing) && spacing.abcC < 0) {
                    size.cx -= spacing.abcC;
                }
                if (size.cx > maximum) {
                    maximum = size.cx;
                }
            }
        }
        HeapFree(GetProcessHeap(), 0, text);
    }
    if (old) {
        SelectObject(dc, old);
    }
    ReleaseDC(list, dc);
    LONG width = maximum + 2 * GetSystemMetrics(SM_CXEDGE);
    DWORD style = info.list ? GetWindowLongW(info.list, GWL_STYLE) : WS_BORDER;
    DWORD extended = info.list ? GetWindowLongW(info.list, GWL_EXSTYLE) : 0;
    RECT bounds = RECT{ 0, 0, width, 1 };
    if (AdjustWindowRectEx(&bounds, style, FALSE, extended)) {
        width = bounds.right - bounds.left;
    } else {
        width += 2 * GetSystemMetrics(SM_CXBORDER);
    }
    width += GetSystemMetrics(SM_CXVSCROLL);
    GetWindowRect(combo, &bounds);
    if (width < bounds.right - bounds.left) {
        width = bounds.right - bounds.left;
    }
    SendMessageW(combo, CB_SETDROPPEDWIDTH, width, 0);
}
