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

#include "RegexSearch.h"

/// Initializes an uncompiled expression with no owned resources.
RegexSearch::RegexSearch() : code(nullptr), matchData(nullptr), context(nullptr) {
    error[0] = 0;
}

/// Releases the compiled expression and all match resources.
RegexSearch::~RegexSearch() {
    pcre2_match_context_free(context);
    pcre2_match_data_free(matchData);
    pcre2_code_free(code);
}

/// Converts a PCRE2 diagnostic into the retained Unicode error buffer.
void RegexSearch::SetError(int failure) {
    if (pcre2_get_error_message(failure, reinterpret_cast<PCRE2_UCHAR*>(error), ARRAYSIZE(error)) < 0) {
        lstrcpynW(error, T(TXT_FIND_FAILED), ARRAYSIZE(error));
    }
}

/// Compiles Unicode multiline matching with optional invariant case folding.
bool RegexSearch::Compile(const wchar_t* pattern, bool matchCase) {
    pcre2_match_context_free(context);
    pcre2_match_data_free(matchData);
    pcre2_code_free(code);
    context = nullptr;
    matchData = nullptr;
    code = nullptr;
    error[0] = 0;
    uint32_t options = PCRE2_UTF | PCRE2_UCP | PCRE2_MULTILINE | PCRE2_ALT_BSUX
        | PCRE2_DUPNAMES | PCRE2_NEVER_BACKSLASH_C;
    if (!matchCase) {
        options |= PCRE2_CASELESS;
    }
    int failure = 0;
    PCRE2_SIZE offset = 0;
    code = pcre2_compile(reinterpret_cast<PCRE2_SPTR>(pattern), PCRE2_ZERO_TERMINATED,
        options, &failure, &offset, nullptr);
    if (!code) {
        SetError(failure);
        return false;
    }
    matchData = pcre2_match_data_create_from_pattern(code, nullptr);
    context = pcre2_match_context_create(nullptr);
    if (!matchData || !context) {
        SetError(PCRE2_ERROR_NOMEMORY);
        return false;
    }
    pcre2_set_match_limit(context, 1000000);
    pcre2_set_depth_limit(context, 1000);
    pcre2_set_heap_limit(context, 32768);
    return true;
}

/// Finds the next nonoverlapping match at or after the supplied UTF-16 offset.
RegexSearchResult RegexSearch::Next(const wchar_t* text, int length, int offset, int* start,
        int* matchLength) {
    int result = pcre2_match(code, reinterpret_cast<PCRE2_SPTR>(text), length, offset, 0, matchData, context);
    if (result == PCRE2_ERROR_NOMATCH) {
        return RegexSearchResult::NotFound;
    }
    if (result < 0) {
        SetError(result);
        return RegexSearchResult::Error;
    }
    PCRE2_SIZE* range = pcre2_get_ovector_pointer(matchData);
    *start = static_cast<int>(range[0]);
    *matchLength = static_cast<int>(range[1] - range[0]);
    return RegexSearchResult::Match;
}

/// Returns the retained engine diagnostic, or an empty string after successful compilation.
const wchar_t* RegexSearch::GetError() const {
    return error;
}
