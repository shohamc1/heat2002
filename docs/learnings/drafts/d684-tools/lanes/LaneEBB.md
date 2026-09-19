# LaneEBB — r4/r5 occupants of the mirror-1 / mirror-2 edge EBBs (sub_0800D684)

Baseline throughout: `/tmp/lanebase/base.c` == `src/sub_0800D684.c`, score
`python3 docs/learnings/drafts/d684-tools/filediff.py FILE --workdir DIR`
-> `{"size":2006,"hunks":0,"sdiff":265}` (51 recolour lines, costs {5:47, 10:4}).
Nothing below 265 was found; **no file under /tmp/LaneEBB/ beats the baseline.**

All work done under `/tmp/LaneEBB/`; nothing in the repo tree was touched;
`tools/agbcc` was only *read* (source at `tools/agbcc/gcc/*.c`, both compilers
used read-only).

---

## 1. The occupant question, answered from the compiler's own numbers

Dumps (stock cc1, `-O2 -mthumb-interwork -fhex-asm -Wimplicit -Wparentheses -dl -dg -da`,
see `/tmp/LaneEBB/dump.sh`, RTL in `d0.i.lreg`, `d0.i.greg`, `d0.i.rtl`):

* mirror-1 edge-3 guard (`w > 0 && v3 >= -0xF00 && …`), source line **798**,
  address 0x800d880ff: `.L24` = label 24, RTL basic blocks 33-37
  (`(code_label 589 … 24 "")` … insns 591, 596-614, 617-677).
* mirror-2 edge-1 guard (`u < 0 && v4 <= 0x1C00 && …`), source line **829**,
  address 0x800d9a8ff: `.L28` = label 28, RTL basic blocks 44-47
  (`(code_label 791 … 28 "")` … insns 886-915-921).

Instrumented cc1 (`tools/agbcc/gcc/old_agbcc`, env `RT_UID=<uid>`) prints, for the
reload chain of an insn, the per-hard-register use counts and the live pseudo set.
Three chains inside/near the two edge EBBs:

```
RT_UID=591  (mirror-1 .L24, `w > 0` test, blk 33)
  live_before: 31 43 44        live_after: 31 43 44
  uses(by regno): 7=315 8=200 10=74          <- r7=u(43) r8=w(44) r10=sl(k0=31)
  r4 = 0 uses, r5 = 0 uses, r6 = 0 uses

RT_UID=434  (mirror-1 edge-1 `e = v2 - 0x1C00`, line 784)
  live_before: 31 34 43 44 139   live_after: 31 34 43 44 45
  uses(by regno): 4=448 7=315 8=200 9=24 10=74
  r4 = 448 uses (pseudos 139 = v2 and 45 = e), r5 = 0, r6 = 0

RT_UID=915  (mirror-2 edge-1 `d1 = (e = v2 - 0x1C00)`, line 829, blk 46)
  live_before: 31 43 44 272 278  live_after: 31 36 43 44 272
  uses(by regno): 4=64 6=420 7=315 8=200 9=24 10=74
  r4 = 64 (pseudo 278 = v2), r6 = 420 (pseudo 36 = d1, live only because the insn defines it)
```

**Result: there is no r4/r5 occupant pair.** At the birth of the shared `e`/`d1`
value, r5 has **0 uses** and r6 has **0 uses** in the reloader's accounting; the
only occupied register is r4, held by the *source* values `v2` (pseudo 139 in
mirror-1, 278 in mirror-2) and by `e` (pseudo 45) itself, which are the same
register because `v2` is dead at that point. The "two earlier quantities occupy
r4 and r5 so `find_free_reg` cannot use r4" diagnosis is therefore refuted for
both edge EBBs by the compiler's own ORDER/UES data, and so is the
`spill_regs[4]`/rotation theory (see §3).

## 2. What the mismatching instructions actually are

The eight "target r4 / ours r6" lines are **not** a free-register choice: they are
the *destination* of the insn that materialises the guard value, and that
destination is the pseudo `d1` (not `e`):

