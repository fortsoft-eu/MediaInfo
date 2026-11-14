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

Last modified for version 1.2.1.8
#>

param(
    [Parameter(Mandatory = $true)]
    [string]$License,
    [Parameter(Mandatory = $true)]
    [string]$Output
)

$ErrorActionPreference = 'Stop'
$directory = Split-Path -Parent $Output
[IO.Directory]::CreateDirectory($directory) | Out-Null
$resourceCompilerLibraries = $env:LIB
try {
    $env:LIB = ''
    Add-Type -Path (Join-Path $PSScriptRoot 'ResourcePacker.cs') -ReferencedAssemblies 'System.dll', `
        'System.IO.Compression.dll'
} finally {
    $env:LIB = $resourceCompilerLibraries
}
$libraries = @(
    @{ Source = '26.10\MediaInfo.dll'; Packed = 'MediaInfo2610.packed' },
    @{ Source = '21.03\MediaInfo.dll'; Packed = 'MediaInfo2103.packed' },
    @{ Source = '0.7.60\MediaInfo.dll'; Packed = 'MediaInfo0760.packed' },
    @{ Source = '26.10\libcurl.dll'; Packed = 'libcurl.packed' },
    @{ Source = '21.03\libcurl.dll'; Packed = 'libcurlXP.packed' },
    @{ Source = 'libwebp.dll'; Packed = 'libwebp.packed' }
)
foreach ($library in $libraries) {
    $source = Join-Path $PSScriptRoot ('Resources\lib\' + $library.Source)
    $packed = Join-Path $directory $library.Packed
    [ResourcePacker]::Pack($source, $packed)
}
$notices = [IO.File]::ReadAllText($License, (New-Object Text.UTF8Encoding($false, $true)))
[IO.File]::WriteAllText($Output, $notices, [Text.Encoding]::Unicode)

$line = "`r`n"
$reportResources = New-Object 'Collections.Generic.List[string]'
$reportOrder = @(
    'cs', 'en', 'de', 'fr', 'es', 'it', 'pt', 'pt-BR', 'pl', 'sk', 'da', 'sv', 'tr', 'lt', 'hu', 'nl', 'ro',
    'gr', 'hr', 'ca', 'eu', 'gl', 'sq', 'be', 'bg', 'uk', 'ru', 'ar', 'fa', 'hy', 'id', 'ja', 'ka', 'ko',
    'th', 'zh-CN', 'zh-HK', 'zh-TW'
)
$reportDirectory = Join-Path $PSScriptRoot 'Resources\lang'
if (@(Get-ChildItem -LiteralPath $reportDirectory -Filter '*.csv').Count -ne $reportOrder.Count) {
    throw 'Expected all report translation tables in display order.'
}
$csvFiles = foreach ($code in $reportOrder) {
    Get-Item -LiteralPath (Join-Path $reportDirectory ($code + '.csv'))
}
$resource = 2000
foreach ($csv in $csvFiles) {
    if ($csv.BaseName -eq 'en') {
        continue
    }
    $text = [IO.File]::ReadAllText($csv.FullName, (New-Object Text.UTF8Encoding($false, $true)))
    $name = [regex]::Match($text, '(?m)^[ \t]*Language_Name;([^\r\n]*)').Groups[1].Value.Trim()
    if (-not $name) {
        throw ('Missing report language name: ' + $csv.Name)
    }
    $filename = 'Report-' + $csv.BaseName + '.utf16'
    [IO.File]::WriteAllText((Join-Path $directory $filename), $text, [Text.Encoding]::Unicode)
    $reportResources.Add($resource.ToString() + ' RCDATA "' + $filename + '"')
    ++$resource
}
[IO.File]::WriteAllText((Join-Path $directory 'ReportLanguages.rc2'),
    ($reportResources -join $line) + $line, [Text.Encoding]::ASCII)
