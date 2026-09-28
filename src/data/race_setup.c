#include "global.h"
#include "data.h"

/* Driver engine parameters, one 5-entry u16 row per driver (30 drivers,
 * in gDriverRoster order: rows are teammates in pairs, which is why
 * consecutive rows repeat. Named gDriver<Name><Power|GearRatio|RpmPerSpeed>.
 * 0x08367C38-0x08367FBC: power, gear ratios, rpm-per-speed, then the
 * race setup tables (pit stop times, pit menu texts, start offsets,
 * frame lists, corner offsets) through 0x083682BC. */

const u16 gDriverSteveParkPower[5] = { 680, 640, 700, 680, 720 };
const u16 gDriverDaleEarnhardtJRPower[5] = { 560, 560, 640, 680, 720 };
const u16 gDriverKevinHarvickPower[5] = { 480, 560, 640, 680, 680 };
const u16 gDriverDaleJarrettPower[5] = { 480, 560, 640, 680, 680 };
const u16 gDriverRickyRuddPower[5] = { 400, 440, 600, 640, 680 };
const u16 gDriverJeffGordonPower[5] = { 400, 440, 600, 640, 680 };
const u16 gDriverJasonPopePower[5] = { 400, 440, 600, 640, 720 };
const u16 gDriverJoeFriedPower[5] = { 400, 440, 600, 640, 720 };
const u16 gDriverRustyWallacePower[5] = { 400, 520, 600, 680, 720 };
const u16 gDriverSterlingMarlinPower[5] = { 400, 520, 600, 680, 720 };
const u16 gDriverBrianLockePower[5] = { 400, 440, 520, 640, 720 };
const u16 gDriverJayMcgeePower[5] = { 440, 480, 640, 640, 680 };
const u16 gDriverMitchellSlaterPower[5] = { 480, 520, 560, 640, 720 };
const u16 gDriverJamesBrownPower[5] = { 480, 520, 560, 640, 720 };
const u16 gDriverNeilWilsonPower[5] = { 400, 440, 520, 640, 720 };
const u16 gDriverTimMunsonPower[5] = { 480, 520, 560, 680, 720 };
const u16 gDriverAndrewBishopPower[5] = { 480, 520, 560, 600, 640 };
const u16 gDriverDanielEvansPower[5] = { 520, 600, 640, 680, 720 };
const u16 gDriverSeanKendrickPower[5] = { 520, 600, 680, 680, 720 };
const u16 gDriverJakeMayPower[5] = { 520, 560, 600, 680, 720 };
const u16 gDriverChrisWalshPower[5] = { 400, 440, 520, 640, 720 };
const u16 gDriverJamesDalyPower[5] = { 440, 480, 640, 640, 680 };
const u16 gDriverAdamBouskillPower[5] = { 480, 520, 560, 640, 720 };
const u16 gDriverTimCoodePower[5] = { 480, 520, 560, 640, 720 };
const u16 gDriverWillGreenoughPower[5] = { 400, 440, 520, 640, 720 };
const u16 gDriverJonnieShearnPower[5] = { 480, 520, 560, 680, 720 };
const u16 gDriverDaveMurphyPower[5] = { 480, 520, 560, 600, 640 };
const u16 gDriverDarrenJacksonPower[5] = { 520, 600, 640, 680, 720 };
const u16 gDriverMikeMerrenPower[5] = { 520, 600, 680, 680, 720 };
const u16 gDriverCameronSheppardPower[5] = { 520, 560, 600, 680, 720 };
const u16 gDriverSteveParkGearRatio[5] = { 6000, 8600, 9300, 13600, 16600 };
const u16 gDriverDaleEarnhardtJRGearRatio[5] = { 6000, 8600, 9300, 13600, 16600 };
const u16 gDriverKevinHarvickGearRatio[5] = { 6800, 8000, 9700, 12000, 13800 };
const u16 gDriverDaleJarrettGearRatio[5] = { 6800, 8000, 9700, 12000, 13800 };
const u16 gDriverRickyRuddGearRatio[5] = { 6800, 7600, 9700, 10000, 13400 };
const u16 gDriverJeffGordonGearRatio[5] = { 6800, 7600, 9700, 10000, 13400 };
const u16 gDriverJasonPopeGearRatio[5] = { 6800, 7600, 9700, 10000, 13400 };
const u16 gDriverJoeFriedGearRatio[5] = { 6800, 7600, 9700, 10000, 13400 };
const u16 gDriverRustyWallaceGearRatio[5] = { 6000, 8000, 9700, 11200, 14200 };
const u16 gDriverSterlingMarlinGearRatio[5] = { 6000, 8000, 9700, 11200, 14200 };
const u16 gDriverBrianLockeGearRatio[5] = { 6800, 7600, 9700, 11200, 13800 };
const u16 gDriverJayMcgeeGearRatio[5] = { 6400, 8000, 9700, 10400, 13000 };
const u16 gDriverMitchellSlaterGearRatio[5] = { 6800, 8400, 10100, 12000, 14000 };
const u16 gDriverJamesBrownGearRatio[5] = { 6800, 8400, 10100, 12000, 14000 };
const u16 gDriverNeilWilsonGearRatio[5] = { 6800, 7600, 9700, 11200, 13800 };
const u16 gDriverTimMunsonGearRatio[5] = { 7200, 8400, 10100, 12000, 14600 };
const u16 gDriverAndrewBishopGearRatio[5] = { 7200, 8400, 10100, 12000, 16600 };
const u16 gDriverDanielEvansGearRatio[5] = { 6000, 8400, 10100, 12400, 15000 };
const u16 gDriverSeanKendrickGearRatio[5] = { 6800, 8400, 10100, 12400, 15000 };
const u16 gDriverJakeMayGearRatio[5] = { 6000, 8400, 10100, 11200, 15000 };
const u16 gDriverChrisWalshGearRatio[5] = { 6800, 7600, 9700, 11200, 13800 };
const u16 gDriverJamesDalyGearRatio[5] = { 6400, 8000, 9700, 10400, 13000 };
const u16 gDriverAdamBouskillGearRatio[5] = { 6800, 8400, 10100, 12000, 14000 };
const u16 gDriverTimCoodeGearRatio[5] = { 6800, 8400, 10100, 12000, 14000 };
const u16 gDriverWillGreenoughGearRatio[5] = { 6800, 7600, 9700, 11200, 13800 };
const u16 gDriverJonnieShearnGearRatio[5] = { 7200, 8400, 10100, 12000, 14600 };
const u16 gDriverDaveMurphyGearRatio[5] = { 7200, 8400, 10100, 12000, 16600 };
const u16 gDriverDarrenJacksonGearRatio[5] = { 6000, 8400, 10100, 12400, 15000 };
const u16 gDriverMikeMerrenGearRatio[5] = { 6800, 8400, 10100, 12400, 15000 };
const u16 gDriverCameronSheppardGearRatio[5] = { 6000, 8400, 10100, 11200, 15000 };
const u16 gDriverSteveParkRpmPerSpeed[5] = { 10, 7, 7, 4, 3 };
const u16 gDriverDaleEarnhardtJRRpmPerSpeed[5] = { 10, 7, 7, 4, 3 };
const u16 gDriverKevinHarvickRpmPerSpeed[5] = { 9, 8, 6, 5, 4 };
const u16 gDriverDaleJarrettRpmPerSpeed[5] = { 9, 8, 6, 5, 4 };
const u16 gDriverRickyRuddRpmPerSpeed[5] = { 9, 8, 6, 6, 4 };
const u16 gDriverJeffGordonRpmPerSpeed[5] = { 9, 8, 6, 6, 4 };
const u16 gDriverJasonPopeRpmPerSpeed[5] = { 9, 8, 6, 6, 4 };
const u16 gDriverJoeFriedRpmPerSpeed[5] = { 9, 8, 6, 6, 4 };
const u16 gDriverRustyWallaceRpmPerSpeed[5] = { 10, 8, 6, 5, 4 };
const u16 gDriverSterlingMarlinRpmPerSpeed[5] = { 10, 8, 6, 5, 4 };
const u16 gDriverBrianLockeRpmPerSpeed[5] = { 9, 8, 6, 5, 4 };
const u16 gDriverJayMcgeeRpmPerSpeed[5] = { 10, 8, 6, 6, 5 };
const u16 gDriverMitchellSlaterRpmPerSpeed[5] = { 9, 7, 6, 5, 4 };
const u16 gDriverJamesBrownRpmPerSpeed[5] = { 9, 7, 6, 5, 4 };
const u16 gDriverNeilWilsonRpmPerSpeed[5] = { 9, 8, 6, 5, 4 };
const u16 gDriverTimMunsonRpmPerSpeed[5] = { 9, 7, 6, 5, 4 };
const u16 gDriverAndrewBishopRpmPerSpeed[5] = { 9, 7, 6, 5, 3 };
const u16 gDriverDanielEvansRpmPerSpeed[5] = { 10, 7, 6, 5, 4 };
const u16 gDriverSeanKendrickRpmPerSpeed[5] = { 9, 7, 6, 5, 4 };
const u16 gDriverJakeMayRpmPerSpeed[5] = { 10, 7, 6, 5, 4 };
const u16 gDriverChrisWalshRpmPerSpeed[5] = { 9, 8, 6, 5, 4 };
const u16 gDriverJamesDalyRpmPerSpeed[5] = { 10, 8, 6, 6, 5 };
const u16 gDriverAdamBouskillRpmPerSpeed[5] = { 9, 7, 6, 5, 4 };
const u16 gDriverTimCoodeRpmPerSpeed[5] = { 9, 7, 6, 5, 4 };
const u16 gDriverWillGreenoughRpmPerSpeed[5] = { 9, 8, 6, 5, 4 };
const u16 gDriverJonnieShearnRpmPerSpeed[5] = { 9, 7, 6, 5, 4 };
const u16 gDriverDaveMurphyRpmPerSpeed[5] = { 9, 7, 6, 5, 3 };
const u16 gDriverDarrenJacksonRpmPerSpeed[5] = { 10, 7, 6, 5, 4 };
const u16 gDriverMikeMerrenRpmPerSpeed[5] = { 9, 7, 6, 5, 4 };
const u16 gDriverCameronSheppardRpmPerSpeed[5] = { 10, 7, 6, 5, 4 };

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
    gDriverSteveParkPower, gDriverDaleEarnhardtJRPower, gDriverKevinHarvickPower,
    gDriverDaleJarrettPower, gDriverRickyRuddPower, gDriverJeffGordonPower,
    gDriverJasonPopePower, gDriverJoeFriedPower, gDriverRustyWallacePower,
    gDriverSterlingMarlinPower, gDriverBrianLockePower, gDriverJayMcgeePower,
    gDriverMitchellSlaterPower, gDriverJamesBrownPower, gDriverNeilWilsonPower,
    gDriverTimMunsonPower, gDriverAndrewBishopPower, gDriverDanielEvansPower,
    gDriverSeanKendrickPower, gDriverJakeMayPower, gDriverChrisWalshPower,
    gDriverJamesDalyPower, gDriverAdamBouskillPower, gDriverTimCoodePower,
    gDriverWillGreenoughPower, gDriverJonnieShearnPower, gDriverDaveMurphyPower,
    gDriverDarrenJacksonPower, gDriverMikeMerrenPower, gDriverCameronSheppardPower
};
const u16 *const gDriverGearRatioTables[] = {
    gDriverSteveParkGearRatio, gDriverDaleEarnhardtJRGearRatio, gDriverKevinHarvickGearRatio,
    gDriverDaleJarrettGearRatio, gDriverRickyRuddGearRatio, gDriverJeffGordonGearRatio,
    gDriverJasonPopeGearRatio, gDriverJoeFriedGearRatio, gDriverRustyWallaceGearRatio,
    gDriverSterlingMarlinGearRatio, gDriverBrianLockeGearRatio, gDriverJayMcgeeGearRatio,
    gDriverMitchellSlaterGearRatio, gDriverJamesBrownGearRatio, gDriverNeilWilsonGearRatio,
    gDriverTimMunsonGearRatio, gDriverAndrewBishopGearRatio, gDriverDanielEvansGearRatio,
    gDriverSeanKendrickGearRatio, gDriverJakeMayGearRatio, gDriverChrisWalshGearRatio,
    gDriverJamesDalyGearRatio, gDriverAdamBouskillGearRatio, gDriverTimCoodeGearRatio,
    gDriverWillGreenoughGearRatio, gDriverJonnieShearnGearRatio, gDriverDaveMurphyGearRatio,
    gDriverDarrenJacksonGearRatio, gDriverMikeMerrenGearRatio, gDriverCameronSheppardGearRatio
};
const u16 *const gDriverRpmPerSpeedTables[] = {
    gDriverSteveParkRpmPerSpeed, gDriverDaleEarnhardtJRRpmPerSpeed, gDriverKevinHarvickRpmPerSpeed,
    gDriverDaleJarrettRpmPerSpeed, gDriverRickyRuddRpmPerSpeed, gDriverJeffGordonRpmPerSpeed,
    gDriverJasonPopeRpmPerSpeed, gDriverJoeFriedRpmPerSpeed, gDriverRustyWallaceRpmPerSpeed,
    gDriverSterlingMarlinRpmPerSpeed, gDriverBrianLockeRpmPerSpeed, gDriverJayMcgeeRpmPerSpeed,
    gDriverMitchellSlaterRpmPerSpeed, gDriverJamesBrownRpmPerSpeed, gDriverNeilWilsonRpmPerSpeed,
    gDriverTimMunsonRpmPerSpeed, gDriverAndrewBishopRpmPerSpeed, gDriverDanielEvansRpmPerSpeed,
    gDriverSeanKendrickRpmPerSpeed, gDriverJakeMayRpmPerSpeed, gDriverChrisWalshRpmPerSpeed,
    gDriverJamesDalyRpmPerSpeed, gDriverAdamBouskillRpmPerSpeed, gDriverTimCoodeRpmPerSpeed,
    gDriverWillGreenoughRpmPerSpeed, gDriverJonnieShearnRpmPerSpeed, gDriverDaveMurphyRpmPerSpeed,
    gDriverDarrenJacksonRpmPerSpeed, gDriverMikeMerrenRpmPerSpeed, gDriverCameronSheppardRpmPerSpeed
};
const u32 gPitStopTireServiceTimes[4] = { 12800, 6400, 6400, 256 };
const u32 gPitStopRepairTimes[2] = { 12800, 256 };
const u8 *const gPitMenuRowLabelTexts[] = {
    gText_TiresLabel, gText_FuelLabel, gText_DamageLabel,
    gText_Ok
};
const u8 *const gPitMenuTireOptionTexts[] = {
    gText_AllTires, gText_Left2, gText_Right2,
    gText_None
};
const u8 *const gPitMenuFuelOptionTexts[] = {
    gText_FullTank, gText_SplashAndDash, gText_None_2
};
const u8 *const gPitMenuRepairOptionTexts[] = {
    gText_Repair, gText_NoRepair
};
const s32 gChallengeStartOffsetPercents[16] = { 50, 30, 96, 90, 30, 50, 45, 75, 75, 50, 50, 75, 15, 92, 88, 50 };
const u8 gTrackStartOffsetPercents[12] = { 50, 80, 35, 40, 35, 35, 90, 50, 45, 35, 60, 40 };
const u8 gPitLaneIndices[44] = { 7, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 240, 255, 0, 0, 240, 255, 0, 0, 16, 0, 0, 0, 240, 255, 0, 0, 240, 255, 0, 0, 16, 0, 0, 0, 16, 0, 0, 0, 16, 0 };
// Its users declare it as u32 *x[], u32 x[].
const u32 *const gLinkMarkerFrameLists[] = {
    gLinkMarkerP1FrameList, gLinkMarkerP2FrameList, gLinkMarkerP3FrameList,
    gLinkMarkerP4FrameList
};
// Its users declare it as u32 *x[].
const u32 *const gDriverNumberFrameLists[] = {
    gDriverSteveParkNumberFrames, gDriverDaleEarnhardtJRNumberFrames, gDriverKevinHarvickNumberFrames,
    gDriverDaleJarrettNumberFrames, gDriverRickyRuddNumberFrames, gDriverJeffGordonNumberFrames,
    gDriverJasonPopeNumberFrames, gDriverJoeFriedNumberFrames, gDriverRustyWallaceNumberFrames,
    gDriverSterlingMarlinNumberFrames, gDriverBrianLockeNumberFrames, gDriverJayMcgeeNumberFrames,
    gDriverMitchellSlaterNumberFrames, gDriverJamesBrownNumberFrames, gDriverNeilWilsonNumberFrames,
    gDriverTimMunsonNumberFrames, gDriverAndrewBishopNumberFrames, gDriverDanielEvansNumberFrames,
    gDriverSeanKendrickNumberFrames, gDriverJakeMayNumberFrames, gDriverChrisWalshNumberFrames,
    gDriverJamesDalyNumberFrames, gDriverAdamBouskillNumberFrames, gDriverTimCoodeNumberFrames,
    gDriverWillGreenoughNumberFrames, gDriverJonnieShearnNumberFrames, gDriverDaveMurphyNumberFrames,
    gDriverDarrenJacksonNumberFrames, gDriverMikeMerrenNumberFrames, gDriverCameronSheppardNumberFrames
};
const s32 gCornerOffsetX[4] = { -425984, 425984, -425984, 425984 };
const s32 gCornerOffsetZ[4] = { -917504, -917504, 1114112, 1114112 };
const u32 gTrackAiDragDivisors[] = {
    0x1CC01F4, 0x1D601A4, 0x1B801CC, 0x1E001DB, 0x1CC01D6, 0x1E001D6,
    (u32)gText_Demo, (u32)gText_OutOfTime
};
// One parameter per task spawned by sub_0800B594 (records screen rows).
const u8 gRecordsTaskParams[12] = { 64, 72, 80, 96, 104, 112, 128, 136, 144, 152, 160, 168 };
