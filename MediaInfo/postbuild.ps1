<#
This is open-source software licensed under the terms of the MIT License.

Copyright (c) 2026 Petr Červinka - FortSoft <cervinka@fortsoft.eu>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Last modified for version 1.1.0.1
#>

param(
    [Parameter(Mandatory = $true)]
    [string]$Path,
    [string]$Library
)

$ErrorActionPreference = 'Stop'
$bytes = [IO.File]::ReadAllBytes($Path)
$pe = [BitConverter]::ToInt32($bytes, 60)
if ([BitConverter]::ToUInt32($bytes, $pe) -ne 0x4550 -or
    [BitConverter]::ToUInt16($bytes, $pe + 4) -ne 0x14C -or
    [BitConverter]::ToUInt16($bytes, $pe + 24) -ne 0x10B) {
    throw 'Expected a Win32 PE32 executable.'
}
foreach ($relative in @(40, 48)) {
    $offset = $pe + 24 + $relative
    [Array]::Copy([BitConverter]::GetBytes([UInt16]4), 0, $bytes, $offset, 2)
    [Array]::Copy([BitConverter]::GetBytes([UInt16]0), 0, $bytes, $offset + 2, 2)
}
[Array]::Clear($bytes, $pe + 24 + 64, 4)
[IO.File]::WriteAllBytes($Path, $bytes)
if ($Library -and [IO.File]::Exists($Library)) {
    $dll = [IO.File]::ReadAllBytes($Library)
    $dllPe = [BitConverter]::ToInt32($dll, 60)
    if ([BitConverter]::ToUInt32($dll, $dllPe) -eq 0x4550 -and
        [BitConverter]::ToUInt16($dll, $dllPe + 4) -eq 0x14C) {
        Copy-Item -LiteralPath $Library `
            -Destination (Join-Path (Split-Path -Parent $Path) 'MediaInfo.dll') -Force
    } else {
        Write-Host 'The solution-root MediaInfo.dll is not x86 and was not copied.'
    }
}
