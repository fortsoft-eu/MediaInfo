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

#pragma once

#include <windows.h>
#include <unknwn.h>

struct IFileDialog;
struct IBindCtx;

/// Owns an optional native Open or Save dialog without requiring newer APIs at process startup.
class ModernFileDialog {

private:
    /// Dynamically resolved COM and Shell entry-point signatures.
    typedef HRESULT(WINAPI* InitializeFunction)(void*, DWORD);
    typedef void (WINAPI* UninitializeFunction)();
    typedef HRESULT(WINAPI* CreateFunction)(REFCLSID, IUnknown*, DWORD, REFIID, void**);
    typedef void (WINAPI* FreeFunction)(void*);
    typedef HRESULT(WINAPI* ItemFunction)(const wchar_t*, IBindCtx*, REFIID, void**);

    /// COM dialog, module lifetime and the functions used to release returned Shell data.
    HMODULE module;
    IFileDialog* dialog;
    UninitializeFunction uninitialize;
    FreeFunction freeMemory;
    ItemFunction createItem;
    bool initialized;
    bool saving;

public:
    /// Initializes an optional native Open or Save dialog through dynamically resolved COM functions.
    explicit ModernFileDialog(bool save);

    /// Releases the native dialog and balances COM and module ownership.
    ~ModernFileDialog();

    /// Configures native filters, selection, title, suggested filename, folder and extension.
    bool Prepare(const wchar_t* filters, UINT type, const wchar_t* title, const wchar_t* name,
        const wchar_t* folder, const wchar_t* extension, bool multiple);

    /// Configures the native Open dialog to select a filesystem folder.
    bool PrepareFolder(const wchar_t* title, const wchar_t* folder);

    /// Shows the prepared native file dialog with its owner and returns the dialog result.
    HRESULT Show(HWND owner);

    /// Copies the selected filesystem path into the caller-provided buffer.
    HRESULT CopyPath(wchar_t* path);

    /// Copies all selected filesystem paths into a process-heap, double-null-terminated buffer.
    HRESULT CopyPaths(wchar_t** paths);

    /// Returns the selected native file-filter index.
    UINT GetType() const;
};
