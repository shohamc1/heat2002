#include "global.h"
#include "structs.h"
#include "collision_normals.h"
#include "variables.h"
#include "championship_tables.h"

extern const u8 gModule_Frontleft[];
extern const u8 gModule_Frontright[];
extern const u8 gModule_Rearleft[];
extern const u8 gModule_Rearright[];
extern const u8 gModule_Back[];
extern const u8 gModule_Front[];
extern const u8 gModule_Left[];
extern const u8 gModule_Right[];
/* The wall-data labels data/rom_08360290.s defines (EWRAM names). */
extern struct Pt gUnk_02027810[];
extern struct WallRec gUnk_02027DB0[];
extern u16 gUnk_020293F0[];
extern u16 gUnk_02029CD4[];

extern const u8 gModule_AndylandRacing[];
extern const u8 gModule_ChipGanassi[];
extern const u8 gModule_DalyEnterprises[];
extern const u8 gModule_Darby[];
extern const u8 gModule_Dei[];
extern const u8 gModule_DriverAdamBouskill[];
extern const u8 gModule_DriverAndrewBishop[];
extern const u8 gModule_DriverBrianLocke[];
extern const u8 gModule_DriverCameronSheppard[];
extern const u8 gModule_DriverChrisWalsh[];
extern const u8 gModule_DriverDaleEarnhardtJr[];
extern const u8 gModule_DriverDaleJarrett[];
extern const u8 gModule_DriverDanielEvans[];
extern const u8 gModule_DriverDarrenJackson[];
extern const u8 gModule_DriverDaveMurphy[];
extern const u8 gModule_DriverJakeMay[];
extern const u8 gModule_DriverJamesBrown[];
extern const u8 gModule_DriverJamesDaly[];
extern const u8 gModule_DriverJasonPope[];
extern const u8 gModule_DriverJayMcgee[];
extern const u8 gModule_DriverJeffGordon[];
extern const u8 gModule_DriverJoeFried[];
extern const u8 gModule_DriverJonnieShearn[];
extern const u8 gModule_DriverKevinHarvick[];
extern const u8 gModule_DriverMikeMerren[];
extern const u8 gModule_DriverMitchellSlater[];
extern const u8 gModule_DriverNeilWilson[];
extern const u8 gModule_DriverNotAvailable[];
extern const u8 gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop10[];
extern const u8 gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop5[];
extern const u8 gModule_DriverRickyRudd[];
extern const u8 gModule_DriverRustyWallace[];
extern const u8 gModule_DriverSeanKendrick[];
extern const u8 gModule_DriverSterlingMarlin[];
extern const u8 gModule_DriverStevePark[];
extern const u8 gModule_DriverTimCoode[];
extern const u8 gModule_DriverTimMunson[];
extern const u8 gModule_DriverWillGreenough[];
extern const u8 gModule_EricHayashiMotorsports[];
extern const u8 gModule_HendrickMotorsports[];
extern const u8 gModule_JimFerrisMotorsports[];
extern const u8 gModule_KravitzRacing[];
extern const u8 gModule_MackneyMotorsports[];
extern const u8 gModule_MikeMacconellRacing[];
extern const u8 gModule_Penske[];
extern const u8 gModule_Rcr[];
extern const u8 gModule_Ryr[];
extern const u8 gModule_TeamCrawfish[];
extern const u8 gModule_TeamTino[];
extern const u8 gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns[];
extern const u8 gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns[];
extern const u8 gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10[];
extern const u8 gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20[];
extern const u8 gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5[];
extern const u8 gModule_TtMotorsports[];
extern const u8 gModule_UnderscoreRow32[];

/* The sprite frames the frame lists below point at: the module's
 * copies of the main program's frames, labelled in its data/*.s
 * fragments by their EWRAM addresses. */
