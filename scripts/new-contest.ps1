<#
.SYNOPSIS
    Create a new contest folder with template files and Makefile.
.EXAMPLE
    .\scripts\new-contest.ps1 cf 900-div2
    .\scripts\new-contest.ps1 cf 900-div2 8
    .\scripts\new-contest.ps1 atcoder 350-abc
    .\scripts\new-contest.ps1 leetcode 400-weekly
#>
param(
    [Parameter(Mandatory)][string]$Platform,
    [Parameter(Mandatory)][string]$Contest,
    [int]$Problems = 0
)

$root = Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)

$platformMap = @{
    "cf"        = "codeforces"
    "codeforces" = "codeforces"
    "atcoder"   = "atcoder"
    "at"        = "atcoder"
    "leetcode"  = "leetcode"
    "lc"        = "leetcode"
}

if (-not $platformMap.ContainsKey($Platform)) {
    Write-Error "Unknown platform: $Platform. Use cf/atcoder/leetcode."
    exit 1
}
$platformDir = $platformMap[$Platform]

if ($Problems -eq 0) {
    $defaults = @{
        "codeforces" = 7
        "atcoder"    = 7
        "leetcode"   = 4
    }
    $Problems = $defaults[$platformDir]
}

$dir = Join-Path $root "contest" $platformDir $Contest
if (Test-Path $dir) {
    Write-Error "Directory already exists: $dir"
    exit 1
}

New-Item -ItemType Directory -Path $dir -Force | Out-Null

$template = Join-Path $root "template" "default.cpp"
$makefile = Join-Path $root "scripts" "Makefile"

if ($platformDir -eq "leetcode") {
    for ($i = 1; $i -le $Problems; $i++) {
        Copy-Item $template (Join-Path $dir "Q$i.cpp")
    }
} else {
    $letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for ($i = 0; $i -lt $Problems; $i++) {
        Copy-Item $template (Join-Path $dir "$($letters[$i]).cpp")
    }
}

if (Test-Path $makefile) {
    Copy-Item $makefile (Join-Path $dir "Makefile")
}

Write-Host "Created: $dir" -ForegroundColor Green
Get-ChildItem $dir | ForEach-Object { Write-Host "  $_" }
