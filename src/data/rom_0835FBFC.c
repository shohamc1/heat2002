#include "global.h"
#include "race_setup_tables.h"

/* no variables.h needed: ModuleInitCar.c declares the three pointer
   tables locally (as u32 x[], entry 31's view), and this file needs
   nothing else from it. */

/* High module (link slave) driver engine parameters (ROM
 * 0x0835FBFC-0x083600E8, EWRAM 0x0202767C-0x02027B68): one 5-entry u16
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
