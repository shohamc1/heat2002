# LANE Half3 — second mirror, search from the 2010/4/909 baseline

Metric: `filediff.py` sdiff (100/shape, 5/reg, 1/imm) + `d684tool.py check` hunks; only strictly
lower `(sdiff, hunks)` at size <= 2010 counts. ~11.6k variants scored at -j4.

| variant (base -> edit) | size | hunks | sdiff |
|---|---|---|---|
| baseline v0 (copy of `src/sub_0800D684.c`) | 2010 | 4 | 909 |
| HA0 edge-0 guard `(e = v2 - 0x1C00)` -> `(d0 = (e = v2 - 0x1C00))` alone | 2010 | 4 | 929 |
| HB0 edge-0 guard `(e = v2 - 0x1C00)` -> `(d1 = (e = v2 - 0x1C00))` alone | 2010 | 4 | 1209 |
| **both of the above together (adopted)** | 2010 | 4 | **889** |
| 224 curated singles (all lane sites) | 2010 | 4+ | 909 best |
| 182 thirds / 2461 random quads / 2445 mirrored pairs on the 889 base | 2010 | 4 | 889 best |
| 343 extended carriers (`self`/`other`/`base`) on edge-0 | 2010 | 4 | 889 best |
| 3125 in-block composites (guard x bound carrier, edges 2/3) | 2010 | 4 | 889 best |
| post-loop `cc` reorder / carrier (6 variants) | 2010 | 4 | 889-949 |

**Best file: `/tmp/laneHalf3/BEST.c` — 2010 bytes, 4 hunks, sdiff 889** (re-verified with `filediff.py`
and `d684tool.py check` in a fresh workdir). Only two lines differ from the baseline:

1. 779: `if (u < 0 && v4 <= 0x1C00 && (e = v2 - 0x1C00) >= 0) {` ->
   `if (u < 0 && v4 <= 0x1C00 && (d0 = (e = v2 - 0x1C00)) >= 0) {`
   `d0` is dead there (last use `v4 = (k0*d0 + k1*d1) >> 8`; rewritten at edge-2 and by the next
   half's preamble `d0 = pb[4]`) => pure dead store that only steers register allocation.
2. 822: same guard in the second mirror -> `(d1 = (e = v2 - 0x1C00))`.
   Same argument: `d1`'s next touch is edge-3's `d1 = edgeq + v2` and the post-loop block reassigns
   `d0`/`d1` before any read => pure dead store.

Learning: the dead-store-carrier lever still applies to the second mirror but **only as a set** — `d0`
in the first half alone costs +20 (929), `d1` in the second half alone costs +300 (1209), the pair is
-20 (889). The carriers must be *different variables in the two mirrors* (`d0`/`d1`): every other
pairing over `k0..k3, d0, d1, edgeq, dz, dx, lim3800, ccd, self, other, base` (2800 combos, symmetric
and asymmetric) is >= 889, and no third edit (~5.8k combos: thirds, quads, exhaustive mirrored pairs on
edges 1-3, extended carriers, in-block guard x bound composites) goes below 889. The residual is pure
allocator choice one mirrored dead store cannot reach: the edge-0 guard's `-0x1C00` pool literal
rematerialises into `r6` (ours) where the ROM uses `r0`, and the `0xF00`/`0xE0<<5` bound constants land
in `r0`/`r3` (ours) where the ROM uses `r2` — our loop body spills one pseudo too many exactly around
the three instructions we carry extra (`adds r6,r4,#0` from `k1 = e; d1 = k1;`, and the two extra
post-loop `cc` reloads where the ROM keeps `cc` in `r4` for all four uses). Deleting either extra does
not move the allocator (drop `k1 = e; d1 = k1;` = 1010; `ccd`-early / `cc`-carrier reorders = 889-949),
so the last 85 recolours + 3 hunks need a whole-function allocation flip, not another local carrier.

Artifacts: `/tmp/laneHalf3/run1..run10.py`, `res_*.json`, best `BEST.c` (= `base889.c`).
