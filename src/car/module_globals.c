#include "global.h"
#include "gba/defines.h"
#include "variables.h"
#include "car.h"

/* This file owns the high module's car/tire EWRAM run 0x0203D4A0-0x0203DDF4
   (issue 5 step 3, run rule), the module twin of src/car/globals.c's run:
   the starting-grid buffer (gUnk_0203D4A0), the tire grip and slip state,
   gModule_Cars (the five 0x190-byte car records: the module races one
   player car plus four AI cars, so gModule_Cars ends at gUnk_0203DCF0),
   the tire-grip leftovers and the challenge state. gModule_AiCars, an
   alias into gModule_Cars, is a macro in car.h. The dead-only symbols inside (gUnk_0203D4F0,
   gUnk_0203D510, gUnk_0203DD20, gUnk_0203DD40, gUnk_0203DDE0: only
   src/dead/sub_083402D8.c touches them) are defined here with the types
   its externs declare, no symbols.ld lines left. gUnk_0203DD60[0x20] ends
   at 0x0203DDE0, and the dead-only gUnk_0203DDE0[0x4] ends the run;
   src/race/module_globals.c's run begins at 0x0203DDE4.
   ldscript.ld's .module_ewram_data_car places the section at
   0x0203D4A0. */

MODULE_EWRAM_DATA u32 gUnk_0203D4A0[0xF] = {0};
MODULE_EWRAM_DATA u32 gModule_TireSlipLimitBase = 0;
MODULE_EWRAM_DATA u8 gModule_TireGripFast = 0;
static MODULE_EWRAM_DATA u8 car_gapD4E1[0x3] = {0};
MODULE_EWRAM_DATA s32 gModule_TireSlipLimit = 0;
MODULE_EWRAM_DATA u8 gUnk_0203D4E8 = 0;
static MODULE_EWRAM_DATA u8 car_gapD4E9[0x3] = {0};
static MODULE_EWRAM_DATA u8 car_gapD4EC[0x4] = {0};
MODULE_EWRAM_DATA u8 gUnk_0203D4F0 = 0;
static MODULE_EWRAM_DATA u8 car_gapD4F1[0x3] = {0};
MODULE_EWRAM_DATA s32 gModule_TireContactVelZ = 0;
static MODULE_EWRAM_DATA u8 car_gapD4F8[0x4] = {0};
MODULE_EWRAM_DATA u8 gUnk_0203D4FC = 0;
static MODULE_EWRAM_DATA u8 car_gapD4FD[0x3] = {0};
MODULE_EWRAM_DATA s32 gUnk_0203D500 = 0;
static MODULE_EWRAM_DATA u8 car_gapD504[0xC] = {0};
/* the module's default gear-power copy; sub_083404A8 fills entry 0..4 */
MODULE_EWRAM_DATA u16 gUnk_0203D510[0x6] = {0};
MODULE_EWRAM_DATA s32 gModule_TireContactVelX = 0;
MODULE_EWRAM_DATA struct Car gModule_Cars[5] = {0};
MODULE_EWRAM_DATA u8 gUnk_0203DCF0 = 0;
static MODULE_EWRAM_DATA u8 car_gapDCF1[0x3] = {0};
MODULE_EWRAM_DATA u8 gModule_TireGripSlow = 0;
static MODULE_EWRAM_DATA u8 car_gapDCF5[0x3] = {0};
MODULE_EWRAM_DATA s32 gModule_YawContactSpeed = 0;
MODULE_EWRAM_DATA s32 gUnk_0203DCFC = 0;
static MODULE_EWRAM_DATA u8 car_gapDD00[0x4] = {0};
MODULE_EWRAM_DATA u32 gUnk_0203DD04 = 0;
MODULE_EWRAM_DATA u8 gUnk_0203DD08 = 0;
static MODULE_EWRAM_DATA u8 car_gapDD09[0x3] = {0};
MODULE_EWRAM_DATA s32 gModule_FrontTireGrip = 0;
MODULE_EWRAM_DATA u8 gUnk_0203DD10 = 0;
static MODULE_EWRAM_DATA u8 car_gapDD11[0x3] = {0};
static MODULE_EWRAM_DATA u8 car_gapDD14[0xC] = {0};
/* sub_0834047C reads five scaled gear-ratio words out of it */
MODULE_EWRAM_DATA u16 gUnk_0203DD20[0x6] = {0};
MODULE_EWRAM_DATA s32 gModule_AxleCarAngle = 0;
MODULE_EWRAM_DATA u8 gUnk_0203DD30 = 0;
static MODULE_EWRAM_DATA u8 car_gapDD31[0x3] = {0};
MODULE_EWRAM_DATA s32 gUnk_0203DD34 = 0;
MODULE_EWRAM_DATA u8 gModule_CurrentCarIndex = 0;
static MODULE_EWRAM_DATA u8 car_gapDD39[0x7] = {0};
/* the module's default gear-ratio copy; sub_083404A8 fills entry 0..4 */
MODULE_EWRAM_DATA u16 gUnk_0203DD40[0x6] = {0};
MODULE_EWRAM_DATA s32 gModule_TireGrip = 0;
static MODULE_EWRAM_DATA u8 car_gapDD50[0x10] = {0};
MODULE_EWRAM_DATA u32 gUnk_0203DD60[0x20] = {0};
/* the dead pit-menu option indices; sub_083402D8 reads [0..2]. Ends the
   run: the race run's gModule_FrontTireGripSlow follows at 0x0203DDE4. */
MODULE_EWRAM_DATA u8 gUnk_0203DDE0[0x4] = {0};
