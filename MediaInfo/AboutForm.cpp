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

#include "AboutForm.h"
#include "MainForm.h"
#include "Localization.h"
#include "LibrarySupport.h"
#include "SettingsStorage.h"
#include "SelectionEdit.h"
#include "SystemDialogTemplate.h"
#include "resource.h"
#include <commctrl.h>
#include <shellapi.h>
#include <windowsx.h>
#include <winver.h>

#ifndef BCM_GETIDEALSIZE
#define BCM_GETIDEALSIZE 0x1601
#endif

/// Refreshes layout after Windows completes native dialog DPI scaling.
static const UINT nativeDialogDpiChangedMessage = WM_APP + 25;

const int ABOUT_ICON_SIZE = 32;
const int ABOUT_LARGE_ICON_SIZE = 48;
const int ABOUT_LARGE_ICON_DPI = 130;

/// Optional common-controls initialization entry point.
typedef BOOL(WINAPI* InitializeControlsFunction)(const INITCOMMONCONTROLSEX*);

/// Control-subclass properties and the application website address.
static const wchar_t ownerProperty[] = L"MediaInfo.AboutOwner";
static const wchar_t originalProperty[] = L"MediaInfo.AboutOriginal";
static const wchar_t licenseOriginalProperty[] = L"MediaInfo.AboutLicenseOriginal";
static const wchar_t websiteRoot[] = L"https://fortsoft.eu/";

/// About context-menu commands and the controls that expose them.
static const UINT openWebsiteCommand = 1;
static const UINT copyUrlCommand = 2;
static const UINT copyInformationCommand = 3;
static const int aboutControls[] = { IDC_INFO_PRODUCT, IDC_INFO_WEBSITE, IDC_INFO_LINK };

/// Optional title removed before the embedded license body is displayed.
static const wchar_t licenseHeading[] = L"MIT License";

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

/// Returns a dialog child's window rectangle mapped to its parent's client coordinates.
static RECT InformationControlRect(HWND window, int id) {
    RECT rect = {};
    GetWindowRect(GetDlgItem(window, id), &rect);
    MapWindowPoints(HWND_DESKTOP, window, reinterpret_cast<POINT*>(&rect), 2);
    return rect;
}

/// Measures unwrapped information text using the control's current font.
static SIZE InformationTextSize(HWND control) {
    SIZE size = {};
    HDC dc = GetDC(control);
    if (dc != nullptr) {
        HFONT font = reinterpret_cast<HFONT>(SendMessageW(control, WM_GETFONT, 0, 0));
        HGDIOBJ previous = font == nullptr ? nullptr : SelectObject(dc, font);
        wchar_t* text = CopyControlText(control);
        if (text != nullptr) {
            GetTextExtentPoint32W(dc, text, lstrlenW(text), &size);
            HeapFree(GetProcessHeap(), 0, text);
        }
        if (previous != nullptr) {
            SelectObject(dc, previous);
        }
        ReleaseDC(control, dc);
    }
    return size;
}

/// Measures unwrapped license text in the edit's current font and toggles the horizontal scrollbar only when
/// needed. Restores horizontal position to the start before hiding the bar; measurement also works while the
/// bar is hidden.
static void UpdateAboutLicenseScrollBar(HWND window) {
    HDC dc = GetDC(window);
    if (dc == nullptr) {
        return;
    }
    wchar_t* text = CopyControlText(window);
    if (text == nullptr) {
        ReleaseDC(window, dc);
        return;
    }
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    HGDIOBJ previousFont = font == nullptr ? nullptr : SelectObject(dc, font);
    RECT textBounds = {};
    DrawTextW(dc, text, lstrlenW(text), &textBounds,
        DT_CALCRECT | DT_NOPREFIX | DT_EXPANDTABS);
    HeapFree(GetProcessHeap(), 0, text);
    if (previousFont != nullptr) {
        SelectObject(dc, previousFont);
    }
    ReleaseDC(window, dc);
    RECT format = {};
    SendMessageW(window, EM_GETRECT, 0, reinterpret_cast<LPARAM>(&format));
    bool needed = textBounds.right - textBounds.left > format.right - format.left;
    bool visible = (GetWindowLongPtrW(window, GWL_STYLE) & WS_HSCROLL) != 0;
    if (needed != visible) {
        if (!needed) {
            SendMessageW(window, WM_HSCROLL, SB_LEFT, 0);
        }
        ShowScrollBar(window, SB_HORZ, needed);
    }
}

/// Recalculates horizontal scrollbar visibility after native size, font, text, or theme updates and removes
/// the subclass on destruction.
static LRESULT CALLBACK AboutLicenseSubclassProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    WNDPROC original = reinterpret_cast<WNDPROC>(GetPropW(window, licenseOriginalProperty));
    if (message == WM_SIZE || message == WM_SETFONT || message == WM_SETTEXT || message == WM_THEMECHANGED) {
        LRESULT result = CallWindowProcW(original, window, message, wParam, lParam);
        UpdateAboutLicenseScrollBar(window);
        return result;
    }
    if (message == WM_NCDESTROY) {
        SetWindowLongPtrW(window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(original));
        RemovePropW(window, licenseOriginalProperty);
    }
    return CallWindowProcW(original, window, message, wParam, lParam);
}