extern const u8 gModule_0201AD3C[];
extern const u8 gModule_0201AD78[];
extern const u8 gModule_0201ADBC[];
extern const u8 gModule_0201AE04[];
extern const u8 gModule_0201AE4C[];
extern const u8 gModule_0201AE94[];
extern const u8 gModule_0201AEDC[];
extern const u8 gModule_0201AF24[];
extern const u8 gModule_0201AF6C[];
extern const u8 gModule_0201AFA8[];
extern const u8 gModule_0201AFF0[];
extern const u8 gModule_0201B038[];
extern const u8 gModule_0201B080[];
extern const u8 gModule_0201B0C8[];
extern const u8 gModule_0201B110[];
extern const u8 gModule_0201B158[];
extern const u8 gModule_0201B1A0[];
extern const u8 gModule_0201B1E8[];
extern const u8 gModule_0201B230[];
extern const u8 gModule_0201B278[];
extern const u8 gModule_0201B2C0[];
extern const u8 gModule_0201B308[];
extern const u8 gModule_0201B350[];
extern const u8 gModule_0201B398[];
extern const u8 gModule_0201B3E0[];
extern const u8 gModule_0201B428[];
extern const u8 gModule_0201B470[];
extern const u8 gModule_0201B4B8[];
extern const u8 gModule_0201B500[];
extern const u8 gModule_0201B548[];
extern const u8 gModule_0201B5B0[];
extern const u8 gModule_0201B6E4[];
extern const u8 gModule_0201B810[];
extern const u8 gModule_0201B948[];
extern const u8 gModule_0201BA7C[];
extern const u8 gModule_0201BBA0[];
extern const u8 gModule_0201BCC0[];
extern const u8 gModule_0201BDCC[];
extern const u8 gModule_0201BED8[];
extern const u8 gModule_0201BFEC[];
extern const u8 gModule_0201C100[];
extern const u8 gModule_0201C210[];
extern const u8 gModule_0201C31C[];
extern const u8 gModule_0201C428[];
extern const u8 gModule_0201C534[];
extern const u8 gModule_0201C63C[];
extern const u8 gModule_0201C744[];
extern const u8 gModule_0201C84C[];
extern const u8 gModule_0201C950[];
extern const u8 gModule_0201CA58[];
extern const u8 gModule_0201CB6C[];
extern const u8 gModule_0201CC84[];
extern const u8 gModule_0201CD94[];
extern const u8 gModule_0201CEA4[];
extern const u8 gModule_0201CFBC[];
extern const u8 gModule_0201D0D0[];
extern const u8 gModule_0201D1E4[];
extern const u8 gModule_0201D2F4[];
extern const u8 gModule_0201D3F8[];
extern const u8 gModule_0201D4F8[];
extern const u8 gModule_0201D5F8[];
extern const u8 gModule_0201D6F0[];
extern const u8 gModule_0201D7E8[];
extern const u8 gModule_0201D8FC[];
extern const u8 gModule_0201D958[];
extern const u8 gModule_0201D9A4[];
extern const u8 gModule_0201D9F4[];
extern const u8 gModule_0201DA48[];
extern const u8 gModule_0201DAAC[];
extern const u8 gModule_0201DB34[];
extern const u8 gModule_0201DBC8[];
extern const u8 gModule_0201DC5C[];
extern const u8 gModule_0201DCF0[];
extern const u8 gModule_0201DD84[];
extern const u8 gModule_0201DE18[];
extern const u8 gModule_0201DEA8[];
extern const u8 gModule_0201DF34[];
extern const u8 gModule_0201DFBC[];
extern const u8 gModule_0201E040[];
extern const u8 gModule_0201E0C4[];
extern const u8 gModule_0201E144[];
extern const u8 gModule_0201E1C0[];
extern const u8 gModule_0201E240[];
extern const u8 gModule_0201E2B8[];
extern const u8 gModule_0201E330[];
extern const u8 gModule_0201E3A4[];
extern const u8 gModule_0201E410[];
extern const u8 gModule_0201E47C[];
extern const u8 gModule_0201E4E4[];
extern const u8 gModule_0201E544[];
extern const u8 gModule_0201E588[];
extern const u8 gModule_0201E5CC[];
extern const u8 gModule_0201E610[];
extern const u8 gModule_0201E650[];
extern const u8 gModule_0201E690[];
extern const u8 gModule_0201E6E4[];
extern const u8 gModule_0201E768[];
extern const u8 gModule_0201E788[];
extern const u8 gModule_0201E7B0[];
extern const u8 gModule_0201E7E0[];
extern const u8 gModule_0201E820[];
extern const u8 gModule_0201E868[];
extern const u8 gModule_0201E8B4[];
extern const u8 gModule_0201E908[];
extern const u8 gModule_0201E95C[];
extern const u8 gModule_0201E9B8[];
extern const u8 gModule_0201EA20[];
extern const u8 gModule_0201EA90[];
extern const u8 gModule_0201EB04[];
extern const u8 gModule_0201EB80[];
extern const u8 gModule_0201EC04[];
extern const u8 gModule_0201EC88[];
extern const u8 gModule_0201ED0C[];
extern const u8 gModule_0201ED90[];
extern const u8 gModule_0201EE10[];
extern const u8 gModule_0201EE90[];
extern const u8 gModule_0201EF08[];
extern const u8 gModule_0201EF7C[];
extern const u8 gModule_0201EFF0[];
extern const u8 gModule_0201F064[];
extern const u8 gModule_0201F0D4[];
extern const u8 gModule_0201F13C[];
extern const u8 gModule_0201F1A4[];
extern const u8 gModule_0201F204[];
extern const u8 gModule_0201F25C[];
extern const u8 gModule_0201F2AC[];
extern const u8 gModule_0201F2F4[];
extern const u8 gModule_0201F334[];
extern const u8 gModule_02024068[];
extern const u8 gModule_020240E8[];
extern const u8 gModule_02024168[];
extern const u8 gModule_020241E8[];
extern const u8 gModule_02024268[];
extern const u8 gModule_020242E8[];
extern const u8 gModule_02024368[];
extern const u8 gModule_02024408[];
extern const u8 gModule_02024488[];
extern const u8 gModule_02024508[];
extern const u8 gModule_02024588[];
extern const u8 gModule_02024608[];
extern const u8 gModule_02024688[];
extern const u8 gModule_02024708[];
extern const u8 gModule_020247A8[];
extern const u8 gModule_02024828[];
extern const u8 gModule_020248A8[];
extern const u8 gModule_02024928[];
extern const u8 gModule_020249A8[];
extern const u8 gModule_02024A28[];
extern const u8 gModule_02024AA8[];
extern const u8 gModule_02024B48[];
extern const u8 gModule_02024BC8[];
extern const u8 gModule_02024C48[];
extern const u8 gModule_02024CC8[];
extern const u8 gModule_02024D48[];
extern const u8 gModule_02024DC8[];
extern const u8 gModule_02024E48[];

