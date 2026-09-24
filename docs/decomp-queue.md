# Decompilation queue: the last 208 functions

This file ranks the 150 game-code functions left at 852 / 1001 matched
(2026-09-24). Work top to bottom. Each tier makes the next one cheaper, and
inside a tier, each family's first member makes the rest ports.

The previous queue, the `sub_08015364` subtree, finished on 2026-09-23.
`git log -- docs/decomp-queue.md` holds its record.

## How the order was built

The ranking uses four facts about each function:

- **Callers.** 205 of the 221 functions have no `bl` caller. They're
  callbacks reached through a pointer. The other 16 are small helpers.
  Call order barely matters, because `match.py` links against the asm
  symbols, but a helper's prototype helps its callers. So the
  `sub_0800792C` and `sub_08007950` helpers (13 callers each) open tier 3.
- **Reference source.** The block from `sub_08001134` to `sub_080025A4` is
  the m4a driver. `tools/tmc/src/gba/m4a.c` has C for every function in it.
  Start from that file, adjusted for this ROM's older revision (see the
  `sub_08001C88` entry in `docs/learnings/parked.md`).
- **Twins.** "port of" means the function is identical, or at least 90%
  similar, to an earlier row, so its C is that row's C with globals,
  callees, or field offsets renamed. "from" names an already-matched near
  twin from `docs/function-twins.md`.
- **Prior attempts.** None of the 221 appears in `parked.md` or
  `solved-walls.md` as a failed attempt.

Rows marked "jump table or inline data" hold `.byte` rows. Their sizes are
lower bounds: luvdis can leave `switch` case bodies outside the block (see
"Resolved: `sub_0800F8D0` was mis-scoped" in `parked.md`). Check the real
range before you cut the fragment.

Hour figures are rough: 0.1 hours per port, and 0.25 to 5 hours per fresh
function by size. Reference source or a matched twin divides the figure
by three, and a jump table multiplies it by 1.5.

## Tier 0: Trivial stubs — finished 2026-09-24

All 14 matched, one per commit; `make check` MATCH throughout.
780 → 794 / 1001. `sub_0800DE5C` was parked first and matched later the
same day; see its entry in `docs/learnings/parked.md`.

What the source shapes turned out to be, for the next stub batch:

- `sub_080032DC` family (4): `void f(void) { u8 unused[0x28]; }` — the
  unused array keeps the frame; `add sp, #-0x28; add sp, #0x28; bx lr`.
- `sub_0800020C` family (2): `while (1) callee();`.
- `sub_083434AC` family (2): `return 0xC00;` — agbcc synthesizes
  `movs r0, #0xC0; lsls r0, r0, #4` for it.
- `sub_080079A0` family (2): `arg->unkC(arg);` — callback at offset 0x0C
  of a linked-list entity (next 0x10, prev 0x14; see the tier 3 helpers).
  The high port calls `_08344B80(arg, arg->unkC)` — the module's renamed
  `_call_via_r1` — following `sub_0833ABF4`'s convention.
- `sub_0800DFC0` family (2): `gUnk_03007FF8 = 1;`.
- `sub_08016CF8`: `return sub_080025FC() * 2;` with a u8-prototyped
  callee — the caller re-narrows and fuses with the `* 2` into
  `lsls #0x18; lsrs #0x17`.

The queue's byte column undercounts four of them: BL is 4 bytes, not 2,
and the pool is part of the function (`sub_0800020C` 8, `sub_080079A0`
12, `sub_0800DFC0` 12, `sub_08016CF8` 14).

## Tier 1: m4a driver, reference C in tmc — finished 2026-09-24

