> Fourth-pass closeout: [`sub_0800D684-FOURTH-PASS.md`](sub_0800D684-FOURTH-PASS.md) (alternative remains unintegrated/nonmatching).

# `sub_0800D684` matching handoff

Date: 2026-09-17 (third pass, supersedes the earlier 2026-09-17 handoffs)

## Target

- Function: `sub_0800D684`
- ROM address: `0x0800d684`
- Function size: 2006 bytes
- Authority: `python3 scripts/match.py sub_0800D684`
- Integration status: not integrated; `asm/rom_0800D684.s` is unchanged
- Source status: `src/sub_0800D684.c` is untracked and is the active draft
  (identical to `docs/learnings/drafts/sub_0800D684.c`)

The whole-ROM build is confirmed `MATCH` with the draft removed from
`src/` (this is expected while unintegrated -- see CLAUDE.md). This has
been re-verified after every fix in this pass, and again at the very end
after the compiler-patch experiment (see below), with the original
`tools/agbcc/old_agbcc` binary confirmed MD5-identical to its pre-experiment
state.

## Where this session got to

Starting point: the second-pass handoff's 2006-byte, 12-masked-diff draft.

**Final point of this pass: 2006/2006 bytes (exact), 959/959 instructions
(exact), 8 masked-diff lines, 142 raw unmatched lines.** Not an exact
match. `fulldiff.py` shows the remaining difference as **8 scattered
single/double-instruction delete+insert pairs** (net 4 extra each way),
not the single clean substitution that existed through fix 19 -- see fix
20's note below for how and why that shape changed.

Full narrative and the complete, byte-exact fix list (25 numbered fixes)
are in the comment header of `src/sub_0800D684.c` (kept byte-identical to
`docs/learnings/drafts/sub_0800D684.c`) -- **that header is the
authoritative version**; this file summarizes it and adds the
process/workflow notes, the parallel-agent incident, and the exhaustive
dead-end catalogue that don't belong in the source comment.

### Fixes 1-19 (16 -> 10 masked diff, then steady while raw unmatched fell
306 -> 178)

Summarized in earlier handoff revisions (git history); full detail is in
the source header's "THIRD-PASS FIXES" list, items 1-19. Fix 13 (routing
the pre-loop `sub_0800D5D4(a1, pa);` call's pointer argument through a
`k2 = (s32)pa; sub_0800D5D4(a1, (s32 *)k2);` round-trip cast) dropped
masked diff from 12 to 10. Fixes 14-19 (all found via the permuter +
pycparser-reprint-diff isolation workflow described below) held masked
diff at 10 while cutting raw unmatched lines 214 -> 178, without touching
the identity of what was then still a single true hunk.

### The parallel-Codex incident, and fixes 20-25 (10 -> 8 masked diff,
178 -> 142 unmatched)

Partway through this pass, a **separate Codex agent session** (unrelated
to this one, running under a different process tree -- PID 826 was a
ChatGPT/Codex app-server) was found running its own `decomp-permuter`
instance against this same function, independently of this session. This
was discovered by:

1. A user report of "orphaned permuter processes."
2. Investigation found **154 leaked multiprocessing worker processes**
   accumulated from this session's own many permuter restarts earlier in
   the pass -- a real bug: killing the main `permuter.py` process with
   `pkill` does not reap its worker pool, which gets reparented to PID 1
   instead of dying. All 154 were confirmed orphaned (not linked to any
   live legitimate process) and killed.
3. Among the survivors was a *second*, unrelated permuter instance (the
   Codex one) actively iterating on `sub_0800D684`. Its output
   (`nonmatchings/sub_0800D684/`) was inspected like any other permuter
   run: every candidate was independently verified via `cmp.py` +
   `fulldiff.py` before anything was adopted, exactly as if it had come
   from this session's own search.
4. **Fix 20** came from that Codex instance's output: an asymmetric
   change to the SECOND half's edge-1 guard, `(e = -0x1C00 - v1) >= 0` ->
   `(e = -0x1C00 - v2) >= 0)`, paired with routing the edge-2 call's
   shift argument through a new `s32 fraction;` local. This is *not* a
   standalone regression of the long-standing "v2 grows the function by
   4 bytes" finding -- that test never paired the guard change with the
   `fraction` change, and the pairing is what matters. The FIRST half's
   own edge-1 already has this exact "guard reads v2, body reads v1"
   asymmetric shape, so this brings the second half in line with a
   pattern the first half needed all along. This is what broke the old
   single clean hunk into today's 8 scattered pairs: several nearby
   instructions reordered as a side effect of the fix, not a regression.
