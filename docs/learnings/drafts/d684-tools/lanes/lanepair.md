# LanePAIR report — combinatorial re-search over the lever library (2026-09-19)

## Lane result

**Best file produced by this lane: `/tmp/lanepair/best_cc2eqcc.c`
= `2006 / 0 / 345`** (verified with `filediff.py`), found on the then-baseline
`2010 / 2 / 585` and adopted by Main immediately (Main then added
`w = (s32)(*cc2).c;` for the `d1 = …; w = d1;` carrier → 335, and the session
went on from there: 295, 285, 276, 275, 265).

The edit is one statement, semantics-preserving:

```c
    register struct Unk0802CC90 *cc2 asm("r4");
    cc2 = &gUnk_0202CC90;   ->   cc2 = cc;
```

It coalesces the two post-loop pointers, so the address is materialised in the
pinned r4 exactly once and both names read it; **both structural hunks
(`adds rN, r4, #0` at 0x800db44 / 0x800db66) disappear and the instruction
stream becomes identical to the ROM's** (size 2006, hunks 0).

Everything else in this lane was search, and **no lever set went below the
baseline in force at the time**. Total ≈ 300 000 compiled/scored variants.

## Sweeps, per baseline

| baseline | stage | variants | best | note |
|---|---|---|---|---|
| 585 | targeted tail probes | 22 | **2006/0/345** | the `cc2 = cc` win |
| 335 | `levers.py` singles | 473 | 335 | 87 neutral, 386 worse |
| 335 | neutral-pair stage | 3 535 | 335 | |
| 335 | `levers.py`+`levers2.py` neutral pairs | 4 427 | 335 | |
| 335 | **all pairs, full library** | 108 025 | 335 | completed, no improvement |
| 335 | triples over best-40-pair levers | 7 472 | 335 | |
| 335 | `alias_sweep.py` 30 occurrences: 1/2/3 at a time | 30 / 435 / 4 060 | 335 | 13 singles byte-identical |
| 335 | `constcarry.py` (27 sites, every occurrence) | 1 367 | 335 | all neutral/worse |
| 335 | `bigpairs.py` (auto-filtered library) | 1 201 | 335 | only **51 of its levers** still match |
| 335 | `carriersub.py` (≤4 removals) | 6 195 | 6 hunks / 1370 | **20 of 22 carriers** still apply |
| 335 | `levers2.py` singles (swaps, renames) | 41 | 335 | all 13 renames **byte-identical** |
| 335 | `split.py` (per-mirror scratch splits) | 511 + 4 000 | 335 | m2_k0/k2/v1hold byte-identical |
| 335 | `levers3.py` (delta/chain reshapes) | 14 | 335 | |
| 335 | `randset.py` random sets k=3..6 | 10 000 | 335 | |
| 335 | spill-set screen of all pairs | 127 727 | – | only `t_pin_r*` combos give the target set |
| 295 | `pinsplit.py` pinned fresh-local splits | 128 | 295 | 4 byte-identical |
| 295 | `pinsplit.py` carriers / pin-pairs | 48 / 224 | 340 / 370 | |
| 285 | `freshlocals.py` (43 value ranges × 9 forms) | 387 | 300 | |
| 285 | all-pairs re-run | 106 150 | 285 | killed after the next adoption (no hit seen) |
| 276 | `levers.py` singles / `freshlocals` | 460 / 387 | 276 / 276 | |
| 265 | `levers.py` singles | 458 | 265 | 114 neutral |
| 265 | `freshlocals.py` | 387 | 265 | 7+ neutral |
| 265 | `split2.py` (v1..v4, per-edge `edgeq`, 9 forms) | 333 | 265 | 10 neutral |
| 265 | `pinsplit.py` carriers / pin-pairs | 48 / 224 | 310 / 340 | |
| 265 | `levers3.py` | 14 | 265 | p7/p8/q7 neutral |
| 265 | neutral-pair stage | 4 795 | 265 | |
| 265 | random sets k=3 | 2 500 | 265 | |
| 265 | triples over the best 40 pairs of the pair stage | 7 683 | stopped mid-run | see note |
| 265 | random sets k=4..6 | not run | – | queued behind the triples stage |

