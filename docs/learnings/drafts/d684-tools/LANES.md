# sub_0800D684 lane brief (2026-09-19, sixth pass)

## Goal
Make `python3 scripts/match.py sub_0800D684` print `MATCH (2006 bytes @
0x0800d684)`.  That needs **bytes**, so two things must both go to zero:

* `hunks` (structural: instruction count/shape, registers masked)
* `sdiff` (field-level: 100 per shape difference, 5 per register recolour,
  1 per immediate/offset) -- i.e. every register operand must agree too

Baseline `src/sub_0800D684.c`: **size 2010, hunks 2, sdiff 627** as of the
seventh pass (the session started at 2010 / 6 hunks / sdiff 1059; six lane
wins came out of it -- see `../sub_0800D684-NEXT.md`).  The only structural
difference left is our two extra post-loop `ldr rN,=gUnk_0202CC90` remats;
everything else is register operands, so the metric is the only gradient
there is.

## Harness (isolated, parallel-safe, never writes to the repo)
    mkdir -p /tmp/<lane> && cp /Users/shohamc1/heat2002-gba/src/sub_0800D684.c /tmp/<lane>/v0.c
    T=/Users/shohamc1/heat2002-gba/docs/learnings/drafts/d684-tools
    python3 $T/filediff.py /tmp/<lane>/v0.c --workdir /tmp/<lane>/wd            # sdiff (primary)
    python3 $T/filediff.py /tmp/<lane>/v0.c --workdir /tmp/<lane>/wd --list     # worst-first line list
    python3 $T/d684tool.py check /tmp/<lane>/v0.c --workdir /tmp/<lane>/wd      # size/hunks + hunk list
    python3 $T/ndiff.py /tmp/<lane>/v0.c --workdir /tmp/<lane>/wd --list        # register-aware diff list
    python3 $T/d684tool.py show /tmp/<lane>/v0.c LO HI --workdir /tmp/<lane>/wd # aligned target|ours disasm

Compile+link+score is ~0.35 s.  Each lane uses its own `--workdir`; nothing
else may run the repo `make` while lanes are compiling.

## Rules
* Only a **strictly lower** `(sdiff, hunks)` counts as progress.  Moving a
  difference elsewhere is not progress; report it only inside a chain that
  ends lower.
* `size` must stay 2006-2010; if a variant's size changes, say so.
* Never edit `/Users/shohamc1/heat2002-gba` (except reading).  Never touch
  `tools/`, `asm/`, `ldscript.ld`, `baserom.gba`, `nascar-heat.sha1`.
* Do not adopt a raw permuter output file; hand-apply the change to your own
  copy first and re-score it.
* Time-box: 50 minutes of wall clock, then write your report and stop.  If you
  run out of ideas earlier, stop earlier and say what you tried.

## Source layout (line numbers in the baseline file)
* ~553-624: structs/externs/prototypes; `struct Ent` fields used:
  unk00, unk08, unk0C, unk14, unk2C, unk34, unk3E, unk40, unk48, unk55,
  unk7C, unk7D, unk88, unkE8, unk140, unk144, unk148, unk175, unk18F.
* ~635+: the function; locals declared in a tuned order (that order is
  **inert**: 95 permutations scored identical -- do not spend time on it).
* pre-loop ~740-760, loop halves, `a1->unk175 = a1->unk175;` self-store,
  `if (flag != 0) { ... }` post-loop block to the end.

## Known mechanisms (do not re-derive)
* `cc` = global-alloc pseudo 51 (refs 21, live 972), never given a hard
  register; each use is a reload rematerialisation.  `pa`/`pb` likewise.
* Reload hands out scratch registers round-robin over `spill_regs[]`, which
  `finish_spills` builds **ascending by register number** from
  `used_spill_regs` (the union of the per-chain picks).  Ours is
  `{r0,r1,r2,r3,r6}`; the ROM's tail remat lands in **r4**, so the ROM's set
  differs there.  Forcing r4 into our set (compiler experiment) re-scores the
  whole function worse (13-16 hunks) -- the set is coupled to everything else.
* All remaining hunks and recolours are allocations.  The 4 hunks are:
  `delete target[52:53]` (the pre-loop ROM `ldr r7,=pa; adds r1,r7,#0` we
  lack), `insert target[264:264]` (our extra `adds r6,r4,#0` from
  `k1 = e; d1 = k1;`), and two extra post-loop `cc` remats (`598`, `617`).
  The `505/511` schedule pair was removed by the sixth pass.

## Reporting (short)
For each variant: file, exact old -> new text, size/hunks/sdiff.  End with:
best file path, its score, and what you learned (one paragraph).  Put the
report in `/tmp/<lane>/REPORT.md` and reply with the same content.