All 58 matched, one per commit; `make check` MATCH throughout.
794 → 852 / 1001. Five parallel drafting agents produced the C (each
family's fresh member plus its ports); integration was serial.

What the source shapes turned out to be, for the next m4a batch:

- Every `ply_*` byte setter (`sub_0800253C` family, 20 functions) compiles
  byte-exact from tmc's two-statement shape
  `track->X = *track->cmdPtr; track->cmdPtr++;` — including the register
  split that differs between field offsets; it falls out of agbcc alone.
  `ply_xxx` (`sub_080024B8`) is the revision difference: it tail-calls one
  function pointer from the RAM jump table (`gUnk_02001D90` /
  `gUnk_02038DE0`), not tmc's double indirection nor pokeemerald's
  `cmdPtr += 4`.
- The queue's semantic names were partly wrong (the asm is ground truth):
  `sub_0800133C`/`sub_08001374` are **m4aMPlayAllStop/AllContinue**
  (player-table loops, count from `gNumMusicPlayersLow/High` linker
  symbols, not literals); `sub_080013B0` is the old revision's track-reinit
  (ImmInit-style, writes `flags=0x80; bendRange=2; volX=0x40;
  lfoSpeed=0x16; tone.type=1` and passes the *track* to ClearChain);
  `sub_08001234` = m4aSongNumStartOrChange, `sub_08001280` =
  m4aSongNumStartOrContinue. The high module's song-num family reads its
  **own EWRAM tables** (`gUnk_0200CA74`, `gUnk_0200CAA4`), not the ROM
  tables.
- Both `ply_memacc` copies were mis-scoped (jump table + 18 case bodies as
  `.byte` rows; 344 bytes each, not 54). The low copy hand-cut like
  `sub_0800F8D0`. The high copy `sub_0833BA00` is a fourth RAM-module
  function (EWRAM link base 0x02002F80, alias `_08344B84 → 0x0200C105` in
  `ram/aliases_0834.s`, `RAM_LINK_OVERRIDES` in `scripts/match.py`): its
  switch table embeds EWRAM addresses, off by exactly the module delta
  0x6338A80 under a ROM-address link.
- The two `svc 0x2A` stubs (`sub_0800151C`, `sub_0833ABDC`) are C after
  all: `void f(u32 *jt) { asm("swi 0x2A"); }` — the solved-walls entry 15
  inline-asm pattern; agbcc supplies the `bx lr`.
- Matching tricks that recurred: the dead write-back store
  (`mplayInfo->ident = ident;`, house trick from `src/sub_08001150.c`)
  decided MPlayContinue and TempoControl's allocation; PanpotControl's
  third parameter is `u8` (zero-extend), not tmc's `s8`; ClearModM needs
  the constant-first `flags = MPT_FLG_PITCHG | track->flags;` duplicated
  per arm so cross-jumping merges the tails; ModDepth/LFOSpeed need the
  CSE'd re-read `if (!track->mod)` rather than testing the parameter.
- Footgun hit once: a comment above a definition that mentions
  `sub_XXXXXXXX (` makes `progress.py`'s `decompiled()` regex credit the
  comment instead of the signature (`sub_0833ABDC`, fixed by rewording).

| # | Function | Bytes | Notes |
|---:|---|---:|---|
| 15 | `sub_0800253C` | 18 | `ply_xdeca` |
| 16 | `sub_08002550` | 18 | `ply_xsust`; port of `sub_0800253C` |
| 17 | `sub_08002564` | 18 | `ply_xrele`; port of `sub_0800253C` |
| 18 | `sub_08002590` | 18 | `ply_xleng`; port of `sub_0800253C` |
| 19 | `sub_080025A4` | 18 | `ply_xswee`; port of `sub_0800253C` |
| 20 | `sub_0833BBFC` | 18 | port of `sub_0800253C` |
| 21 | `sub_0833BC10` | 18 | port of `sub_0800253C` |
| 22 | `sub_0833BC24` | 18 | port of `sub_0800253C` |
| 23 | `sub_0833BC50` | 18 | port of `sub_0800253C` |
| 24 | `sub_0833BC64` | 18 | port of `sub_0800253C` |
| 25 | `sub_0800151C` | 4 | `MusicPlayerJumpTableCopy` |
| 26 | `sub_0833ABDC` | 4 | port of `sub_0800151C` |
| 27 | `sub_08002578` | 12 | `ply_xiecv` |
| 28 | `sub_08002584` | 12 | `ply_xiecl`; port of `sub_08002578` |
| 29 | `sub_0833BC38` | 12 | port of `sub_08002578` |
| 30 | `sub_0833BC44` | 12 | port of `sub_08002578` |
| 31 | `sub_08002514` | 18 | `ply_xtype` |
| 32 | `sub_08002528` | 18 | `ply_xatta`; port of `sub_08002514` |
| 33 | `sub_0833BBD4` | 18 | port of `sub_08002514` |
| 34 | `sub_0833BBE8` | 18 | port of `sub_08002514` |
| 35 | `sub_080024B8` | 14 | `ply_xxx` |
| 36 | `sub_0833BB78` | 14 | port of `sub_080024B8` |
| 37 | `sub_0800133C` | 38 | `m4aSongNumStop` |
| 38 | `sub_08001374` | 38 | `m4aSongNumContinue`; port of `sub_0800133C` |
| 39 | `sub_0833A9FC` | 38 | port of `sub_0800133C` |
| 40 | `sub_0833AA34` | 38 | port of `sub_0800133C` |
| 41 | `sub_08001134` | 24 | `MPlayContinue` |
| 42 | `sub_0833A7F4` | 24 | port of `sub_08001134` |
| 43 | `sub_08002498` | 26 | `ply_xcmd` |
| 44 | `sub_0833BB58` | 26 | port of `sub_08002498` |
| 45 | `sub_08002238` | 30 | `ClearModM` |
| 46 | `sub_0833B8F8` | 30 | port of `sub_08002238` |
| 47 | `sub_080020CC` | 36 | `m4aMPlayTempoControl` |
| 48 | `sub_0833B78C` | 36 | port of `sub_080020CC` |
| 49 | `sub_080020F4` | 104 | `m4aMPlayVolumeControl` |
| 50 | `sub_080021D0` | 104 | `m4aMPlayPanpotControl`; port of `sub_080020F4` |
| 51 | `sub_0833B7B4` | 104 | port of `sub_080020F4` |
| 52 | `sub_0833B890` | 104 | port of `sub_080020F4` |
| 53 | `sub_08002340` | 54 | `ply_memacc`; jump table or inline data |
| 54 | `sub_0833BA00` | 54 | port of `sub_08002340`; jump table or inline data |
| 55 | `sub_08002258` | 112 | `m4aMPlayModDepthSet` |
| 56 | `sub_080022CC` | 112 | `m4aMPlayLFOSpeedSet`; port of `sub_08002258` |
| 57 | `sub_0833B918` | 112 | port of `sub_08002258` |
| 58 | `sub_0833B98C` | 112 | port of `sub_08002258` |
| 59 | `sub_080024CC` | 62 | `ply_xwave` |
| 60 | `sub_0833BB8C` | 62 | port of `sub_080024CC` |
| 61 | `sub_08001234` | 66 | `m4aSongNumStart` |
| 62 | `sub_0833A8F4` | 66 | port of `sub_08001234` |
| 63 | `sub_08001BD0` | 68 | `CgbOscOff` |
| 64 | `sub_0833B290` | 68 | port of `sub_08001BD0` |
| 65 | `sub_080013B0` | 70 | `m4aMPlayAllStop` |
| 66 | `sub_0833AA70` | 70 | port of `sub_080013B0` |
| 67 | `sub_08001280` | 72 | `m4aSongNumStartOrChange` |
| 68 | `sub_0833A940` | 72 | port of `sub_08001280` |
| 69 | `sub_0800177C` | 80 | `SoundClear` |
| 70 | `sub_0833AE3C` | 80 | port of `sub_0800177C` |
| 71 | `sub_08001B28` | 160 | `MidiKeyToCgbFreq` |
| 72 | `sub_0833B1E8` | 160 | port of `sub_08001B28` |

## Tier 2: Near copies of matched functions

18 functions, 1180 bytes, about 3 hours.

| # | Function | Bytes | Notes |
|---:|---|---:|---|
| 73 | `sub_08000444` | 16 | from `sub_08005560` |
| 74 | `sub_08000478` | 16 | from `sub_08005560`; port of `sub_08000444` |
| 75 | `sub_08339B04` | 16 | from `sub_08005560`; port of `sub_08000444` |
| 76 | `sub_08339B38` | 16 | from `sub_08005560`; port of `sub_08000444` |
| 77 | `sub_08000214` | 10 | from `sub_08000260` |
| 78 | `sub_083398D4` | 10 | from `sub_08000260`; port of `sub_08000214` |
| 79 | `sub_0833DBE0` | 18 | from `sub_0833DBC8` |
| 80 | `sub_0801303C` | 104 | from `sub_08013878` |
| 81 | `sub_08013A7C` | 104 | from `sub_08013878`; port of `sub_0801303C` |
| 82 | `sub_08014400` | 104 | from `sub_08013878`; port of `sub_0801303C` |
| 83 | `sub_08009C00` | 72 | from `sub_08009BB4` |
| 84 | `sub_08341690` | 72 | from `sub_08009BB4`; port of `sub_08009C00` |
| 85 | `sub_08012F1C` | 122 | from `sub_080144F4` |
| 86 | `sub_08013114` | 110 | from `sub_0800F22C`; port of `sub_08012F1C` |
| 87 | `sub_080149A4` | 122 | from `sub_0800F22C`; port of `sub_08012F1C` |
| 88 | `sub_080101BC` | 88 | from `sub_080100CC` |
| 89 | `sub_0801021C` | 88 | from `sub_080100CC`; port of `sub_080101BC` |
| 90 | `sub_08015244` | 92 | from `sub_08013878` |

## Tier 3: Sprite-callback family

29 functions, 3280 bytes, about 27 hours.

| # | Function | Bytes | Notes |
|---:|---|---:|---|
| 91 | `sub_0800792C` | 14 | helper, 13 callers |
| 92 | `sub_0833FF84` | 14 | port of `sub_0800792C`; helper, 12 callers |
| 93 | `sub_08007950` | 26 | helper, 13 callers |
| 94 | `sub_0833FFA8` | 26 | port of `sub_08007950`; helper, 12 callers |
| 95 | `sub_0800B5D4` | 28 |  |
| 96 | `sub_08342DA4` | 28 | port of `sub_0800B5D4` |
| 97 | `sub_0800B384` | 62 |  |
| 98 | `sub_08342B54` | 62 | port of `sub_0800B384` |
| 99 | `sub_083429E8` | 36 |  |
| 100 | `sub_083429B8` | 38 |  |
| 101 | `sub_0800B030` | 86 |  |
| 102 | `sub_08342948` | 86 | port of `sub_0800B030` |
| 103 | `sub_0800AE94` | 110 |  |
| 104 | `sub_083427DC` | 110 | port of `sub_0800AE94` |
| 105 | `sub_0800B46C` | 178 |  |
| 106 | `sub_08342C3C` | 178 | port of `sub_0800B46C` |
| 107 | `sub_08342F4C` | 90 |  |
| 108 | `sub_0834288C` | 100 |  |
| 109 | `sub_0800B0A0` | 104 |  |
| 110 | `sub_0800B120` | 108 |  |
| 111 | `sub_08342A14` | 116 |  |
| 112 | `sub_0800B8EC` | 256 |  |
| 113 | `sub_08342FF0` | 256 | port of `sub_0800B8EC` |
| 114 | `sub_0800AF44` | 140 |  |
| 115 | `sub_08342E28` | 156 |  |
| 116 | `sub_0800B7E0` | 182 |  |
| 117 | `sub_0800BA38` | 184 |  |
| 118 | `sub_0800B658` | 244 |  |
| 119 | `sub_0800B1A4` | 262 |  |

## Tier 4: Pairs to decompile once and port

76 functions, 6224 bytes, about 39 hours.

| # | Function | Bytes | Notes |
|---:|---|---:|---|
| 120 | `sub_08009BA4` | 16 |  |
| 121 | `sub_08341634` | 16 | port of `sub_08009BA4` |
| 122 | `sub_08000340` | 20 |  |
| 123 | `sub_08339A00` | 20 | port of `sub_08000340` |
| 124 | `sub_08000410` | 20 |  |
| 125 | `sub_08339AD0` | 20 | port of `sub_08000410` |
| 126 | `sub_080031B0` | 22 |  |
| 127 | `sub_0833C6F4` | 22 | port of `sub_080031B0` |
| 128 | `sub_08000328` | 24 |  |
| 129 | `sub_083399E8` | 24 | port of `sub_08000328` |
| 130 | `sub_08002618` | 24 |  |
| 131 | `sub_0833BCD8` | 24 | port of `sub_08002618` |
| 132 | `sub_08003EF0` | 28 |  |
| 133 | `sub_0833D1F4` | 28 | port of `sub_08003EF0` |
| 134 | `sub_080057E8` | 28 |  |
| 135 | `sub_0833E2E4` | 28 | port of `sub_080057E8` |
| 136 | `sub_08003D6C` | 32 |  |
| 137 | `sub_0833D070` | 32 | port of `sub_08003D6C` |
| 138 | `sub_08008B40` | 36 |  |
| 139 | `sub_08340CB0` | 36 | port of `sub_08008B40` |
| 140 | `sub_08008B6C` | 36 |  |
| 141 | `sub_08340CDC` | 36 | port of `sub_08008B6C` |
| 142 | `sub_0800BA0C` | 36 |  |
| 143 | `sub_08343110` | 36 | port of `sub_0800BA0C` |
| 144 | `sub_080032AC` | 40 |  |
| 145 | `sub_0833C7F0` | 40 | port of `sub_080032AC` |
| 146 | `sub_08003E5C` | 40 |  |
| 147 | `sub_0833D160` | 40 | port of `sub_08003E5C` |
| 148 | `sub_0800A008` | 42 |  |
| 149 | `sub_08341A98` | 42 | port of `sub_0800A008` |
| 150 | `sub_08010134` | 44 |  |
| 151 | `sub_08010164` | 44 | port of `sub_08010134` |
| 152 | `sub_080089EC` | 48 |  |
| 153 | `sub_08340B5C` | 48 | port of `sub_080089EC` |
| 154 | `sub_08000224` | 52 |  |
| 155 | `sub_083398E4` | 52 | port of `sub_08000224` |
| 156 | `sub_08003DF4` | 52 |  |
| 157 | `sub_0833D0F8` | 52 | port of `sub_08003DF4` |
| 158 | `sub_08003E28` | 52 |  |
| 159 | `sub_0833D12C` | 52 | port of `sub_08003E28` |
| 160 | `sub_08007A44` | 52 |  |
| 161 | `sub_0834009C` | 52 | port of `sub_08007A44` |
| 162 | `sub_08004E58` | 66 |  |
| 163 | `sub_0833DAD8` | 66 | port of `sub_08004E58` |
| 164 | `sub_0800A5E4` | 68 |  |
| 165 | `sub_08342030` | 68 | port of `sub_0800A5E4` |
| 166 | `sub_0800C98C` | 136 |  |
| 167 | `sub_0800CA20` | 136 | port of `sub_0800C98C` |
| 168 | `sub_083432F4` | 136 | port of `sub_0800C98C` |
| 169 | `sub_08343388` | 136 | port of `sub_0800C98C` |
| 170 | `sub_0800A478` | 84 |  |
| 171 | `sub_08341F08` | 84 | port of `sub_0800A478` |
| 172 | `sub_08005808` | 90 |  |
| 173 | `sub_0833E304` | 90 | port of `sub_08005808` |
| 174 | `sub_0800F85C` | 90 | jump table or inline data |
| 175 | `sub_083448F4` | 90 | port of `sub_0800F85C`; jump table or inline data |
| 176 | `sub_08004504` | 94 |  |
| 177 | `sub_0833D700` | 94 | port of `sub_08004504` |
| 178 | `sub_08004568` | 98 |  |
| 179 | `sub_0833D764` | 98 | port of `sub_08004568` |
| 180 | `sub_080059A8` | 104 |  |
| 181 | `sub_0833E4A4` | 104 | port of `sub_080059A8` |
| 182 | `sub_08003E84` | 106 |  |
| 183 | `sub_0833D188` | 106 | port of `sub_08003E84` |
| 184 | `sub_0800592C` | 110 |  |
| 185 | `sub_0833E428` | 110 | port of `sub_0800592C` |
| 186 | `sub_0800E640` | 168 | jump table or inline data |
| 187 | `sub_08364730` | 168 | port of `sub_0800E640`; jump table or inline data |
| 188 | `sub_08005FA8` | 186 | jump table or inline data |
| 189 | `sub_0833EAA4` | 186 | port of `sub_08005FA8`; jump table or inline data |
| 190 | `sub_0800306C` | 258 | jump table or inline data |
| 191 | `sub_0833C5B0` | 258 | port of `sub_0800306C`; jump table or inline data |
| 192 | `sub_08006094` | 286 | jump table or inline data |
| 193 | `sub_0833EB90` | 286 | port of `sub_08006094`; jump table or inline data |
| 194 | `sub_0800E75C` | 286 | jump table or inline data |
| 195 | `sub_0800E8A0` | 290 | port of `sub_0800E75C`; jump table or inline data |

## Tier 5: Singletons

26 functions, 3262 bytes, about 44 hours.

| # | Function | Bytes | Notes |
|---:|---|---:|---|
| 196 | `sub_0800CB5C` | 18 |  |
| 197 | `sub_0800EA3C` | 20 |  |
| 198 | `sub_0800BBDC` | 26 |  |
| 199 | `sub_08012354` | 38 |  |
| 200 | `sub_08016568` | 46 |  |
| 201 | `sub_08010768` | 48 |  |
| 202 | `sub_080107A4` | 48 |  |
| 203 | `sub_08002718` | 56 | jump table or inline data |
| 204 | `sub_0800BAFC` | 56 |  |
| 205 | `sub_080069D8` | 58 |  |
| 206 | `sub_0800CC4C` | 66 |  |
| 207 | `sub_0800CC00` | 68 |  |
| 208 | `sub_08012784` | 78 |  |
| 209 | `sub_08004BCC` | 94 |  |
| 210 | `sub_08014BA4` | 122 |  |
| 211 | `sub_08010A04` | 126 |  |
| 212 | `sub_08015060` | 126 |  |
| 213 | `sub_080126BC` | 130 |  |
| 214 | `sub_08012E48` | 134 |  |
| 215 | `sub_0801037C` | 142 |  |
| 216 | `sub_08341F64` | 160 |  |
| 217 | `sub_08003C78` | 192 |  |
| 218 | `sub_0800A4D4` | 222 |  |
| 219 | `sub_083642FC` | 372 | jump table or inline data |
| 220 | `sub_08008160` | 382 | jump table or inline data |
| 221 | `sub_080132F8` | 434 | jump table or inline data |

