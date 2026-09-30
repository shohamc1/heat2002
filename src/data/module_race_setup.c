#include "global.h"
#include "structs.h"
#include "race_setup_tables.h"
#include "approach_constants.h"

/* Track 7's waypoint gates in the module's copy of the main program's
 * segs parts (data/rom_0835DCB8.s, EWRAM name). */
extern struct TrackSeg gUnk_02025E20[];

/* The frame lists src/data/module_championship_data.c defines, and the first
 * driver palette in the module's copy fragment data/rom_08354010.s. */
extern const u8 *const gModule_CarSpriteHalfAFrames[];
extern const u8 *const gModule_CarSpriteHalfBFrames[];
extern const u8 gModule_0201E748[];

/* no variables.h needed: ModuleInitCar.c declares the three pointer
   tables locally (as u32 x[], entry 31's view), and this file needs
   nothing else from it. */

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

/* The frame lists src/data/module_championship_data.c defines. */
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

/* High module (link slave) track-segment table (ROM 0x0835F440,
 * EWRAM 0x020269C0): the one row ModuleLoadTrackSegs loads its
 * gModule_TrackSegs from: gUnk_02025E20, track 7's records in the
 * module's copy of tracks 3-11's segs parts (data/rom_0835DCB8.s). */
const struct TrackSeg *const gModule_TrackSegTables[1] = { gUnk_02025E20 };

/* High module (link slave) sprite-cache slots, pit and points tables
 * (ROM 0x0835F444-0x0835F8A0, EWRAM 0x020269C4-0x02026E20), the twins of
 * the main program's gObjTileCache64Tiles to gRacePointsTable
 * (src/data/race_setup.c, which says what each is for): the numbers
 * build from race_setup_tables.h. The car sprite and palette tables
 * hold one row each, where the main program's hold 30. */

const u16 gModule_ObjTileCache64Tiles[4] = OBJ_TILE_CACHE_64_TILES;
const u16 gModule_ObjTileCache16Tiles[24] = OBJ_TILE_CACHE_16_TILES;
const u16 gModule_ObjTileCache2Tiles[32] = OBJ_TILE_CACHE_2_TILES;
const u16 gModule_ObjTileCache8Tiles[20] = OBJ_TILE_CACHE_8_TILES;
const u16 gModule_ObjTileCache4Tiles[16] = OBJ_TILE_CACHE_4_TILES;
const u16 gModule_ObjTileCache1Tiles[32] = OBJ_TILE_CACHE_1_TILES;
const u32 gModule_PitStallPositions[192] = PIT_STALL_POSITIONS;
const u16 gModule_PitEntryProgressPoints[12] = PIT_ENTRY_PROGRESS_POINTS;
const u16 gModule_PitExitProgressPoints[12] = PIT_EXIT_PROGRESS_POINTS;
const u8 gModule_RacePointsTable[32] = RACE_POINTS_TABLE;
const u8 *const *const gModule_DriverCarSpriteHalfATables[1] = { gModule_CarSpriteHalfAFrames };
const u8 *const *const gModule_DriverCarSpriteHalfBTables[1] = { gModule_CarSpriteHalfBFrames };
const u8 *const gModule_DriverPalettes[1] = { gModule_0201E748 };

/* High module (link slave) tire-grip setups (ROM 0x0835F8A0-0x0835FB0C,
 * EWRAM 0x02026E20-0x0202708C), byte-identical to the main program's
 * gTireGripDefaults (src/data/race_setup.c, which says what each row is
 * for): the ROM holds them twice, once per GBA. race_setup_tables.h
 * shares the initialisers, so one edit changes both copies.
 * ModuleSetTireGrip.c loads row 0 for every car in a link race. */
const struct TireGripSetup gModule_TireGripDefaults[31] = TIRE_GRIP_DEFAULTS;

/* The rest of the car setup tables (ROM 0x0835FB0C-0x0835FBFC, EWRAM
 * 0x0202708C-0x0202717C): track 7's row of the main program's
 * gTrackStartGrids, then the twins of its seven car setups and AI gear
 * rows, gUnk_08367B64 to gUnk_08367C2E (src/data/race_setup.c, which
 * says what each is for). Both build from race_setup_tables.h. */