/* High module (link slave) wall and tyre-name tables (ROM
 * 0x08363954-0x08363988, EWRAM 0x0202AED4-0x0202AF08). */

/* The link track's walls (struct TrackWalls, structs.h): the wall vertices,
 * wall records and the 48x48 cell grid module_walls.c walks. The main
 * program's twelve-row gTrackWallTables (src/data/championship_data.c) says
 * what each field is; this one row's blobs are a copy of track 7's
 * (data/rom_08360290.s), labelled by their EWRAM addresses. */
const struct TrackWalls gModule_TrackWallTables[1] = {
    { gUnk_02027810, gUnk_02027DB0, 0xB2, gUnk_020293F0, gUnk_02029CD4 },
};

/* The eight tyre-position names in the pit menu's order, the twin of
 * the main program's gUnk_083FDA0C (src/data/championship_data.c); the
 * strings are high_module_text.c's tyre block. */
const u8 *const gModule_TirePositionTexts[8] = { gModule_Frontleft, gModule_Frontright, gModule_Rearleft,
                                                 gModule_Rearright, gModule_Back,      gModule_Front,
                                                 gModule_Left,      gModule_Right };

/* High module (link slave) collision response normals (ROM
 * 0x08363988-0x083639A8, EWRAM 0x0202AF08-0x0202AF28), byte-identical to the
 * main program's gCarCollisionNormals (src/data/championship_data.c, which
 * says what they are for): the ROM holds them twice, once per GBA.
 * collision_normals.h shares the initialisers, so one edit changes both
 * copies. module_collide.c reads them through its own view (struct
 * CollisionNormal x[]). */
const s32 gModule_CarCollisionNormals[8] = CAR_COLLISION_NORMALS;

