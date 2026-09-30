#include "global.h"
#include "data.h"
#include "race_setup_tables.h"

/* Race setup data (0x083671C0-0x083682BC): per-track object-tile VRAM
 * caches, pit stall coordinates and entry/exit progress points, race
 * points, tire grip defaults, starting grids, the AI driver's default
 * setup, then the driver engine parameters (one 5-entry u16 row per
 * driver, 30 drivers in gDriverRoster order; rows are teammates in pairs,
 * which is why consecutive rows repeat. Named
 * gDriver<Name><Power|GearRatio|RpmPerSpeed>), and the race setup tables
 * (pit stop times, pit menu texts, start offsets, frame lists, corner
 * offsets) through 0x083682BC. */
extern const u8 gUnk_08330D38[];
extern const u8 gUnk_08330D58[];
extern const u8 gUnk_08330D78[];
extern const u8 gUnk_08330D98[];
extern const u8 gUnk_08330DB8[];
extern const u8 gUnk_08330DD8[];
extern const u8 gUnk_08330DF8[];
extern const u8 gUnk_08330E18[];
extern const u8 gUnk_08330E38[];
extern const u8 gUnk_08330E58[];
extern const u8 gUnk_08330E78[];
extern const u8 gUnk_08330E98[];
extern const u8 gUnk_08330EB8[];
extern const u8 gUnk_08330ED8[];
extern const u8 gUnk_08330EF8[];
extern const u8 gUnk_08330F18[];
extern const u8 gUnk_08330F38[];
extern const u8 gUnk_08330F58[];
extern const u8 gUnk_08330F78[];
extern const u8 gUnk_08330F98[];
extern const u8 gUnk_08330FB8[];
extern const u8 gUnk_08330FD8[];
extern const u8 gUnk_08330FF8[];
extern const u8 gUnk_08331018[];
extern const u8 gUnk_08331038[];
extern const u8 gUnk_08331058[];
extern const u8 gUnk_08331078[];
extern const u8 gUnk_083311A8[];
extern const u8 gUnk_083311C8[];
extern const struct TrackSeg gTrackSegs_Track0[];
extern const struct TrackSeg gTrackSegs_Track1[];
extern const struct TrackSeg gTrackSegs_Track2[];
extern const struct TrackSeg gTrackSegs_Track3[];
extern const struct TrackSeg gTrackSegs_Track4[];
extern const struct TrackSeg gTrackSegs_Track5[];
extern const struct TrackSeg gTrackSegs_Track6[];
extern const struct TrackSeg gTrackSegs_Track7[];
extern const struct TrackSeg gTrackSegs_Track8[];
extern const struct TrackSeg gTrackSegs_Track9[];
extern const struct TrackSeg gTrackSegs_Track10[];
extern const struct TrackSeg gTrackSegs_Track11[];
extern const u32 gUnk_083FEF80[];
extern const u32 gUnk_083FF004[];
extern const u32 gUnk_083FF088[];
extern const u32 gUnk_083FF10C[];
extern const u32 gUnk_083FF190[];
extern const u32 gUnk_083FF214[];
extern const u32 gUnk_083FF298[];
extern const u32 gUnk_083FF31C[];
extern const u32 gUnk_083FF3A0[];
extern const u32 gUnk_083FF424[];
extern const u32 gUnk_083FF4A8[];
extern const u32 gUnk_083FF52C[];

const struct TrackSeg *const gTrackSegTables[] = { gTrackSegs_Track0, gTrackSegs_Track1, gTrackSegs_Track2, gTrackSegs_Track3,
                                                   gTrackSegs_Track4, gTrackSegs_Track5, gTrackSegs_Track6, gTrackSegs_Track7,
                                                   gTrackSegs_Track8, gTrackSegs_Track9, gTrackSegs_Track10, gTrackSegs_Track11 };
