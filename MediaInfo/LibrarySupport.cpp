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

#include "LibrarySupport.h"
#include "Localization.h"

/// Tracks compressed input, buffered DEFLATE bits and decoding validity.
struct Bits {
    const BYTE* p;
    DWORD n;
    DWORD pos;
    DWORD buf;
    int have;
    BOOL ok;
};

/// Stores canonical Huffman code-length counts and their ordered symbols.
struct Huff {
    WORD count[16];
    WORD symbol[288];
};

/// Filenames used to discover, validate and extract the supported libraries.
const wchar_t mediaInfoLibraryName[] = L"MediaInfo.dll";
const wchar_t curlLibraryName[] = L"libcurl.dll";
const wchar_t webpLibraryName[] = L"libwebp.dll";

/// Bundled-library versions used by discovery and the About product header.
const wchar_t* const bundledMediaInfoVersions[] = { L"26.10", L"21.03", L"0.7.60" };
const wchar_t bundledCurlVersions[] = L"8.11.0-DEV, 7.47.1";

/// Packed-resource signature and the cross-process extraction mutex.
static const DWORD packedSignature = 0x4D494450;
static const char cacheMutexName[] = "FortSoft.MediaInfo.LibraryCache";

/// Checks a PE file for x86 architecture and returns its Windows and subsystem version information.
bool InspectLibraryImage(const wchar_t* path, wchar_t* error, int capacity, const wchar_t* name) {
    HANDLE file = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_DELETE, nullptr, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        wchar_t message[256];
        wsprintfW(message, T(TXT_FILE_OPEN_FAILED), name);
        lstrcpynW(error, message, capacity);
        return false;
    }
    IMAGE_DOS_HEADER dos = IMAGE_DOS_HEADER{};
    DWORD read = 0;
    DWORD size = GetFileSize(file, nullptr);
    bool valid = ReadFile(file, &dos, sizeof(dos), &read, nullptr)
        && read == sizeof(dos)
        && dos.e_magic == IMAGE_DOS_SIGNATURE
        && dos.e_lfanew >= static_cast<LONG>(sizeof(dos))
        && size >= 24
        && static_cast<DWORD>(dos.e_lfanew) <= size - 24;
    DWORD signature = 0;
    IMAGE_FILE_HEADER header = IMAGE_FILE_HEADER{};
    if (valid) {
        valid = SetFilePointer(file, dos.e_lfanew, nullptr, FILE_BEGIN) != INVALID_SET_FILE_POINTER
            && ReadFile(file, &signature, sizeof(signature), &read, nullptr)
            && read == sizeof(signature)
            && signature == IMAGE_NT_SIGNATURE
            && ReadFile(file, &header, sizeof(header), &read, nullptr)
            && read == sizeof(header)
            && header.Characteristics & IMAGE_FILE_DLL;
    }
    CloseHandle(file);
    if (!valid) {
        lstrcpynW(error, T(TXT_INVALID_WINDOWS_DLL), capacity);
        return false;
    }
    if (header.Machine != IMAGE_FILE_MACHINE_I386) {
        wchar_t message[256];
        wsprintfW(message, T(TXT_LIBRARY_REQUIRES_X86), name);
        lstrcpynW(error, message, capacity);
        return false;
    }
    return true;
}

/// Tries a library filename in a candidate folder while skipping inaccessible or missing files.
static bool TryLibraryFolder(
    const wchar_t* folder, const wchar_t* name, LibraryCandidateFunction candidate, void* context) {
    wchar_t path[MAX_PATH];
    if (lstrlenW(folder) + lstrlenW(name) + 2 > MAX_PATH) {
        return false;
    }
    lstrcpyW(path, folder);
    lstrcatW(path, L"\\");
    lstrcatW(path, name);
    DWORD attributes = GetFileAttributesW(path);
    return attributes != INVALID_FILE_ATTRIBUTES
        && !(attributes & FILE_ATTRIBUTE_DIRECTORY)
        && candidate(path, context);
}

