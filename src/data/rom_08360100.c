#include "global.h"
#include "race_setup_tables.h"
#include "approach_constants.h"

/* The pit-menu label rows inside gModule_PitLabelBlock
 * (src/data/high_module_text.c), named by their EWRAM addresses in
 * symbols.ld. */
extern const u8 gUnk_0200CFC4[]; /* OK */
extern const u8 gUnk_0200CFC8[]; /* DAMAGE: */
extern const u8 gUnk_0200CFD0[]; /* FUEL  : */
extern const u8 gUnk_0200CFD8[]; /* TIRES : */
extern const u8 gUnk_0200CFE0[]; /* NONE      */
extern const u8 gUnk_0200CFEC[]; /* RIGHT 2   */
extern const u8 gUnk_0200CFF8[]; /* LEFT 2    */
extern const u8 gUnk_0200D004[]; /* ALL TIRES */
extern const u8 gUnk_0200D010[]; /* NONE           */
extern const u8 gUnk_0200D020[]; /* SPLASH AND DASH */
extern const u8 gUnk_0200D030[]; /* FULL TANK      */
extern const u8 gUnk_0200D040[]; /* NO REPAIR */
extern const u8 gUnk_0200D04C[]; /* REPAIR    */

/* The two strings inside gModule_Demo and gModule_OutOfTime
 * (high_module_text.c) that gModule_083682A8 points at, named in
 * symbols.ld. */
extern const u8 gUnk_0200D0EC[]; /* DEMO */
extern const u8 gUnk_0200D10C[]; /* OUT OF TIME */

/* The frame lists src/data/rom_083639A8.c defines. */
extern const u8 *const gModule_LinkMarkerP1FrameList[];
extern const u8 *const gModule_LinkMarkerP2FrameList[];
extern const u8 *const gModule_LinkMarkerP3FrameList[];
extern const u8 *const gModule_LinkMarkerP4FrameList[];
extern const u8 *const gModule_DriverSteveParkNumberFrames[];
extern const u8 *const gModule_DriverDaleEarnhardtJRNumberFrames[];
extern const u8 *const gModule_DriverKevinHarvickNumberFrames[];
extern const u8 *const gModule_DriverDaleJarrettNumberFrames[];
extern const u8 *const gModule_DriverRickyRuddNumberFrames[];
extern const u8 *const gModule_DriverJeffGordonNumberFrames[];
extern const u8 *const gModule_DriverJasonPopeNumberFrames[];
extern const u8 *const gModule_DriverJoeFriedNumberFrames[];
extern const u8 *const gModule_DriverRustyWallaceNumberFrames[];
extern const u8 *const gModule_DriverSterlingMarlinNumberFrames[];
extern const u8 *const gModule_DriverBrianLockeNumberFrames[];
extern const u8 *const gModule_DriverJayMcgeeNumberFrames[];
extern const u8 *const gModule_DriverMitchellSlaterNumberFrames[];
extern const u8 *const gModule_DriverJamesBrownNumberFrames[];
extern const u8 *const gModule_DriverNeilWilsonNumberFrames[];
extern const u8 *const gModule_DriverTimMunsonNumberFrames[];
extern const u8 *const gModule_DriverAndrewBishopNumberFrames[];
extern const u8 *const gModule_DriverDanielEvansNumberFrames[];
extern const u8 *const gModule_DriverSeanKendrickNumberFrames[];
extern const u8 *const gModule_DriverJakeMayNumberFrames[];
extern const u8 *const gModule_DriverChrisWalshNumberFrames[];
extern const u8 *const gModule_DriverJamesDalyNumberFrames[];
extern const u8 *const gModule_DriverAdamBouskillNumberFrames[];
extern const u8 *const gModule_DriverTimCoodeNumberFrames[];
extern const u8 *const gModule_DriverWillGreenoughNumberFrames[];
extern const u8 *const gModule_DriverJonnieShearnNumberFrames[];
extern const u8 *const gModule_DriverDaveMurphyNumberFrames[];
extern const u8 *const gModule_DriverDarrenJacksonNumberFrames[];
extern const u8 *const gModule_DriverMikeMerrenNumberFrames[];
extern const u8 *const gModule_DriverCameronSheppardNumberFrames[];

/* High module (link slave) pit-menu option text tables (ROM
 * 0x08360100-0x0836012C, EWRAM 0x02027680-0x020276AC): the fixed row
 * labels and the tyre and fuel option rows, in the main program's order sub_083402D8.c draws, the
 * twins of the main program's gPitMenuRowLabelTexts /
 * gPitMenuTireOptionTexts / gPitMenuFuelOptionTexts
 * (src/data/race_setup.c). Each entry points into
 * gModule_PitLabelBlock's packed strings. */

