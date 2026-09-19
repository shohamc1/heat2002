# LaneInject — dead-carrier injection sweeps for sub_0800D684

Owner: `LaneInject`.  Everything was written under `/tmp/LaneInject` only; the
repo tree was never modified and `tools/agbcc` was only ever *executed*
(read-only), never edited.

Metric: `python3 docs/learnings/drafts/d684-tools/filediff.py FILE --workdir DIR`
(size from `d684tool.py`).  Every number below comes from that tool.

## 1. Baselines used (the adopted baseline moved five times while this lane ran)

| file | size | hunks | sdiff | when |
|---|---|---|---|---|
| `/tmp/lanebase/base.c` | 2006 | 0 | 335 | lane start |
| same file | 2006 | 0 | 295 | after LanePostT's tail split |
| same file | 2006 | 0 | 285 | after LanePostT's `b5`/`kb` |
| same file | 2006 | 0 | 276 | after LaneConst's `cp5` |
| same file (current) | 2006 | 0 | 265 | after the braces fix + LanePostT's `cp` at mirror-2 edge-3 |

Because the baseline kept moving, `harness.run_cached` was changed to namespace
every cache key with the baseline's object-file hash (`<hash8>:<key>`), so a
sweep is never silently reused across a baseline change.

## 2. Tooling built (all under /tmp/LaneInject)

| file | what it does |
|---|---|
| `harness.py` | compile+link+score a candidate in a private workdir; JSONL cache; 8-way `ProcessPoolExecutor` (fork).  Detects "no effect" candidates by hashing the **object file** |
| `linemap.py` / `linemap.txt`, `linemap285.txt` | source line `<->` instruction index map, from `cc1 -g` + `objdump --dwarf=decodedline` |
| `an.py` | address-indexed T (ROM) / O (ours) listing annotated with the owning C line |
| `sweep_singles.py`, `phase.py`, `sweep2.py`, `phase_b.py`, `regionb.py`, `splitb.py`, `final_edges.py`, `mirsplit.py` | sweep drivers |
| `rtsweep.py`, `uni.py` | RT-trace (`RT_ALL=1`) probes; `uni.py` gets score **and** spill set from one `cc1` run |

**Correction that mattered:** the first harness used the `.s` hash to detect
"the probe changed nothing".  That is wrong — two semantically identical
variants differ in `.LCB<n>` label numbering, which produced ~4500 false
"this probe changed the code" positives and a bogus cluster analysis.  Switching
to the **`.o` hash** fixed it (verified: `v1 = v1;` after base line 746 vs 753
both hash equal to the baseline object; after line 755 it does not).

## 3. Where the recolours are (335 baseline, `filediff --list` + `linemap.txt`)

55 differing operands on 51 instructions: prologue/loop head (L724, L734-736),
`d0`/`dz` (L752/755), mirror-1 edges 0-3 (L782-806), mirror-2 edges 0-3
(L825-847), and the tail gate (L886-890, L937-938).

## 4. Sweep accounting (every probe that was run)