// The sprite caches' OBJ VRAM tile numbers. Each array holds u16 tile
// indices that InitObjTileCache reads one by one (turning each into an
// OBJ_VRAM0 offset with t << 5); the words below just pair them.
const u16 gObjTileCache64Tiles[4] = OBJ_TILE_CACHE_64_TILES;
const u16 gObjTileCache16Tiles[24] = OBJ_TILE_CACHE_16_TILES;
const u16 gObjTileCache2Tiles[32] = OBJ_TILE_CACHE_2_TILES;
const u16 gObjTileCache8Tiles[20] = OBJ_TILE_CACHE_8_TILES;
const u16 gObjTileCache4Tiles[16] = OBJ_TILE_CACHE_4_TILES;
const u16 gObjTileCache1Tiles[32] = OBJ_TILE_CACHE_1_TILES;
// Its users declare it as s32 x[], u32 x[].
// Twelve tracks times eight pit stalls, one (x, y) pair each
// (ComputePitStallDistance, UpdateAiDriver).
const u32 gPitStallPositions[192] = PIT_STALL_POSITIONS;
// The track progress value at which a car may enter its pit stall, per
// track (car/update.c compares it against the car's progress).
const u16 gPitEntryProgressPoints[12] = PIT_ENTRY_PROGRESS_POINTS;
// The track progress value at which a car leaves the pit lane, per track.
const u16 gPitExitProgressPoints[12] = PIT_EXIT_PROGRESS_POINTS;
// NASCAR championship points per finishing position 1-30; 31st and
// beyond get nothing (AwardRacePoints, src/race/grid.c).
const u8 gRacePointsTable[32] = RACE_POINTS_TABLE;
const u32 *const gDriverCarSpriteHalfATables[] = {
    gUnk_083FF424, gUnk_083FF424, gUnk_083FF52C, gUnk_083FF004, gUnk_083FF52C, gUnk_083FF214,
    gUnk_083FF10C, gUnk_083FF31C, gUnk_083FF52C, gUnk_083FF52C, gUnk_083FF31C, gUnk_083FF214,
    gUnk_083FF31C, gUnk_083FF424, gUnk_083FF10C, gUnk_083FF10C, gUnk_083FF424, gUnk_083FF214,
    gUnk_083FF10C, gUnk_083FF214, gUnk_083FF424, gUnk_083FF214, gUnk_083FF52C, gUnk_083FF10C,
    gUnk_083FF31C, gUnk_083FF004, gUnk_083FF004, gUnk_083FF004, gUnk_083FF31C, gUnk_083FF004
};
const u32 *const gDriverCarSpriteHalfBTables[] = {
    gUnk_083FF3A0, gUnk_083FF3A0, gUnk_083FF4A8, gUnk_083FEF80, gUnk_083FF4A8, gUnk_083FF190,
    gUnk_083FF088, gUnk_083FF298, gUnk_083FF4A8, gUnk_083FF4A8, gUnk_083FF298, gUnk_083FF190,
    gUnk_083FF298, gUnk_083FF3A0, gUnk_083FF088, gUnk_083FF088, gUnk_083FF3A0, gUnk_083FF190,
    gUnk_083FF088, gUnk_083FF190, gUnk_083FF3A0, gUnk_083FF190, gUnk_083FF4A8, gUnk_083FF088,
    gUnk_083FF298, gUnk_083FEF80, gUnk_083FEF80, gUnk_083FEF80, gUnk_083FF298, gUnk_083FEF80
};
// Its users declare it as u32 *x[].
const u8 *const gDriverPalettes[] = { gUnk_08330D38, gUnk_08330D58, gUnk_08330D78, gUnk_08330D98, gUnk_08330DB8,
                                      gUnk_08330DD8, gUnk_083311A8, gUnk_083311C8, gUnk_08330DF8, gUnk_08330E18,
                                      gUnk_08330E38, gUnk_08330E58, gUnk_08330E78, gUnk_08330E98, gUnk_08330EB8,
                                      gUnk_08330ED8, gUnk_08330EF8, gUnk_08330F18, gUnk_08330F38, gUnk_08330F58,
                                      gUnk_08330F78, gUnk_08330F98, gUnk_08330FB8, gUnk_08330FD8, gUnk_08330FF8,
                                      gUnk_08331018, gUnk_08331038, gUnk_08330D98, gUnk_08331058, gUnk_08331078 };
