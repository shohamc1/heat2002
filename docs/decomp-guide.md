# How to decompile one function (read this whole file first)

This is the step-by-step for turning one `sub_XXXXXXXX` from `asm/*.s` into
C in `src/`. It is written for someone who has never done a matching
decompilation. Every rule here exists because someone got it wrong.

The only definition of "done": `make check` prints `MATCH`. Not "the C looks
right". Not "the disassembly is equivalent". The SHA1 of the built ROM equals
the SHA1 of the original. Nothing else counts.

## 0. Before you touch anything

```
git status          # must be clean
make check          # must print MATCH -- if not, STOP, something is broken already
make test           # all six checks must pass
```

If `make check` does not print MATCH on a clean tree, do not start a ticket.
Do `make clean && make check`. If it still fails, report it; do not "fix" it
by editing `baserom.gba`, `nascar-heat.sha1`, `ldscript.ld` guesses, or the
Makefile's `check` rule. Those are never the problem.

## 1. Pick the function

Take the lowest-numbered **open** ticket in `docs/tickets/README.md`. Do not
pick a function because it looks interesting. Do not pick two.

Read the ticket. Then find the function in asm:

```
grep -n 'thumb_func_start sub_0800048C' asm/*.s
```

It is in exactly one file. Print the block from that line to the next
`thumb_func_start` line. That is everything you are working with.

## 2. Read the asm properly

Things people misread:

**Which bytes belong to the function.** The block runs from
`thumb_func_start NAME` to the next `thumb_func_start`. It contains, in
order: instructions; maybe `.byte 0x00, 0x00` (2 bytes of alignment pad);
then the literal pool (`_XXXXXXXX: .4byte ...` lines that the `ldr rN,
_XXXXXXXX` instructions read); and then, in 312 of 742 cases, **more
`.byte` rows that are NOT part of the function**. Those are data or code
luvdis could not classify. The function ends after its last pool entry.
Everything after that must survive extraction untouched (step 6).

**`ldr r0, _080004AC @ =0x04000130`** loads the constant `0x04000130` from
the pool. The `@ =...` comment tells you the value. In C this is either a
hardware register (`0x04xxxxxx`), a RAM global (`0x02xxxxxx` EWRAM,
`0x03xxxxxx` IWRAM), a ROM data table (`0x08xxxxxx`), or a plain big
constant (anything else). Each becomes a different kind of C (step 3).

**`lsls rN, rN, #0x10` / `lsrs rN, rN, #0x10`** pairs are the compiler
narrowing to `u16`. `#0x18` pairs narrow to `u8`. `lsls`/`asrs` (arithmetic)
narrow to `s16`/`s8`. If you see them, the variable or parameter has that
width. If you do NOT see them and your build emits them, your type is too
narrow.

**`push {r4, lr}` ... `pop {r4}; pop {r0}; bx r0`** is a normal non-leaf
prologue/epilogue. `pop {r0}; bx r0` instead of `pop {pc}` is what agbcc
always emits -- if your output has `pop {pc}` you are not using
`tools/agbcc/old_agbcc`. Which registers are pushed (`r4`..`r7`) tells you how
many callee-saved locals the compiler needed, which constrains how many
locals you declare.

**`bl sub_XXXXXXXX`** is a call. `bx lr` with no push is a leaf. `swi #N` is
a BIOS call and needs inline asm -- skip those tickets unless the ticket says
how.

**`mov r12, lr` / `bx r12`** is a leaf that calls something without saving
lr on the stack. Rare; see the shared-pool note in step 6.

## 3. Write the C

File: `src/sub_0800048C.c`. **One function per file. Always.** The build
places whole objects at addresses; two functions in one file cannot be placed.

```c
#include "global.h"

extern u16 gKeysHeld;      /* 0x020005C8, defined in symbols.ld */
extern u16 gKeysPressed;   /* 0x020005CC */

void sub_0800048C(void)
{
    u16 keys = ~*(volatile u16 *)0x04000130;
    gKeysPressed = keys & ~gKeysHeld;
    gKeysHeld = keys;
}
```

Rules that decide whether this matches:

- **Types from `include/global.h`**: `u8 u16 u32 s8 s16 s32`. Never `int`
  unless the asm shows no narrowing at all. `int` and `s32` are the same
  thing to the compiler, but be explicit anyway.
