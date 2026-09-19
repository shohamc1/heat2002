# LaneE4 — second loop mirror, edge value in r4 (2026-09-19)

**No semantics-preserving improvement over the baseline.** Best sound file is the
baseline itself: `/tmp/laneE4/best.c` (= copy of `src/sub_0800D684.c`),
**(hunks, sdiff, size) = (2, 617, 2010)**.

## Scores (all filediff.py, workdir-isolated, never wrote to the repo)

| candidate | edit set | sdiff | hunks | size | sound? |
|---|---|---|---|---|---|
| baseline | — | 617 | 2 | 2010 | yes |
| A1arg2 | first mirror edge-1 numerator `(e << 16) / u` → `(k3 << 16) / u` | **612** | 2 | 2010 | **NO — semantics-changing** |
| A1arg2 + B0all6 / B1bound3 / B1guard3 / A1guard1 / A2bound1 / A2bound3 | as above plus one neutral edit | 612 | 2 | 2010 | **NO** |
| B0all6 | `(d1 = (e = v2 - 0x1C00)); edgeq = w * d1 / u; … (d1 << 16) / -u` | 617 | 2 | 2010 | yes (byte-identical) |
| B0all1 (drop carrier) | `(e = v2 - 0x1C00)` | 657 | 2 | 2010 | yes |
| B0all2/7 (`d0` carrier, e or d0 body) | `(d0 = (e = v2 - 0x1C00))` | 677 | 2 | 2010 | yes |
| B3carry3 | edge-3 bound `d1 = edgeq + v2` → `d0 = …` (guard paired) | 637 | 2 | 2010 | yes |
| B1guard1 (2nd mirror edge-1 d0 carrier) | `(d0 = (e = -0x1C00 - v2))` | 637 | 2 | 2010 | yes |
| B2guard2 (2nd mirror edge-2 d0 carrier) | `(d0 = (e = -0xF00 - v1))` | 637 | 2 | 2010 | yes |
| everything else tried | carriers `k0 k1 k2 k3 v1 v3 v4 u edgeq dx dz lim3800 self other` | 1270–29651 | 4–68 | 2006–2050 | mixed |

`/tmp/laneE4/log.jsonl`, `log2.jsonl`, `logp.jsonl` hold every scored config
(~4 500 scores); `/tmp/laneE4/gen.py` / `gen2.py` hold the lever definitions
(gen2's option list was hand-audited for semantic equivalence; the earlier
gen.py sweep includes intentionally-unsound cross-slot spellings).

## Why 612 is not adoptable
`(k3 << 16) / u` in the **first** mirror's edge-1 call passes `k3 = edgeq + v1`
where the target-source expression passes `e = -0x1C00 - v2`; these are different
values, so the edit changes the called function's argument. It moves the metric
by -5 only because it happens to recolour `800d864/866` (fix) against
`800d860/862/86a` (break). No equivalence argument exists — reject it.

## Learning (one paragraph)
The second-mirror edge-0 block is a *pick rotation*, not a carrier choice: the
target has **both** the constant reload in r0 (`ldr r0,[pc] @ 0x800da1c; adds
r4,r4,r0`) **and** `e` living in r4 (v2's register, so v2 dies at `adds r4,r4,r0`),
while our compile can only get one of the two — with the `(d1 = (e = …))` carrier
the whole reload-scratch sequence of the block matches the target (r0, r2, r3,
r0, …) but the guard value lands in r6; dropping the carrier puts the value in r4
but rotates the scratch picks one slot (const→r6, then r2→r0, r3→r1, …), which is
worth exactly the 40-point swing 617↔657 in both directions. The block after the
guard (`800d9be-9d2`, `800da42-52`) is a downstream echo of that first pick, which
is why every single- and pair-level carrier swap in this region scores ≥617:
no semantics-preserving source spelling I tried (~4 500 configs over carrier
variables, bound carriers, call-argument mixes `cc`/`&gUnk_0202CC90`, numerator
spellings, guard-condition spellings, in both mirrors) moves the first pick and
e's register independently. The remaining distance is the whole-function
liveness/rotation state documented in `sub_0800D684-NEXT.md`, and the only edit
that touches the metric here is a semantic change.