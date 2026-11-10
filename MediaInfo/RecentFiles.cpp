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
 * Last modified for version 1.2.0.2
 */

#include "RecentFiles.h"
#include "SettingsStorage.h"
#include "resource.h"
#include "MainForm.h"

/// Copies the flat File menu into a fresh native popup, preserving item text, state and command data.
static HMENU CopyFileMenu(HMENU source) {
    HMENU copy = CreatePopupMenu();
    if (!copy) {
        return nullptr;
    }
    int count = GetMenuItemCount(source);
    for (int index = 0; index < count; ++index) {
        MENUITEMINFOW item = MENUITEMINFOW{};
        item.cbSize = sizeof(item);
        item.fMask = MIIM_TYPE | MIIM_ID | MIIM_STATE | MIIM_DATA | MIIM_CHECKMARKS;
        if (!GetMenuItemInfoW(source, index, TRUE, &item) || item.cch >= MAXDWORD / sizeof(wchar_t)) {
            DestroyMenu(copy);
            return nullptr;
        }
        wchar_t* caption = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0,
            (item.cch + 1) * sizeof(wchar_t)));
        if (!caption) {
            DestroyMenu(copy);
            return nullptr;
        }
        item.dwTypeData = caption;
        ++item.cch;
        bool copied = GetMenuItemInfoW(source, index, TRUE, &item)
            && InsertMenuItemW(copy, index, TRUE, &item);
        HeapFree(GetProcessHeap(), 0, caption);
        if (!copied) {
            DestroyMenu(copy);
            return nullptr;
        }
    }
    return copy;
}

/// Initializes an empty recent-files list.
RecentFiles::RecentFiles()
        : paths(static_cast<RecentPath*>(HeapAlloc(GetProcessHeap(),
        HEAP_ZERO_MEMORY, Capacity * sizeof(RecentPath)))), count(0) {}

/// Releases every stored recent-file path.
RecentFiles::~RecentFiles() {
    if (paths) {
        HeapFree(GetProcessHeap(), 0, paths);
    }
}

/// Loads up to eight recent paths from the saved registry buffer.
void RecentFiles::Load() {
    count = 0;
    wchar_t* buffer = paths
        ? static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), 0, (Capacity * MAX_PATH + 1) * sizeof(wchar_t)))
        : nullptr;
    if (!buffer) {
        return;
    }
    DWORD length = LoadRecentFilesSetting(buffer, Capacity * MAX_PATH + 1);
    DWORD offset = 0;
    while (offset < length && buffer[offset] && count < Capacity) {
        DWORD end = offset;
        while (end < length && buffer[end]) {
            ++end;
        }
        if (end - offset < MAX_PATH) {
            bool duplicate = false;
            for (int index = 0; index < count; ++index) {
                if (!lstrcmpiW(paths[index], buffer + offset)) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                lstrcpyW(paths[count++], buffer + offset);
            }
        }
        offset = end + 1;
    }
    HeapFree(GetProcessHeap(), 0, buffer);
}

/// Persists the current recent-file order as a double-null-terminated registry buffer.
bool RecentFiles::Save() const {
    wchar_t* buffer = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
        (Capacity * MAX_PATH + 1) * sizeof(wchar_t)));
    if (!buffer) {
        return false;
    }
    DWORD length = 0;
    for (int index = 0; index < count; ++index) {
        lstrcpyW(buffer + length, paths[index]);
        length += lstrlenW(paths[index]) + 1;
    }
    buffer[length++] = 0;
    if (length == 1) {
        buffer[length++] = 0;
    }
    bool saved = SaveRecentFilesSetting(buffer, length);
    HeapFree(GetProcessHeap(), 0, buffer);
    return saved;
}