// Tire-grip setups, 31 rows (struct TireGripSetup, structs.h):
// rear slow/fast grip, front slow/fast grip, slip-limit base.
// SetTireGrip (src/car/tire_grip.c) loads row 0 for link races and the
// player's car; no decompiled code reads the other 30 rows yet.
const struct TireGripSetup gTireGripDefaults[31] = TIRE_GRIP_DEFAULTS;
// Starting-grid records (struct TrackGrid, structs.h), one per track;
// BuildStartingGrid (race/grid.c) places the 24 slots from each row.
const struct TrackGrid gTrackStartGrids[12] = {
    { 2689, 1651, -60, -60, 40, -40, 96 }, { 1460, 1192, 60, 0, 0, -60, 192 },  { 3988, 3646, -40, 40, 56, 56, 32 },
    { 449, 1444, 0, -40, -50, 0, 128 },    { 3954, 2933, 0, -40, -50, 0, 128 }, { 1439, 2619, 0, 50, 40, 0, 0 },
    { 1461, 1318, 0, -56, 40, 0, 128 },    TRACK_7_START_GRID,  { 3160, 2605, -56, 0, 40, 0, 0 },
    { 1178, 3161, 0, -56, -40, 0, 0 },     { 734, 1065, 56, 0, 40, 0, 128 },    { 2064, 2613, 56, 0, 0, -40, 192 },
};
// Seven car setups of three 5-entry rows each (gear power, gear ratio,
// rpm per speed, one entry per gear), the layout of the per-driver rows
// below. InitTuneSettings copies the second setup's power and ratio rows
// (gTuneDefaultGearPower, gTuneDefaultGearRatio) into the tune menu. The
// sixth setup is the AI driver's (SetAiDriverGearTables, InitCar), with one
// stray u16 between its power and ratio rows.
const u16 gUnk_08367B64[5] = UNK_08367B64;
const u16 gUnk_08367B6E[5] = UNK_08367B6E;
const u16 gUnk_08367B78[5] = UNK_08367B78;
const u16 gTuneDefaultGearPower[5] = TUNE_DEFAULT_GEAR_POWER;
const u16 gTuneDefaultGearRatio[5] = TUNE_DEFAULT_GEAR_RATIO;
const u16 gUnk_08367B96[5] = UNK_08367B96;
const u16 gUnk_08367BA0[5] = UNK_08367BA0;
const u16 gUnk_08367BAA[5] = UNK_08367BAA;
const u16 gUnk_08367BB4[5] = UNK_08367BB4;
const u16 gUnk_08367BBE[5] = UNK_08367BBE;
const u16 gUnk_08367BC8[5] = UNK_08367BC8;
const u16 gUnk_08367BD2[5] = UNK_08367BD2;
const u16 gUnk_08367BDC[5] = UNK_08367BDC;
const u16 gUnk_08367BE6[5] = UNK_08367BE6;
const u16 gUnk_08367BF0[5] = UNK_08367BF0;
const u16 gAiDriverGearPowerTable[5] = AI_DRIVER_GEAR_POWER_TABLE;
const u16 gUnk_08367C04[1] = UNK_08367C04;
const u16 gAiDriverGearRatioTable[5] = AI_DRIVER_GEAR_RATIO_TABLE;
const u16 gAiDriverRpmPerSpeedTable[5] = AI_DRIVER_RPM_PER_SPEED_TABLE;
const u16 gUnk_08367C1A[5] = UNK_08367C1A;
const u16 gUnk_08367C24[5] = UNK_08367C24;
const u16 gUnk_08367C2E[5] = UNK_08367C2E;

