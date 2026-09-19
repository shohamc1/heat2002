#!/bin/sh
# Whole-ROM safety check with the target draft excluded (it duplicates the
# asm copy until integration). Restores the draft on every exit path.
set -e
REPO=/Users/shohamc1/heat2002-gba
SRC="$REPO/src/sub_0800D684.c"
HELD=/tmp/held_sub_0800D684.c
restore() {
    if [ -f "$HELD" ]; then mv "$HELD" "$SRC"; fi
}
trap restore EXIT INT TERM

if [ -f "$SRC" ]; then mv "$SRC" "$HELD"; fi
rm -f "$REPO/build/src/sub_0800D684.o" "$REPO/build/src/sub_0800D684.s" "$REPO/build/src/sub_0800D684.i"
cd "$REPO"
start=$(date +%s)
make -B check 2>&1 | tail -5
echo "corpus_check took $(( $(date +%s) - start ))s"