const struct TrackGrid gModule_TrackStartGrids[1] = { TRACK_7_START_GRID };
const u16 gModule_020270A8[5] = UNK_08367B64;
const u16 gModule_020270B2[5] = UNK_08367B6E;
const u16 gModule_020270BC[5] = UNK_08367B78;
const u16 gModule_TuneDefaultGearPower[5] = TUNE_DEFAULT_GEAR_POWER;
const u16 gModule_TuneDefaultGearRatio[5] = TUNE_DEFAULT_GEAR_RATIO;
const u16 gModule_020270DA[5] = UNK_08367B96;
const u16 gModule_020270E4[5] = UNK_08367BA0;
const u16 gModule_020270EE[5] = UNK_08367BAA;
const u16 gModule_020270F8[5] = UNK_08367BB4;
const u16 gModule_02027102[5] = UNK_08367BBE;
const u16 gModule_0202710C[5] = UNK_08367BC8;
const u16 gModule_02027116[5] = UNK_08367BD2;
const u16 gModule_02027120[5] = UNK_08367BDC;
const u16 gModule_0202712A[5] = UNK_08367BE6;
const u16 gModule_02027134[5] = UNK_08367BF0;
const u16 gModule_AiDriverGearPowerTable[5] = AI_DRIVER_GEAR_POWER_TABLE;
const u16 gModule_02027148[1] = UNK_08367C04;
const u16 gModule_AiDriverGearRatioTable[5] = AI_DRIVER_GEAR_RATIO_TABLE;
const u16 gModule_AiDriverRpmPerSpeedTable[5] = AI_DRIVER_RPM_PER_SPEED_TABLE;
const u16 gModule_0202715E[5] = UNK_08367C1A;
const u16 gModule_02027168[5] = UNK_08367C24;
const u16 gModule_02027172[5] = UNK_08367C2E;

/* High module (link slave) driver engine parameters (ROM
 * 0x0835FBFC-0x083600E8, EWRAM 0x0202717C-0x02027668): one 5-entry u16
 * row per driver, 30 drivers in gDriverRoster order, then the three
 * pointer tables ModuleInitCar loads a car's gear/power rows through.
 * Byte-identical to the main program's gDriver*Power/GearRatio/
 * RpmPerSpeed rows and gDriverGearPowerTables/gDriverGearRatioTables/
 * gDriverRpmPerSpeedTables (src/data/race_setup.c, which says what each
 * row is for): the ROM holds them twice, once per GBA.
 * race_setup_tables.h shares the row initialisers, so one edit changes
 * both copies. */
