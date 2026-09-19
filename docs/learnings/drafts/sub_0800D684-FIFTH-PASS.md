# `sub_0800D684` fifth pass closeout

Date: 2026-09-18. Supersedes the third/fourth-pass handoff for the *current*
state; the historical narrative in `sub_0800D684-HANDOFF.md` and the source
header still stands for everything this pass did not touch.

## State

| | baseline (fourth pass) | now |
|---|---|---|
| size | 2006 | **2010** |
| structural hunks | 8 | **6** |
| target-extras / ours-extras | 4 / 4 | 2 / 4 |

Authority: `python3 scripts/match.py sub_0800D684` -> `MISMATCH (2010 bytes
@ 0x0800d684)`. `src/sub_0800D684.c` (untracked, not integrated) and
`docs/learnings/drafts/sub_0800D684.c` are byte-identical; source SHA256
`5284a61c...` before the banner, see the file.
Whole-ROM `make check` with the draft excluded still prints `MATCH`
(`/tmp/d684v5/corpus_check.sh` does the exclude/restore, 16 s).

### Remaining 6 hunks

    delete target[52:53]   ours[52:52]     pre-loop: ROM `ldr r7,=pa; adds r1,r7,#0`; ours `ldr r1,=pa`
    insert target[264:264] ours[263:264]   ours: `adds r6,r4,#0` from `k1 = e; d1 = k1;`
    insert target[505:505] ours[505:506]   ours: `e << 16` scheduled one slot early
    delete target[511:512] ours[512:512]   target: `e << 16` immediately before the div call
    insert target[598:598] ours[598:599]   ours: extra post-loop cc rematerialisation
    insert target[617:617] ours[618:619]   ours: extra post-loop cc rematerialisation

## Two edits adopted this pass

Both in the post-loop block; applied to `src/sub_0800D684.c`:

1. hunk 683 (+693 falls out of it).

       d1 = (s32)&((struct Ent *)u)->unk55;       k2 = (s32)&((struct Ent *)u)->unk55;
       v55 = *(u8 *)d1;                     ->    v55 = *(u8 *)k2;
                                                  d1 = k2;

   The ROM computes `addr(u+0x55)` into a temp, loads through it, then copies
   it into d1's register (`adds r0,r7,#0 / adds r0,#85 / ldrb r1,[r0] /
   adds r6,r0,#0`). The carrier spelling is the CSE shape of that. The third
   `movs r1,#0` before `sub_0800BA34` is not separately obtainable: it appears
   because the loaded byte now lands in r1 and clobbers the stale zero from
   the `unk140/144/148 = 0` stores. `k2`/`edgeq`/`dz`/`sd`/`fraction` as the
   carrier give the identical object; `d0` does not.

2. `hit2 = (struct Ent *)w;` moved above `((struct Ent *)u)->unk48 = ...;`.
   Without it edit 1 costs a `mov r8,r9` at index 774 (hit2/w stop coalescing)
   and a 2-byte pool-align pad. All 12 orderings of that statement group were
   brute-forced; this is the unique optimum.

## Size arithmetic (measured, use it)

Over 112 variants, `size == 2006 + 2*(o_extra - t_extra)` holds exactly for
105 (the 7 exceptions are compile-broken variants, off by +2). Each pool
`.align` pad lands on exactly one decoded instruction slot. So `size == 2006`
reduces to **net instruction excess == 0**. This pass's state is at +2, and
nothing inside 660-960 can be removed (that range is hunk-clean), so 2006
needs the remaining fixes to net -2 instructions. The 505/511 pair is
count-neutral (a scheduling swap).

## Mechanism (why the last hunks are coupled)

- Every remaining hunk is a **reload** decision, not a global-alloc choice.
- `cc` is global-alloc pseudo 51 (`refs 21`, `live_length 972`): priority rank
  314/321, never given a hard register. All of its uses are reload
  rematerialisations of the spilled pseudo (`Spilling for insn 1287 / 1293 /
  2372 / 2386` in `.greg`). Reload's cross-insn inheritance
  (`reg_last_reload_reg`) serves later uses from one register only while it
  stays valid: in our compile the first post-loop remat lands in r6, which the
  sin-table `ldrsh r6,[r0,r3]` clobbers, so reload rematerialises twice more.
  The ROM's first remat lands in r4, which nothing touches until 0x800dbc6, so
  one load serves all four uses (ROM has 4 cc pool refs after the loop's
  3; we have 6 -> the two extra hunks).
- `LanePostLoopCc`: the only source shape that yields exactly one
  materialisation for the four post-loop cc reads is spelling them against the
  global (`gUnk_0202CC90.a/.c/.d/.g`) instead of through `cc`. That matches
  the ROM's count but shortens pseudo 51's live range, which re-scores the
  whole function (16 hunks). It is a lead, not adoptable, on its own.
- The pre-loop hunk 52 is the same family: our compiler always folds the
  address constant straight into the argument register, the ROM materialises
  it into r7 and copies. The ROM's r7 live range is exactly indices 50-52 and
  the ROM rematerialises the same address at every loop use, so it is not a
  value held live across the call either.

