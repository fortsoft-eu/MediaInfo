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

/// Maintains the eight-file history and its filename-only menu entries.
class RecentFiles {

public:
    static const int Capacity = 8;

private:
    typedef wchar_t RecentPath[MAX_PATH];

    RecentPath* paths;
    int count;

    /// Prevents copying ownership of the native resources held by this object.
    RecentFiles(const RecentFiles&) = delete;

    /// Prevents assigning ownership of the native resources held by another object.
    RecentFiles& operator=(const RecentFiles&) = delete;

public:
    /// Initializes an empty recent-files list.
    RecentFiles();

    /// Releases every stored recent-file path.
    ~RecentFiles();

    /// Loads up to eight recent paths from the saved registry buffer.
    void Load();

    /// Persists the current recent-file order as a double-null-terminated registry buffer.
    bool Save() const;

    /// Moves a path to the front, removes duplicates and keeps at most eight recent files.
    void Add(const wchar_t* path);

    /// Removes one recent-file entry from the ordered path list.
    void Remove(int index);

    /// Removes a matching path even if recent entries were reordered while a confirmation was open.
    void Remove(const wchar_t* path);

    /// Releases all recent-file entries and leaves the list empty.
    void Clear();

    /// Reports whether the recent-files list contains no entries.
    bool IsEmpty() const;

    /// Returns a stored recent-file path when its index is valid.
    const wchar_t* Get(int index) const;

    /// Rebuilds the numbered recent-file section above Exit using shortened filenames.
    void UpdateMenu(HMENU menu) const;
};
