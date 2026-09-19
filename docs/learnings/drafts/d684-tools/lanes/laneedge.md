# LaneEDGE report — `e`-register recolour family in `sub_0800D684`

Lane dir: `/tmp/laneedge` (nothing written outside it).

## Baseline (final)
`/tmp/laneedge/base.c` == `/tmp/lanebase/base.c` == `src/sub_0800D684.c`

    filediff.py /tmp/laneedge/base.c  ->  {"size": 2006, "hunks": 0, "sdiff": 265}

The baseline moved 585 -> 345 -> 335 -> 295 -> 285 -> 276 -> 265 during my run.
**Every final number below was re-measured against 265.**

## Result
**No semantics-preserving edit in the `e`-carrier family beats 265.**
Every sub-265 candidate found needs a carrier whose value is *not* `e` at that
point (or an unrelated value move), i.e. it is a diagnostic, not a fix.

## Candidates (all measured against the 265 baseline, filediff.py)

| file | size | hunks | sdiff | semantics |
|---|---|---|---|---|
| `/tmp/laneedge/BEST_diag_all3.c` | 2006 | 0 | **225** | DIAGNOSTIC ONLY |
| `/tmp/laneedge/BEST_diag_m2e2argd1.c` | 2006 | 0 | 250 | DIAGNOSTIC ONLY |
| `/tmp/laneedge/BEST_diag_m1e1argk3.c` | 2006 | 0 | 260 | DIAGNOSTIC ONLY |
| `/tmp/laneedge/BEST_diag_cplain_m2e2argd1.c` | 2006 | 0 | 230 | DIAGNOSTIC ONLY |
| `/tmp/laneedge/BEST260_Cplain+M2e2argd1.c` | 2006 | 0 | 250 | DIAGNOSTIC (295-era file) |

Edits (src line numbers in base.c):

1. `Cplain` — line 825 guard `(d1 = (e = v2 - 0x1C00))` -> `(e = v2 - 0x1C00)`.
   Semantics-preserving; 305 alone (worse than 265).
2. `M2e2argd1` — line 835 arg `(e << 16) / u` -> `(d1 << 16) / u`.
   DIAGNOSTIC: `d1` = `pb[7]-pa[7]`; the ROM's arg is `e` (`lsls r0, r4, #16`
   at 0x800da5a).
3. `M1e1argk3` — line 792 arg `(e << 16) / u` -> `(k3 << 16) / u`.
   DIAGNOSTIC: `k3` = `edgeq + v1`; the ROM's arg is `e` at 0x800d86a.

## What the diagnostics fix (address -> target text)

`BEST_diag_m2e2argd1` (250) fixes, purely by reallocation:
```
800da54  add  r0, sp, #32        (&flag address, target r0)
800da56  str  r0, [sp, #4]
800da70  mov  r1, r8             (w > 0 compare, target r1)
800da72  cmp  r1, #0
```
and breaks only its own arg `800da5a lsls r0, r6, #16`.

`BEST_diag_all3` (225) additionally fixes **the whole mirror-2 edge-0 `e`
family** and two more sites, while breaking only its three own arg/scratch
slots:
```
FIXED   800d864/866  add r0, sp, #32 / str r0, [sp, #4]
FIXED   800d880/882  mov r1, r8 / cmp r1, #0
FIXED   800d9aa      adds r4, r4, r0      <- mirror-2 edge-0 e in r4
FIXED   800d9ac      cmp  r4, #0
FIXED   800d9b2      muls r0, r4
FIXED   800d9d8      lsls r0, r4, #16
BROKEN  800d860/862  ldr r6,=[cc] / str r6,[sp,#0]
BROKEN  800d86a      lsls r0, r3, #16   (own arg)
BROKEN  800da5a      lsls r0, r6, #16   (own arg)
```
Note that in `all3` the mirror-2 edge-0 arg is still the **correct** `(e << 16)`
— so the whole 0x800d9a8–0x800d9d8 family (20 sdiff) is reachable while keeping
semantics. The two divergent dials are only needed to trigger the reallocation.

