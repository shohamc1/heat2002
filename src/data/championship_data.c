#include "global.h"
#include "championship_tables.h"
#include "collision_normals.h"
#include "data.h"

extern const u8 gText_Rearright[];
extern const u8 gText_Rearleft[];
extern const u8 gText_Frontright[];
extern const u8 gText_Frontleft[];
extern const u8 gText_Right[];
extern const u8 gText_Left[];
extern const u8 gText_Front[];
extern const u8 gText_Back[];
extern const u8 gUnk_0807CA7C[];
extern const u8 gUnk_0807CAC8[];
extern const u8 gUnk_0807CB14[];
extern const u8 gText_InfogramesSuperSpeedway[];
extern const u8 gText_TrackNum11[];
extern const u8 gText_TrackLen1357[];
extern const u8 gText_PhoenixInternationalRaceway[];
extern const u8 gText_TrackNum9[];
extern const u8 gText_TrackLen2555[];
extern const u8 gText_AsphaltCity[];
extern const u8 gText_TrackNum8[];
extern const u8 gText_TrackLen1950[];
extern const u8 gText_KansasSpeedway[];
extern const u8 gText_TrackNum3[];
extern const u8 gText_TrackLen066[];
extern const u8 gText_PurleyPark[];
extern const u8 gText_TrackNum10[];
extern const u8 gText_TrackLen3723[];
extern const u8 gText_CrawfishRaceway[];
extern const u8 gText_TrackNum17[];
extern const u8 gText_TrackLen2033[];
extern const u8 gText_FujiPort[];
extern const u8 gText_TrackLen1899[];
extern const u8 gText_GreatCanyon[];
extern const u8 gText_TrackNum19[];
extern const u8 gText_TrackLen2231[];
extern const u8 gText_MichiganInternationalSpeedway[];
extern const u8 gText_TrackNum20[];
extern const u8 gText_TrackLen1054[];
extern const u8 gText_GreenValley[];
extern const u8 gText_TrackNum14[];
extern const u8 gText_TrackLen243[];
extern const u8 gText_DarlingtonRaceway[];
extern const u8 gText_TrackNum15[];
extern const u8 gText_TrackLen3044[];
extern const u8 gText_HooleyDowns[];
extern const u8 gText_TrackNum22[];
extern const u8 gText_TrackLen1567[];
extern const u8 gText_DarrenJackson[];
extern const u8 gText_JonnieShearn[];
extern const u8 gText_AdamBouskill[];
extern const u8 gText_JamesDaly[];
extern const u8 gText_JakeMay[];
extern const u8 gText_SeanKendrick[];
extern const u8 gText_DanielEvans[];
extern const u8 gText_AndrewBishop[];
extern const u8 gText_TimMunson[];
extern const u8 gText_NeilWilson[];
extern const u8 gText_JamesBrown[];
extern const u8 gText_JayMcgee[];
extern const u8 gText_BrianLocke[];
extern const u8 gText_SterlingMarlin[];
extern const u8 gText_RustyWallace[];
extern const u8 gText_JoeFried[];
extern const u8 gText_JasonPope[];
extern const u8 gText_JeffGordon[];
extern const u8 gText_RickyRudd[];
extern const u8 gText_DaleJarrett[];
extern const u8 gText_KevinHarvick[];
extern const u8 gText_DaleEarnhardtJR[];
extern const u8 gText_StevePark[];
extern const u8 gText_NotAvailable[];
extern const u8 gText_NotAvailableYouNeedToFinishASeasonInTheTop10[];
extern const u8 gText_NotAvailableYouNeedToFinishASeasonInTheTop5[];
extern const u8 gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns[];
extern const u8 gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns[];
extern const u8 gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20[];
extern const u8 gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10[];
extern const u8 gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5[];
extern const u8 gText_TeamCrawfish[];
extern const u8 gText_Darby[];
extern const u8 gText_EricHayashiMotorsports[];
extern const u8 gText_MikeMacconellRacing[];
extern const u8 gText_TeamTino[];
extern const u8 gText_TtMotorsports[];
extern const u8 gText_AndylandRacing[];
extern const u8 gText_JimFerrisMotorsports[];
extern const u8 gText_ChipGanassi[];
extern const u8 gText_Penske[];
extern const u8 gText_KravitzRacing[];
extern const u8 gText_MackneyMotorsports[];
extern const u8 gText_DalyEnterprises[];
extern const u8 gText_HendrickMotorsports[];
extern const u8 gText_Ryr[];
extern const u8 gText_Rcr[];
extern const u8 gText_Dei[];
extern const u8 gText_UnderscoreRow32[];
extern const u8 gUnk_082CC5D8[];
extern const u8 gUnk_082F98C0[];
extern const u8 gUnk_082FB6AC[];
extern const u8 gUnk_082FD0F8[];
extern const u8 gUnk_082FF41C[];
extern const u8 gUnk_08300BCC[];
extern const u8 gUnk_08302E00[];
extern const u8 gUnk_083049FC[];
extern const u8 gUnk_08306238[];
extern const u8 gUnk_0830877C[];
extern const u8 gUnk_0830AB68[];
extern const u8 gUnk_0830CA10[];
extern const u8 gUnk_0830E418[];
extern struct Pt gUnk_083CA0C4[];
extern struct WallRec gUnk_083CA9DC[];
extern u16 gUnk_083CCDDC[];
extern u16 gUnk_083CDA98[];
extern struct Pt gUnk_083CEC98[];
extern struct WallRec gUnk_083CF7D0[];
extern u16 gUnk_083D2430[];
extern u16 gUnk_083D32A8[];
extern struct Pt gUnk_083D44A8[];
extern struct WallRec gUnk_083D4A28[];
extern u16 gUnk_083D5FA8[];
extern u16 gUnk_083D669E[];
extern struct Pt gUnk_083D78A0[];
extern struct WallRec gUnk_083D7FE0[];
extern u16 gUnk_083D9C80[];
extern u16 gUnk_083DA5D0[];
extern struct Pt gUnk_083DB7D0[];
extern struct WallRec gUnk_083DC1C0[];
extern u16 gUnk_083DE920[];
extern u16 gUnk_083DF630[];
extern struct Pt gUnk_083E0830[];
extern struct WallRec gUnk_083E1290[];
extern u16 gUnk_083E3BB0[];
extern u16 gUnk_083E4A40[];
extern struct Pt gUnk_083E5C40[];
extern struct WallRec gUnk_083E6218[];
extern u16 gUnk_083E7918[];
extern u16 gUnk_083E81CA[];
extern struct Pt gUnk_083E93CC[];
extern struct WallRec gUnk_083E996C[];
extern u16 gUnk_083EAFAC[];
extern u16 gUnk_083EB890[];
extern struct Pt gUnk_083ECA90[];
extern struct WallRec gUnk_083ED040[];
extern u16 gUnk_083EE6A0[];
extern u16 gUnk_083EEE84[];
extern struct Pt gUnk_083F0084[];
extern struct WallRec gUnk_083F0CC4[];
extern u16 gUnk_083F3D64[];
extern u16 gUnk_083F4D42[];
extern struct Pt gUnk_083F5F44[];
extern struct WallRec gUnk_083F64A4[];
extern u16 gUnk_083F79C4[];
extern u16 gUnk_083F80C4[];
extern struct Pt gUnk_083F92C4[];
extern struct WallRec gUnk_083F9B14[];
extern u16 gUnk_083FBBF4[];
extern u16 gUnk_083FC71C[];
extern const GfxSrc gUnk_083FED48[];
extern const GfxSrc gUnk_083FED4C[];
extern const GfxSrc gUnk_083FED50[];
extern const GfxSrc gUnk_083FED54[];
extern const GfxSrc gUnk_083FED58[];
extern const GfxSrc gUnk_083FED5C[];
extern const GfxSrc gUnk_083FED60[];
extern const GfxSrc gUnk_083FED64[];
extern const GfxSrc gUnk_083FED68[];
extern const GfxSrc gUnk_083FED6C[];
extern const GfxSrc gUnk_083FED70[];
extern const GfxSrc gUnk_083FED74[];
extern const GfxSrc gUnk_083FED78[];
extern const GfxSrc gUnk_083FED7C[];
extern const GfxSrc gUnk_083FED80[];
extern const GfxSrc gUnk_083FED84[];
extern const GfxSrc gUnk_083FED88[];
extern const GfxSrc gUnk_083FED8C[];
extern const GfxSrc gUnk_083FED90[];
extern const GfxSrc gUnk_083FED94[];
extern const GfxSrc gUnk_083FED98[];
extern const GfxSrc gUnk_083FED9C[];
extern const GfxSrc gUnk_083FEDA0[];
extern const GfxSrc gUnk_083FEDA4[];
extern const GfxSrc gUnk_083FEDA8[];
extern const GfxSrc gUnk_083FEDAC[];
extern const GfxSrc gUnk_083FEDB0[];
extern const GfxSrc gUnk_083FEDB4[];
extern const GfxSrc gUnk_083FEDB8[];
extern const GfxSrc gUnk_083FEDBC[];
extern const GfxSrc gUnk_083FEDC0[];
extern const GfxSrc gUnk_083FEDC4[];
extern const GfxSrc gUnk_083FEDC8[];
extern const GfxSrc gUnk_083FEDCC[];
extern const GfxSrc gUnk_083FEDD0[];
extern const GfxSrc gUnk_083FEDD4[];
extern const GfxSrc gUnk_083FEDD8[];
extern const GfxSrc gUnk_083FEDDC[];
extern const GfxSrc gUnk_083FEDE0[];
extern const GfxSrc gUnk_083FEDE4[];
extern const GfxSrc gUnk_083FEDE8[];
extern const GfxSrc gUnk_083FEDEC[];
extern const GfxSrc gUnk_083FEDF0[];
extern const GfxSrc gUnk_083FEDF4[];
extern const GfxSrc gUnk_083FEDF8[];
extern const GfxSrc gUnk_083FEDFC[];
extern const GfxSrc gUnk_083FEE00[];
extern const GfxSrc gUnk_083FEE04[];
extern const GfxSrc gUnk_083FEE08[];
extern const GfxSrc gUnk_083FEE0C[];
extern const GfxSrc gUnk_083FEE10[];
extern const GfxSrc gUnk_083FEE14[];
extern const GfxSrc gUnk_083FEE18[];
extern const GfxSrc gUnk_083FEE1C[];
extern const GfxSrc gUnk_083FEE20[];
extern const GfxSrc gUnk_083FEE24[];
extern const GfxSrc gUnk_083FEE28[];
extern const GfxSrc gUnk_083FEE2C[];
extern const GfxSrc gUnk_083FEE30[];
extern const GfxSrc gUnk_083FEE34[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track2[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track3[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track5[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track1[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track4[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track0[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track6[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track7[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track8[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track10[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track11[];
extern const struct TrackPreviewGfx gTrackPreviewGfx_Track9[];

// One row per track, read by LoadTrackWalls. The (u32) cast makes the
// wall count's INCBIN a compound literal, as in race_data.c.
const struct TrackWalls gTrackWallTables[12] = {
    { gUnk_083CA0C4, gUnk_083CA9DC, (u32)INCBIN_U32("build/assets/tracks/hooley_downs/wall_count.bin"), gUnk_083CCDDC, gUnk_083CDA98 },
    { gUnk_083D44A8, gUnk_083D4A28, (u32)INCBIN_U32("build/assets/tracks/darlington_raceway/wall_count.bin"), gUnk_083D5FA8, gUnk_083D669E },
    { gUnk_083CEC98, gUnk_083CF7D0, (u32)INCBIN_U32("build/assets/tracks/green_valley/wall_count.bin"), gUnk_083D2430, gUnk_083D32A8 },
    { gUnk_083D78A0, gUnk_083D7FE0, (u32)INCBIN_U32("build/assets/tracks/michigan_international_speedway/wall_count.bin"), gUnk_083D9C80, gUnk_083DA5D0 },
    { gUnk_083DB7D0, gUnk_083DC1C0, (u32)INCBIN_U32("build/assets/tracks/great_canyon/wall_count.bin"), gUnk_083DE920, gUnk_083DF630 },
    { gUnk_083E0830, gUnk_083E1290, (u32)INCBIN_U32("build/assets/tracks/fuji_port/wall_count.bin"), gUnk_083E3BB0, gUnk_083E4A40 },
    { gUnk_083E5C40, gUnk_083E6218, (u32)INCBIN_U32("build/assets/tracks/crawfish_raceway/wall_count.bin"), gUnk_083E7918, gUnk_083E81CA },
    { gUnk_083E93CC, gUnk_083E996C, (u32)INCBIN_U32("build/assets/tracks/purley_park/wall_count.bin"), gUnk_083EAFAC, gUnk_083EB890 },
    { gUnk_083ECA90, gUnk_083ED040, (u32)INCBIN_U32("build/assets/tracks/kansas_speedway/wall_count.bin"), gUnk_083EE6A0, gUnk_083EEE84 },
    { gUnk_083F0084, gUnk_083F0CC4, (u32)INCBIN_U32("build/assets/tracks/asphalt_city/wall_count.bin"), gUnk_083F3D64, gUnk_083F4D42 },
    { gUnk_083F5F44, gUnk_083F64A4, (u32)INCBIN_U32("build/assets/tracks/phoenix_international_raceway/wall_count.bin"), gUnk_083F79C4, gUnk_083F80C4 },
    { gUnk_083F92C4, gUnk_083F9B14, (u32)INCBIN_U32("build/assets/tracks/infogrames_super_speedway/wall_count.bin"), gUnk_083FBBF4, gUnk_083FC71C },
};
// No decompiled code reads these labels yet.
const u8 *const gUnk_083FDA0C[] = { gText_Frontleft, gText_Frontright, gText_Rearleft, gText_Rearright,
                                    gText_Back,      gText_Front,      gText_Left,     gText_Right };
// Its users declare it as struct CollisionNormal x[].
/* Collision response normals, one (x, z) pair per contact direction,
 * in 20.12 fixed point (4096 = 1). The initialisers live in
 * collision_normals.h, shared with the high module's byte-identical
 * copy (src/data/module_championship_data.c): the ROM holds them twice, once per
 * GBA. */
const s32 gCarCollisionNormals[8] = CAR_COLLISION_NORMALS;
// No decompiled code reads this word yet.
const s32 gUnk_083FDA4C[1] = UNK_083FDA4C;
const u8 *const gUnk_083FDA50[3] = { gUnk_0807CA7C, gUnk_0807CAC8, gUnk_0807CB14 };
// No decompiled code reads this word yet.
const u32 gUnk_083FDA5C[1] = { 0x800F };
// Options-menu row v runs from gOptionsMenuMinValues[v] to
// gOptionsMenuMaxValues[v]; gLapsPerOption maps the laps row to a lap
// count and ends in 3 zero pad bytes.
const u8 gOptionsMenuMinValues[7] = OPTIONS_MENU_MIN_VALUES;
const u8 gOptionsMenuMaxValues[7] = OPTIONS_MENU_MAX_VALUES;
const u8 gLapsPerOption[10] = LAPS_PER_OPTION;
const struct TrackSelectEntry gTrackSelectEntries[12] = {
    { 0x1, gText_TrackLen1567, gText_TrackNum22, gText_HooleyDowns, gTrackPreviewGfx_Track0, gUnk_08302E00 },
    { 0x1, gText_TrackLen3044, gText_TrackNum15, gText_DarlingtonRaceway, gTrackPreviewGfx_Track1, gUnk_082FF41C },
    { 0x1, gText_TrackLen243, gText_TrackNum14, gText_GreenValley, gTrackPreviewGfx_Track2, gUnk_082F98C0 },
    { 0x1, gText_TrackLen1054, gText_TrackNum20, gText_MichiganInternationalSpeedway, gTrackPreviewGfx_Track3, gUnk_082FB6AC },
    { 0x1, gText_TrackLen2231, gText_TrackNum19, gText_GreatCanyon, gTrackPreviewGfx_Track4, gUnk_08300BCC },
    { 0x1, gText_TrackLen1899, gText_TrackNum14, gText_FujiPort, gTrackPreviewGfx_Track5, gUnk_082FD0F8 },
    { 0x1, gText_TrackLen2033, gText_TrackNum17, gText_CrawfishRaceway, gTrackPreviewGfx_Track6, gUnk_083049FC },
    { 0x1, gText_TrackLen3723, gText_TrackNum10, gText_PurleyPark, gTrackPreviewGfx_Track7, gUnk_08306238 },
    { 0, gText_TrackLen066, gText_TrackNum3, gText_KansasSpeedway, gTrackPreviewGfx_Track8, gUnk_0830877C },
    { 0, gText_TrackLen1950, gText_TrackNum8, gText_AsphaltCity, gTrackPreviewGfx_Track9, gUnk_0830E418 },
    { 0, gText_TrackLen2555, gText_TrackNum9, gText_PhoenixInternationalRaceway, gTrackPreviewGfx_Track10, gUnk_0830AB68 },
    { 0, gText_TrackLen1357, gText_TrackNum11, gText_InfogramesSuperSpeedway, gTrackPreviewGfx_Track11, gUnk_0830CA10 },
};
// The 30-driver roster (struct DriverRosterEntry, structs.h): name and
// team id, rows in teammate pairs sharing the id.
const struct DriverRosterEntry gDriverRoster[] = {
    { gText_StevePark, 0 },        { gText_DaleEarnhardtJR, 0 }, { gText_KevinHarvick, 0x1 },
    { gText_DaleJarrett, 0x2 },    { gText_RickyRudd, 0x2 },     { gText_JeffGordon, 0x3 },
    { gText_JasonPope, 0x4 },      { gText_JoeFried, 0x4 },      { gText_RustyWallace, 0x7 },
    { gText_SterlingMarlin, 0x8 }, { gText_BrianLocke, 0x5 },    { gText_JayMcgee, 0x5 },
    { gText_MitchellSlater, 0x6 }, { gText_JamesBrown, 0x6 },    { gText_NeilWilson, 0x9 },
    { gText_TimMunson, 0x9 },      { gText_AndrewBishop, 0xA },  { gText_DanielEvans, 0xA },
    { gText_SeanKendrick, 0xB },   { gText_JakeMay, 0xB },       { gText_ChrisWalsh, 0xC },
    { gText_JamesDaly, 0xC },      { gText_AdamBouskill, 0xD },  { gText_TimCoode, 0xD },
    { gText_WillGreenough, 0xE },  { gText_JonnieShearn, 0xE },  { gText_DaveMurphy, 0xF },
    { gText_DarrenJackson, 0xF },  { gText_MikeMerren, 0x10 },   { gText_CameronSheppard, 0x10 },
};
// Its users declare it as u8 *x[].
const u8 *const gChampionshipLockedTexts[] = { gText_NotAvailableYouNeedToFinishASeasonInTheTop5,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop5,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop5,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop5,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop5,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop5,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop5,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop10,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop10,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop10,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop10,
                                               gText_NotAvailableYouNeedToFinishASeasonInTheTop10,
                                               gText_NotAvailable,
                                               gText_NotAvailable,
                                               gText_NotAvailable,
                                               gText_NotAvailable,
                                               gText_NotAvailable };
/* Team tier (0, 1 or 2) passed to UnlockChampionshipTier when a championship is
 * started with team a; UnlockChampionshipTier unlocks every team in tiers at or
 * below it. */
const u8 gChampionshipTeamTiers[17] = CHAMPIONSHIP_TEAM_TIERS;
// The season finish (top 5, 10 or 20) team a requires, then 2 zero pad
// bytes.
const u8 gChampionshipRequiredFinish[19] = CHAMPIONSHIP_REQUIRED_FINISH;
// Its users declare it as u8 *x[].
const u8 *const gChampionshipQualifyTexts[] = {
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns,
    gText_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns
};
/* Track id for each championship index; all zero in the shipped ROM. */
const u8 gChampionshipTrackIds[20] = CHAMPIONSHIP_TRACK_IDS;
/* Qualifying lap-time target in milliseconds (33 or 37 seconds) for
 * each championship index, compared against the player's lap time. */
const u32 gChampionshipQualifyLapTimeTargets[17] = CHAMPIONSHIP_QUALIFY_LAP_TIME_TARGETS;
const u8 *const gChampionshipRetainTexts[] = { gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20,
                                               gText_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20 };
// Its users declare it as u8 *x[] (team_select.c: const u8 *const x[]).
#if PLATFORM_GBA
const u32 gChampionshipTeamNames[17] = { (u32)gText_Dei,
                                         (u32)gText_Rcr,
                                         (u32)gText_Ryr,
                                         (u32)gText_HendrickMotorsports,
                                         (u32)gText_DalyEnterprises,
                                         (u32)gText_MackneyMotorsports,
                                         (u32)gText_KravitzRacing,
                                         (u32)gText_Penske,
                                         (u32)gText_ChipGanassi,
                                         (u32)gText_JimFerrisMotorsports,
                                         (u32)gText_AndylandRacing,
                                         (u32)gText_TtMotorsports,
                                         (u32)gText_TeamTino,
                                         (u32)gText_MikeMacconellRacing,
                                         (u32)gText_EricHayashiMotorsports,
                                         (u32)gText_Darby,
                                         (u32)gText_TeamCrawfish };
#else
const u8 *const gChampionshipTeamNames[17] = { gText_Dei,
                                               gText_Rcr,
                                               gText_Ryr,
                                               gText_HendrickMotorsports,
                                               gText_DalyEnterprises,
                                               gText_MackneyMotorsports,
                                               gText_KravitzRacing,
                                               gText_Penske,
                                               gText_ChipGanassi,
                                               gText_JimFerrisMotorsports,
                                               gText_AndylandRacing,
                                               gText_TtMotorsports,
                                               gText_TeamTino,
                                               gText_MikeMacconellRacing,
                                               gText_EricHayashiMotorsports,
                                               gText_Darby,
                                               gText_TeamCrawfish };
#endif
// No decompiled code reads these bytes yet.
const u8 gUnk_083FDE14[4] = UNK_083FDE14;
// Its users declare it as u32 x, u32 x[].
// The font row every screen loads through DummyUiFontLoad (a stub in the
// retail build; sub_08006738 is the working twin).
const u8 *const gUiFontTable[] = { gText_UnderscoreRow32 };
/* Season schedule: track id for each gSeasonRaceIndex (34 races; bytes
 * 17-33 double as the gChallengeIndex track table via the gUnk_083FDE2D
 * alias). */
const u8 gChampionshipTrackOrder[34] = { CHAMPIONSHIP_TRACK_ORDER, 0 };
// Sixteen 0x7FFF words. No decompiled code reads them yet.
const u16 gUnk_083FDE3E[16] = { 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
                                0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF };
// GetString ids; DrawMainMenuItems draws the first seven as its menu rows.
const u16 gUnk_083FDE5E[10] = { 72, 73, 74, 75, 76, 77, 78, 79, 80, 106 };
// No decompiled code reads these bytes yet.
const u8 gUnk_083FDE72[6] = UNK_083FDE72;
// LinkTrackSelect.c maps the cursor to a track id through this table.
const u8 gLinkTrackSelectTrackIds[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
// Twenty 4-byte rows. No decompiled code reads them yet.
const u8 gUnk_083FDE84[80] = { 3, 4, 5, 0, 3, 4, 5, 0, 3, 4, 4, 0, 2, 7, 5, 0, 3, 6, 3, 0, 3, 2, 5, 0, 3, 4, 5,
                               0, 3, 5, 5, 0, 3, 4, 3, 0, 3, 8, 5, 0, 4, 4, 7, 0, 3, 4, 5, 0, 3, 3, 5, 0, 2, 4,
                               6, 0, 3, 1, 5, 0, 3, 2, 1, 0, 3, 1, 5, 0, 3, 4, 1, 0, 3, 4, 5, 0, 3, 2, 5, 0 };
// No decompiled code reads these labels yet.
const u8 *const gUnk_083FDED4[] = { gText_A,     gText_Ab,     gText_Abc,     gText_Abcd,
                                    gText_Abcde, gText_Abcdee, gText_Abcdeee, gText_Abcdeeee };
const u8 *const gDriverCarPalettes[] = { gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8,
                                         gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8,
                                         gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8,
                                         gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8,
                                         gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8,
                                         gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8, gUnk_082CC5D8,
                                         gUnk_082CC5D8, gUnk_082CC5D8 };
const GfxSrc *const gDriverCarGfxLeftTiles[] = {
    gUnk_083FED9C, gUnk_083FEDBC, gUnk_083FEDAC, gUnk_083FEDB8, gUnk_083FEDA8, gUnk_083FEDA4,
    gUnk_083FED98, gUnk_083FEDA0, gUnk_083FEDB0, gUnk_083FEDB4, gUnk_083FED48, gUnk_083FED4C,
    gUnk_083FED50, gUnk_083FED54, gUnk_083FED58, gUnk_083FED5C, gUnk_083FED60, gUnk_083FED64,
    gUnk_083FED68, gUnk_083FED6C, gUnk_083FED70, gUnk_083FED74, gUnk_083FED78, gUnk_083FED7C,
    gUnk_083FED80, gUnk_083FED84, gUnk_083FED88, gUnk_083FED8C, gUnk_083FED90, gUnk_083FED94
};
const GfxSrc *const gDriverCarGfxRightTiles[] = {
    gUnk_083FEE14, gUnk_083FEE34, gUnk_083FEE24, gUnk_083FEE30, gUnk_083FEE20, gUnk_083FEE1C,
    gUnk_083FEE10, gUnk_083FEE18, gUnk_083FEE28, gUnk_083FEE2C, gUnk_083FEDC0, gUnk_083FEDC4,
    gUnk_083FEDC8, gUnk_083FEDCC, gUnk_083FEDD0, gUnk_083FEDD4, gUnk_083FEDD8, gUnk_083FEDDC,
    gUnk_083FEDE0, gUnk_083FEDE4, gUnk_083FEDE8, gUnk_083FEDEC, gUnk_083FEDF0, gUnk_083FEDF4,
    gUnk_083FEDF8, gUnk_083FEDFC, gUnk_083FEE00, gUnk_083FEE04, gUnk_083FEE08, gUnk_083FEE0C
};
