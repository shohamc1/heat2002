# LanePostT — post-loop tail + mirror-2 sites (`sub_0800D684`)

Lane: `/tmp/LanePostT`. All work confined to `/tmp/LanePostT/`; no repo edits, no builds,
no changes under `tools/agbcc` (read-only use of the RT-instrumented `gcc/old_agbcc`
and of `gcc/reload1.c` / `gcc/local-alloc.c`).

## Baseline / best

| | path | size | hunks | sdiff |
|---|---|---|---|---|
| baseline at lane start | `/tmp/lanebase/base.c` | 2006 | 0 | **335** |
| **best (this lane)** | `/tmp/LanePostT/best265.c` | 2006 | 0 | **265** |

`best265.c` is byte-identical to `/tmp/lanebase/base.c` and to
`/Users/shohamc1/heat2002-gba/src/sub_0800D684.c` at the time of writing — i.e. all
of this lane's wins were verified by Main and adopted.

Reproduce: `python3 docs/learnings/drafts/d684-tools/filediff.py /tmp/LanePostT/best265.c --workdir /tmp/LanePostT`

## Adopted wins (all semantics-preserving, all verified by Main with `filediff.py`)

### Win 1 — 335 → 295 : split the tail address off the `k2` allocno
`/tmp/LanePostT/gen2/k5_r0_none_ve_k2_cc_glob.c` (copy: `best295.c`)

* declare `register s32 k5 asm("r0");` and `u8 ve;` in the post-loop block;
* `k2 = (s32)&u->unk55; v55 = *(u8 *)k2; d1 = k2;`
  -> `k5 = (s32)&u->unk55; v55 = *(u8 *)k5; d1 = k5;`
* the final `v55 = 0x10; *(u8 *)d1 = v55; hit2->unk55 = v55;` uses `ve`.

Effect: fixes 0x800dc0c/0x800dc0e/0x800dc10/0x800dc12/0x800dc14/0x800dc1c/0x800dc1e
(-40), nothing broken. The tail address was sharing the whole-function `k2` pseudo
(global-alloc home r1); the ROM has it in r0, so it must be a separate pseudo.

### Win 2 — 295 → 285 : pin the tail's `gUnk_0202A550` address; fresh gate carrier
`/tmp/LanePostT/gen3/fresh_pinr2_cc_glob_base.c` (copy: `best285.c`)

* declare `register struct Ent *b5 asm("r2");`, set it once before the outer gate
  (`b5 = (struct Ent *)gUnk_0202A550;`) and respell the three
  `(struct Ent *)gUnk_0202A550` comparisons in that gate as `b5`;
* `k2 = gUnk_020021E0; if (k2 == 0 && ...)` -> `s32 kb; kb = gUnk_020021E0; if (kb == 0 && ...)`.

Effect: fixes 0x800dde2/0x800dde8 (-10), nothing broken. The gate split alone costs
+10 because it knocks the tail's A550 address materialisation from r2 to r1; pinning
`b5` to r2 recovers it. `gUnk_0202A550` is an array whose *address* is taken and never
its value, so caching the address is value-preserving.
Equivalent gate spellings that also give 285: `register s32 kg asm("r0")` (pinned) and
the temp-free `if (gUnk_020021E0 == 0 && ...)`.

### Win 3 — 276 → 265 : pinned pointer at mirror-2 edge-3
`/tmp/LanePostT/gen7/e3cpr1.c` (copy: `best266.c`; adopted on top of LaneARG's
brace fix, measured 265)

* declare `register struct Unk0802CC90 *cp asm("r1");`
* at mirror-2 edge-3 only:
  ```c
  if ((u32)(d1 + 0x1C00) <= 0x3800) {
      cp = &gUnk_0202CC90;
      sub_0800D64C(cursor, a2, a1, 3, cp, &flag, -w, (e << 16) / -w);
  }
  ```

Effect: fixes 0x800dafc/0x800dafe (-10), nothing broken.

**Placement rule (the reusable part).** The pinned assignment must be the statement
*immediately before the call, inside a braced `if` body*. Putting the same assignment
at the top of the guard block lets the constant load schedule one slot early and
produces an insert/delete hunk pair (2006/4, 2010/4, or 2010/2 depending on the site).
Every one of my earlier `cp` attempts at this site failed for exactly that reason.

## Sweeps run (counts)