/// Returns a borrowed string from the declared version-resource translation tables, or ? if unavailable.
static const wchar_t* GetApplicationString(const BYTE* data, const wchar_t* entry) {
    WORD* translations = nullptr;
    UINT translationBytes = 0;
    if (!data) {
        return L"?";
    }
    BOOL result = VerQueryValueW(data, L"\\VarFileInfo\\Translation",
        reinterpret_cast<void**>(&translations), &translationBytes);
    if (!result || !translations) {
        return L"?";
    }
    for (UINT index = 0; index + 1 < translationBytes / sizeof(WORD); index += 2) {
        wchar_t query[64];
        wsprintfW(query, L"\\StringFileInfo\\%04X%04X\\%s", translations[index],
            translations[index + 1], entry);
        wchar_t* name = nullptr;
        UINT length = 0;
        result = VerQueryValueW(data, query, reinterpret_cast<void**>(&name), &length);
        if (result && name && length > 1 && name[0]) {
            return name;
        }
    }
    return L"?";
}

/// Reads the executable product version into a buffer of at least 24 characters, using ? on failure.
static void GetApplicationVersion(const BYTE* data, wchar_t* version) {
    lstrcpyW(version, L"?");
    VS_FIXEDFILEINFO* information = nullptr;
    UINT informationSize = 0;
    if (!data) {
        return;
    }
    BOOL result = VerQueryValueW(data, L"\\", reinterpret_cast<void**>(&information), &informationSize);
    if (result && information && informationSize >= sizeof(VS_FIXEDFILEINFO)) {
        if (information->dwSignature == VS_FFI_SIGNATURE) {
            wsprintfW(version, L"%u.%u.%u.%u",
                HIWORD(information->dwProductVersionMS),
                LOWORD(information->dwProductVersionMS),
                HIWORD(information->dwProductVersionLS),
                LOWORD(information->dwProductVersionLS));
        }
    }
}

/// Inserts the executable product name into the localized About title, preserving its language-specific
/// order.
static void BuildAboutTitle(wchar_t* title) {
    wsprintfW(title, T(TXT_ABOUT_TITLE), GetApplicationName());
}

/// Builds the localized product header from executable metadata and bundled-library versions.
static void BuildAboutProductText(wchar_t* product) {
    BYTE* data = LoadApplicationVersionInfo();
    wchar_t version[48];
    GetApplicationVersion(data, version);
    const wchar_t* name = GetApplicationName();
    const wchar_t* description = TranslateText(GetApplicationString(data, L"FileDescription"));
    const wchar_t* copyright = GetApplicationString(data, L"LegalCopyright");
    wsprintfW(product, L"%s\r\n%s\r\n\r\n%s %s\r\n%s\r\n%s Win32 (x86)\r\n%s %s, %s, %s\r\n%s %s", name,
        description, T(TXT_VERSION), version, copyright, T(TXT_PLATFORM), T(TXT_EMBEDDED_MEDIALIB),
        bundledMediaInfoVersions[0], bundledMediaInfoVersions[1], bundledMediaInfoVersions[2],
        T(TXT_EMBEDDED_CURL), bundledCurlVersions);
    if (data) {
        HeapFree(GetProcessHeap(), 0, data);
    }
}

/// Builds the product website URL in a MAX_PATH buffer using the lowercase executable product name.
static void BuildAboutWebsiteUrl(wchar_t* website) {
    UINT rootLength = ARRAYSIZE(websiteRoot) - 1;
    lstrcpyW(website, websiteRoot);
    lstrcpynW(website + rootLength, GetApplicationName(), MAX_PATH - rootLength - 1);
    CharLowerBuffW(website + rootLength, lstrlenW(website + rootLength));
    lstrcatW(website, L"/");
}

/// Loads the license body without its optional title, BOM or outer whitespace and uses native edit line
/// endings.
wchar_t* AboutForm::LoadLicenseText() const {
    HMODULE module = GetModuleHandleW(nullptr);
    HRSRC resource = FindResourceW(module, MAKEINTRESOURCEW(IDR_LICENSE), RT_RCDATA);
    HGLOBAL loaded = resource ? LoadResource(module, resource) : nullptr;
    const wchar_t* source = loaded ? static_cast<const wchar_t*>(LockResource(loaded)) : nullptr;
    DWORD length = resource ? SizeofResource(module, resource) / sizeof(wchar_t) : 0;
    if (!source || !length) {
        return nullptr;
    }
    if (*source == 0xFEFF) {
        ++source;
        --length;
    }
    while (length && IsTextWhitespace(*source)) {
        ++source;
        --length;
    }
    DWORD firstLine = 0;
    while (firstLine < length && source[firstLine] != L'\r' && source[firstLine] != L'\n') {
        ++firstLine;
    }
    wchar_t heading[ARRAYSIZE(licenseHeading)] = {};
    UINT headingLength = 0;
    bool whitespace = false;
    for (DWORD index = 0; index < firstLine && headingLength < ARRAYSIZE(heading); ++index) {
        if (IsTextWhitespace(source[index])) {
            whitespace = true;
        } else {
            if (whitespace && headingLength) {
                heading[headingLength++] = L' ';
            }
            if (headingLength < ARRAYSIZE(heading)) {
                heading[headingLength++] = source[index];
            }
            whitespace = false;
        }
    }
    if (headingLength < ARRAYSIZE(heading)) {
        heading[headingLength] = 0;
        if (!lstrcmpiW(heading, licenseHeading)) {
            source += firstLine;
            length -= firstLine;
        }
    }
    while (length && IsTextWhitespace(*source)) {
        ++source;
        --length;
    }
    while (length && (!source[length - 1] || IsTextWhitespace(source[length - 1]))) {
        --length;
    }
    SIZE_T characters = length;
    for (DWORD index = 0; index < length; ++index) {
        if (source[index] == L'\n' && (!index || source[index - 1] != L'\r')) {
            ++characters;
        }
    }
    wchar_t* text = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0, (characters + 1) * sizeof(wchar_t)));
    if (text) {
        SIZE_T written = 0;
        for (DWORD index = 0; index < length; ++index) {
            if (source[index] == L'\n' && (!index || source[index - 1] != L'\r')) {
                text[written++] = L'\r';
            }
            text[written++] = source[index];
        }
        text[written] = 0;
    }
    return text;
}

