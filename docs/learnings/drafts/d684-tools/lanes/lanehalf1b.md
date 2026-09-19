# LaneHalf1b — FIRST loop mirror (a1-first / cursor-third edge blocks), 2010/4/909
Baseline (repo src/sub_0800D684.c == /tmp/lanehalf2/BEST2.c): **2010 B, 4 hunks, sdiff 909**.
Region owned: lines 779-806 (edges 0-3, `sub_0800D64C(a1, a2, cursor, ...)`). ~36 000 variants scored
with my -j4 harness (`/tmp/lanehalf1b/{h,run,follow,spell,probe2}.py`, log `res_core.jsonl`).
**No variant beat 909/4. Best file: /tmp/lanehalf1b/BEST1b.c (== baseline, 2010/4/909).**
## Score-changing variants (exact text old -> new), all inside the first mirror
| # | edit (old -> new) | size | hunks | sdiff |
|---|---|---|---|---|
| 1 | edge-3 bound `k2 = edgeq + v2; d1 = k2 + 0x1C00; if ((u32)d1 <= 0x3800)` -> `d1 = edgeq + v2; if ((u32)(d1 + 0x1C00) <= 0x3800)` (= mirror-2 win) | 2010 | 4 | **909 neutral** |
| 2 | edge-1 bound `k2 = edgeq + v1; if ((u32)(k2 + 0xF00) <= 0x1E00)` -> `edgeq += v1; if ((u32)(edgeq + 0xF00) <= 0x1E00)` (= mirror-2 win) | 2010 | 4 | **909 neutral** |
| 3 | edge-2 shift: drop `k1 = e; d1 = k1;` + call `(d1 << 16) / w` -> `(e << 16) / w` (= mirror-2 win) | 2010 | 4 | 1010 (its hunk moves 264 -> 278) |
| 4 | 3 + edge-3 `k2 = edgeq + v2; if ((u32)(k2 + 0x1C00) <= 0x3800)` (k2_direct) | 2010 | 4 | 1000 |
| 5 | edge-0 arg `cursor, 0, &gUnk_0202CC90` -> `cc` | 2010 | 4 | 919 |
| 6 | edges 1/2/3 arg `cc` -> `&gUnk_0202CC90` (each alone) | 2018 | 10 | 1856 / 1826 / 1315 |
| 7 | edge-3 self-store `gUnk_083FDA2C[(*cc).d].f1 = ...;` deleted | 2010 | 4 | 924 |
| 8 | edge-1 bound carrier k0 / d0 / d1 / k3 / v1hold (each alone) | 2010 | 4/4/4/8/62 | 929 / 919 / 919 / 1403 / 29008 |
| 9 | edge-2 bound carrier k0 / d0 / d1 / k3; check inlined (no carrier) | 2010/2010/1998/2010/2010 | 8/4/8/8/4 | 1430 / 919 / 2639 / 1403 / 1050 |
| 10 | edge-3 bound carrier k0 / d0 / k3; check inlined | 2010 | 4/4/8/4 | 919 / 919 / 1238 / 1004 |
| 11 | edge-1 guard `u > 0` -> `0 < u` (mirror-2 spelling) | 2010 | 4 | 909 inert |
| 12 | shift carrier at edge 0/1/3 (`k1 = e;`+`(k1 << 16)/..`, `d1 = e;`+`(d1 << 16)/..`) | 2010 | 4-64 | 2193-51378 |
Cross product (2 edge-0 arg x 8 edge-1 x 42 edge-2 carrier x shift x 8 edge-3 x 2 self-store, then
x 8 call-arg mixes, x 54 spellings, x 12 dead-store carrier inserts): only **12 of 10752** shape
combos reach 909 (edge-1 `k2`|`edgeq += v1`; edge-2 carrier `k2` with `k1d1`/`d1e`/`d1dead` shift;
edge-3 `base`|`d1_win`); every other combination is >= 919. No combo reached hunks < 4; at size
2006 the best sdiff is 1238.

## Learning
The first mirror is a hard local optimum, unlike the second. Every lever that makes its text match
the target disassembly is either score-neutral (mirror-2's edge-1/edge-3 edits: 909/4 -- they do not
move allocation here) or actively harmful (mirror-2's edge-2 edit: 1000-1010). `d684tool show`
explains why: the target reaches edge-2 with no `e` carrier (`lsls r0, r4, #16`) yet still emits the
`w`-argument copy `mov r1, r8` exactly once, and our source can have one or the other but not both.
Keeping `k1 = e; d1 = k1;` costs the extra `adds r6, r4, #0` at 0x800d8a4 (the known hunk) but keeps
the `w` copy in r1 (recolour only); dropping it trades that hunk for an equal one at `mov r1, r8`
(insert 278), so hunks stays 4 either way and sdiff worsens. The call-argument mix is also inverted
vs the second mirror: this half wants `&gUnk_0202CC90` at edge 0, `cc` at edges 1-3 (+900 to swap).
So no (sdiff, hunks) progress is obtainable from this region alone; its six remaining recolours
(0x800d800/802/804, 0x800d812, 0x800d880, 0x800d8c0, 0x800d902/908) and the 0x800d8a4 hunk are
downstream of whole-function allocation; fix the pre-loop (hunk 52) and post-loop (two `cc` remats)
hunks first, then re-check this region.