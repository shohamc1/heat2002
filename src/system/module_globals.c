#include "global.h"
#include "gba/defines.h"
#include "variables.h"

/* This file owns the high module's game/link/track/fade EWRAM run
   0x020390A0-0x0203ACD0, the module twin of src/system/globals.c's run: the
   race state (gModule_NumCars through gModule_RaceEndState, gModule_Camera,
   the link state), the track pointer block (gModule_TrackMapWidth through
   gModule_Bg2ScrollX, mostly src/track/module_track.c's map pointers), and
   the palette-fade state (the two 0xC00-byte buffers plus the 0x200-byte
   staging buffer, src/palette/module_fade.c's variables). Every identified
   variable in the span is defined here in address order; the static gap
   arrays pad only the addresses no identified symbol covers, including the
   one dead-only symbol (gUnk_020390E4, defined here for the dead files that
   use it). ldscript.ld's .module_ewram_data_system places the section at
   0x020390A0. */

MODULE_EWRAM_DATA u8 gModule_NumCars[8] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_020390A8 = 0;
static MODULE_EWRAM_DATA u8 sys_gap90A9[0x3] = { 0 };
MODULE_EWRAM_DATA s32 gModule_FrameCounter = 0;
MODULE_EWRAM_DATA u16 gUnk_020390B0[4] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_020390B8 = 0;
static MODULE_EWRAM_DATA u8 sys_gap90B9[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gModule_NumLinkPlayers[8] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_020390C4 = 0;
static MODULE_EWRAM_DATA u8 sys_gap90C5[0x7] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_020390CC = 0;
static MODULE_EWRAM_DATA u8 sys_gap90CD[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gModule_VBlankWorkDone = 0;
static MODULE_EWRAM_DATA u8 sys_gap90D1[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gModule_RaceStarted = 0;
static MODULE_EWRAM_DATA u8 sys_gap90D5[0x7] = { 0 };
MODULE_EWRAM_DATA u8 gModule_TrackId = 0;
static MODULE_EWRAM_DATA u8 sys_gap90DD[0x7] = { 0 };
/* the module's random seed (variables.h declares it; sub_0833BCBC
   steps it) */
MODULE_EWRAM_DATA u32 gUnk_020390E4 = 0;
static MODULE_EWRAM_DATA u8 sys_gap90E8[0x4] = { 0 };
MODULE_EWRAM_DATA u8 gModule_IsLinkRace = 0;
static MODULE_EWRAM_DATA u8 sys_gap90ED[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gModule_IsDemo = 0;
static MODULE_EWRAM_DATA u8 sys_gap90F1[0xB] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_020390FC = 0;
static MODULE_EWRAM_DATA u8 sys_gap90FD[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_02039100 = 0;
static MODULE_EWRAM_DATA u8 sys_gap9101[0xF] = { 0 };
MODULE_EWRAM_DATA u32 gModule_Camera[9] = { 0 };
MODULE_EWRAM_DATA u16 gModule_VBlanksThisFrame = 0;
static MODULE_EWRAM_DATA u8 sys_gap9136[0x1E] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_02039154 = 0;
static MODULE_EWRAM_DATA u8 sys_gap9155[0x3] = { 0 };
MODULE_EWRAM_DATA u32 gUnk_02039158 = 0;
static MODULE_EWRAM_DATA u8 sys_gap915C[0x4] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_02039160[0xC] = { 0 };
MODULE_EWRAM_DATA u8 gModule_GameMode = 0;
static MODULE_EWRAM_DATA u8 sys_gap916D[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_02039170[0xC] = { 0 };
MODULE_EWRAM_DATA u16 gUnk_0203917C = 0;
static MODULE_EWRAM_DATA u8 sys_gap917E[0x2] = { 0 };
MODULE_EWRAM_DATA u16 gModule_LinkTxSeqNum = 0;
static MODULE_EWRAM_DATA u8 sys_gap9182[0x6] = { 0 };
MODULE_EWRAM_DATA u16 gUnk_02039188[4] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_02039190 = 0;
static MODULE_EWRAM_DATA u8 sys_gap9191[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_02039194 = 0;
static MODULE_EWRAM_DATA u8 sys_gap9195[0x33] = { 0 };
MODULE_EWRAM_DATA u8 gModule_VBlankWorkPhase = 0;
static MODULE_EWRAM_DATA u8 sys_gap91C9[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_020391CC = 0;
static MODULE_EWRAM_DATA u8 sys_gap91CD[0x7] = { 0 };
MODULE_EWRAM_DATA u8 gModule_BgScrollUpdateEnabled = 0;
static MODULE_EWRAM_DATA u8 sys_gap91D5[0xB] = { 0 };
MODULE_EWRAM_DATA u32 gUnk_020391E0[4] = { 0 };
MODULE_EWRAM_DATA u8 gModule_RaceEndState = 0;
static MODULE_EWRAM_DATA u8 sys_gap91F1[0xF] = { 0 };
MODULE_EWRAM_DATA struct Car *gModule_CarOrder[6] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_02039218[4] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_0203921C = 0;
static MODULE_EWRAM_DATA u8 sys_gap921D[0x3] = { 0 };
MODULE_EWRAM_DATA u32 gModule_TrackMapWidth = 0;
MODULE_EWRAM_DATA const u16 *gModule_TrackUnk28 = 0;
MODULE_EWRAM_DATA u16 *gModule_Bg3MapPtr = 0;
MODULE_EWRAM_DATA u16 *gModule_Bg2Metatiles = 0;
static MODULE_EWRAM_DATA u8 sys_gap9230[0x4] = { 0 };
MODULE_EWRAM_DATA u8 gModule_MapScrollHalfMetatile = 0;
static MODULE_EWRAM_DATA u8 sys_gap9235[0x3] = { 0 };
MODULE_EWRAM_DATA u16 *gModule_Bg3Metatiles = 0;
static MODULE_EWRAM_DATA u8 sys_gap923C[0x4] = { 0 };
MODULE_EWRAM_DATA u32 gModule_Bg2ScrollY = 0;
MODULE_EWRAM_DATA u32 gModule_BgMapWidth = 0;
MODULE_EWRAM_DATA u16 gUnk_02039248 = 0;
static MODULE_EWRAM_DATA u8 sys_gap924A[0x12] = { 0 };
MODULE_EWRAM_DATA u32 gModule_Bg1ScrollX = 0;
MODULE_EWRAM_DATA u32 gModule_Bg1ScrollY = 0;
MODULE_EWRAM_DATA u16 *gModule_CellMapPtr = 0;
MODULE_EWRAM_DATA u16 *gModule_Bg2MapPtr = 0;
static MODULE_EWRAM_DATA u8 sys_gap926C[0x14] = { 0 };
MODULE_EWRAM_DATA u32 gUnk_02039280 = 0;
static MODULE_EWRAM_DATA u8 sys_gap9284[0x4] = { 0 };
MODULE_EWRAM_DATA u32 gModule_BgMapWidth2 = 0;
static MODULE_EWRAM_DATA u8 sys_gap928C[0x4] = { 0 };
MODULE_EWRAM_DATA u32 gModule_Bg3ScrollX = 0;
MODULE_EWRAM_DATA u16 gUnk_02039294 = 0;
static MODULE_EWRAM_DATA u8 sys_gap9296[0x2] = { 0 };
MODULE_EWRAM_DATA u32 gModule_Bg3ScrollY = 0;
MODULE_EWRAM_DATA const u8 *gModule_SurfaceTablePtr = 0;
MODULE_EWRAM_DATA u32 gUnk_020392A0 = 0;
MODULE_EWRAM_DATA u16 gUnk_020392A4 = 0;
static MODULE_EWRAM_DATA u8 sys_gap92A6[0x2] = { 0 };
MODULE_EWRAM_DATA u32 gModule_Bg2ScrollX = 0;
static MODULE_EWRAM_DATA u8 sys_gap92AC[0x14] = { 0 };
MODULE_EWRAM_DATA u8 gModule_PaletteBufferDirty = 0;
static MODULE_EWRAM_DATA u8 sys_gap92C1[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gModule_PaletteFadeActive = 0;
static MODULE_EWRAM_DATA u8 sys_gap92C5[0x3] = { 0 };
MODULE_EWRAM_DATA s16 gModule_PaletteFadeSteps = 0;
static MODULE_EWRAM_DATA u8 sys_gap92CA[0x6] = { 0 };
MODULE_EWRAM_DATA u32 gModule_PaletteFadeColors[0x300] = { 0 };
MODULE_EWRAM_DATA u32 gModule_PaletteFadeDeltas[0x300] = { 0 };
MODULE_EWRAM_DATA u16 gModule_PaletteBuffer[0x100] = { 0 };
