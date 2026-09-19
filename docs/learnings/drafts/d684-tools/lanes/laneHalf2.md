# LANE Half2 report — second loop mirror (4 edge blocks, ~indices 330-570)

Metric: filediff sdiff (100/shape, 5/register, 1/imm), d684tool hunks.
Starting baseline: 2010 / 6 hunks / sdiff 1059.

## Variants that changed the score

| variant (base -> edit) | size | hunks | sdiff |
|---|---|---|---|
| baseline v0 | 2010 | 6 | 1059 |
| edge-0 guard: `(d1 = (e = v2 - 0x1C00))` -> `(e = v2 - 0x1C00)` | 2010 | 7 | 1287 |
| edge-2: braces+`fraction = e << 16;`+`fraction / w` -> `(e << 16) / w` inline | 2014 | 6 | 1110 |
| **both of the above together** | 2010 | **4** | **959**  ← adopted |
| edge-3: `k2 = edgeq + v2;` -> `d1 = edgeq + v2;` (bound reads d1) alone | 2010 | 6 | 1151 |
| edge-3 call: `cc` -> `&gUnk_0202CC90` alone | 2010 | 4 | 959 (inert) |
| **those two together** | 2010 | 4 | **949**  ← adopted |
| edge-1 guard: `(d1 = (e = -0x1C00 - v2))` -> `(e = -0x1C00 - v2)` alone | 2010 | 4 | 949 (inert) |
| edge-2: `k2 = edgeq + v2;` -> `k0 = edgeq + v2;` alone | 2010 | 4 | 949 (inert) |
| **all four 949-base edits together** | 2010 | 4 | **909**  ← best |
| edge-0 guard carrier -> `k0`/`k1` | 2006 | 8-9 | 1639 / 1679 |
| edge-0 guard carrier -> `d0` | 2010 | 7 | 1307 |
| `w = v3 - v1hold; u = v4 - v2;` order swapped | 2010 | 8 | 1259 |
| preamble `d0=pb[4]; d1=pb[5];` interleaved with the `- pa[..]` | 2014 | 11 | 1691 |
| edge-1 accumulator `edgeq += v1` -> `edgeq += v1hold` | 2022 | 19 | 3173 |
| cc -> `&gUnk_0202CC90` on calls 0/1/2 | 2010-2018 | 7-11 | 1267-1681 |

Inert (score unchanged): all remaining edge-1 carrier choices (k0..k3, d0, edgeq,
v1hold, lim3800, fraction, drop), `>= 0` -> `> -1`, `edgeq += x` -> `x + edgeq`,
bound-operand order swap, `k2`/`d1` bound splits, `(e << 16)` -> `(e * 0x10000)`,
`-u`/`-w` -> `(0 - u)`, post-loop `ccd`/`(*cc).g`/`hit2->unk7C`/`unk88`/do-while
dials (~1500 variants scored in total: singles + random pairs/triples/quads).

## Best file
`/tmp/laneHalf2/BEST2.c`  (2010 bytes, **4 hunks, sdiff 909**, i.e. baseline 949 - 40)
Four value-preserving edits, all in the second mirror:
1. edge-1 guard drops its dead `d1 =` carrier (matches the FIRST half's shape).
2. edge-2 bound carrier `k2` -> `k0`.
3. edge-3 bound carrier `k2` -> `d1`.
4. edge-3 call passes `&gUnk_0202CC90` (as the FIRST half's calls do) instead of `cc`.

## What I learned
Every remaining difference in this mirror is an allocation coupling, and no dial
in the region is monotone: edge-0's carrier change and the edge-2 inline are each
a regression alone but together are -100 sdiff and -2 hunks (they remove the
505/511 schedule hunk pair); the edge-3 carrier rename and its `&gUnk_0202CC90`
call each do nothing alone but together are -10; and edge-1/edge-2 carrier
re-spellings that are inert on their own unlock a further -40 only in the 949
context. Conversely `cc3 + D_split1` scored 1279 when applied without the other
pair, so the search had to be run on whole combinations, never single edits.
Residual diffs in the region are all register colours plus the `(e << 16)` and
bound-constant recolours (`movs rX,#0xE0/0xF0`), i.e. the same spill-set/allocno
plateau described in LANES.md; I found no source shape that moves them.
