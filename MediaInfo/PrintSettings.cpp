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
 * Last modified for version 1.2.0.0
 */

#include "PrintSettings.h"
#include "MainForm.h"
#include <commdlg.h>

/// Clones a movable printer-settings handle without changing the stored original.
static bool CopyPrintHandle(HGLOBAL source, HGLOBAL& destination) {
    destination = nullptr;
    if (!source) {
        return true;
    }
    SIZE_T size = GlobalSize(source);
    const void* input = GlobalLock(source);
    if (!size || !input) {
        if (input) {
            GlobalUnlock(source);
        }
        return false;
    }
    destination = GlobalAlloc(GMEM_MOVEABLE, size);
    void* output = destination ? GlobalLock(destination) : nullptr;
    if (output) {
        CopyMemory(output, input, size);
        GlobalUnlock(destination);
    } else if (destination) {
        GlobalFree(destination);
        destination = nullptr;
    }
    GlobalUnlock(source);
    return output != nullptr;
}

/// Releases the printer configuration and device-name memory blocks.
static void FreePrintHandles(HGLOBAL mode, HGLOBAL names) {
    if (mode) {
        GlobalFree(mode);
    }
    if (names) {
        GlobalFree(names);
    }
}

/// Initializes empty printer selections and margins of 12.7 mm on every side.
PrintSettings::PrintSettings()
        : deviceMode(nullptr), deviceNames(nullptr), margins(RECT{ 1270, 1270, 1270, 1270 }) {}

/// Releases the retained printer configuration buffers.
PrintSettings::~PrintSettings() {
    FreePrintHandles(deviceMode, deviceNames);
}

/// Replaces the retained printer configuration and releases the previous memory blocks.
void PrintSettings::ReplaceDevice(HGLOBAL mode, HGLOBAL names) {
    FreePrintHandles(deviceMode, deviceNames);
    deviceMode = mode;
    deviceNames = names;
}

/// Opens native Page Setup and commits printer settings and margins only when accepted.
bool PrintSettings::PageSetup(HWND owner, wchar_t* error, int capacity) {
    error[0] = 0;
    PAGESETUPDLGW dialog = PAGESETUPDLGW{};
    dialog.lStructSize = sizeof(dialog);
    dialog.hwndOwner = owner;
    dialog.Flags = PSD_MARGINS | PSD_INHUNDREDTHSOFMILLIMETERS;
    dialog.rtMargin = margins;
    bool copied = CopyPrintHandle(deviceMode, dialog.hDevMode)
        && CopyPrintHandle(deviceNames, dialog.hDevNames);
    bool accepted = copied && PageSetupDlgW(&dialog) != FALSE;
    DWORD failure = copied && !accepted ? CommDlgExtendedError() : 0;
    if (accepted) {
        ReplaceDevice(dialog.hDevMode, dialog.hDevNames);
        margins = dialog.rtMargin;
        return true;
    }
    FreePrintHandles(dialog.hDevMode, dialog.hDevNames);
    if (!copied || failure) {
        lstrcpynW(error, T(TXT_PAGE_SETUP_FAILED), capacity);
    }
    return false;
}

/// Returns a printer context owned by the caller and commits only accepted device settings.
HDC PrintSettings::ChoosePrinter(HWND owner, bool* printToFile, wchar_t* error, int capacity) {
    error[0] = 0;
    PRINTDLGW dialog = PRINTDLGW{};
    dialog.lStructSize = sizeof(dialog);
    dialog.hwndOwner = owner;
    dialog.Flags = PD_RETURNDC | PD_USEDEVMODECOPIESANDCOLLATE | PD_NOSELECTION | PD_NOPAGENUMS;
    dialog.nMinPage = 1;
    dialog.nMaxPage = 65535;
    dialog.nFromPage = 1;
    dialog.nToPage = 1;
    dialog.nCopies = 1;
    bool copied = CopyPrintHandle(deviceMode, dialog.hDevMode)
        && CopyPrintHandle(deviceNames, dialog.hDevNames);
    bool accepted = copied && PrintDlgW(&dialog) != FALSE;
    DWORD failure = copied && !accepted ? CommDlgExtendedError() : 0;
    if (accepted && dialog.hDC) {
        ReplaceDevice(dialog.hDevMode, dialog.hDevNames);
        *printToFile = (dialog.Flags & PD_PRINTTOFILE) != 0;
        return dialog.hDC;
    }
    if (dialog.hDC) {
        DeleteDC(dialog.hDC);
    }
    FreePrintHandles(dialog.hDevMode, dialog.hDevNames);
    if (!copied || failure || accepted) {
        lstrcpynW(error, T(TXT_PRINT_FAILED), capacity);
    }
    return nullptr;
}

