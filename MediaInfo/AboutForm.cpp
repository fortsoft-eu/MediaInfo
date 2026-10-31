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

/// Optional common-controls initialization entry point.
typedef BOOL(WINAPI* InitializeControlsFunction)(const INITCOMMONCONTROLSEX*);

/// Control-subclass properties and the application website address.
static const wchar_t ownerProperty[] = L"MediaInfo.AboutOwner";
static const wchar_t originalProperty[] = L"MediaInfo.AboutOriginal";
static const wchar_t websiteRoot[] = L"https://fortsoft.eu/";

/// About context-menu commands and the controls that expose them.
static const UINT openWebsiteCommand = 1;
static const UINT copyUrlCommand = 2;
static const UINT copyInformationCommand = 3;
static const int aboutControls[] = { IDC_INFO_PRODUCT, IDC_INFO_WEBSITE, IDC_INFO_LINK, IDC_INFO_ICON };

/// Optional title removed before the embedded license body is displayed.
static const wchar_t licenseHeading[] = L"MIT License";

/// Loads the executable version resource for product-name and version queries; the caller frees the buffer.
static BYTE* LoadApplicationVersionInfo() {
    wchar_t path[MAX_PATH] = {};
    DWORD length = GetModuleFileNameW(nullptr, path, ARRAYSIZE(path));
    if (!length || length >= ARRAYSIZE(path)) {
        return nullptr;
    }
    DWORD ignored = 0;
    DWORD size = GetFileVersionInfoSizeW(path, &ignored);
    if (!size) {
        return nullptr;
    }
    BYTE* data = static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), 0, size));
    if (data && !GetFileVersionInfoW(path, 0, size, data)) {
        HeapFree(GetProcessHeap(), 0, data);
        return nullptr;
    }
    return data;
}

