# LaneBig — randomized lever-set search, sub_0800D684

**Unadopted improvement: (hunks, sdiff, size) = (2, 602, 2010)** vs baseline (2, 617, 2010).
Best file `/tmp/LaneBig/BEST.c` (copy of `adopt1.c`). One single-line edit, line 772 of
`src/sub_0800D684.c`, first loop mirror, right after `sub_0800D5D4(cursor, pb);`:

    old:         d0 = pa[4];
    new:         d0 = gUnk_0202CCB0[4];

Equivalence: `pa` is set once (`pa = gUnk_0202CCB0;`) before the loop and never reassigned;
`gUnk_0202CCB0` is read-only here (`sub_0800D5D4` writes only through `pb`), so the two lvalues
are the same at that point. Verified effect: exactly three recoloured lines disappear from
`filediff --list` at 0x800d770/772/774 (ours `r6` where the ROM has `r0`): 3 x 5 = 15 sdiff.
`size` 2010 and hunks 2 (`t_extra 0 / o_extra 2`) unchanged.

Second equivalent set, different byte stream, also (2, 602, 2010) — `/tmp/LaneBig/final_best.c` =
the edit above **plus** `        d0 = pb[4];` -> `        d0 = gUnk_0202CD30[4];` (mirror 2).
Adopt only one; BEST.c is the minimal.

## Table

| file | size | hunks | sdiff | set |
|---|---|---|---|---|
| `/tmp/LaneBig/BEST.c` | 2010 | 2 | **602** | `pa[4]` -> `gUnk_0202CCB0[4]` (mirror 1) |
| `/tmp/LaneBig/final_best.c` | 2010 | 2 | 602 | above + `pb[4]` -> `gUnk_0202CD30[4]` (mirror 2) |
| `/tmp/LaneBig/best.c` | 2010 | 2 | 602 | best 9-lever descent set (no better) |
| `/tmp/LaneBig/v0.c` (baseline) | 2010 | 2 | 617 | — |

## Search

Library: **139 sites / 340 levers** — dead-store carriers on all 8 edge guards; per-occurrence
`pa[k]`/`pb[k]` <-> global respellings (20 sites); bound-carrier swaps + `edgeq += x` +
numerator/shift spellings; `cc` <-> `&gUnk_0202CC90` at all 8 calls; pre-loop `pa` carrier (17
locals); `v1hold`/`v`-computation carriers both mirrors; post-loop `(*cc)`/`ccd`/`gUnk_083FDA2C`/
`q0`/`q1` spellings; `((struct Ent*)x)->f` vs pointer locals; `unk48/unk40`, `sd`/`hit2`;
self-store removals; `base` == `(struct Ent *)gUnk_0202A550`; guard operand order; statement
reorders. Cost: ~10,700 scored variants in the box at `-j4` (340 singles + 9,741 logged set
evaluations, 1,127 rejected as textually conflicting, +291 output-hash probes), ~45 min.

Singles ranking found exactly one improvement; object-hash sweep showed 89/291 original levers
are byte-identical to the baseline (only 173 distinct outcomes). Then full-neighbourhood
coordinate descent (~440 evals/step) from the baseline and from the winning lever, with plateau
moves, plus 9,000 randomized sets of size 2-7 (half forced through the winner).

## Learning

The lever class is nearly spent: 89 of 291 single edits compile byte-identically to the baseline,
198 are strictly worse, and exactly one family moves sdiff. The win is *occurrence-specific*, not
family-wide — `pa[4]` in the first mirror is worth -15, while the textually adjacent `pa[5]`,
`pb[4]`, `pb[5]` and every mirror-2 read are neutral or worse. Mechanism: `pa` is a spilled
pseudo, so each read is a fresh `ldr rN,=gUnk_0202CCB0` remat whose scratch register depends on
the surrounding chain's live set; writing the global directly reshapes just that chain and hands
it r0 (the ROM's register) instead of r6 without moving any other insn's cost. The generalisable
rule is therefore to enumerate one lever per *occurrence* of an aliasable lvalue, not per
statement or per family. The reachable plateau for this library is 602: descent from both the
baseline and from the winning seed converged there in ~6 steps and then only wandered among
byte-identical neighbours, and 9,000 random sets of size 2-7 never beat it.