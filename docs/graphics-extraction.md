# Extract the graphics

This brief is for an agent starting cold. Your job is to move the ROM's
graphics out of `asm/` and into `assets/graphics.json`, the same way commit
`6b46339` moved the sound data. `make check` must print `MATCH` at every
commit.

Status: steps 1 and 2 of the plan are done (`8641006`, `bc0be13`). The
PNGs they produce are greyscale and, for most blobs, not arranged the way
the game draws them. Step 3 fixes that.

## Read first

1. `CLAUDE.md`: the project rules.
2. `docs/learnings/parked.md`, section "Extracted data assets": what the
   sound pass found and what's left.
3. `git show 6b46339`: the sound pass. Copy its shape: `assets/sound.json`,
   `scripts/assets.py`, the `.incbin` block in `data/rom_0801CD08.s`, and the
   `ASSET_STAMP`, `tools`, and `convert` rules in the `Makefile`.

## What's known

These facts come from scans run on 2026-09-23. The scan scripts weren't
committed, so re-derive any number you depend on.

- The main program decompresses with `RLUnCompVram` and `LZ77UnCompVram`.
  The high module has its own RL copy (`sub_08344B70`), and the multiboot
  island has its own LZ77 copy (`sub_08364800`).
- The ROM's 4-byte-aligned words that point at 4-byte-aligned ROM addresses
  give 3,078 distinct targets. Of those, 657 start a valid compressed
  stream: 654 RL
  (first byte `0x30`) and 3 LZ77 (first byte `0x10`), 340,659 compressed
  bytes in total.
- The decompressed sizes are 512 bytes (233 blobs), 256 (198), 4,096
  (106), 128 (64), 32 (29), 64 (23), 38,400 (2), and 12,544 (1).
- The blobs sit in 112 runs of back-to-back streams. Most of them are in
  `0x08280000` to `0x08340000`, and all of them are in
  `data/rom_0801CD08.s`, which covers `0x0801CD08` to `0x083393E0`.
- Every stream but one ends with zero fill to a 4-byte boundary.
- `gbagfx` recompresses 656 of the 657 byte for byte. Its output sometimes
  adds zero fill to 4 bytes, which matches the ROM's own fill.
- The exception is the 12,544-byte blob at `0x080C0000`. It's 13,437 bytes
  in the ROM against 11,836 from `gbagfx`, and the bytes after its stream
  aren't zero. Confirm its stream length before you extract it, then keep it
  raw.
- The two 38,400-byte blobs, at `0x082B370C` and `0x0830EE78`, are the
  Crawfish Interactive and Infogrames boot logos. They're 240x160 8bpp
  bitmaps (mode 4). Their palettes aren't identified.
- `gbagfx` round-trips its own greyscale PNGs. A 4bpp blob converted to PNG
  with no palette converts back to identical bytes, so you can convert a
  blob before you know its palette.
- The multiboot island holds three more LZ77 blobs, at `0x083648A8`,
  `0x083648F4`, and `0x08364940`, which no ROM pointer reaches. They're the
  same sizes as the main program's three.
- About 3.3 MB of the ROM is uncompressed data: BG tilemaps (16-bit screen
  entries with flip and palette bits) and 4bpp tiles, mostly in
  `0x08080000` to `0x08280000`. Few direct pointers reach it.

## Where the code loads graphics

A blob's destination tells you its format. Sprite tiles go to OBJ VRAM
(`0x06010000`), BG data goes to `0x06000000`, and palettes go to
`0x05000000`. These decompiled callers are the place to start:

- `src/sub_0800E008.c` copies the three LZ77 blobs from the table
  `gUnk_083FDA50` (`0x0807CA7C`, `0x0807CAC8`, and `0x0807CB14`) to
  `OBJ_VRAM0 + i * 0x200`.
- `src/DrawTeamSelect [sub_08010BA8].c` and `src/DrawDriverSelect [sub_08010E04].c` decompress RL blobs, such
  as `0x082C9000`, to OBJ VRAM. They reach the blobs through the tables
  `gUnk_083FDF74` and `gUnk_083FDFEC`, which hold pointers to pointers.
- `src/sub_08010FE4.c` and `src/sub_08012C4C.c` decompress RL blobs to OBJ
  VRAM.
