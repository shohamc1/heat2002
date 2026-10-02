#include "global.h"
#include "gba/defines.h"
#include "variables.h"

/* This file owns the HUD/sprite-counters EWRAM runs 0x02024C40-0x02025270
   and 0x02025380-0x020253F8: the depth-sorted sprite queue and its sort
   buffers, the OAM entry/affine counters, the sprite order table, the track
   cues, the lap/race timers and record tables, the countdown, the link-menu
   key state and the finish order. Every identified variable in the two
   spans is defined here in address order; the static gap arrays pad only
   the addresses no identified symbol covers. ldscript.ld's .bss_hud_globals
   places the first section at 0x02024C40 and.bss_hud_globals_2 the second
   at 0x02025380.

   gDepthSortedSprites is the 64 12-byte depth-sorted sprite entries; the
   gap behind it holds gUnk_02024F40 (defined here; only
   src/dead/sub_0800E734.c reads it, as the sprite rotation index into
   gSinTable) and, from 0x02024F50 on, the second OAM sort buffer
   gSecondOamSortBuffer (ResetSpriteQueues stores its address in oam.c's
   gSecondOamSortCursor). gSpriteOrderTable is sized to gUnk_020251F0; its
   first 0x40 entries are used. Each track-record table holds one entry per
   track (12, gTrackId's range). gFinishedCarOrder holds one entry per car
   (24, gNumCars' maximum; DrawLinkFinishTimes walks gNumFinishedCars of
   them). */

EWRAM_DATA struct DepthSortedSprite gDepthSortedSprites[0x40] = { 0 };
EWRAM_DATA u16 gUnk_02024F40 = 0;
static EWRAM_DATA u8 hud_gap24F42[0xE] = { 0 };
/* The second OAM sort buffer (0x02024F50-0x02025150): ResetSpriteQueues
   stores this address in oam.c's gSecondOamSortCursor. */
EWRAM_DATA u8 gSecondOamSortBuffer[0x200] = { 0 };
EWRAM_DATA u8 gOamEntryCount = 0;
static EWRAM_DATA u8 hud_gap5151[0x3] = { 0 };
EWRAM_DATA u8 gOamAffineCount = 0;
static EWRAM_DATA u8 hud_gap5155[0xB] = { 0 };
EWRAM_DATA u16 gSpriteOrderTable[0x48] = { 0 };
EWRAM_DATA u16 gUnk_020251F0 = 0;
static EWRAM_DATA u8 hud_gap51F2[0x2] = { 0 };
EWRAM_DATA u8 gTireWearBlinkCounter = 0;
static EWRAM_DATA u8 hud_gap51F5[0x3] = { 0 };
EWRAM_DATA u16 gUnk_020251F8 = 0;
static EWRAM_DATA u8 hud_gap51FA[0x2] = { 0 };
EWRAM_DATA u16 gLapSec = 0;
static EWRAM_DATA u8 hud_gap51FE[0x2] = { 0 };
EWRAM_DATA u16 gTrackRecordSec[12] = { 0 };
EWRAM_DATA u16 gLapMin = 0;
static EWRAM_DATA u8 hud_gap521A[0x2] = { 0 };
EWRAM_DATA s32 gCountdownSeconds = 0;
EWRAM_DATA u16 gRaceSec = 0;
static EWRAM_DATA u8 hud_gap5222[0x2] = { 0 };
EWRAM_DATA u16 gRaceMs = 0;
static EWRAM_DATA u8 hud_gap5226[0x2] = { 0 };
EWRAM_DATA u8 gUnk_02025228 = 0;
static EWRAM_DATA u8 hud_gap5229[0x3] = { 0 };
EWRAM_DATA u16 gUnk_0202522C = 0;
static EWRAM_DATA u8 hud_gap522E[0xA] = { 0 };
EWRAM_DATA u8 gUnk_02025238 = 0;
static EWRAM_DATA u8 hud_gap5239[0x3] = { 0 };
EWRAM_DATA u8 gUnk_0202523C = 0;
static EWRAM_DATA u8 hud_gap523D[0x3] = { 0 };
EWRAM_DATA u8 gDefaultCountdownSeconds = 0;
static EWRAM_DATA u8 hud_gap5241[0x3] = { 0 };
EWRAM_DATA u8 gUnk_02025244 = 0;
static EWRAM_DATA u8 hud_gap5245[0x3] = { 0 };
EWRAM_DATA u8 gPauseMenuCursor = 0;
static EWRAM_DATA u8 hud_gap5249[0x3] = { 0 };
EWRAM_DATA s8 gTrackCueId = 0;
static EWRAM_DATA u8 hud_gap524D[0x3] = { 0 };
EWRAM_DATA u8 gUnk_02025250 = 0;
static EWRAM_DATA u8 hud_gap5251[0x3] = { 0 };
EWRAM_DATA u16 gUnk_02025254 = 0;
static EWRAM_DATA u8 hud_gap5256[0x2] = { 0 };
EWRAM_DATA u16 gLinkMenuKeysPressed = 0;
static EWRAM_DATA u8 hud_gap525A[0x2] = { 0 };
EWRAM_DATA u8 gUnk_0202525C = 0;
static EWRAM_DATA u8 hud_gap525D[0x3] = { 0 };
EWRAM_DATA u16 gRaceMin = 0;
static EWRAM_DATA u8 hud_gap5262[0xE] = { 0 };

EWRAM_DATA2 u16 gTrackRecordMin[12] = { 0 };
EWRAM_DATA2 u16 gUnk_02025398 = 0;
static EWRAM_DATA2 u8 hud_gap539A[0x2] = { 0 };
EWRAM_DATA2 u8 gMenuBlinkCounter = 0;
static EWRAM_DATA2 u8 hud_gap539D[0x3] = { 0 };
EWRAM_DATA2 u16 gTrackRecordMs[12] = { 0 };
#if PORTABLE
EWRAM_DATA2 const u8 *gTrackCueList = 0;
#else
EWRAM_DATA2 u32 gTrackCueList = 0;
#endif
EWRAM_DATA2 u16 gLinkMenuKeysPrev = 0;
static EWRAM_DATA2 u8 hud_gap53BE[0x2] = { 0 };
EWRAM_DATA2 u32 gCountdownMs = 0;
EWRAM_DATA2 u8 gLinkMenuPlayerIndex = 0;
static EWRAM_DATA2 u8 hud_gap53C5[0x3] = { 0 };
EWRAM_DATA2 u8 gUnk_020253C8 = 0;
static EWRAM_DATA2 u8 hud_gap53C9[0x3] = { 0 };
EWRAM_DATA2 u16 gLapMs = 0;
static EWRAM_DATA2 u8 hud_gap53CE[0x2] = { 0 };
EWRAM_DATA2 const struct TrackSeg *gTrackSegs = 0;
EWRAM_DATA2 u8 gNumFinishedCars = 0;
static EWRAM_DATA2 u8 hud_gap53D5[0xB] = { 0 };
EWRAM_DATA2 u8 gFinishedCarOrder[0x18] = { 0 };