const u8 *const gModule_PitMenuRowLabelTexts[4] = { gUnk_0200CFD8, gUnk_0200CFD0, gUnk_0200CFC8, gUnk_0200CFC4 };
const u8 *const gModule_PitMenuTireOptionTexts[4] = { gUnk_0200D004, gUnk_0200CFF8, gUnk_0200CFEC, gUnk_0200CFE0 };
const u8 *const gModule_PitMenuFuelOptionTexts[3] = { gUnk_0200D030, gUnk_0200D020, gUnk_0200D010 };

/* The rest of the race-setup tables (ROM 0x0836012C-0x08360280, EWRAM
 * 0x020276AC-0x02027800), the twins of the main program's from
 * gPitMenuRepairOptionTexts to gRecordsTaskParams (src/data/race_setup.c,
 * which says what each is for). The numbers are byte-identical and build
 * from race_setup_tables.h; the pointer tables point at the module's own
 * strings and frame lists. */

const u8 *const gModule_PitMenuRepairOptionTexts[2] = { gUnk_0200D04C, gUnk_0200D040 };
const s32 gModule_ChallengeStartOffsetPercents[16] = CHALLENGE_START_OFFSET_PERCENTS;
const u8 gModule_TrackStartOffsetPercents[12] = TRACK_START_OFFSET_PERCENTS;
const u8 gModule_PitLaneIndices[12] = PIT_LANE_INDICES;
const s32 gModule_083681C8[8] = UNK_083681C8;
const u8 *const *const gModule_LinkMarkerFrameLists[4] = {
    gModule_LinkMarkerP1FrameList, gModule_LinkMarkerP2FrameList,
    gModule_LinkMarkerP3FrameList, gModule_LinkMarkerP4FrameList
};
const u8 *const *const gModule_DriverNumberFrameLists[30] = {
    gModule_DriverSteveParkNumberFrames, gModule_DriverDaleEarnhardtJRNumberFrames,
    gModule_DriverKevinHarvickNumberFrames, gModule_DriverDaleJarrettNumberFrames,
    gModule_DriverRickyRuddNumberFrames, gModule_DriverJeffGordonNumberFrames,
    gModule_DriverJasonPopeNumberFrames, gModule_DriverJoeFriedNumberFrames,
    gModule_DriverRustyWallaceNumberFrames, gModule_DriverSterlingMarlinNumberFrames,
    gModule_DriverBrianLockeNumberFrames, gModule_DriverJayMcgeeNumberFrames,
    gModule_DriverMitchellSlaterNumberFrames, gModule_DriverJamesBrownNumberFrames,
    gModule_DriverNeilWilsonNumberFrames, gModule_DriverTimMunsonNumberFrames,
    gModule_DriverAndrewBishopNumberFrames, gModule_DriverDanielEvansNumberFrames,
    gModule_DriverSeanKendrickNumberFrames, gModule_DriverJakeMayNumberFrames,
    gModule_DriverChrisWalshNumberFrames, gModule_DriverJamesDalyNumberFrames,
    gModule_DriverAdamBouskillNumberFrames, gModule_DriverTimCoodeNumberFrames,
    gModule_DriverWillGreenoughNumberFrames, gModule_DriverJonnieShearnNumberFrames,
    gModule_DriverDaveMurphyNumberFrames, gModule_DriverDarrenJacksonNumberFrames,
    gModule_DriverMikeMerrenNumberFrames, gModule_DriverCameronSheppardNumberFrames
};
const s32 gModule_CornerOffsetX[4] = CORNER_OFFSET_X;
const s32 gModule_CornerOffsetZ[4] = CORNER_OFFSET_Z;
const u16 gModule_TrackAiDragDivisors[12] = TRACK_AI_DRAG_DIVISORS;
const u8 *const gModule_083682A8[2] = { gUnk_0200D0EC, gUnk_0200D10C };
const u8 gModule_RecordsTaskParams[12] = RECORDS_TASK_PARAMS;

/* The twins of the main program's second-order approach constants
 * gUnk_083CA0B4-gUnk_083CA0C0 (src/data/rom_083C9574.c). Only dead code
 * reads them (sub_083432F4.c). */
const s32 gUnk_02027800 = APPROACH_STIFFNESS_A;
const s32 gUnk_02027804 = APPROACH_DAMPING_A;
const s32 gUnk_02027808 = APPROACH_STIFFNESS_B;
const s32 gUnk_0202780C = APPROACH_DAMPING_B;