- `src/sub_08007760.c` has six `RLUnCompVram` calls. `src/ShowBootSplash3 [sub_080102F0].c`
  and `src/ShowBootSplash2 [sub_08010334].c` each decompress one blob to VRAM.
- `src/sub_0833FDC4.c` is the high module's loader, through `sub_08344B70`.

To tell BG tiles from tilemaps, read the BG control register the same code
writes. To give an image its colours, find the copy that loads its palette.

## Plan

Commit after each step. Each commit needs `make check` to print `MATCH` and
`python3 scripts/progress.py --selftest` to pass.

1. **Extract the raw blobs.** Write `assets/graphics.json` with one entry
   per blob: `type` `"rl"` or `"lz"`, and `size` set to the stream length.
   Replace the blobs' `.byte` rows with `.incbin` lines, adding
   `.align 2, 0` where the ROM has zero fill. This takes about two hours.
2. **Convert them.** Extend `scripts/assets.py convert` so it decompresses
   each blob with `gbagfx` and writes a PNG. Then rebuild each PNG into a
   compressed blob and compare it with the `.bin`, ignoring `gbagfx`'s
   trailing zero fill. `gbagfx` picks the operation from file extensions:
   `.rl` or `.lz` in, `.4bpp` or `.8bpp` out, then `.png`. Keep
   `0x080C0000` raw. This takes about two hours.
3. **Identify the formats.** Use the loaders to record each blob's format,
   width, and palette in its `options`, so the PNGs show real colours. This
   is open-ended, so work in batches, one loader at a time. The logos and
   the 60 car sprites are done; `parked.md` shows how each was found. For
   a sprite, the OAM attributes the loader writes give its colour mode
   (`0x2000` in attribute 0 means 256 colours) and size, and its width in
   tiles is the sprite's width. The `palette` option takes the ROM address
   that the loader copies into palette RAM.
4. **Optional: extract uncompressed data.** Walk the loaders' pointer tables
   to find the tilemaps and tiles in `0x08080000` to `0x08280000`.

Steps 1 and 2 are done when `make clean && make check` prints `MATCH`,
`make convert` reports that every blob but `0x080C0000` converts back byte
for byte, and `parked.md` records the result.

## Rewrite the asm

The script that rewrote the asm for the sound pass wasn't committed. Write
a reusable one, for example `scripts/incbin_assets.py`, that does the
following:

1. Map each line of a fragment to its ROM address, starting from the
   address in the fragment's name. Line sizes follow these rules:
   - `.byte` rows are one byte per value.
   - `.2byte` is 2 bytes, and `.4byte` is 4.
   - `bl` and `blx` are 4 bytes, and every other instruction is 2.
   - `thumb_func_start` aligns the address to 4.
   - Labels, `.global`, `.thumb`, and `non_word_aligned_thumb_func_start`
     take no space.
2. Check every `_XXXXXXXX:` and `sub_XXXXXXXX:` label against its computed
   address. If any label disagrees, the map is wrong, so stop.
3. Split a `.byte` row when an asset boundary falls inside it.
4. Before you remove a label, confirm that nothing outside the removed range
   references it. Search the rest of the fragment, the other `data/*.s`
   files, `src/*.c`, `ldscript.ld`, and `symbols.ld`.
5. Write the `.incbin` lines. `.align 2, 0` aligns relative to the
   fragment's start, so it only matches the ROM when the fragment starts on
   a 4-byte boundary. `rom_0801CD08.s` does.

## Rules

- Don't modify `baserom.gba`, `nascar-heat.sha1`, or anything in `tools/`.
- Leave the pointer tables that reference the blobs as `.byte` rows. The
  pointer pass (see "Pointers" in `docs/learnings/parked.md`) wrote the
  real tables as symbols later.
- The five luvdis false positives that sat in `rom_0801CD08.s`
  (`sub_08120E3A`, `sub_08121316`, `sub_08248272`, `sub_0824C6F0`, and
  `sub_0827B7CA`) are part of the untyped blobs in `assets/unknown.json`.
  `progress.py --selftest` counts all seven whether or not they're in
  `asm/`.
- Stage only your own paths when you commit.
- When you finish a step, update "Extracted data assets" in
  `docs/learnings/parked.md`.
