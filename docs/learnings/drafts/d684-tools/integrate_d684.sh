#!/bin/sh
# Integrate sub_0800D684 once match.py reports MATCH.
#
#   docs/learnings/drafts/d684-tools/integrate_d684.sh          # dry run + checks
#   docs/learnings/drafts/d684-tools/integrate_d684.sh --apply  # do it
#
# Steps (all verified by hand in DECOMP-001 and again for this function):
#   1. cut asm/rom_0800D684.s at the `thumb_func_start sub_0800D684` line,
#      keeping the macro preamble (lines 1-34) in place;
#   2. create asm/rom_0800DE5C.s = same preamble + the function's trailing
#      `.byte 0x00, 0x47, 0x70, 0x47` rows;
#   3. insert `build/src/sub_0800D684.o(.text*);` and `build/asm/rom_0800DE5C.o(.text*);`
#      between `build/asm/rom_0800D684.o(.text*);` and `build/src/sub_0800DE60.o(.text*);`
#      in ldscript.ld, in that order.
set -e
REPO=/Users/shohamc1/heat2002-gba
APPLY=0
[ "$1" = "--apply" ] && APPLY=1
cd "$REPO"

echo "== match.py =="
RESULT=$(python3 scripts/match.py sub_0800D684 2>/dev/null | head -1)
echo "$RESULT"
case "$RESULT" in
  *": MATCH ("*) ;;
  *) echo "ABORT: sub_0800D684 does not MATCH yet" >&2; exit 1 ;;
esac

FRAG=asm/rom_0800D684.s
LINE=$(grep -n $'\tthumb_func_start sub_0800D684$' "$FRAG" | head -1 | cut -d: -f1)
[ -n "$LINE" ] || { echo "ABORT: function not found in $FRAG" >&2; exit 1; }
echo "function starts at line $LINE of $FRAG"

if [ "$APPLY" = 0 ]; then
    echo "dry run: would keep lines 1-$((LINE-1)), write asm/rom_0800DE5C.s, patch ldscript.ld"
    exit 0
fi

head -n $((LINE-1)) "$FRAG" > /tmp/d684_head.s
cp /tmp/d684_head.s "$FRAG"
{ cat /tmp/d684_head.s; printf '\t.byte 0x00, 0x47, 0x70, 0x47\n'; } > asm/rom_0800DE5C.s
python3 - <<'PY'
import pathlib
p = pathlib.Path("ldscript.ld")
t = p.read_text()
old = "        build/asm/rom_0800D684.o(.text*);\n        build/src/sub_0800DE60.o(.text*);"
assert t.count(old) == 1, t.count(old)
new = ("        build/asm/rom_0800D684.o(.text*);\n"
       "        build/src/sub_0800D684.o(.text*);\n"
       "        build/asm/rom_0800DE5C.o(.text*);\n"
       "        build/src/sub_0800DE60.o(.text*);")
p.write_text(t.replace(old, new))
print("ldscript.ld patched")
PY
make check
python3 scripts/progress.py