Note on the un-finished triples stage: 41 levers (the union of the best 40 pairs)
give 7 683 triples; it ran ~12 minutes at `-j4` without producing a result file.
Its `filediff` errors also exposed a real artefact worth keeping: some lever
combinations make the compile reference `_080171F8`, i.e. they change which
runtime helper a division calls — those are the `s_*`/`sw_*` reversions and are
**not** semantics-preserving in the ROM sense; they were never candidates.

## Levers dropped by the baseline changes (asked for explicitly)

* `bigpairs.py`: **90 of its ~141 entries** no longer match (51 survive). The
  whole alias/`arg`/post-loop-spelling half is gone (the tail now uses `cc2`,
  `w = (s32)(*cc2).c;`, the `q0/q1` pair no longer has the `do/while` wrapper,
  …).
* `carriersub.py`: **2 of 22** (`w_carrier`, `glob_g`) — both tail spellings.
* `levers.py` on 265: 17 rejected (`arg0`, `arg7`, `s_h2e3_arg`, the
  `k1e0_to_*` block renames, `l_continue`, `tr_flag_plus`, …); the library
  tracks the text automatically, so this list is the "no longer applicable"
  answer.
* `levers2.py`: 3 rejected (`sw_dv_1e2`, `ad_t_decl`, `ad_h1_self`).

## Diagnostics this lane contributed (all read-only; canonical compiler untouched)

* The instrumented cc1 (`tools/agbcc/gcc/old_agbcc`) was verified to emit
  **byte-identical** assembly to `tools/agbcc/old_agbcc`
  (sha256 `41fbd1a6…a4aa`) on the base, so its trace is trustworthy.
* Forced spill sets on our stream: `{0,1,2,3,6}` = 335 (natural);
  `{0,1,2,3,4,6}` = 2002 / 10 / 1818; `{0,1,2,3,4,5,6}` = 2010 / 10 / 1896 —
  i.e. on the *then-current* stream, matching the ROM's set made things worse
  (consistent with Main's later uid-1439 analysis that the 5th entry, not
  membership, is the cause).
* Spill-set screens: 14 of ~500 singles put r4 in `used_spill_regs`
  (`t_pin_r0..r3` give exactly `{0,1,2,3,4,6}`, score 2002/9);
  127 727 screened pairs produced hits only for those same `t_pin_*` combos.
* `s_loopend_self` (removing the loop-end `a1->unk175 = a1->unk175;`) costs
  2 hunks; both self-stores are load-bearing. `m_pre_self` = 375.
* `s_dz_d0` (dissolving the `d0 = self->unk08; dz = d0;` carrier) = 835;
  `p1/p3` (shortening the same value's life) = 345…375. The loop-entry delta
  block is at a local optimum.

## Files

* `/tmp/lanepair/best_cc2eqcc.c` — 2006 / 0 / 345 (this lane's discovery).
* Result JSONL per stage: `singles.jsonl`, `singles265.jsonl`,
  `pairs.jsonl`, `merged_pairs265.jsonl`, `triples.jsonl`, `rand265.jsonl`,
  `split.jsonl`, `split2_265.jsonl`, `freshlocals265.jsonl`,
  `pinsplit_pin.jsonl`, `carrier`/`pair`, `screen.jsonl`,
  `screen_pairs.jsonl`, `allpairs.jsonl`; harness copies in `tools/`.

## Caveats / semantics

* Every edit reported as a candidate is semantics-preserving (pointer
  coalescing, alias respelling of `pa[k]`→`gUnk_0202CCB0[k]`, `register`
  qualifiers, `asm("rN")` pins, fresh locals that carry an identical value,
  renames, commutative operand swaps, adjacent independent statement swaps,
  self-stores of an identical value).
* Diagnostic-only (semantics-changing) levers inside the sweep libraries, never
  reported as results: the guard carriers that write a **live** variable
  (`u`, `w`, `v2`, `v3`, `v4`, `v1hold`) and `k1e0_to_v1hold`/`k2e0_to_v1hold`.
* `constcarry.py` rewrites the literal `6` inside identifiers, mangling
  `sub_0800D64C`; those variants fail to link and are errors, not evidence.
* The final triples stage on 265 and the k=4..6 random sets did not finish; I
  stopped them (12+ minutes without output) rather than leave them running. Every
  stage that *did* finish found nothing below the then-current baseline.
* Two families produced linker-time changes of the called helper
  (`_080171F8`): the `s_*`/`sw_*` reversions of the division operands. They are
  diagnostics, not candidates.