/* High module (link slave) option, championship and sprite-frame tables (ROM
 * 0x083639A8-0x08363EE8, EWRAM 0x0202AF28-0x0202B468). The numbers are
 * byte-identical to the main program's tables of the same names in
 * src/data/championship_data.c (which say what each is for), shared through
 * championship_tables.h; the pointer tables are the same shape and point at
 * the module's own strings and sprite frames. The main program's
 * gUnk_083FDA50, gUnk_083FDA5C, gTrackSelectEntries, gUnk_083FDE3E,
 * gUnk_083FDE5E and the tables after gUnk_083FDE72 have no copy here. */

// No module code reads these yet.
const s32 gModule_0202AF28[1] = UNK_083FDA4C;
const u8 gModule_OptionsMenuMinValues[7] = OPTIONS_MENU_MIN_VALUES;
const u8 gModule_OptionsMenuMaxValues[7] = OPTIONS_MENU_MAX_VALUES;
const u8 gModule_LapsPerOption[10] = LAPS_PER_OPTION;
// The 30-driver roster: name and team id, rows in teammate pairs.
const struct DriverRosterEntry gModule_DriverRoster[30] = {
    { gModule_DriverStevePark, 0x0 }, { gModule_DriverDaleEarnhardtJr, 0x0 }, { gModule_DriverKevinHarvick, 0x1 },
    { gModule_DriverDaleJarrett, 0x2 }, { gModule_DriverRickyRudd, 0x2 }, { gModule_DriverJeffGordon, 0x3 },
    { gModule_DriverJasonPope, 0x4 }, { gModule_DriverJoeFried, 0x4 }, { gModule_DriverRustyWallace, 0x7 },
    { gModule_DriverSterlingMarlin, 0x8 }, { gModule_DriverBrianLocke, 0x5 }, { gModule_DriverJayMcgee, 0x5 },
    { gModule_DriverMitchellSlater, 0x6 }, { gModule_DriverJamesBrown, 0x6 }, { gModule_DriverNeilWilson, 0x9 },
    { gModule_DriverTimMunson, 0x9 }, { gModule_DriverAndrewBishop, 0xA }, { gModule_DriverDanielEvans, 0xA },
    { gModule_DriverSeanKendrick, 0xB }, { gModule_DriverJakeMay, 0xB }, { gModule_DriverChrisWalsh, 0xC },
    { gModule_DriverJamesDaly, 0xC }, { gModule_DriverAdamBouskill, 0xD }, { gModule_DriverTimCoode, 0xD },
    { gModule_DriverWillGreenough, 0xE }, { gModule_DriverJonnieShearn, 0xE }, { gModule_DriverDaveMurphy, 0xF },
    { gModule_DriverDarrenJackson, 0xF }, { gModule_DriverMikeMerren, 0x10 }, { gModule_DriverCameronSheppard, 0x10 }
};
const u8 *const gModule_ChampionshipLockedTexts[17] = {
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop5,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop5,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop5,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop5,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop5,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop5,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop5,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop10,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop10,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop10,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop10,
    gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop10,
    gModule_DriverNotAvailable,
    gModule_DriverNotAvailable,
    gModule_DriverNotAvailable,
    gModule_DriverNotAvailable,
    gModule_DriverNotAvailable
};
const u8 gModule_ChampionshipTeamTiers[17] = CHAMPIONSHIP_TEAM_TIERS;
const u8 gModule_ChampionshipRequiredFinish[19] = CHAMPIONSHIP_REQUIRED_FINISH;
const u8 *const gModule_ChampionshipQualifyTexts[17] = {
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns
};
const u8 gModule_ChampionshipTrackIds[20] = CHAMPIONSHIP_TRACK_IDS;
const u32 gModule_ChampionshipQualifyLapTimeTargets[17] = CHAMPIONSHIP_QUALIFY_LAP_TIME_TARGETS;
const u8 *const gModule_ChampionshipRetainTexts[17] = {
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20,
    gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20
};
const u8 *const gModule_ChampionshipTeamNames[17] = {
    gModule_Dei, gModule_Rcr, gModule_Ryr,
    gModule_HendrickMotorsports, gModule_DalyEnterprises, gModule_MackneyMotorsports,
    gModule_KravitzRacing, gModule_Penske, gModule_ChipGanassi,
    gModule_JimFerrisMotorsports, gModule_AndylandRacing, gModule_TtMotorsports,
    gModule_TeamTino, gModule_MikeMacconellRacing, gModule_EricHayashiMotorsports,
    gModule_Darby, gModule_TeamCrawfish
};
const u8 gModule_0202B1C0[4] = UNK_083FDE14;
const u8 *const gModule_UiFontTable[1] = { gModule_UnderscoreRow32 };
const u8 gModule_ChampionshipTrackOrder[33] = { CHAMPIONSHIP_TRACK_ORDER };
const u8 gModule_0202B1E9[6] = UNK_083FDE72;

