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

#pragma once

#include <windows.h>

struct PrintJob;

struct PrintLine {
    int start;
    int length;
};

class PrintSettings {

private:
    HGLOBAL deviceMode;
    HGLOBAL deviceNames;
    RECT margins;

    /// Replaces the retained printer configuration and releases the previous memory blocks.
    void ReplaceDevice(HGLOBAL mode, HGLOBAL names);

public:
    /// Initializes empty printer selections and margins of 12.7 mm on every side.
    PrintSettings();

    /// Releases the retained printer configuration buffers.
    ~PrintSettings();

    /// Opens native Page Setup and commits printer settings and margins only when accepted.
    bool PageSetup(HWND owner, wchar_t* error, int capacity);

    /// Returns a printer context owned by the caller and commits only accepted device settings.
    HDC ChoosePrinter(HWND owner, bool* printToFile, wchar_t* error, int capacity);

    /// Returns page margins in hundredths of a millimeter.
    RECT GetMargins() const;

    /// Copies the retained native printer settings into the supplied DEVMODE structure.
    bool GetDeviceMode(DEVMODEW& mode) const;
};

class PrintLayout {

private:
    const wchar_t* text;
    HFONT font;
    RECT area;
    PrintLine* lines;
    UINT lineCount;
    UINT capacity;
    UINT rows;
    LONG lineHeight;

    /// Appends a source text span, growing the line buffer as needed.
    bool AddLine(int start, int length);

    /// Clears pagination and releases the font and cached line positions.
    void Reset();

public:
    /// Initializes an empty page layout without allocating font or line storage.
    PrintLayout();

    /// Releases the font and line positions owned by the page layout.
    ~PrintLayout();

    /// Measures the captured edit font and wraps its text into pages within the supplied content rectangle.
    bool Initialize(const PrintJob& job, HDC reference, const RECT& content, int dpiX, int dpiY);

    /// Draws one zero-based page with the saved font, line positions and content clipping.
    bool DrawPage(HDC output, UINT page) const;

    /// Returns the number of pages in the prepared layout.
    UINT GetPageCount() const;
};

/// Converts physical page margins to printer pixels and clips them to the printable area.
RECT PrintContentRect(HDC printer, const RECT& margins);
