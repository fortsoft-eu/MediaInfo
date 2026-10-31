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

#include <windows.h>
#include <stddef.h>

/// Allocates PCRE2 memory from the native process heap without linking the C runtime.
void* __cdecl malloc(size_t size) {
    return HeapAlloc(GetProcessHeap(), 0, size ? size : 1);
}

/// Releases a PCRE2 process-heap allocation, accepting the standard null-pointer no-op.
void __cdecl free(void* block) {
    if (block) {
        HeapFree(GetProcessHeap(), 0, block);
    }
}

/// Copies potentially overlapping byte ranges without calling another runtime helper.
void* __cdecl memmove(void* destination, const void* source, size_t length) {
    volatile unsigned char* output = (volatile unsigned char*)destination;
    const volatile unsigned char* input = (const volatile unsigned char*)source;
    if ((ULONG_PTR)output < (ULONG_PTR)input) {
        for (size_t index = 0; index < length; ++index) {
            output[index] = input[index];
        }
    } else {
        while (length) {
            --length;
            output[length] = input[length];
        }
    }
    return destination;
}

/// Compares unsigned bytes with the ordering required by the standard memory comparator.
int __cdecl memcmp(const void* first, const void* second, size_t length) {
    const volatile unsigned char* left = (const volatile unsigned char*)first;
    const volatile unsigned char* right = (const volatile unsigned char*)second;
    for (size_t index = 0; index < length; ++index) {
        if (left[index] != right[index]) {
            return left[index] - right[index];
        }
    }
    return 0;
}

/// Locates an ANSI delimiter, including the string terminator, in PCRE2's native option text.
char* __cdecl strchr(const char* text, int character) {
    unsigned char value = (unsigned char)character;
    while (*text && (unsigned char)*text != value) {
        ++text;
    }
    return (unsigned char)*text == value ? (char*)text : NULL;
}

/// Provides the x86 compiler multiplication helper without linking a C runtime.
__declspec(naked) void __cdecl _allmul(void) {
    __asm {
        mov eax, [esp + 8]
        mov ecx, [esp + 12]
        imul eax, ecx
        mov edx, [esp + 16]
        mov ecx, [esp + 4]
        imul edx, ecx
        add edx, eax
        mov eax, ecx
        mov ecx, edx
        mul dword ptr[esp + 12]
        add edx, ecx
        ret 16
    }
}