5. **A correctness bug was found and rejected** in a further Codex-found
   candidate (masked diff 6, tempting): it introduced a `u32 bound3800;`
   local assigned `= 0x3800;` **only inside the FIRST half's edge-3 `if`
   block**, then read at that same block AND at the SECOND half's edge-2
   check -- a different, later conditional with no intervening
   unconditional write. If the first half's edge-3 guard is false for a
   given iteration, the second half's edge-2 read gets a stale value.
   Same class of bug as the earlier-documented 1440-candidate caution.
   Verified by hand-tracing every write/read; NOT adopted.
6. Codex's own permuter instance later stalled on its own (all its
   worker-pool children went `<defunct>`, unrelated to anything this
   session did) and was left alone -- not killed, since it wasn't this
   session's process to touch.
7. **Fixes 21-25** were found by this session's own permuter, restarted
   cleanly from the fix-20 base, using the same
   permuter-output-plus-pycparser-reprint-diff workflow as fixes 14-19:
   two more genuine no-op self-stores (the same idiom as the original
   `a1->unk175 = a1->unk175;`), one more carrier-chain extension, and one
   paired change (comparison-operand reorder + a `d0` carrier for a
   post-loop pointer cast). Full before/after code for all of fixes
   20-25 is in the source header.

### Comparator tooling (unchanged from earlier passes, still authoritative)

- **Masked-diff** (`cmp.py`): disassemble both target and candidate,
  blank register names, normalize `[pc, #N]` and hex literals, then
  diff. Tracks real structural progress; raw byte count and unmasked
  instruction diff both swing wildly on a single register recoloring.
- **Full, non-truncated instruction comparator** (`fulldiff.py`): compares
  the *actual* target length against the *actual* candidate length via
  `difflib.SequenceMatcher(autojunk=False)`, not clipped to
  `min(len(ours), len(target))` the way `match.py`'s own diff view is.
  **Always run this after adopting any candidate** -- a candidate can
  have a better raw unmatched-line count while secretly introducing a
  second true hunk that a worse but differently-shaped fix happens to
  cancel out in the naive diff. After fix 20 this stopped printing a
  single `REPLACE` line and started printing 8 scattered
  `delete`/`insert` opcodes with instruction-index context; get that
  detailed view with a short inline Python script using
  `match.compare()` and `difflib.SequenceMatcher.get_opcodes()` (not
  saved as a standing script this pass, but trivial to reconstruct --
  see the source header's per-hunk breakdown for the exact target/ours
  context at each of the 8 remaining locations).
- **pycparser reprint-diff**: reprint the pre-candidate baseline through
  `pycparser` (the same parser the permuter uses) so both sides share
  identical brace/formatting conventions, then `diff -u` the two
  reprints. Isolates the one real semantic change from pycparser's
  cosmetic noise (added braces, split multi-declarations, blank-line
  churn) far better than diffing the raw candidate against the
  hand-formatted draft directly.

Standing workflow per candidate, unchanged all pass: hand-apply just the
isolated real change to the clean draft (never adopt a raw permuter file
directly -- it drops the header, expands macros, reformats everything);
verify a stale-value safety argument for any reused local (trace every
read forward to its next unconditional write); re-run `cmp.py` +
`fulldiff.py`; verify whole-ROM safety (move draft out of `src/`, delete
its `.o`, `make check`, confirm `MATCH`, restore); update the header,
sync the drafts copy, restart the permuter from the new base -- always
verifying exactly one instance is running afterward
(`ps -ef | grep decomp-permuter | grep -v grep`).

## The remaining difference: no longer one hunk, now eight