/// Searches executable ancestors, Program Files and user installation folders through a candidate callback.
bool SearchLibraryLocations(
    const wchar_t* name, const wchar_t* beside, LibraryCandidateFunction candidate, void* context) {
    wchar_t directory[MAX_PATH];
    if (beside) {
        lstrcpynW(directory, beside, MAX_PATH);
        wchar_t* separator = nullptr;
        for (wchar_t* cursor = directory; *cursor; ++cursor) {
            if (*cursor == L'\\' || *cursor == L'/') {
                separator = cursor;
            }
        }
        if (separator) {
            *separator = 0;
            if (TryLibraryFolder(directory, name, candidate, context)) {
                return true;
            }
        }
    }
    DWORD length = GetModuleFileNameW(nullptr, directory, MAX_PATH);
    if (length && length < MAX_PATH) {
        wchar_t* filename = directory;
        for (wchar_t* cursor = directory; *cursor; ++cursor) {
            if (*cursor == L'\\' || *cursor == L'/') {
                filename = cursor + 1;
            }
        }
        if (filename != directory) {
            filename[-1] = 0;
            int rootLength = directory[1] == L':' ? 2 : 0;
            if (directory[0] == L'\\' && directory[1] == L'\\') {
                wchar_t* cursor = directory + 2;
                int separators = 0;
                while (*cursor) {
                    if (*cursor == L'\\' && ++separators == 2) {
                        break;
                    }
                    ++cursor;
                }
                rootLength = static_cast<int>(cursor - directory);
            }
            while (true) {
                if (TryLibraryFolder(directory, name, candidate, context)) {
                    return true;
                }
                wchar_t* separator = nullptr;
                for (wchar_t* cursor = directory; *cursor; ++cursor) {
                    if (*cursor == L'\\' || *cursor == L'/') {
                        separator = cursor;
                    }
                }
                if (!separator || separator - directory < rootLength) {
                    break;
                }
                *separator = 0;
            }
        }
    }
    const wchar_t* variables[] = {
        L"ProgramFiles",
        L"ProgramFiles(x86)",
        L"ProgramW6432",
        L"LOCALAPPDATA",
        L"APPDATA"
    };
    const wchar_t* folders[] = {
        L"\\MediaInfo",
        L"\\MediaArea\\MediaInfo",
        L"\\MediaArea",
        L"\\MediaArea.net\\MediaInfo",
        L"\\Programs\\MediaInfo",
        L"\\Programs\\MediaArea\\MediaInfo"
    };
    for (int variable = 0; variable < 5; ++variable) {
        wchar_t base[MAX_PATH];
        length = GetEnvironmentVariableW(variables[variable], base, MAX_PATH);
        if (!length || length >= MAX_PATH) {
            continue;
        }
        for (int folder = 0; folder < 6; ++folder) {
            if (length + lstrlenW(folders[folder]) >= MAX_PATH) {
                continue;
            }
            lstrcpyW(directory, base);
            lstrcatW(directory, folders[folder]);
            if (TryLibraryFolder(directory, name, candidate, context)) {
                return true;
            }
        }
    }
    return false;
}

/// Writes a complete worker-protocol message buffer, including any partial pipe writes.
bool WriteLibraryBytes(HANDLE pipe, const void* data, DWORD size) {
    const BYTE* cursor = static_cast<const BYTE*>(data);
    while (size) {
        DWORD written = 0;
        if (!WriteFile(pipe, cursor, size, &written, nullptr) || !written) {
            return false;
        }
        cursor += written;
        size -= written;
    }
    return true;
}

/// Reads a complete worker-protocol message buffer or reports a closed or failed pipe.
bool ReadLibraryBytes(HANDLE pipe, void* data, DWORD size) {
    BYTE* cursor = static_cast<BYTE*>(data);
    while (size) {
        DWORD received = 0;
        if (!ReadFile(pipe, cursor, size, &received, nullptr) || !received) {
            return false;
        }
        cursor += received;
        size -= received;
    }
    return true;
}

/// Returns the localized operation description used in isolated library-failure messages.
const wchar_t* LibraryOperationName(LibraryOperation operation) {
    switch (operation) {
        case LibraryOperation::New:
            return L"MediaInfo_New";
        case LibraryOperation::Open:
            return L"MediaInfo_Open";
        case LibraryOperation::Inform:
            return L"MediaInfo_Inform";
        case LibraryOperation::Copy:
            return T(TXT_REPORT_COPY_OPERATION);
        case LibraryOperation::Close:
            return L"MediaInfo_Close";
        case LibraryOperation::Delete:
            return L"MediaInfo_Delete";
        case LibraryOperation::Version:
            return L"MediaInfo_Option (Info_Version)";
        case LibraryOperation::Option:
            return L"MediaInfo_Option";
        case LibraryOperation::Language:
            return L"MediaInfo_Option (Language)";
        case LibraryOperation::CurlLoad:
            return T(TXT_CURL_LOAD_OPERATION);
        case LibraryOperation::Unload:
            return T(TXT_MEDIALIB_UNLOAD_OPERATION);
        default:
            return T(TXT_MEDIALIB_LOAD_OPERATION);
    }
}

