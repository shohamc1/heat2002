# LaneQty2 report — blocks 26/41/47 (bound checks), 42/48 (call setup), 75/87 (post-loop `sd`)

Baseline `src/sub_0800D684.c`: **(hunks, sdiff, size) = (2, 602, 2010)**.
Best found: **(2, 602, 2010)** — no strict improvement. Best file
`/tmp/laneqty2/best.c` (byte-identical module to the baseline, see below).

## The key datum: the quantity count DOES move, and it does not matter

I built an instrumented cc1 (see "Harness" below) that prints, per basic block,
`next_qty` and each quantity's member pseudos / birth / death. Baseline:

| block | what it is | quantities (n) | members (baseline) |
|---|---|---|---|
| 26 | mirror-1 edge-0 bound `(u32)(edgeq+0xF00)<=0x1E00` | 3 | 165(b2 d4), 170(b14 d18), 171(b16 d18) |
| 41 | mirror-1 edge-2 bound `(u32)(k2+0x1C00)<=0x3800` | 3 | 235(b2 d4), 240(b12 d14), 242(b18 d20) |
| 42 | mirror-1 edge-2 call setup | 3 | 244(b6 d14), 245(b10 d12), 250(b18 d20) |
| 47 | mirror-2 edge-1 bound `(u32)(edgeq+0xF00)<=0x1E00` | 3 | 306(b2 d4), 311(b14 d18), 312(b16 d18) |
| 48 | mirror-2 edge-1 call setup | 3 | 314(b6 d14), 315(b10 d12), 320(b18 d20) |
| 75 | post-loop 1st `sd = -unk2C >> 12` | **2** | 519(b2 d6), {521,520}(b4 d8) tied |
| 87 | post-loop 2nd `sd = -unk2C >> 12` | **2** | 614(b2 d6), {616,615}(b4 d8) tied |

(The task brief says 75/87 are 3-quantity; they are **2** — the two register
pair is tied by `combine_regs`, so the block never reaches the hand-rolled
`case 3:`. Only 26, 41, 42, 47, 48 are genuinely 3-quantity.)

Count-moving edits (exact edits, all score-neutral or worse):

