# What to port from pokeemerald

[pret/pokeemerald](https://github.com/pret/pokeemerald) is a matching
decompilation of a 2002 GBA game built with the same compiler family
(`tools/agbcc`, `old_agbcc` for the sound driver). Four things in it are
worth taking. They are ranked by value per hour of work.

Status as of 16 September 2026: item 3 is done, item 1 is partly done,
and items 2 and 4 are not started. Each section below opens with its own
status line.

| Item | Status |
|---|---|
| 1. m4a names and structs | Partly done. Header and name map landed; 10 twin pairs converted, ~41 files still unidentified. |
| 2. Library-linking build | Not started. |
| 3. Header gaps | Done, but unused. See the note in that section. |
| 4. Graphics and data tooling | Not started, deliberately. |

## 1. m4a names and structs

**Status: partly done.** `include/gba/m4a_internal.h` now exists with
eight verified struct layouts, and `docs/m4a-map.md` names 13 twin pairs.
Ten certain pairs (20 files) have had their hand-rolled offset casts
replaced with named fields, each re-checked with `match.py`. Function and
file renames were deliberately not done; see `docs/m4a-map.md`. What
remains: ~41 sound-region files still unidentified, one pair marked
"likely", and three identified pairs still in assembly.

Take `include/gba/m4a_internal.h` and read `src/m4a.c` alongside your own
sound-region files.

Your ROM runs the same MP2K sound driver pret decompiled. The proof is
`src/sub_080016E4.c`: it is pokeemerald's `m4aSoundMode(u32 mode)`, field
for field. Both read the same bit groups out of one `u32` argument
(reverb, max channels, master volume, DA bit, sample frequency), both
guard on the `Smsh` ident, and both end by calling a frequency setter and
a channel clear. `parked.md` already records the engine ident as
`0x68736D53`, one revision below pret's `0x68736D54`.

What the header gives you:

- Names for the decompiled files in the two engine copies. The "67 files"
  figure this document first gave was wrong: it came from assuming the
  address ranges `src/sub_0800*.c` and `src/sub_0833*.c` were contiguous
  engine code. The low range starts with unrelated boot code (VRAM, OAM
  and palette clears, keypad polling), so the copies are not contiguous
  blocks. Each remaining file needs reading, not an address-range
  assumption. See `docs/m4a-map.md`.
- `struct SoundInfo`, `MusicPlayerInfo`, `MusicPlayerTrack`, `CgbChannel`,
  `SoundChannel`, `WaveData`, `ToneData` and `SongHeader`, replacing the
  hand-rolled offset casts the decompiled files carry now. `sub_080016E4.c`
  declares `struct Snd { u32 magic; u8 unk4; ... u8 pad[0x48]; u8
  chan[12][0x40]; }`; that is `struct SoundInfo`.
- Named constants for the same magic numbers: `ID_NUMBER`,
  `SOUND_MODE_MASVOL`, `SOUND_MODE_FREQ_SHIFT` and the rest.
- Reference C for work that is parked. `parked.md` lists three m4a
  near-miss drafts (`sub_080019F4`, `sub_08001A74`, `sub_08001C20`), one
  never-attempted function (`sub_08002638`) and five untried high twins.
  pokeemerald has a matching C body for each.

Two cautions. The revision differs, so expect small body differences; the
struct layouts and names carry over regardless. And a rename is a refactor
that must keep `make check` at MATCH, because `ldscript.ld` names objects
by filename.

pokeemerald leaves `src/m4a_1.s` in assembly. Those are the hot mixer
routines. Your equivalents are correctly parked for the same reason.

## 2. The library-linking build

**Status: not started.** Nothing below has been applied.

This is the reference implementation for something `parked.md` already
proposes but has never wired up: replacing the 92 vendored runtime
functions with objects built from source.

### What is parked today

`parked.md` establishes that 92 of the 743 blocks are runtime library
code, not game code: 33 libgcc and 59 newlib. They are excluded from the
denominator, so `progress.py` reports against 646. The newlib half alone
is 14,832 bytes, and every one of the 59 is identified by address, symbol
and source file in `docs/learnings/runtime-newlib-map.json`.

The identification is already strong. All 59 match the compiled bytes of
the vendored `tools/agbcc/libc/` sources, with relocation fields excluded,
built with `old_agbcc -O2 -fno-builtin` and no interwork. That is exactly
what `tools/agbcc/libc/Makefile` does:

    CC1    := ../old_agbcc
    CFLAGS := -O2 -fno-builtin

So the library that produced these bytes is sitting in the tree,
unbuilt.

### What pokeemerald does

Three mechanisms, all of which your build lacks:

1. It links the archives. `Makefile:121` reads
   `LIB := -L ../../tools/agbcc/lib -lgcc -lc`. Your link line is
   `$(LD) -T ldscript.ld -T symbols.ld -o $@ $(OBJS)`, with no libraries.
2. It places each archive member at an exact address, one line per member.
   `ld_script.ld:389-440` lists `*libgcc.a:_divsi3.o(.text);`,
   `*libc.a:memcpy.o(.text);`, `*libc.a:vfprintf.o(.text);` and 50 more.
   Lines 1255-1293 do the same for `.rodata`. This is the "explicit
   newlib objects" approach `parked.md` calls for, and it is what keeps
   blanket archive linking from deciding placement for you.
3. It overrides flags per object rather than globally.
   `Makefile:283-289` sets `libc.o: CC1 := old_agbcc` and
   `libc.o: CFLAGS := -O2`, leaving every other object alone. That is the
   "separate build group with its own flags" the parked notes require, and
   it is why replacing runtime objects does not put the existing matches
   at risk.

Your `tools/agbcc/build.sh` already runs `make -C libgcc` and
`make -C libc` and produces `libgcc.a` and `libc.a`; `install.sh` already
copies both into `tools/agbcc/lib/`. Neither archive is built in the tree
now.

### How extraction actually works

The part that is easy to get wrong: a linker pulls a member out of an
archive only when that member resolves an undefined symbol. Right now
nothing in the build references `strlen`, because the assembly fragment
defines `sub_0801AFD0` and callers use that name. Adding `-lc` alone
changes nothing.

To pull one member deliberately, you need four edits together:

1. Force the extraction, with `-u strlen` on the link line or
   `EXTERN(strlen)` in the linker script.
2. Delete the function from its `asm/*.s` fragment, the same cut any
   ticket makes, or you get a duplicate definition.
3. Add the placement line to `ldscript.ld` in address order, the same slot
   the fragment occupied: `*libc.a:strlen.o(.text);`.
4. Alias the old name in `symbols.ld` so decompiled callers still link:
   `sub_0801AFD0 = strlen;`.

### Where to start

Start with `strlen`. It is the smallest single-function member in the set:
66 bytes at `0x0801AFD0`, from `tools/agbcc/libc/string/strlen.c`, with no
literal pool, no `.rodata` and no dependency on another member. Your
linker script places only `.text` today, so a member carrying data cannot
be placed yet, and `strlen` carries none. Its 66-byte size is 2 mod 4, so
it also exercises the zero-fill alignment rule the Makefile already
handles.

If `strlen` matches, the rest of `libc/string/` follows on the same
pattern: `memset` (82 bytes, `0x0801A514`), `strcmp` (90,
`0x0801AF74`), `memcpy` (94, `0x0801A42C`), `memchr` (128, `0x0801A3AC`),
`memmove` (136). All are single-function, data-free members.

### Two constraints to plan around

The ROM carries a second copy of the libgcc helpers in the `0x0834xxxx`
region, which `parked.md` calls cluster 4: `sub_08344BB8` and five others
at the head of `asm/rom_08344B7A.s`. An archive holds one `_divsi3.o`, and
a linker script places one object at one address. So for every duplicated
helper you can convert one copy at most; the other stays in assembly. This
is why `parked.md` says to leave cluster 4 alone, and it is correct.

The large members are the opposite of the probe case. `vfprintf.o` is
4,456 bytes across six functions and spans two clusters; `dtoa.o`,
`mallocr.o` and `mprec.o` each carry `.rodata`, and `mallocr.o` carries
`.data` and `COMMON` as well. Those need the data sections in
`ldscript.ld` before they can be attempted at all.

### Cost

Two to three days for the whole set, and it is the riskiest of the four
items: duplicate symbols, member ordering and data placement all bite.
The `strlen` probe is an afternoon, and it either validates the approach
or kills it cheaply.

## 3. Header gaps

**Status: done, and so far unused.** Every macro and type in the table
below was added, and `make check` still prints MATCH. An audit afterwards
found that no file in `src/` uses any of the 30 names, and there are no
latent call sites either: the `sizeof(x)/sizeof(x[0])` idiom appears in
zero files, no file writes a timer register, and the only two files
touching OAM do a bulk clear through `vu16 *` that a struct would not
improve.

This section's original argument, that the work was cheap and low risk,
was the wrong test. The right test is whether anything calls it. Treat
these 171 lines as scaffolding for the data phase in item 4, and delete
them if that phase does not arrive.

`include/gba/` is already a pokeemerald port, trimmed. These are the
pieces you left behind that are worth having.

| Header | Missing pieces |
|---|---|
| `defines.h` | `TILE_SIZE`, `TILE_SIZE_1BPP`, `TILE_OFFSET_4BPP`, `TILE_OFFSET_8BPP`, `PLTT_OFFSET_4BPP`, `DISPLAY_TILE_WIDTH`, `DISPLAY_TILE_HEIGHT`, `BG_TILE_H_FLIP`, `BG_TILE_V_FLIP`, `EWRAM_END`, `IWRAM_END` |
| `io_reg.h` | 45 register definitions. 44 were added; `WIN_RANGE` was dropped because `defines.h` already defines an equivalent. |
| `macro.h` | `DmaFillLarge16`, `DmaFillLarge32`, `DmaClear16Defvars`, `DmaClear32Defvars`, `CpuFastFill8`, `IntrEnable` |
| `global.h` | `ARRAY_COUNT`, `min`, `max`, `Q_8_8`, `Q_4_12`, `Q_24_8`, `T1_READ_16`, `T1_READ_32` |
| `types.h` | `struct OamData`, `struct BgCnt`, `union Color`. You have no equivalent file. |

`T1_READ_16` and `T1_READ_32` read unaligned little-endian values out of a
byte pointer. Data-driven code uses them constantly, and writing the
shift-and-or by hand each time is where width mistakes creep in.

## 4. Graphics and data tooling, for later

**Status: not started, deliberately.**

Don't port these until a data ticket exists. `ldscript.ld` places only
`.text`, and every byte of data still lives inside an `asm/*.s` fragment as
`.byte` rows, so neither tool has anything to act on yet.

- `tools/gbagfx` converts PNG to and from 4bpp, 8bpp, LZ77 and RL formats.
  Nine C files, needs libpng.
- `tools/preproc` implements `INCBIN_U8("data/foo.bin")` in C source. That
  is the mechanism for moving a `.byte` blob out of assembly into a named
  binary file that C references by symbol.

## What not to port

- `tools/ramscrgen` with `sym_ewram.txt` and friends generates RAM symbol
  addresses by ordering declarations. Your `symbols.ld`, with 624 absolute
  addresses, is simpler and correct for a fixed target layout.
- `asmdiff.sh` dumps two ROM ranges and diffs them. `scripts/match.py` is
  better: it links the candidate at the real address first, so pool
  relocations resolve.
- `tools/gbafix` writes the ROM header checksum. You reproduce the header
  byte for byte from assembly.
- `src/agb_flash*.c` and `src/siirtc.c` decompile Nintendo's save
  libraries. Your ROM has no `FLASH_V` or `SIIRTC` signature string, so it
  doesn't use them.
- Appending `.text` and `.align 2, 0` after compiling. pokeemerald does
  this at `Makefile:307` and you already do it in your own Makefile. Treat
  it as independent confirmation that your alignment fix is the standard
  one, not as something to change.