/// Fills a memory region with zero bytes.
static void zero(void* a, DWORD n) {
    BYTE* p = (BYTE*)a;
    while (n--) {
        *p++ = 0;
    }
}

/// Reads an unaligned 32-bit little-endian value.
static DWORD u32(const BYTE* p) {
    return p[0] | (DWORD)p[1] << 8 | (DWORD)p[2] << 16 | (DWORD)p[3] << 24;
}

/// Calculates the ZIP-compatible CRC32 checksum of a byte sequence.
static DWORD crc(const BYTE* p, DWORD n) {
    DWORD c = ~0UL;
    while (n--) {
        c ^= *p++;
        for (int k = 0; k < 8; k++) {
            c = c >> 1 ^ (0UL - (c & 1) & 0xEDB88320UL);
        }
    }
    return ~c;
}

/// Allocates a byte buffer from the process heap. Returns null on failure.
static void* alloc(DWORD n) {
    return HeapAlloc(GetProcessHeap(), 0, n);
}

/// Releases a process-heap buffer. Accepts a null pointer.
static void release(void* p) {
    if (p) {
        HeapFree(GetProcessHeap(), 0, p);
    }
}

/// Reads n bits from a DEFLATE stream, least significant bit first.
/// Marks the stream invalid if the input ends before enough bits are available.
static unsigned bits(Bits* b, int n) {
    while (b->have < n) {
        if (b->pos == b->n) {
            b->ok = FALSE;
            return 0;
        }
        b->buf |= (DWORD)b->p[b->pos++] << b->have;
        b->have += 8;
    }
    unsigned v = b->buf & (1UL << n) - 1;
    b->buf >>= n;
    b->have -= n;
    return v;
}

/// Builds a canonical Huffman decoding table from symbol code lengths.
/// Rejects invalid lengths and oversubscribed trees.
static BOOL tree(Huff* h, const BYTE* l, int n) {
    WORD off[16];
    zero(h, sizeof(*h));
    for (int i = 0; i < n; i++) {
        if (l[i] > 15) {
            return FALSE;
        }
        h->count[l[i]]++;
    }
    int left = 1;
    for (int k = 1; k <= 15; k++) {
        left = left * 2 - h->count[k];
        if (left < 0) {
            return FALSE;
        }
    }
    off[1] = 0;
    for (int k = 1; k < 15; k++) {
        off[k + 1] = off[k] + h->count[k];
    }
    for (int i = 0; i < n; i++) {
        if (l[i]) {
            h->symbol[off[l[i]]++] = (WORD)i;
        }
    }
    return TRUE;
}

/// Decodes one Huffman symbol, or returns -1 and marks the stream invalid.
static int symbol(Bits* b, Huff* h) {
    unsigned code = 0, first = 0, index = 0;
    for (int n = 1; n <= 15; n++) {
        code |= bits(b, 1);
        unsigned count = h->count[n];
        if (code >= first && code - first < count) {
            return h->symbol[index + code - first];
        }
        index += count;
        first = (first + count) << 1;
        code <<= 1;
    }
    b->ok = FALSE;
    return -1;
}

