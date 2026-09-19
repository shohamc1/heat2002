#!/bin/sh
# DIAGNOSTIC: does shifting reload's rotating spill-register index reach the ROM?
# Patches last_spill_reg's start value in reload1.c, rebuilds cc1, scores
# several candidate sources. Restores reload1.c at the end.
set -e
SUB=/Users/shohamc1/heat2002-gba/tools/agbcc
for k in -1 0 1 2 3 4 5; do
    sed -i '' "s/^  last_spill_reg = .*;/  last_spill_reg = $k;/" "$SUB/gcc/reload1.c"
    grep -n "^  last_spill_reg" "$SUB/gcc/reload1.c"
    rm -f "$SUB/gcc/reload1.o"
    make -C "$SUB/gcc" old -j8 >/tmp/d684v5/build_diag_$k.log 2>&1
    cp "$SUB/gcc/old_agbcc" "/tmp/d684v5/cc_r$k"
    for f in /tmp/d684v5/base.c /tmp/d684v5/lanetail/tail_k2.c /tmp/d684v5/h3_e3carrier.c; do
        out=$(python3 /tmp/d684v5/d684tool.py check "$f" --workdir /tmp/d684v5/wddiag --json --cc "/tmp/d684v5/cc_r$k" 2>&1 | head -1)
        echo "k=$k $(basename $f) $out"
    done
done
sed -i '' "s/^  last_spill_reg = .*;/  last_spill_reg = -1;/" "$SUB/gcc/reload1.c"
rm -f "$SUB/gcc/reload1.o"
make -C "$SUB/gcc" old -j8 >/tmp/d684v5/build_diag_restore.log 2>&1
cd "$SUB" && git status --short
echo DIAG-DONE