const u16 gDriverSteveParkPower[5] = DRIVER_STEVE_PARK_POWER;
const u16 gDriverDaleEarnhardtJRPower[5] = DRIVER_DALE_EARNHARDT_J_R_POWER;
const u16 gDriverKevinHarvickPower[5] = DRIVER_KEVIN_HARVICK_POWER;
const u16 gDriverDaleJarrettPower[5] = DRIVER_DALE_JARRETT_POWER;
const u16 gDriverRickyRuddPower[5] = DRIVER_RICKY_RUDD_POWER;
const u16 gDriverJeffGordonPower[5] = DRIVER_JEFF_GORDON_POWER;
const u16 gDriverJasonPopePower[5] = DRIVER_JASON_POPE_POWER;
const u16 gDriverJoeFriedPower[5] = DRIVER_JOE_FRIED_POWER;
const u16 gDriverRustyWallacePower[5] = DRIVER_RUSTY_WALLACE_POWER;
const u16 gDriverSterlingMarlinPower[5] = DRIVER_STERLING_MARLIN_POWER;
const u16 gDriverBrianLockePower[5] = DRIVER_BRIAN_LOCKE_POWER;
const u16 gDriverJayMcgeePower[5] = DRIVER_JAY_MCGEE_POWER;
const u16 gDriverMitchellSlaterPower[5] = DRIVER_MITCHELL_SLATER_POWER;
const u16 gDriverJamesBrownPower[5] = DRIVER_JAMES_BROWN_POWER;
const u16 gDriverNeilWilsonPower[5] = DRIVER_NEIL_WILSON_POWER;
const u16 gDriverTimMunsonPower[5] = DRIVER_TIM_MUNSON_POWER;
const u16 gDriverAndrewBishopPower[5] = DRIVER_ANDREW_BISHOP_POWER;
const u16 gDriverDanielEvansPower[5] = DRIVER_DANIEL_EVANS_POWER;
const u16 gDriverSeanKendrickPower[5] = DRIVER_SEAN_KENDRICK_POWER;
const u16 gDriverJakeMayPower[5] = DRIVER_JAKE_MAY_POWER;
const u16 gDriverChrisWalshPower[5] = DRIVER_CHRIS_WALSH_POWER;
const u16 gDriverJamesDalyPower[5] = DRIVER_JAMES_DALY_POWER;
const u16 gDriverAdamBouskillPower[5] = DRIVER_ADAM_BOUSKILL_POWER;
const u16 gDriverTimCoodePower[5] = DRIVER_TIM_COODE_POWER;
const u16 gDriverWillGreenoughPower[5] = DRIVER_WILL_GREENOUGH_POWER;
const u16 gDriverJonnieShearnPower[5] = DRIVER_JONNIE_SHEARN_POWER;
const u16 gDriverDaveMurphyPower[5] = DRIVER_DAVE_MURPHY_POWER;
const u16 gDriverDarrenJacksonPower[5] = DRIVER_DARREN_JACKSON_POWER;
const u16 gDriverMikeMerrenPower[5] = DRIVER_MIKE_MERREN_POWER;
const u16 gDriverCameronSheppardPower[5] = DRIVER_CAMERON_SHEPPARD_POWER;
const u16 gDriverSteveParkGearRatio[5] = DRIVER_STEVE_PARK_GEAR_RATIO;
const u16 gDriverDaleEarnhardtJRGearRatio[5] = DRIVER_DALE_EARNHARDT_J_R_GEAR_RATIO;
const u16 gDriverKevinHarvickGearRatio[5] = DRIVER_KEVIN_HARVICK_GEAR_RATIO;
const u16 gDriverDaleJarrettGearRatio[5] = DRIVER_DALE_JARRETT_GEAR_RATIO;
const u16 gDriverRickyRuddGearRatio[5] = DRIVER_RICKY_RUDD_GEAR_RATIO;
const u16 gDriverJeffGordonGearRatio[5] = DRIVER_JEFF_GORDON_GEAR_RATIO;
const u16 gDriverJasonPopeGearRatio[5] = DRIVER_JASON_POPE_GEAR_RATIO;
const u16 gDriverJoeFriedGearRatio[5] = DRIVER_JOE_FRIED_GEAR_RATIO;
const u16 gDriverRustyWallaceGearRatio[5] = DRIVER_RUSTY_WALLACE_GEAR_RATIO;
const u16 gDriverSterlingMarlinGearRatio[5] = DRIVER_STERLING_MARLIN_GEAR_RATIO;
const u16 gDriverBrianLockeGearRatio[5] = DRIVER_BRIAN_LOCKE_GEAR_RATIO;
const u16 gDriverJayMcgeeGearRatio[5] = DRIVER_JAY_MCGEE_GEAR_RATIO;
const u16 gDriverMitchellSlaterGearRatio[5] = DRIVER_MITCHELL_SLATER_GEAR_RATIO;
const u16 gDriverJamesBrownGearRatio[5] = DRIVER_JAMES_BROWN_GEAR_RATIO;
const u16 gDriverNeilWilsonGearRatio[5] = DRIVER_NEIL_WILSON_GEAR_RATIO;
const u16 gDriverTimMunsonGearRatio[5] = DRIVER_TIM_MUNSON_GEAR_RATIO;
const u16 gDriverAndrewBishopGearRatio[5] = DRIVER_ANDREW_BISHOP_GEAR_RATIO;
const u16 gDriverDanielEvansGearRatio[5] = DRIVER_DANIEL_EVANS_GEAR_RATIO;
const u16 gDriverSeanKendrickGearRatio[5] = DRIVER_SEAN_KENDRICK_GEAR_RATIO;
const u16 gDriverJakeMayGearRatio[5] = DRIVER_JAKE_MAY_GEAR_RATIO;
const u16 gDriverChrisWalshGearRatio[5] = DRIVER_CHRIS_WALSH_GEAR_RATIO;
const u16 gDriverJamesDalyGearRatio[5] = DRIVER_JAMES_DALY_GEAR_RATIO;
const u16 gDriverAdamBouskillGearRatio[5] = DRIVER_ADAM_BOUSKILL_GEAR_RATIO;
const u16 gDriverTimCoodeGearRatio[5] = DRIVER_TIM_COODE_GEAR_RATIO;
const u16 gDriverWillGreenoughGearRatio[5] = DRIVER_WILL_GREENOUGH_GEAR_RATIO;
const u16 gDriverJonnieShearnGearRatio[5] = DRIVER_JONNIE_SHEARN_GEAR_RATIO;
const u16 gDriverDaveMurphyGearRatio[5] = DRIVER_DAVE_MURPHY_GEAR_RATIO;
const u16 gDriverDarrenJacksonGearRatio[5] = DRIVER_DARREN_JACKSON_GEAR_RATIO;
const u16 gDriverMikeMerrenGearRatio[5] = DRIVER_MIKE_MERREN_GEAR_RATIO;
const u16 gDriverCameronSheppardGearRatio[5] = DRIVER_CAMERON_SHEPPARD_GEAR_RATIO;
const u16 gDriverSteveParkRpmPerSpeed[5] = DRIVER_STEVE_PARK_RPM_PER_SPEED;
const u16 gDriverDaleEarnhardtJRRpmPerSpeed[5] = DRIVER_DALE_EARNHARDT_J_R_RPM_PER_SPEED;
const u16 gDriverKevinHarvickRpmPerSpeed[5] = DRIVER_KEVIN_HARVICK_RPM_PER_SPEED;
const u16 gDriverDaleJarrettRpmPerSpeed[5] = DRIVER_DALE_JARRETT_RPM_PER_SPEED;
const u16 gDriverRickyRuddRpmPerSpeed[5] = DRIVER_RICKY_RUDD_RPM_PER_SPEED;
const u16 gDriverJeffGordonRpmPerSpeed[5] = DRIVER_JEFF_GORDON_RPM_PER_SPEED;
const u16 gDriverJasonPopeRpmPerSpeed[5] = DRIVER_JASON_POPE_RPM_PER_SPEED;
const u16 gDriverJoeFriedRpmPerSpeed[5] = DRIVER_JOE_FRIED_RPM_PER_SPEED;
const u16 gDriverRustyWallaceRpmPerSpeed[5] = DRIVER_RUSTY_WALLACE_RPM_PER_SPEED;
const u16 gDriverSterlingMarlinRpmPerSpeed[5] = DRIVER_STERLING_MARLIN_RPM_PER_SPEED;
const u16 gDriverBrianLockeRpmPerSpeed[5] = DRIVER_BRIAN_LOCKE_RPM_PER_SPEED;
const u16 gDriverJayMcgeeRpmPerSpeed[5] = DRIVER_JAY_MCGEE_RPM_PER_SPEED;
const u16 gDriverMitchellSlaterRpmPerSpeed[5] = DRIVER_MITCHELL_SLATER_RPM_PER_SPEED;
const u16 gDriverJamesBrownRpmPerSpeed[5] = DRIVER_JAMES_BROWN_RPM_PER_SPEED;
const u16 gDriverNeilWilsonRpmPerSpeed[5] = DRIVER_NEIL_WILSON_RPM_PER_SPEED;
const u16 gDriverTimMunsonRpmPerSpeed[5] = DRIVER_TIM_MUNSON_RPM_PER_SPEED;
const u16 gDriverAndrewBishopRpmPerSpeed[5] = DRIVER_ANDREW_BISHOP_RPM_PER_SPEED;
const u16 gDriverDanielEvansRpmPerSpeed[5] = DRIVER_DANIEL_EVANS_RPM_PER_SPEED;
const u16 gDriverSeanKendrickRpmPerSpeed[5] = DRIVER_SEAN_KENDRICK_RPM_PER_SPEED;
const u16 gDriverJakeMayRpmPerSpeed[5] = DRIVER_JAKE_MAY_RPM_PER_SPEED;
const u16 gDriverChrisWalshRpmPerSpeed[5] = DRIVER_CHRIS_WALSH_RPM_PER_SPEED;
const u16 gDriverJamesDalyRpmPerSpeed[5] = DRIVER_JAMES_DALY_RPM_PER_SPEED;
const u16 gDriverAdamBouskillRpmPerSpeed[5] = DRIVER_ADAM_BOUSKILL_RPM_PER_SPEED;
const u16 gDriverTimCoodeRpmPerSpeed[5] = DRIVER_TIM_COODE_RPM_PER_SPEED;
const u16 gDriverWillGreenoughRpmPerSpeed[5] = DRIVER_WILL_GREENOUGH_RPM_PER_SPEED;
const u16 gDriverJonnieShearnRpmPerSpeed[5] = DRIVER_JONNIE_SHEARN_RPM_PER_SPEED;
const u16 gDriverDaveMurphyRpmPerSpeed[5] = DRIVER_DAVE_MURPHY_RPM_PER_SPEED;
const u16 gDriverDarrenJacksonRpmPerSpeed[5] = DRIVER_DARREN_JACKSON_RPM_PER_SPEED;
const u16 gDriverMikeMerrenRpmPerSpeed[5] = DRIVER_MIKE_MERREN_RPM_PER_SPEED;
const u16 gDriverCameronSheppardRpmPerSpeed[5] = DRIVER_CAMERON_SHEPPARD_RPM_PER_SPEED;