/// Decodes a raw RFC 1951 DEFLATE stream into a fixed-size output buffer.
/// Supports stored, fixed-Huffman, and dynamic-Huffman blocks and checks buffer bounds.
/// Returns TRUE only when input consumption and output length match the supplied sizes.
static BOOL inflate(const BYTE* src, DWORD ns, BYTE* out, DWORD no) {
    static const BYTE order[19] = { 16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15 };
    static const WORD lb[29] = {
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        13,
        15,
        17,
        19,
        23,
        27,
        31,
        35,
        43,
        51,
        59,
        67,
        83,
        99,
        115,
        131,
        163,
        195,
        227,
        258
    };
    static const BYTE le[29] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        1,
        2,
        2,
        2,
        2,
        3,
        3,
        3,
        3,
        4,
        4,
        4,
        4,
        5,
        5,
        5,
        5,
        0
    };
    static const WORD db[30] = {
        1,
        2,
        3,
        4,
        5,
        7,
        9,
        13,
        17,
        25,
        33,
        49,
        65,
        97,
        129,
        193,
        257,
        385,
        513,
        769,
        1025,
        1537,
        2049,
        3073,
        4097,
        6145,
        8193,
        12289,
        16385,
        24577
    };
    static const BYTE de[30] = {
        0,
        0,
        0,
        0,
        1,
        1,
        2,
        2,
        3,
        3,
        4,
        4,
        5,
        5,
        6,
        6,
        7,
        7,
        8,
        8,
        9,
        9,
        10,
        10,
        11,
        11,
        12,
        12,
        13,
        13
    };
    Bits b = { src, ns, 0, 0, 0, TRUE };
    DWORD pos = 0;
    BOOL last = FALSE;
    Huff h, d, c;
    BYTE lens[320];
    while (!last && b.ok) {
        last = bits(&b, 1);
        unsigned type = bits(&b, 2);
        if (type == 0) {
            b.buf = 0;
            b.have = 0;
            unsigned len = bits(&b, 16), inv = bits(&b, 16);
            if ((len ^ inv) != 65535 || len > no - pos) {
                return FALSE;
            }
            while (len--) {
                out[pos++] = (BYTE)bits(&b, 8);
            }
            continue;
        }
        if (type == 1) {
            for (int i = 0; i < 288; i++) {
                lens[i] = (BYTE)(i < 144 ? 8 : i < 256 ? 9 : i < 280 ? 7 : 8);
            }
            if (!tree(&h, lens, 288)) {
                return FALSE;
            }
            for (int i = 0; i < 32; i++) {
                lens[i] = 5;
            }
            if (!tree(&d, lens, 32)) {
                return FALSE;
            }
        } else if (type == 2) {
            unsigned nl = bits(&b, 5) + 257, nd = bits(&b, 5) + 1, nc = bits(&b, 4) + 4;
            if (nl > 286) {
                return FALSE;
            }
            zero(lens, 320);
            for (unsigned i = 0; i < nc; i++) {
                lens[order[i]] = (BYTE)bits(&b, 3);
            }
            if (!tree(&c, lens, 19)) {
                return FALSE;
            }
            unsigned i = 0;
            while (i < nl + nd && b.ok) {
                int s = symbol(&b, &c);
                if (s < 0) {
                    return FALSE;
                }
                if (s < 16) {
                    lens[i++] = (BYTE)s;
                } else {
                    unsigned repeat;
                    BYTE v = 0;
                    if (s == 16) {
                        if (!i) {
                            return FALSE;
                        }
                        v = lens[i - 1];
                        repeat = bits(&b, 2) + 3;
                    } else if (s == 17) {
                        repeat = bits(&b, 3) + 3;
                    } else {
                        repeat = bits(&b, 7) + 11;
                    }
                    if (repeat > nl + nd - i) {
                        return FALSE;
                    }
                    while (repeat--) {
                        lens[i++] = v;
                    }
                }
            }
            if (!lens[256] || !tree(&h, lens, nl) || !tree(&d, lens + nl, nd)) {
                return FALSE;
            }
        } else {
            return FALSE;
        }
        while (true) {
            int s = symbol(&b, &h);
            if (!b.ok) {
                return FALSE;
            }
            if (s == 256) {
                break;
            }
            if (s < 256) {
                if (pos == no) {
                    return FALSE;
                }
                out[pos++] = (BYTE)s;
            } else {
                if (s > 285) {
                    return FALSE;
                }
                unsigned len = lb[s - 257] + bits(&b, le[s - 257]);
                int ds = symbol(&b, &d);
                if (ds < 0 || ds > 29) {
                    return FALSE;
                }
                unsigned dist = db[ds] + bits(&b, de[ds]);
                if (!b.ok || dist > pos || len > no - pos) {
                    return FALSE;
                }
                while (len--) {
                    out[pos] = out[pos - dist];
                    pos++;
                }
            }
        }
    }
    return b.ok && pos == no && b.pos == ns;
}

/// Validates a packed resource and decodes it only when its length and CRC32 agree.
bool UnpackLibraryBytes(const BYTE* packed, DWORD packedSize, BYTE** unpacked, DWORD* unpackedSize) {
    *unpacked = nullptr;
    *unpackedSize = 0;
    if (!packed || packedSize <= 12 || u32(packed) != packedSignature) {
        return false;
    }
    DWORD size = u32(packed + 4);
    if (!size || size > 128UL * 1024 * 1024) {
        return false;
    }
    BYTE* bytes = static_cast<BYTE*>(alloc(size));
    if (!bytes) {
        return false;
    }
    if (!inflate(packed + 12, packedSize - 12, bytes, size) || crc(bytes, size) != u32(packed + 8)) {
        release(bytes);
        return false;
    }
    *unpacked = bytes;
    *unpackedSize = size;
    return true;
}

