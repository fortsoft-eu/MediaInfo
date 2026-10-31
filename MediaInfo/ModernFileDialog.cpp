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

#include "ModernFileDialog.h"

#pragma push_macro("NTDDI_VERSION")
#undef NTDDI_VERSION
#define NTDDI_VERSION 0x06000000
#include <shobjidl.h>
#pragma pop_macro("NTDDI_VERSION")

/// Initializes an optional native Open or Save dialog through dynamically resolved COM functions.
ModernFileDialog::ModernFileDialog(bool save)
        : module(nullptr), dialog(nullptr), uninitialize(nullptr), freeMemory(nullptr), createItem(nullptr),
        initialized(false), saving(save) {
    createItem = reinterpret_cast<ItemFunction>(GetProcAddress(GetModuleHandleW(L"shell32.dll"),
        "SHCreateItemFromParsingName"));
    if (!createItem) {
        return;
    }
    wchar_t path[MAX_PATH];
    UINT length = GetSystemDirectoryW(path, MAX_PATH);
    if (!length || length + 11 >= MAX_PATH) {
        return;
    }
    lstrcatW(path, L"\\ole32.dll");
    module = LoadLibraryW(path);
    if (!module) {
        return;
    }
    InitializeFunction initialize =
        reinterpret_cast<InitializeFunction>(GetProcAddress(module, "CoInitializeEx"));
    CreateFunction create = reinterpret_cast<CreateFunction>(GetProcAddress(module, "CoCreateInstance"));
    uninitialize = reinterpret_cast<UninitializeFunction>(GetProcAddress(module, "CoUninitialize"));
    freeMemory = reinterpret_cast<FreeFunction>(GetProcAddress(module, "CoTaskMemFree"));
    if (!initialize || !create || !uninitialize || !freeMemory) {
        return;
    }
    if (FAILED(initialize(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE))) {
        return;
    }
    initialized = true;
    create(saving ? __uuidof(FileSaveDialog) : __uuidof(FileOpenDialog), nullptr, CLSCTX_INPROC_SERVER,
        __uuidof(IFileDialog), reinterpret_cast<void**>(&dialog));
}

/// Releases the native dialog and balances COM and module ownership.
ModernFileDialog::~ModernFileDialog() {
    if (dialog) {
        dialog->Release();
    }
    if (initialized) {
        uninitialize();
    }
    if (module) {
        FreeLibrary(module);
    }
}

/// Configures native filters, selection, title, suggested filename, folder and extension.
bool ModernFileDialog::Prepare(const wchar_t* filters, UINT type, const wchar_t* title, const wchar_t* name,
        const wchar_t* folder, const wchar_t* extension, bool multiple) {
    if (!dialog) {
        return false;
    }
    UINT count = 0;
    const wchar_t* cursor = filters;
    while (*cursor) {
        cursor += lstrlenW(cursor) + 1;
        if (!*cursor) {
            return false;
        }
        cursor += lstrlenW(cursor) + 1;
        ++count;
    }
    if (!count || count > MAXDWORD / sizeof(COMDLG_FILTERSPEC)) {
        return false;
    }
    COMDLG_FILTERSPEC* specs = static_cast<COMDLG_FILTERSPEC*>(HeapAlloc(GetProcessHeap(),
        0, count * sizeof(COMDLG_FILTERSPEC)));
    if (!specs) {
        return false;
    }
    cursor = filters;
    for (UINT index = 0; index < count; ++index) {
        specs[index].pszName = cursor;
        cursor += lstrlenW(cursor) + 1;
        specs[index].pszSpec = cursor;
        cursor += lstrlenW(cursor) + 1;
    }
    FILEOPENDIALOGOPTIONS options = 0;
    HRESULT result = dialog->GetOptions(&options);
    options |= FOS_FORCEFILESYSTEM | FOS_PATHMUSTEXIST | FOS_NOCHANGEDIR;
    options |= saving ? FOS_OVERWRITEPROMPT : FOS_FILEMUSTEXIST;
    if (multiple) {
        options |= FOS_ALLOWMULTISELECT;
    }
    bool prepared = SUCCEEDED(result)
        && SUCCEEDED(dialog->SetOptions(options))
        && SUCCEEDED(dialog->SetFileTypes(count, specs))
        && SUCCEEDED(dialog->SetFileTypeIndex(type))
        && SUCCEEDED(dialog->SetTitle(title));
    HeapFree(GetProcessHeap(), 0, specs);
    if (!prepared) {
        return false;
    }
    if (name && name[0] && FAILED(dialog->SetFileName(name))) {
        return false;
    }
    if (extension && FAILED(dialog->SetDefaultExtension(extension))) {
        return false;
    }
    if (folder && folder[0]) {
        IShellItem* item = nullptr;
        if (SUCCEEDED(createItem(folder, nullptr, __uuidof(IShellItem), reinterpret_cast<void**>(&item)))) {
            dialog->SetFolder(item);
            item->Release();
        }
    }
    return true;
}

