# LaneConst — `sub_0800D684` constant-scratch-register lane (final report)

Scope: the "materialised constant / scratch register" family of `sub_0800D684`
plus the loop-increment spelling and the folded `a1->unk18F` constant, worked
against `/tmp/lanebase/base.c`. All work under `/tmp/LaneConst/`; nothing in the
repo tree was written, `tools/agbcc` was never modified (the instrumented cc1
was only *read/executed*).

## Result

**Best preserving file (mine): `/tmp/LaneConst/lane_best_braced_cp5.c` —
`{"size": 2006, "hunks": 0, "sdiff": 275}`**, verified with
`docs/learnings/drafts/d684-tools/filediff.py` (275 = 285 baseline + the braced
`cp5` edit below). Main verified the same edit (LaneARG fixed the brace bug —
see the withdrawal note); it is in the current 265 baseline.

Edit (semantics-preserving, one site), against the 285 baseline:

```c
    register struct Unk0802CC90 *cp5 asm("r3");   /* with the other declarations */
...
            if ((u32)(edgeq + 0xF00) <= 0x1E00) {
                cp5 = &gUnk_0202CC90;
                sub_0800D64C(a1, a2, cursor, 0, cp5, &flag, -u, (e << 16) / -u);
            }
```
It fixes `0x800d80e/0x800d810` (`ldr r0,[pc]; str r0,[sp,#0]` ->
`ldr r3,...; str r3,...`) = -10. `cp5 = cc;` scores identically; the pin to r3
is what matters (unpinned `cp5` = 816).

### WITHDRAWN: the 276 form was NOT semantics-preserving