/// Opens the application website in the default browser and reports launch failures.
void AboutForm::OpenWebsite() const {
    HINSTANCE result = ShellExecuteW(window, L"open", websiteUrl, nullptr, nullptr, SW_SHOWNORMAL);
    if (reinterpret_cast<INT_PTR>(result) <= 32) {
        MessageBoxW(window, T(TXT_WEBSITE_OPEN_FAILED), GetApplicationName(), MB_OK | MB_ICONERROR);
    }
}

/// Shows the native context commands appropriate to the product information or website link.
void AboutForm::ShowContextMenu(HWND source, LPARAM location) const {
    HMENU menu = CreatePopupMenu();
    if (!menu) {
        return;
    }
    if (GetDlgCtrlID(source) == IDC_INFO_LINK) {
        AppendMenuW(menu, MF_STRING, openWebsiteCommand, T(TXT_OPEN_WEBSITE));
        AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
        AppendMenuW(menu, MF_STRING, copyUrlCommand, T(TXT_COPY_URL));
        AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    }
    AppendMenuW(menu, MF_STRING, copyInformationCommand, T(TXT_COPY_INFORMATION));
    POINT point = POINT{ GET_X_LPARAM(location), GET_Y_LPARAM(location) };
    if (location == -1) {
        RECT bounds = RECT{};
        GetWindowRect(source, &bounds);
        point = POINT{ bounds.left, bounds.bottom };
    }
    UINT command = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, point.x, point.y, 0,
        window, nullptr);
    DestroyMenu(menu);
    if (command == openWebsiteCommand) {
        OpenWebsite();
    } else if (command == copyUrlCommand) {
        if (!CopyTextToClipboard(window, websiteUrl)) {
            MessageBoxW(window, T(TXT_COPY_URL_FAILED), GetApplicationName(), MB_OK | MB_ICONERROR);
        }
    } else if (command == copyInformationCommand) {
        CopyInformation();
    }
}