| # | driver | generator | baseline | probes scored | compile errors | 2006/0/0-hunk | best (size/hunks/sdiff) |
|---|---|---|---|---|---|---|---|
| 1 | `sweep_singles.py` | 7 self-op forms x 35 vars x positions 714-773 | 335 | 15 003 recorded (6 000 `s*` singles + 9 000 `c*` pairs share this file) | 706 | 10 848 | 335 |
| 2 | `phase.py` | `self/or0/const4/neg` x 26 vars x all positions | 335 | 3 003 (killed) | - | - | 335 |
| 3 | `sweep2.py` | `Y = X;` pairs, 174 region positions | 335 | 12 003 | - | 8 605 | **330** at time of run (`c790_e_k3`) |
| 4 | `rtsweep.py` | `Y = X;` pairs, all positions, RT-filtered | 335 | 3 366 (`arch/rtcache/rt.jsonl`, 3 711 entries) | 0 | - | no probe with `4` in `USEDSPILL` |
| 5 | `uni.py` | `Y = X;` pairs, all positions, score+RT in one pass | 295 | 4 173 (`arch/uni.jsonl` + `cache.jsonl`) | 63 | 3 931 | 295 = baseline; 7 RT hits, all `c734_k0_*` (value-changing) |
| 6 | `regionb.py` (first run) | pairs/self/pinned-fresh/unpinned-fresh, lines 779-797 | 285 | 1 500 | 79 | 1 017 | 285 |
| 7 | `splitb.py` | loop-head `dx`/`dz` split family | 285 | 10 | 0 | 10 | 285 |
| 8 | `regionb.py` (final run) | pairs/self/pinned-fresh/unpinned-fresh, lines 779-797 | 265 | 7 686 | 396 | 6 204 | **260** (`R794_e_k3`) |
| 9 | `final_edges.py` | mirror-1/2 edge-1 `e` split family + diagnostics | 265 | 33 | 0 | 22 | **250** (`w1`/`w2`, diagnostic) |
| 10 | `mirsplit.py` | per-mirror splits of `v2`,`v4`,`v1hold`,`w`,`u`, plain + pinned r0-r6 | 265 | 70 | 0 | **0** | none keeps the shape |
| 11 | inline (`edgeq` per-edge split) | per-edge-block `edgeq` -> fresh `eqb`, plain + pinned r0-r4 | 265 | 54 | 0 | 5 | 265 = baseline (`E756_r1`) |

Total distinct probes scored ≈ **47 100**; the driver-prefix breakdown of the
on-disk caches is `s*` 6 000, `c*` 14 403, `R*` 7 446, `S/P/Q*` 3 240, `x*` 18,
`y*` 3, `w*` 2, `M*` 80, `v*` 10.

## 5. Best candidates found

### 5a. `/tmp/LaneInject/best/r794_e_k3.c` — 2006 / 0 / **260** (baseline 265, **-5**)

One inserted statement, `e = k3;`, after C line 794 (`k3 = edgeq + v1;`, inside
the mirror-1 edge-1 guard L792-797).

Cost audit (per Main's warning that the metric prices a branch-offset change as
1 point): the candidate's diff histogram is `{5: 44, 10: 4}` — identical cost
classes to the baseline (`{5: 45, 10: 4}`), **no cost-1 or cost-2 line**.

Exactly: removes `800d864`+`800d866` (`add r0,sp,#32` / `str r0,[sp,#4]`) and
`800d880`+`800d882` (`mov r1,r8` / `cmp r1,#0`), adds `800d860`+`800d862`
(`ldr r3,[pc,#444]` / `str r3,[sp,#0]`) and `800d86a` (`lsls r0,r4,#16`).
Net -20/+15.

**Classification: (b) DIAGNOSTIC-ONLY, not semantics-preserving.**  Line 796
reads `e` as the 8th argument of `sub_0800D64C`, so `e = k3` replaces
`(-0x1C00 - v2)` with `(edgeq + v1)`; the compiler propagates the value and
`(e << 16) / u` becomes `(k3 << 16) / u`.  It wins purely because `e` and `k3`
then share a pseudo.

The same edit measured **330** against the 335 baseline (`/tmp/LaneInject/best/c790_e_k3.c`),
also -5; the delta is invariant across three baseline generations.

### 5b. `/tmp/LaneInject/best/w1.c`, `/tmp/LaneInject/best/w2.c` — 2006 / 0 / **250** (baseline 265, **-15**)

`e = d1;` inserted after L836 (`edgeq = w * e / u;`) or after L837
(`edgeq += v1;`) in the mirror-2 edge-1 block L835-840.  Both give the identical
byte stream.  Cost audit: `{5, 10}` only, no cost-1 line.  Removes
`800da54/da56` (+`800da70/da72`), adds `800da5a`.

**Classification: (b) DIAGNOSTIC-ONLY.**  Same failure mode: L839 reads `e` as
the 8th argument.

## 6. Negative results (recorded so they are not repeated)