extern const u8 gText_Ok[];
extern const u8 gText_DamageLabel[];
extern const u8 gText_FuelLabel[];
extern const u8 gText_TiresLabel[];
extern const u8 gText_None[];
extern const u8 gText_Right2[];
extern const u8 gText_Left2[];
extern const u8 gText_AllTires[];
extern const u8 gText_None_2[];
extern const u8 gText_SplashAndDash[];
extern const u8 gText_FullTank[];
extern const u8 gText_NoRepair[];
extern const u8 gText_Repair[];
extern const u8 gText_Demo[];
extern const u8 gText_OutOfTime[];
extern const u16 gDriverSteveParkPower[];
extern const u16 gDriverDaleEarnhardtJRPower[];
extern const u16 gDriverKevinHarvickPower[];
extern const u16 gDriverDaleJarrettPower[];
extern const u16 gDriverRickyRuddPower[];
extern const u16 gDriverJeffGordonPower[];
extern const u16 gDriverJasonPopePower[];
extern const u16 gDriverJoeFriedPower[];
extern const u16 gDriverRustyWallacePower[];
extern const u16 gDriverSterlingMarlinPower[];
extern const u16 gDriverBrianLockePower[];
extern const u16 gDriverJayMcgeePower[];
extern const u16 gDriverMitchellSlaterPower[];
extern const u16 gDriverJamesBrownPower[];
extern const u16 gDriverNeilWilsonPower[];
extern const u16 gDriverTimMunsonPower[];
extern const u16 gDriverAndrewBishopPower[];
extern const u16 gDriverDanielEvansPower[];
extern const u16 gDriverSeanKendrickPower[];
extern const u16 gDriverJakeMayPower[];
extern const u16 gDriverChrisWalshPower[];
extern const u16 gDriverJamesDalyPower[];
extern const u16 gDriverAdamBouskillPower[];
extern const u16 gDriverTimCoodePower[];
extern const u16 gDriverWillGreenoughPower[];
extern const u16 gDriverJonnieShearnPower[];
extern const u16 gDriverDaveMurphyPower[];
extern const u16 gDriverDarrenJacksonPower[];
extern const u16 gDriverMikeMerrenPower[];
extern const u16 gDriverCameronSheppardPower[];
extern const u16 gDriverSteveParkGearRatio[];
extern const u16 gDriverDaleEarnhardtJRGearRatio[];
extern const u16 gDriverKevinHarvickGearRatio[];
extern const u16 gDriverDaleJarrettGearRatio[];
extern const u16 gDriverRickyRuddGearRatio[];
extern const u16 gDriverJeffGordonGearRatio[];
extern const u16 gDriverJasonPopeGearRatio[];
extern const u16 gDriverJoeFriedGearRatio[];
extern const u16 gDriverRustyWallaceGearRatio[];
extern const u16 gDriverSterlingMarlinGearRatio[];
extern const u16 gDriverBrianLockeGearRatio[];
extern const u16 gDriverJayMcgeeGearRatio[];
extern const u16 gDriverMitchellSlaterGearRatio[];
extern const u16 gDriverJamesBrownGearRatio[];
extern const u16 gDriverNeilWilsonGearRatio[];
extern const u16 gDriverTimMunsonGearRatio[];
extern const u16 gDriverAndrewBishopGearRatio[];
extern const u16 gDriverDanielEvansGearRatio[];
extern const u16 gDriverSeanKendrickGearRatio[];
extern const u16 gDriverJakeMayGearRatio[];
extern const u16 gDriverChrisWalshGearRatio[];
extern const u16 gDriverJamesDalyGearRatio[];
extern const u16 gDriverAdamBouskillGearRatio[];
extern const u16 gDriverTimCoodeGearRatio[];
extern const u16 gDriverWillGreenoughGearRatio[];
extern const u16 gDriverJonnieShearnGearRatio[];
extern const u16 gDriverDaveMurphyGearRatio[];
extern const u16 gDriverDarrenJacksonGearRatio[];
extern const u16 gDriverMikeMerrenGearRatio[];
extern const u16 gDriverCameronSheppardGearRatio[];
extern const u16 gDriverSteveParkRpmPerSpeed[];
extern const u16 gDriverDaleEarnhardtJRRpmPerSpeed[];
extern const u16 gDriverKevinHarvickRpmPerSpeed[];
extern const u16 gDriverDaleJarrettRpmPerSpeed[];
extern const u16 gDriverRickyRuddRpmPerSpeed[];
extern const u16 gDriverJeffGordonRpmPerSpeed[];
extern const u16 gDriverJasonPopeRpmPerSpeed[];
extern const u16 gDriverJoeFriedRpmPerSpeed[];
extern const u16 gDriverRustyWallaceRpmPerSpeed[];
extern const u16 gDriverSterlingMarlinRpmPerSpeed[];
extern const u16 gDriverBrianLockeRpmPerSpeed[];
extern const u16 gDriverJayMcgeeRpmPerSpeed[];
extern const u16 gDriverMitchellSlaterRpmPerSpeed[];
extern const u16 gDriverJamesBrownRpmPerSpeed[];
extern const u16 gDriverNeilWilsonRpmPerSpeed[];
extern const u16 gDriverTimMunsonRpmPerSpeed[];
extern const u16 gDriverAndrewBishopRpmPerSpeed[];
extern const u16 gDriverDanielEvansRpmPerSpeed[];
extern const u16 gDriverSeanKendrickRpmPerSpeed[];
extern const u16 gDriverJakeMayRpmPerSpeed[];
extern const u16 gDriverChrisWalshRpmPerSpeed[];
extern const u16 gDriverJamesDalyRpmPerSpeed[];
extern const u16 gDriverAdamBouskillRpmPerSpeed[];
extern const u16 gDriverTimCoodeRpmPerSpeed[];
extern const u16 gDriverWillGreenoughRpmPerSpeed[];
extern const u16 gDriverJonnieShearnRpmPerSpeed[];
extern const u16 gDriverDaveMurphyRpmPerSpeed[];
extern const u16 gDriverDarrenJacksonRpmPerSpeed[];
extern const u16 gDriverMikeMerrenRpmPerSpeed[];
extern const u16 gDriverCameronSheppardRpmPerSpeed[];
extern const u32 gDriverSteveParkNumberFrames[];
extern const u32 gDriverDaleEarnhardtJRNumberFrames[];
extern const u32 gDriverKevinHarvickNumberFrames[];
extern const u32 gDriverDaleJarrettNumberFrames[];
extern const u32 gDriverRickyRuddNumberFrames[];
extern const u32 gDriverJeffGordonNumberFrames[];
extern const u32 gDriverJasonPopeNumberFrames[];
extern const u32 gDriverJoeFriedNumberFrames[];
extern const u32 gDriverRustyWallaceNumberFrames[];
extern const u32 gDriverSterlingMarlinNumberFrames[];
extern const u32 gDriverBrianLockeNumberFrames[];
extern const u32 gDriverJayMcgeeNumberFrames[];
extern const u32 gDriverMitchellSlaterNumberFrames[];
extern const u32 gDriverJamesBrownNumberFrames[];
extern const u32 gDriverNeilWilsonNumberFrames[];
extern const u32 gDriverTimMunsonNumberFrames[];
extern const u32 gDriverAndrewBishopNumberFrames[];
extern const u32 gDriverDanielEvansNumberFrames[];
extern const u32 gDriverSeanKendrickNumberFrames[];
extern const u32 gDriverJakeMayNumberFrames[];
extern const u32 gDriverChrisWalshNumberFrames[];
extern const u32 gDriverJamesDalyNumberFrames[];
extern const u32 gDriverAdamBouskillNumberFrames[];
extern const u32 gDriverTimCoodeNumberFrames[];
extern const u32 gDriverWillGreenoughNumberFrames[];
extern const u32 gDriverJonnieShearnNumberFrames[];
extern const u32 gDriverDaveMurphyNumberFrames[];
extern const u32 gDriverDarrenJacksonNumberFrames[];
extern const u32 gDriverMikeMerrenNumberFrames[];
extern const u32 gDriverCameronSheppardNumberFrames[];
extern const u32 gLinkMarkerP1FrameList[];
extern const u32 gLinkMarkerP2FrameList[];
extern const u32 gLinkMarkerP3FrameList[];
extern const u32 gLinkMarkerP4FrameList[];

