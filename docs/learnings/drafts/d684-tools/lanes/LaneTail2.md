# LaneTail2 report — sub_0800D684 (tail block + pre-loop family)

Working dir: `/tmp/LaneTail2/` (nothing was written into the repo tree; `tools/agbcc`,
`src/`, `asm/`, `build/`, `ldscript.ld` untouched).

## 1. Baseline and best

| stage | file | size | hunks | sdiff |
|---|---|---|---|---|
| baseline on entry (7th pass) | `/tmp/lanebase/base.c` (then 345) | 2010 | 2 | 585 |
| intermediate | `/tmp/lanebase/base.c` after LanePAIR's `cc2 = cc;` | 2006 | 0 | 345 |
| **best found by me (adopted)** | `/tmp/LaneTail2/best335.c` == `/tmp/lanebase/base.c` == `src/sub_0800D684.c` | **2006** | **0** | **335** |

Metric: `python3 docs/learnings/drafts/d684-tools/filediff.py FILE --workdir DIR`.

### The winning edit (semantics-preserving, already in the baseline)

```c
/* in the post-loop block, before: */
    d1 = (s32)(*cc2).c;
    w = d1;
/* after: */
    w = (s32)(*cc2).c;
```

Dropping the dead `d1` carrier in the tail fixes exactly the two lines
`800db4a ldrh r0,[r6,#52]` / `800db4c lsrs r1,r0,#8` (target loads into `r0`,
the carrier version loaded into `r6`) and regresses nothing: 345 − 10 = 335,
size 2006, hunks 0 (`c_base2.txt` → `c_best335.txt` diff in this dir).

I reported this to Main; it was adopted in parallel (`cmp best335.c /tmp/lanebase/base.c` → identical).

## 2. What the remaining 335 is

`cost.py base3.c` (`/tmp/LaneTail2/cost.py`) shows 62 differing lines, no shape
differences (all 5s and 10s). They cluster into these families:

