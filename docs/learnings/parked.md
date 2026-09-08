# Parked functions and known dead ends

Things that were attempted and did *not* match, with the reason. Read this
before picking a ticket: several of these look like easy leaves and are not.
A park is not a permanent verdict — it is a record of what was already tried,
so the next attempt starts from the failure instead of rediscovering it.

## Not functions at all (luvdis false positives)

Five entries in the 743 count are data runs that the seed heuristic
(`BL` target ∩ `push {..., lr}` prologue) misclassified. A `0xB5` byte
appears in data roughly 1-in-256 of the time, and these five landed on one
that a `bl` also happens to point near.

| "Function" | Tell |
|---|---|
| `sub_08026DB6` | `push` immediately followed by `bhi`/`bcs` on no comparison; `.2byte 0xF9BF @ bl lr+894` |
| `sub_0824C6F0` | two `push` in a row, then a solid `.byte` run |
| `sub_0827B7CA` | `strb r5, [r2, r1]` before any register is set up |
| `sub_080462B2` | `.2byte 0xFA4A @ bl lr+1172` — a `bl` into the middle of nowhere |
| `sub_08121316` | `add sp, #0x000`, then a second `push` |

They are left in `asm/` and must stay there. Do not write C for them. The
743 denominator is therefore ~738 real functions; the count is left at 743
so it agrees with the disassembly and with `progress.py --selftest`.

## Non-interwork epilogues

Two functions end in `pop {r4, pc}` (and `sub_080172C4`'s sibling shape
`mov pc, lr`). Under `-mthumb-interwork` agbcc always emits the
`pop {r4}; pop {r0}; bx r0` form, so the retail bytes are unreachable from
C with the flags the original build used.

`sub_080172C4` itself is solved: it is the `__div0` hook, a bare
`mov pc, lr`, and `__attribute__((naked))` reproduces it exactly
(`src/sub_080172C4.c`). That trick does **not** generalize — a naked
function with a real body means hand-writing the whole body in asm, which
is not decompilation.

27 `pop {r4, pc}` / `mov pc, lr` sites exist across `asm/`. Any ticket
whose target ends that way is blocked on the same wall. Do not add a
compiler flag to work around it (see `CLAUDE.md`, "Never do these").

## The `lsls rB, rA` cross-register-scale family

26 sites, in `rom_0800C98A.s` (5), `rom_0800E732.s` (4), `rom_08016E36.s`
(2), `rom_080172C6.s` (5), `rom_08019D60.s` (3), `rom_0801A56E.s` (6),
`rom_0801B588.s` (1).

The retail code shifts one register by another register's value
(`lsls r4, r5`) while `r5` stays live across the shift and is reused
afterwards. agbcc's `local-alloc.c` allocates the shift-amount register
such that it is treated as dead after the shift, so the natural C
(`x << n` with `n` a live local) produces a copy and a different register
assignment. Root cause is understood; the missing piece is a C construct
that keeps the index live across the shift in a way agbcc's allocator
agrees with. Nobody has found it yet.

Do not attempt to fix this in `tools/agbcc/`. It is vendored and its exact
behavior is what makes every other function match.

## The flag-check scheduling pattern

14 occurrences in the ROM, 0 reachable from current agbcc: the original
compiler scheduled a flag test ahead of an intervening instruction in a way
this build of agbcc will not reproduce from any C arrangement tried so far.
Likely a different point release of the same compiler, or different
optimization ordering. Parked with no known path.

## Style notes that are *not* blockers

- Four decompiled files use raw address casts (`*(u16 *)0x02022E18`)
  instead of `extern` symbols from `symbols.ld`. They byte-match. Worth
  tidying when the surrounding data is named, not before.
- `symbols.ld` has 9 identical duplicate lines. Harmless to `ld`; a
  `sort -u` fixes it whenever someone is editing the file anyway.
