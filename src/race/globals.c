#include "global.h"
#include "gba/defines.h"
#include "variables.h"

/* This file owns the race EWRAM runs 0x0202CBE0-0x0202CCD0 and
   0x0202CD90-0x0202CDE8 (issue 5 step 3, run rule): the pit-menu cursor,
   the tire-force leftovers, the lap-time snapshots and text buffer, the
   AI driver's closest-lane state, the wall tables' pointers, the car
   contact record and its self frame counters; then the RunRace argument
   buffers, the unreferenced gUnk_0202CDB0 byte and the SIO transfer
   block. Every identified variable in the two spans is defined here in
   address order; the static gap arrays pad only the addresses no
   identified symbol covers. ldscript.ld's .bss_race_globals places the
   first section at 0x0202CBE0 and .bss_race_globals_2 the second at
   0x0202CD90.

   Variables moved here from their old owners (definitions unchanged):
   src/car/tire_forces.c (the four angles/speeds past 0x0202CBE4),
   src/race/lap_time.c, src/car/ai_driver.c,
   src/car/TestCornersVsWalls.c (gWalls, gWallVertices),
   src/car/CollideCarWithWalls.c, src/car/collide.c (gCarCollContact,
   gCarCollFrameSelf), src/race/UpdateLapProgress.c (gUnk_0202CC20) and
   src/menu/MainMenuLoop.c (the three RunRace buffers), plus the
   symbols.ld lines the runs covered, now deleted.

   struct CarContact and struct CommRegs come from structs.h.
   gLapTimeTextBuf is sized to gUnk_0202CC20,
   and DrawLapTime writes its 9 text bytes. */

EWRAM_DATA u8 gPitMenuCursorRow = 0;
static EWRAM_DATA u8 race_globals_gapCBE1[0x3] = { 0 };
EWRAM_DATA s32 gCarHeadingAngle = 0;
EWRAM_DATA s32 gYawContactVelX = 0;
EWRAM_DATA s32 gYawContactVelZ = 0;
EWRAM_DATA s32 gTireForceAngle = 0;
static EWRAM_DATA u8 race_globals_gapCBF4[0xC] = { 0 };
EWRAM_DATA u32 gUnk_0202CC00 = 0;
EWRAM_DATA struct Task *gRaceStartTaskPtr = 0;
EWRAM_DATA u32 gUnk_0202CC08 = 0;
static EWRAM_DATA u8 race_globals_gapCC0C[0x4] = { 0 };
EWRAM_DATA u8 gLapTimeTextBuf[0xC] = { 0 };
EWRAM_DATA u32 gUnk_0202CC1C[1] = { 0 };
EWRAM_DATA u32 gUnk_0202CC20 = 0;
EWRAM_DATA s32 gClosestLanePointX = 0;
EWRAM_DATA u8 gAiCarAheadSide = 0;
static EWRAM_DATA u8 race_globals_gapCC29[0x3] = { 0 };
EWRAM_DATA u8 gUnk_0202CC2C = 0;
static EWRAM_DATA u8 race_globals_gapCC2D[0x7] = { 0 };
EWRAM_DATA s32 gClosestLaneSegmentIndex = 0;
EWRAM_DATA s32 gClosestLanePointZ = 0;
EWRAM_DATA const struct LaneSeg *gClosestLaneSegment = 0;
EWRAM_DATA struct WallRec *gWalls = 0;
EWRAM_DATA struct Pt *gWallVertices = 0;
EWRAM_DATA u32 gUnk_0202CC48 = 0;
EWRAM_DATA s32 gUnk_0202CC4C = 0;
EWRAM_DATA s32 gWallCollisionNormal[5] = { 0 };
EWRAM_DATA s32 gUnk_0202CC64 = 0;
EWRAM_DATA u16 *gUnk_0202CC68 = 0;
EWRAM_DATA u16 *gUnk_0202CC6C = 0;
EWRAM_DATA s32 gUnk_0202CC70 = 0;
static EWRAM_DATA u8 race_globals_gapCC74[0x1C] = { 0 };
EWRAM_DATA struct CarContact gCarCollContact = { 0 };
static EWRAM_DATA u8 race_globals_gapCCA0[0x10] = { 0 };
EWRAM_DATA s32 gCarCollFrameSelf[8] = { 0 };

EWRAM_DATA2 u8 gUnk_0202CD90[0xC] = { 0 };
EWRAM_DATA2 u8 gUnk_0202CD9C[0xC] = { 0 };
EWRAM_DATA2 u8 gUnk_0202CDA8[0x8] = { 0 };
EWRAM_DATA2 u8 gUnk_0202CDB0 = 0;
static EWRAM_DATA2 u8 race_globals_gapCDB1[0xF] = { 0 };
EWRAM_DATA2 u8 gUnk_0202CDC0[0x10] = { 0 };
EWRAM_DATA2 struct CommRegs gSioTransfer = { 0 };
