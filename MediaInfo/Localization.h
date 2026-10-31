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

/// Pairs a text identifier with its immutable translation.
struct LocalizedText {
    TextId id;
    const wchar_t* text;
};

/// Contains the complete set of interface texts for one supported locale.
struct LocalizedLanguage {
    AppLanguage id;
    LocalizedText texts[TXT_COUNT];
};

/// Identifies an embedded report translation by code, display name and resource identifier.
struct ReportLanguageEntry {
    const wchar_t* code;
    const wchar_t* name;
    UINT resource;
};

/// Returns the immutable translation for a supported language and named text key.
const wchar_t* GetLocalizedText(AppLanguage language, TextId id);

/// Returns the complete Help text for the active interface language.
const wchar_t* LocalizedHelpText();

/// Returns the number of original-English and official translated report-language choices.
int ReportLanguageCount();

/// Returns a report-language display name by index.
const wchar_t* ReportLanguageName(int index);

/// Returns the report-language table code, using an empty code for original English.
const wchar_t* ReportLanguageCode(int index);

/// Finds an official report-language choice by its independent table code.
int ReportLanguageIndex(const wchar_t* selection);

/// Loads an embedded or custom UTF-8 or UTF-16 report translation table into an owned Unicode buffer.
wchar_t* LoadReportLanguage(const wchar_t* selection, wchar_t* error, int capacity);