* **Self-op forms are exactly equivalent.**  `X = X;`, `X = X + 0;`,
  `X = X - 0;`, `X = (s32)X;` disagree on 0 of 2357 probes.  `X = X | 0;`
  differs on 536, `X = 0;` vs `X = 4;` on 317.
* **Pre-loop injections are inert.**  Every probe at C lines 714-752 produces an
  object file byte-identical to the baseline's, so it cannot move the allocation.
  Only L753-756 perturbed anything on the 335 baseline, and always for the worse
  (395/695).
* **The loop-head `d0`/`dz` block (L747-756) cannot be fixed by splitting.**
  Dropping the `d0` carrier, or introducing a fresh `d0h`/`eqh` (unpinned, and
  pinned to r0/r1/r4) all score 645 except `v6_fresh_eq` at 295 — i.e. nothing
  beats the baseline.  `d0` is one global-alloc allocno spanning the loop and
  therefore must be callee-saved, which is why the ROM's r0 there is unreachable
  from this spelling.
* **`USEDSPILL` set membership is not a lever.**  RT traces: baseline
  `USEDSPILL: 0 1 2 3 6`; `ORDER uid=63 pot: 1 2 3 12 4 5 6 ...`, so r4 *is* a
  candidate at uid 63/77/91/112, but the allocator never needs a fifth distinct
  spill register before uid 1439, when r4 and r5 both have uses
  (`ORDER uid=121 pot: 0 1 2 3 12 5 6 7 8 9 4 10 ...`).  Of 7 077 RT-probed
  injections, 7 put `4` in the set (`c734_k0_k1/k2/k3/dz/dx/...`) and every one
  clobbers `k0` before its use at the very next line — all value-changing.
  This agrees with Main's and LaneSpill's independent conclusions.
* **Per-mirror value splits destroy the shape.**  All 70 variants that split
  `v2`/`v4`/`v1hold`/`w`/`u` into a fresh (plain or r0-r6-pinned) local used only
  inside one mirror half change size (1974-2038) and hunks (33-71); none keeps
  2006/0.  Main's programme item 1 is a dead end in this form.
* **Per-edge `edgeq` splits are worse than neutral.**  54 variants (9 blocks x
  {plain, r0..r4}), each giving `edgeq` a fresh local inside one edge block:
  only 5 keep 2006/0, best 265 (= baseline) at `E756_r1`, the rest 275-1298.
  Main's programme item 2 is a dead end in this form.
* **Preserving respellings of the 250 site are neutral.**  A fresh `e8`/`ev`
  replacing `e` in the mirror-2 edge-1 block (unpinned and pinned r0-r6, the
  assignment placed inside a braced `if`-body immediately before the call) all
  score exactly 265.  The *consistent* `d1` respelling of that block (condition,
  division and shift all using `d1`) scores 635, and the mirror-1 analogue 635.
* **A `.s`-hash filter is unsound** (see §2).

## 7. Unverified / not attempted

* The `uni.py` pairs sweep against the 265 baseline was not re-run to completion;
  its 295-baseline results (`arch/uni.jsonl`, 4 173 probes) are recorded but not
  transferable because the allocation changed with every adoption.
* `phase_b.py` (fresh-local `nx`/`ny` injections) was written but never run.
* No candidate below the current 265 baseline was found that is
  semantics-preserving; the two sub-baseline candidates are both diagnostics.
* The `w1`/`w2` and `r794_e_k3` files under `/tmp/LaneInject/best/` must not be
  adopted into `src/` in their current form.

## 8. Reproduction

```
cd /tmp/LaneInject
python3 harness.py                       # confirms the baseline score + hash
python3 regionb.py all                   # mirror-1 edge-0/1 injection sweep
python3 final_edges.py                   # edge-1 split family + diagnostics
python3 mirsplit.py all                  # per-mirror value splits
python3 linemap.py /tmp/lanebase/base.c > linemap285.txt
python3 an.py 88 100                     # T|O listing for address indices 88-100
```
All scripts guard their work behind `if __name__ == "__main__":` and cap the
pool at 8 workers.