- **RAM/ROM addresses become `extern` symbols**, not casts. Write
  `extern u32 gFoo[];` and add `gFoo = 0x083FE6C4;` to `symbols.ld`
  (one line, semicolon, hex). A cast like `((u32 *)0x083FE6C4)[i]` produces
  the same instructions in a *different order* and will not match (this was
  DECOMP-002). Hardware registers (`0x04xxxxxx`) are the exception: cast
  those, `*(volatile u16 *)0x04000130`.
- **Name the symbol after its address** until you know what it is:
  `gUnk_083FE6C4`. Renaming later is a one-line change in two places.
- **Callee prototypes** go in the same `.c` file for now:
  `void sub_0800BE00(u32 a, u32 b);` above your function. Get the parameter
  widths from the callee's asm (its narrowing shifts at the top).
- **Locals: exact count, declaration order.** agbcc assigns registers in the
  order you declare. If the asm uses `r4` and `r5`, you likely have two
  locals that live across a call. If stack traffic appears in your output
  that is not in the target, you have one local too many or too few.
- **Statement order is instruction order.** The compiler barely reorders.
  Two stores in the asm happen in the order you write them.
- **Loop shape**: `bge`/`ble` at the *top* of the loop = `for`/`while`.
  Compare-and-branch at the *bottom* only = `do { } while`. Getting this
  wrong produces an extra branch that never goes away.
- **Argument evaluation is right-to-left.** `f(a(), b())` calls `b` first.
- Do not write `static`, `inline`, `const` on anything unless the asm makes
  you. Do not add casts to silence warnings.

## 4. Match it

```
python3 scripts/match.py sub_0800048C
```

That is the only command. It compiles just your object (a full `make` will
fail with "multiple definition" while the asm copy still exists -- that is
expected, ignore it, do not delete the asm yet), links it alone at the
function's address with real symbol values, and byte-compares against the
ROM.

`MATCH` -> step 5. `MISMATCH` -> it prints the target bytes, your bytes, and
an instruction diff. Read the diff, change the C, run it again. Typical
fixes, in order of how often they are the answer:

| Diff shows | Cause | Fix |
|---|---|---|
| extra `lsls/lsrs #16` or `#24` | a variable is too narrow | widen to u32/s32 |
| missing `lsls/lsrs` | a variable is too wide | narrow to u16/u8 |
| same instructions, different order | cast instead of extern; or statements reordered | use `extern` symbol; reorder C to match |
| constant loaded before/after the memory it is combined with | `volatile` on the global | target loads memory first -> add `volatile`; target loads the constant first -> drop it |
| `bl 0x8000000`/wrong target | prototype missing or wrong name | declare the callee |
| `str`/`ldr [sp, ...]` you don't have in target | too many locals | remove one |
| `push {r4, r5}` vs `push {r4}` | wrong number of live locals | add/remove a local |
| `pop {pc}` | wrong compiler | use the Makefile, never `gcc` directly |
| literal pool value differs | wrong constant/address | copy the `@ =` value exactly |
| `undefined reference to gFoo` | symbol not in `symbols.ld` | add it |

Do not loop forever. If after ~10 tries the diff is one stubborn
instruction, write down what you tried in the ticket under "Risks" and
move on to the next ticket. A half-done ticket with notes is useful; a
guessed "match" that is not one is not.

Things that are NOT fixes and must never be done:
- adding `-O1`, `-O0`, `-fno-...` or any flag to the Makefile
- editing anything under `tools/`
- editing `asm/*.s` to look more like your output
- inline asm to force bytes (the point is C)

## 5. Verify it is a real match

`match.py` printed MATCH. Before extracting, sanity-check that the size is
right: it prints `(N bytes @ 0x...)`. Count the instructions in the asm block
up to and including the pool: 2 bytes per instruction, 4 per `.4byte`, plus
any `.byte 0x00, 0x00` pad before the pool. If N is much smaller than that,
the compiler dropped code (a dead store, an unused local) and the "match" is
only matching a prefix -- go back to step 3.

## 6. Extract: move it from asm to C

This is the step with the most ways to fail silently. Follow it exactly.

