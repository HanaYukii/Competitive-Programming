#!/bin/bash
# Create a new contest folder with template files and Makefile.
#
# Usage:
#   ./scripts/new-contest.sh cf 900-div2
#   ./scripts/new-contest.sh cf 900-div2 8
#   ./scripts/new-contest.sh atcoder 350-abc
#   ./scripts/new-contest.sh leetcode 400-weekly

set -e

ROOT="$(cd "$(dirname "$0")/.." && pwd)"

PLATFORM="$1"
CONTEST="$2"
PROBLEMS="${3:-0}"

if [ -z "$PLATFORM" ] || [ -z "$CONTEST" ]; then
    echo "Usage: $0 <platform> <contest> [problems]"
    echo "  platform: cf, atcoder (at), leetcode (lc)"
    echo "  contest:  900-div2, 350-abc, 400-weekly, etc."
    echo "  problems: number of problems (default: 7 for cf/at, 4 for lc)"
    exit 1
fi

case "$PLATFORM" in
    cf|codeforces) PLATFORM_DIR="codeforces" ;;
    at|atcoder)    PLATFORM_DIR="atcoder" ;;
    lc|leetcode)   PLATFORM_DIR="leetcode" ;;
    *) echo "Unknown platform: $PLATFORM"; exit 1 ;;
esac

if [ "$PROBLEMS" -eq 0 ]; then
    case "$PLATFORM_DIR" in
        codeforces|atcoder) PROBLEMS=1 ;;
        leetcode)           PROBLEMS=1 ;;
    esac
fi

DIR="$ROOT/contest/$PLATFORM_DIR/$CONTEST"

if [ -d "$DIR" ]; then
    echo "Error: Directory already exists: $DIR"
    exit 1
fi

mkdir -p "$DIR"

TEMPLATE="$ROOT/template/default.cpp"
MAKEFILE_SRC="$ROOT/scripts/Makefile"

if [ "$PLATFORM_DIR" = "leetcode" ]; then
    for i in $(seq 1 "$PROBLEMS"); do
        cp "$TEMPLATE" "$DIR/Q$i.cpp"
    done
else
    LETTERS="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for i in $(seq 0 $((PROBLEMS - 1))); do
        LETTER="${LETTERS:$i:1}"
        cp "$TEMPLATE" "$DIR/$LETTER.cpp"
    done
fi

if [ -f "$MAKEFILE_SRC" ]; then
    cp "$MAKEFILE_SRC" "$DIR/Makefile"
fi

echo "Created: $DIR"
ls "$DIR"
