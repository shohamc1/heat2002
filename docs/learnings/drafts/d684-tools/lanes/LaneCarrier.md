# LaneCarrier — whole-file carrier mining, sub_0800D684

Base: mid-run rebase taken from repo src → `/tmp/LaneCarrier/v1.c` = **2010 B / 4 hunks / sdiff 909**
(old base `v0.c` was 2010/4/949). Every number below is measured against 909.

## Tooling built (all fresh, under /tmp/LaneCarrier/)
- `live.py` — pycparser statement-level CFG + backward liveness; prints, per statement, the locals
  that are DEAD immediately before it (safe carriers). Two real bugs found+fixed on the way:
  (a) `cc -E` output must keep its `# line` directives or `coord.line` is *preprocessed* line numbers
  (my first auto-sweep silently edited the comment header, 1011/1011 "byte-identical" — caught by a
  codegen-signature check); (b) in-expression assignments (`(k1 = pb[1])`) must contribute their lvalue
  as a def, otherwise k0..k3 looked live everywhere the loop back-edge reached.
- `sweep2.py` — enumerates every carriable literal occurrence × every provably-dead carrier at that
  point, scores in parallel. `sc.py` — scorer + md5 codegen signature (inert vs real change).
  `gsearch.py` — random-subset search over sets of 2–6 edits.

## Score-changing variants (none improve; these are the mildest regressions)
| file (`cand2/`) | old -> new | size/hunks/sdiff | deadness argument |
|---|---|---|---|
| `L860_8_0_d0.c` | `ang = ((struct Ent *)w)->unk34 >> 8;` -> `d0 = 8;` / `ang = ...>> d0;` | 2010/4/919 | d0 is unconditionally rewritten at L863 (`d0 = gUnk_0801CD08[ang + 0x40];`) before its first later read at L866; liveness live_in(L860) ∌ d0. |
| `L914_12_0_w.c` | `sd = -hit2->unk2C >> 12;` -> `w = 12;` / `sd = ...>> w;` | 2010/4/919 | w's last read is L911 (`((struct Ent *)w)->unk7C`); hit2 is used from L901 on, and w is never read after L911. |
| `L918_0x32_0_w.c` | `if (sd > 0x32)` -> `w = 0x32;` / `if (sd > w)` | 2010/4/919 | same as above (w dead from L911). |
| old base: `e1_f00_f1__u` / `__e` | `if ((u32)(edgeq + 0xF00) <= 0x1E00)` -> `u = 0xF00;` / `if (...edgeq + u...)` | 2010/4/939 | **INVALID** — u and e are read on the very next line (the call's `-u`, `(e << 16)/-u`). The 939 was a byte-improving *bug*; do not adopt. |

## Volume / outcome
- Auto sweep on the new base: 1105 generated, 983 compile, 122 compile errors (block-scoped
  `sd/ang/v55` used out of scope). Of the 983: **434 compile byte-IDENTICAL to the baseline**
  (agbcc -O2 folds the constant, the extra dead store leaves no trace) and **549 change codegen —
  every one strictly worse, minimum 1109**. Zero are ≤909.
- Hand-built sweep on the old base: 1112 variants, best 949 (baseline) apart from the two invalid 939s.
- Set search: 4200 random subsets (size 2–6) drawn from the 220 mildest-regression edits → 0 improvements;
  plus 3000 more (rerun after a sibling's stray `pkill` killed the first attempt) restricted to the 55
  post-loop edits — the region that carries the remaining recolour cluster → 0 improvements. 7200 sets
  scored in total; not one produced sdiff < 909 or hunks < 4.
- Best file: none beats `/tmp/LaneCarrier/v1.c` (909). Nothing to hand over as progress.

## Learning
On this baseline the literal→dead-carrier lever is **exhausted, and it is exhausted for a structural
reason**: agbcc's constant propagation deletes the carried store outright, so 44% of all the
substitutions I generated compile to *the same bytes* as the baseline, and the other 56% (which do
perturb allocation) all make the function *worse* — the allocation the current source induces is a
strict local optimum with respect to "move an immediate into a dead local". The one lever that once
paid (-10, `dz = 4` + `>> dz`) is already spent in v1 and its siblings are now inert. Combined with the
old base's only sub-baseline hits being *semantically invalid* (clobbering a variable read one line
later, buying 10 points of sdiff), the honest conclusion is that further sdiff progress will not come
from carrier substitutions; it needs a different edit class (statement reordering, or the codegen
reasons behind the four structural hunks at 0x800d6ec / 0x800d8a4 / 0x800db68 / 0x800db90).
