#include "global.h"
#include "gba/m4a_internal.h"
#include "variables.h"

/* This file owns the main program's one contiguous EWRAM run
   0x02000DE0-0x02022E20 (issue 5 step 3, run rule): the m4a driver state
   (gSoundInfo through the MusicPlayerInfo players and gMPlayMemAccArea),
   the game/menu/link state (0x02002090-0x020021F0), the track map buffers
   and scroll registers (0x02002200-0x02022DF8), and the palette-fade state
   (gPaletteBufferDirty, gFadeActive, gPaletteFadeSteps). Every identified variable in
   that span is defined here in address order; the static gap arrays pad
   only the addresses no identified symbol covers. ldscript.ld's
   .bss_globals places the section at the run's start (0x02000DE0).

   Variables moved here from their old owners (definitions unchanged):
   src/race/RunRace.c, src/car/UpdateCarSurface.c, src/menu/MainMenuLoop.c,
   src/link/ExchangeLinkInput.c, src/car/update.c, src/track/track.c, and
   src/system/MainVBlankCallback.c (gVBlankWorkPhase, the first RAM
   variable ever moved into C, whose EWRAM_DATA pattern the rest of this
   file follows); the rest came off symbols.ld lines, now deleted.

   Two symbols.ld lines stay as absolute aliases inside the map buffers,
   where no separate bytes exist: gUnk_0200CAD0 (inside gBg2MapBuffer) and
   gUnk_02022823 (inside gCellMapBuffer); nothing references either. */

/* ---- m4a driver state (0x02000DE0-0x02002070) ----
   gSoundInfo is one struct SoundInfo (0xFB0 bytes: the header, the twelve
   SoundChannels and the 0xC60-byte pcmBuffer), which lands exactly on
   gMPlayJumpTable. */

EWRAM_DATA struct SoundInfo gSoundInfo = { 0 };
#if PORTABLE
/* Hosted: the full 0x24-entry jump table the ROM template copy fills
   (MPlayJumpTableCopy). On the GBA the run is 0x22 entries followed by
   two pointer words the same copy installs through its overrun:
   template entries 0x22 (RealClearChain) and 0x23 (SoundMainBTM, the
   0x40-byte clear) land exactly on gUnk_02001E18/gUnk_02001E1C, the
   pointers src/sound/m4a_clear.c's ClearChain/Clear64byte call through.
   Hosted, the table is one array and those two names alias its tail
   (m4a_clear.c), so the install the ROM performs with one copy works
   the same way and the copy stays in bounds. */
EWRAM_DATA MPlayFunc gMPlayJumpTable[0x24] = { 0 };
#else
EWRAM_DATA MPlayFunc gMPlayJumpTable[0x22] = { 0 };
/* ClearChain/Clear64byte call through these (src/sound/m4a_clear.c). */
EWRAM_DATA void (*gUnk_02001E18)(u32) = 0;
EWRAM_DATA void (*gUnk_02001E1C)(void *) = 0;
#endif
EWRAM_DATA struct CgbChannel gCgbChans[4] = { 0 };
EWRAM_DATA struct MusicPlayerInfo gBgMusicPlayer = { 0 };
EWRAM_DATA struct MusicPlayerInfo gEngineSoundPlayer = { 0 };
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_SE2 = { 0 };
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_SE4 = { 0 };
EWRAM_DATA u8 gMPlayMemAccArea[0x10] = { 0 };
EWRAM_DATA struct MusicPlayerInfo gMPlayInfo_SE3 = { 0 };
static EWRAM_DATA u8 gap02002070[0x20] = { 0 };

/* ---- game, menu and link state (0x02002090-0x020021F1) ---- */