## Ruled out this pass (do not retry)

- **`calls.c` precompute rule.** Rebuilt `old_agbcc` with the fork commit's
  three `SYMBOL_REF/LABEL_REF/CONST` lines reverted: byte-identical output for
  this function for `(s32 *)k2` *and* a naked `gUnk_0202CCB0` argument. The
  rebuilt patched binary reproduces the vendored one on `sub_08003738`.
- **Flags.** 23 `-f` flags: `-fno-rerun-cse-after-loop`, `-fno-gcse`,
  `-fno-cse-skip-blocks`, `-fno-omit-frame-pointer`, `-fforce-addr`,
  `-fno-expensive-optimizations` all blow up (size 2018-2070, 16-104 hunks);
  `-fno-strength-reduce`, `-fno-function-cse`, `-fno-regmove`,
  `-fno-rerun-loop-opt`, `-fno-thread-jumps`, `-fno-peephole`, `-fno-inline`,
  `-fno-defer-pop`, `-fno-optimize-register-move`, `-frerun-cse-after-loop`,
  `-fgcse` are byte-neutral.
- **Literal address `(s32 *)0x0202CCB0` for `pa`** (CONST_INT instead of
  SYMBOL_REF): 9 hunks / 2010, and it duplicates pool entries.
- **Reload `last_spill_reg` rotation.** Diagnostic: rebuilt cc1 with
  `last_spill_reg` starting at 0..5 instead of -1. k=1,2 regress badly; 0,3,4,5
  are identical to -1. The rotation re-syncs; a start-index shift is not the
  lever. (The counter is per-function: reload1.c:210 static, reset at line
  817.)
- **~2900 single self-store / re-read dials** inserted before every statement
  boundary (`/tmp/d684v5/dials.py`, results in `dials.jsonl`): no single dial
  improves on 6 hunks.
- **Joint lever search, 10240 combinations** on top of this pass's base
  (inline variants x carriers x post-loop orderings x call-argument forms):
  floor is 6 hunks.
- Pre-loop spellings (LaneTail, exhaustive): `pa` direct, `(s32 *)pa`, naked
  global, `(s32 *)(void *)k2`, `(s32 *)(k2+0)`, call moved around
  `pb`/`cc`/self-store, loop's first `pa` use routed through the same
  variable: all tie at 6 or move the hunk to 50-53 (7 hunks); loop-routing
  variants destroy the loop allocation (38 hunks).

## Tooling built this pass (reusable)

- `/tmp/d684v5/d684tool.py` — isolated compile+score: `check FILE
  [--json] [--cc CC1] [--workdir D]`, `show FILE LO HI` (aligned target/ours
  disassembly). Compiles with the project's exact flags, links at
  0x0800D684, prints `size/hunks/t_extra/o_extra` and the structural hunk
  list. Safe to run in parallel; never writes to the repo.
- `/tmp/d684v5/corpus_check.sh` — whole-ROM `make -B check` with the draft
  excluded and restored on every exit path (16 s).
- `/tmp/d684v5/search.py` — lever-combination search (`SEARCH_BASE=... python3
  search.py -j8`), `/tmp/d684v5/dials.py` — dial sweep,
  `/tmp/d684v5/diag_rotation.sh` — the rotation diagnostic (restores the tree).
- `/tmp/d684v5/lanetail/LANETAIL_EDIT.md` — the adopted edits in full text.
- Best variants: `/tmp/d684v5/lanetail/tail_k2.c` (this state),
  `/tmp/d684v5/ccpost/k2_dot.c` (post-loop direct-global lead, 16 hunks),
  `/tmp/d684v5/search2/c528/v.c` (6 hunks, alternate spelling).

## Next steps, in order

1. The post-loop direct-global shape is *right* but needs pseudo 51's live
   range preserved (it ends at the last loop use otherwise). Pair it with a
   late use of `cc` that is not foldable, or find the shape that yields one
   post-loop materialisation *and* keeps cc live through the block.
2. Fix 264 without paying the `mov r1,r8` at 278. `e` is a function-wide
   pseudo (`reg 45`, 6 sets / 6 deaths), so `local-alloc` refuses to tie a new
   pseudo to it - any copy of `e` is a real `adds r6,r4,#0`. Inline use of `e`
   removes 264 but the call's `w` argument copy then takes r0 instead of r1,
   which adds the instruction back at 278. Look for a shape that keeps r0
   occupied (or r6 dead) at the argument-store point without emitting an
   instruction.
3. Hunk 52 is not reachable from the pre-loop block alone by any spelling
   tried; treat it as a consequence of whatever produces the ROM's reload
   register choice (r7) there.
4. If source search stalls again: the permuter is the tool that produced
   fixes 21-25 in the third pass. Restart it from this 6-hunk base
   (`python3 scripts/permute.py sub_0800D684 src/sub_0800D684.c -j8`), watch
   for orphaned workers, and measure candidates with `d684tool.py`, not with
   the permuter's own score.

Do not integrate until `scripts/match.py` prints MATCH.
