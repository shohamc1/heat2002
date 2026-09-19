# LaneSpill — reload scratch set / USEDSPILL lane report (2026-09-19)

Baseline used for all final numbers: `/tmp/lanebase/base.c` == `src/sub_0800D684.c`
== **2006 / 0 hunks / 265 sdiff**, `USEDSPILL` = `0 1 2 3 6`.

## Acceptance (a) MET
Semantics-preserving single-token edits under `/tmp/LaneSpill/cand/` whose
`USEDSPILL` is the target's `0 1 2 3 4 6`:

| file | change (one token) | USEDSPILL | size/hunks/sdiff @265 |
|---|---|---|---|
| `cand/cc2_pin_r3.c` | `cc2 asm("r4")` -> `asm("r3")` | `0 1 2 3 4 6` | 2002 / 9 / **1730** |
| `cand/cc2_pin_r2.c` | -> `asm("r2")` | `0 1 2 3 4 6` | 2002 / 9 / 1793 |
| `cand/cc2_pin_r1.c` | -> `asm("r1")` | `0 1 2 3 4 6` | 2002 / 9 / 1888 |
| `cand/cc2_pin_r0.c` | -> `asm("r0")` | `0 1 2 3 4 6` | 2002 / 9 / 2008 |

Every value fed to every use is identical; only the hard register of the pinned
pointer changes. `SPILLSET` for the r3 row is `0->0 1->1 2->2 3->3 4->4 6->5`,
i.e. exactly the target's rotation (5th reload scratch is r4:
`RT uid=91 rnum=1 reg=4 idx=4 nspills=6`).

## Harness (reproducible)
```
python3 /tmp/LaneSpill/run.py FILE [--setonly] [--workdir DIR]
python3 /tmp/LaneSpill/sweep.py FAMILY [--jobs 8] [--score] [--base FILE]
python3 /tmp/LaneSpill/em.py                 # mirror-half `e` split family
```
One `cc -E` + one compile with the read-only instrumented
`tools/agbcc/gcc/old_agbcc`; `USEDSPILL` parsed from stderr; score computed with
`filediff.py`'s own code. Baseline check reproduces exactly
`{"spill":[0,1,2,3,6],"size":2006,"hunks":0,"sdiff":265}`.

## The rule (tools/agbcc/gcc/reload1.c, read-only)
`order_regs_for_reload` builds `potential_reload_regs` as
`[zero-use call-used r0-r3,r12] ++ [zero-use non-call-used r4-r11] ++
[used, ascending REG_N_REFS] ++ [bad]`; `allocate_reload_reg` takes the first
class-legal entry; `finish_spills` stores the union ascending by regno, and
reloads round-robin that array. So a hard reg joins `used_spill_regs` only at a
chain where it is **zero-use and not in the chain's live_before/live_after**,
and the array's 5th slot changes r6 -> r4 the moment r4 joins.

## Root cause of the missing r4
* The file's only `asm("r4")` is `register struct Unk0802CC90 *cc2 asm("r4");`
  (post-loop block). The hard-reg references emitted for a pinned variable land
  in `chain->live_before/live_after`, so at chain **uid 1323** the baseline shows
  `bad: 4 11 13 14 15 16` and the chain takes r3 (`CHAINSET uid=1323 n=1: 3`).
* With `cc2` moved to r0-r3 the same chain is `bad: 3 ...`, r4 is free, and the
  chain takes r4 (`CHAINSET uid=1323 n=1: 4`) — that single pick is what puts r4
  into the set.
* The other r6-picking chains (uid 1439,1440,1442,1445,1446,1448) are blocked by
  the REG_EQUIV pseudo of the tail's `0x140` constant (insn 1414 -> 1454,
  `(set (reg 472) (const_int 320))` in the `-dl` dump), which the allocator keeps
  in r4 across that whole region; source-level attempts to break or relocate that
  allocno (family `tail140`, 7 variants) all leave the set unchanged.
