param(
    [int[]]$Chapters = (13..18),
    [string]$Compiler = ""
)

$ErrorActionPreference = "Stop"

function Resolve-Compiler {
    param([string]$RequestedCompiler)

    if ($RequestedCompiler -ne "") {
        if (-not (Test-Path -LiteralPath $RequestedCompiler)) {
            throw "Compiler not found: $RequestedCompiler"
        }

        return (Resolve-Path -LiteralPath $RequestedCompiler).Path
    }

    $fromPath = Get-Command g++ -ErrorAction SilentlyContinue
    if ($fromPath) {
        return $fromPath.Source
    }

    $mingwCompiler = "C:\MinGW\bin\g++.exe"
    if (Test-Path -LiteralPath $mingwCompiler) {
        return $mingwCompiler
    }

    throw "No g++ compiler found. Install MinGW or pass -Compiler C:\path\to\g++.exe."
}

$repoRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$compilerPath = Resolve-Compiler $Compiler
$compilerDir = Split-Path -Parent $compilerPath
$env:PATH = "$compilerDir;$env:PATH"
$failures = @()

foreach ($chapter in $Chapters) {
    $chapterPath = Join-Path $repoRoot ("chapter_{0:D2}" -f $chapter)
    if (-not (Test-Path -LiteralPath $chapterPath)) {
        Write-Host "Skipping missing chapter: $chapterPath"
        continue
    }

    $exerciseDirs = Get-ChildItem -LiteralPath $chapterPath -Directory |
        Where-Object { $_.Name -like "exercise*" } |
        Sort-Object Name

    foreach ($dir in $exerciseDirs) {
        $sources = @(Get-ChildItem -LiteralPath $dir.FullName -Filter "*.cpp" -File |
            Sort-Object Name |
            ForEach-Object { $_.FullName })

        if ($sources.Count -eq 0) {
            continue
        }

        $exePath = Join-Path $dir.FullName ($dir.Name + ".exe")
        Write-Host "Building $($dir.Name)..."

        $arguments = @("-std=c++17", "-O2", "-static-libgcc", "-static-libstdc++") + $sources + @("-o", $exePath)
        & $compilerPath @arguments
        if ($LASTEXITCODE -ne 0) {
            $failures += $dir.FullName
        }
    }
}

if ($failures.Count -gt 0) {
    Write-Host ""
    Write-Host "Failed builds:"
    foreach ($failure in $failures) {
        Write-Host "  $failure"
    }

    exit 1
}

Write-Host ""
Write-Host "Exercise executable build complete."
