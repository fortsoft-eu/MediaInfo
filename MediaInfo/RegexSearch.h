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

#include "MediaInfo.h"
#define PCRE2_CODE_UNIT_WIDTH 16
#define PCRE2_STATIC
#include "PCRE2/pcre2.h"

/// Distinguishes a successful regex match, the end of matching and an actual engine failure.
enum class RegexSearchResult {
    Match,
    NotFound,
    Error
};

/// Owns a bounded UTF-16 PCRE2 pattern and its matching resources without a runtime DLL.
class RegexSearch {

private:
    pcre2_code* code;
    pcre2_match_data* matchData;
    pcre2_match_context* context;
    wchar_t error[256];

    /// Converts a PCRE2 diagnostic into the retained Unicode error buffer.
    void SetError(int failure);

public:
    /// Initializes an uncompiled expression with no owned resources.
    RegexSearch();

    /// Releases the compiled expression and all match resources.
    ~RegexSearch();

    /// Prevents copying ownership of engine resources.
    RegexSearch(const RegexSearch&) = delete;

    /// Prevents assigning ownership of engine resources.
    RegexSearch& operator=(const RegexSearch&) = delete;

    /// Compiles Unicode multiline matching with optional invariant case folding.
    bool Compile(const wchar_t* pattern, bool matchCase);

    /// Finds the next nonoverlapping match at or after the supplied UTF-16 offset.
    RegexSearchResult Next(const wchar_t* text, int length, int offset, int* start, int* matchLength);

    /// Returns the retained engine diagnostic, or an empty string after successful compilation.
    const wchar_t* GetError() const;
};
