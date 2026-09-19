# LaneHalf4 — second-mirror randomized set search (baseline 2010/4/889)

## Result: no improvement — best = baseline 2010 bytes / 4 hunks / 889 sdiff
Best file `/tmp/LaneHalf4/best.c` (byte-identical to `v0.c`); score-tied
alternative `/tmp/LaneHalf4/tie-pree.c` (pre-loop self-store moved after the call,
also 889). 15 007 variants scored; none with `(hunks, sdiff)` < (4, 889).

## Method
`pool.py` = 2660 atoms / 37 sites: guard dead-store carriers (8 sites × 10);
bound carriers, operand order, in-place accumulator and numerator spellings at all
8 edges; post-loop carriers for `>>12 >>14 %3 0x32 40000 ang+0x40 0x10 0x400 -6`
(u8 carriers filtered to round-tripping literals); pre-loop `pa` carriers; new
families `self` (loop-bottom no-op self-store placement), `cc` (post-loop `cc`
re-assignment / direct-global spellings), `th` (`d0 *= 1000` placement).
`rs.py` = random 2-6 atom sets + hill-climbing; `beam.py` = staged beam, one site
per stage, score-bucket shuffling so neutral ties stay diverse (~40 scores/s, -j4).

## Score-changing variants (all neutral or worse)
| variant | size | hunks | sdiff |
|---|---|---|---|
| *(baseline)* | 2010 | 4 | 889 |
| `pct3u:lim3800` alone | 2010 | 4 | 890 |
| `SG3:d0` alone | 2010 | 4 | 909 |
| `preD` alone | 2010 | 4 | 914 |
| best pair `FE2:acc_d0:k0chain`+`SG3:d0` | 2010 | 4 | 910 |
| `SE1:car_k0:expr_d0`+`dzu:v1hold` | 2010 | 6 | 1109 |
| `self` (drop loop-bottom self-store) | 2010 | 6 | 1151 |
| `cc` (post-loop `cc = &gUnk_0202CC90;`) | 2014 | 6 | 1290 |
| `SE0:car_k3:n`+`preA` | 2018 | 7 | 2004 |

## Negative results (retire these levers)
1. **Guard dead-store carriers are structurally dead**: all 80 atoms over the 8
   guard sites, plus full 8-stage beams composing one carrier per guard, never left
   2010/4/889 (678/1188 guard scores were exactly 889). agbcc -O2 eliminates these
   dead stores before allocation.
2. Exhaustive pair sweep of the 299 codegen-changing single atoms (351 pairs, ≤3
   labels per site) bottoms out at 910: no 2-edit set improves.
3. `self` / `cc` / `th` move codegen (up to 6 hunks) but only upwards.
4. Sizes 1986 and 1994 are reachable, but never together with sdiff < 889.

## Learning
The four residual hunks are unreachable by local or pairwise reshuffle of this
source: the levers split cleanly into inert families (guard dead stores, self-store
placement — eliminated before allocation) and active-but-worsening families (edge
bound carriers, numerators, post-loop literal carriers). 15k sampled variants,
including full 8-way guard compositions, never dip below 889, so 889 is a lock-step
equilibrium: every edit that removes one of our three extra instructions
(`adds r6,r4,#0` from `k1 = e; d1 = k1;`, the two post-loop `cc` remats) pays back
more shape cost elsewhere, and the missing ROM `adds r1,r7,#0` (pa kept in r7)
needs a callee-saved assignment no source pressure reproduced here. Progress likely
needs a genuinely different global spelling of `cc`/`pa` that changes their
rematerialisation class, not more carrier noise.
