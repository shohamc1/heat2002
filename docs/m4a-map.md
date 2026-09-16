# m4a sound-engine name map

This ROM runs the MP2K/m4a sound driver twice: a low copy near
`0x08000260` and a high copy near `0x08339920` (see
`docs/learnings/parked.md`, "The m4a engine is duplicated at delta
0x3396C0"). Each row below is one engine function, identified by
comparing its decompiled C body (or, for asm-only rows, the drafts in
`docs/learnings/drafts/`) against a reference decompilation of the same
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
| `sub_080013F8` | `sub_0833AAB8` | `MPlayExtender` | certain | yes | converted |
| `sub_08001520` | `sub_0833ABE0` | `ClearChain` | certain | yes | nothing to convert (already just a jump-table call, no offset casts) |
| `sub_08001534` | `sub_0833ABF4` | `Clear64byte` | certain | yes | nothing to convert (already just a jump-table call, no offset casts) |
| `sub_08001548` | `sub_0833AC08` | `SoundInit` | certain | yes | converted |
| `sub_08001640` | `sub_0833AD00` | `SampleFreqSet` | certain | yes | converted |
| `sub_080016E4` | `sub_0833ADA4` | `m4aSoundMode` | certain | yes | converted |
| `sub_080017D0` | `sub_0833AE90` | `m4aSoundVSyncOff` | certain | yes | converted |
| `sub_0800184C` | `sub_0833AF0C` | `m4aSoundVSyncOn` | certain | yes | converted |
| `sub_08001888` | `sub_0833AF48` | `MPlayOpen` | certain | yes | converted |
| `sub_08001900` | `sub_0833AFC0` | `MPlayStart` | certain | yes | converted (kept the r4/r0 register pins) |
| `sub_080019B4` | `sub_0833B074` | `m4aMPlayStop` | certain | yes | converted |
| `sub_0800215C` | `sub_0833B81C` | `m4aMPlayPitchControl` | certain | yes | converted |
| `sub_08001150` | `sub_0833A810` | fade-control setter (`m4aMPlayFadeIn`/`m4aMPlayFadeOutTemporarily` family) | likely | yes | not touched (confidence is only "likely", not certain) |
| `sub_08000DC8` | `sub_0833A488` | `TrackStop` | certain | **no** (blocked in compiler; `tst rX, rY` unreachable — see `parked.md`) | n/a, not decompiled |
| `sub_080019F4` | `sub_0833B0B4` | `FadeOutBody` | certain | **no** (near-miss draft: `docs/learnings/drafts/sub_080019F4.c`) | n/a, not decompiled |
| `sub_08001A74` | `sub_0833B134` | `TrkVolPitSet` | certain | **no** (near-miss draft: `docs/learnings/drafts/sub_08001A74.c`) | n/a, not decompiled |

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

`sub_08001150`/`sub_0833A810` write the same two fields the reference
driver's `m4aMPlayFadeIn` and `m4aMPlayFadeOutTemporarily` both write
(`fadeOI`, `fadeOC`, `fadeOV`), and the field offsets match exactly, but
this ROM's revision writes a plain `0x100` to `fadeOV` and never touches
`MUSICPLAYER_STATUS_PAUSE` or a `TEMPORARY_FADE`/`FADE_IN` tag bit, so it
does not reproduce either split function's body exactly. Likely the same
family, not a certain single upstream name.

## Not part of the engine

`sub_08001170` and `sub_08001208` reference sound-engine internals
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
