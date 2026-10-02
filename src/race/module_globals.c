#include "global.h"
#include "gba/defines.h"
#include "variables.h"

/* This file owns the high module's two race/walls/collide EWRAM runs, the
   module twin of src/race/globals.c's run: the tire-force leftovers and the
   four heading/yaw angles (0x0203DDE4-0x0203DEF0, ending at the lap- time
   state), then the lap-time state, the wall-table pointers and wall-
   collision state, the car contact record with its frame counters, the
   challenge/link leftovers and gModule_Language (0x0203DF44-0x0203E005).
   The 0x54-byte span 0x0203DEF0-0x0203DF44 between the frame counters and
   gUnk_0203DF44 carries no identified symbol, as does the 0xDB-byte span
   0x0203E005-0x0203E0E0 behind gModule_Language; the dead-only
   gUnk_0203E000 (src/dead/sub_08342948.c sets it) is defined here.
   gModule_CarCollContact is one struct CarContact (structs.h), with the
   second record's space behind it unnamed. ldscript.ld's
   .module_ewram_data_race and .module_ewram_data_race_2 place the two
   sections. */

MODULE_EWRAM_DATA u8 gModule_FrontTireGripSlow = 0;
static MODULE_EWRAM_DATA u8 race_gapDDE5[0x3] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_0203DDE8[0xC] = { 0 };
MODULE_EWRAM_DATA s32 gModule_AxleTireGrip = 0;
MODULE_EWRAM_DATA s32 gUnk_0203DDF8 = 0;
MODULE_EWRAM_DATA u8 gModule_FrontTireGripFast = 0;
static MODULE_EWRAM_DATA u8 race_gapDDFD[0x7] = { 0 };
MODULE_EWRAM_DATA s32 gModule_CarHeadingAngle = 0;
MODULE_EWRAM_DATA s32 gModule_YawContactVelX = 0;
MODULE_EWRAM_DATA s32 gModule_YawContactVelZ = 0;
MODULE_EWRAM_DATA s32 gModule_TireForceAngle = 0;
static MODULE_EWRAM_DATA u8 race_gapDE14[0xC] = { 0 };
MODULE_EWRAM_DATA u32 gUnk_0203DE20 = 0;
MODULE_EWRAM_DATA struct Task *gModule_RaceStartTaskPtr = 0;
MODULE_EWRAM_DATA u32 gUnk_0203DE28 = 0;
static MODULE_EWRAM_DATA u8 race_gapDE2C[0x4] = { 0 };
MODULE_EWRAM_DATA u8 gUnk_0203DE30[0xC] = { 0 };
MODULE_EWRAM_DATA u32 gUnk_0203DE3C = 0;
MODULE_EWRAM_DATA u32 gUnk_0203DE40 = 0;
static MODULE_EWRAM_DATA u8 race_gapDE44[0x1C] = { 0 };
MODULE_EWRAM_DATA struct WallRec *gModule_Walls = 0;
MODULE_EWRAM_DATA struct Pt *gModule_WallVertices = 0;
MODULE_EWRAM_DATA u32 gUnk_0203DE68 = 0;
MODULE_EWRAM_DATA s32 gUnk_0203DE6C = 0;
MODULE_EWRAM_DATA s32 gModule_WallCollisionNormal[5] = { 0 };
MODULE_EWRAM_DATA s32 gUnk_0203DE84 = 0;
MODULE_EWRAM_DATA u16 *gUnk_0203DE88 = 0;
MODULE_EWRAM_DATA u16 *gUnk_0203DE8C = 0;
MODULE_EWRAM_DATA s32 gUnk_0203DE90 = 0;
static MODULE_EWRAM_DATA u8 race_gapDE94[0x1C] = { 0 };
MODULE_EWRAM_DATA struct CarContact gModule_CarCollContact = { 0 };
static MODULE_EWRAM_DATA u8 race_gapDEC0[0x10] = { 0 };
MODULE_EWRAM_DATA s32 gModule_CarCollFrameSelf[8] = { 0 };

MODULE_EWRAM_DATA2 s32 gUnk_0203DF44 = 0;
static MODULE_EWRAM_DATA2 u8 race_gapDF48[0x8] = { 0 };
MODULE_EWRAM_DATA2 s32 gModule_CarCollFrameOther[8] = { 0 };
static MODULE_EWRAM_DATA2 u8 race_gapDF70[0x40] = { 0 };
MODULE_EWRAM_DATA2 u8 gUnk_0203DFB0 = 0;
static MODULE_EWRAM_DATA2 u8 race_gapDFB1[0x7] = { 0 };
MODULE_EWRAM_DATA2 u16 gModule_LinkTxBuffer[6] = { 0 };
MODULE_EWRAM_DATA2 u32 gUnk_0203DFC4 = 0;
static MODULE_EWRAM_DATA2 u8 race_gapDFC8[0x2C] = { 0 };
MODULE_EWRAM_DATA2 u32 gUnk_0203DFF4 = 0;
static MODULE_EWRAM_DATA2 u8 race_gapDFF8[0x8] = { 0 };
MODULE_EWRAM_DATA2 u8 gUnk_0203E000 = 0;
static MODULE_EWRAM_DATA2 u8 race_gapE001[0x3] = { 0 };
MODULE_EWRAM_DATA2 u8 gModule_Language = 0;
