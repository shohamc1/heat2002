# Decompilation queue: sub_08015364 subtree — final state

The queue originally held 203 functions reachable from `sub_08015364` and not
yet decompiled, ranked by caller count. This file now records where that
effort landed: what was integrated, and what is parked with a draft and a
one-line statement of the remaining diff. Each parked draft's header comment
is the authoritative record; `docs/learnings/parked.md` holds the cross-cutting
dead ends.

## Status

- 161 of the 203 queue functions decompiled and integrated on this branch
  (`git log --oneline main..HEAD | grep -c Decompile` = 161; `src/` grew from
  262 functions at `main` to 423).
- `python3 scripts/progress.py`: functions 423 / 646 matched; code 51108 /
  102164 bytes (50.0254%); whole ROM 51108 / 119704 bytes (42.6953%) over
  743 blocks (5 of which are luvdis false positives — see `parked.md`).
- 42 queue functions remain, all parked: 41 with drafts in
  `docs/learnings/drafts/`, plus `sub_08000972` (below).

## Remaining to decompile (in asm, no draft)

None. Every queue function still in `asm/` either has a quarantined draft or
belongs to the hand-written-asm pair `sub_08000958` + `sub_08000972`, which is
retail hand-written assembly, not a C target — leave both halves in `asm/`
(`docs/learnings/parked.md`, "Parked 2026-09-14: sub_08000958 +
sub_08000972"). The pair's analysis record lives in
`docs/learnings/drafts/sub_08000958.c`.

## Parked with drafts (42)

Ranked by original caller count. Drafts for functions since resolved into
`src/` (e.g. `sub_0800EEFC`) are kept as learning records and are not listed.

| Function | Size | Callers | Remaining diff (from draft header) |
|---|---|---|---|
| `sub_080065A8` | 396 b | 30 | exact size, 198/198 instructions, same opcodes — register-allocation names only |
| `sub_08003330` | 1032 b | 9 | unmatched draft; record in `docs/learnings/sub_08003330.md` |
| `sub_08004DB4` | 240 b | 4 | bare code draft, no quarantine header |
| `sub_0800BD98` | 104 b | 3 | bare code draft, no quarantine header |
| `sub_08016F80` | 128 b | 2 | 108/120 bytes, structure matches; DISPCNT `ands r4,r3` vs our `ands r3,r4` |
| `sub_08003F84` | 148 b | 2 | loop tail 2 insns short (reload scratch r0 vs r2) + high-register permutation |
| `sub_080112E0` | 156 b | 2 | structure fully solved; one pairwise register permutation |
| `sub_0800930C` | 176 b | 2 | bare code draft, no quarantine header |
| `sub_08017000` | 184 b | 2 | one allocation decision plus its register fallout (190/184 bytes) |
| `sub_08004018` | 200 b | 2 | 2 insn-shape issues in the loop body |
| `sub_08000DC8` | 772 b | 2 | BLOCKED — epilogue is interwork form |
| `sub_0800F0BC` | 24 b | 1 | BLOCKED — reachable/unreachable insn mix (`mov r2, pc` self-check) |
| `sub_08000958` | 26 b | 1 | hand-written asm pair with `sub_08000972`; not reachable from agbcc C |
| `sub_08007304` | 64 b | 1 | wave-1 closeout: 4-byte floor with r7 pin (mov r7,ip constructible); pure-C r0-occupant impossible |
| `sub_0800383C` | 84 b | 1 | one register permutation away |
| `sub_08016ED8` | 100 b | 1 | one cluster of 4 register-swapped instructions at 0x08016eea |
| `sub_0800C2CC` | 140 b | 1 | wave-5d state compiles; agent died mid-work |
| `sub_0800C430` | 176 b | 1 | wave-4 dead-agent state; rebuild diverges (push set differs) |
| `sub_0800A628` | 224 b | 1 | 220/220 bytes; one diff cluster around the j-chain 0x800a66a-0x800a686 |
| `sub_0800CBB8` | 224 b | 1 | structure 100% solved; only a register swap (mask results r3,r2) |
| `sub_08008AB0` | 228 b | 1 | 132 b code, identical control flow/block layout; register allocation differs |
| `sub_080170B8` | 228 b | 1 | register-allocation and block-ordering artifacts after ~18 iterations |
| `sub_080046D0` | 268 b | 1 | batch3 register permutation only (batches 1&2, flags, masks all MATCH) |
| `sub_0800DE9C` | 304 b | 1 | everything matches except 2 insns in the loop's tile computation |
| `sub_08011B08` | 316 b | 1 | compiles; one allocation-race cluster left (324/324, diff at words 9-82) |
| `sub_0800E200` | 452 b | 1 | wave-5d state compiles; agent died mid-experiment |
| `sub_0800E008` | 504 b | 1 | best build 540/532 bytes (retry-wave notes in header) |
| `sub_0800AB78` | 520 b | 1 | 520/520 bytes; cross-jump sharing of the four `sub_0800A80C` call sites |
| `sub_0800BEA4` | 580 b | 1 | wave-4 dead-agent state; mid-function code 4 bytes short |
| `sub_0800CD38` | 580 b | 1 | best build 572/580 bytes |
| `sub_0800A084` | 592 b | 1 | wave-4 dead-agent state; code 2 bytes short, branch/pool offsets drift |
| `sub_08007C44` | 692 b | 1 | 700/700 bytes; register+slot allocation only, pools match |
| `sub_08009C4C` | 764 b | 1 | wave-5d state replaces older draft; agent died mid-work |
| `sub_0800A80C` | 876 b | 1 | 896/876 bytes; GCSE PRE hoists at the `sub_0800D248` join |
| `sub_080097A4` | 892 b | 1 | wave-4 dead-agent state; allocation pattern differs (adds-chain vs movs+adds) |
| `sub_0800D248` | 908 b | 1 | best build 868/908 bytes (64-bit math / MIN/MAX chains) |
| `sub_0800EAA0` | 1004 b | 1 | control-flow transcription believed correct after ~12 iterations |
| `sub_0800D684` | 2012 b | 1 | 1990/2012 bytes; 39-instruction multiset diff, fully characterized |
| `sub_08006A34` | 2240 b | 1 | 2240/2240 bytes, 10 bytes differ at 3 sites; root causes identified |

`sub_08000972` (1110 b, 1 caller) has no separate draft: it is the second
half of the hand-written-asm pair above.
