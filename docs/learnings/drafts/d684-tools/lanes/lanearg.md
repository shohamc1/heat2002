# LaneARG report — call-argument setup recolours in `sub_0800D684`

## Best candidate from this lane — ADOPTED

**`/tmp/lanearg/braced_275.c` — size 2006, hunks 0, sdiff 275** (vs the then-baseline
276). Verified with `filediff.py <file> --workdir /tmp/lanearg`. Semantics-preserving.
Main verified and adopted it; combined with LanePostT's follow-up the baseline is now
**2006 / 0 / 265**.

Exact edit, applied to `/tmp/lanebase/base.c` (the 276 file), one occurrence:

```diff
-            if ((u32)(edgeq + 0xF00) <= 0x1E00)
-                cp5 = &gUnk_0202CC90;
-                sub_0800D64C(a1, a2, cursor, 0, cp5, &flag, -u, (e << 16) / -u);
+            if ((u32)(edgeq + 0xF00) <= 0x1E00) {
+                cp5 = &gUnk_0202CC90;
+                sub_0800D64C(a1, a2, cursor, 0, cp5, &flag, -u, (e << 16) / -u);
+            }
```

### Correctness warning attached to the adopted 276 baseline

The `cp5` edit in `/tmp/lanebase/base.c` (== `src/sub_0800D684.c` at the time of
writing) **drops the braces**, so the `if` guards only the assignment and the call to
`sub_0800D64C` is executed **unconditionally**. Disassembly evidence from the 276 build:

```
193 T 800d80c: bhi.n 0x800d82e   |  O 800d80c: bhi.n 0x800d810     <- ours skips only 2 insns
194 T 800d80e: ldr r3, [pc,#528] |  O 800d80e: ldr r3, [pc,#528]
195 T 800d810: str r3, [sp,#0]   |  O 800d810: str r3, [sp,#0]
...
207 T 800d82a: bl 0x800d64c      |  O 800d82a: bl 0x800d64c        <- reached unconditionally
```

`0x800d810` is *before* the `bl`, so our call can no longer be skipped; the ROM's
`bhi 0x800d82e` skips the whole argument setup and the call. `braced_275.c` restores
`bhi.n 0x800d82e` (that line stops being a diff) and gains 1 further point: **275**.

## Assigned family: the `&flag` / 5th-argument call setup

**No variant of the `&flag` spelling family improves on the baseline, at any baseline
version I tested (345, 335, 295, 285, 276, 275).** Every spelling that does not change the
instruction stream compiles to a **byte-identical object** — the address is
rematerialised, so a straight-line carrier is folded before register allocation sees it.

Sweeps (isolated compile + `filediff.py`; "identical" = normalised `.s` md5 equal):

| sweep | variants | result |
|---|---|---|
| `&flag` → dead carrier per site: 8 sites × 19 carriers (`k0 k1 k2 k3 d0 d1 dz dx edgeq v1hold lim3800 i count a2 base self other a1_175 u0`) | 152 | byte-identical (except `k0`) |
| `(u8 *)(s32)&flag`, `(u8 *)(void *)&flag`, `&flag + 0` | 24 | byte-identical |
| 2-site and 3-site carrier combinations | 137 | byte-identical |
| one global `u8 *fap` = `&flag` at 2/4/8 sites | 5 | worse (355) |
| `&flag` → `k0` carrier (the one carrier not folded) | 8 | 740, hunks 2 |
| u-guard respellings `u > 0` / `0 < u` / `u >= 1` / `(k2 = u) > 0` / `(d0 = u) > 0` / `!(u <= 0)` / `(s32)u > 0` | 14 | byte-identical |
| fresh **pinned pointer** carriers `register u8 *pf_Sn asm("rN")` (for `&flag`) and `register struct Unk0802CC90 *pc_Sn asm("rN")` (5th arg) at all 8 sites × {r0,r1,r2,r3,r5,r7,r8,sl} | 153 | best 410; rest 655+ |
| fresh **pinned s32** carriers `register s32 q_Sn asm("rN")` for the 5th arg and `&flag`, assignment as a plain statement | 97 | best 490 |
| winner-shaped `register s32 k6 asm("rN")` for `pa`/`pb`/`u`/`hit2`/`d1`/`cc` | 49 | 295 (identical, pin not honoured) ... 681 |
| group J: braces restored on the guarded calls + pinned `&flag` pointer per site | 96 | 275 (brace fix only); the `&flag` carriers are inert on top |
| group K: preserving pinned-pointer carriers at S1/S2/S5/S8 on top of `braced_275.c` | 50 | 0 better than 275 |
| group I: fresh constant locals for the `0xF00`, `0x1C00`, `0x1E00` materialisations in mirror-1 edge 0 (unpinned and pinned) | 22 | byte-identical or worse |

