# m4a sound-engine name map

This ROM runs the MP2K/m4a sound driver twice: a low copy near
`0x08000260` and a high copy near `0x08339920` (see
`docs/learnings/parked.md`, "The m4a engine is duplicated at delta
0x3396C0"). Each row below is one engine function, identified by
comparing its decompiled C body against a reference decompilation of the same
MP2K/m4a driver used across many licensed GBA titles from this era.

Every "certain" row was confirmed by matching struct-field offsets or
literal values the ROM code actually computes (jump-table indices,
constant math results, a magic-number range check split into two
constants, etc.), not by address arithmetic. The `docs/learnings/parked.md`
note that "the delta holds only for a twin function's own address" means
the delta is safe to use as a place to *look*, never as a substitute for
reading the code there; every pair below was independently read at both
addresses.

## Identified functions

| Low address | High address | Name | Confidence | Decompiled? | Struct pass (Stage B3) |
|---|---|---|---|---|---|
| `MPlayExtender [sub_080013F8]` | `sub_0833AAB8` | `MPlayExtender` | certain | yes | converted |
| `ClearChain [sub_08001520]` | `sub_0833ABE0` | `ClearChain` | certain | yes | nothing to convert (already just a jump-table call, no offset casts) |
| `Clear64byte [sub_08001534]` | `sub_0833ABF4` | `Clear64byte` | certain | yes | nothing to convert (already just a jump-table call, no offset casts) |
| `SoundInit [sub_08001548]` | `sub_0833AC08` | `SoundInit` | certain | yes | converted |
| `SampleFreqSet [sub_08001640]` | `sub_0833AD00` | `SampleFreqSet` | certain | yes | converted |
| `m4aSoundMode [sub_080016E4]` | `sub_0833ADA4` | `m4aSoundMode` | certain | yes | converted |
| `m4aSoundVSyncOff [sub_080017D0]` | `sub_0833AE90` | `m4aSoundVSyncOff` | certain | yes | converted |
| `m4aSoundVSyncOn [sub_0800184C]` | `sub_0833AF0C` | `m4aSoundVSyncOn` | certain | yes | converted |
| `MPlayOpen [sub_08001888]` | `sub_0833AF48` | `MPlayOpen` | certain | yes | converted |
| `MPlayStart [sub_08001900]` | `sub_0833AFC0` | `MPlayStart` | certain | yes | converted (kept the r4/r0 register pins) |
| `m4aMPlayStop [sub_080019B4]` | `sub_0833B074` | `m4aMPlayStop` | certain | yes | converted |
| `m4aMPlayPitchControl [sub_0800215C]` | `sub_0833B81C` | `m4aMPlayPitchControl` | certain | yes | converted |
| `m4aSoundInit [sub_08001170]` | `ModuleM4aSoundInit [sub_0833A830]` | `m4aSoundInit` | certain | yes | n/a (no offset casts; see the build constants below) |
| `sub_08001150` | `ModuleMPlayFadeOut [sub_0833A810]` | fade-control setter (`m4aMPlayFadeIn`/`m4aMPlayFadeOutTemporarily` family) | likely | yes | not touched (confidence is only "likely", not certain) |
| `sub_08000DC8` | `sub_0833A488` | `TrackStop` | certain | n/a (hand-written asm in `m4a_1.s`; built from `lib/m4a_1.s`) | n/a |
| `FadeOutBody [sub_080019F4]` | `sub_0833B0B4` | `FadeOutBody` | certain | yes | not converted |
| `TrkVolPitSet [sub_08001A74]` | `sub_0833B134` | `TrkVolPitSet` | certain | yes | not converted |

All 20 files across the 10 "converted" rows still print `MATCH` individually
(`python3 scripts/match.py <name>`), and `make check` prints `MATCH` for the
whole ROM after every one of them.

The "certain" confidence on the three asm-only rows comes from
`MPlayExtender`'s jump-table assignment (`gUnk_02001D90[0x1E..0x21]` /
`gUnk_02038DE0[0x1E..0x21]` hold, in order, `SampleFreqSet`, `TrackStop`,
`FadeOutBody`, `TrkVolPitSet` — indices `0x1E`-`0x21` are exactly
30-33, matching the reference driver's jump-table slots for those four
functions) plus the direct calls from `MPlayStart`/`m4aMPlayStop` to
`sub_08000DC8`/`sub_0833A488` at the position `TrackStop` occupies.

