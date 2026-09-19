# Lane CrossSet2 — cross-region lever-set search, sub_0800D684
Baseline `src/sub_0800D684.c`: 2010 bytes, hunks 2, sdiff 667 (`filediff.py`;
hunks/size confirmed by `d684tool.py check`).
## Best — `/tmp/lanecrossset2/best.c`: 2010 / 2 / **627** (was 667)
| lever | change | alone |
|---|---|---|
| `M1B1_carrier_k3` | mirror-1 edge 1: `k2 = edgeq + v1; if ((u32)(k2 + 0xF00) <= 0x1E00)` -> `k3 = ...` | 677 |
| `po_k1_dot` | `k1 = (&gUnk_083FDA2C[ccd])->f0;` -> `k1 = gUnk_083FDA2C[ccd].f0;` | **1025, 4 hunks** |
| `po_glob_g_g` | `d0 = -(*cc).g;` -> `d0 = -gUnk_0202CC90.g;` | 707 |
Pairs score 667 / 717 / 985 — two are worse than baseline alone, one far worse,
yet the triple beats every pair by 40. Equivalent scorer: `M2B1_carrier_k3 +
po_k1_dot + po_glob_g_g` = 627; runners-up `M2B2_carrier_k1+M2E2copy_k1_early`
652, `po_glob_u_a+po_glob_w_c` 677.
Equivalence (hand-checked): renamed bound temp `k3` is never read before its next
write (mirror-2's `v3 = ((k3 = pa[3]) * d0 - ...)`) and `k2`'s next use is a
write too, so both the added and the removed write are dead; `(&a[i])->f` is
`a[i].f`; `cc = &gUnk_0202CC90` is assigned once pre-loop and never written, so
`(*cc).g` is `gUnk_0202CC90.g`.
## Rejected (semantics-changing, higher-scoring)
Every sweep kept offering a 602 set `E2num1_e2d1 + M2B2_carrier_k2 +
M2B3_carrier_d1`: `E2num1_e2d1` rewrites mirror-2 edge-2's numerator
`(e << 16)/w` to `(d1 << 16)/w`, but there `e = -0xF00 - v1` (its own guard)
while `d1` still holds `v2 - 0x1C00` (edge-0's carrier guard) or `pa[7]-pb[7]`
(matrix). The *valid* compound — the guard gains `d1 = (e = ...)` and the call
reads `d1`, i.e. mirror-1's shape — scores (4, 1298, 2014). 12 of the 249
first-pass levers were invalid the same way and were deleted before the final
runs.
## Searched
~297 levers / ~45 sites: pre-loop `pa` carriers and `pa`/`pb`/`cc` alias
permutations; `cc` vs `&gUnk_0202CC90` at all 8 calls; dead carriers for all 8
edge guards; bound carriers edges 1-3 both mirrors; numerator spellings,
recomputes, copy-carriers at all 8 calls; post-loop `(*cc)`-read carriers, a `cc`
local copy, direct-global reads, statement reorderings, divisor/`0x10`/`0x400`/
`-6` carriers. Scored: full pair sweeps (21 506+17 945+3 061 pairs), greedy from
8 seeds, ~38 000 randomized 2-6 sets; every single lever >= 667, no set moved
`hunks` below 2.
## Learning
The last two hunks are the two extra post-loop `ldr rN,=gUnk_0202CC90` remats: the
ROM keeps `cc` in r4 across the whole `if (flag != 0)` block so its later `(*cc)`
reads are plain `[r4,#9]`/`[r4,#12]`, while ours remat into r6 and that register is
immediately consumed by `w`. Nothing in ~50 000 scored sets changed which scratch
reload picks there; the levers that *do* move — the mirror bound temporaries
`k2`/`k0`/`k3`, the `k1` access spelling, `(*cc).g` going global-direct — buy the
40 sdiff but leave the remat shape untouched. That pins the gap to reload's
scratch set/rotation (`spill_regs`/`last_spill_reg`) at that one chain, which no
locally liveness-preserving C rewrite reached — and the 55-point win on offer was
a mis-compilation, so a large lever family must be equivalence-audited first.