const u16 *const gDriverGearPowerTables[] = {
    gDriverSteveParkPower,      gDriverDaleEarnhardtJRPower, gDriverKevinHarvickPower, gDriverDaleJarrettPower,
    gDriverRickyRuddPower,      gDriverJeffGordonPower,      gDriverJasonPopePower,    gDriverJoeFriedPower,
    gDriverRustyWallacePower,   gDriverSterlingMarlinPower,  gDriverBrianLockePower,   gDriverJayMcgeePower,
    gDriverMitchellSlaterPower, gDriverJamesBrownPower,      gDriverNeilWilsonPower,   gDriverTimMunsonPower,
    gDriverAndrewBishopPower,   gDriverDanielEvansPower,     gDriverSeanKendrickPower, gDriverJakeMayPower,
    gDriverChrisWalshPower,     gDriverJamesDalyPower,       gDriverAdamBouskillPower, gDriverTimCoodePower,
    gDriverWillGreenoughPower,  gDriverJonnieShearnPower,    gDriverDaveMurphyPower,   gDriverDarrenJacksonPower,
    gDriverMikeMerrenPower,     gDriverCameronSheppardPower
};
const u16 *const gDriverGearRatioTables[] = {
    gDriverSteveParkGearRatio,      gDriverDaleEarnhardtJRGearRatio, gDriverKevinHarvickGearRatio,
    gDriverDaleJarrettGearRatio,    gDriverRickyRuddGearRatio,       gDriverJeffGordonGearRatio,
    gDriverJasonPopeGearRatio,      gDriverJoeFriedGearRatio,        gDriverRustyWallaceGearRatio,
    gDriverSterlingMarlinGearRatio, gDriverBrianLockeGearRatio,      gDriverJayMcgeeGearRatio,
    gDriverMitchellSlaterGearRatio, gDriverJamesBrownGearRatio,      gDriverNeilWilsonGearRatio,
    gDriverTimMunsonGearRatio,      gDriverAndrewBishopGearRatio,    gDriverDanielEvansGearRatio,
    gDriverSeanKendrickGearRatio,   gDriverJakeMayGearRatio,         gDriverChrisWalshGearRatio,
    gDriverJamesDalyGearRatio,      gDriverAdamBouskillGearRatio,    gDriverTimCoodeGearRatio,
    gDriverWillGreenoughGearRatio,  gDriverJonnieShearnGearRatio,    gDriverDaveMurphyGearRatio,
    gDriverDarrenJacksonGearRatio,  gDriverMikeMerrenGearRatio,      gDriverCameronSheppardGearRatio
};
const u16 *const gDriverRpmPerSpeedTables[] = {
    gDriverSteveParkRpmPerSpeed,      gDriverDaleEarnhardtJRRpmPerSpeed, gDriverKevinHarvickRpmPerSpeed,
    gDriverDaleJarrettRpmPerSpeed,    gDriverRickyRuddRpmPerSpeed,       gDriverJeffGordonRpmPerSpeed,
    gDriverJasonPopeRpmPerSpeed,      gDriverJoeFriedRpmPerSpeed,        gDriverRustyWallaceRpmPerSpeed,
    gDriverSterlingMarlinRpmPerSpeed, gDriverBrianLockeRpmPerSpeed,      gDriverJayMcgeeRpmPerSpeed,
    gDriverMitchellSlaterRpmPerSpeed, gDriverJamesBrownRpmPerSpeed,      gDriverNeilWilsonRpmPerSpeed,
    gDriverTimMunsonRpmPerSpeed,      gDriverAndrewBishopRpmPerSpeed,    gDriverDanielEvansRpmPerSpeed,
    gDriverSeanKendrickRpmPerSpeed,   gDriverJakeMayRpmPerSpeed,         gDriverChrisWalshRpmPerSpeed,
    gDriverJamesDalyRpmPerSpeed,      gDriverAdamBouskillRpmPerSpeed,    gDriverTimCoodeRpmPerSpeed,
    gDriverWillGreenoughRpmPerSpeed,  gDriverJonnieShearnRpmPerSpeed,    gDriverDaveMurphyRpmPerSpeed,
    gDriverDarrenJacksonRpmPerSpeed,  gDriverMikeMerrenRpmPerSpeed,      gDriverCameronSheppardRpmPerSpeed
};
const u32 gPitStopTireServiceTimes[4] = PIT_STOP_TIRE_SERVICE_TIMES;
const u32 gPitStopRepairTimes[2] = PIT_STOP_REPAIR_TIMES;
const u8 *const gPitMenuRowLabelTexts[] = { gText_TiresLabel, gText_FuelLabel, gText_DamageLabel, gText_Ok };
const u8 *const gPitMenuTireOptionTexts[] = { gText_AllTires, gText_Left2, gText_Right2, gText_None };
const u8 *const gPitMenuFuelOptionTexts[] = { gText_FullTank, gText_SplashAndDash, gText_None_2 };
const u8 *const gPitMenuRepairOptionTexts[] = { gText_Repair, gText_NoRepair };
const s32 gChallengeStartOffsetPercents[16] = CHALLENGE_START_OFFSET_PERCENTS;
const u8 gTrackStartOffsetPercents[12] = TRACK_START_OFFSET_PERCENTS;
const u8 gPitLaneIndices[12] = PIT_LANE_INDICES;
// Eight 16.16 fixed-point values (+/-16.0). No decompiled code reads them yet.
const s32 gUnk_083681C8[8] = UNK_083681C8;
// Its users declare it as u32 *x[], u32 x[].
const u32 *const gLinkMarkerFrameLists[] = { gLinkMarkerP1FrameList, gLinkMarkerP2FrameList, gLinkMarkerP3FrameList,
                                             gLinkMarkerP4FrameList };