/// Returns a borrowed product name from the declared version-resource translation tables, or ? if unavailable.
static const wchar_t* GetApplicationName(const BYTE* data) {
    WORD* translations = nullptr;
    UINT translationBytes = 0;
    if (!data || !VerQueryValueW(data, L"\\VarFileInfo\\Translation",
            reinterpret_cast<void**>(&translations), &translationBytes) || !translations) {
        return L"?";
    }
    for (UINT index = 0; index + 1 < translationBytes / sizeof(WORD); index += 2) {
        wchar_t query[64];
        wsprintfW(query, L"\\StringFileInfo\\%04X%04X\\ProductName", translations[index],
            translations[index + 1]);
        wchar_t* name = nullptr;
        UINT length = 0;
        if (VerQueryValueW(data, query, reinterpret_cast<void**>(&name), &length)
                && name
                && length > 1
                && name[0]) {
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
    if (data
            && VerQueryValueW(data, L"\\", reinterpret_cast<void**>(&information), &informationSize)
            && information
            && informationSize >= sizeof(VS_FIXEDFILEINFO)
            && information->dwSignature == VS_FFI_SIGNATURE) {
        wsprintfW(version, L"%u.%u.%u.%u",
            HIWORD(information->dwProductVersionMS),
            LOWORD(information->dwProductVersionMS),
            HIWORD(information->dwProductVersionLS),
            LOWORD(information->dwProductVersionLS));
    }
}

/// Inserts the executable product name into the localized About title, preserving its language-specific order.
static void BuildAboutTitle(wchar_t* title) {
    BYTE* data = LoadApplicationVersionInfo();
    wsprintfW(title, T(TXT_ABOUT_TITLE), GetApplicationName(data));
    if (data) {
        HeapFree(GetProcessHeap(), 0, data);
    }
}

/// Builds the localized product header with the executable product name, version and bundled-library versions.
static void BuildAboutProductText(wchar_t* product) {
    BYTE* data = LoadApplicationVersionInfo();
    wchar_t version[48];
    GetApplicationVersion(data, version);
    wsprintfW(product, L"%s\r\n%s\r\n\r\n%s %s\r\nCopyright © Petr Červinka — FortSoft 2026\r\n%s Win32"
        L" (x86)\r\n%s %s, %s, %s\r\n%s %s", GetApplicationName(data), T(TXT_APPLICATION_DESCRIPTION),
        T(TXT_VERSION), version, T(TXT_PLATFORM), T(TXT_EMBEDDED_MEDIALIB), bundledMediaInfoVersions[0],
        bundledMediaInfoVersions[1], bundledMediaInfoVersions[2], T(TXT_EMBEDDED_CURL), bundledCurlVersions);
    if (data) {
        HeapFree(GetProcessHeap(), 0, data);
    }
}

/// Builds the product website URL in a MAX_PATH buffer using the lowercase executable product name.
static void BuildAboutWebsiteUrl(wchar_t* website) {
    BYTE* data = LoadApplicationVersionInfo();
    UINT rootLength = ARRAYSIZE(websiteRoot) - 1;
    lstrcpyW(website, websiteRoot);
    lstrcpynW(website + rootLength, GetApplicationName(data), MAX_PATH - rootLength - 1);
    CharLowerBuffW(website + rootLength, lstrlenW(website + rootLength));
    lstrcatW(website, L"/");
    if (data) {
        HeapFree(GetProcessHeap(), 0, data);
    }
}

/// Loads the license body without its optional title, BOM or outer whitespace and uses native edit line
/// endings.
static wchar_t* LicenseText() {
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

/// Initializes an unopened modal About form and its owned resources.
AboutForm::AboutForm()
        : window(nullptr), tooltip(nullptr), uiFont(nullptr), textFont(nullptr), linkFont(nullptr),
        hand(nullptr), legacyCursorModule(nullptr), buttonSize(SIZE{}), licenseSize(SIZE{}), licenseDpi(96),
        ownsUiFont(false), nativeLink(false), initialized(false) {
    websiteUrl[0] = 0;
}

/// Closes the dialog and releases its fonts, tooltip and control subclasses.
AboutForm::~AboutForm() {
    Close();
    DetachControls();
    if (ownsUiFont) {
        DeleteObject(uiFont);
    }
    if (textFont) {
        DeleteObject(textFont);
    }
    if (linkFont) {
        DeleteObject(linkFont);
    }
}

/// Applies current interface, license and fallback-link fonts and selects the appropriate icon size.
void AboutForm::SetFonts(bool updateUi) {
    HFONT newUi = updateUi
        ? CreateUiFont(window)
        : reinterpret_cast<HFONT>(SendMessageW(window, WM_GETFONT, 0, 0));
    if (!newUi) {
        return;
    }
    HFONT newText = CreateAboutFont(window);
    LOGFONTW link = LOGFONTW{};
    GetObjectW(newUi, sizeof(link), &link);
    link.lfUnderline = TRUE;
    HFONT newLink = CreateFontIndirectW(&link);
    if (updateUi) {
        SendMessageW(window, WM_SETFONT, reinterpret_cast<WPARAM>(newUi), FALSE);
    }
    const int ids[] = { IDC_INFO_PRODUCT, IDC_INFO_WEBSITE, IDC_INFO_LINK, IDC_INFO_TEXT, IDOK };
    for (int index = 0; index < 5; ++index) {
        HFONT font = ids[index] == IDC_INFO_TEXT && newText
            ? newText
            : ids[index] == IDC_INFO_LINK && !nativeLink ? newLink : newUi;
        if (updateUi || font != newUi) {
            SendDlgItemMessageW(window, ids[index], WM_SETFONT, reinterpret_cast<WPARAM>(font), TRUE);
        }
    }
    if (ownsUiFont) {
        DeleteObject(uiFont);
    }
    if (textFont) {
        DeleteObject(textFont);
    }
    if (linkFont) {
        DeleteObject(linkFont);
    }
    uiFont = newUi;
    ownsUiFont = updateUi;
    textFont = newText;
    linkFont = newLink;
    int iconSize = WindowDpi(window) >= 130 ? 48 : 32;
    HICON icon = static_cast<HICON>(LoadImageW(GetModuleHandleW(nullptr), MAKEINTRESOURCEW(IDI_MEDIAINFO),
        IMAGE_ICON, iconSize, iconSize, LR_SHARED));
    HWND iconControl = GetDlgItem(window, IDC_INFO_ICON);
    SendMessageW(iconControl, STM_SETICON, reinterpret_cast<WPARAM>(icon), 0);
    SetWindowPos(iconControl, nullptr, 0, 0, iconSize, iconSize, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
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

/// Builds the natural About layout, fits it to the work area and anchors controls on resize.
void AboutForm::Layout(bool resize) const {
    if (!initialized || IsIconic(window)) {
        return;
    }
    RECT client = RECT{};
    GetClientRect(window, &client);
    SIZE currentClient = { client.right, client.bottom };
    SIZE margin = DialogUnits(uiFont, 8, 8);
    SIZE button = buttonSize;
    button.cx = PreferredButtonSize(GetDlgItem(window, IDOK), button).cx;
    SIZE gap = DialogUnits(uiFont, 4, 6);
    int textTop = margin.cy;
    if (resize) {
        UINT dpi = WindowDpi(window);
        SIZE license = { MulDiv(licenseSize.cx, dpi, licenseDpi), MulDiv(licenseSize.cy, dpi, licenseDpi) };
        client.right = license.cx + 2 * DialogUnits(uiFont, 10, 0).cx;
        HWND icon = GetDlgItem(window, IDC_INFO_ICON);
        SetWindowPos(icon, nullptr, margin.cx, margin.cy, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
        RECT iconBounds = ControlRect(icon, window);
        SIZE productPosition = DialogUnits(uiFont, 0, 4);
        productPosition.cx = iconBounds.right + iconBounds.left;
        int width = client.right - margin.cx - productPosition.cx;
        HWND product = GetDlgItem(window, IDC_INFO_PRODUCT);
        int productHeight = WrappedLabelHeight(product, width);
        PlaceControl(product, productPosition.cx, productPosition.cy, width, productHeight);
        TEXTMETRICW metrics = TEXTMETRICW{};
        ReadControlMetrics(GetDlgItem(window, IDC_INFO_WEBSITE), &metrics);
        SIZE labelSize = SIZE{};
        HDC dc = GetDC(window);
        HGDIOBJ old = SelectObject(dc, uiFont);
        wchar_t websiteText[128];
        GetDlgItemTextW(window, IDC_INFO_WEBSITE, websiteText, 128);
        GetTextExtentPoint32W(dc, websiteText, lstrlenW(websiteText), &labelSize);
        SelectObject(dc, old);
        ReleaseDC(window, dc);
        int websiteY = productPosition.cy + productHeight + gap.cy;
        PlaceControl(GetDlgItem(window, IDC_INFO_WEBSITE), productPosition.cx, websiteY, labelSize.cx,
            metrics.tmHeight);
        int linkX = productPosition.cx + labelSize.cx + gap.cx;
        HWND link = GetDlgItem(window, IDC_INFO_LINK);
        int linkWidth = client.right - margin.cx - linkX;
        int linkHeight = metrics.tmHeight;
        if (nativeLink) {
            SIZE ideal = SIZE{};
            LRESULT height = SendMessageW(link, LM_GETIDEALSIZE, linkWidth, reinterpret_cast<LPARAM>(&ideal));
            if (height > 0) {
                linkHeight = static_cast<int>(height);
            }
            if (ideal.cx > 0 && ideal.cx < linkWidth) {
                linkWidth = ideal.cx;
            }
        } else {
            dc = GetDC(link);
            old = SelectObject(dc, reinterpret_cast<HFONT>(SendMessageW(link, WM_GETFONT, 0, 0)));
            wchar_t linkText[256];
            GetWindowTextW(link, linkText, 256);
            SIZE textSize = SIZE{};
            if (GetTextExtentPoint32W(dc, linkText, lstrlenW(linkText), &textSize)) {
                if (textSize.cx > 0 && textSize.cx < linkWidth) {
                    linkWidth = textSize.cx;
                }
                linkHeight = textSize.cy;
            }
            SelectObject(dc, old);
            ReleaseDC(link, dc);
        }
        PlaceControl(link, linkX, websiteY, linkWidth, linkHeight);
        AlignControlBaseline(link, GetDlgItem(window, IDC_INFO_WEBSITE));
        RECT linkBounds = ControlRect(link, window);
        int rowBottom = websiteY + metrics.tmHeight;
        textTop = (linkBounds.bottom > rowBottom ? linkBounds.bottom : rowBottom) + gap.cy;
        client.bottom = textTop + license.cy + gap.cy + button.cy + margin.cy;
        RECT bounds;
        GetWindowRect(window, &bounds);
        int outerWidth = bounds.right - bounds.left + client.right - currentClient.cx;
        int outerHeight = bounds.bottom - bounds.top + client.bottom - currentClient.cy;
        if (outerWidth != bounds.right - bounds.left || outerHeight != bounds.bottom - bounds.top) {
            SetWindowPos(window, nullptr, 0, 0, outerWidth, outerHeight,
                SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
        }
    }
    if (!resize) {
        textTop = ControlRect(GetDlgItem(window, IDC_INFO_TEXT), window).top;
    }
    int buttonY = client.bottom - margin.cy - button.cy;
    PlaceControl(GetDlgItem(window, IDOK), client.right - margin.cx - button.cx, buttonY, button.cx,
        button.cy);
    PlaceControl(GetDlgItem(window, IDC_INFO_TEXT), margin.cx, textTop, client.right - 2 * margin.cx,
        buttonY - gap.cy - textTop);
    if (resize) {
        FitToWorkArea();
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

/// Loads the license text and installs native edit, link, tooltip and context-menu behavior.
bool AboutForm::Initialize() {
    BuildAboutWebsiteUrl(websiteUrl);
    RECT buttonBounds = ControlRect(GetDlgItem(window, IDOK), window);
    buttonSize = SIZE{ buttonBounds.right - buttonBounds.left, buttonBounds.bottom - buttonBounds.top };
    licenseDpi = WindowDpi(window);
    licenseSize = SIZE{
        MulDiv(ABOUT_LICENSE_WIDTH_96DPI, licenseDpi, 96),
        MulDiv(ABOUT_LICENSE_HEIGHT_96DPI, licenseDpi, 96)
    };
    SetFonts(false);
    if (!uiFont) {
        return false;
    }
    initialized = true;
    HWND edit = GetDlgItem(window, IDC_INFO_TEXT);
    if (!InstallSelectionEditHandler(edit)) {
        return false;
    }
    SendMessageW(edit, EM_SETLIMITTEXT, 0x7FFFFFFE, 0);
    InstallInformationWordBreak(edit);
    wchar_t* license = LicenseText();
    SetWindowTextW(edit, license ? license : T(TXT_LICENSE_UNAVAILABLE));
    if (license) {
        HeapFree(GetProcessHeap(), 0, license);
    }
    RefreshLanguage();
    if (!AttachControls()) {
        return false;
    }
    SendMessageW(window, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(LoadApplicationIcon(false)));
    SendMessageW(window, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(LoadApplicationIcon(true)));
    Layout();
    return true;
}

/// Applies the suggested DPI-change bounds, rebuilds fonts and updates the dialog layout.
INT_PTR AboutForm::HandleDpiChange(LPARAM lParam) {
    RECT* bounds = reinterpret_cast<RECT*>(lParam);
    SetWindowPos(window, nullptr, bounds->left, bounds->top, bounds->right - bounds->left,
        bounds->bottom - bounds->top, SWP_NOZORDER | SWP_NOACTIVATE);
    SetFonts(true);
    Layout();
    return TRUE;
}

/// Handles native website-link activation notifications and returns whether the message was processed.
INT_PTR AboutForm::HandleNotification(LPARAM lParam) {
    NMHDR* notification = reinterpret_cast<NMHDR*>(lParam);
    if (nativeLink
            && notification->hwndFrom == GetDlgItem(window, IDC_INFO_LINK)
            && (notification->code == NM_CLICK || notification->code == NM_RETURN)) {
        OpenWebsite();
        SetWindowLongPtrW(window, DWLP_MSGRESULT, 0);
        return TRUE;
    }
    return FALSE;
}

/// Handles native About-dialog commands, sizing, theme changes and website notifications.
INT_PTR CALLBACK AboutForm::DialogProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    AboutForm* owner = reinterpret_cast<AboutForm*>(GetWindowLongPtrW(window, DWLP_USER));
    if (message == WM_INITDIALOG) {
        owner = reinterpret_cast<AboutForm*>(lParam);
        owner->window = window;
        SetWindowLongPtrW(window, DWLP_USER, reinterpret_cast<LONG_PTR>(owner));
        if (!owner->Initialize()) {
            owner->Close();
            return FALSE;
        }
        SetFocus(GetDlgItem(window, IDOK));
        SendDlgItemMessageW(window, IDC_INFO_TEXT, EM_SETSEL, 0, 0);
        return FALSE;
    }
    if (!owner) {
        return FALSE;
    }
    switch (message) {
        case WM_DRAWITEM:
            if (wParam == IDC_INFO_PRODUCT) {
                return DrawWrappedTextItem(reinterpret_cast<const DRAWITEMSTRUCT*>(lParam));
            }
            break;
        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
                owner->Close();
                return TRUE;
            }
            break;
        case WM_NOTIFY:
            return owner->HandleNotification(lParam);
        case WM_SIZE:
            owner->Layout(false);
            return TRUE;
        case WM_DISPLAYCHANGE:
            owner->Layout();
            return TRUE;
        case WM_SETTINGCHANGE:
        case WM_THEMECHANGED:
            owner->SetFonts(true);
            owner->Layout();
            return TRUE;
        case WM_DPICHANGED:
            return owner->HandleDpiChange(lParam);
        case WM_CTLCOLORSTATIC:
            if (!owner->nativeLink && reinterpret_cast<HWND>(lParam) == GetDlgItem(window, IDC_INFO_LINK)) {
                SetTextColor(reinterpret_cast<HDC>(wParam), RGB(0, 0, 255));
                SetBkColor(reinterpret_cast<HDC>(wParam), GetSysColor(COLOR_BTNFACE));
                return reinterpret_cast<INT_PTR>(GetSysColorBrush(COLOR_BTNFACE));
            }
            break;
        case WM_CLOSE:
            owner->Close();
            return TRUE;
        case WM_DESTROY:
            owner->DetachControls();
            return TRUE;
        case WM_NCDESTROY:
            ResetInformationWordBreak();
            owner->window = nullptr;
            owner->initialized = false;
            break;
    }
    return FALSE;
}

/// Opens About modally without saving its position.
void AboutForm::Show(HWND owner) {
    if (window) {
        SetForegroundWindow(window);
        return;
    }
    HINSTANCE instance = GetModuleHandleW(nullptr);
    DLGTEMPLATE* definition = LoadSystemDialogTemplate(instance, IDD_ABOUT, owner);
    if (!definition) {
        return;
    }
    DialogBoxIndirectParamW(instance, definition, owner, DialogProc, reinterpret_cast<LPARAM>(this));
    HeapFree(GetProcessHeap(), 0, definition);
}

/// Closes the active modal dialog.
void AboutForm::Close() {
    if (window) {
        EndDialog(window, IDOK);
    }
}

/// Returns the dialog handle, or null when it is closed.
HWND AboutForm::GetWindow() const {
    return window;
}

/// Replaces the static website control with a native SysLink when the installed controls support it.
void AboutForm::CreateNativeLink() {
    HMODULE commonControls = GetModuleHandleW(L"comctl32.dll");
    InitializeControlsFunction initialize = commonControls
        ? reinterpret_cast<InitializeControlsFunction>(GetProcAddress(commonControls, "InitCommonControlsEx"))
        : nullptr;
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
    for (int index = 0; index < 4; ++index) {
        HWND control = GetDlgItem(window, aboutControls[index]);
        if (aboutControls[index] != IDC_INFO_LINK || !nativeLink) {
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
        if (!SetWindowLongPtrW(control, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(ControlProc))
                && GetLastError()) {
            RemovePropW(control, originalProperty);
            RemovePropW(control, ownerProperty);
            DetachControls();
            return false;
        }
    }
    tooltip = CreateWindowExW(WS_EX_TOPMOST, TOOLTIPS_CLASSW, nullptr, WS_POPUP | TTS_ALWAYSTIP | TTS_NOPREFIX,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, window, nullptr, GetModuleHandleW(nullptr),
        nullptr);
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
        if (!WideCharToMultiByte(CP_ACP, 0, tooltipText, -1, ansiTooltipText, sizeof(ansiTooltipText), nullptr,
                nullptr)) {
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
        for (int index = 0; index < 4; ++index) {
            HWND control = GetDlgItem(window, aboutControls[index]);
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

/// Opens the application website in the default browser and reports launch failures.
void AboutForm::OpenWebsite() {
    HINSTANCE result = ShellExecuteW(window, L"open", websiteUrl, nullptr, nullptr, SW_SHOWNORMAL);
    if (reinterpret_cast<INT_PTR>(result) <= 32) {
        MessageBoxW(window, T(TXT_WEBSITE_OPEN_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
    }
}

/// Copies the About product information and website address as Unicode text.
void AboutForm::CopyInformation() {
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
            MessageBoxW(window, T(TXT_COPY_INFORMATION_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
        }
        HeapFree(GetProcessHeap(), 0, text);
    }
    HeapFree(GetProcessHeap(), 0, product);
}

/// Shows the native context commands appropriate to the product information or website link.
void AboutForm::ShowContextMenu(HWND source, LPARAM location) {
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
    UINT command = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, point.x, point.y, 0, window, nullptr);
    DestroyMenu(menu);
    if (command == openWebsiteCommand) {
        OpenWebsite();
    } else if (command == copyUrlCommand) {
        if (!CopyTextToClipboard(window, websiteUrl)) {
            MessageBoxW(window, T(TXT_COPY_URL_FAILED), L"MediaInfo", MB_OK | MB_ICONERROR);
        }
    } else if (command == copyInformationCommand) {
        CopyInformation();
    }
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

/// Routes About context, cursor and fallback-link completed clicks, keyboard, focus and painting messages.
LRESULT CALLBACK AboutForm::ControlProc(HWND control, UINT message, WPARAM wParam, LPARAM lParam) {
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
    return original
        ? CallWindowProcW(original, control, message, wParam, lParam)
        : DefWindowProcW(control, message, wParam, lParam);
}