| addr (ROM) | ROM | ours | RTL insn | pseudo |
|---|---|---|---|---|
| 800d890/892/896/8c0 | `subs r4,r1,r0` … `lsls r0,r4,#16` | `subs r6,r1,r0` … `lsls r0,r6,#16` | 608 (blk 35) | 36 = `d1` |
| 800d9aa/9ac/9b2/9d8 | `adds r4,r4,r0` … | `adds r6,r4,r0` … | 915 (blk 46) | 36 = `d1` |
| 800d902/908 | `adds r1,r1,r0; cmp r1,r0` | `adds r6,r1,r0; cmp r6,r0` | blk 38 (line 809) | 36 = `d1` |
| 800daec/af2 | `adds r1,r1,r0` ×2 | `adds r6,r1,r0; adds r1,r6,r0` | blk 62 (line 849) | 36 = `d1` |

Identity of the two pseudos (verified against the initial RTL `d0.i.rtl` and the
final `d0.i.greg`):

* **pseudo 45 = `e`**, home **r4** (`REGNUM … 45=4(48refs)`).
  Initial insn 608 `(set (reg/v:SI 45) (minus (reg:SI 212) (reg:SI 211)))`
  = `e = -0xF00 - v1`; also insn 434/699/699'.
* **pseudo 36 = `d1`**, home **r6** (`REGNUM … 36=6(70refs)`).
  Initial insns 610-612 `(set (reg:SI 213) (reg/v:SI 45))` /
  `(set (reg/v:SI 36) (reg:SI 213))` = `k1 = e; d1 = k1;`.
* Both compiles agree on these homes — the matching lines prove it:
  0x800d774 `ldr r6,[r0,#20]` (= `d1 = pa[5]`) and 0x800d83c `subs r4,r1,r0`
  (= `e = -0x1C00 - v2`, line 792) are byte-identical in ROM and ours.

**Mechanism.** Our source writes the carrier `(d1 = (e = …))` (lines 798, 829) and
`k1 = e; d1 = k1;` (801-802). CSE propagates `e`→`d1` inside the edge, the copy
into `e` dies, and the value is *born in pseudo 36 (r6)* instead of pseudo 45
(r4). The ROM's register is r4, i.e. **the ROM's compile kept the edge-guard value
in `e`**. The mismatching lines are exactly the sites where our carrier moved the
value from `e` to `d1`; they are not caused by r4/r5 occupancy of neighbouring
quantities, and not by `spill_regs`.

## 3. Everything that was tried (size / hunks / sdiff; baseline 2006/0/265)

Source edits (scripts `/tmp/LaneEBB/sweep_carriers.py`, files `/tmp/LaneEBB/v00*.c`,
`/tmp/LaneEBB/sw/c*.c`):