| tag | generator | variants | best | note |
|---|---|---|---|---|
| s1 | `levers.py` singles (tail spellings/carriers) | 34 | 335 | all neutral or worse |
| s2 | `levers2.py` singles | 30 | 335 | 11 neutral, rest worse |
| gen | `gen.py` 9-dim product (pvar/order/load/vvar/gvar/m2/evar) | 5760 generated | — | superseded (started on the 335 base) and cancelled once gen2 produced 295 |
| **gen2** | `gen2.py` pins × fresh address | 480 | **295** | win 1 |
| **gen3** | `gen3.py` gate × A550 × mirror-2 args | 240 | **285** | win 2 |
| gen4 | `gen4.py` pinned mirror-2 call args | 36 | 285 | pin there adds an instruction |
| gen5 | `gen5.py` `k0`/`d1` splits at 839/845 | 99 | 285 | pinned and unpinned all worse |
| gen6 | in-place `edgeq += v2` forms | 18 | 285 | worse |
| **gen7** | placement of the pinned pointer at mirror-2 edge-3 | 12 | **266** | win 3 (adopted as 265) |
| gen8 | `fp = &flag;` / `nw = -w;` pins at edge-3 | 11 | 478 | worse |
| gen9 | `nw` pin (r0/r1/r2/r3) ± `fp` | 12 | 832 | worse |
| gen10 | edge-2 pin: 5 registers × 4 placements | 20 | 798 | load schedules early |
| gen11 | gen10 re-run on 265 | 16 | 934 | worse |
| gen12 | `fp`/`nw` pins at edge-3 (correct placement) | 19 | 582 | worse |
| gen13 | edge-2 constant respellings | 8 | 265 | neutral or 2010/4 |
| gen14 | block-scoped `fp` pin at edge-3 | 4 | 582 | worse |
| gen15 | in-place accumulation re-run on 265 | 6 | 265 | neutral or worse |
| gen16 | per-mirror splits of `v2`/`v4`/`w`/`v1hold` and per-edge `edgeq` in mirror-2 (power set) | 113 | 265 | `VH` byte-identical; rest 503+ |
| gen17 | shaping the tail `q0`/`q1` read-modify-write group to free r4 at RTL uid 1448 (scored with filediff **and** USEDSPILL) | 275 | 265 | no variant reaches r4 in `used_spill_regs`; only sets seen are {0,1,2,3,6} (195), {0,1,2,3} (56, best 3737) and {0,1,2,3,5,7} (24, best 29067) |
| gen18 | mirror-1 edge-2 carriers (`k1 = e; d1 = k1;` forms, fresh/pinned `e`, in-place `edgeq += v2`) | 27 | 265 | all neutral (including `d1 = e`, which Main measured at 290 on an older base) |
| s1/s2 rerun | tail libraries against 265 | 47 | 265 | nothing new |

Total ≈ 1300 scored variants in the finalised rounds (plus the 5760-variant product
that was generated and partially run before being superseded).

## Round-7 detail: the r4-at-uid-1448 lead (measured, refuted)

Main's follow-up hypothesis was that the 5th `spill_regs` entry is r6 because r4 is
occupied at the chain that first needs a 5th scratch (the tail `w->unk0C -= q0;` /
`w->unk14 -= q1;` pair, RTL uids 1447-1456), and that freeing r4 there would rotate
the whole set to the target's. `gen17.py` reshapes exactly those statements (explicit
`x = x - q` forms, `*(s32 *)(w+12)` offset forms, a `struct Ent *wp` pointer carrier,
moving `hit2 = (struct Ent *)w;` up to that point, fresh `q0`/`q1` carriers, u-group
respellings, group reordering, `d0 *= 1000` / `q0 = ...` respellings), singly and in
all pairs/triples, and scores each with filediff **and** the RT-instrumented
`USEDSPILL` set.

Result: 275 variants, **not one** puts r4 in `used_spill_regs`. The only sets observed
are `{0,1,2,3,6}` (195 variants, best 265), `{0,1,2,3}` (56, best 3737) and
`{0,1,2,3,5,7}` (24, best 29067) — so the set is a symptom, not a lever, exactly as
the later correction from Main states. The RTL at uid 1448 confirms why: the chain is
`r0 = mem[r6+12]; r6 = mem[sp+56]; r0 = r0 - r6; ...; mem[r6+12] = r0` — the scratch
that r6 supplies is the reload of the *spilled* `q0`, and `r4`'s 24 uses at that chain
come from elsewhere in the tail, not from these statements' temporaries.