`/tmp/LaneConst/WITHDRAWN_cp5_unbraced_276_semantics_changing.c` scored 276 but
is a **behavioural bug**, not a recolour: the guard's body was brace-less, and
the edit replaced the single `sub_0800D64C(...)` statement with two statements,
so only `cp5 = ...` stayed conditional and **the call became unconditional**.
The only signal in the metric was the +1 branch-offset line at `0x800d80c`
(`bhi.n 0x800d810` vs the ROM's `bhi.n 0x800d82e`) — LaneARG caught it by hand
from the disassembly; Main's brace fix gave 275 and removed that line.
Lesson recorded for my lane: **a cost-1 diff line is not benign — check the
disassembly of any candidate that introduces one.** My earlier "one layout
artefact, +1" note was exactly the bug.

Secondary preserving result: `/tmp/LaneConst/alt_e0a_free.c` (= `v/e0a_free.c`) —
2006 / 0 / **285** against the then-295 baseline. It splits the long-lived `e`
allocno inside mirror-1's edge-0 block only:

```c
s32 e0a;                                   /* fresh local */
if (u < 0 && v4 <= 0x1C00 && (e0a = v2 - 0x1C00) >= 0) {
    edgeq = w * e0a / u; edgeq += v1hold;
    if ((u32)(edgeq + 0xF00) <= 0x1E00)
        sub_0800D64C(a1, a2, cursor, 0, &gUnk_0202CC90, &flag, -u, (e0a << 16) / -u);
}
```
It is **not additive** with LanePostT's `b5`/`kb` win — both fix the same 10
sdiff points, so after that adoption `e0a` is exactly neutral (measured 285 on
the 285 baseline). `register s32 e0a asm("r4")` scores the same as the unpinned
form; the pin is unnecessary there.

## Corrections to the ticket's premises (evidence)

1. **The loop increment was never a diff site.** The increment compiles to
   `movs r0,#200; lsls r0,r0,#1; add sl,r0` at target/ours slots 566-568
   (`0x800db28`-`0x800db2c`) and is byte-identical in both streams. `cursor`
   lives in `sl`; there is no `+0x190` pool load anywhere.
2. **The two flagged sites are the mirror edge-0 guards, not a constant pool
   add.** `0x800d7ea/7ec` and `0x800d9a8/9aa` are `e = v2 - 0x1C00`. The pool
   word they load is `0x0800DA1C = 0xFFFFE400` (-0x1C00), not `0x190`. At
   mirror-1 the constant's scratch is r0 (target) vs r6 (ours) with destination
   r4 in both; at mirror-2 the scratch is r0 in both but the *destination* is r4
   (target) vs r6 (ours).
3. **`0x800d6cc/6ce` is the pre-loop `a1->unk18F` read**: `ldr r1,[pc,#828]`
   (pool `0x0800DA0C = 399`) then `adds r0,r3,r1`; ours uses r6 for the
   constant. Not the loop increment.

Decoded literal pool (read from `baserom.gba`, useful for other lanes):
`0x0800D9F8=&gUnk_02002090`, `D9FC=&gUnk_020020DC`, `DA00=&gUnk_020020AC`,
`DA04=0x175`, `DA08=&gUnk_0202A550`, `DA0C=0x18F`, `DA10=&gUnk_0202CD24`,
`DA14=&gUnk_0202CCB0`, `DA18=&gUnk_0202CD30`, `DA1C=-0x1C00`,
`DA20=&gUnk_0202CC90`, `DA24=-0xF00`, `DC90=&gUnk_0202CC90`, `DC94=-0xF00`,
`DC98=&gUnk_0801CD08`, `DC9C=&gUnk_083FDA2C`.

## Sweeps (all measured with `filediff.py`; "inert" = byte-identical to that baseline)

| # | script | variants | baseline | best | note |
|---|---|---|---|---|---|
| 1 | `sweep.py singles` | 88 | 335 / 276 | tie (55 inert at each) | 12 `unk18F`/`unk175` spellings, 20 edge-0 carrier dialects, 8 increment spellings, 18 comparison-operand swaps, 6 constant spellings |
| 2 | `sweep.py pairs` (full pool) | 1596 launched | 335 | see row 3 | one member (`e0m1_v4hi`) was mis-quoted and failed to compile, taking its pairs with it; the surviving top-30 list was not captured |
| 3 | `sweep.py pairs` (23 corrected levers) | 253 | 335 | 375 | nothing below the baseline |
| 4 | `sweep.py pairs` (21 non-inert levers) | 166 | 276 | 316 | nothing below the baseline |
| 5 | `pins.py` 18 locals x 11 regs | 198 | 335 | 335 (ties: `dx@r2`, `self@r1/r8/fp`, `base@r2`, `other@r8`) | no pin beats the baseline |
| 6 | `pins2.py` fresh-pinned constant carriers (`kc`) | 47 | 295 / 276 | tie | `kc_18f_r*` fold back to the constant (inert); the `(e = v2 + kc)` forms change the stream and regress |
| 7 | `e0b.py` fresh local for the edge-0 guard value | 20 | 295 / 285 / 276 | **285** (`e0a_free`, `e0a_r4`) | mirror-2's `e0b` form is catastrophic (26420+) in every pin |
| 8 | `m1e0.py` splits inside mirror-1 edge-0 (`eq0`/`vh0`/`all3`) | 24 | 285 | 335 | the block's residual is reload-scratch, not allocno, pressure |
| 9 | `m1e2.py` fresh local for mirror-1 edge-2's `e` | 22 | 285 / 276 | tie (`e2a_free` inert) | every pinned form >= 1111 |
| 10 | `addr.py` fresh pinned pointers for the call-setup addresses (`cp5`, `pf6`) | 31 | 285 / 276 | **276** (`cp5_r3`, `cp5_src_cc`) | `pf6` (`&flag`) in every pin is >= 866 |
| 11 | `m2sh.py` mirror-2 edge-0 / mirror-1 edge-2 `(e << 16)` shifts | 44 | 276 | 1115 | all >= 1115 |
| 12 | `comb.py` sets: `e0a` + library, and library pairs | 155 | 285 | 285 | no set beats the baseline |
| 13 | `cp5ext.py` `cp5_r3` + library | ~30 | 285 | 276 | nothing additive with `cp5_r3` |
| 14 | `trace.py` USEDSPILL probes (instrumented cc1) | ~230 | - | - | mechanism evidence below |
| 15 | re-run of rows 1/3-13 library against **265** | 85 singles + 146 pairs + 20 + 22 + 47 + 44 | 265 | tie at 265 (best pair 305) | nothing below 265 |
| 16 | `vsplit.py` mirror-2 half value splits (`v2b`, `v4b`, `v1holdb`, `wb`, `ub`, `v1b`) and per-edge `edgeq` splits | 100 | 265 | tie (`v1holdb_free`, coalesced); best non-tie 494 | refutes Main's "split the block-local values" hypothesis |
| 17 | `ev2.py` pairs: `e` pinned into r4 + `v2` split per half (pinned and free) | 24 | 265 | 1029 (`e_r4` alone); all pairs >= 1216 | moving `e` into r4 while moving `v2` out never pays |

All variants listed above are intended to be semantics-preserving, and the two
edits that reached Main carry their value unchanged at every use inside one
basic block (`e0a` used only inside the edge-0 block, and `e` is re-assigned
inside the condition at the top of every later block, so no stale read is
possible). **The one exception is the original `cp5` submission (276), which
silently made the call unconditional — withdrawn, see above**; its corrected
braced form (275) is what entered the baseline.

## Exhaustive r4-in-set census (probeall.py over every variant on disk)

`probeall.py` ran the instrumented cc1 over **all 2 111 variant files** in
`/tmp/LaneConst/v/` (75 s, 8 workers) and reported every one whose global
`used_spill_regs` contains r4 — i.e. every variant that changes the 5th spill
entry away from r6. Out of 2 111, exactly **23** qualify, and all 23 are the
same levers:

| variant(s) | set | (size, hunks, sdiff) at 265 |
|---|---|---|
| `inc_ptr_carrier` (dead `k2 = 0x190;` hoisted before the loop, increment reads k2) | {0,1,2,3,4,6,7} | 1994 / 21 / 3339 |
| `v4ge_sub+inc_ptr_carrier`, `v4ge_swap+inc_ptr_carrier` | {0,1,2,3,4,6,7} | 2018 / 31 / 5159 ; 1994 / 24 / 3714 |
| `v4ge_sub+inc_k2pre`, `v4ge_swap+inc_k2pre` | {0,1,2,3,4,6,7} | 2018 / 31 / 5347 ; 1998 / 26 / 3882 |
| `pin_count_r0..r3`, `pin_i_r0..r3`, `pin_cursor_r0..r3` | {0,1,2,3,4,5} | 2002-2030 / 54-69 / 28000-34000 |
| `pin_d1_r7` / `pin_d1_r8` / `pin_d1_sl` | {0,1,2,3,4} / {0,1,2,3,4,5} | 1978 / 95 / 14025 ; 2014 / 82 / 11049 ; 2014 / 82 / 11164 |
| `kcc_m2_r0/r1/r3` (constant carrier on mirror-2 edge-0) | {0,1,2,3,4,5} | 2046-2050 / 60 / 33790-34990 |

So no variant in this library reaches r4-in-set with anything close to a usable
score, and the one family that *does* keep size near target
(`inc_ptr_carrier`, size 1994) is 21 hunks off. This is the census Main asked
for; it confirms the set hypothesis is not reachable from the constant-scratch
or value-splitting lever families.

## USEDSPILL mechanism evidence (instrumented cc1, read-only)

* Baseline set is `{0,1,2,3,6}`. `r6` enters it at RTL uids 1439/1440/1442/
  1445/1446/1448; at uid 1439 the occupancy vector is
  `r0=24 r1=77 r2=30 r3=27 r4=24 r5=427 r6=0 r7=315` (bad: r11,r13,r14,r15,r16),
  so r6 is the only free register in `LO_REGS` — the whole recolour family is
  downstream of that single pick.
* The 24 refs occupying r4 there are *short-lived r4 temporaries* (pseudos 137 =
  `v2`, 277, 172, 468, 485 -> 8+8+3+3+2 = 24). Pinning `e` (pseudo 45) to r5/r6
  removes `e` from r4 but leaves the chain's r4 count at 24, so **pinning `e`
  does not restore r4 to the set** — the "make r4 free" route needs those
  temporaries gone, which is not source-reachable.
* Pinning `count` or `i` to r0-r3 *does* put r4 (and r5) in the set
  (`{0,1,2,3,4,5}`), but every such variant scores 30000+ (call-clobber
  save/restore storm).

## Artifacts (exact paths)

* `/tmp/LaneConst/lane_best_braced_cp5.c` — my preserving best (275).
* `/tmp/LaneConst/WITHDRAWN_cp5_unbraced_276_semantics_changing.c` — the buggy
  276 form (unconditional call), kept as evidence for the audit lesson.
* `/tmp/LaneConst/alt_e0a_free.c` — the 285 `e0a` source.
* `/tmp/LaneConst/base_285.c` — the 285 baseline snapshot the two were built on.
* `/tmp/LaneConst/v/*.c` — every scored variant, named by lever.
* `/tmp/LaneConst/{s1,s2,s3,s4,p2,p3,p4}.txt` — raw score tables.
* `/tmp/LaneConst/{sweep,pins,pins2,e0b,m1e0,m1e2,addr,m2sh,comb,cp5ext,vsplit,ev2,trace}.py`
  — reproducible drivers (all guarded by `if __name__ == "__main__":`, 8 workers).
* `/tmp/LaneConst/dis.txt` — full 959-slot aligned listing of the 335 baseline.

## Unverified / diagnostic-only

* Nothing here was run through `make check` / `corpus_check.sh` (main-agent
  scope).
* `sweep.py pairs` row 2: the launched 1596-pair run is only partially
  evidenced (a mis-quoted `e0m1_v4hi` member broke its own pairs and its error
  text filled the captured tail); rows 3-4 are the trustworthy pair results.
* The 198-variant pin sweep (row 5) was measured against the 335 baseline only;
  the 276 adoption re-shuffles allocation, so pins were not re-swept.
* `sweep.py` variants `e0m1_u/e0m2_u/e0m1_w/e0m2_w/e0m1_i/e0m2_i` are
  **diagnostic-only**: they overwrite a live value (`u`, `w`, `i`) inside the
  guard, so they are not semantics-preserving and were excluded from pair runs.
* `m1e0.py` can no longer rebuild its variants (its anchor text includes the
  pre-`cp5` call), so its 24 results stand only as history.