* Chain live sets can contain *hard* regs as well as pseudos; the RT trace prints
  only the pseudo half, which is why the r4 blocker at uid 1323 is invisible in
  the `live_before` line.

## All sets ever observed (90 candidates measured; 1 more failed to compile)
```
0 1 2 3 6      baseline; cc2 -> r6,r7,r8,r9,r10,r12; cc2 un-pinned / dead
0 1 2 3 4 6    cc2 -> r0 / r1 / r2 / r3                (4 files, acceptance (a))
0 1 2 3 5      cc2 -> r5; d0 -> r9/r10; d1 pinned r4/r9/r10 (cc2 untouched)
0 1 2 3 7      u -> r4/r9/r10; w -> r4/r9/r10 (pinned)
0 1 2 3 4 5 6  cc2 -> r3 together with d0 -> r4
0 1 2 3 4      never observed
```

## Sweeps (all vs the baseline current at the time; final column = best of family)
| family | n | lever | best result |
|---|---|---|---|
| `pine` | 11 | `register s32 e asm("rN")`, N != r4 | 2006 / 6 / 1210 (r2), set unchanged |
| `pine4` | 3 | `e asm("r4")`, `e r4 + edgeq r1`, `e r4 + v1hold r4` | 2010 / 6 / 1029 |
| `pinmisc` | 18 | pins of `edgeq,v1hold,u,w,d0,d1` to r4/r9/r10 | 2006 / 2 / 465 (`v1hold`->r9) |
| `cc2pin` | 14 (13 compiled + 1 deliberate deletion test that cc1 rejects) | move/remove the `cc2` pin | 2002 / 9 / 1730 (r3, set `0 1 2 3 4 6`) |
| `cc2b` | 6 | keep r4 but shorten/relocate cc2's use, r12 pin | set unchanged |
| `tail140` | 7 | split the tail `0x140` constant allocno (carriers, pointer forms) | 2006 / 0 / 265 (pointer-form rewrites are no-ops) |
| `ccsplit` | 3 | two fresh pinned pointer locals for cc2's two reads (r1/r2/r3) | 2014 / 4 / 969, set unchanged |
| `em` | 29 | split the mirror half's `e` uses into a fresh local (pinned r3/r4/r5/r9/r10) | 2006 / 0 / 325 (`em_all` decl last), no hunks but worse |
| `mirsplit` | 96 | rename every mirror-half use of one variable `X` to a fresh `Xb` (X in v1..v4, v1hold, w, u, edgeq, k0..k3, d0, d1, dx, dz; +/- pin to r1/r3/r4/r5/r9) | 6 variants neutral at 2006 / 0 / 265; nothing below |
Nothing in any family beat 265 (190 candidates total). Verification of the deliverable after the last
baseline move: each of the four `cc2_pin_rN` files differs from
`/tmp/lanebase/base.c` by exactly one token (`diff` shows a single line) and
`cc2_pin_r3` re-measured as `{"spill":[0,1,2,3,4,6],"size":2002,"hunks":9,"sdiff":1730}`.