/// Configures the native Open dialog to select a filesystem folder.
bool ModernFileDialog::PrepareFolder(const wchar_t* title, const wchar_t* folder) {
    if (!dialog) {
        return false;
    }
    FILEOPENDIALOGOPTIONS options = 0;
    HRESULT result = dialog->GetOptions(&options);
    options |= FOS_PICKFOLDERS | FOS_FORCEFILESYSTEM | FOS_PATHMUSTEXIST | FOS_NOCHANGEDIR;
    if (FAILED(result) || FAILED(dialog->SetOptions(options)) || FAILED(dialog->SetTitle(title))) {
        return false;
    }
    if (folder && folder[0]) {
        IShellItem* item = nullptr;
        if (SUCCEEDED(createItem(folder, nullptr, __uuidof(IShellItem), reinterpret_cast<void**>(&item)))) {
            dialog->SetFolder(item);
            item->Release();
        }
    }
    return true;
}

/// Shows the prepared native file dialog with its owner and returns the dialog result.
HRESULT ModernFileDialog::Show(HWND owner) {
    return dialog ? dialog->Show(owner) : E_FAIL;
}

/// Copies the selected filesystem path into the caller-provided buffer.
HRESULT ModernFileDialog::CopyPath(wchar_t* path) {
    IShellItem* item = nullptr;
    HRESULT result = dialog->GetResult(&item);
    if (FAILED(result)) {
        return result;
    }
    wchar_t* text = nullptr;
    result = item->GetDisplayName(SIGDN_FILESYSPATH, &text);
    if (SUCCEEDED(result)) {
        if (lstrlenW(text) >= MAX_PATH) {
            result = HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE);
        } else {
            lstrcpyW(path, text);
        }
    }
    if (text) {
        freeMemory(text);
    }
    item->Release();
    return result;
}

/// Copies all selected filesystem paths into a process-heap, double-null-terminated buffer.
HRESULT ModernFileDialog::CopyPaths(wchar_t** paths) {
    *paths = nullptr;
    IFileOpenDialog* open = nullptr;
    HRESULT result = dialog->QueryInterface(__uuidof(IFileOpenDialog), reinterpret_cast<void**>(&open));
    if (FAILED(result)) {
        return result;
    }
    IShellItemArray* items = nullptr;
    result = open->GetResults(&items);
    open->Release();
    if (FAILED(result)) {
        return result;
    }
    DWORD count = 0;
    result = items->GetCount(&count);
    if (count > 65535) {
        result = E_OUTOFMEMORY;
    }
    SIZE_T capacity = 1;
    wchar_t* buffer = nullptr;
    wchar_t* destination = nullptr;
    for (int pass = 0; pass < 2 && SUCCEEDED(result); ++pass) {
        if (pass == 1) {
            buffer = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                capacity * sizeof(wchar_t)));
            destination = buffer;
            if (!buffer) {
                result = E_OUTOFMEMORY;
                break;
            }
        }
        for (DWORD index = 0; index < count && SUCCEEDED(result); ++index) {
            IShellItem* item = nullptr;
            result = items->GetItemAt(index, &item);
            if (FAILED(result)) {
                break;
            }
            wchar_t* text = nullptr;
            result = item->GetDisplayName(SIGDN_FILESYSPATH, &text);
            if (SUCCEEDED(result)) {
                int length = lstrlenW(text);
                if (length >= MAX_PATH) {
                    result = HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE);
                } else if (pass == 0) {
                    capacity += length + 1;
                } else if (static_cast<SIZE_T>(destination - buffer) + length + 1 >= capacity) {
                    result = E_UNEXPECTED;
                } else {
                    lstrcpyW(destination, text);
                    destination += length + 1;
                }
            }
            if (text) {
                freeMemory(text);
            }
            item->Release();
        }
    }
    items->Release();
    if (FAILED(result)) {
        if (buffer) {
            HeapFree(GetProcessHeap(), 0, buffer);
        }
    } else {
        *paths = buffer;
    }
    return result;
}

/// Returns the selected native file-filter index.
UINT ModernFileDialog::GetType() const {
    UINT type = 1;
    dialog->GetFileTypeIndex(&type);
    return type;
}
