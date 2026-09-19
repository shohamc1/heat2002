# LanePerm2 — decomp-permuter over sub_0800D684 (602 baseline)

## Result: nothing beats the baseline. No file to hand over.
Best produced by the permuter = **(2, 607, 2010)** vs baseline **(2, 602, 2010)**.
Baseline src/sub_0800D684.c re-scored here: `{"size": 2010, "hunks": 2, "sdiff": 602}`.

| run | dir | config | iterations | candidates <= base score | best filediff |
|---|---|---|---|---|---|
| A | nonmatchings/sub_0800D684 | default weights, no `--seed`, -j2, 34 min | >=24k (23.9k at 04:12) | 0 (no output-* at all) | — |
| W3 | /tmp/laneperm2/nm4 | **patched** should_output (accept score <= base+150), no `--seed`, -j2 | ~9 min | 0 at <=750 | (2,607,2010) `nm4/output-755-1/source.c` |
| B*, C, W/W2 | nm2, nm3 | biased weights / region pragmas / `--seed` | — | 0 | wedged (see below) |
| harvest0_orig | harvest0_orig | 17 output-* left by earlier sessions | — | 0 | (4, 949, 2010) |

Best candidate file: `/tmp/laneperm2/nm4/output-755-1/source.c` — (2, 607, 2010) of 64 candidates
in `nm4/output-*` (35 are 2-hunk, bottoming at 607/612; rest 3-23 hunks). None drops below 2 hunks.
Its instruction delta vs the baseline is two *added* `ldr rX,[pc,#…]` pool loads (0x800db64,
0x800db90) plus ~5 recolours in the loop — the same failure mode as our two extra remats.

## What the numbers say
- Permuter base score = 750 in the same currency as filediff (regalloc 5/field, ins/del 100,
  reorder 60). 750 ~ 602: 200 = the two extra remat instructions, 335 = 67 recolours, rest imms.
- A ran the whole function (>=24k iterations, error rate ~3%) with **zero** candidates <=750 with a
  distinct asm hash; the smallest non-base score ever seen in the log is **760** (one extra
  regalloc field). The draft is a strict local optimum for every single-pass mutation.
- Widening the output threshold by +150 (one-line patch in a /tmp copy) proved it from the other
  side: the near-miss pool (755-880) is worse for filediff too (607, 612, 627, 642, 672, ...).

## Two permuter traps for the next session (verified)
1. `--seed a,b,c` **wedges the run**: `seed_iterator` becomes `itertools.repeat(force_seed)`, so a
   seed whose mutation fails to compile reproduces the same failing candidate every iteration ->
   100% compile errors from ~iteration 50 (every seeded run). Run unseeded (error rate ~3%).
2. `#pragma _permuter randomizer start/end` regions do **not** confine mutations. Passes can move
   statements out of the region: seed 23 moved `hit2 = (struct Ent *)w;` into the loop body while
   its declaration stayed behind -> `hit2 undeclared`, 100% failures. Unusable on this function.

## Semantics
Nothing was adopted, so there is no carrier-aliasing question to hand-check. All candidates are
permuter output (structurally semantics-preserving by construction; the ones above only differ in
register/remat choices). Deliverable is a negative result: the permuter is exhausted at the
current base; the two remaining hunks need a lever outside its mutation space.
