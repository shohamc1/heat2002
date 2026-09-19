# LaneCross3 — cross-region lever-set search from (sdiff 627, hunks 2, size 2010)

Baseline: `src/sub_0800D684.c` snapshotted to /tmp/lanecross3/baseline.c (verified 2010/2/627).
169 levers over ~45 sites (post-loop cc spellings x18, `((struct Ent*)u)`->`u0` x17, pre-loop
carriers x9, first/second mirror bound+shift+guard carriers x40, 8 call-arg mixes, pa/pb
spellings x7, post-loop misc x20, unk140/144/148 orders x12, statement-order swaps x15,
`v1hold == v1` equivalences x4, cpa/hit2 alias rewrites).
Score cache: /tmp/lanecross3/cache.json (18 673 compiled variants), log /tmp/lanecross3/log.jsonl.

| batch | variants scored | best (hunks, sdiff, size) |
|---|---|---|
| singles | 169 | (2, 627, 2010) — nothing improves alone (123 change the object) |
| pairs, all 169 (exhaustive, 14 196) | 14 196 | **(2, 617, 2010) `ss4+m2e3_d1`** |
| greedy: winning pair + each remaining lever (167) | 167 | (2, 617, 2010) — every 3-set ties |
| quads: winning pair + 2 of the 44 tie-3 levers (946) | 946 | (2, 617, 2010) — no improvement |
| randomized 3-6 sets, uniform over pool | 3 199 | (2, 627, 2010) — no improvement |

**Best file: `/tmp/lanecross3/best.c` — (hunks, sdiff, size) = (2, 617, 2010)**, verified twice
(`filediff.py`: 617; `d684tool.py check`: 2 hunks = the two post-loop cc remat inserts, t_extra 0,
o_extra 2). Net −10 sdiff vs baseline; the same 2 structural hunks remain, size unchanged.
Both edits are hand-applyable to the repo draft:

1. bp 815 (first mirror, edge-3 block, right after the `sub_0800D64C(...,3, cc, ...)` call):
   `gUnk_083FDA2C[(*cc).d].f1 = gUnk_083FDA2C[(*cc).d].f1;`
   -> `d0 = gUnk_083FDA2C[(*cc).d].f1;` newline `gUnk_083FDA2C[(*cc).d].f1 = d0;`
2. bp 852-853 (second mirror, edge-3):
   `edgeq = edgeq + v2;` -> `d1 = edgeq + v2;` (the following `if ((u32)(edgeq + 0x1C00) ...)`
   becomes `if ((u32)(d1 + 0x1C00) <= 0x3800)`).

## Equivalence audit (both edits accepted)
* (1) `ss4`: the original is a genuine self-store (read field, write same value back). The
  rewrite routes the value through `d0`; the store target `gUnk_083FDA2C[(*cc).d].f1` is
  re-evaluated but `cc` is assigned once (bp 739) and never modified, no call or store to
  `gUnk_0202CC90.d` sits between the read and the write, so both evaluations denote the same
  lvalue. No aliasing: `d0` is unconditionally rewritten at bp 817 (`d0 = pb[4];`) before any
  read on every path, and again at bp 873/878 in the post-loop — the write is dead on all
  paths, so no stale-value read is possible.
* (2) `m2e3_d1`: pure carrier swap; the dead-store audit is `d1` — its next read is always
  preceded by an unconditional write (bp 818 `d1 = pb[5];` on the next iteration, or bp 868
  `d1 = (s32)(*cc).c;` after the loop). `edgeq` keeps the same value it had; nothing reads it
  after this point in the edge-3 block. No variable written by one edit is read by the other
  (edit 1's carrier `d0` is never read by edit 2, and vice versa).
* No other edit was accepted, so no other audit is owed.

## Learning
The two remaining hunks are structurally unreachable from source spelling: they are one
*reload rematerialisation* of `&gUnk_0202CC90` in the post-loop top whose register choice
(ours r6 — a member of our spill set {r0,r1,r2,r3,r6}, clobbered by the `ldrsh r6` two
instructions later — versus the ROM's r4, never clobbered in that block) is decided inside
reload, downstream of anything the C shape can express; the exhaustive 169-lever pair sweep,
the tie-anchored quad sweep, and 3 199 random 3-6 sets all bottom out at exactly this pair of
inserts (o_extra stays 2 in every single one). What *is* still steerable is the register
recolouring around them: the whole accepted-edit history is dead-store carriers, and the win
here is one more of the same family — routing a genuinely dead value through `d0`/`d1` at the
two edge-3 sites moved five recolours (worth 10 sdiff) into agreement without touching the
hunks, and it only pays as a *pair* (each edit alone is neutral at 627). No variant in this
pass moved sdiff below 617 or hunks below 2.