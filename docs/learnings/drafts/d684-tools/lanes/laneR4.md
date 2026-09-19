# LaneR4 — report: making r4 enter the reload scratch set / the tail `cc` remat

Time-boxed lane (50 min, ~85 min used after the parent's mid-lane re-steer).
Workdir `/tmp/laneR4/`. Nothing under `src/`, `asm/`, `ldscript.ld` was touched;
the repo `tools/agbcc` tree was **not** modified (it arrived with
`reload_set.patch` applied + built — LaneQty2 confirmed it uses its own copy);
I copied the binary to `/tmp/laneR4/cc1_RT` and used that.

## 1. Instrumented measurements (all with the stock `tools/agbcc/old_agbcc`)

`RT_ALL=1` on the 602 baseline: 188 insn chains, global spill set
`{r0,r1,r2,r3,r6}` (`NEWSPILL` counts r0:69 r1:27 r2:6 r3:4 r6:6; every need is
class 2 = `LO_REGS` (r0-r7) or class 4 = `BASE_REGS` (r0-r7+sp) — never class 1
`NONARG_LO_REGS`).

Chains with the ticket's target profile (r0–r3 occupied, r4 free): **exactly
two**, uids 1717 and 1959 (the post-loop `unkE8[unk3E]` divisions), both with an
empty need — this reproduces `NEXT.md`'s claim independently.

The post-loop `(*cc)` chains (`uid 1420…1450`, i.e. the materialisation at
`0x800db42` and the three follows):

```
ORDER uid=1442 pot: 12 6 9 10 0 4 3 2 1 8 7 5 11 13 14 15 16
  uses (pre-sort, index = regno): r0=24 r1=77 r2=30 r3=27 r4=24 r5=427 r6=0 r7=315 r8=200
  bad: 11 13 14 15 16
  live_before: 35 43 44 468 470 472 476
```

**r4 is occupied there (uses = 24)**, and the pick is `idx=4` of the global
`spill_regs[] = [r0,r1,r2,r3,r6]`, i.e. r6. Because the value the ROM serves
into r4 already exists in r4 in no shape of ours, this is *not* a "make r4
enter the union" problem at the tail: even with r4 in the set the tail cannot
take it.

**Direct check:** `RT_SET=012346` (forced set) → **size 2006 (target size!) but
12 hunks / sdiff 2058, and the two post-loop remats are still emitted**
(`ldr r2,[pc,#300]` at `0x800db64`, `ldr r0,[pc,#256]` at `0x800db90`); the two
instructions that disappear are unrelated (`0x800d7ba`, `0x800d9f4`). So the
premise "r4 ∈ `used_spill_regs` collapses the two hunks" is false for this
draft — `allocate_reload_reg` rejects index 4 because r4 is in use at that insn.

The pre-carrier draft (`/tmp/mylane_v0/natural_base.c`) is the counterpart: 191
chains, set `{r0,r1,r2,r3,r4,r6}`, r4 enters at **uid 362 / 827** — the mirror-1
/ mirror-2 `(k1 = p[1]) * d0` multiplies — class 2 need, profile
`r0=48 r1=44 r2=60 r3=72 r4=0 r5=0 r6=306`, `pot: 12 4 5 7 8 9 1 0 2 3 10 6` →
r4 is the first `LO_REGS` candidate. That is exactly the profile the ticket
asks for, and it is reproduced inside our draft's neighbourhood by a single
carrier (candidate 3 below).

## 2. Candidates (profile = uses r0..r4 at the chain named; stock cc1)

| # | candidate (file) | size | hunks | sdiff | chain | r0..r4 uses before → after |
|---|---|---|---|---|---|---|
| B | `src/sub_0800D684.c` (== `/tmp/laneR4/base.c`) | 2010 | 2 | 602 | 1441 | 24,77,30,27,**24** (r4 busy) |
| 1 | compiler `RT_SET=012346` (diagnostic) | **2006** | 12 | 2058 | 1441 | unchanged 24,77,30,27,24 |
| 2 | drop the `ccd = (*cc).d;` carrier (`hyb/h14.c`) | 2014 | 17 | 2787 | 1345 | 24,33,0,135,**0** ⇒ `NEWSPILL reg=2` then **`reg=4`** |
| 3 | `k3 = 4` → `dz = 4` (`hyb/h19.c`) | 2022 | 26 | 4542 | 395 (mirror-1 mult) | 48,44,60,72,**0** ⇒ `NEWSPILL` **`reg=4`** |
| 4 | pre-carrier draft (`/tmp/mylane_v0/natural_base.c`) | 2010 | 26 | ~3800 | 362 / 827 | 48,44,60,72,**0** ⇒ `NEWSPILL` **`reg=4`** |
| 5 | **`/tmp/laneR4/best.c`** — tail-only pointer pinned to r4 (see §3) | 2010 | 2 | **585** | 1442 | r4=24 (now the *home* of `cc2`) |

Nothing reaches `hunks == 0` or `size == 2006 && hunks <= 2`. Candidate 5 beats
the sdiff baseline (**585 < 602**) at the same size and hunk count.

Hunk-count is otherwise sticky. Reverting each of the 21 natural↔current source
hunks **one at a time on the baseline** keeps 2 hunks at indices
1,2,5,6,7,9,13,15,16,18,20 (sdiff 602–1102) and gives 4–26 hunks elsewhere; the
only two that put r4 into the set are #2 (h14, `NEWSPILL reg=4` at uid 1345) and
#19 (h19, `NEWSPILL reg=4` at uid 395, the mirror-1 multiply). Repeating the
sweep **on the winner** keeps 2 hunks at indices 5,6,16 (all 585, neutral),
21 → 595, 2 → 600, 19 → 610, 14 → 615, 9 → 625, 7 → 640; the do-while revert
(index 18 there) is the only route to `size 2006` and costs 4 hunks / 749–774.

## 3. The one lever that works: the tail pointer's *home* register

Following the parent's `cc2` lead (`/tmp/cc2`, best unpinned `2002/9/1766`), the
unpinned tail pointer lands in **r3** (`ldr r3,[pc,#332]` at `0x800db40`), not
r4 — `find_free_reg` scans r0..r7 and r0–r2 are busy while r3 is free over the
pointer's live range. A 155-cell sweep (5 pins × 31 read-subset masks) found:

```
    register struct Unk0802CC90 *cc2 asm("r4");
    cc2 = &gUnk_0202CC90;            /* first statement of the post-loop block */
    ...
    d1 = (s32)(*cc2).c;              /* instead of (*cc).c  */
    ...
    d0 = -(*cc2).g;                  /* instead of -gUnk_0202CC90.g */
```
→ `/tmp/laneR4/best.c` = **2010 / 2 hunks / sdiff 585** (stock cc1).
With the pin the address is materialised once into r4 at `0x800db42` and r4 is
still live at the late reads, so the `(*cc).d` remat at `0x800db64` disappears;
one late read collapses into an *inheritance copy* from r4. The two residual
extra instructions are `adds r6,r4,#0` (`0x800db44`) and `adds r2,r4,#0`
(`0x800db66`), i.e. reload's scratch for the un-routed `(*cc).a` / `(*cc).d`
reads inherits from r4 instead of rematerialising the pool address. Neighbouring
masks (r4 pin: 3→597, 16→590, 17→595, 19→596, 21→595) confirm the axis is real;
r3/r5/r6/r7 pins are all worse; unpinned is 9 hunks.

Semantics: `cc2` is a new block-local alias of `&gUnk_0202CC90`, the two routed
reads are the same two field accesses from the same storage at the same points;
`asm("r4")` is a register hint only.

## 4. Best file

`/tmp/laneR4/best.c` — 2010 / 2 / **585**. (Baseline copy: `/tmp/laneR4/base.c`;
per-candidate sources under `/tmp/laneR4/{cand,hyb,cc2s,cc2p,comb,comb2}/`.)

## 5. Learning

The tail residue is not a spill-set question: at our post-loop `(*cc)` chain r4
is *occupied* (uses = 24), so `allocate_reload_reg` skips index 4 whatever
`used_spill_regs` says — forcing `{0,1,2,3,4,6}` changes the size to 2006 but
leaves both remats and rotates 12 other shapes. The ROM simply keeps the tail
pointer's *home* in r4: `register ... *cc2 asm("r4")` plus two routed reads
reproduces that at the source level (602 → 585, one remat gone), and the
remaining work is to make the allocator choose r4 *without* the pin — for an
unpinned tail pointer `find_free_reg` returns r3 because r0–r2 are busy and r3
is free across the pointer's live range, so a value that occupies r3 for the
whole of `[cc2 birth, last cc2 read]` (or a live range that crosses the
post-loop call, pushing the pseudo to global-alloc's callee-saved set) is the
shape to look for.