Since fix 20, `fulldiff.py` shows 8 scattered single/double-instruction
delete+insert pairs instead of one clean substitution. All 8 were
individually investigated this pass with concrete target-vs-ours
disassembly context (full detail, including exact addresses and RTL
insn numbers, is in the source header's "NEXT STEP" section):

1. **Pre-loop `sub_0800D5D4(a1, pa)` call**: target loads `pa`'s address
   into r7 first, then copies r7->r1 for the call; ours loads directly
   into r1. Most informative lead -- see "root cause" below.
2. **Extra register copy** near the FIRST half's edge-2 bound check:
   confirmed to be fix 18/22's `k1 = e; d1 = k1;` pair. Tried moving both
   inside the bound-check `if`, moving only `d1 = k1;` inside, and
   swapping assignment order relative to `k2` -- all no-op or regress.
3-4. **Shift-scheduling** in the same edge-2 call's stack-argument setup:
   the `(k1 << 16)` shift computes one position too early relative to
   target, which defers it to immediately before the division call.
   Tried reverting fix 22's carrier hop, reordering `k1`/`d1` relative to
   `k2`, routing the shift through `edgeq`, and dropping the carrier
   entirely -- all no-op or regress (one variant, masked-diff-neutral,
   still exploded raw unmatched 142 -> 530 from unrelated recoloring).
5-6. **Post-loop `gUnk_083FDA2C[...]`-style reads**: `cc`'s field reads
   (`ccd = (*cc).d; k1 = (&gUnk_083FDA2C[ccd])->f0; ...`) reload from a
   literal pool in ours; target already has the base address resident in
   a register. Same root cause as #1, for `cc` instead of `pa`. Tried
   uniform `ccd`/arrow-style access for both `k1` and `k0`'s lines
   (fix 3's old finding re-confirmed as neutral under the current draft
   state) and reference-count-boosting reads -- no effect.
7. **`d1 = (s32)&((struct Ent*)u)->unk55;`** address computation: target
   computes into r0 then copies to r6 (since `d1` must survive to the
   very end of the post-loop block); ours computes directly into r6.
   Tried 5 carrier variants (`k0`/`k1`/`k2`/`k3`/`edgeq`) -- all pure
   no-ops.
8. **`sub_0800BA34(v55, v55, -6, 0, v55, v55, 0x400)`** call: target
   loads three separate zero immediates; ours elides one. RTL-traced
   across all four dump stages (`-dc -dl -dg -dG`): at local-alloc our
   RTL already has all three separate zero-constant insns with
   `REG_EQUAL` notes; at global-alloc, two get replaced with
   `NOTE_INSN_DELETED` as dead-code elimination, apparently triggered by
   hard register r0 being reused sequentially for three unrelated
   transient values right before the call. Every variant tried
   (`volatile` read, distinct local for one argument, carrier locals for
   the `-6`/`0x400` literals) regresses catastrophically (masked diff
   8 -> 34-57, byte count grows). This call site is unusually fragile to
   any touch at all.

### Root cause identified for #1, #2, #3-4, #5-6 (and likely a factor in #7)

`pa` and `cc` are not held in stable callee-saved registers across the
whole function, the way the target's compile holds them. Traced to
`tools/agbcc/gcc/global.c`'s `allocno_compare`, the priority function
that orders global register allocation:

    pri = (log2(n_refs) * n_refs / live_length) * 10000 * size

`pa`/`cc` are live from before the loop until deep into (or past) it --
long static `live_length` -- while short-lived edge-math temporaries
(`k1`, `k2`, `edgeq`, `e`) have short `live_length` and win the priority
race despite fewer total references. `flow.c` gives in-loop references a
modest `+= loop_depth` boost to `n_refs`, but nothing compensates
`live_length` for crossing a loop, so long-lived pointers with high
in-loop reference density still lose to short, hot bursts.

This is a *global, whole-function* register-allocation-priority
characteristic, not a locally steerable statement shape. It resisted
every C-level lever tried this pass:

- Register `asm("rN")` pins, both general (12 variables tried across
  earlier passes) and, this pass specifically, `pa`/`cc` pinned to the
  exact `r7` the disassembly points to: both regress catastrophically
  (masked diff 8 -> 527 and 8 -> 550).
- A narrower, non-whole-lifetime pin technique found by searching the
  codebase for precedent (see below): forcing `pa`'s value into r7 for
  just the one pre-loop call via `register s32 *pa_r7 asm("r7") = pa;
  __asm__ volatile ("" : : "r" (pa_r7));` -- regresses (masked diff
  8 -> 91, byte count wrong).
- Splitting `cc`'s post-loop uses into a separate `cc2` local to shrink
  `cc`'s own live range -- zero effect.
- Redundantly re-deriving `pa`/`cc`/`pb` at the loop's back-edge
  (`loop_continue:`) to break the cross-iteration live edge from the
  static allocator's perspective -- zero effect (the compiler evidently
  treats it as dead code).
- Raising `pa`/`cc`'s apparent reference-count priority via extra
  harmless field reads -- zero effect.

### Compiler modification: attempted and empirically refuted

Per the active `/goal` directive's "may introduce a targeted compiler
change" clause (invoked explicitly by the user after source-level options
were judged exhausted), `global.c`'s `allocno_compare` was patched to
boost priority for allocnos that cross calls
(`allocno_calls_crossed[v] != 0`), on the theory that under-weighting
call-crossing pseudos is what lets short-lived temporaries win the
priority race:

- **Proportional boost** (`pri *= 1 + calls_crossed`): masked diff on
  `sub_0800D684` itself went from 8 to **373**.