/// Moves a path to the front, removes duplicates and keeps at most eight recent files.
void RecentFiles::Add(const wchar_t* path) {
    if (!paths || !path || !*path || lstrlenW(path) >= MAX_PATH) {
        return;
    }
    wchar_t copy[MAX_PATH];
    lstrcpyW(copy, path);
    int position = 0;
    while (position < count && lstrcmpiW(paths[position], copy)) {
        ++position;
    }
    if (position == count && count < Capacity) {
        ++count;
    }
    if (position >= Capacity) {
        position = Capacity - 1;
    }
    for (int index = position; index > 0; --index) {
        lstrcpyW(paths[index], paths[index - 1]);
    }
    lstrcpyW(paths[0], copy);
}

/// Removes one recent-file entry from the ordered path list.
void RecentFiles::Remove(int index) {
    if (index < 0 || index >= count) {
        return;
    }
    for (int position = index + 1; position < count; ++position) {
        lstrcpyW(paths[position - 1], paths[position]);
    }
    --count;
}

/// Removes a matching path even if recent entries were reordered while a confirmation was open.
void RecentFiles::Remove(const wchar_t* path) {
    for (int index = 0; index < count; ++index) {
        if (!lstrcmpiW(paths[index], path)) {
            Remove(index);
            return;
        }
    }
}

/// Returns a stored recent-file path when its index is valid.
const wchar_t* RecentFiles::Get(int index) const {
    return index >= 0 && index < count ? paths[index] : nullptr;
}

/// Releases all recent-file entries and leaves the list empty.
void RecentFiles::Clear() {
    count = 0;
}

/// Reports whether the recent-files list contains no entries.
bool RecentFiles::IsEmpty() const {
    return count == 0;
}

/// Rebuilds the File submenu and its numbered recent files without retaining obsolete native widths.
void RecentFiles::UpdateMenu(HMENU menuBar) const {
    HMENU menu = GetSubMenu(menuBar, 0);
    if (!menu) {
        return;
    }
    bool removed = false;
    for (int index = GetMenuItemCount(menu) - 1; index >= 0; --index) {
        UINT command = GetMenuItemID(menu, index);
        if (command >= ID_FILE_RECENT_FIRST && command < ID_FILE_RECENT_FIRST + Capacity) {
            DeleteMenu(menu, index, MF_BYPOSITION);
            removed = true;
        }
    }
    if (removed) {
        for (int index = 1; index < GetMenuItemCount(menu); ++index) {
            if (GetMenuItemID(menu, index) == ID_FILE_EXIT &&
                GetMenuState(menu, index - 1, MF_BYPOSITION) & MF_SEPARATOR) {
                DeleteMenu(menu, index - 1, MF_BYPOSITION);
                break;
            }
        }
    }
    for (int index = 0; index < count; ++index) {
        wchar_t caption[2 * MAX_PATH + 16];
        wsprintfW(caption, L"&%d ", index + 1);
        wchar_t* destination = caption + lstrlenW(caption);
        wchar_t name[MAX_PATH];
        FormatFileNameCaption(paths[index], 80, name, MAX_PATH);
        for (const wchar_t* source = name; *source; ++source) {
            *destination++ = *source;
            if (*source == L'&') {
                *destination++ = L'&';
            }
        }
        *destination = 0;
        InsertMenuW(menu, ID_FILE_EXIT, MF_BYCOMMAND | MF_STRING, ID_FILE_RECENT_FIRST + index, caption);
    }
    if (count) {
        InsertMenuW(menu, ID_FILE_EXIT, MF_BYCOMMAND | MF_SEPARATOR, 0, nullptr);
    }
    HMENU replacement = CopyFileMenu(menu);
    if (!replacement) {
        return;
    }
    MENUITEMINFOW popup = MENUITEMINFOW{};
    popup.cbSize = sizeof(popup);
    popup.fMask = MIIM_SUBMENU;
    popup.hSubMenu = replacement;
    if (SetMenuItemInfoW(menuBar, 0, TRUE, &popup)) {
        DestroyMenu(menu);
    } else {
        DestroyMenu(replacement);
    }
}
