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

#include "JpegEncoder.h"

/// Matches the GDI+ startup-input layout used by dynamically loaded entry points.
struct ImageStartupInput {
    UINT version;
    void* callback;
    BOOL suppressThread;
    BOOL suppressCodecs;
};

/// Matches the GDI+ codec metadata used to locate a JPEG encoder.
struct ImageCodec {
    GUID clsid;
    GUID format;
    const wchar_t* name;
    const wchar_t* dll;
    const wchar_t* description;
    const wchar_t* extensions;
    const wchar_t* mimeType;
    DWORD flags;
    DWORD version;
    DWORD signatureCount;
    DWORD signatureSize;
    const BYTE* signaturePattern;
    const BYTE* signatureMask;
};

/// Dynamically resolved GDI+ startup and encoder-enumeration entry points.
typedef int (WINAPI* ImageStartupFunction)(ULONG_PTR*, const ImageStartupInput*, void*);
typedef int (WINAPI* ImageEncodersSizeFunction)(UINT*, UINT*);
typedef int (WINAPI* ImageEncodersFunction)(UINT, UINT, ImageCodec*);

/// Loads optional GDI+ entry points and locates the installed JPEG encoder.
JpegEncoder::JpegEncoder()
    : module(nullptr), token(0), encoder(), shutdown(nullptr), create(nullptr), save(nullptr),
    dispose(nullptr), available(false) {
    wchar_t filename[MAX_PATH];
    UINT length = GetSystemDirectoryW(filename, MAX_PATH);
    if (!length || length + 13 >= MAX_PATH) {
        return;
    }
    lstrcatW(filename, L"\\gdiplus.dll");
    module = LoadLibraryW(filename);
    if (!module) {
        return;
    }
    ImageStartupFunction startup =
        reinterpret_cast<ImageStartupFunction>(GetProcAddress(module, "GdiplusStartup"));
    shutdown = reinterpret_cast<ShutdownFunction>(GetProcAddress(module, "GdiplusShutdown"));
    create = reinterpret_cast<FromBitmapFunction>(GetProcAddress(module, "GdipCreateBitmapFromHBITMAP"));
    save = reinterpret_cast<SaveFunction>(GetProcAddress(module, "GdipSaveImageToFile"));
    dispose = reinterpret_cast<DisposeFunction>(GetProcAddress(module, "GdipDisposeImage"));
    ImageEncodersSizeFunction getSize =
        reinterpret_cast<ImageEncodersSizeFunction>(GetProcAddress(module, "GdipGetImageEncodersSize"));
    ImageEncodersFunction getEncoders =
        reinterpret_cast<ImageEncodersFunction>(GetProcAddress(module, "GdipGetImageEncoders"));
    ImageStartupInput input = ImageStartupInput{ 1, nullptr, FALSE, TRUE };
    if (!startup
            || !shutdown
            || !create
            || !save
            || !dispose
            || !getSize
            || !getEncoders
            || startup(&token, &input, nullptr)) {
        return;
    }
    UINT count = 0;
    UINT bytes = 0;
    if (getSize(&count, &bytes)
            || !count
            || count > 4096
            || bytes < count * sizeof(ImageCodec)
            || bytes > 0x1000000) {
        return;
    }
    ImageCodec* codecs = static_cast<ImageCodec*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, bytes));
    if (!codecs) {
        return;
    }
    if (!getEncoders(count, bytes, codecs)) {
        for (UINT index = 0; index < count; ++index) {
            if (codecs[index].mimeType && !lstrcmpiW(codecs[index].mimeType, L"image/jpeg")) {
                encoder = codecs[index].clsid;
                available = true;
                break;
            }
        }
    }
    HeapFree(GetProcessHeap(), 0, codecs);
}

/// Shuts down GDI+ and releases its dynamically loaded module.
JpegEncoder::~JpegEncoder() {
    if (token && shutdown) {
        shutdown(token);
    }
    if (module) {
        FreeLibrary(module);
    }
}

/// Reports whether the native JPEG encoder was initialized successfully.
bool JpegEncoder::IsAvailable() const {
    return available;
}

/// Writes the rendered report bitmap using the available GDI+ JPEG encoder.
bool JpegEncoder::Save(const wchar_t* path, HBITMAP bitmap) {
    if (!available) {
        return false;
    }
    void* image = nullptr;
    if (create(bitmap, nullptr, &image)) {
        return false;
    }
    bool success = save(image, path, &encoder, nullptr) == 0;
    return dispose(image) == 0 && success;
}