/// Returns page margins in hundredths of a millimeter.
RECT PrintSettings::GetMargins() const {
    return margins;
}

/// Copies the retained native printer settings into the supplied DEVMODE structure.
bool PrintSettings::GetDeviceMode(DEVMODEW& mode) const {
    DEVMODEW* value = deviceMode ? static_cast<DEVMODEW*>(GlobalLock(deviceMode)) : nullptr;
    if (!value) {
        return false;
    }
    ZeroMemory(&mode, sizeof(mode));
    CopyMemory(&mode, value, value->dmSize < sizeof(mode) ? value->dmSize : sizeof(mode));
    GlobalUnlock(deviceMode);
    return true;
}

/// Fits a printed line to the available width, preserving surrogate pairs and words when possible.
static int PrintedLineLength(HDC dc, const wchar_t* text, int length, int width) {
    int first = 0;
    int last = length;
    while (first < last) {
        int count = first + (last - first + 1) / 2;
        RECT measured = RECT{ 0, 0, width, 0 };
        if (!DrawTextW(dc, text, count, &measured,
            DT_CALCRECT | DT_SINGLELINE | DT_NOPREFIX | DT_EXPANDTABS)) {
            return 0;
        }
        if (measured.right <= width) {
            first = count;
        } else {
            last = count - 1;
        }
    }
    if (first && text[first - 1] >= 0xD800 && text[first - 1] <= 0xDBFF
        && text[first] >= 0xDC00 && text[first] <= 0xDFFF) {
        --first;
    }
    if (first < length) {
        for (int count = first; count > 0; --count) {
            if (text[count - 1] == L' ' || text[count - 1] == L'\t') {
                return count;
            }
        }
    }
    return first;
}

/// Initializes an empty page layout without allocating font or line storage.
PrintLayout::PrintLayout()
        : text(nullptr), font(nullptr), area(RECT{}), lines(nullptr), lineCount(0), capacity(0), rows(0),
        lineHeight(0) {}

/// Releases the font and line positions owned by the page layout.
PrintLayout::~PrintLayout() {
    Reset();
}

/// Clears pagination and releases the font and cached line positions.
void PrintLayout::Reset() {
    if (font) {
        DeleteObject(font);
    }
    if (lines) {
        HeapFree(GetProcessHeap(), 0, lines);
    }
    font = nullptr;
    lines = nullptr;
    text = nullptr;
    lineCount = 0;
    capacity = 0;
    rows = 0;
}

/// Appends a source text span, growing the line buffer as needed.
bool PrintLayout::AddLine(int start, int length) {
    if (lineCount == capacity) {
        UINT next = capacity ? capacity * 2 : 128;
        if (next < capacity || next > MAXDWORD / sizeof(PrintLine)) {
            return false;
        }
        void* memory = lines
            ? HeapReAlloc(GetProcessHeap(), 0, lines, next * sizeof(PrintLine))
            : HeapAlloc(GetProcessHeap(), 0, next * sizeof(PrintLine));
        if (!memory) {
            return false;
        }
        lines = static_cast<PrintLine*>(memory);
        capacity = next;
    }
    lines[lineCount++] = PrintLine{ start, length };
    return true;
}