`sub_08001150`/`ModuleMPlayFadeOut` write the same two fields the reference
driver's `m4aMPlayFadeIn` and `m4aMPlayFadeOutTemporarily` both write
(`fadeOI`, `fadeOC`, `fadeOV`), and the field offsets match exactly, but
this ROM's revision writes a plain `0x100` to `fadeOV` and never touches
`MUSICPLAYER_STATUS_PAUSE` or a `TEMPORARY_FADE`/`FADE_IN` tag bit, so it
does not reproduce either split function's body exactly. Likely the same
family, not a certain single upstream name.

## Tier 1 batch (2026-09-24, all decompiled and matched)

The 2026-09-24 Tier 1 queue decompiled the remaining driver functions
(`docs/decomp-queue.md`). Every pair below was matched byte-for-byte from
`tmc`'s `m4a.c` shapes (one revision older), so the identification is
certain unless noted. Names follow tmc; where the older revision's body
differs, the note in `docs/decomp-queue.md`'s Tier 1 section is the record.

| Low address | High address | Name |
|---|---|---|
| `sub_08001134` | `sub_0833A7F4` | `MPlayContinue` |
| `sub_08001234` | `sub_0833A8F4` | `m4aSongNumStartOrChange` |
| `sub_08001280` | `sub_0833A940` | `m4aSongNumStartOrContinue` |
| `sub_0800133C` | `sub_0833A9FC` | `m4aMPlayAllStop` |
| `sub_08001374` | `sub_0833AA34` | `m4aMPlayAllContinue` |
| `sub_080013B0` | `sub_0833AA70` | track reinit (ImmInit-style; see queue notes) |
| `sub_0800151C` | `sub_0833ABDC` | `SoundGetJumpList` (`svc 0x2A` stub, inline asm) |
| `sub_0800177C` | `sub_0833AE3C` | `SoundClear` |
| `MidiKeyToCgbFreq [sub_08001B28]` | `sub_0833B1E8` | `MidiKeyToCgbFreq` |
| `CgbOscOff [sub_08001BD0]` | `sub_0833B290` | `CgbOscOff` |
| `sub_080020CC` | `sub_0833B78C` | `m4aMPlayTempoControl` |
| `sub_080020F4` | `sub_0833B7B4` | `m4aMPlayVolumeControl` |
| `sub_080021D0` | `sub_0833B890` | `m4aMPlayPanpotControl` (3rd param `u8`, not `s8`) |
| `sub_08002238` | `sub_0833B8F8` | `ClearModM` |
| `sub_08002258` | `sub_0833B918` | `m4aMPlayModDepthSet` |
| `sub_080022CC` | `sub_0833B98C` | `m4aMPlayLFOSpeedSet` |
| `ply_memacc [sub_08002340]` | `sub_0833BA00` | `ply_memacc` (high copy is a RAM module, base 0x02002F80) |
| `ply_xcmd [sub_08002498]` | `sub_0833BB58` | `ply_xcmd` |
| `ply_xxx [sub_080024B8]` | `sub_0833BB78` | `ply_xxx` (revision difference; see queue notes) |
| `ply_xwave [sub_080024CC]` | `sub_0833BB8C` | `ply_xwave` |
| `ply_xtype [sub_08002514]` | `sub_0833BBD4` | `ply_xtype` |
| `ply_xatta [sub_08002528]` | `sub_0833BBE8` | `ply_xatta` |
| `ply_xdeca [sub_0800253C]` | `sub_0833BBFC` | `ply_xdeca` |
| `ply_xsust [sub_08002550]` | `sub_0833BC10` | `ply_xsust` |
| `ply_xrele [sub_08002564]` | `sub_0833BC24` | `ply_xrele` |
| `ply_xiecv [sub_08002578]` | `sub_0833BC38` | `ply_xiecv` |
| `ply_xiecl [sub_08002584]` | `sub_0833BC44` | `ply_xiecl` |
| `ply_xleng [sub_08002590]` | `sub_0833BC50` | `ply_xleng` |
| `ply_xswee [sub_080025A4]` | `sub_0833BC64` | `ply_xswee` |