- **Flat 2x boost** (gentler): masked diff went from 8 to **18**.

Both regressed the very function the patch was meant to fix, before any
whole-corpus regression run was even needed -- a decisive negative
result. This refutes the specific "boost call-crossing priority" theory,
at least in this formulation. The compiler was rebuilt
(`make -C gcc old`) for each test and the original `old_agbcc` binary was
restored from a pre-experiment backup after, with an MD5 checksum
confirming byte-identical restoration; `tools/agbcc`'s git status was
confirmed clean (`git checkout -- gcc/global.c`) before continuing.
**Do not re-attempt this exact patch shape.** A different formula shape
(e.g. adjusting how `live_length` itself is computed, rather than
boosting priority multiplicatively) has not been tried and might behave
differently, but each iteration costs a full rebuild-and-test cycle.

### Flag sweep specific to this function

The existing 72-cell flag sweep documented in `parked.md` covered nine
*other* stuck functions, not this one. Swept fresh for `sub_0800D684`:
all 16 cells of `{old_agbcc, agbcc} x {-O1,-O2,-O3,-Os} x {interwork
on/off}`, tested against this exact draft via `make CC1=... CFLAGS=...
-B build/src/sub_0800D684.o` (command-line override, no changes to the
tracked Makefile). Only `old_agbcc -O2 -mthumb-interwork` -- already the
Makefile's flags -- produces the correct 2006-byte output length; every
other cell gives the wrong size outright (1998-2078 bytes). This function
was almost certainly built with the same flags as the rest of the ROM.

### Codebase search for a sibling idiom

Searched all of `src/*.c` (via a dedicated research subagent) for
functions sharing the "pointer aliases a global before a loop, survives
calls inside the loop" shape, looking for a C idiom already used
elsewhere in this codebase that might transfer. Findings:

- `sub_0800BB58` and `sub_0801177C` both use `register T *p asm("rN")`
  successfully -- but both pin a pointer whose *initial* value is
  already cheap to obtain (a function parameter already sitting in a
  register, or a stack-local array's address). Neither faces our case of
  a pointer that must come from an expensive literal-pool load of a
  global's address.
- `sub_0801177C`'s own header comment describes its technique as
  re-deriving the pointer fresh every loop iteration rather than
  carrying it across calls -- but this only works because re-deriving a
  *stack* address is nearly free. Re-deriving `pa`/`cc` from their
  globals would require exactly the literal-pool reload we are trying to
  avoid, so this idiom does not transfer.
- `sub_0800AD80` has our exact structural shape unpinned --
  `p = gUnk_0202A550;` surviving four calls per loop iteration, matched
  with zero register tricks -- but its loop body is far simpler than
  ours (much lower local register pressure), so its long-lived pointer
  never has to compete with a dozen short-lived edge-math temporaries.
  This *confirms* the priority-race theory rather than refuting it or
  offering a new lever.
- `sub_0800E200` uses a different, more surgical technique: forcing a
  value into a specific hard register for a narrow scope via
  `register T x asm("rN") = value; __asm__ volatile ("" : : "r" (x));`,
  rather than pinning the variable's storage class for its whole
  lifetime. Tried this on the pre-loop `sub_0800D5D4(a1, pa)` call
  (listed above under "root cause" dead-ends) -- also regressed.

No transferable fix emerged from this search; it corroborated the root
cause rather than resolving it.

## Next shortest path

No live lead remains from this pass's exhaustive sweep. Options, in
order of how promising they seem:

1. **A different compiler-formula theory.** The call-crossing-priority
   boost is refuted, but adjusting how `allocno_live_length` itself is
   computed (rather than boosting priority multiplicatively) has not
   been tried. Each iteration is a full rebuild-and-test cycle with
   uncertain payoff, and any change that *does* help this function still
   needs the same rigor as the existing `calls.c` patch: rival rules
   built and regression-tested against the whole 257-function corpus
   before it could ship.
2. **Set this aside and return later.** Nothing is lost by pausing: the
   draft is safe, fully documented, whole-ROM `MATCH` holds with it
   unintegrated, and every dead end this pass found is recorded so it
   won't be re-tried blindly.
3. Per CLAUDE.md and this project's own convention (see the
   `parked-target-must-match` memory note): do not park this as a
   permanent near-miss. Any future work on it should continue toward
   exact `MATCH`, not settle for 142/8.

Do not integrate or edit linker/asm fragments until `python3
scripts/match.py sub_0800D684` prints `MATCH (2006 bytes @ 0x0800d684)`.
