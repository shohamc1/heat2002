#include "global.h"
#include "gba/defines.h"
#include "variables.h"
#include "car.h"

/* This file owns the car/tire/pit EWRAM run 0x0202A510-0x0202CBE0 (issue 5
   step 3, run rule): the tire grip and tire-force state, the pit-stop and
   challenge timers, the setup tables, gCars (the 24 0x190-byte car records,
   ending exactly at gPitMenuActive) and the pit-menu selection state.
   Every identified variable in the span is defined here in address order;
   the static gap arrays pad only the addresses no identified symbol
   covers. ldscript.ld's .bss_car_globals places the section at 0x0202A510.

   Variables moved here from their old owners (definitions unchanged):
   src/car/tire_grip.c, src/car/tire_forces.c (except gCarHeadingAngle,
   gYawContactVelX, gYawContactVelZ and gTireForceAngle, which sit in the
   next run and moved to src/race/globals.c), src/race/pitstop.c,
   src/car/collide.c (only gUnk_0202A530), src/race/challenge.c,
   src/car/setup.c, src/car/update.c (gFuelOutStutterCounter) and
   src/race/UpdateLapProgress.c (gStartedCarCount, gPlayerPittedFlag),
   plus the symbols.ld lines the run covered, now deleted. gAiCars, an alias
   into gCars, is a macro in car.h; the unreferenced gUnk_0202A6A8
   line was deleted outright. gPitServiceSelections is the pit menu's
   three option rows (indices 0..2, one byte each plus slack).
   gWaypointSpeedSamples holds one u32 sample per AI waypoint slot. */

EWRAM_DATA u32 gTireSlipLimitBase = 0;
EWRAM_DATA u8 gTireGripFast = 0;
static EWRAM_DATA u8 car_globals_gapA515[0x3] = {0};
EWRAM_DATA s32 gTireSlipLimit = 0;
EWRAM_DATA u8 gFuelOutStutterCounter = 0;
static EWRAM_DATA u8 car_globals_gapA51D[0x3] = {0};
EWRAM_DATA s32 gPitFuelToAdd = 0;
EWRAM_DATA u8 gPitMenuBlinkCounter = 0;
static EWRAM_DATA u8 car_globals_gapA525[0x3] = {0};
EWRAM_DATA s32 gTireContactVelZ = 0;
static EWRAM_DATA u8 car_globals_gapA52C[0x4] = {0};
EWRAM_DATA u8 gUnk_0202A530 = 0;
static EWRAM_DATA u8 car_globals_gapA531[0x3] = {0};
EWRAM_DATA s32 gChallengeTimerMs = 0;
static EWRAM_DATA u8 car_globals_gapA538[0x4] = {0};
EWRAM_DATA u8 gPitServiceEnabled = 0;
static EWRAM_DATA u8 car_globals_gapA53D[0x3] = {0};
EWRAM_DATA u16 gUnk_0202A540[6] = {0};
EWRAM_DATA s32 gTireContactVelX = 0;
EWRAM_DATA struct Car gCars[24] = {0};
EWRAM_DATA u8 gPitMenuActive = 0;
static EWRAM_DATA u8 car_globals_gapCAD1[0x3] = {0};
EWRAM_DATA u8 gTireGripSlow = 0;
static EWRAM_DATA u8 car_globals_gapCAD5[0x3] = {0};
EWRAM_DATA s32 gYawContactSpeed = 0;
EWRAM_DATA s32 gChallengeTimerSec = 0;
EWRAM_DATA s32 gPlayerPitProgressRate = 0;
EWRAM_DATA s32 gUnk_0202CAE4 = 0;
EWRAM_DATA u8 gChallengePhase = 0;
static EWRAM_DATA u8 car_globals_gapCAE9[0x3] = {0};
EWRAM_DATA s32 gFrontTireGrip = 0;
EWRAM_DATA u8 gStartedCarCount = 0;
static EWRAM_DATA u8 car_globals_gapCAF1[0xF] = {0};
EWRAM_DATA u16 gUnk_0202CB00[6] = {0};
EWRAM_DATA s32 gAxleCarAngle = 0;
EWRAM_DATA u8 gChallengeEndDelay = 0;
static EWRAM_DATA u8 car_globals_gapCB11[0x3] = {0};
EWRAM_DATA s32 gUnk_0202CB14 = 0;
EWRAM_DATA u8 gCurrentCarIndex = 0;
static EWRAM_DATA u8 car_globals_gapCB19[0x7] = {0};
EWRAM_DATA u16 gUnk_0202CB20[6] = {0};
EWRAM_DATA s32 gTireGrip = 0;
static EWRAM_DATA u8 car_globals_gapCB30[0x10] = {0};
EWRAM_DATA u32 gWaypointSpeedSamples[0x20] = {0};
EWRAM_DATA u8 gPitServiceSelections[4] = {0};
EWRAM_DATA u8 gFrontTireGripSlow = 0;
static EWRAM_DATA u8 car_globals_gapCBC5[0x3] = {0};
EWRAM_DATA u8 gPitStallOccupied[8] = {0};
EWRAM_DATA u8 gPlayerPittedFlag = 0;
static EWRAM_DATA u8 car_globals_gapCBD1[0x3] = {0};
EWRAM_DATA s32 gAxleTireGrip = 0;
EWRAM_DATA s32 gChallengeBestValue = 0;
EWRAM_DATA u8 gFrontTireGripFast = 0;