| variant | exact old -> new | block n before -> after | size/hunks/sdiff |
|---|---|---|---|
| `b_m1e0_k2` | `if ((u32)(edgeq + 0xF00) <= 0x1E00)` (m1 edge-0) -> `k2 = edgeq + 0xF00;` + `if ((u32)k2 <= 0x1E00)` | 26: 3 -> **2** | 2010/2/**602** (asm **byte-identical**) |
| `b_m2e0_k2` | same text at m2 edge-0 -> `k2 = edgeq + 0xF00;` + `if ((u32)k2 <= 0x1E00)` | 47: 3 -> **2** | 2010/2/**602** (asm byte-identical) |
| `p_b_m1e0_k2__b_m2e0_k2` | both of the above | 26: 3->2 **and** 47: 3->2 | 2010/2/**602** (asm byte-identical) |
| `b_m1e0_d0` | `if ((u32)(edgeq + 0xF00) <= 0x1E00)` -> `d0 = edgeq + 0xF00;` + `if ((u32)d0 <= 0x1E00)` | 26: 3 -> **2** | 2010/2/612 |
| `b_m2e0_d0` | same at m2 edge-0 with `d0` | 47: 3 -> **2** | 2010/2/612 |
| `b_m2e0_dx` | same at m2 edge-0 with `dx` | 47: 3 -> **2** | 2010/2/652 |
| `b_m1e0_dz` | same at m1 edge-0 with `dz` | 26: 3 -> **2** | 2010/2/662 |
| `b_m1e3_lim3800` | `d1 = k2 + 0x1C00;` + `if ((u32)d1 <= 0x3800)` -> `lim3800 = k2 + 0x1C00;` + `if ((u32)lim3800 <= 0x3800)` | 41: 3 -> **4** (qsort path) | 2010/2/657 |
| `c_m1e3_k0` | `d1 = k2 + 0x1C00;` -> `k0 = k2 + 0x1C00;` (carrier only; the call still reads `d1`) | 41: 3 -> **1** | 1998/10/3837 |
| `b_m1e2_*`, `b_m1e1_*`, `b_m2e1_*`, `b_m2e3_*`, `b_m2e2_*` | same carrier forms at the other bound sites | unchanged (3) | 602 (k2/lim3800) .. 1040 |
| `s1_k2`/`s1_d0` | `sd = -((struct Ent *)u)->unk2C >> 12;` -> `k2/d0 = -((struct Ent *)u)->unk2C;` + `sd = k2/d0 >> 12;` | 75: 2 (unchanged) | 2010/2/612 |
| `s2_k2`/`s2_d0` | `sd = -hit2->unk2C >> 12;` -> carrier form | 87: 2 (unchanged) | 2010/2/612 |
| `q_m1e0_qa` … (fresh `s32 qa,qb,qc;` + carrier at every bound site) | `if ((u32)(edgeq + 0xF00) <= 0x1E00)` -> `qa = edgeq + 0xF00;` + `if ((u32)qa <= 0x1E00)` | unchanged (folds/tie back to 3) | 2010/2/602, **asm byte-identical** |

**Conclusion on the lever: it works mechanically (26/47 go 3->2, 41 goes 3->4
and 3->1) but no count change alters a single emitted instruction.** Every
neutral case is byte-identical; every case that changes code makes it worse.
So the register recolours at `0x800d800-0x800d806` (movs/lsls/adds of `0xF00`
into r0 vs the ROM's r2), at the call setups and at the post-loop `sd` are
**not** produced by `block_alloc`'s `case 3` ordering bug. They are set
downstream: the `(plus (reg) (const_int 3840))` materialisation register is a
reload/`final` scratch pick (`last_spill_reg` phase over `spill_regs[] =
{r0,r1,r2,r3,r6}`), and r0 is simply the first free one in our trajectory
whereas the ROM's trajectory is one allocation later. That reinforces the
existing "whole-function liveness/RTL trajectory" conclusion, now with direct
evidence that the local-alloc quantity list at those blocks is a *free*
variable — it can be 2, 3 or 4 with identical output.

## Coverage

* 250 single edits (`/tmp/laneqty2/V`): 8 bound sites x 17 carriers
  (insert the sum into `k0/k1/k2/k3/d0/d1/dx/dz/lim3800/w/u/e/v1hold/sd` or a
  fresh local), 5 definition-carrier renames, 2 `sd` sites x 17 carriers.
  250 files generated, 193 compiled (58 name a carrier not declared in that
  scope, e.g. `sd` inside the loop or the undeclared `qa`).  Best = 602
  (neutral, 21 of the 193); 41 sit at 612; the rest are worse.
* 1770 pairs over the 61 non-worsening singles (`/tmp/laneqty2/P`):
  min sdiff **602**, no `hunks` change; exactly the 185 pairs that score 602
  emit byte-identical assembly (verified by `diff` of the `.s`, not just the
  metric). Worst pair 28058.
* 30 fresh-local (`qa/qb/qc`) 4-quantity variants (`/tmp/laneqty2/Q`):
  all neutral or worse; the new local is cse-folded or tied away, count stays 3.
* Cumulative: **0 candidates at or below the baseline** in ~2000 scored
  variants (193 singles + 1770 pairs + 30 fresh-local); the baseline is
  confirmed as a local optimum in this lever class.

## Harness (reusable by the next pass)

* `/tmp/laneqty2/local-alloc-qty.patch` — adds, inside `block_alloc`, a stderr
  dump `QTYBB <b> n=<next_qty> [q<i>: <pseudos> b<birth> d<death>]…` plus
  `QTYPHYS <b> q<i>=<reg>…` after the allocation loop. Apply to a copy of
  `tools/agbcc`, `make -C gcc old -j4`, and you get exact quantity structure
  for any candidate. (Nothing in the repo was modified.)
* `/tmp/laneqty2/h.py VARDIR` — parallel (4-way) cpp+cc1(instrumented)+as+link
  +score of every `*.c` in a directory, prints size/hunks/sdiff with the
  baseline delta and the per-block quantity counts.
* `/tmp/laneqty2/gen.py`, `pairgen.py` — the variant generators used above.

## Learning (one paragraph)

The premise that the seven 3-quantity blocks hold the answer is arithmetically
partly wrong and, where right, not causal. Blocks 75/87 are 2-quantity — their
two registers are `combine_regs`-tied, so `case 3` never runs there. For 26/41/
47 the count is genuinely changeable from source without touching the
instruction stream (assigning the bound's sum to a variable that is live in
another block removes the temp from the block and drops `next_qty` to 2;
assigning it to `lim3800`/a fresh local pushes 41 to 4), and I did that — yet
the object code is byte-for-byte identical to the baseline, so the hand-rolled
`case 3` bug cannot be what recolours these sites. The recoloured operand at
0x800d800 is the register chosen for materialising the `add` operand constant
and would need the *reload* scratch phase to move, not local-alloc. Every one
of the 2050 variants bottomed out at the baseline; the lever class is spent.
