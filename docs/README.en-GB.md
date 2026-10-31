# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | **English (UK)** | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Native x86 Windows viewer for MediaInfo.dll reports. Each file has its own read-only tab.

[Build and compatibility details](#build) | [Dependency audit](#dependencies) | [Licence](../license.txt)

## Build

Open MediaInfo.sln in Visual Studio 2015 with the Visual C++ v140 toolset installed. Choose Release | Win32 and build the solution. The only application platform is Win32 (x86).

Outputs:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

The viewer does not link the C or C++ runtime and does not need an MSVC redistributable. The selected
MediaInfo.dll can have its own dependencies.

Building requires Windows PowerShell and .NET Framework. These are build requirements only; the native
executable requires neither PowerShell nor .NET.

### Release package

After building Release, run `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` .
The script creates `MediaInfo-<version>-win32.zip` in the solution directory, using the executable's four-part
file version. The archive contains `MediaInfo.exe` and the combined `license.txt` directly at its root.

## Compatibility

The Win32 viewer is designed to use Windows NT 4.0 APIs.

The executable includes three x86 MediaInfo libraries: 26.10 for current Windows, 21.03 from the Windows XP
package and 0.7.60 from the Windows 95–2000 package. A library's architecture alone does not determine its
operating-system compatibility. The viewer tries the bundled libraries from newest to oldest and stops after
the first successful load and version query.

Windows 95 is not currently a supported runtime.

## Usage

- File > Open (Ctrl+O) opens the Windows file dialog with multiple selection. On Windows Vista and later, Open
  and Save use the modern Common Item Dialog; older Windows use the legacy common dialogs.
- Drag one or more files onto the window, the EXE icon or its shortcut, or pass their paths on the command
  line. If multiple instances are disabled, the files open in the running window.
- Each distinct normalised full path has one tab. Reopening an already open file selects its existing tab
  without reloading or changing its report, selection or scroll position. Comparisons ignore path letter case.
  Multiple-file openings process the list in order and leave the last successfully processed file active,
  whether newly opened or already open. Hovering over a tab header displays the full file path in a native
  tooltip, including when the displayed filename is shortened.
- The File menu lists the eight most recently loaded files directly above Exit, between separators. Entries
  show only a number and filename. Selecting an entry opens its stored full path or selects its existing tab;
  successful reopening moves it to the top without duplicates. Selecting an unavailable file asks whether to
  remove its recent-files entry. The native question icon and Yes/No buttons are used. Yes is the default and
  removes the entry from the menu and registry; No retains it. The prompt includes the full path.
- The mouse wheel over overflowing tab headers scrolls the header strip one tab per message without changing
  selection or focus.
- Ctrl+Tab and Ctrl+Shift+Tab switch tabs; Ctrl+W closes the active tab. Middle-clicking a tab header closes
  that tab while preserving any other active tab. File > Close All closes every tab, including queued reports.
  File > Exit (Alt+F4) closes the application.
- Double-click selects a word. Triple-click selects a logical line. Dragging extends the selection by words or
  lines.
- Ctrl+A selects the report; Ctrl+C copies it.
- Settings > Preferences (Ctrl+G) opens a single preferences dialog for MediaInfo and curl paths, report font,
  font antialiasing, interface language and report language. An empty DLL path enables automatic discovery.
- The font button displays the family, point size and style and opens the standard Windows font dialog.
  Default restores Consolas, or Courier New if Consolas is unavailable; the Default button is disabled while
  the default is selected. User-selected fonts are retained without substitution by application code.
- Font antialiasing choices are ClearType when supported, GDI and None. The initial choice is ClearType when
  supported, otherwise GDI. Font settings affect only media reports and their image exports.
- File > Export (Ctrl+E) opens the Windows Save As dialog and exports the entire active report to TXT, BMP,
  GIF, JPEG, PNG, TIFF or WebP, including text outside the visible area.
- Help opens a separate modeless window with its own taskbar entry and minimize button. About is a modal
  dialog; its product header lists all three embedded DLL versions.

Print… (Ctrl+P) opens the system printer dialog and prints the complete active tab without a preview. The
selected report font is used; long lines wrap and the text is split into pages. Printing runs in the
background.

Open Folder… opens files directly in the selected folder, each in its own tab. Subfolders are not included.
Open and Open Folder share their last selected folder. Export remembers its own folder, defaulting to
Documents.

Advanced Mode shows additional report fields.

Full Parsing examines the entire file and can take longer. These report options and Trace Level belong to each
tab; a change refreshes only the active tab. The last manually chosen combination is saved for new tabs and
the next launch. A matching cached report is reused while the file remains unchanged.

Known Formats, Known Codecs and Known Parameters open in their own report tabs.

The initial window size and location are selected by Windows. Saved placement overrides those defaults on
later launches.

The left status pane shows file paths and loading progress; the right pane shows the loaded MediaInfo.dll
version. Long paths are shortened with an ellipsis to fit the available space.

## Create a Header File

Tools is the third main menu. Its Create a Header File… command opens one source file independently of the
report tabs and copies its first 524288 bytes (512 KiB). A shorter file is copied in full; an empty file
produces an empty output. This is ordinary binary file reading, without MediaInfo analysis or a requirement
for MediaInfo.dll. The tool leaves report tabs and the viewer's recent-files list unchanged.

After reading, the Save As dialog starts in the source file's folder and suggests video.mp4.header for
video.mp4: .header is appended to the complete original name. You can change both the name and the destination
folder. Cancelling either dialog writes no output. Replacing an existing destination requires confirmation.
The source stays unchanged; a failed save preserves the previous destination. Open and Save use the newest
native dialogs available on the current Windows version.

At application startup, the tool takes its initial input folder from File > Open. If no folder has been saved,
Windows chooses the initial location. After an input file is selected, the tool remembers its own folder only
until the application exits, even if Save As is cancelled. It neither changes the folders used by Open and
Export nor saves its own folder to the application settings. Every Save As dialog starts in the folder of the
currently selected input file, regardless of the previous save destination.

## Library discovery

A saved manual path is tried first. If it cannot be loaded, automatic discovery tries:

1. MediaInfo.dll beside the executable, then in each parent directory up to the drive or UNC share root.
2. ProgramFiles, ProgramFiles(x86) and ProgramW6432.
3. LOCALAPPDATA and APPDATA.

Under these installation roots, discovery checks MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo and Programs\MediaArea\MediaInfo. Unreadable locations and
incompatible DLLs are skipped. It does not recursively scan the disk.

If no compatible external DLL is found, the viewer tries the embedded versions in this order: 26.10, 21.03,
0.7.60. It extracts and tests one version at a time. Once a version loads successfully, older versions are
neither extracted nor tested. Distributing MediaInfo.exe alone is sufficient; a compatible external DLL always
takes priority and can be updated independently.

A failed manual library change retains the library that was already loaded.

## Report export

The Save As formats are ordered TXT, BMP, GIF, JPEG, PNG, TIFF and WebP. Unsupported encoders are omitted from
both modern and legacy dialogs.

TXT offers ANSI, UTF-8, UTF-8 with BOM, UTF-16 BE with BOM and UTF-16 LE with BOM. The second entry, UTF-8
without BOM, is the default. The complete report text and its original line endings are preserved.

BMP, PNG and TIFF preserve all rendered colours; GIF89a preserves the exact rendered palette when the image
has at most 256 colours. Export always writes the selected format or reports an error; it never substitutes
another format.

Images contain the full report in the selected report font, with black text on a white background. They do not
contain the application menu, tab headers, status bar, selection or caret. Rendering is independent of the
edit's scroll position.

To avoid silently truncating reports or exhausting the address space on older computers, a single image is
limited to 16,384 pixels wide, 32,767 pixels high and 256 MiB of uncompressed bitmap memory. Select a smaller
font if a report exceeds those limits.

`Google WebP (*.webp)` is the last format and saves the report losslessly.

WebP: 16383 × 16383 px.

## Interface and report languages

Preferences (Settings > Preferences, Ctrl+G) contains library paths, report font, antialiasing and language
choices. The interface has 36 variants and initially follows Windows. Reports always default to the library’s
original English, independently of Windows and the interface. Only a manual report-language choice changes
this: English, 37 translations or a custom MediaInfo CSV table.

OK or Apply commits changes; Cancel discards pending edits. Preferences sets the tab name limit (80 by
default) and clears the recent-files list. Long names retain their beginning, ending and extension with a
middle ellipsis.

By default, only one instance is allowed and later launches send files to the open window. Preferences can
allow multiple instances. With multiple windows, only the first window of each form restores its saved
position; later windows restore size only.

Changing only the interface leaves the text of open reports unchanged. A manually applied report-language
change reloads their reports while preserving tab order and MRU order.

## libcurl

Automatic curl discovery checks beside the selected MediaInfo DLL, then the shared executable/ancestor,
Program Files and user-installation locations. If no compatible external curl is found, the matching embedded
current or XP version is extracted into the checked per-user cache. The oldest MediaInfo 0.7.60 bypasses curl
discovery, extraction and loading entirely. An explicitly selected invalid curl rejects the preference change;
missing optional automatic curl does not prevent ordinary local-file reports.

## Filename captions and recent history

MRU filenames are shortened only when longer than 80 UTF-16 code units. A middle ellipsis preserves the
beginning, the end of the stem and the complete final extension; full paths and reports remain unchanged. Tab
captions use the same algorithm with a configurable default limit of 80.

Recent files > Clear immediately clears both the live MRU menu and its saved paths while leaving all open tabs
intact. It does not apply or validate pending preferences and does not enable Apply. Cancel or Escape
preserves the cleared history while discarding pending edits. Clear is disabled whenever the list is empty,
and its state is refreshed when new reports populate the list. A registry-write failure is reported
immediately. Applying a new tab-name limit updates every open tab without reloading its media report.

## Licence and redistribution

The viewer is licensed under the MIT Licence in license.txt.

MediaInfo is a third-party component. The sole maintained distribution notice is root license.txt, encoded as
UTF-8 with CRLF and including the viewer, libraries, statically incorporated components, icon and official
translation tables.

This product uses the MediaInfo library, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licence: <https://mediaarea.net/en/MediaInfo/License>
- Windows downloads: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Dependencies

### Files

| Resource | Architecture | Version reported by the component | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Paths in the table are relative to the MediaInfo project directory.

The current library reports a development version; its exact source commit cannot be recovered from that
version string. Its accompanying notice uses the upstream 8.11.0 copyright and permission text, whose licence
terms are also present in the development series.

### Incorporated components

| Component | Evidence and scope | Notice |
| --- | --- | --- |
| MediaInfoLib | Actual versions and required Unicode exports; unchanged supplied binaries | Version-specific original copyright, redistribution conditions and disclaimer |
| ZenLib | Static project references and embedded ZenLib RTTI in all three DLLs; exact linked revisions not supplied | zlib-style ZenLib notice |
| zlib | Embedded inflate/deflate version strings: 1.3.2 in MediaInfo 26.10, 1.2.11 in 21.03, 1.2.7 in 0.7.60; curl additionally reports 1.3.1 and 1.2.8 | Original zlib notices for all five versions |
| TinyXML-2 | Matching modern source targets and binary RTTI; included in the legacy project, but not independently identified in the stripped legacy binary | Original Lee Thomason zlib-style notice retained |
| Brian Gladman AES | Included in both modern upstream library targets, with matching permissive source notices | 1998–2013 redistribution notice and disclaimer |
| Brian Gladman SHA-1/SHA-2 | Both modern targets; SHA-256 and SHA-512 constant tables present in both modern binaries | 1998–2010 redistribution notice and disclaimer |
| Brian Gladman HMAC | Both modern targets and their curl/S3 reader code | Original three-condition notice, including its alternative-licence paragraph |
| MD5 | Modern source targets; Colin Plumb implementation explicitly states public domain | Attribution retained |
| Base64 | Markus Ewald header in all three corresponding source trees, crediting Bob Withers | Original authorship attribution retained; qualification below |
| fmt | 26.10 target and fmt v11 format_error RTTI in the binary | Original MIT notice, including optional exception |
| tfsxml | 26.10 source target | Original MediaArea MIT notice |
| Android JNI interface | JNI_OnLoad is actually exported by both modern DLLs; the included JNI header is from AOSP | AOSP copyright and complete Apache Licence 2.0 |
| libcurl | Supplied x86 binaries; actual version exports; dynamically used by modern MediaInfo | Original curl notices for 8.11.0 and 7.47.1 |
| Official report translations | All 38 unmodified CSV sources from the MediaInfo v26.10 language directory; 37 non-English tables are embedded, while English uses DLL defaults | Same project BSD-2-Clause notice retained in the combined notice |
| MediaInfo icon | Unmodified official multi-image icon, source revision f057dd3649bc8692a83863b67770e22c9b9dd81a | Original BSD-2-Clause notice and attribution |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

The matching source targets establish inclusion in those upstream build configurations; they do not prove that
every function survives optimisation in the vendor binaries. No exact-version claim is made for dependencies
whose revision is not recorded in those binaries.

### Optional components and system libraries

- The Windows library projects enable runtime-loaded libcurl for MediaInfo 26.10 and 21.03. MediaInfo 0.7.60
  was built with MEDIAINFO_LIBCURL_NO; its binary also contains the disabled-support diagnostic. The viewer
  never discovers, extracts or loads curl for that bundled version.
- libmms is disabled in all three supplied Windows DLLs, as confirmed by their embedded disabled-support
  messages. It is not redistributed.
- Qt and wxWidgets belong to optional GUI builds. Neither is included in this viewer or in these DLL
  dependencies. Their generic entries were removed from the displayed licence.
- Graphviz is an optional runtime hook in modern upstream code. No Graphviz DLL is redistributed.
- No FFmpeg plugin is redistributed.
- The MediaInfo DLLs directly import only KERNEL32.dll. This does not mean that their statically linked
  runtime and helper code are absent.
- Current curl directly imports WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll and KERNEL32.dll. XP curl
  directly imports WS2_32.dll, WLDAP32.dll, ADVAPI32.dll and KERNEL32.dll. These are Windows components. Their
  availability is checked by the Windows loader.
- Curl reports Windows Schannel/WinSSL, not an OpenSSL build. Its reported additional compression dependency
  is statically included zlib. No additional external non-Windows DLL appears in its direct import table.
- The viewer itself has no C/C++ runtime dependency. The supplied third-party DLLs contain their own compiled
  runtime portions. The Windows builds use Microsoft tooling; there is no evidence requiring the generic
  libstdc++ or libc++ inventory entries.
- JPEG uses dynamically loaded system GDI+. The C# resource packer and PowerShell are build tools and are not
  runtime dependencies.

Ordinary local-file inspection does not require a MediaArea server or a remotely downloaded format database.
libcurl is used by MediaInfo for URL inputs and potentially remote references in supported media formats.
Bundling it does not add a separate URL-opening command to this viewer.

### Licence storage and limitations

The sole maintained distribution notice is [license.txt](../license.txt) , encoded as UTF-8 with CRLF. The
checked BSD, curl, zlib, MIT and Apache redistribution clauses do not require a separate notice file
physically beside each DLL; the combined notice accompanies them in the executable and distribution materials.

The archived MediaInfo 0.7.60 package uses its own version-specific licence and includes the old GNU Library
GPL text. Its terms expressly distinguish unmodified binary redistribution from modified versions; dynamic
linking by this viewer does not modify the supplied DLL. Its original conditions and accompanying licence text
are retained. The viewer remains MIT-licensed.

One upstream attribution needs qualification: the Markus Ewald Base64 header has no explicit permission or
licence statement. MediaArea describes the Bob Withers Base64 implementation as public domain in its related
MediaConch documentation, but that does not independently establish a licence grant for every Ewald change. No
licence grant has been invented for that header. A complete vendor confirmation of that provenance, the exact
ZenLib revisions and the curl development commit was not available in the supplied binaries. These points
prevent treating this inventory as a complete, independently certified SBOM.

### Primary sources

- [MediaInfo redistribution terms](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 library target](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 library target](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 library target](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl loader](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Bundled helper sources and their notices](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib notice](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib source notices](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 notice](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 notice](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache Licence 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 description](https://github.com/MediaArea/MediaConch/blob/master/README.md)

The report tables come from
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . The matching project
LICENCE is <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