// Its users declare it as u32 *x[].
const u32 *const gDriverNumberFrameLists[] = {
    gDriverSteveParkNumberFrames,      gDriverDaleEarnhardtJRNumberFrames, gDriverKevinHarvickNumberFrames,
    gDriverDaleJarrettNumberFrames,    gDriverRickyRuddNumberFrames,       gDriverJeffGordonNumberFrames,
    gDriverJasonPopeNumberFrames,      gDriverJoeFriedNumberFrames,        gDriverRustyWallaceNumberFrames,
    gDriverSterlingMarlinNumberFrames, gDriverBrianLockeNumberFrames,      gDriverJayMcgeeNumberFrames,
    gDriverMitchellSlaterNumberFrames, gDriverJamesBrownNumberFrames,      gDriverNeilWilsonNumberFrames,
    gDriverTimMunsonNumberFrames,      gDriverAndrewBishopNumberFrames,    gDriverDanielEvansNumberFrames,
    gDriverSeanKendrickNumberFrames,   gDriverJakeMayNumberFrames,         gDriverChrisWalshNumberFrames,
    gDriverJamesDalyNumberFrames,      gDriverAdamBouskillNumberFrames,    gDriverTimCoodeNumberFrames,
    gDriverWillGreenoughNumberFrames,  gDriverJonnieShearnNumberFrames,    gDriverDaveMurphyNumberFrames,
    gDriverDarrenJacksonNumberFrames,  gDriverMikeMerrenNumberFrames,      gDriverCameronSheppardNumberFrames
};
const s32 gCornerOffsetX[4] = CORNER_OFFSET_X;
const s32 gCornerOffsetZ[4] = CORNER_OFFSET_Z;
// The AI drag divisor per track (car/update.c).
const u16 gTrackAiDragDivisors[12] = TRACK_AI_DRAG_DIVISORS;
// No decompiled code reads this pointer pair yet.
const u8 *const gUnk_083682A8[] = { gText_Demo, gText_OutOfTime };
// One parameter per task spawned by AddTrackRecordTasks (records screen rows).
const u8 gRecordsTaskParams[12] = RECORDS_TASK_PARAMS;