**6a. Check for a shared literal pool.** Look at every `ldr rN, _XXXXXXXX`
in the block: is `_XXXXXXXX:` defined inside this block? And does any
*other* function's block `ldr` a label defined in this one? If either is
false, STOP -- the function shares a pool with a neighbour and cannot be
extracted alone (a PC-relative `ldr` cannot cross an object boundary; the
assembler says "invalid offset" and `.global` does not help). There are
exactly two such pairs in this ROM: `sub_08000958`+`sub_08000972` and
`sub_0833A018`+`sub_0833A032`. Decompile both halves of a pair or neither.

**6b. Find the cut points.** In the fragment file:
- START = the `thumb_func_start NAME` line.
- END = the line after the function's last pool entry (`_XXXXXXXX: .4byte`).
  If there is no pool, END = the line after the last instruction (and after
  a trailing `.byte 0x00, 0x00` pad if the next function starts 4-aligned
  and this one ended 2-mod-4 -- check the addresses).
- Everything from END to the next `thumb_func_start` is trailing data.
  It is NOT deleted.

**6c. Split the file.**
- Fragment A = original file up to (not including) START.
- Fragment B = the macro preamble (lines 1 through
  `@ End embedded Luvdis macros`, copied verbatim from the top of any
  `asm/*.s`) followed by everything from END to the end of the original.
- Name B `asm/rom_ADDR.s` where ADDR is the ROM address of its first byte:
  function address + function size (the N from `match.py`), in uppercase
  hex, 8 digits. E.g. `sub_08016558` is 16 bytes -> `asm/rom_08016568.s`.
- Overwrite the original with A.

**6d. `ldscript.ld`.** Insert two lines right after the fragment-A line:
```
        build/asm/rom.o(.text*);
        build/src/sub_0800048C.o(.text*);      <- new
        build/asm/rom_080004B8.o(.text*);      <- new
        build/asm/rom_08006738.o(.text*);
```
Address order, top to bottom. Get this wrong and the ROM assembles in the
wrong order and `make check` fails loudly (good) -- but only if you actually
run it.

**6e. Build.**
```
make check
```
If it says `undefined reference to _XXXXXXXX`: a bare address label is
referenced across the split. Add `.global _XXXXXXXX` on the line before
its definition (in whichever fragment defines it) and rebuild. One-time fix.

If it says `multiple definition`: you left the function in asm. Re-check 6b.

If it says `MISMATCH`: you deleted or duplicated bytes. `cmp -l baserom.gba
nascar-heat.gba | head` shows the first differing offset; subtract
`0x08000000` from your function address to see if it is near the cut.
Usually trailing data was dropped (6b) or the fragment name/order is wrong
(6d). Do not try to patch it with `.byte` filler -- restore the fragment
from git and redo the split.

**6f. Confirm.**
```
make check                              # MATCH
python3 scripts/match.py sub_0800048C   # still MATCH
python3 scripts/progress.py             # function count went up by exactly 1
make test                               # 6 checks pass
```

## 7. Commit

One function per commit. Include: `src/NAME.c`, both asm fragments,
`ldscript.ld`, `symbols.ld` if touched, the ticket (status -> done, commit
hash), `docs/tickets/README.md` row. Message: `Decompile sub_0800048C`.

Never commit: `build/`, `*.elf`, `nascar-heat.gba`, `report.json`,
`__pycache__`, `*.sav`. They are gitignored; if `git status` shows them,
something is wrong with your setup.

## Things that look wrong but are correct

- `make` printing assembler warnings about `r13` or `r6 UNKNOWN` from the
  asm fragments. Those are the original ROM's bytes; leave them.
- `make` failing during step 4. Expected until step 6.
- `progress.py` saying `WARNING: sub_X is in src/ but does not match`.
  That is the verifier doing its job: a `.c` file exists whose bytes are
  wrong. Fix or delete the file.
- Two-byte zero gaps between functions in the ROM. The linker makes those;
  never add them by hand.

## Things that look right but are wrong

- A diff that is "only" a different branch offset or pool offset. Bytes
  differ; it is a mismatch.
- "The C is semantically identical." Irrelevant.
- `MATCH` from `match.py` after you also edited asm. `match.py` only checks
  your object; `make check` is the real test.
- A green `make check` right after `make disasm`. `make disasm` writes to
  `build/rom_reference.s` and is only for reference reading.
- Editing `include/global.h` types to make a width match. The types are
  fixed-width; change your variable, not the typedef.
- Touching a header and trusting the next `make`. Headers are tracked as
  dependencies now, but if in doubt `make clean` costs 20 seconds.