## Site map (line numbers in `base.c`)
| site | src lines | source text | ROM reg | our reg |
|---|---|---|---|---|
| M1e0 | 782–787 | `(e = v2 - 0x1C00)` | r4 | r4 ok |
| M1e1 | 788–793 | `(e = -0x1C00 - v2)` | r4 | r4 ok |
| **M1A** | 794–801 | `(d1 = (e = -0xF00 - v1))` | **r4** | **r6** |
| M1e3 | 802–809 | `(e = v1 - 0xF00)` | r4 | r4 ok |
| **M2C** | 825–830 | `(d1 = (e = v2 - 0x1C00))` | **r4** | **r6** |
| M2e2 | 831–836 | `(e = -0x1C00 - v2)` | r4 | r4 ok |
| M2e3 | 837–842 | `(e = -0xF00 - v1)` | r4 | r4 ok |
| M2e4 | 843–848 | `(e = v1 - 0xF00)` | r4 | r4 ok |

M1A recolours: 0x800d890/892/896/8c0. M2C recolours: 0x800d9aa/9ac/9b2/9d8.

## Mechanism
The only two mismatched `e` sites are exactly the only two guards that wrap `e`
in a dead copy `(d1 = (e = <expr>))`. The copy tie drags the coalesced (e,d1)
pair to `d1`'s function-wide register r6, where the ROM has r4. Removing the
wrap lets `e` take the source register in place — that *is* what the ROM does —
but it reallocates the neighbouring scratch (`movs r2,#240`, `ldr r3,=[cc]`,
`add r0,sp,#32`, `movs r2,#224`) by more than it gains.

## Sweeps run (all under `/tmp/laneedge`, ≤ -j8, `__main__`-guarded)

