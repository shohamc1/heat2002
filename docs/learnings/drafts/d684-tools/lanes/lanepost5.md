# LanePost5 — post-loop `cc` remats, baseline (2010 / 2 hunks / 667)

**Best file: `/tmp/lanepost5/best.c`** — unchanged baseline, **2010 / 2 / 667**. No variant reached hunks < 2.
Tool deliverable: **`/tmp/lanepost5/agbcc/gcc/old_agbcc`** — instrumented cc1 (reload1.c patched with
`RT_SET`/`RT_ADDSET`/`RT_DELSET` env spill-set controls plus the SPILLSET/NEWSPILL/RT/ORDER traces), verified
byte-identical to the reference on the baseline. Spill-set search is now one env var.

## Instrumented facts (new)
- `USEDSPILL: 0 1 2 3 6` → `spill_regs=[0,1,2,3,6]`, `n_spills=5`.
- The four post-loop `(*cc)` reads are pseudo **50**, not 51 (51 is spilled but never reloaded here):
  `RT uid=1285 rnum=0 reg=6 idx=4 nspills=5 last=3 in=(reg/v:SI 50)` = the remat at 0x800db42;
  the +9 read is `RT uid=766/1334 in=(mem/s:QI (plus:SI (reg/v:SI 50)(const_int 9)))`; the +12 read follows.
  Only two of the three remats pass through `allocate_reload_reg`; the rest are inheritance failures after
  `ldrsh r6` at 0x800db56 kills the scratch.

## Decisive negative — the 2 hunks are not a spill-set artefact
Forced **all 511 non-empty subsets of {r0..r8}** into `used_spill_regs` at `finish_spills` (RT_SET), scored each:

| set | size | hunks | | set | size | hunks |
|---|---|---|---|---|---|---|
| `{0,1,2,3,6}` natural | 2010 | **2** | | `{0,1,2,3,5,6}` | 2010 | 13 |
| `{0,1,2,3,4,6}` | 2006 | 12 | | `{0,1,2,3,4,6,7}` | 2006 | 15 |
| `{0,1,2,3,6,7}` | 2006 | 12 | | `{0,1,2,3,4,5,6,7}` | 2010 | 16 |
| `{0,1,2,3,4,5,6}` | 2014 | 12 | | best of remaining 504 | ≥2010 | ≥17 |

Adding r4 fixes the **size** (2006) but rotates the in-loop picks (first break at slot 50, `ldr r6,[sp,#36]`):
with r4 in the set index 4 becomes r4 at *every* insn where `last_spill_reg==3`, but the ROM keeps r6 at the
in-loop index-4 sites, which happens only if r4 fails `reload_reg_free_p` there (r4 live as the `e` pseudo)
and is accepted at 0x800db42. So the ROM's set is `{0,1,2,3,4,6}` and r4 enters it via a chain whose *emitted*
reloads match ours — a `calculate_needs` over-allocation, not a visible reload. Not reachable by source edits.

## Source sweeps (all semantics-preserving; carrier aliasing hand-checked)
| family | variants | result |
|---|---|---|
| carriers for `(*cc).a`/`.c`/`.d`/`.g` over 23 dead locals (`u0`,`d1`,`dz`,`k3`,`q0`,`m1`,`v1hold`,`a2`,`lim3800`,…) | 92 | **all byte-identical, 2010/2/667 — inert** |
| zero-store carriers `unk140/144/148 = (x = 0)` (23 locals × u,w) | 23 | all inert, 2010/2/667 |
| `d0 *= 1000;` moved ×4, `ccd` moved, `hit2` moved, u/w store interleave, u-group reverse, w-before-u, sin-load swap, `k1`/`k0` swap, `f0`/`f1` arrow/dot, `[0x40+ang]`, `u`/`w` direct, extra pointer local | 15 | 4 tie 667 (`hit2_after_u0`, `f1_dot`, `sin_comm`, `ptr_u`); rest 1025–5621 (`interleave_uw` 2006/14/4820) |

## Learning
The two hunks are a `spill_regs` *membership* difference, but membership is not adjustable from either side:
r4 must be allocated by some chain, and every chain that would take it in our build emits the same reloads as
the ROM. Forcing the set is exhausted (511 sets, min 2 hunks), and no post-loop spelling/reorder/carrier edit
perturbs the reload sequence — 119 of 130 variants are literally byte-identical. The only remaining lever is to
make one chain *over-allocate* one more spill register where r4 is dead (change `calculate_needs`'s reload/group
count without adding an emitted reload); post-loop statement surgery cannot, because that whole region is one
chain whose need is already met by r0-r3/r6.
