#include "global.h"
#include "data.h"

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
extern const struct TrackSeg gUnk_08365348[];
extern const struct TrackSeg gUnk_08365618[];
extern const struct TrackSeg gUnk_08365798[];
extern const struct TrackSeg gUnk_08365A38[];
extern const struct TrackSeg gUnk_08365CC0[];
extern const struct TrackSeg gUnk_08366140[];
extern const struct TrackSeg gUnk_08366470[];
extern const struct TrackSeg gUnk_08366620[];
extern const struct TrackSeg gUnk_083668A8[];
extern const struct TrackSeg gUnk_08366A58[];
extern const struct TrackSeg gUnk_08366DE8[];
extern const struct TrackSeg gUnk_08366F38[];
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

const struct TrackSeg *const gTrackSegTables[] = {
    gUnk_08365348, gUnk_08365618, gUnk_08365798,
    gUnk_08365A38, gUnk_08365CC0, gUnk_08366140,
    gUnk_08366470, gUnk_08366620, gUnk_083668A8,
    gUnk_08366A58, gUnk_08366DE8, gUnk_08366F38
};
// The sprite caches' OBJ VRAM tile numbers. Each array holds u16 tile
// indices that sub_08007304 reads one by one (turning each into an
// OBJ_VRAM0 offset with t << 5); the words below just pair them.
const u16 gObjTileCache64Tiles[4] = {
    0x0, 0x40, 0x80, 0xC0
};
const u16 gObjTileCache16Tiles[24] = {
    0x100, 0x110, 0x120, 0x130, 0x140, 0x150, 0x160, 0x170,
    0x180, 0x190, 0x1A0, 0x1B0, 0x1C0, 0x1D0, 0x1E0, 0x1F0,
    0x200, 0x210, 0x220, 0x230, 0x0, 0x0, 0x0, 0x0
};
const u16 gObjTileCache2Tiles[32] = {
    0x240, 0x242, 0x244, 0x246, 0x248, 0x24A, 0x24C, 0x24E,
    0x250, 0x252, 0x254, 0x256, 0x258, 0x25A, 0x25C, 0x25E,
    0x260, 0x262, 0x264, 0x266, 0x268, 0x26A, 0x26C, 0x26E,
    0x270, 0x272, 0x274, 0x276, 0x278, 0x27A, 0x27C, 0x27E
};
const u16 gObjTileCache8Tiles[20] = {
    0x2C0, 0x2C8, 0x2D0, 0x2D8, 0x2E0, 0x2E8, 0x2F0, 0x2F8,
    0x300, 0x308, 0x310, 0x318, 0x320, 0x328, 0x330, 0x338,
    0x340, 0x348, 0x350, 0x358
};
const u16 gObjTileCache4Tiles[16] = {
    0x360, 0x364, 0x368, 0x36C, 0x370, 0x374, 0x378, 0x37C,
    0x380, 0x384, 0x388, 0x38C, 0x390, 0x394, 0x398, 0x39C
};
const u16 gObjTileCache1Tiles[32] = {
    0x3A0, 0x3A1, 0x3A2, 0x3A3, 0x3A4, 0x3A5, 0x3A6, 0x3A7,
    0x3A8, 0x3A9, 0x3AA, 0x3AB, 0x3AC, 0x3AD, 0x3AE, 0x3AF,
    0x3B0, 0x3B1, 0x3B2, 0x3B3, 0x3B4, 0x3B5, 0x3B6, 0x3B7,
    0x3B8, 0x3B9, 0x3BA, 0x3BB, 0x3BC, 0x3BD, 0x3BE, 0x3BF
};
// Its users declare it as s32 x[], u32 x[].
// Twelve tracks times eight pit stalls, one (x, y) pair each
// (sub_0800C4E0, UpdateAiDriver).
const u32 gPitStallPositions[192] = {
    3015, 2209, 2855, 2049, 2703, 1897,
    2551, 1745, 2399, 1593, 2247, 1441,
    2095, 1289, 1943, 1137, 1471, 1308,
    1568, 1308, 1664, 1308, 1759, 1308,
    1856, 1308, 1952, 1308, 2048, 1308,
    2144, 1308, 3998, 3278, 3957, 3310,
    3915, 3355, 3874, 3389, 3833, 3430,
    3799, 3468, 3753, 3511, 3712, 3558,
    888, 2208, 896, 2112, 888, 2016,
    896, 1920, 888, 1824, 896, 1728,
    888, 1632, 896, 1536, 4195, 3469,
    4199, 3372, 4197, 3279, 4197, 2988,
    4195, 2894, 4197, 2798, 4195, 2702,
    4193, 2606, 1639, 2385, 1641, 2445,
    1639, 2575, 1641, 2637, 1639, 2701,
    1638, 2827, 1641, 2896, 1641, 3023,
    2413, 1455, 2413, 1615, 2413, 1775,
    2414, 1855, 2413, 2016, 2413, 2177,
    2413, 2336, 2413, 2496, 2413, 1455,
    2413, 1615, 2413, 1775, 2414, 1855,
    2413, 2016, 2414, 2177, 2414, 2336,
    2414, 2496, 2601, 1816, 2601, 1927,
    2603, 2107, 2600, 2297, 2602, 2400,
    2599, 2495, 2602, 2582, 2600, 2671,
    898, 2474, 897, 2535, 897, 2597,
    897, 2661, 896, 2727, 897, 2793,
    897, 2857, 896, 2923, 1034, 1734,
    1035, 1637, 1034, 1539, 1034, 1443,
    1032, 1347, 1035, 1245, 1033, 1156,
    1033, 1056, 1645, 2418, 1711, 2416,
    1834, 2417, 1901, 2418, 1963, 2418,
    2029, 2419, 2094, 2416, 2222, 2417
};
// The track progress value at which a car may enter its pit stall, per
// track (car/update.c compares it against the car's progress).
const u16 gPitEntryProgressPoints[12] = {
    365, 150, 390, 325, 660, 480, 90, 0,
    210, 500, 150, 380
};
// The track progress value at which a car leaves the pit lane, per track.
const u16 gPitExitProgressPoints[12] = {
    410, 200, 425, 365, 720, 505, 125, 0,
    260, 580, 190, 400
};
// NASCAR championship points per finishing position 1-30; 31st and
// beyond get nothing (AwardRacePoints, src/race/grid.c).
const u8 gRacePointsTable[32] = {
    175, 170, 165, 160, 155, 150, 146, 142,
    138, 134, 130, 127, 124, 121, 118, 115,
    112, 109, 106, 103, 100, 97, 94, 91,
    88, 85, 82, 79, 76, 73, 0, 0
};
const u32 *const gDriverCarSpriteHalfATables[] = {
    gUnk_083FF424, gUnk_083FF424, gUnk_083FF52C,
    gUnk_083FF004, gUnk_083FF52C, gUnk_083FF214,
    gUnk_083FF10C, gUnk_083FF31C, gUnk_083FF52C,
    gUnk_083FF52C, gUnk_083FF31C, gUnk_083FF214,
    gUnk_083FF31C, gUnk_083FF424, gUnk_083FF10C,
    gUnk_083FF10C, gUnk_083FF424, gUnk_083FF214,
    gUnk_083FF10C, gUnk_083FF214, gUnk_083FF424,
    gUnk_083FF214, gUnk_083FF52C, gUnk_083FF10C,
    gUnk_083FF31C, gUnk_083FF004, gUnk_083FF004,
    gUnk_083FF004, gUnk_083FF31C, gUnk_083FF004
};
const u32 *const gDriverCarSpriteHalfBTables[] = {
    gUnk_083FF3A0, gUnk_083FF3A0, gUnk_083FF4A8,
    gUnk_083FEF80, gUnk_083FF4A8, gUnk_083FF190,
    gUnk_083FF088, gUnk_083FF298, gUnk_083FF4A8,
    gUnk_083FF4A8, gUnk_083FF298, gUnk_083FF190,
    gUnk_083FF298, gUnk_083FF3A0, gUnk_083FF088,
    gUnk_083FF088, gUnk_083FF3A0, gUnk_083FF190,
    gUnk_083FF088, gUnk_083FF190, gUnk_083FF3A0,
    gUnk_083FF190, gUnk_083FF4A8, gUnk_083FF088,
    gUnk_083FF298, gUnk_083FEF80, gUnk_083FEF80,
    gUnk_083FEF80, gUnk_083FF298, gUnk_083FEF80
};
// Its users declare it as u32 *x[].
const u8 *const gDriverPalettes[] = {
    gUnk_08330D38, gUnk_08330D58, gUnk_08330D78,
    gUnk_08330D98, gUnk_08330DB8, gUnk_08330DD8,
    gUnk_083311A8, gUnk_083311C8, gUnk_08330DF8,
    gUnk_08330E18, gUnk_08330E38, gUnk_08330E58,
    gUnk_08330E78, gUnk_08330E98, gUnk_08330EB8,
    gUnk_08330ED8, gUnk_08330EF8, gUnk_08330F18,
    gUnk_08330F38, gUnk_08330F58, gUnk_08330F78,
    gUnk_08330F98, gUnk_08330FB8, gUnk_08330FD8,
    gUnk_08330FF8, gUnk_08331018, gUnk_08331038,
    gUnk_08330D98, gUnk_08331058, gUnk_08331078
};
// Tire-grip setups, 31 rows (struct TireGripSetup, structs.h):
// rear slow/fast grip, front slow/fast grip, slip-limit base.
// SetTireGrip (src/car/tire_grip.c) loads row 0 for link races and the
// player's car; no decompiled code reads the other 30 rows yet.
const struct TireGripSetup gTireGripDefaults[31] = {
    { 180, 180, 70, 70, 80000 },
    { 160, 66, 103, 103, 69632 },
    { 180, 54, 180, 63, 40960 },
    { 84, 62, 124, 108, 51536 },
    { 132, 114, 100, 83, 46080 },
    { 168, 154, 72, 99, 55296 },
    { 88, 66, 140, 140, 51536 },
    { 100, 100, 100, 100, 60416 },
    { 200, 170, 100, 55, 48128 },
    { 96, 70, 160, 192, 51536 },
    { 128, 134, 128, 91, 33792 },
    { 108, 74, 160, 192, 52560 },
    { 84, 66, 132, 83, 71680 },
    { 116, 78, 172, 200, 54608 },
    { 152, 110, 140, 103, 37888 },
    { 220, 170, 100, 83, 30720 },
    { 255, 150, 120, 75, 65536 },
    { 175, 130, 204, 47, 80896 },
    { 107, 90, 236, 179, 50176 },
    { 132, 102, 192, 212, 60752 },
    { 88, 66, 140, 140, 51536 },
    { 160, 66, 103, 103, 69632 },
    { 180, 54, 180, 63, 40960 },
    { 84, 62, 124, 108, 51536 },
    { 132, 114, 100, 83, 46080 },
    { 168, 154, 72, 99, 55296 },
    { 88, 66, 140, 140, 51536 },
    { 100, 100, 100, 100, 60416 },
    { 200, 170, 100, 55, 48128 },
    { 96, 70, 160, 192, 51536 },
    { 128, 134, 128, 91, 33792 },
};
// Starting-grid records (struct TrackGrid, structs.h), one per track;
// BuildStartingGrid (race/grid.c) places the 24 slots from each row.
const struct TrackGrid gTrackStartGrids[12] = {
    { 2689, 1651, -60, -60, 40, -40, 96 },
    { 1460, 1192, 60, 0, 0, -60, 192 },
    { 3988, 3646, -40, 40, 56, 56, 32 },
    { 449, 1444, 0, -40, -50, 0, 128 },
    { 3954, 2933, 0, -40, -50, 0, 128 },
    { 1439, 2619, 0, 50, 40, 0, 0 },
    { 1461, 1318, 0, -56, 40, 0, 128 },
    { 2875, 1564, 0, 56, -40, 0, 128 },
    { 3160, 2605, -56, 0, 40, 0, 0 },
    { 1178, 3161, 0, -56, -40, 0, 0 },
    { 734, 1065, 56, 0, 40, 0, 128 },
    { 2064, 2613, 56, 0, 0, -40, 192 },
};
// Seven car setups of three 5-entry rows each (gear power, gear ratio,
// rpm per speed, one entry per gear), the layout of the per-driver rows
// below. sub_08008338 copies the second setup's power and ratio rows
// (gUnk_08367B82, gUnk_08367B8C) into the tune menu. The sixth setup is
// the AI driver's (sub_08008394, InitCar), with one stray u16 between
// its power and ratio rows.
const u16 gUnk_08367B64[5] = { 450, 420, 400, 400, 475 };
const u16 gUnk_08367B6E[5] = { 5500, 9000, 12000, 13500, 18200 };
const u16 gUnk_08367B78[5] = { 11, 7, 5, 4, 3 };
const u16 gUnk_08367B82[5] = { 200, 200, 240, 260, 280 };
const u16 gUnk_08367B8C[5] = { 6000, 8000, 8500, 10000, 15000 };
const u16 gUnk_08367B96[5] = { 10, 8, 7, 6, 4 };
const u16 gUnk_08367BA0[5] = { 300, 300, 300, 260, 50 };
const u16 gUnk_08367BAA[5] = { 6300, 7500, 8775, 10125, 12750 };
const u16 gUnk_08367BB4[5] = { 10, 9, 7, 6, 5 };
const u16 gUnk_08367BBE[5] = { 300, 300, 300, 240, 40 };
const u16 gUnk_08367BC8[5] = { 6300, 7500, 8250, 9000, 10500 };
const u16 gUnk_08367BD2[5] = { 10, 9, 7, 7, 6 };
const u16 gUnk_08367BDC[5] = { 280, 280, 320, 340, 360 };
const u16 gUnk_08367BE6[5] = { 6000, 8600, 9300, 13600, 16600 };
const u16 gUnk_08367BF0[5] = { 10, 7, 7, 4, 3 };
const u16 gAiDriverGearPowerTable[5] = { 280, 280, 320, 340, 360 };
const u16 gUnk_08367C04[1] = { 20 };
const u16 gAiDriverGearRatioTable[5] = { 6000, 8600, 9300, 13600, 16600 };
const u16 gAiDriverRpmPerSpeedTable[5] = { 10, 7, 7, 4, 3 };
const u16 gUnk_08367C1A[5] = { 280, 280, 320, 340, 360 };
const u16 gUnk_08367C24[5] = { 6000, 8600, 9300, 13600, 16600 };
const u16 gUnk_08367C2E[5] = { 10, 7, 7, 4, 3 };

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
const u8 gPitLaneIndices[12] = { 7, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7 };
// Eight 16.16 fixed-point values (+/-16.0). No decompiled code reads them yet.
const s32 gUnk_083681C8[8] = { -1048576, -1048576, 1048576, -1048576, -1048576, 1048576, 1048576, 1048576 };
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
// The AI drag divisor per track (car/update.c).
const u16 gTrackAiDragDivisors[12] = { 500, 460, 420, 470, 460, 440, 475, 480, 470, 460, 470, 480 };
// No decompiled code reads this pointer pair yet.
const u8 *const gUnk_083682A8[] = { gText_Demo, gText_OutOfTime };
// One parameter per task spawned by sub_0800B594 (records screen rows).
const u8 gRecordsTaskParams[12] = { 64, 72, 80, 96, 104, 112, 128, 136, 144, 152, 160, 168 };