EWRAM_DATA u8 gNumCars[8] = { 0 };
EWRAM_DATA u8 gChallengeScore = 0;
EWRAM_DATA s32 gFrameCounter = 0;
EWRAM_DATA u16 gPlayerKeys[4] = { 0 };
EWRAM_DATA u8 gPreRaceSimActive = 0;
static EWRAM_DATA u8 gap020020A9[0x3] = { 0 };
EWRAM_DATA u8 gNumLinkPlayers[8] = { 0 };
EWRAM_DATA u8 gUnk_020020B4 = 0;
static EWRAM_DATA u8 gap020020B5[0x3] = { 0 };
EWRAM_DATA u16 gUnk_020020B8 = 0;
static EWRAM_DATA u8 gap020020BA[0x2] = { 0 };
EWRAM_DATA u8 gLapProgressAdvanced = 0;
static EWRAM_DATA u8 gap020020BD[0x3] = { 0 };
EWRAM_DATA u8 gVBlankWorkDone = 0;
static EWRAM_DATA u8 gap020020C1[0x3] = { 0 };
EWRAM_DATA u8 gRaceStarted = 0;
static EWRAM_DATA u8 gap020020C5[0x7] = { 0 };
EWRAM_DATA u8 gTrackId = 0;
static EWRAM_DATA u8 gap020020CD[0x7] = { 0 };
EWRAM_DATA u32 gRngState = 0;
static EWRAM_DATA u8 gap020020D8[0x4] = { 0 };
EWRAM_DATA u8 gIsLinkRace = 0;
static EWRAM_DATA u8 gap020020DD[0x3] = { 0 };
EWRAM_DATA u8 gIsDemo = 0;
static EWRAM_DATA u8 gap020020E1[0xB] = { 0 };
EWRAM_DATA u8 gUnk_020020EC = 0;
static EWRAM_DATA u8 gap020020ED[0x3] = { 0 };
EWRAM_DATA u8 gNewTrackRecord = 0;
static EWRAM_DATA u8 gap020020F1[0xF] = { 0 };
EWRAM_DATA u32 gCamera[9] = { 0 };
EWRAM_DATA u16 gVBlankCounter = 0;
static EWRAM_DATA u8 gap02002126[0x1E] = { 0 };
EWRAM_DATA u8 gExitRaceLoop = 0;
static EWRAM_DATA u8 gap02002145[0x3] = { 0 };
EWRAM_DATA u32 gUnk_02002148 = 0;
static EWRAM_DATA u8 gap0200214C[0x4] = { 0 };
EWRAM_DATA u8 gUnk_02002150[0xC] = { 0 };
EWRAM_DATA u8 gGameMode = 0;
static EWRAM_DATA u8 gap0200215D[0x3] = { 0 };
EWRAM_DATA u8 gUnk_02002160[0xC] = { 0 };
EWRAM_DATA u16 gLinkVBlankTimeout = 0;
static EWRAM_DATA u8 gap0200216E[0x2] = { 0 };
EWRAM_DATA u16 gLinkTxSeqNum = 0;
static EWRAM_DATA u8 gap02002172[0x6] = { 0 };
EWRAM_DATA u16 gLinkPhase0RecvWords[6] = { 0 };
EWRAM_DATA u8 gNumLaps = 0;
static EWRAM_DATA u8 gap02002185[0x33] = { 0 };
EWRAM_DATA u8 gVBlankWorkPhase = 0;
static EWRAM_DATA u8 gap020021B9[0x3] = { 0 };
EWRAM_DATA u8 gRaceAborted = 0;
static EWRAM_DATA u8 gap020021BD[0x7] = { 0 };
EWRAM_DATA u8 gBgScrollUpdateEnabled = 0;
static EWRAM_DATA u8 gap020021C5[0xB] = { 0 };
EWRAM_DATA u32 gUnk_020021D0[0x4] = { 0 };
EWRAM_DATA u8 gRaceEndState = 0;
static EWRAM_DATA u8 gap020021E1[0xB] = { 0 };
EWRAM_DATA u8 gUnk_020021EC[0x4] = { 0 };
EWRAM_DATA u8 gUnk_020021F0 = 0;
static EWRAM_DATA u8 gap020021F1[0xF] = { 0 };

/* ---- track map buffers, scroll registers and fade state
        (0x02002200-0x02022E20) ----
   The three RLE buffers are sized to the next symbol (0x9A0C, 0x9A0C and
   0xD748 bytes), which the widest track's decoded streams (19715, 19715
   and 27555 halfwords) exactly fill. */

EWRAM_DATA u32 gTrackMapWidth = 0;
static EWRAM_DATA u8 gap02002204[0x4] = { 0 };
EWRAM_DATA u8 *gBg3MapPtr = 0;
static EWRAM_DATA u8 gap0200220C[0x4] = { 0 };
EWRAM_DATA u8 *gBg2Metatiles = 0;
static EWRAM_DATA u8 gap02002214[0x4] = { 0 };
EWRAM_DATA u8 gMapScrollHalfMetatile = 0;
static EWRAM_DATA u8 gap02002219[0x3] = { 0 };
EWRAM_DATA u8 *gBg3Metatiles = 0;
EWRAM_DATA u16 gBg3MapBuffer[0x4D06] = { 0 };
EWRAM_DATA u32 gBg2ScrollY = 0;
EWRAM_DATA u32 gBgMapWidth = 0;
EWRAM_DATA u16 gUnk_0200BC34 = 0;
static EWRAM_DATA u8 gap0200BC36[0x12] = { 0 };
EWRAM_DATA u32 gBg1ScrollX = 0;
EWRAM_DATA u32 gBg1ScrollY = 0;
EWRAM_DATA u8 *gCellMapPtr = 0;
EWRAM_DATA u8 *gBg2MapPtr = 0;
static EWRAM_DATA u8 gap0200BC58[0x18] = { 0 };
EWRAM_DATA u16 gBg2MapBuffer[0x4D06] = { 0 };
EWRAM_DATA u32 gUnk_0201567C = 0;
static EWRAM_DATA u8 gap02015680[0x10] = { 0 };
EWRAM_DATA u16 gCellMapBuffer[0x6BA4] = { 0 };
EWRAM_DATA u32 gBgMapWidth2 = 0;
static EWRAM_DATA u8 gap02022DDC[0x4] = { 0 };
EWRAM_DATA u32 gBg3ScrollX = 0;
EWRAM_DATA u16 gUnk_02022DE4 = 0;
static EWRAM_DATA u8 gap02022DE6[0x2] = { 0 };
EWRAM_DATA u32 gBg3ScrollY = 0;
EWRAM_DATA const u8 *gSurfaceTablePtr = 0;
EWRAM_DATA u32 gUnk_02022DF0 = 0;
EWRAM_DATA u16 gUnk_02022DF4 = 0;
static EWRAM_DATA u8 gap02022DF6[0x2] = { 0 };
EWRAM_DATA u32 gBg2ScrollX = 0;
static EWRAM_DATA u8 gap02022DFC[0x14] = { 0 };
EWRAM_DATA u8 gPaletteBufferDirty = 0;
static EWRAM_DATA u8 gap02022E11[0x3] = { 0 };
EWRAM_DATA u8 gFadeActive = 0;
static EWRAM_DATA u8 gap02022E15[0x3] = { 0 };
EWRAM_DATA u16 gPaletteFadeSteps = 0;
static EWRAM_DATA u8 gap02022E1A[0x6] = { 0 };