/// Measures the captured edit font and wraps its text into pages within the supplied content rectangle.
bool PrintLayout::Initialize(const PrintJob& job, HDC reference, const RECT& content, int dpiX, int dpiY) {
    Reset();
    area = content;
    int width = area.right - area.left;
    int height = area.bottom - area.top;
    if (!job.report || !job.fontDpi || dpiX <= 0 || dpiY <= 0 || width <= 0 || height <= 0) {
        return false;
    }
    LOGFONTW description = job.font;
    description.lfHeight = MulDiv(description.lfHeight, dpiY, job.fontDpi);
    description.lfWidth = MulDiv(description.lfWidth, dpiX, job.fontDpi);
    font = CreateFontIndirectW(&description);
    if (!font) {
        return false;
    }
    HGDIOBJ previous = SelectObject(reference, font);
    TEXTMETRICW metrics = TEXTMETRICW{};
    bool success = previous && previous != HGDI_ERROR && GetTextMetricsW(reference, &metrics);
    lineHeight = metrics.tmHeight + metrics.tmExternalLeading;
    rows = success && lineHeight > 0 ? height / lineHeight : 0;
    text = job.report;
    const wchar_t* cursor = text;
    if (rows) {
        do {
            int length = 0;
            while (length < 8192 && cursor[length] && cursor[length] != L'\r' && cursor[length] != L'\n') {
                ++length;
            }
            int count = length ? PrintedLineLength(reference, cursor, length, width) : 0;
            if (length && !count || !AddLine(static_cast<int>(cursor - text), count)) {
                success = false;
                break;
            }
            cursor += count;
            if (count == length) {
                if (*cursor == L'\r') {
                    ++cursor;
                    if (*cursor == L'\n') {
                        ++cursor;
                    }
                } else if (*cursor == L'\n') {
                    ++cursor;
                }
            }
        } while (*cursor);
    } else {
        success = false;
    }
    if (previous && previous != HGDI_ERROR) {
        SelectObject(reference, previous);
    }
    return success;
}

/// Draws one zero-based page with the saved font, line positions and content clipping.
bool PrintLayout::DrawPage(HDC output, UINT page) const {
    if (page >= GetPageCount()) {
        return false;
    }
    int saved = SaveDC(output);
    if (!saved) {
        return false;
    }
    SelectObject(output, font);
    SetTextColor(output, RGB(0, 0, 0));
    SetBkMode(output, TRANSPARENT);
    IntersectClipRect(output, area.left, area.top, area.right, area.bottom);
    bool success = true;
    UINT first = page * rows;
    for (UINT row = 0; row < rows && first + row < lineCount; ++row) {
        const PrintLine& line = lines[first + row];
        int top = area.top + row * lineHeight;
        RECT bounds = RECT{ area.left, top, area.right, top + lineHeight };
        if (line.length
            && !DrawTextW(output, text + line.start, line.length, &bounds,
                DT_SINGLELINE | DT_NOPREFIX | DT_EXPANDTABS)) {
            success = false;
            break;
        }
    }
    RestoreDC(output, saved);
    return success;
}

/// Returns the number of pages in the prepared layout.
UINT PrintLayout::GetPageCount() const {
    return rows ? lineCount / rows + (lineCount % rows != 0) : 0;
}

/// Converts physical page margins to printer pixels and clips them to the printable area.
RECT PrintContentRect(HDC printer, const RECT& margins) {
    int dpiX = GetDeviceCaps(printer, LOGPIXELSX);
    int dpiY = GetDeviceCaps(printer, LOGPIXELSY);
    int offsetX = GetDeviceCaps(printer, PHYSICALOFFSETX);
    int offsetY = GetDeviceCaps(printer, PHYSICALOFFSETY);
    RECT requested = RECT{
        MulDiv(margins.left, dpiX, 2540) - offsetX,
        MulDiv(margins.top, dpiY, 2540) - offsetY,
        GetDeviceCaps(printer, PHYSICALWIDTH) - MulDiv(margins.right, dpiX, 2540) - offsetX,
        GetDeviceCaps(printer, PHYSICALHEIGHT) - MulDiv(margins.bottom, dpiY, 2540) - offsetY
    };
    RECT printable = RECT{ 0, 0, GetDeviceCaps(printer, HORZRES), GetDeviceCaps(printer, VERTRES) };
    RECT area = RECT{};
    IntersectRect(&area, &requested, &printable);
    return area;
}
