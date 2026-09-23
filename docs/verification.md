# How do we know the decompilation is correct?

Short answer: **we don't, fully.** `make check` proves something narrower than
"correct," and it is worth being precise about the gap.

## What MATCH actually proves

`make check` proves the linked output is bit-identical to `baserom.gba`:

```
shasum -c nascar-heat.sha1     ->  MATCH
```

That is a strong claim about **bytes**, and it is the strongest signal the
project has. If the ROM matches, the compiled C produces the same machine code
the original build produced. There is no room for "close enough" — one wrong
register, one different branch, and the hash changes.

It does **not** prove:

| Claim | Proven by MATCH? |
|---|---|
| Output bytes equal the retail ROM | **yes** |
| Our C means the same thing as the original C | no |
| Function names / signatures are right | no |
| Types are right (`s32` vs `int` vs `enum`) | no |
| The game runs | no — never executed |
| `baserom.gba` is itself a good dump | not by itself |

### Same bytes, different source

Many C spellings compile to identical bytes. `while (i--)` and a `for` loop can
emit the same instructions; `s32` and `int` are the same type here; a `u8`
parameter that is immediately widened is indistinguishable from `int`. Matching
bytes means our source is *a* valid preimage, not *the* original preimage.

This is inherent to decompilation and not fixable by tooling. It is why the
convention is to keep matching functions small and to revisit signatures once
callers are decompiled and the real call sites become readable.

### Names are placeholders

`sub_08006734` is an address, not a name. The recon report labels things like
`__divsi3` and `memcpy` by **behavioral shape** — a shift/subtract division
core, a word-copy fast path with a byte tail. That is inference, and the report
says so. No symbol table survived in the ROM.

## The dump itself

`nascar-heat.sha1.baserom` pins the input, but a hash only proves *consistency*
with the dump we started from — not that the dump is good. The SHA-1
`0eb1fa43d8b0f8a6fb1e3ac04f7bba92c7cbac96` is corroborated against the No-Intro
/ Libretro databases, which is meaningful external agreement but not a
first-party verification. A bad dump that matched a bad database entry would
still produce a confident MATCH.

## Why the matcher compares bytes, not text

`scripts/match.py` originally compared *normalized instruction text* and was
wrong in both directions:

**False MATCH — moving a label.** These normalize identically because the
normalizer dropped label lines, but they assemble to different bytes (the
branch target moves):

```asm
    mov r0, #0        mov r0, #0
.L1:                  add r0, #1
    add r0, #1      .L1:
    cmp r0, #4        cmp r0, #4
    blt .L1           blt .L1
```

**False MISMATCH — `lsl` vs `lsls`.** agbcc emits divided-syntax `lsl`; unified
syntax requires `lsls`. Different text, identical encoding (`0x0080`).

The matcher now assembles both sides and compares bytes.
`python3 scripts/match.py --selftest` asserts the label case really does change
bytes while its text stays identical — the bug is pinned, not just fixed.

When a fragment cannot be assembled standalone (external `bl` targets, literal
pools outside the extracted range) the matcher reports **INCONCLUSIVE** rather
than guessing. Only `make check` is authoritative in that case.

## Verification, weakest to strongest

1. **Per-function bytes** — `scripts/match.py NAME`. Fast, local, sound. Says
   nothing about placement or the rest of the ROM.
2. **Whole-ROM SHA-1** — `make check`. The real gate. Every commit must pass.
3. **Runtime behavior** — *not currently done.* The ROM has never been booted
   in an emulator by this project.

## The honest gap: nobody has run it

A byte-identical ROM is guaranteed to behave identically, so booting the build
adds nothing **while the match holds**. Its value is as a canary for the case
where the match is lost or deliberately relaxed — for example if the project
ever accepts a non-matching function to make progress. There is no such
function today, so runtime testing is deferred rather than skipped.

If a MATCH is ever lost and cannot be recovered, boot both ROMs in mGBA and
compare before trusting anything.

## What would falsify our work

Concrete failure modes worth watching for:

- `make check` prints MISMATCH → the change is wrong. No interpretation needed.
- `match.py` says MATCH but `make check` fails → placement/linker-order bug, not
  a codegen bug. See "Extracting a function: linker placement" in `CLAUDE.md`.
- `match.py` says INCONCLUSIVE → not a match. Do not record it as one.
- A function matches only with contrived C (`volatile` sprinkles, unreachable
  branches, dead locals) → suspect the *shape* is wrong. A struct field,
  different loop form, or a missing early return usually explains it more
  simply. A tortured match is a smell, not a win.