`gen18.py` then took the other remaining lead — moving the *destination* of the
`-0xF00 - v1` / `-0x1C00 - v2` e-definitions (RTL uid 434, `e`'s birth) from r6 to r4
by reshaping the mirror-1 edge-2 carriers (`k1 = e; d1 = k1;` -> `d1 = e;` / dropped /
`d1 = (k1 = e);`, in-place `edgeq += v2`, fresh and r4-pinned `eg` locals, statement
reordering) — 27 variants, **all 265**. Notably `d1 = e` now scores 265 where Main
measured 290 on an earlier baseline, i.e. the allocation has drifted past that dial.

Together with the earlier rounds and the other lanes' ~25000 variants, `e`'s
destination at the loop edge blocks is not reachable from the source with any of the
levers known at this point.

## Round-6 detail: per-mirror value splits

`gen16.py` renames, in the mirror-2 half only, each of `v2` (-> `v2b`), `v4` (-> `v4b`),
`w` (-> `wh`), `v1hold` (-> `v1hb`) and per-edge `edgeq` (-> `eq0`/`eq1`/`eq2`/`eq3`),
individually and in every combination (113 variants, all compiled):

* `VH` (split `v1hold`) — byte-identical to the baseline.
* `EQ3` (edge-3 `edgeq`) 503/2; `EQ0` 580/2; `V4` 580/2 at 2002 bytes (loses the
  in-place `adds` shape); everything else worse. Nothing below 265.

Together with the earlier results on this axis (LaneEDGE: fresh `e2` locals pinned or
not, best 295, pinned 689-784; Main: pinning `e` to r4 = 1029), moving the mirror-half
`e`/`v2`/`edgeq` quantity into r4 from the source looks exhausted.

## What is left in this lane's region (unresolved)

Cost 5 each (from `filediff.py --list` on `best265.c`):

| address | target | ours | note |
|---|---|---|---|
| 0x800daa4/0x800daa6 | `ldr r3,[pc,#488]` + `str r3,[sp]` | `ldr r6,...` + `str r6,[sp]` | mirror-2 edge-2's `&gUnk_0202CC90`; needs r3 |
| 0x800db00/0x800db02 | `add r2,sp,#32` + `str r2,[sp,#4]` | `add r1,...` + `str r1,...` | mirror-2 edge-3 `&flag` |
| 0x800db04/0x800db06 | `mov r3,r8` + `negs r1,r3` | `mov r2,r8` + `negs r1,r2` | mirror-2 edge-3 `-w` copy |
| 0x800da94/0x800da96/0x800da98/0x800da9a | `adds r1,r1,r0` … | `adds r2,r1,r0` … | mirror-2 edge-2 bound in r1 vs r2 (src 839) |
| 0x800daec/0x800daf2 | `adds r1,r1,r0` ×2 | `adds r6,r1,r0`, `adds r1,r6,r0` | mirror-2 edge-3 bound in r1 vs r6 (src 845) |

Diagnosis (from the RT-instrumented compiler and `reload1.c`):

* the 0x800dc0c/dde2/…/dafc-class sites are **local-alloc/global-alloc** picks, and
  the pinned-fresh-local lever reaches them (three wins above);
* the remaining mirror-2 scratches at 0x800dafc-0x800db06 are **reload** registers
  chosen by `allocate_reload_reg`'s function-wide round-robin
  (`spill_regs[++last_spill_reg]`, `spill_regs` = `[r0,r1,r2,r3,r6]` here). Measured
  RT trace at the two mirrors: mirror-1 edge-3's `&flag` reload takes `reg=2 idx=2
  last=1`, mirror-2 edge-3's takes `reg=1 idx=1 last=0` — i.e. the same chain one
  round-robin slot apart. The ROM has both at `r2`, so the difference is the phase of
  that counter, not a source-level choice at these two instructions.
* Trying to pin those two values with `register u8 *fp asm("r2")` /
  `register s32 nw asm("r3")` makes the register *fixed for the whole function*,
  which re-allocates `w` from r8 to r9 and costs more than it fixes (best 582).

## Notes on method (correctness)

* Every candidate reported as a win was checked with `filediff.py --list` for new
  cost-1/cost-2 lines (branch targets/offsets) before being reported; the two cost-1
  lines that LaneConst's brace-dropping edit introduced were caught by Main/LaneARG and
  are not present in any variant from this lane. All of this lane's adopted edits keep
  `hunks == 0` and add no cost-1 line.
* All carriers used here are value-preserving: `k5`/`b5`/`kb`/`ve`/`cp` each receive one
  value that the replaced expression produced at the same point, and no value passed to
  `sub_0800D64C` / `sub_0800BA34` changes.

## Unverified / caveats

* `gen` (5760 variants) was generated against the 335 base and cancelled part-way; its
  results were never analysed. It is superseded by gen2-gen15.
* The `register ... asm("rN")` pins are the precedent already present in the adopted
  source (`cc2 asm("r4")`, now `k5 asm("r0")`, `b5 asm("r2")`, `cp asm("r1")`). They
  are semantics-preserving C but they are not something the original ROM source would
  have contained; if the project ever wants a pin-free match, the three wins above
  would each have to be re-derived from an allocator-visible structural difference.
* 0x800da94/0x800da98/0x800da9a and 0x800daec/0x800daf2 (src lines 839 and 845) were
  claimed from LaneEDGE mid-session; LaneEDGE confirmed the hand-off and also reported
  the same negative results (unpinned 335, pinned r7 340, r0-r6 much worse) that this
  lane reproduced.
