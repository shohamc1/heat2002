#include "global.h"
#include "gba/defines.h"
#include "variables.h"

/* This file owns the high module's two race-timer EWRAM runs (issue 5
   step 3, run rule), the module twin of src/hud/globals.c's second run:
   the lap/race timers and countdown (0x0203B6A8-0x0203B708), and the
   track-record tables through the finish order (0x0203B810-0x0203B870).
   The 0x108-byte span between them (0x0203B708-0x0203B810) carries no
   identified symbol. Each track-record table holds one entry per track
   (12, gModule_TrackId's range); gModule_FinishedCarOrder holds one
   entry per module car (8). The dead-only symbols inside
   (gUnk_0203B6F4, gUnk_0203B700, gUnk_0203B82C: only src/dead/
   sub_0833DAD8.c and sub_0833E3F8.c touch them) are defined here with
   the types their externs declare, no symbols.ld lines left.
   ldscript.ld's .module_ewram_data_hud and .module_ewram_data_hud_2
   place the two sections. */

MODULE_EWRAM_DATA u16 gModule_LapSec = 0;
static MODULE_EWRAM_DATA u8 hud_gapB6AA[0x6] = { 0 };
MODULE_EWRAM_DATA u16 gModule_TrackRecordSec[0xC] = { 0 };
/* gModule_LapMin, gModule_LapMs and the race timers stay arrays, read
   at [0]: their main-program twins are scalars, but declaring these as
   scalars changes the module's timer code. */
MODULE_EWRAM_DATA u16 gModule_LapMin[2] = { 0 };
MODULE_EWRAM_DATA u32 gModule_CountdownSeconds = 0;
MODULE_EWRAM_DATA u16 gModule_RaceSec[2] = { 0 };
MODULE_EWRAM_DATA u16 gModule_RaceMs[2] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_0203B6D8 = 0;
static MODULE_EWRAM_DATA u8 hud_gapB6D9[0x3] = { 0 };
MODULE_EWRAM_DATA u16 gUnk_0203B6DC = 0;
static MODULE_EWRAM_DATA u8 hud_gapB6DE[0xA] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_0203B6E8 = 0;
static MODULE_EWRAM_DATA u8 hud_gapB6E9[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_0203B6EC = 0;
static MODULE_EWRAM_DATA u8 hud_gapB6ED[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_0203B6F0 = 0;
static MODULE_EWRAM_DATA u8 hud_gapB6F1[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_0203B6F4 = 0;
static MODULE_EWRAM_DATA u8 hud_gapB6F5[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_0203B6F8 = 0;
static MODULE_EWRAM_DATA u8 hud_gapB6F9[0x3] = { 0 };
MODULE_EWRAM_DATA u16 gUnk_0203B6FC = 0;
static MODULE_EWRAM_DATA u8 hud_gapB6FE[0x2] = { 0 };
/* sub_0833E4A4 draws the countdown's digit pair through it */
MODULE_EWRAM_DATA u8 gUnk_0203B700[0x4] = { 0 };
MODULE_EWRAM_DATA u16 gModule_RaceMin[2] = { 0 };
static MODULE_EWRAM_DATA u8 hud_gapB708[0x4] = { 0 };

MODULE_EWRAM_DATA2 u16 gModule_TrackRecordMin[0xC] = { 0 };
MODULE_EWRAM_DATA2 u16 gUnk_0203B828 = 0;
static MODULE_EWRAM_DATA2 u8 hud_gapB82A[0x2] = { 0 };
MODULE_EWRAM_DATA2 u8 gUnk_0203B82C = 0;
static MODULE_EWRAM_DATA2 u8 hud_gapB82D[0x3] = { 0 };
MODULE_EWRAM_DATA2 u16 gModule_TrackRecordMs[0xC] = { 0 };
MODULE_EWRAM_DATA2 u16 gUnk_0203B848 = 0;
static MODULE_EWRAM_DATA2 u8 hud_gapB84A[0x2] = { 0 };
MODULE_EWRAM_DATA2 u32 gModule_CountdownMs = 0;
MODULE_EWRAM_DATA2 u8 gUnk_0203B850 = 0;
static MODULE_EWRAM_DATA2 u8 hud_gapB851[0x3] = { 0 };
MODULE_EWRAM_DATA2 u8 gUnk_0203B854 = 0;
static MODULE_EWRAM_DATA2 u8 hud_gapB855[0x3] = { 0 };
MODULE_EWRAM_DATA2 u16 gModule_LapMs[4] = { 0 };
MODULE_EWRAM_DATA2 const struct TrackSeg *gModule_TrackSegs = 0;
MODULE_EWRAM_DATA2 u8 gModule_NumFinishedCars = 0;
static MODULE_EWRAM_DATA2 u8 hud_gapB865[0x3] = { 0 };
MODULE_EWRAM_DATA2 u8 gModule_FinishedCarOrder[8] = { 0 };