const u16 gModule_DriverSteveParkPower[5] = DRIVER_STEVE_PARK_POWER;
const u16 gModule_DriverDaleEarnhardtJRPower[5] = DRIVER_DALE_EARNHARDT_J_R_POWER;
const u16 gModule_DriverKevinHarvickPower[5] = DRIVER_KEVIN_HARVICK_POWER;
const u16 gModule_DriverDaleJarrettPower[5] = DRIVER_DALE_JARRETT_POWER;
const u16 gModule_DriverRickyRuddPower[5] = DRIVER_RICKY_RUDD_POWER;
const u16 gModule_DriverJeffGordonPower[5] = DRIVER_JEFF_GORDON_POWER;
const u16 gModule_DriverJasonPopePower[5] = DRIVER_JASON_POPE_POWER;
const u16 gModule_DriverJoeFriedPower[5] = DRIVER_JOE_FRIED_POWER;
const u16 gModule_DriverRustyWallacePower[5] = DRIVER_RUSTY_WALLACE_POWER;
const u16 gModule_DriverSterlingMarlinPower[5] = DRIVER_STERLING_MARLIN_POWER;
const u16 gModule_DriverBrianLockePower[5] = DRIVER_BRIAN_LOCKE_POWER;
const u16 gModule_DriverJayMcgeePower[5] = DRIVER_JAY_MCGEE_POWER;
const u16 gModule_DriverMitchellSlaterPower[5] = DRIVER_MITCHELL_SLATER_POWER;
const u16 gModule_DriverJamesBrownPower[5] = DRIVER_JAMES_BROWN_POWER;
const u16 gModule_DriverNeilWilsonPower[5] = DRIVER_NEIL_WILSON_POWER;
const u16 gModule_DriverTimMunsonPower[5] = DRIVER_TIM_MUNSON_POWER;
const u16 gModule_DriverAndrewBishopPower[5] = DRIVER_ANDREW_BISHOP_POWER;
const u16 gModule_DriverDanielEvansPower[5] = DRIVER_DANIEL_EVANS_POWER;
const u16 gModule_DriverSeanKendrickPower[5] = DRIVER_SEAN_KENDRICK_POWER;
const u16 gModule_DriverJakeMayPower[5] = DRIVER_JAKE_MAY_POWER;
const u16 gModule_DriverChrisWalshPower[5] = DRIVER_CHRIS_WALSH_POWER;
const u16 gModule_DriverJamesDalyPower[5] = DRIVER_JAMES_DALY_POWER;
const u16 gModule_DriverAdamBouskillPower[5] = DRIVER_ADAM_BOUSKILL_POWER;
const u16 gModule_DriverTimCoodePower[5] = DRIVER_TIM_COODE_POWER;
const u16 gModule_DriverWillGreenoughPower[5] = DRIVER_WILL_GREENOUGH_POWER;
const u16 gModule_DriverJonnieShearnPower[5] = DRIVER_JONNIE_SHEARN_POWER;
const u16 gModule_DriverDaveMurphyPower[5] = DRIVER_DAVE_MURPHY_POWER;
const u16 gModule_DriverDarrenJacksonPower[5] = DRIVER_DARREN_JACKSON_POWER;
const u16 gModule_DriverMikeMerrenPower[5] = DRIVER_MIKE_MERREN_POWER;
const u16 gModule_DriverCameronSheppardPower[5] = DRIVER_CAMERON_SHEPPARD_POWER;
const u16 gModule_DriverSteveParkGearRatio[5] = DRIVER_STEVE_PARK_GEAR_RATIO;
const u16 gModule_DriverDaleEarnhardtJRGearRatio[5] = DRIVER_DALE_EARNHARDT_J_R_GEAR_RATIO;
const u16 gModule_DriverKevinHarvickGearRatio[5] = DRIVER_KEVIN_HARVICK_GEAR_RATIO;
const u16 gModule_DriverDaleJarrettGearRatio[5] = DRIVER_DALE_JARRETT_GEAR_RATIO;
const u16 gModule_DriverRickyRuddGearRatio[5] = DRIVER_RICKY_RUDD_GEAR_RATIO;
const u16 gModule_DriverJeffGordonGearRatio[5] = DRIVER_JEFF_GORDON_GEAR_RATIO;
const u16 gModule_DriverJasonPopeGearRatio[5] = DRIVER_JASON_POPE_GEAR_RATIO;
const u16 gModule_DriverJoeFriedGearRatio[5] = DRIVER_JOE_FRIED_GEAR_RATIO;
const u16 gModule_DriverRustyWallaceGearRatio[5] = DRIVER_RUSTY_WALLACE_GEAR_RATIO;
const u16 gModule_DriverSterlingMarlinGearRatio[5] = DRIVER_STERLING_MARLIN_GEAR_RATIO;
const u16 gModule_DriverBrianLockeGearRatio[5] = DRIVER_BRIAN_LOCKE_GEAR_RATIO;
const u16 gModule_DriverJayMcgeeGearRatio[5] = DRIVER_JAY_MCGEE_GEAR_RATIO;
const u16 gModule_DriverMitchellSlaterGearRatio[5] = DRIVER_MITCHELL_SLATER_GEAR_RATIO;
const u16 gModule_DriverJamesBrownGearRatio[5] = DRIVER_JAMES_BROWN_GEAR_RATIO;
const u16 gModule_DriverNeilWilsonGearRatio[5] = DRIVER_NEIL_WILSON_GEAR_RATIO;
const u16 gModule_DriverTimMunsonGearRatio[5] = DRIVER_TIM_MUNSON_GEAR_RATIO;
const u16 gModule_DriverAndrewBishopGearRatio[5] = DRIVER_ANDREW_BISHOP_GEAR_RATIO;
const u16 gModule_DriverDanielEvansGearRatio[5] = DRIVER_DANIEL_EVANS_GEAR_RATIO;
const u16 gModule_DriverSeanKendrickGearRatio[5] = DRIVER_SEAN_KENDRICK_GEAR_RATIO;
const u16 gModule_DriverJakeMayGearRatio[5] = DRIVER_JAKE_MAY_GEAR_RATIO;
const u16 gModule_DriverChrisWalshGearRatio[5] = DRIVER_CHRIS_WALSH_GEAR_RATIO;
const u16 gModule_DriverJamesDalyGearRatio[5] = DRIVER_JAMES_DALY_GEAR_RATIO;
const u16 gModule_DriverAdamBouskillGearRatio[5] = DRIVER_ADAM_BOUSKILL_GEAR_RATIO;
const u16 gModule_DriverTimCoodeGearRatio[5] = DRIVER_TIM_COODE_GEAR_RATIO;
const u16 gModule_DriverWillGreenoughGearRatio[5] = DRIVER_WILL_GREENOUGH_GEAR_RATIO;
const u16 gModule_DriverJonnieShearnGearRatio[5] = DRIVER_JONNIE_SHEARN_GEAR_RATIO;
const u16 gModule_DriverDaveMurphyGearRatio[5] = DRIVER_DAVE_MURPHY_GEAR_RATIO;
const u16 gModule_DriverDarrenJacksonGearRatio[5] = DRIVER_DARREN_JACKSON_GEAR_RATIO;
const u16 gModule_DriverMikeMerrenGearRatio[5] = DRIVER_MIKE_MERREN_GEAR_RATIO;
const u16 gModule_DriverCameronSheppardGearRatio[5] = DRIVER_CAMERON_SHEPPARD_GEAR_RATIO;
const u16 gModule_DriverSteveParkRpmPerSpeed[5] = DRIVER_STEVE_PARK_RPM_PER_SPEED;
const u16 gModule_DriverDaleEarnhardtJRRpmPerSpeed[5] = DRIVER_DALE_EARNHARDT_J_R_RPM_PER_SPEED;
const u16 gModule_DriverKevinHarvickRpmPerSpeed[5] = DRIVER_KEVIN_HARVICK_RPM_PER_SPEED;
const u16 gModule_DriverDaleJarrettRpmPerSpeed[5] = DRIVER_DALE_JARRETT_RPM_PER_SPEED;
const u16 gModule_DriverRickyRuddRpmPerSpeed[5] = DRIVER_RICKY_RUDD_RPM_PER_SPEED;
const u16 gModule_DriverJeffGordonRpmPerSpeed[5] = DRIVER_JEFF_GORDON_RPM_PER_SPEED;
const u16 gModule_DriverJasonPopeRpmPerSpeed[5] = DRIVER_JASON_POPE_RPM_PER_SPEED;
const u16 gModule_DriverJoeFriedRpmPerSpeed[5] = DRIVER_JOE_FRIED_RPM_PER_SPEED;
const u16 gModule_DriverRustyWallaceRpmPerSpeed[5] = DRIVER_RUSTY_WALLACE_RPM_PER_SPEED;
const u16 gModule_DriverSterlingMarlinRpmPerSpeed[5] = DRIVER_STERLING_MARLIN_RPM_PER_SPEED;
const u16 gModule_DriverBrianLockeRpmPerSpeed[5] = DRIVER_BRIAN_LOCKE_RPM_PER_SPEED;
const u16 gModule_DriverJayMcgeeRpmPerSpeed[5] = DRIVER_JAY_MCGEE_RPM_PER_SPEED;
const u16 gModule_DriverMitchellSlaterRpmPerSpeed[5] = DRIVER_MITCHELL_SLATER_RPM_PER_SPEED;
const u16 gModule_DriverJamesBrownRpmPerSpeed[5] = DRIVER_JAMES_BROWN_RPM_PER_SPEED;
const u16 gModule_DriverNeilWilsonRpmPerSpeed[5] = DRIVER_NEIL_WILSON_RPM_PER_SPEED;
const u16 gModule_DriverTimMunsonRpmPerSpeed[5] = DRIVER_TIM_MUNSON_RPM_PER_SPEED;
const u16 gModule_DriverAndrewBishopRpmPerSpeed[5] = DRIVER_ANDREW_BISHOP_RPM_PER_SPEED;
const u16 gModule_DriverDanielEvansRpmPerSpeed[5] = DRIVER_DANIEL_EVANS_RPM_PER_SPEED;
const u16 gModule_DriverSeanKendrickRpmPerSpeed[5] = DRIVER_SEAN_KENDRICK_RPM_PER_SPEED;
const u16 gModule_DriverJakeMayRpmPerSpeed[5] = DRIVER_JAKE_MAY_RPM_PER_SPEED;
const u16 gModule_DriverChrisWalshRpmPerSpeed[5] = DRIVER_CHRIS_WALSH_RPM_PER_SPEED;
const u16 gModule_DriverJamesDalyRpmPerSpeed[5] = DRIVER_JAMES_DALY_RPM_PER_SPEED;
const u16 gModule_DriverAdamBouskillRpmPerSpeed[5] = DRIVER_ADAM_BOUSKILL_RPM_PER_SPEED;
const u16 gModule_DriverTimCoodeRpmPerSpeed[5] = DRIVER_TIM_COODE_RPM_PER_SPEED;
const u16 gModule_DriverWillGreenoughRpmPerSpeed[5] = DRIVER_WILL_GREENOUGH_RPM_PER_SPEED;
const u16 gModule_DriverJonnieShearnRpmPerSpeed[5] = DRIVER_JONNIE_SHEARN_RPM_PER_SPEED;
const u16 gModule_DriverDaveMurphyRpmPerSpeed[5] = DRIVER_DAVE_MURPHY_RPM_PER_SPEED;
const u16 gModule_DriverDarrenJacksonRpmPerSpeed[5] = DRIVER_DARREN_JACKSON_RPM_PER_SPEED;
const u16 gModule_DriverMikeMerrenRpmPerSpeed[5] = DRIVER_MIKE_MERREN_RPM_PER_SPEED;
const u16 gModule_DriverCameronSheppardRpmPerSpeed[5] = DRIVER_CAMERON_SHEPPARD_RPM_PER_SPEED;