| # | edit | result |
|---|---|---|
| E1 | drop mirror-1 edge-3 carrier + `k1/d1` lines, call uses `(e<<16)` | 2006/0/**829** |
| E2 | drop mirror-1 edge-4 `d1 = k2+0x1C00` carrier (inline the sum) | 2006/0/**320** |
| E3 | drop mirror-2 edge-1 `d1 =` (line 829) | 2006/0/**305** |
| E4 | drop mirror-2 edge-4 `d1 = edgeq+v2` carrier | 2006/0/**315** |
| E1+E2+E3+E4 | all four removed | 2010/4/909 |

Full 16-combination sweep of the four carrier toggles (`c00`…`c15`, bit set =
carrier present): 909, 410, 919, 355, 869, 370, 879, 315, 859, 360, 869, 305,
819, 320, 829, **265 (c15 = baseline, all carriers present)**. The baseline
configuration is the global optimum of this family; every removal loses more
elsewhere than it gains at the edge sites (E3 alone fixes the four mirror-2
edge-1 lines and breaks ten others).

Compiler-side diagnostics (instrumented cc1, no source change):

| probe | result |
|---|---|
| `RT_FREE4=1447` (force r4 zero-use at chain 1447) | 2006/13/2252 |
| `RT_FREE4=1440 RT_FREE4_HI=1500` | 2006/12/2056 (`SPILLSET … 4 -> idx 4`, i.e. set becomes {0,1,2,3,4}) |
| `RT_FREE4=1400 RT_FREE4_HI=1600`, `0..3000` | 2006/12/2056 |
| `RT_SET=01236` (re-derive baseline set) | 2006/0/**265** (sanity: reproduces baseline) |
| `RT_SET=0123456` | 2010/10/1826 |
| `RT_SET=012356` | 2006/11/1833 |
| `RT_SET=012346` | 2002/10/1748 |
| `RT_ADDSET=4` / `=45` / `=5` | 2002/10/1748 / 2010/10/1826 / 2006/11/1833 |
| `RT_SET=01234`, `RT_SET=012345`, `RT_DELSET=6`, `RT_DELSET=6+RT_ADDSET=4/5` | ICE `reload1.c:3711` / fatal "no spill register" |
| `RT_FORCE_LIST=4:1` (force the ROM's pick at the first divergent allocation) | 2006/0/305 |
| `RT_FORCE_LIST=19:0` (force uid 434's constant reload to r0) | 2010/4/824 |

Conclusion from these: **the spill set really is {r0,r1,r2,r3,r6} (5 entries) in
both builds** — forcing r4/r5 in (or r6 out) ICEs or regresses massively, and
`RT_SET=01236` reproduces 265 exactly. `spill_regs[4] = r6` is not the defect.

## 4. Where our build first diverges (new, and it is not the edge blocks)

The reloader allocates scratches round-robin: `i = last_spill_reg; i++ …` over
`spill_regs`, taking the first register that is OK (`reload_reg_free_p`), and a
spill reg is *excluded for a chain* exactly when a live pseudo of that chain is
homed in it (`finish_spills`: `chain->used_spill_regs = used_spill_regs &
~used_by_pseudos`, reload1.c:3619-3627).

The first divergent pick in the whole function is at **RTL uid 91** — address
**0x800d6cc**, source `a1->unk18F` (insn 91 = `(set (reg:SI 79) (plus (reg/v:SI 22)
(const_int 399)))`):

```
uid 91 rnum=0  ours r3 idx 3   ROM r3   (matches)
uid 91 rnum=1  ours r6 idx 4   ROM r1   (0x800d6cc: `ldr r6,[pc,#828]` vs `ldr r1,[pc,#828]`)
```

Both start from the same `last_spill_reg` (=3): candidates are idx 4 (r6), 0, 1, …
r0 is the insn's destination in both, so r0 is blocked for both; therefore **in
the ROM's compile r6 was not available as a scratch at uid 91**, while in ours it
was. All 51 recolour lines are downstream of this class of difference (scratch
picks and the carrier-induced `d1` homes), and the first one is in the *entry
block*, before any edge code runs — so the edge-EBB framing cannot be the root
cause. The tail (0x800db08-0x800de2a) matches exactly, so the two allocations
re-converge later.

## 5. Unverified / open

* Which pseudo is homed in r6 in the ROM's compile at uid 91 is **not** pinned
  down. The live pseudos of that block in our build are 22 (`a1`), 24 (`base`,
  = r2 in both), 26 (`a2`, the never-set `s32 a2`), 28/29 (`reg/v:DI`, defined at
  insn 1370, the `m[2]`/`q[2]` pair) and 30 (`count`) — all spilled in our build
  (absent from `REGNUM`). Any of them homed in r6 would reproduce the ROM's pick
  and would reshape the whole scratch rotation; the exact one is unverified.
* The claim "the ROM has no carriers" is an *inference* from the ROM's r4 at the
  eight sites plus E3/E4 behaviour; it is not proven, and no carrier-free variant
  scored below 265.
* `RT_FREE4`, `RT_SET`, `RT_ADDSET`, `RT_FORCE_LIST` are compiler-side probes with
  no source equivalent; none of their results is a candidate for the repo.
* All 51 baseline diffs are costs 5/10 (register recolours) — none is a cost-1
  branch-target diff, so the baseline file is behaviourally identical to the ROM
  as far as the metric can observe. Some *probe* variants (e.g. `c00`, `c02`, the
  `RT_SET` variants) do produce cost-1 diffs / different branch targets and must
  not be used as source candidates.