/// Creates the requested cache directory tree and reports inaccessible locations.
static bool EnsureCacheDirectory(const wchar_t* path) {
    DWORD attributes = GetFileAttributesW(path);
    if (attributes != INVALID_FILE_ATTRIBUTES) {
        return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
    }
    wchar_t parent[MAX_PATH];
    lstrcpynW(parent, path, MAX_PATH);
    wchar_t* last = nullptr;
    for (wchar_t* cursor = parent; *cursor; ++cursor) {
        if (*cursor == L'\\' || *cursor == L'/') {
            last = cursor;
        }
    }
    if (!last || last == parent || last == parent + 2 && parent[1] == L':') {
        return CreateDirectoryW(path, nullptr) || GetLastError() == ERROR_ALREADY_EXISTS;
    }
    *last = 0;
    if (!EnsureCacheDirectory(parent)) {
        return false;
    }
    return CreateDirectoryW(path, nullptr) || GetLastError() == ERROR_ALREADY_EXISTS;
}

/// Reads a per-user or system folder path from the registry into the supplied buffer.
static bool ReadFolder(HKEY root, const wchar_t* keyName, const wchar_t* valueName, wchar_t* path) {
    HKEY key = nullptr;
    if (RegOpenKeyExW(root, keyName, 0, KEY_QUERY_VALUE, &key) != ERROR_SUCCESS) {
        return false;
    }
    wchar_t value[MAX_PATH] = L"";
    DWORD bytes = sizeof(value);
    DWORD type = 0;
    LONG result = RegQueryValueExW(key, valueName, nullptr, &type, reinterpret_cast<BYTE*>(value), &bytes);
    RegCloseKey(key);
    value[MAX_PATH - 1] = 0;
    if (result != ERROR_SUCCESS || type != REG_SZ && type != REG_EXPAND_SZ || !value[0]) {
        return false;
    }
    if (type == REG_EXPAND_SZ) {
        DWORD length = ExpandEnvironmentStringsW(value, path, MAX_PATH);
        return length && length <= MAX_PATH;
    }
    lstrcpyW(path, value);
    return true;
}

/// Chooses an accessible per-user cache root, retaining the legacy profile and temporary-directory locations.
static bool CacheBase(int index, wchar_t* path) {
    DWORD length = 0;
    switch (index) {
        case 0:
            length = GetEnvironmentVariableW(L"LOCALAPPDATA", path, MAX_PATH);
            break;
        case 1:
            length = GetEnvironmentVariableW(L"APPDATA", path, MAX_PATH);
            break;
        case 2:
            return ReadFolder(HKEY_CURRENT_USER,
                L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders", L"Local AppData",
                path);
        case 3:
            return ReadFolder(HKEY_CURRENT_USER,
                L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders", L"AppData", path);
        case 4:
            length = GetEnvironmentVariableW(L"USERPROFILE", path, MAX_PATH);
            if (length && length + 18 < MAX_PATH) {
                lstrcatW(path, L"\\Application Data");
                return true;
            }
            return false;
        case 5:
            length = GetEnvironmentVariableW(L"ProgramFiles", path, MAX_PATH);
            break;
        case 6:
            return ReadFolder(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion",
                L"ProgramFilesDir", path);
        default:
            length = GetTempPathW(MAX_PATH, path);
            break;
    }
    return length && length < MAX_PATH;
}

/// Checks an existing extracted library against the expected resource length and CRC32.
static bool CachedLibraryMatches(const wchar_t* path, DWORD expectedSize, DWORD expectedCrc) {
    HANDLE file = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_DELETE, nullptr, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        return false;
    }
    DWORD high = 0;
    DWORD size = GetFileSize(file, &high);
    BYTE* bytes = size == expectedSize && !high ? static_cast<BYTE*>(alloc(size)) : nullptr;
    bool valid = bytes != nullptr;
    DWORD offset = 0;
    while (valid && offset < size) {
        DWORD received = 0;
        valid = ReadFile(file, bytes + offset, size - offset, &received, nullptr) && received;
        offset += received;
    }
    if (valid) {
        valid = crc(bytes, size) == expectedCrc;
    }
    release(bytes);
    CloseHandle(file);
    return valid;
}