| # | sweep | count | best / outcome vs 285 |
|---|---|---|---|
| 1 | whole-function `register s32 e asm("rN")`, r0–r9,sl | 11 | all worse |
| 2 | fresh local + `asm("rN")` pin at M1A and/or M2C (4×4) | 16 | all >= 26411 (345-era) |
| 3 | M1A×M2C guard-carrier form sweep | 65 | 330 (345-era) |
| 4 | A{guard×chain×arg} × C{guard×arg} | 194 | 330 (345-era) |
| 5 | M2C{guard carrier × pre/post `d1=e` × arg carrier} | 301 | 330 (345-era) |
| 6 | expression respellings at A and C | 15 | neutral/worse |
| 7 | per-part carrier sweep: 7 e-sites × {guard,mul,arg} × 7 carriers | 2401 | only 11 of 126 single-part changes <= 400; 9 of them use the other-valued `d1`/`k3` |
| 8 | in-place `edgeq += X` accumulators, all subsets | 32 | only `Cplain` helps |
| 9 | combinations of the 6 best single dials, all subsets | 64 | 245 (all3) |
| 10 | slot coordinate descent (27 slots, free + preserving-only) | 2 descents | 245 free; preserving-only made no move |
| 11 | multiplication commutations | 128 | neutral/worse |
| 12 | preserving respellings/reorderings/operand swaps/bound rewrites | 322 | **ZERO below 295** |
| 13 | loop-variable pins `u->r7,w->r8,v1hold->r9,edgeq,d1` | 26 | all worse |
| 14 | arithmetic respellings (divisor, casts, `0x10000`, bounds) | 154 | all neutral |
| 15 | **pinned-fresh-local lever** (Main's recipe) on 12→9 edge values × {unpinned, r0–r7} | 118 → 109 (285) → 82 (276) | **ZERO below 285 / 276**; best just tie the baseline |
| 16 | RT-trace (`RT_ALL=1`) USEDSPILL scan over carrier reverts, sizes 1–3 | 1350 traced | 23 exact-set hits, all need the divergent `k3_4` |
| 17 | cached `cc` pointer `ccE` for the eight edge call sites, pins r0–r7 + mirror-subsets | 18 | all worse (best 3332) |
| 17b | block-scoped `u8 *fp = &flag;` breakout at the seven edge call sites, {unpinned, r0–r3} | 36 (276) + 15 (265) | unpinned exactly neutral; pinned all >= 649 |
| 17d | braced pinned copy of the argument value (`register s32 eo asm("rN"); eo = e; ... (eo << 16)`) at six edge call sites, {unpinned, r0–r7} | 55 (re-run on 265) | unpinned neutral (265); every pinned form 2010/2/649 |
| 17c | diagnostics `Cplain`/`M2e2argd1`/`M1e1argk3` singles+pairs+triple | 8 (re-run on 276) | best 236, all DIAGNOSTIC |
| 18 | per-region `edgeq` fresh-local + pin for M1e1/M2C/M2e2 | 28 | ZERO below 285 |
| 19 | `k3` (M1e1 accumulator) fresh-local + pins | 9 | all worse, 2 hunks |

## Left open / unverified
* The copy-tie explanation is inferred from generated code; I did not read
  agbcc's `local-alloc.c`/`reload1.c` for this lane.
* Every sub-285 candidate here is semantics-changing and must not be adopted
  without an independent semantics-preserving derivation.
* Untested: `-f`-flag dials, compiler rebuilds, edits outside the eight edge
  blocks (other lanes own those), and src lines 839/845 (handed to LanePostT).

## Main's item 1 and item 2 (re-run on 265) — both closed

**Per-mirror-2 fresh-local splits** (Main's item 1), assignment right after the
def line, all later mirror-2 uses renamed, {unpinned, r0-r7}, 37 variants:
```
v1hold unpinned 265/0/2006  (EXACTLY NEUTRAL; pins r7 5 hunks/881, r4 43 hunks, r5/r6 ~46 hunks)
v4     unpinned 494/2       (pins r0 679, r1 980)
v2     unpinned 1510/10     (pins r4 2002/2/689, r7 2002/7/1175)
w      unpinned 1709/13     (all pins >= 2208)
```
Mirror-1 was left to LaneTail2 (handed over by IRC).

**Per-edge-block fresh-local split of `edgeq`** (Main's item 2), 64 variants,
best 310: M1A/M1e3/M2e4 pinned r7 = 310, M1e0 r7 = 315; every unpinned form
gains 2 hunks (M1e0 617, M1A 500, M1e3 495, M2e4 503).

**Block-scoped pinned argument copies** (Main's item 3 attempts), 55 variants:
`register s32 eo asm("rN"); eo = e;` inside braces immediately before the call
at six edge sites -> unpinned neutral (265), every pinned form 2010/2/649.

Nothing under 265 was found in any of these.

## uid-434 / uid-1447 probe (Main's relocation target) — 265 baseline

New probe `/tmp/laneedge/rt2.py` records every `NEWSPILL uid= reg=` in emission
order together with the `USES` occupancy vector that precedes it:

```
base 265:  uid  434  NEWSPILL reg 0   occ r0..r10 = 0 0 0 0 448 0 0 315 200 24 74
           uid 1447  NEWSPILL reg 6   occ r0..r10 = 24 77 30 27 24 427 0 315 200 0 0
           USEDSPILL = 0 1 2 3 6   (first pick of each: r1@63, r2@63, r0@77, r3@91, r6@1447)
```

Tests aimed at freeing r4 at uid 434 (all measured at 265):
```
volatile s32 v[4]                 2030/19/4218   uid434 occ r4: 448 -> 416
volatile only the mirror-2 v2 store  2010/7/1247  uid434 occ r4: 448 (unchanged)
per-mirror-2 split of v2 (v2b)       1510/10      uid434 occ r4: unchanged
```
Conclusion: r4's 448 `uses` at uid 434 barely move under any `v2` respelling —
the accumulator is dominated by the function-wide 0x140 REG_EQUIV pseudo in the
tail (which LaneSpill showed matches the ROM). `hard_reg_n_uses` is a
function-wide weighted count, so it is not the quantity that decides `e`'s
destination; local-alloc's liveness is, and in the ROM `r4` is free at `e`'s
birth only because the ROM keeps `v2` in memory ([sp,#20]) while our compile
keeps `v[1]` in r4 across the four mirror-2 guards. Forcing `v` into memory
costs 19-25 hunks. No preserving edit found that changes the pick.