/// Routes About context, cursor and fallback-link completed clicks, keyboard, focus and painting messages.
LRESULT CALLBACK AboutForm::ControlSubclassProc(HWND control, UINT message, WPARAM wParam, LPARAM lParam) {
    AboutForm* owner = static_cast<AboutForm*>(GetPropW(control, ownerProperty));
    WNDPROC original = reinterpret_cast<WNDPROC>(GetPropW(control, originalProperty));
    if (owner) {
        if (message == WM_CONTEXTMENU) {
            owner->ShowContextMenu(control, lParam);
            return 0;
        }
        if (GetDlgCtrlID(control) == IDC_INFO_LINK) {
            if (message == WM_SETCURSOR && LOWORD(lParam) == HTCLIENT && owner->hand) {
                SetCursor(owner->hand);
                return TRUE;
            }
            if (!owner->nativeLink) {
                if (message == WM_SETFOCUS || message == WM_KILLFOCUS) {
                    LRESULT result = CallWindowProcW(original, control, message, wParam, lParam);
                    InvalidateRect(control, nullptr, TRUE);
                    return result;
                }
                if (message == WM_LBUTTONDOWN || message == WM_LBUTTONDBLCLK) {
                    SetFocus(control);
                    SetCapture(control);
                    return 0;
                }
                if (message == WM_LBUTTONUP) {
                    if (GetCapture() == control) {
                        ReleaseCapture();
                        RECT bounds = RECT{};
                        GetClientRect(control, &bounds);
                        POINT point = POINT{ GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
                        if (PtInRect(&bounds, point)) {
                            owner->OpenWebsite();
                        }
                    }
                    return 0;
                }
                if (message == WM_CANCELMODE) {
                    if (GetCapture() == control) {
                        ReleaseCapture();
                    }
                    return 0;
                }
                if (message == WM_GETDLGCODE) {
                    LRESULT code = CallWindowProcW(original, control, message, wParam, lParam) & ~DLGC_STATIC;
                    if (wParam == VK_RETURN || wParam == VK_SPACE) {
                        code |= DLGC_WANTMESSAGE;
                    }
                    return code;
                }
                if (message == WM_CHAR && (wParam == VK_RETURN || wParam == VK_SPACE)) {
                    return 0;
                }
                if (message == WM_PAINT) {
                    PAINTSTRUCT paint = PAINTSTRUCT{};
                    HDC dc = BeginPaint(control, &paint);
                    PaintLink(control, dc);
                    EndPaint(control, &paint);
                    return 0;
                }
                if (message == WM_PRINTCLIENT || message == WM_PRINT) {
                    if (message == WM_PRINT
                        && (!(lParam & PRF_CLIENT)
                            || lParam & PRF_CHECKVISIBLE && !IsWindowVisible(control))) {
                        return 0;
                    }
                    PaintLink(control, reinterpret_cast<HDC>(wParam));
                    return 0;
                }
            }
            if (message == WM_MBUTTONUP
                || !owner->nativeLink
                    && message == WM_KEYDOWN
                    && (wParam == VK_RETURN || wParam == VK_SPACE)) {
                owner->OpenWebsite();
                return 0;
            }
        }
    }
    if (message == WM_NCDESTROY) {
        if (original) {
            SetWindowLongPtrW(control, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(original));
        }
        RemovePropW(control, originalProperty);
        RemovePropW(control, ownerProperty);
    }
    if (original) {
        return CallWindowProcW(original, control, message, wParam, lParam);
    }
    return DefWindowProcW(control, message, wParam, lParam);
}

/// Returns this form's native window, or null while it is closed.
HWND AboutForm::GetWindow() const {
    return window;
}

/// Destroys this form and releases its controls and owned fonts.
void AboutForm::Close() const {
    if (window != nullptr) {
        if (modal) {
            EndDialog(window, IDCANCEL);
        } else {
            DestroyWindow(window);
        }
    }
}

/// Refreshes the localized title, product header and website label.
void AboutForm::RefreshLanguage() {
    if (!window) {
        return;
    }
    wchar_t title[384];
    BuildAboutTitle(title);
    SetWindowTextW(window, title);
    SetDlgItemTextW(window, IDOK, T(TXT_CLOSE));
    wchar_t product[768];
    BuildAboutProductText(product);
    SetDlgItemTextW(window, IDC_INFO_PRODUCT, product);
    SetDlgItemTextW(window, IDC_INFO_WEBSITE, T(TXT_WEBSITE_LABEL));
    Layout();
}

/// Applies the effective interface font and current theme while keeping the About license in Consolas.
bool AboutForm::ApplyStyle(bool updateFont) {
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
    HFONT nextLicenseFont = CreateAboutFont(window);
    if (nextLicenseFont == nullptr) {
        if (updateFont) {
            DeleteObject(font);
        }
        return false;
    }
    LOGFONTW link = LOGFONTW{};
    GetObjectW(font, sizeof(link), &link);
    link.lfUnderline = TRUE;
    HFONT nextLinkFont = CreateFontIndirectW(&link);
    if (nextLinkFont == nullptr) {
        DeleteObject(nextLicenseFont);
        if (updateFont) {
            DeleteObject(font);
        }
        return false;
    }
    HFONT previousFont = ownsFont && uiFont != font ? uiFont : nullptr;
    ownsFont = updateFont || ownsFont && uiFont == font;
    uiFont = font;
    SendMessageW(window, WM_SETFONT, reinterpret_cast<WPARAM>(font), FALSE);
    const int ids[] = { IDC_INFO_PRODUCT, IDC_INFO_WEBSITE, IDC_INFO_LINK, IDC_INFO_TEXT, IDOK };
    for (int id : ids) {
        HWND control = GetDlgItem(window, id);
        if (control == nullptr) {
            continue;
        }
        HFONT selected = id == IDC_INFO_TEXT ? nextLicenseFont : font;
        if (id == IDC_INFO_LINK && !nativeLink) {
            selected = nextLinkFont;
        }
        SendMessageW(control, WM_SETFONT, reinterpret_cast<WPARAM>(selected), FALSE);
    }
    if (tooltip != nullptr) {
        SendMessageW(tooltip, WM_SETFONT, reinterpret_cast<WPARAM>(font), FALSE);
    }
    if (previousFont != nullptr) {
        DeleteObject(previousFont);
    }
    if (licenseFont != nullptr) {
        DeleteObject(licenseFont);
    }
    licenseFont = nextLicenseFont;
    if (linkFont != nullptr) {
        DeleteObject(linkFont);
    }
    linkFont = nextLinkFont;
    int size = GetSystemDialogDpi(window) >= ABOUT_LARGE_ICON_DPI ? ABOUT_LARGE_ICON_SIZE : ABOUT_ICON_SIZE;
    HICON icon = static_cast<HICON>(LoadImageW(GetModuleHandleW(nullptr), MAKEINTRESOURCEW(IDI_MEDIAINFO),
        IMAGE_ICON, size, size, LR_SHARED));
    SendDlgItemMessageW(window, IDC_INFO_ICON, STM_SETICON, reinterpret_cast<WPARAM>(icon), 0);
    SetWindowPos(GetDlgItem(window, IDC_INFO_ICON), nullptr, 0, 0, size, size,
        SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    UpdateWindowIcons(window, IDI_MEDIAINFO);
    Layout();
    RedrawWindow(window, nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_FRAME | RDW_ALLCHILDREN);
    return true;
}

/// Fits the About window to its monitor work area after its natural layout.
void AboutForm::FitToWorkArea() const {
    RECT bounds = RECT{};
    if (!GetWindowRect(window, &bounds)) {
        return;
    }
    RECT work = WindowWorkArea(bounds);
    LONG width = bounds.right - bounds.left;
    LONG height = bounds.bottom - bounds.top;
    if (width > work.right - work.left) {
        width = work.right - work.left;
    }
    if (height > work.bottom - work.top) {
        height = work.bottom - work.top;
    }
    LONG left = bounds.left;
    LONG top = bounds.top;
    if (left < work.left) {
        left = work.left;
    } else if (left > work.right - width) {
        left = work.right - width;
    }
    if (top < work.top) {
        top = work.top;
    } else if (top > work.bottom - height) {
        top = work.bottom - height;
    }
    if (left != bounds.left
            || top != bounds.top
            || width != bounds.right - bounds.left
            || height != bounds.bottom - bounds.top) {
        SetWindowPos(window, nullptr, left, top, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    }
}

/// Builds the natural About layout from its fixed license dimensions, then fits it to the monitor work area.
/// Resize notifications anchor the edit to the right and bottom edges and the Close button to the bottom
/// right.
void AboutForm::Layout(bool resize) const {
    if (!initialized || IsIconic(window)) {
        return;
    }
    RECT client = {};
    GetClientRect(window, &client);
    SIZE current = { client.right, client.bottom };
    UINT dpi = GetSystemDialogDpi(window);
    SIZE margin = DialogUnits(uiFont, 8, 8);
    SIZE gap = DialogUnits(uiFont, 4, 6);
    SIZE button = DialogButtonSize(GetDlgItem(window, IDOK), IDD_ABOUT);
    int textTop = margin.cy;
    if (resize) {
        SIZE license = {
            MulDiv(referenceLicense.cx, dpi, referenceDpi),
            MulDiv(referenceLicense.cy, dpi, referenceDpi)
        };
        client.right = license.cx + 2 * DialogUnits(uiFont, 10, 0).cx;
        SetWindowPos(GetDlgItem(window, IDC_INFO_ICON), nullptr, margin.cx, margin.cy, 0, 0,
            SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
        RECT icon = InformationControlRect(window, IDC_INFO_ICON);
        SIZE productPosition = DialogUnits(uiFont, 0, 4);
        productPosition.cx = icon.right + icon.left;
        int width = client.right - margin.cx - productPosition.cx;
        int productHeight = WrappedLabelHeight(GetDlgItem(window, IDC_INFO_PRODUCT), width);
        PlaceControl(GetDlgItem(window, IDC_INFO_PRODUCT), productPosition.cx, productPosition.cy, width,
            productHeight);
        SIZE website = InformationTextSize(GetDlgItem(window, IDC_INFO_WEBSITE));
        int websiteY = productPosition.cy + productHeight + gap.cy;
        PlaceControl(GetDlgItem(window, IDC_INFO_WEBSITE), productPosition.cx, websiteY, website.cx,
            website.cy);
        int linkX = productPosition.cx + website.cx + gap.cx;
        int linkWidth = client.right - margin.cx - linkX;
        SIZE idealLink = {};
        int linkHeight = website.cy;
        if (nativeLink) {
            LRESULT height = SendDlgItemMessageW(window, IDC_INFO_LINK, LM_GETIDEALSIZE, linkWidth,
                reinterpret_cast<LPARAM>(&idealLink));
            if (height > 0) {
                linkHeight = static_cast<int>(height);
            }
            if (idealLink.cx > 0 && idealLink.cx < linkWidth) {
                linkWidth = idealLink.cx;
            }
        } else {
            SIZE text = InformationTextSize(GetDlgItem(window, IDC_INFO_LINK));
            if (text.cx > 0 && text.cx < linkWidth) {
                linkWidth = text.cx;
            }
            linkHeight = text.cy;
        }
        PlaceControl(GetDlgItem(window, IDC_INFO_LINK), linkX, websiteY, linkWidth, linkHeight);
        AlignControlBaseline(GetDlgItem(window, IDC_INFO_LINK), GetDlgItem(window, IDC_INFO_WEBSITE));
        RECT link = InformationControlRect(window, IDC_INFO_LINK);
        textTop = websiteY + website.cy;
        if (link.bottom > textTop) {
            textTop = link.bottom;
        }
        textTop += gap.cy;
        client.bottom = textTop + license.cy + gap.cy + button.cy + margin.cy;
        if (client.right != current.cx || client.bottom != current.cy) {
            RECT bounds = {};
            GetWindowRect(window, &bounds);
            SetWindowPos(window, nullptr, 0, 0, bounds.right - bounds.left + client.right - current.cx,
                bounds.bottom - bounds.top + client.bottom - current.cy,
                SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
        }
    }
    if (!resize) {
        textTop = InformationControlRect(window, IDC_INFO_TEXT).top;
    }
    int buttonY = client.bottom - margin.cy - button.cy;
    PlaceControl(GetDlgItem(window, IDOK), client.right - margin.cx - button.cx, buttonY, button.cx,
        button.cy);
    PlaceControl(GetDlgItem(window, IDC_INFO_TEXT), margin.cx, textTop,
        client.right - 2 * margin.cx, buttonY - gap.cy - textTop);
    if (resize) {
        FitToWorkArea();
    }
}

/// Handles this form's native commands, layout, theme, DPI changes and resource cleanup.
INT_PTR AboutForm::HandleMessage(UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_CLOSE
            || message == WM_COMMAND && (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)) {
        Close();
        return TRUE;
    }
    if (message == WM_SIZE) {
        Layout(false);
        return TRUE;
    }
    if (message == WM_DRAWITEM && wParam == IDC_INFO_PRODUCT) {
        return DrawWrappedTextItem(reinterpret_cast<const DRAWITEMSTRUCT*>(lParam));
    }
    if (message == WM_CTLCOLORDLG && !AreVisualStylesActive()) {
        return reinterpret_cast<INT_PTR>(GetSysColorBrush(COLOR_BTNFACE));
    }
    if (message == WM_CTLCOLORSTATIC
            && !nativeLink && reinterpret_cast<HWND>(lParam) == GetDlgItem(window, IDC_INFO_LINK)) {
        SetTextColor(reinterpret_cast<HDC>(wParam), RGB(0, 0, 255));
        SetBkColor(reinterpret_cast<HDC>(wParam), GetSysColor(COLOR_BTNFACE));
        return reinterpret_cast<INT_PTR>(GetSysColorBrush(COLOR_BTNFACE));
    }
    if (message == WM_NOTIFY) {
        NMHDR* notification = reinterpret_cast<NMHDR*>(lParam);
        if (nativeLink
                && notification->hwndFrom == GetDlgItem(window, IDC_INFO_LINK)
                && (notification->code == NM_CLICK || notification->code == NM_RETURN)) {
            OpenWebsite();
            SetWindowLongPtrW(window, DWLP_MSGRESULT, 0);
            return TRUE;
        }
    }
    if (message == WM_DISPLAYCHANGE) {
        Layout();
        return TRUE;
    }
    if (message == WM_THEMECHANGED || message == WM_SETTINGCHANGE) {
        ApplyStyle(true);
        return TRUE;
    }
    if (message == WM_DPICHANGED) {
        if (GetProcAddress(GetModuleHandleW(L"user32.dll"), "GetDialogDpiChangeBehavior") == nullptr) {
            RECT* bounds = reinterpret_cast<RECT*>(lParam);
            SetWindowPos(window, nullptr, bounds->left, bounds->top, bounds->right - bounds->left,
                bounds->bottom - bounds->top, SWP_NOZORDER | SWP_NOACTIVATE);
            ApplyStyle(true);
            return TRUE;
        }
        PostMessageW(window, nativeDialogDpiChangedMessage, 0, 0);
        return FALSE;
    }
    if (message == nativeDialogDpiChangedMessage) {
        ApplyStyle(false);
        return TRUE;
    }
    if (message == WM_DESTROY) {
        DetachControls();
        return TRUE;
    }
    if (message == WM_NCDESTROY) {
        ClearWindowIcons(window);
        if (ownsFont) {
            DeleteObject(uiFont);
        }
        uiFont = nullptr;
        ownsFont = false;
        initialized = false;
        ResetInformationWordBreak();
        if (licenseFont != nullptr) {
            DeleteObject(licenseFont);
            licenseFont = nullptr;
        }
        if (linkFont != nullptr) {
            DeleteObject(linkFont);
            linkFont = nullptr;
        }
        window = nullptr;
    }
    return FALSE;
}

/// Associates the native dialog with its form object and dispatches only this form's messages.
INT_PTR CALLBACK AboutForm::DialogProc(HWND dialog, UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_INITDIALOG) {
        AboutForm* form = reinterpret_cast<AboutForm*>(lParam);
        form->window = dialog;
        SetWindowLongPtrW(dialog, DWLP_USER, reinterpret_cast<LONG_PTR>(form));
        if (!form->Initialize()) {
            form->Close();
        }
        return FALSE;
    }
    AboutForm* form = reinterpret_cast<AboutForm*>(GetWindowLongPtrW(dialog, DWLP_USER));
    return form == nullptr ? FALSE : form->HandleMessage(message, wParam, lParam);
}

/// Loads the license, installs native controls and restores the position retained in memory.
bool AboutForm::Initialize() {
    if (modal) {
        LONG_PTR extended = GetWindowLongPtrW(window, GWL_EXSTYLE);
        SetWindowLongPtrW(window, GWL_EXSTYLE, extended & ~WS_EX_APPWINDOW | WS_EX_DLGMODALFRAME);
        SetWindowPos(window, nullptr, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
    }
    uiFont = reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    BuildAboutWebsiteUrl(websiteUrl);
    referenceDpi = GetSystemDialogDpi(window);
    referenceLicense = SIZE{
        MulDiv(ABOUT_LICENSE_WIDTH_96DPI, referenceDpi, 96),
        MulDiv(ABOUT_LICENSE_HEIGHT_96DPI, referenceDpi, 96)
    };
    initialized = true;
    HWND edit = GetDlgItem(window, IDC_INFO_TEXT);
    if (!InstallSelectionEditHandler(edit) || !ApplyStyle(false)) {
        return false;
    }
    SendMessageW(edit, EM_SETLIMITTEXT, 0x7FFFFFFE, 0);
    InstallInformationWordBreak(edit);
    WNDPROC original = reinterpret_cast<WNDPROC>(GetWindowLongPtrW(edit, GWLP_WNDPROC));
    if (!SetPropW(edit, licenseOriginalProperty, reinterpret_cast<HANDLE>(original))) {
        return false;
    }
    SetLastError(0);
    const LONG_PTR previousProc = SetWindowLongPtrW(edit, GWLP_WNDPROC,
        reinterpret_cast<LONG_PTR>(AboutLicenseSubclassProc));
    if (!previousProc && GetLastError()) {
        RemovePropW(edit, licenseOriginalProperty);
        return false;
    }
    wchar_t* license = LoadLicenseText();
    SetWindowTextW(edit, license ? license : T(TXT_LICENSE_UNAVAILABLE));
    if (license) {
        HeapFree(GetProcessHeap(), 0, license);
    }
    RefreshLanguage();
    if (!AttachControls()) {
        return false;
    }
    Layout();
    if (!ApplyInitialPosition() || !placement.Attach(window, "AboutWindow")) {
        return false;
    }
    SetFocus(GetDlgItem(window, IDOK));
    SendDlgItemMessageW(window, IDC_INFO_TEXT, EM_SETSEL, 0, 0);
    if (!modal) {
        placement.Show();
    }
    return true;
}

/// Creates or activates About, optionally using the native modal dialog loop.
void AboutForm::Show(HWND owner, DialogPosition position, bool modalDialog) {
    if (window != nullptr && IsWindow(window)) {
        placement.BringToFront();
        return;
    }
    ownerWindow = owner;
    initialPosition = position;
    modal = modalDialog;
    initialized = false;
    placement.SetUseWindowsDefaultLocation(position == DialogPosition::WindowsDefault);
    HINSTANCE instance = GetModuleHandleW(nullptr);
    DLGTEMPLATE* definition = LoadSystemDialogTemplate(instance, IDD_ABOUT, owner);
    if (definition == nullptr) {
        return;
    }
    if (modal) {
        DialogBoxIndirectParamW(instance, definition, ownerWindow, DialogProc,
            reinterpret_cast<LPARAM>(this));
    } else {
        CreateDialogIndirectParamW(instance, definition, nullptr, DialogProc,
            reinterpret_cast<LPARAM>(this));
    }
    HeapFree(GetProcessHeap(), 0, definition);
}

/// Initializes an unopened About form and its owned resources.
AboutForm::AboutForm()
        : linkFont(nullptr),
        hand(nullptr),
        legacyCursorModule(nullptr),
        initialPosition(DialogPosition::Template),
        nativeLink(false) {
    websiteUrl[0] = 0;
    placement.SetDisableSaveSize(true);
    placement.SetDisableSaveWindowState(true);
    placement.SetSavingOptions(PersistWindowStateSavingOptions::None);
    placement.SetDetectionOptions(WindowDetectionOptions::NoDetection);
    placement.SetUseWindowsDefaultLocation(false);
    placement.SetUseWindowsDefaultSize(false);
}

/// Closes the dialog and releases its fonts, tooltip and control subclasses.
AboutForm::~AboutForm() {
    Close();
    DetachControls();
    if (ownsFont) {
        DeleteObject(uiFont);
    }
    if (licenseFont) {
        DeleteObject(licenseFont);
    }
    if (linkFont) {
        DeleteObject(linkFont);
    }
}

/// Routes modeless keyboard input through the native dialog manager.
bool AboutForm::Translate(MSG* message) {
    return !modal
        && window
        && (message->hwnd == window || IsChild(window, message->hwnd))
        && IsDialogMessageW(window, message);
}

/// Applies the requested initial placement while leaving a retained position to PersistWindowState.
bool AboutForm::ApplyInitialPosition() {
    if (initialPosition != DialogPosition::CenterParent
            && initialPosition != DialogPosition::CenterScreen) {
        return true;
    }
    const PersistWindowStateData& saved = placement.GetState();
    if (saved.x != CW_USEDEFAULT && saved.y != CW_USEDEFAULT) {
        return true;
    }
    RECT bounds = RECT{};
    if (!GetWindowRect(window, &bounds)) {
        return false;
    }
    RECT reference = bounds;
    if (ownerWindow && !GetWindowRect(ownerWindow, &reference)) {
        return false;
    }
    if (initialPosition == DialogPosition::CenterScreen || !ownerWindow) {
        reference = WindowWorkArea(reference);
    }
    int x = reference.left + (reference.right - reference.left - bounds.right + bounds.left) / 2;
    int y = reference.top + (reference.bottom - reference.top - bounds.bottom + bounds.top) / 2;
    return SetWindowPos(window, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE) != FALSE;
}

/// Replaces the static website control with a native SysLink when the installed controls support it.
void AboutForm::CreateNativeLink() {
    HMODULE commonControls = GetModuleHandleW(L"comctl32.dll");
    InitializeControlsFunction initialize;
    if (commonControls) {
        initialize = reinterpret_cast<InitializeControlsFunction>(GetProcAddress(commonControls,
            "InitCommonControlsEx"));
    } else {
        initialize = nullptr;
    }
    INITCOMMONCONTROLSEX controls = INITCOMMONCONTROLSEX{ sizeof(controls), ICC_LINK_CLASS };
    if (!initialize || !initialize(&controls)) {
        return;
    }
    HWND original = GetDlgItem(window, IDC_INFO_LINK);
    RECT bounds = ControlRect(original, window);
    wchar_t markup[2 * ARRAYSIZE(websiteUrl) + 32];
    wsprintfW(markup, L"<a href=\"%s\">%s</a>", websiteUrl, websiteUrl);
    HWND link = CreateWindowExW(0, WC_LINK, markup, WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_CLIPSIBLINGS,
        bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, window, nullptr,
        GetModuleHandleW(nullptr), nullptr);
    if (!link) {
        return;
    }
    SendMessageW(link, WM_SETFONT, SendDlgItemMessageW(window, IDC_INFO_WEBSITE, WM_GETFONT, 0, 0), FALSE);
    SetWindowPos(link, ::GetWindow(original, GW_HWNDPREV), 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    DestroyWindow(original);
    SetWindowLongPtrW(link, GWLP_ID, IDC_INFO_LINK);
    nativeLink = true;
}

/// Installs About control handlers, the native hand cursor and a localized website tooltip.
bool AboutForm::AttachControls() {
    DetachControls();
    SetDlgItemTextW(window, IDC_INFO_LINK, websiteUrl);
    CreateNativeLink();
    hand = LoadCursorW(nullptr, IDC_HAND);
    if (!hand) {
        wchar_t path[MAX_PATH];
        UINT length = GetWindowsDirectoryW(path, MAX_PATH);
        if (length && length + lstrlenW(L"\\winhlp32.exe") < MAX_PATH) {
            lstrcatW(path, L"\\winhlp32.exe");
            legacyCursorModule = LoadLibraryExW(path, nullptr, LOAD_LIBRARY_AS_DATAFILE);
            if (legacyCursorModule) {
                hand = LoadCursorW(legacyCursorModule, MAKEINTRESOURCEW(106));
            }
        }
    }
    if (!hand) {
        hand = LoadCursorW(nullptr, IDC_ARROW);
    }
    for (int id : aboutControls) {
        HWND control = GetDlgItem(window, id);
        if (id != IDC_INFO_LINK || !nativeLink) {
            SetWindowLongW(control, GWL_STYLE, GetWindowLongW(control, GWL_STYLE) | SS_NOTIFY);
        }
        WNDPROC original = reinterpret_cast<WNDPROC>(GetWindowLongPtrW(control, GWLP_WNDPROC));
        if (!SetPropW(control, ownerProperty, this)) {
            DetachControls();
            return false;
        }
        if (!SetPropW(control, originalProperty, reinterpret_cast<HANDLE>(original))) {
            RemovePropW(control, ownerProperty);
            DetachControls();
            return false;
        }
        SetLastError(0);
        const LONG_PTR previousProc = SetWindowLongPtrW(control, GWLP_WNDPROC,
            reinterpret_cast<LONG_PTR>(ControlSubclassProc));
        if (!previousProc && GetLastError()) {
            RemovePropW(control, originalProperty);
            RemovePropW(control, ownerProperty);
            DetachControls();
            return false;
        }
    }
    tooltip = CreateWindowExW(WS_EX_TOPMOST, TOOLTIPS_CLASSW, nullptr,
        WS_POPUP | TTS_ALWAYSTIP | TTS_NOPREFIX, CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT, window, nullptr, GetModuleHandleW(nullptr), nullptr);
    if (!tooltip) {
        DetachControls();
        return false;
    }
    wsprintfW(tooltipText, T(TXT_WEBSITE_TOOLTIP), websiteUrl);
    TOOLINFOW information = TOOLINFOW{};
    information.cbSize = TTTOOLINFOW_V1_SIZE;
    information.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
    information.hwnd = window;
    information.uId = reinterpret_cast<UINT_PTR>(GetDlgItem(window, IDC_INFO_LINK));
    information.lpszText = tooltipText;
    if (!SendMessageW(tooltip, TTM_ADDTOOLW, 0, reinterpret_cast<LPARAM>(&information))) {
        const int length = WideCharToMultiByte(CP_ACP, 0, tooltipText, -1, ansiTooltipText,
            sizeof(ansiTooltipText), nullptr, nullptr);
        if (!length) {
            DetachControls();
            return false;
        }
        TOOLINFOA legacy = TOOLINFOA{};
        legacy.cbSize = TTTOOLINFOA_V1_SIZE;
        legacy.uFlags = information.uFlags;
        legacy.hwnd = window;
        legacy.uId = information.uId;
        legacy.lpszText = ansiTooltipText;
        if (!SendMessageA(tooltip, TTM_ADDTOOLA, 0, reinterpret_cast<LPARAM>(&legacy))) {
            DetachControls();
            return false;
        }
    }
    return true;
}

/// Removes About subclasses and releases interaction resources while preserving their windows.
void AboutForm::DetachControls() {
    if (tooltip && IsWindow(tooltip)) {
        DestroyWindow(tooltip);
    }
    tooltip = nullptr;
    if (window && IsWindow(window)) {
        for (int id : aboutControls) {
            HWND control = GetDlgItem(window, id);
            if (GetPropW(control, ownerProperty) == this) {
                WNDPROC original = reinterpret_cast<WNDPROC>(GetPropW(control, originalProperty));
                if (original) {
                    SetWindowLongPtrW(control, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(original));
                }
                RemovePropW(control, originalProperty);
                RemovePropW(control, ownerProperty);
            }
        }
    }
    hand = nullptr;
    nativeLink = false;
    if (legacyCursorModule) {
        FreeLibrary(legacyCursorModule);
        legacyCursorModule = nullptr;
    }
}

/// Copies the About product information and website address as Unicode text.
void AboutForm::CopyInformation() const {
    wchar_t* product = CopyControlText(GetDlgItem(window, IDC_INFO_PRODUCT));
    if (!product) {
        return;
    }
    const wchar_t* label = T(TXT_ABOUT_WEBSITE_APPEND);
    SIZE_T characters = static_cast<SIZE_T>(lstrlenW(product)) + lstrlenW(websiteUrl) + lstrlenW(label) + 1;
    wchar_t* text = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0, characters * sizeof(wchar_t)));
    if (text) {
        lstrcpyW(text, product);
        lstrcatW(text, label);
        lstrcatW(text, websiteUrl);
        if (!CopyTextToClipboard(window, text)) {
            MessageBoxW(window, T(TXT_COPY_INFORMATION_FAILED), GetApplicationName(), MB_OK | MB_ICONERROR);
        }
        HeapFree(GetProcessHeap(), 0, text);
    }
    HeapFree(GetProcessHeap(), 0, product);
}

/// Draws the static link with native GDI and an uninset focus rectangle without optional printing support.
void AboutForm::PaintLink(HWND control, HDC dc) {
    int saved = SaveDC(dc);
    RECT bounds = RECT{};
    GetClientRect(control, &bounds);
    HFONT font = reinterpret_cast<HFONT>(SendMessageW(control, WM_GETFONT, 0, 0));
    if (font) {
        SelectObject(dc, font);
    }
    HBRUSH background = reinterpret_cast<HBRUSH>(SendMessageW(GetParent(control), WM_CTLCOLORSTATIC,
        reinterpret_cast<WPARAM>(dc), reinterpret_cast<LPARAM>(control)));
    FillRect(dc, &bounds, background ? background : GetSysColorBrush(COLOR_BTNFACE));
    SetBkMode(dc, TRANSPARENT);
    wchar_t text[256];
    int length = GetWindowTextW(control, text, ARRAYSIZE(text));
    DrawTextW(dc, text, length, &bounds, DT_LEFT | DT_TOP | DT_SINGLELINE | DT_NOPREFIX);
    if (GetFocus() == control) {
        SetTextColor(dc, RGB(0, 0, 0));
        SetBkColor(dc, RGB(255, 255, 255));
        DrawFocusRect(dc, &bounds);
    }
    if (saved) {
        RestoreDC(dc, saved);
    }
}