/// Publishes complete validated library bytes through a temporary file while the cache mutex is held.
static bool WriteCachedLibrary(const wchar_t* folder, const wchar_t* path, const BYTE* bytes, DWORD size) {
    wchar_t temporary[MAX_PATH];
    if (!GetTempFileNameW(folder, L"MIV", 0, temporary)) {
        return false;
    }
    HANDLE file =
        CreateFileW(temporary, GENERIC_WRITE, 0, nullptr, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    bool success = file != INVALID_HANDLE_VALUE;
    DWORD offset = 0;
    while (success && offset < size) {
        DWORD written = 0;
        success = WriteFile(file, bytes + offset, size - offset, &written, nullptr) && written;
        offset += written;
    }
    if (file != INVALID_HANDLE_VALUE) {
        success = FlushFileBuffers(file) && success;
        if (!CloseHandle(file)) {
            success = false;
        }
    }
    if (success) {
        success = MoveFileExW(temporary, path, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != FALSE;
    }
    if (!success) {
        DeleteFileW(temporary);
    }
    return success;
}

/// Serializes cache access across processes, reuses verified DLLs and publishes complete extracted files.
bool ExtractBundledLibrary(
    UINT resource, const wchar_t* version, wchar_t* path, wchar_t* error, int capacity, const wchar_t* name) {
    HMODULE module = GetModuleHandleW(nullptr);
    HRSRC entry = FindResourceW(module, MAKEINTRESOURCEW(resource), RT_RCDATA);
    HGLOBAL loaded = entry ? LoadResource(module, entry) : nullptr;
    const BYTE* packed = loaded ? static_cast<const BYTE*>(LockResource(loaded)) : nullptr;
    DWORD packedSize = entry ? SizeofResource(module, entry) : 0;
    if (!packed
            || packedSize <= 12
            || u32(packed) != packedSignature
            || !u32(packed + 4)
            || u32(packed + 4) > 128UL * 1024 * 1024) {
        lstrcpynW(error, T(TXT_LIBRARY_RESOURCE_INVALID), capacity);
        return false;
    }
    HANDLE cacheMutex = CreateMutexA(nullptr, FALSE, cacheMutexName);
    DWORD lock = cacheMutex ? WaitForSingleObject(cacheMutex, INFINITE) : WAIT_FAILED;
    if (lock != WAIT_OBJECT_0 && lock != WAIT_ABANDONED) {
        DWORD failure = GetLastError();
        if (cacheMutex) {
            CloseHandle(cacheMutex);
        }
        lstrcpynW(error, T(TXT_LIBRARY_EXTRACTION_FAILED), capacity);
        FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, failure, 0, error,
            capacity, nullptr);
        return false;
    }
    BYTE* bytes = nullptr;
    DWORD size = 0;
    bool success = false;
    bool unpackFailed = false;
    for (int index = 0; index < 8; ++index) {
        wchar_t folder[MAX_PATH];
        if (!CacheBase(index, folder)) {
            continue;
        }
        int length = lstrlenW(folder);
        while (length && (folder[length - 1] == L'\\' || folder[length - 1] == L'/')) {
            folder[--length] = 0;
        }
        const wchar_t* application = index == 5 || index == 6
            ? L"\\MediaInfo\\Libraries\\"
            : L"\\FortSoft\\MediaInfo\\Libraries\\";
        wchar_t suffix[80];
        wsprintfW(suffix, L"%s-%08lX", version, u32(packed + 8));
        if (length + lstrlenW(application) + lstrlenW(suffix) + lstrlenW(name) + 2 > MAX_PATH) {
            continue;
        }
        lstrcatW(folder, application);
        lstrcatW(folder, suffix);
        lstrcpyW(path, folder);
        lstrcatW(path, L"\\");
        lstrcatW(path, name);
        if (CachedLibraryMatches(path, u32(packed + 4), u32(packed + 8))) {
            success = true;
            break;
        }
        if (!EnsureCacheDirectory(folder)) {
            continue;
        }
        if (!bytes && !UnpackLibraryBytes(packed, packedSize, &bytes, &size)) {
            lstrcpynW(error, T(TXT_LIBRARY_DECOMPRESSION_FAILED), capacity);
            unpackFailed = true;
            break;
        }
        if (WriteCachedLibrary(folder, path, bytes, size)) {
            success = true;
            break;
        }
    }
    release(bytes);
    ReleaseMutex(cacheMutex);
    CloseHandle(cacheMutex);
    if (!success && !unpackFailed) {
        lstrcpynW(error, T(TXT_LIBRARY_EXTRACTION_FAILED), capacity);
    }
    return success;
}