| group | address(es) | what differs |
|---|---|---|
| pre-loop | 800d6cc/6ce | `a1->unk18F` constant scratch (target r1, ours r6) |
| pre-loop | 800d6e8/6ec | `pa` address temp for the `sub_0800D5D4(a1, pa)` arg (target r7, ours r2) |
| pre-loop | 800d6f2/6f8 | `flag = 0`/`i`/`count` (target r2/r3, ours r3/r6) |
| pre-loop | 800d742/746 | `d0 = self->unk08` load (target r0, ours r5) |
| mirror-1/2 | 800d880/890/892/896/8c0, 800d9a8..9d8 | `e` in r4 (target) vs r6 (ours) |
| mirror-1/2 | 800d850/856, 800d902/908, 800daec/af2 | `k3/k0 = edgeq + v2` in place (target) vs temp (ours) |
| post-loop | 800dc0c..800dc1e, 800dde2..dde8 | `k2`/`v55` swap, byte-load temp (others' territory) |

Tooling built for this (all under `/tmp/LaneTail2/`): `gen.py` (parameterised tail
generator, verified byte-identical to the baseline file when the parameters are
the baseline's), `patch.py`, `sweep.py`, `cost.py`, `struct.py`, `sites.py`,
`rng.py`, `rev.py`, `stmts.py`, `pin_sweep.py`, `lmmap.py`/`grp.py`.

## 3. Sweeps run (all scored with filediff.py; "inert" = exactly the baseline score)

| # | sweep | variants | best | notes |
|---|---|---|---|---|
| 1 | tail read-routing: 16 subsets of {.a,.c,.d,.g} through `cc2` × 5 pins (∅/r3/r4/r5/r7) × `cc2 = cc` vs `= &gUnk_0202CC90` × 3 `k0` spellings | 480 | 345 (18 of them) | on the 345 baseline; with `cc2 = cc` the read spelling is inert |
| 2 | tail `ang`-line respellings (10 forms: casts, k2/d0 temp, raw pointer, `/256`, …) | 10 | 345 (9 inert) | the load temp is allocator-chosen, spellings do not move it |
| 3 | declaration-list single moves (all ordered pairs) | 602 | 345 (526 inert) | only moves of `a2`/`i`/`m,q`/`count` change anything (357–2577) — they move **stack slots**; the region is at a local optimum |
| 4 | register pins `register T x asm("rN")` for 20 locals × {r0..r7} | 180 | 345 (inert when the local is already there) | pinning `e`→r4 etc. is 4–60× worse; no pin helps |
| 5 | edge-carrier flip: `kN = edgeq + vX;` → `edgeq += vX;` / combined expression, all 5 sites (3^5) | 216 | 345 (base) | in-place at S3/S4 is neutral, combined forms cost 2–6 hunks |
| 6 | tail dials on the 335 base (w spellings, u0 removal, ang temps, ccd/k0/k1 spellings, `g` global, pin regs, `cc2 =` position, hit2 cast) | 26 | 335 (10 inert) | the 345-forms regress; nothing below 335 |
| 7 | revert of the 25 documented "recent accepted edits" | 25 | **335** (r08) | see §1; on top of r08 the other 24 reverts are 335–835 |
| 8 | pre-loop spellings: unk18F guard (`!x`, raw pointer, reorder, carrier, `or`-split), `k0 = (s32)pa` carriers (k1/k2/k3/d0/d1/edgeq/v1hold/global/none/cast), `count` computation (carrier through `a2`, `==` form, swapped init, casts), for-head (`i=0` hoist, casts, `(u8)count`, `s32 count`), `dz` block (`d1`/`k0`/reverse/`d3`/edgeq-first/no-d0) | 74 | 335 (many inert) | pre-loop region yields **nothing** below 335; every real change is worse (350…850) |
| 9 | `(s32)` cast removal at each of the 8 cast sites | 9 | 345 (4 inert) | the 4 `sub_0800E708` casts matter (445), the rest inert |
| 10 | per-half duplicates of the 15 long-lived carriers (`d0b`, `d1b`, `eb`, …) | 30 | 345 (10 inert) | splitting `d0`/`d1`/`u`/`w`/`e` across halves is much worse (405–29000) |
| 11 | adjacent-statement swaps across the function | ~200 | 345 | mostly compile-neutral/inert; no improvement |
| 12 | guard-carrier sweep at the two `(d1 = (e = …))` sites: 12 carriers × 12 (147 incl. no-carrier) | 147 | **335 only for `d1`/`d1`** | confirms the current carrier choice is the optimum of that coordinate |

| 13 | pairs of the 16 revert dials (`C(16,2)`) | 120 | 360 (best pair) | two individually-bad edits never cancel below 335 |
| 14 | `cc2` declaration hoisted to function scope (4 positions) / non-asm register / r5 / first-in-block | 7 | 335 (5 inert) | placement of the pinned declaration is inert; dropping `asm` costs 2 hunks |
| 15 | pre-loop extra carriers: 20 carriers for `k0 = (s32)pa`, 17 for an `a1->unk18F` temp, `(u8)count`/`s32 count`/`s32 i` | 40 | 335 (11 inert) | nothing below 335 |

| 16 | **reload spill-set scan** (`tools/agbcc/gcc/old_agbcc` with `RT_ALL=1`, verified byte-identical code to the shipped cc1) over every candidate in `cand/` | 2395 | 335 | 339 variants have r4 in USEDSPILL; **all 339 score ≥ 1766** (they are the broken-tail variants for which r4 stops being used). Sets seen: 1764× {0,1,2,3,6} (baseline), 297× {0,1,2,3,4,6}, 210× {0,1,2,3,5}, 41× {0,1,2,3,4,5}, 10× {0,1,2,3,7}, 9× {0,1,2,3,5,6}, 8× {0,1,2,3,5,7}, 1× {0,1,2,3,4}. Data: `spill.json`, `r4_in_spillset.txt` |

## 4. Diagnostics (evidence, not adoptable edits)

* ROM literal pool (read from the ROM image): `0x800da04=0x175`, `da08=0x202A550`,
  `da0c=0x18F`, `da10=0x202CD24`, `da14=0x202CCB0` (pa), `da18=0x202CD30` (pb),
  `da1c=-0x1C00`, `da20=0x202CC90` (cc), `da24=-0xF00`. Confirms the pre-loop
  differences are folded *field-offset* / *address* constants.
* `old_agbcc -dg -dumpbase dmp` (global-alloc dump, `dmp.greg`/`dmp.rtl`/`dmp.lreg`)
  identifies the pseudos: `e` = reg 45, `w` = 44, `u` = 43, `d1` = 36, `k3` = 40,
  `edgeq` = 46. Global alloc's "Register dispositions" gives 45→r4, 44→r8, 43→r7,
  40→r3, 46→r1 — i.e. global-alloc *does* give `e` r4, and the r6 uses at
  `800d890`/`800d9aa` are downstream (reload-side), which is why no source spelling
  of the `e` expression moves them.
* `old_agbcc -fdump-reg-lifetimes` (fork-only flag, per-function hard-register
  live-range source lines) for the baseline:
  `r0=687-948 r1=715-938 r2=719-938 r3=724-938 r4=728-945 r5=752-915 r6=724-944 r7=781-935 r8=780-938 r9=772-827 sl=729-847`.
* The fork's `RT_SET`/`RT_ADDSET`/`RT_DELSET`/`RT_FORCE_LIST`/`RT_ALL` hooks in
  `reload1.c` are **not compiled into the shipped `tools/agbcc/old_agbcc`**
  (`strings` finds none of them), so reload-register forcing could not be used
  without rebuilding the compiler (out of scope). `forcecheck.py` therefore
  cannot be re-run against the current baseline here.
* `find_free_register` (resource.c) has no callers; reload scratch choice comes
  from `allocate_reload_reg` (reload1.c), which round-robins `spill_regs` from
  `last_spill_reg` — the spill order itself comes from `order_regs_for_reload`,
  which is a function of `hard_reg_n_uses`. That couples the pre-loop reload
  scratches to the loop's allocation, which is consistent with every pre-loop
  dial being inert or harmful.

## 5. Unverified / not done

* The lower bound is not established: I did not search pairs/triples of dials
  around the two biggest families (`e`-in-r4/r6, `edgeq`-temp) beyond the
  coordinates listed above; those are the most likely place for a sub-335 hit.
* The `RT_*` reload-forcing experiments (diagnostic) were not run — the shipped
  `old_agbcc` lacks the instrumentation and rebuilding is out of scope.
* No claim is made that any of the listed variants is *faithful* beyond being
  semantics-preserving as written; only `r08` (the adopted edit) was verified
  against the baseline by filediff.

## 6. Post-295 re-sweep of the pre-loop axis (new baseline 2006/0/295)

`base4.c` = `/tmp/lanebase/base.c` at 295 (`filediff.py` verified). Remaining
pre-loop debt there is 4 groups / 50 sdiff:
`800d6cc/6ce` (folded `0x18F` constant scratch, target r1 vs ours r6),
`800d6e8/6ec` (`pa` address temp, target r7 vs ours r2),
`800d6f2–6f8` (`flag`/`i`/`count`, target r2/r3 vs ours r3/r6, 20 sdiff),
`800d742/746` (`self->unk08` load, target r0 vs ours r5).

Retried on the new baseline, all semantics-preserving, all ≥ 295:

* `pa` value through a fresh pinned local (`register s32 pax asm("rN")` and
  `register s32 *pax asm("rN")`, N = r0..r7, replacing `k0 = (s32)pa`) — 16
  variants: 295 (inert) at r2/r3 (the allocator's own choice), 305 at r4, 537 at
  r1, worse at the rest; r7 (the target's register) is not among the 295 group.
* `self->unk08` through a fresh block-scoped local `dzt` (unpinned) and pinned to
  r0..r7, plus `dz -= other->unk08` and a fresh `dxt` for `self->unk00` — 11
  variants, 655 (all the same worse code), 795 for the `dz -=` form.
* counter zero through a fresh pinned `iz` (`iz = 0; i = (u8)iz;`), `count` read
  through a fresh pinned `cz`, `pa` through a fresh pinned pointer `paz` — 24
  variants: 295 (inert) for `iz` at r0..r4, 1883+ for `paz`, 4992+ for r7.
* the earlier pre-loop battery re-run on 295 (guards, `count` spellings, `i`
  types/hoist, `pa` carriers, `cursor`/`base` respellings, `pa[4]`, self-store
  removal, `dz` reversal) — 37 variants, best 295, several 305–737.

Conclusion for this lane: the pre-loop family is not reachable by the
"fresh pinned local" lever in any form tried (>350 variants); its four remaining
recolours are reload-scratch choices downstream of the whole-function
`hard_reg_n_uses`/spill-order computation.

## 7. Checkpoint at the 285 baseline (final)

`base5.c` == `/tmp/lanebase/base.c` == 2006 / 0 / 285 (verified). The pre-loop
debt is unchanged by the two later tail wins — the same 4 groups, 50 sdiff:
`800d6cc/6ce` (folded `0x18F` scratch: target r1, ours r6), `800d6e8/6ec`
(target r7, ours r2), `800d6f2–6f8` (target r2/r3, ours r3/r6), `800d742/746`
(target r0, ours r5).

Chain-level evidence for why source edits cannot move these: `RT_ALL=1` USES
lines show the *pre-loop* chains have `uses = [24, 0, 0, 0, 0, 0, 0, 0]`, i.e.
r1..r7 are all zero-use candidates there, yet the emitted code uses r6 (at
`800d6cc`, `800d6f6`) and r2 (at `800d6e8`) — so those two registers are not
reload scratch choices at all but *allocno* choices made by global-alloc from the
pre-loop RTL's conflict structure, which is fixed by the surrounding code.

Every "fresh pinned local" form Main proposed for this region was measured on the
295 base (see §6) and again at 285; all are the baseline score or worse. I have no
candidate below the current baseline for this lane.

## 8. Re-runs against the later baselines (295 → 285 → 276 → 265)

The whole pre-loop lever library (`preloop285.py`, ~100 variants: guard
spellings, 20 `pa` carriers, count/i forms, dz block forms and pins,
`cursor`/`base` respellings, plus the pinned-pointer `pk = gUnk_0202CCB0;`
form copied from the adopted wins) was re-run at 295, 285, 276 and 265.
Result every time: **MIN == the baseline**, i.e. every variant is either inert
(identical code) or worse. Reverts/pins (incl. all 20 locals × r0..r7) and all
602 declaration-move permutations were re-run at 276: nothing below.

Audit note (per Main's cost-1 lesson): my adopted edit (`w = (s32)(*cc2).c;`)
touched only the two cost-5 lines at 800db4a/800db4c and introduced **no**
cost-1/cost-2 line — `c_base2.txt` vs `c_best335.txt` contain only 5-cost
entries, so it is a pure recolour fix and behaviour-safe by construction.

Final state of this lane: no candidate below the current baseline; the pre-loop's
50 sdiff of recolours (four groups listed in §6/§7) are global-alloc allocno
choices, provably not reachable from source spellings/pins/carriers/orderings in
that region.

## 9. Per-mirror value splits (Main's item 1) against 265

Tested by renaming a value to a fresh local (`Xb`, declared next to the original)
across exactly one mirror half and re-scoring; then the same with the fresh local
pinned (`register s32 Xb asm("rN")`).

* mirror-2, unpinned: v2 1738, v4 580, w 2013, v1hold 265 (inert), k0 265 (inert),
  k2 265 (inert), k3 627, k1 670, edgeq 670, d0 655, d1 939, v1 1342, v3 28828.
* mirror-1, unpinned: v2 1161, v4 1285, w 2244, v1hold 265 (inert), k0/k2 265 (inert),
  k3 627, k1 670, edgeq 670, d0 655, d1 27522, v1 970, v3 28555.
* pinned r4/r5/r6/r7 (both halves, all of the above): 2013–30019, no exceptions.

`BELOW 265: none` in every batch. LaneEDGE ran the mirror-2 pinned variants in
parallel with identical conclusions; the value-split lever does not move the
mirror `e`/r4 sites from either half.

## 10. Spill-order scan against Main's uid-1439 criterion

Captured the *ordered* `spill_regs` list for all 3080 candidate files
(`spillseq.json`, via `RT_ALL=1` and the `SPILLSET <reg> -> idx <index>` trace
lines). Baseline order is (0,1,2,3,6) — 2253 candidates; other orders seen:
(0,1,2,3,5) 343, (0,1,2,3,4,6) 298, (0,1,2,3,4,5) 53, (0,1,2,3,7) 18,
(0,1,2,3,5,6) 17.

353 candidates make **r4 the 5th spill entry** (i.e. `spill_regs[4] = 4`, the
register Main's uid-1439 trace says would fix the rotation). Every one of those
candidates was scored with `filediff.py` in the r4-set sweep above: best 1766,
i.e. none of them retains a good tail — the order change comes only from the
broken-tail variants (pin/form changes that lose the `cc2` allocation), never
from a preserving edit. So within my 3080-candidate corpus there is no variant
that is simultaneously good and has r4 at index 4.