const u16 *const gModule_DriverGearPowerTables[30] = {
    gModule_DriverSteveParkPower, gModule_DriverDaleEarnhardtJRPower, gModule_DriverKevinHarvickPower, gModule_DriverDaleJarrettPower,
    gModule_DriverRickyRuddPower, gModule_DriverJeffGordonPower, gModule_DriverJasonPopePower, gModule_DriverJoeFriedPower,
    gModule_DriverRustyWallacePower, gModule_DriverSterlingMarlinPower, gModule_DriverBrianLockePower, gModule_DriverJayMcgeePower,
    gModule_DriverMitchellSlaterPower, gModule_DriverJamesBrownPower, gModule_DriverNeilWilsonPower, gModule_DriverTimMunsonPower,
    gModule_DriverAndrewBishopPower, gModule_DriverDanielEvansPower, gModule_DriverSeanKendrickPower, gModule_DriverJakeMayPower,
    gModule_DriverChrisWalshPower, gModule_DriverJamesDalyPower, gModule_DriverAdamBouskillPower, gModule_DriverTimCoodePower,
    gModule_DriverWillGreenoughPower, gModule_DriverJonnieShearnPower, gModule_DriverDaveMurphyPower, gModule_DriverDarrenJacksonPower,
    gModule_DriverMikeMerrenPower, gModule_DriverCameronSheppardPower,
};
const u16 *const gModule_DriverGearRatioTables[30] = {
    gModule_DriverSteveParkGearRatio, gModule_DriverDaleEarnhardtJRGearRatio, gModule_DriverKevinHarvickGearRatio, gModule_DriverDaleJarrettGearRatio,
    gModule_DriverRickyRuddGearRatio, gModule_DriverJeffGordonGearRatio, gModule_DriverJasonPopeGearRatio, gModule_DriverJoeFriedGearRatio,
    gModule_DriverRustyWallaceGearRatio, gModule_DriverSterlingMarlinGearRatio, gModule_DriverBrianLockeGearRatio, gModule_DriverJayMcgeeGearRatio,
    gModule_DriverMitchellSlaterGearRatio, gModule_DriverJamesBrownGearRatio, gModule_DriverNeilWilsonGearRatio, gModule_DriverTimMunsonGearRatio,
    gModule_DriverAndrewBishopGearRatio, gModule_DriverDanielEvansGearRatio, gModule_DriverSeanKendrickGearRatio, gModule_DriverJakeMayGearRatio,
    gModule_DriverChrisWalshGearRatio, gModule_DriverJamesDalyGearRatio, gModule_DriverAdamBouskillGearRatio, gModule_DriverTimCoodeGearRatio,
    gModule_DriverWillGreenoughGearRatio, gModule_DriverJonnieShearnGearRatio, gModule_DriverDaveMurphyGearRatio, gModule_DriverDarrenJacksonGearRatio,
    gModule_DriverMikeMerrenGearRatio, gModule_DriverCameronSheppardGearRatio,
};
const u16 *const gModule_DriverRpmPerSpeedTables[30] = {
    gModule_DriverSteveParkRpmPerSpeed, gModule_DriverDaleEarnhardtJRRpmPerSpeed, gModule_DriverKevinHarvickRpmPerSpeed, gModule_DriverDaleJarrettRpmPerSpeed,
    gModule_DriverRickyRuddRpmPerSpeed, gModule_DriverJeffGordonRpmPerSpeed, gModule_DriverJasonPopeRpmPerSpeed, gModule_DriverJoeFriedRpmPerSpeed,
    gModule_DriverRustyWallaceRpmPerSpeed, gModule_DriverSterlingMarlinRpmPerSpeed, gModule_DriverBrianLockeRpmPerSpeed, gModule_DriverJayMcgeeRpmPerSpeed,
    gModule_DriverMitchellSlaterRpmPerSpeed, gModule_DriverJamesBrownRpmPerSpeed, gModule_DriverNeilWilsonRpmPerSpeed, gModule_DriverTimMunsonRpmPerSpeed,
    gModule_DriverAndrewBishopRpmPerSpeed, gModule_DriverDanielEvansRpmPerSpeed, gModule_DriverSeanKendrickRpmPerSpeed, gModule_DriverJakeMayRpmPerSpeed,
    gModule_DriverChrisWalshRpmPerSpeed, gModule_DriverJamesDalyRpmPerSpeed, gModule_DriverAdamBouskillRpmPerSpeed, gModule_DriverTimCoodeRpmPerSpeed,
    gModule_DriverWillGreenoughRpmPerSpeed, gModule_DriverJonnieShearnRpmPerSpeed, gModule_DriverDaveMurphyRpmPerSpeed, gModule_DriverDarrenJacksonRpmPerSpeed,
    gModule_DriverMikeMerrenRpmPerSpeed, gModule_DriverCameronSheppardRpmPerSpeed,
};

/* The twins of the main program's pit stop service times,
 * gPitStopTireServiceTimes and gPitStopRepairTimes (src/data/
 * race_setup.c), at ROM 0x083600E8-0x08360100. No module code reads
 * them. */
const u32 gModule_PitStopTireServiceTimes[4] = PIT_STOP_TIRE_SERVICE_TIMES;
const u32 gModule_PitStopRepairTimes[2] = PIT_STOP_REPAIR_TIMES;

/* High module (link slave) pit-menu option text tables (ROM
 * 0x08360100-0x0836012C, EWRAM 0x02027680-0x020276AC): the fixed row labels
 * and the tyre and fuel option rows, in the main program's order
 * sub_083402D8.c draws, the twins of the main program's
 * gPitMenuRowLabelTexts / gPitMenuTireOptionTexts / gPitMenuFuelOptionTexts
 * (src/data/race_setup.c). Each entry points into gModule_PitLabelBlock's
 * packed strings. */
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
