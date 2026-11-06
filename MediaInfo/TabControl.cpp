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

#include "TabControl.h"
#include <commctrl.h>
#include <windowsx.h>

static const wchar_t originalTabProperty[] = L"MediaInfo.TabOriginalProc";

/// Maximizes the report page area and handles middle-click tab closing through the parent window.
static LRESULT CALLBACK BorderlessTabProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    WNDPROC original = reinterpret_cast<WNDPROC>(GetPropW(window, originalTabProperty));
    if (message == TCM_ADJUSTRECT && lParam && !(GetWindowLongW(window, GWL_STYLE) & TCS_BOTTOM)) {
        RECT rectangle = *reinterpret_cast<RECT*>(lParam);
        LRESULT result = CallWindowProcW(original, window, message, wParam, lParam);
        int headerHeight = 0;
        int count = TabCtrl_GetItemCount(window);
        for (int index = 0; index < count; ++index) {
            RECT header = RECT{};
            if (TabCtrl_GetItemRect(window, index, &header) && header.bottom > headerHeight) {
                headerHeight = header.bottom;
            }
        }
        rectangle.top += wParam ? -headerHeight : headerHeight;
        *reinterpret_cast<RECT*>(lParam) = rectangle;
        return result;
    }
    if (message == WM_MBUTTONDOWN) {
        return 0;
    }
    if (message == WM_MBUTTONUP) {
        TCHITTESTINFO hit = TCHITTESTINFO{};
        hit.pt = POINT{ GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
        int index = TabCtrl_HitTest(window, &hit);
        if (index >= 0 && hit.flags & TCHT_ONITEM) {
            SendMessageW(GetParent(window), tabCloseMessage, index, reinterpret_cast<LPARAM>(window));
        }
        return 0;
    }
    if (message == WM_NCDESTROY) {
        SetWindowLongPtrW(window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(original));
        RemovePropW(window, originalTabProperty);
    }
    return CallWindowProcW(original, window, message, wParam, lParam);
}

/// Installs the native tab subclass used for workspace painting and header input.
bool InstallBorderlessTabHandler(HWND window) {
    WNDPROC original = reinterpret_cast<WNDPROC>(GetWindowLongPtrW(window, GWLP_WNDPROC));
    if (!SetPropW(window, originalTabProperty, reinterpret_cast<HANDLE>(original))) {
        return false;
    }
    SetLastError(0);
    if (!SetWindowLongPtrW(window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(BorderlessTabProc))
            && GetLastError()) {
        RemovePropW(window, originalTabProperty);
        return false;
    }
    return true;
}

/// Scrolls overflowing tab headers while preserving the selected report and keyboard focus.
bool ScrollTabHeaders(HWND owner, HWND tabs, WPARAM wParam, LPARAM lParam) {
    int delta = GET_WHEEL_DELTA_WPARAM(wParam);
    if (!delta
            || !owner
            || !tabs
            || !IsWindowEnabled(owner)
            || !IsWindowVisible(tabs)) {
        return false;
    }
    int count = TabCtrl_GetItemCount(tabs);
    RECT header = RECT{};
    RECT client = RECT{};
    if (count <= 0 || !TabCtrl_GetItemRect(tabs, 0, &header) || !GetClientRect(tabs, &client)) {
        return false;
    }
    POINT point = POINT{ GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
    HWND hovered = WindowFromPoint(point);
    if (hovered != tabs && hovered != owner && !IsChild(tabs, hovered)) {
        return false;
    }
    ScreenToClient(tabs, &point);
    header.left = client.left;
    header.right = client.right;
    if (!PtInRect(&header, point)) {
        return false;
    }
    HWND scrollButtons = FindWindowExW(tabs, nullptr, UPDOWN_CLASSW, nullptr);
    if (!scrollButtons || !IsWindowVisible(scrollButtons)) {
        return false;
    }
    RECT last = RECT{};
    RECT buttons = RECT{};
    if (!TabCtrl_GetItemRect(tabs, count - 1, &last) || !GetWindowRect(scrollButtons, &buttons)) {
        return true;
    }
    MapWindowPoints(HWND_DESKTOP, tabs, reinterpret_cast<POINT*>(&buttons), 2);
    if (delta < 0 && last.right <= buttons.left) {
        return true;
    }
    int firstVisible = 0;
    for (int index = 0; index < count; ++index) {
        RECT item = RECT{};
        if (!TabCtrl_GetItemRect(tabs, index, &item)) {
            return true;
        }
        if (item.left >= 0) {
            firstVisible = index;
            break;
        }
    }
    int position = firstVisible + (delta > 0 ? -1 : 1);
    if (position < 0) {
        position = 0;
    } else if (position >= count) {
        position = count - 1;
    }
    SendMessageW(tabs, WM_HSCROLL, MAKEWPARAM(SB_THUMBPOSITION, position), 0);
    SendMessageW(tabs, WM_HSCROLL, MAKEWPARAM(SB_ENDSCROLL, position), 0);
    return true;
}

/// Calculates the report area beneath the tab headers without adding unnecessary page margins.
RECT GetTabContentRect(HWND window) {
    RECT rectangle = RECT{};
    GetClientRect(window, &rectangle);
    TabCtrl_AdjustRect(window, FALSE, &rectangle);
    MapWindowPoints(window, GetParent(window), reinterpret_cast<POINT*>(&rectangle), 2);
    return rectangle;
}