## Important caveat on the premise (unverified but evidence-backed)
The remaining 265 diff is 47 register recolours (cost 5) + 4 double recolours
(cost 10); enumerating the sites where the target has r4 and ours differs gives
exactly 7, all in the **mirror half** (`0x800d880`, `882`, `886`, `8ae`, `990`,
`996`, `9ba`) and all of the forms `subs r4,r1,r0` / `cmp r4,#0` /
`adds r0,r4,#0` / `lsls r0,r4,#16` / `muls r0,r4`. In our compile the same
values are in r6 (`subs r6,r1,r0` ...) with **no stack traffic around them** —
those are the edge-guard value `e` computed, compared and used 3-4 times inside
one basic block, i.e. a *block-local value allocation* of `e`, not a reload
scratch. The target's cc pointer (idx 580/581/617) and its `0x140` constant
(idx 645-674) are in r4 in **both** compiles. So "the target's set contains r4"
is not established by these sites; they are equally consistent with the target
having the same set and simply allocating `e` to r4 in the mirror half where we
use r6. That would explain why every set-changing edit scores worse (the set
change is real but it is not what the ROM's colouring wants). Recommend the
remaining work be treated as an `e`-allocation problem in the mirror half.

## Mechanism note (local-alloc, readable in tools/agbcc/gcc/local-alloc.c)
`find_free_reg` returns the **lowest-numbered** hard reg that is inside the class,
not in `fixed_reg_set`/`call_used_reg_set` (the latter only when the quantity
does not cross a call) and not in `regs_live_at[]` over the quantity's
birth..death. `regs_live_at` already carries the hard regs of quantities
allocated earlier in the same EBB (`post_mark_life`). So a call-crossing
quantity is naturally *entitled* to r4 — it takes r4 unless an earlier quantity
in the same EBB already marked it live. Our mirror-half `e` quantity lands in r6,
which means r4 and r5 were marked live before it in that EBB; the target's landed
in r4. That is the shape of the remaining problem, and it is why pinning `e`,
splitting `e`, or moving the `cc2` pin does not move those seven sites: the site
value is not the same allocno that the pins act on.


## Direct test of "free r4 at uid 1439" (Main's latest hypothesis)
Refuted by the ROM's own disassembly, which our 265 baseline matches
instruction-for-instruction in that region:
```
idx 645 0x800db8e  movs r4, #160     (both)   <- 0x140 materialised into r4
idx 646 0x800db90  lsls r4, r4, #1   (both)
...
idx 659-668  hit2->unk0C/unk14 updates  (all identical in both compiles)
idx 669 0x800dbbe  add r4, r8        (both)   <- r4 still holds 0x140 here
idx 670            str r1, [r4, #0]  (both)
```
`-dl` shows why: pseudo 472 = `(const_int 320)` with `REG_EQUIV`, live insn
1414 -> 1454 (`REG_DEAD` at 1454, the `w->unk140 = 0` address), i.e. r4 is
*live* across the six chains (uid 1439,1440,1442,1445,1446,1448) in the ROM too.
So the ROM could not have picked r4 at uid 1439 either.

Broader check: the whole tail (0x800db08..0x800de2a, indices 578..957) has
**zero** register diffs, while 16 reloads in the function use `idx=4` (r6),
five of them in the tail (uid 1439,1440,1442,1446,1448). Under a six-element
target set `[r0,r1,r2,r3,r4,r6]`, index 4 is r4 and index 5 is r6, so a tail of
~50 reloads would necessarily show r4-vs-r6 differences; there are none. The
consistent model is that the ROM's set equals ours and that the visible
differences are *value* allocations in the loop (target r4/r1/r3 for `e`, ours
r6/r0/r3), not the scratch rotation.

## Unverified
* Whether the target's `USEDSPILL` really contains r4: our only evidence is the
  7 recolours above, which are ambiguous (see caveat). Not verifiable without
  the ROM's own compile.
* `count_pseudo`'s use values in the `USES` line are not `REG_N_REFS`-consistent
  with the `REGNUM` print at the end of reload (ratios 2-8 per register), so I
  used the `ORDER ... pot:` list, not the raw numbers, for all reasoning.
* The `e`-in-r6 local allocation was not moved to r4 by any pin tried
  (`pine`, `pine4`, `em`): pinning shifts the whole file, not one block.

## Files
`/tmp/LaneSpill/{run.py,sweep.py,em.py,REPORT.md}`,
candidates in `/tmp/LaneSpill/cand/*.c`,
raw family output in `/tmp/LaneSpill/res_*.txt` / `res_*.json`,
traces in `/tmp/LaneSpill/*.log` and `/tmp/LaneSpill/dumps2/`.
Nothing outside `/tmp/LaneSpill/` was written; `tools/agbcc` was only executed.