The high module's song-num family reads its own EWRAM copies of the song
and player tables (`gUnk_0200CA74`, `gUnk_0200CAA4`), and its table data
sits at one fixed delta 0x17FF6E0 from the low ROM tables (already recorded
for `gCgb3Vol`); code addresses in the module map at delta 0x6338A80
(0x08338A80 ↔ 0x02000000).

## Not part of the engine

`m4aSoundInit` and `sub_08001208` reference sound-engine internals
(`SOUND_INFO_PTR`, calls into `m4aSoundMode`, `MPlayOpen`, `MPlayStart`)
but are game-side callers that set up this title's specific song/track
tables, not driver functions. They are decompiled but out of scope for
Stage B3.

## Coverage against the 67-file estimate

The background analysis behind this pass estimated 67 decompiled files
across the two copies (35 low, 32 high). Reading every `src/sub_0800*.c` and
`src/sub_0833*.c` file that references a sound-engine token
(`SOUND_INFO_PTR`, the `0x68736D53` ident, or a jump-table RAM global)
found only 13 low-copy and 13 high-copy decompiled files that are
actually engine code (the 26 "yes" rows above), plus 3 function pairs
still in assembly. The low copy's address range starts with unrelated
boot code (VRAM/OAM/palette clear, interrupt vector setup, keypad
polling) that happened to fall into the address window the earlier
estimate assumed was contiguous engine code — it isn't; the two engine
copies are not contiguous blocks of decompiled files, so finding the
rest of the 67 needs the same per-function reading done here, function
by function, not an address-range assumption. The remaining ~41 files
are left unidentified rather than guessed.

## Struct layouts

`include/gba/m4a_internal.h` has the confirmed struct layouts
(`SoundInfo`, `MusicPlayerInfo`, `MusicPlayerTrack`, `CgbChannel`,
`SoundChannel`, `SongHeader`, `ToneData`, `WaveData`) and the function
prototypes for every "certain" row above.

## Renaming: deliberately not done here

None of the `src/sub_*.c` files or function symbols above were renamed
to their engine names. `ldscript.ld` and `symbols.ld` place objects and
resolve symbols by filename/symbol name, so a rename cascades into both
and is a separate, higher-risk piece of work. Renaming is a deliberate
follow-up, not part of this pass.

## Build-configuration constants

Three symbols in `symbols.ld` are not addresses. The code takes a symbol's
address and truncates it, which is how the MP2K build materialises a
compile-time configuration value:

    soundInfo->maxLines = (u8)(u32)&gMaxLines;      // src/MPlayExtender.c
    cnt = (u16)(u32)gNumMusicPlayersLow;             // src/m4aSoundInit.c

The reference driver declares the same two symbols in its own linker
script, as `gNumMusicPlayers` and `gMaxLines`. This repo's names, and
their values:

| Symbol | Value | Used by |
|---|---|---|
| `gMaxLines` | 0 | both copies, in `MPlayExtender` |
| `gNumMusicPlayersLow` | 5 | low copy, in `m4aSoundInit` |
| `gNumMusicPlayersHigh` | 4 | high copy, in `m4aSoundInit` |

The two engine copies are configured with different music-player counts,
5 and 4. That is why one concept needs two symbols: a linker symbol holds
one value. It is also independent evidence that the copies are separate
builds rather than a byte-for-byte duplication, which matches the
`parked.md` rule that the 0x3396C0 delta applies to a twin's own address
and to nothing else.

These were named `gUnk_00000005`, `gUnk_00000004` and `gUnk_00000000`
until 16 September 2026. All four affected files still print `MATCH`.