Conclusion: the register that appears in `add rX, sp, #32` / `str rX, [sp, #4]`,
`ldr rX, [pc, =cc]` / `str rX, [sp, #0]`, `mov rX, r8` and `negs rN, rX` at
`0x800d80e–814`, `0x800d864/866`, `0x800da54/56`, `0x800daa4/a6`, `0x800dafc–806`,
`0x800d880/882`, `0x800da70/72`, `0x800dde2/de8`, `0x800d742/746` is chosen by the reload
pass's round-robin over `spill_regs[]`; the C spelling of those arguments cannot move it.
The one lever that *has* moved a site in this region is LaneConst's fresh pinned pointer
`cp5`, and the only follow-up I found there is the brace restoration above.

## Other searches run (all against the then-current baseline, all semantics-preserving)

| search | count | improvements |
|---|---|---|
| 407-lever catalog (walk.py + my `&flag`, unk55, pre-loop, guard, simplification, declaration, unused-declaration families), singles | 287 changing levers | 0 |
| normalised-asm census of that catalog | 407 | 260 byte-identical, 96 change code, 37 stale |
| all pairs of the real levers | 2851 | 0 |
| all triples of levers scoring ≤ 385/hunks 0 | 35 | 0 |
| declaration permutations / moves, unused locals at all 24 slots, `register` qualifiers | 195 | 0 (closest `declsw_690_691` 2006/12/347) |
| group C simplification / statement collapse | 31 | 0 |
| group D live-range reshaping | 13 | 0 |
| spill-set screens: pairs with r4 in `used_spill_regs` | 2851 | 136 hits; every semantics-preserving one scores 1994/46/7254 or worse. The exact `{0,1,2,3,4}` hits all need the semantics-changing `unk55_k2only`. Confirms Main's conclusion that set membership is a symptom, not a lever. |

Total ≈ 8 000 scored variants.

## Tooling this lane adds

1. `/tmp/lanearg/spills.py` — prints the reload pass's real `used_spill_regs` for any
   variant from the **stock** compiler, no rebuild:
   `old_agbcc -O2 -mthumb-interwork -fhex-asm -Wimplicit -Wparentheses -dg f.i -o /dev/null`
   writes `f.i.greg`, containing reload's own `Spilling for insn N.` / `Spilling reg R.`
   lines (from `find_reload_regs`/`new_spill_reg`). The union of `Spilling reg R.` **is**
   `used_spill_regs`. Our baselines: `{0,1,2,3,6}` → `spill_regs[] = [r0,r1,r2,r3,r6]`.
   The r6 needs come from six chains, all at RTL insns 1442–1451 = the
   `((struct Ent *)w)->unk0C -= q0; ((struct Ent *)w)->unk14 -= q1;` pair.
2. `/tmp/lanearg/census.py` — normalised-asm census (strip `@…`, normalise `.LCB\d+`,
   `.L\d+`, `LC\d+`) telling you which levers in a family actually change the machine
   code. A raw `.s` md5 is misleading: a wrapper `{ … }` bumps GCC's local-label counter
   and produces false positives.

## Unverified / not attempted

* I never rebuilt or modified `tools/agbcc`; all measurements used the pristine
  `old_agbcc` (md5 `4f7ab5340990e324e66127b9d0d7bb20`).
* `RT_SET` forcing of `used_spill_regs` (needs a cc1 rebuild) remains the one experiment
  that would settle whether the residual diff is a spill-set artefact.
* `spill4b.py` (spill-set-changing lever × all levers) was still running at close.
* I did not re-measure my whole lever library against every intermediate baseline; the
  `&flag` family was re-measured against 345, 335, 285, 276 and 275 and was inert each time.

## Addendum — mirror-2 per-value splits against the 265 baseline

Following Main's LaneSpill-derived hypothesis (get the mirror-half `e` quantity into r4
by changing what else occupies r4 inside those blocks), I split each mirror-2 value into a
fresh local, unpinned and pinned to r4/r0/r2/r3 (`sl.py`, 24 variants):

| variant | score |
|---|---|
| baseline 265 | (2006, 0, 265) |
| `v1holdsplit_{plain,r0,r2,r4}` | (2006, 0, 265) — byte-identical (pin not honoured / folded) |
| `edgeqsplit_plain` | (2006, 2, 580) |
| `edgeqsplit_{r4,r2,r0}` | (2010, 3, 859) / (2010, 3, 899) / (2010, 4, 964) |
| `v2split_plain` | (2006, 7, 1085) |
| `v2split_{r3,r4,r2,r0}` | (2042, 59, 29343) … (2106, 95, 38383) |

**Nothing below 265.** `v4split*`, `wsplit*` and `usplit*` did not apply (their anchor
text no longer matched the 265 source), so those three values remain untested.

## Final state at close

* Lane contribution adopted: `/tmp/lanearg/braced_275.c` (brace restoration; fixed the
  unconditional-call bug and gained a point). Baseline afterwards **2006 / 0 / 265**.
* Best candidate from this lane that still beats the baseline it was measured against:
  `braced_275.c` (275 vs 276) — now superseded by the adopted 265.
* Nothing I produced beats 265.