/* The sprite frame lists, the twins of the main program's in
 * data/rom_083FEF08.s and data/rom_083FF724.s: one number frame per driver
 * (reached through gModule_DriverNumberFrameLists, module_draw.c), the two
 * car sprite halves (gModule_DriverCarSpriteHalfATables/BTables), the damage
 * smoke (module_particles.c), and one link-marker list per player
 * (gModule_LinkMarkerFrameLists, module_draw.c and ModuleDrawLinkMarker.c). */
const u8 *const gModule_DriverSteveParkNumberFrames[1] = { gModule_0201AD3C };
const u8 *const gModule_DriverDaleEarnhardtJRNumberFrames[1] = { gModule_0201AD78 };
const u8 *const gModule_DriverKevinHarvickNumberFrames[1] = { gModule_0201ADBC };
const u8 *const gModule_DriverDaleJarrettNumberFrames[1] = { gModule_0201AE04 };
const u8 *const gModule_DriverRickyRuddNumberFrames[1] = { gModule_0201AE4C };
const u8 *const gModule_DriverJeffGordonNumberFrames[1] = { gModule_0201AE94 };
const u8 *const gModule_DriverJasonPopeNumberFrames[1] = { gModule_0201AEDC };
const u8 *const gModule_DriverJoeFriedNumberFrames[1] = { gModule_0201AF24 };
const u8 *const gModule_DriverRustyWallaceNumberFrames[1] = { gModule_0201AF6C };
const u8 *const gModule_DriverSterlingMarlinNumberFrames[1] = { gModule_0201AFA8 };
const u8 *const gModule_DriverBrianLockeNumberFrames[1] = { gModule_0201AFF0 };
const u8 *const gModule_DriverJayMcgeeNumberFrames[1] = { gModule_0201B038 };
const u8 *const gModule_DriverMitchellSlaterNumberFrames[1] = { gModule_0201B080 };
const u8 *const gModule_DriverJamesBrownNumberFrames[1] = { gModule_0201B0C8 };
const u8 *const gModule_DriverNeilWilsonNumberFrames[1] = { gModule_0201B110 };
const u8 *const gModule_DriverTimMunsonNumberFrames[1] = { gModule_0201B158 };
const u8 *const gModule_DriverAndrewBishopNumberFrames[1] = { gModule_0201B1A0 };
const u8 *const gModule_DriverDanielEvansNumberFrames[1] = { gModule_0201B1E8 };
const u8 *const gModule_DriverSeanKendrickNumberFrames[1] = { gModule_0201B230 };
const u8 *const gModule_DriverJakeMayNumberFrames[1] = { gModule_0201B278 };
const u8 *const gModule_DriverChrisWalshNumberFrames[1] = { gModule_0201B2C0 };
const u8 *const gModule_DriverJamesDalyNumberFrames[1] = { gModule_0201B308 };
const u8 *const gModule_DriverAdamBouskillNumberFrames[1] = { gModule_0201B350 };
const u8 *const gModule_DriverTimCoodeNumberFrames[1] = { gModule_0201B398 };
const u8 *const gModule_DriverWillGreenoughNumberFrames[1] = { gModule_0201B3E0 };
const u8 *const gModule_DriverJonnieShearnNumberFrames[1] = { gModule_0201B428 };
const u8 *const gModule_DriverDaveMurphyNumberFrames[1] = { gModule_0201B470 };
const u8 *const gModule_DriverDarrenJacksonNumberFrames[1] = { gModule_0201B4B8 };
const u8 *const gModule_DriverMikeMerrenNumberFrames[1] = { gModule_0201B500 };
const u8 *const gModule_DriverCameronSheppardNumberFrames[1] = { gModule_0201B548 };
const u8 *const gModule_CarSpriteHalfBFrames[33] = {
    gModule_0201B5B0, gModule_0201B6E4, gModule_0201B810, gModule_0201B948,
    gModule_0201BA7C, gModule_0201BBA0, gModule_0201BCC0, gModule_0201BDCC,
    gModule_0201BED8, gModule_0201BFEC, gModule_0201C100, gModule_0201C210,
    gModule_0201C31C, gModule_0201C428, gModule_0201C534, gModule_0201C63C,
    gModule_0201C744, gModule_0201C84C, gModule_0201C950, gModule_0201CA58,
    gModule_0201CB6C, gModule_0201CC84, gModule_0201CD94, gModule_0201CEA4,
    gModule_0201CFBC, gModule_0201D0D0, gModule_0201D1E4, gModule_0201D2F4,
    gModule_0201D3F8, gModule_0201D4F8, gModule_0201D5F8, gModule_0201D6F0,
    gModule_0201D7E8
};
const u8 *const gModule_CarSpriteHalfAFrames[33] = {
    gModule_0201D8FC, gModule_0201D958, gModule_0201D9A4, gModule_0201D9F4,
    gModule_0201DA48, gModule_0201DAAC, gModule_0201DB34, gModule_0201DBC8,
    gModule_0201DC5C, gModule_0201DCF0, gModule_0201DD84, gModule_0201DE18,
    gModule_0201DEA8, gModule_0201DF34, gModule_0201DFBC, gModule_0201E040,
    gModule_0201E0C4, gModule_0201E144, gModule_0201E1C0, gModule_0201E240,
    gModule_0201E2B8, gModule_0201E330, gModule_0201E3A4, gModule_0201E410,
    gModule_0201E47C, gModule_0201E4E4, gModule_0201E544, gModule_0201E588,
    gModule_0201E5CC, gModule_0201E610, gModule_0201E650, gModule_0201E690,
    gModule_0201E6E4
};
const u8 *const gModule_DamageSmokeFrames[32] = {
    gModule_0201E768, gModule_0201E788, gModule_0201E7B0, gModule_0201E7E0,
    gModule_0201E820, gModule_0201E868, gModule_0201E8B4, gModule_0201E908,
    gModule_0201E95C, gModule_0201E9B8, gModule_0201EA20, gModule_0201EA90,
    gModule_0201EB04, gModule_0201EB80, gModule_0201EC04, gModule_0201EC88,
    gModule_0201ED0C, gModule_0201ED90, gModule_0201EE10, gModule_0201EE90,
    gModule_0201EF08, gModule_0201EF7C, gModule_0201EFF0, gModule_0201F064,
    gModule_0201F0D4, gModule_0201F13C, gModule_0201F1A4, gModule_0201F204,
    gModule_0201F25C, gModule_0201F2AC, gModule_0201F2F4, gModule_0201F334
};
const u8 *const gModule_LinkMarkerP1FrameList[7] = {
    gModule_02024068, gModule_020240E8, gModule_02024168, gModule_020241E8,
    gModule_02024268, gModule_020242E8, gModule_02024368
};
const u8 *const gModule_LinkMarkerP2FrameList[7] = {
    gModule_02024408, gModule_02024488, gModule_02024508, gModule_02024588,
    gModule_02024608, gModule_02024688, gModule_02024708
};
const u8 *const gModule_LinkMarkerP3FrameList[7] = {
    gModule_020247A8, gModule_02024828, gModule_020248A8, gModule_02024928,
    gModule_020249A8, gModule_02024A28, gModule_02024AA8
};
const u8 *const gModule_LinkMarkerP4FrameList[9] = {
    gModule_02024B48, gModule_02024BC8, gModule_02024C48, gModule_02024CC8,
    gModule_02024D48, gModule_02024DC8, gModule_02024E48, (const u8 *)gUnk_02024EE8,
    (const u8 *)gUnk_02024F70
};
