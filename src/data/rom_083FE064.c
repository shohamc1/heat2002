#include "global.h"
#include "data.h"

/* End-of-ROM tables, 0x083FE064-0x083FED48: the cheat password data,
 * the credits/challenge pointer tables, and the save/track constants. */

/* The five 5-digit cheat passwords the password-entry screen
 * (sub_080132F8) compares against gCheatCodeDials: codes 0-3, then
 * gCheatCodeMasterSequence, code 4, the master code that unlocks every
 * cheat flag at once, plus its 3 zero pad bytes. */
const u8 gCheatCodeSequences[4][5] = {
    { 1, 6, 2, 0, 0 },
    { 8, 1, 3, 9, 5 },
    { 0, 7, 9, 1, 3 },
    { 6, 2, 9, 7, 2 }
};
const u8 gCheatCodeMasterSequence[8] = {
    2, 9, 8, 0, 1, 0, 0, 0
};
// Its users declare it as u8 *x[].
const u8 *const gCheatCodeTable[5] = {
    gCheatCodeSequences[0], gCheatCodeSequences[1], gCheatCodeSequences[2],
    gCheatCodeSequences[3], gCheatCodeMasterSequence
};
/* 64 halfwords that look like four 16-colour BGR555 palettes. No
 * decompiled code reads them yet. */
const u16 gUnk_083FE094[64] = {
    0x21C8, 0x03FF, 0x039F, 0x031F, 0x02BF, 0x023F, 0x01DF, 0x015F,
    0x00FF, 0x007F, 0x001F, 0x0014, 0x0000, 0x1347, 0x0F67, 0x7FFF,
    0x21C8, 0x00DA, 0x0050, 0x0063, 0x0095, 0x6F9C, 0x5EF7, 0x4E73,
    0x10A6, 0x2D8C, 0x011F, 0x031F, 0x3E10, 0x2129, 0x0F87, 0x7FFF,
    0x21C8, 0x7FFF, 0x6B5A, 0x5294, 0x39CE, 0x2108, 0x6D20, 0x00D9,
    0x01BE, 0x0C63, 0x579F, 0x42BA, 0x29F4, 0x152F, 0x0069, 0x0000,
    0x21C8, 0x03FF, 0x02DF, 0x017F, 0x5AA0, 0x71A0, 0x2D6B, 0x65EF,
    0x4C00, 0x0000, 0x529E, 0x7FFE, 0x5EF6, 0x3DEF, 0x1CE7, 0x7FFF
};
extern const u8 gText_MarinaCerra[];
extern const u8 gText_CherylSlater[];
extern const u8 gText_DanielWalsh[];
extern const u8 gText_MichelleLamb[];
extern const u8 gText_ExtraSpecialThanks[];
extern const u8 gText_BillHudson[];
extern const u8 gText_MikeCartabianoAtSennari[];
extern const u8 gText_JonTrafford[];
extern const u8 gText_JohnTaylor[];
extern const u8 gText_RobWalkley[];
extern const u8 gText_LynneBradstock[];
extern const u8 gText_SpecialThanks[];
extern const u8 gText_LoriDrazen[];
extern const u8 gText_WorldWideMarketing[];
extern const u8 gText_LeezaMariaElkhazen[];
extern const u8 gText_ElieSamaha[];
extern const u8 gText_FranchisePictures[];
extern const u8 gText_CatChannon[];
extern const u8 gText_EuropeanPrManager[];
extern const u8 gText_SusanKramer[];
extern const u8 gText_DirectorOfAmericanPr[];
extern const u8 gText_DavidBlundell[];
extern const u8 gText_ProductManager[];
extern const u8 gText_ScottSmith[];
extern const u8 gText_DirectorOfAmericanMarketing[];
extern const u8 gText_LisaCheneyBolcato[];
extern const u8 gText_DirectorOfEuropeanMarketing[];
extern const u8 gText_AaronEndo[];
extern const u8 gText_JoeBooth[];
extern const u8 gText_ExecutiveProducer[];
extern const u8 gText_AndrewWilliams[];
extern const u8 gText_Producer[];
extern const u8 gText_BamEntertainment[];
extern const u8 gText_JonathanShearn[];
extern const u8 gText_QualityAssurance[];
extern const u8 gText_DevelopmentAssistant[];
extern const u8 gText_ColinKendrick[];
extern const u8 gText_TechnicalManager[];
extern const u8 gText_DirectorOfDevelopment[];
extern const u8 gText_ProducerDesigner[];
extern const u8 gText_RockettMusic[];
extern const u8 gText_MusicSfx[];
extern const u8 gText_JoStearn[];
extern const u8 gText_AdditionalArt[];
extern const u8 gText_TerryFord[];
extern const u8 gText_GraphicArtist[];
extern const u8 gText_GianlucaCancelmi[];
extern const u8 gText_AssistantProgrammer[];
extern const u8 gText_LeadProgrammer[];
extern const u8 gText_CrawfishInteractive[];
extern const u8 gText_EmptyCreditLine[];
extern const u8 gText_HardcoreChallenges[];
extern const u8 gText_HardChallenges[];
extern const u8 gText_MediumChallenges[];
extern const u8 gText_EasyChallenges[];
extern const u8 gText_YouHaveBeatenAllThe[];
extern const u8 gText_MUltiplayer[];
extern const u8 gText_4th2[];
extern const u8 gText_3rd2[];
extern const u8 gText_2nd2[];
extern const u8 gText_1st2[];
extern const u8 gText_SingleRacePits[];
extern const u8 gText_YouDidntBeatTheHeat[];
extern const u8 gText_BadLuck2[];
extern const u8 gText_50[];
extern const u8 gText_5[];
extern const u8 gText_ButYouAlreadyDidBetter[];
extern const u8 gText_ChooseChallenge[];
extern const u8 gText_YouCompletedBeatTheHeat[];
extern const u8 gText_YouBeatTheHeat[];
extern const u8 gText_BeatTheHeatHardcore[];
extern const u8 gText_BeatTheHeatHard[];
extern const u8 gText_BeatTheHeatMEdium[];
extern const u8 gText_BeatTheHeatEasy[];
extern const u8 gText_NowTryHardcoreDifficulty[];
extern const u8 gText_NowTryHardDifficulty[];
extern const u8 gText_NowTryMediumDifficulty[];
extern const u8 gText_YouBeatTheHeat2[];
extern const u8 gText_Congratulations2[];
extern const u8 gText_Hardcore[];
extern const u8 gText_Hard[];
extern const u8 gText_Medium[];
extern const u8 gText_Easy[];
extern const u8 gText_BankLabel[];
extern const u8 gText_LengthLabel[];
extern const u8 gText_ChooseTrack[];
extern const u8 gText_SplitLabel[];
extern const u8 gText_QualifyingLap2[];
extern const u8 gText_WarmupLap[];
extern const u8 gText_ChangeDriver[];
extern const u8 gText_OutOfTime2[];
extern const u8 gText_LapTimeLabel[];
extern const u8 gText_Checkpoint[];
extern const u8 gText_RaceOver[];
extern const u8 gText_Paused2[];
extern const u8 gText_YouCompletedStoryMode[];
extern const u8 gText_OrTurnPowerOff[];
extern const u8 gText_DoNotRemoveCable[];
extern const u8 gText_YouWonTheChampionship[];
extern const u8 gText_YourRatingIs[];
extern const u8 gText_YouCompletedArcadeMode[];
extern const u8 gText_SeasonComPleted[];
extern const u8 gText_YouDidIt[];
extern const u8 gText_Save[];
extern const u8 gText_Load[];
extern const u8 gText_Free[];
extern const u8 gText_Replay[];
extern const u8 gText_Rev[];
extern const u8 gText_Speed[];
extern const u8 gText_Acceleration[];
extern const u8 gText_GameOver[];
extern const u8 gText_Go[];
extern const u8 gText_DemoMode2[];
extern const u8 gText_Continue[];
extern const u8 gText_Exit[];
extern const u8 gText_Zone[];
extern const u8 gText_Timer2[];
extern const u8 gText_Lap2[];
extern const u8 gText_Best[];
extern const u8 gText_Mph[];
extern const u8 gText_DoNotRemoveCableOrTurnPowerOff[];
extern const u8 gText_Sending[];
extern const u8 gText_PleaseWait[];
extern const u8 gText_LinkFail[];
extern const u8 gText_LinkOk[];
extern const u8 gText_Handling[];
extern const u8 gText_MaxSpeed[];
extern const u8 gText_SelectTeam[];
extern const u8 gText_LanguageSelect[];
extern const u8 gText_SelectDriver[];
extern const u8 gText_PasswordAccepted[];
extern const u8 gText_PasswordRejected[];
extern const u8 gText_PasswordEntry[];
extern const u8 gText_RadioControlCar[];
extern const u8 gText_RadioControlMenu[];
extern const u8 gText_No3[];
extern const u8 gText_Yes2[];
extern const u8 gText_AreYouSure2[];
extern const u8 gText_Time2[];
extern const u8 gText_Position[];
extern const u8 gText_Saving[];
extern const u8 gText_SaveError[];
extern const u8 gText_SaveOk[];
extern const u8 gText_SaveCareer[];
extern const u8 gText_NewGame[];
extern const u8 gText_LoadGame[];
extern const u8 gText_RollingStart[];
extern const u8 gText_RaceSumMAry[];
extern const u8 gText_MUltiplayerMEnu[];
extern const u8 gText_MAinMEnu[];
extern const u8 gText_Waiting[];
extern const u8 gText_OkLink[];
extern const u8 gText_Player4Link[];
extern const u8 gText_Player3Link[];
extern const u8 gText_Player2Link[];
extern const u8 gText_Player1Link[];
extern const u8 gText_SinglePakLink[];
extern const u8 gText_MultiPakLink[];
extern const u8 gText_TopSecretCars[];
extern const u8 gText_CareerMode[];
extern const u8 gText_TimeTrial[];
extern const u8 gText_Multiplayer[];
extern const u8 gText_BeatTheHeat[];
extern const u8 gText_SingleRace[];
extern const u8 gText_ArcadeMode[];
extern const u8 gText_100[];
extern const u8 gText_30[];
extern const u8 gText_20[];
extern const u8 gText_15[];
extern const u8 gText_10[];
extern const u8 gText_On[];
extern const u8 gText_Off[];
extern const u8 gText_Expert[];
extern const u8 gText_Easy2[];
extern const u8 gText_Hard2[];
extern const u8 gText_Normal[];
extern const u8 gText_Controls[];
extern const u8 gText_Sfx[];
extern const u8 gText_Music[];
extern const u8 gText_Transmission[];
extern const u8 gText_Laps[];
extern const u8 gText_GhostCar[];
extern const u8 gText_Handicap[];
extern const u8 gText_GameDifficulty[];
extern const u8 gText_Options[];
extern const u8 gText_PosDriverNamePoints[];
extern const u8 gText_SeasonResults[];
extern const u8 gText_QualifyResults[];
extern const u8 gText_ChampPracticeResults[];
extern const u8 gText_RaceResults[];
extern const u8 gText_Total100Pct[];
extern const u8 gText_WinLose100Pct[];
extern const u8 gText_Newsstands100Pct[];
extern const u8 gText_Trailers100Pct[];
extern const u8 gText_Manholes100Pct[];
extern const u8 gText_BonusScoreTally[];
extern const u8 gText_CityStage4[];
extern const u8 gText_CityStage3[];
extern const u8 gText_CityStage2[];
extern const u8 gText_CityStage1[];
extern const u8 gText_BonusStageSelect[];
extern const u8 gText_StoryRaceResults[];
extern const u8 gText_StoryObjectiveTextD[];
extern const u8 gText_StoryObjectiveTextC[];
extern const u8 gText_StoryObjectiveTextB[];
extern const u8 gText_StoryObjectiveTextA[];
extern const u8 gText_StoryObjective[];
extern const u8 gText_StoryOutlineTextD[];
extern const u8 gText_StoryOutlineTextC[];
extern const u8 gText_StoryOutlineTextB[];
extern const u8 gText_StoryOutlineTextA[];
extern const u8 gText_HaveNowBeenAcceptedOn[];
extern const u8 gText_YouPassedTheChallengeAnd[];
extern const u8 gText_TheTeam[];
extern const u8 gText_YouFailedToQualifyFor[];
extern const u8 gText_TeamChallengeResults[];
extern const u8 gText_SingleRaceResults[];
extern const u8 gText_TimETrialResults[];
extern const u8 gText_ResultsSampleTimes[];
extern const u8 gText_ArcadeRaceResults[];
extern const u8 gText_PressStart[];
extern const u8 gText_ChangeBonusStage[];
extern const u8 gText_BonusRoundRetry[];
extern const u8 gText_ChooseNewStory[];
extern const u8 gText_StoryRetry[];
extern const u8 gText_ArcadeRetry[];
extern const u8 gText_SingleRaceRetry[];
extern const u8 gText_Quit[];
extern const u8 gText_ChangeTeam[];
extern const u8 gText_ChangeTrack[];
extern const u8 gText_Retry[];
extern const u8 gText_TimETrial[];
extern const u8 gText_Race2[];
extern const u8 gText_Qualify[];
extern const u8 gText_Practice2[];
extern const u8 gText_SeasonOptions[];
extern const u8 gText_Challenge16[];
extern const u8 gText_Challenge15[];
extern const u8 gText_Challenge14[];
extern const u8 gText_Challenge13[];
extern const u8 gText_Challenge12[];
extern const u8 gText_Challenge11[];
extern const u8 gText_Challenge10[];
extern const u8 gText_Challenge9[];
extern const u8 gText_Challenge8[];
extern const u8 gText_Challenge7[];
extern const u8 gText_Challenge6[];
extern const u8 gText_Challenge5[];
extern const u8 gText_Challenge4[];
extern const u8 gText_Challenge3[];
extern const u8 gText_Challenge2[];
extern const u8 gText_Challenge1[];
extern const u8 gText_TakesToBeatThemAll[];
extern const u8 gText_LetsSeeIfYouHaveWhatIt[];
extern const u8 gText_Victory[];
extern const u8 gText_AndHoldThemOffForThe[];
extern const u8 gText_CanYouPassTheEntireField[];
extern const u8 gText_PlaceWith20LapsToGo[];
extern const u8 gText_ChallengeYoureInLast[];
extern const u8 gText_RacewayIsTheSiteForThis[];
extern const u8 gText_MichiganInternational[];
extern const u8 gText_To1stAndCaptureTheGold[];
extern const u8 gText_SeeIfYouCanGoFrom3rd[];
extern const u8 gText_15LapsToGo[];
extern const u8 gText_EarnhardtJrs8RideWith[];
extern const u8 gText_TakeTheWheelOfDale[];
extern const u8 gText_AsphaltCityToGiveItATry[];
extern const u8 gText_CircuitInTheFictional[];
extern const u8 gText_BeenDoneSoWeveBuiltA[];
extern const u8 gText_NascarCityRacesHaveNever[];
extern const u8 gText_TheGold[];
extern const u8 gText_OvertakeRustyAndBringHome[];
extern const u8 gText_DraftHesInThe1RideTo[];
extern const u8 gText_UseYourTeamMateSteveParks[];
extern const u8 gText_No2[];
extern const u8 gText_BehindRustyWallaceInThe[];
extern const u8 gText_Juniors8RideIn3rdPlace[];
extern const u8 gText_ThisChallengeYoureInDale[];
extern const u8 gText_GreenValleyIsTheSiteFor[];
extern const u8 gText_TheChampionship[];
extern const u8 gText_BeatOutKevinHarvickFor[];
extern const u8 gText_TheLeadForALapInOrderTo[];
extern const u8 gText_GetInTo1stPlaceAndKeep[];
extern const u8 gText_ToGo[];
extern const u8 gText_AreIn4thPlaceWith15Laps[];
extern const u8 gText_SeasonAtGreatCanyonYou[];
extern const u8 gText_ThisIsTheLastRaceOfThe[];
extern const u8 gText_AndPassDjToWin[];
extern const u8 gText_GoLetsSeeIfYouCanCatch[];
extern const u8 gText_VictoryYouveGot5LapsTo[];
extern const u8 gText_SeeIfYouCanLeadParkToA[];
extern const u8 gText_LeadAndWinTheRace[];
extern const u8 gText_QuickPitStopToTakeThe[];
extern const u8 gText_DaleJarrettUsedALightning[];
extern const u8 gText_AfterLeadingFor164Laps[];
extern const u8 gText_LostAtDarlingtonRaceway[];
extern const u8 gText_OnMarch182001StevePark[];
extern const u8 gText_Race[];
extern const u8 gText_YouHave10LapsToWinThe[];
extern const u8 gText_AHardChargingRickyRudd[];
extern const u8 gText_ToVictoryWhileFightingOff[];
extern const u8 gText_YouDriveGordonsDupont24[];
extern const u8 gText_His100thCareerWinCould[];
extern const u8 gText_InternationalRacewayFor[];
extern const u8 gText_OffRickyRuddAtMichigan[];
extern const u8 gText_OnJune10thJeffGordonHeld[];
extern const u8 gText_Ride[];
extern const u8 gText_MarlinIsLendingYouHis40[];
extern const u8 gText_LuckilyForYouSterling[];
extern const u8 gText_ThinkYouCanDoIt[];
extern const u8 gText_Record[];
extern const u8 gText_You3LapsToBreakThis[];
extern const u8 gText_118MphWereGoingToGive[];
extern const u8 gText_InternationalRacewayIs[];
extern const u8 gText_RecordAtPhoenix[];
extern const u8 gText_TheAverageLapTopSpeed[];
extern const u8 gText_RecordTime[];
extern const u8 gText_YouHave3LapsToBeatThe[];
extern const u8 gText_CanYouTopThat[];
extern const u8 gText_QualifyingLap[];
extern const u8 gText_Amazing2829Second[];
extern const u8 gText_DarlingtonRacewayIsAn[];
extern const u8 gText_TheTrackRecordAt[];
extern const u8 gText_DrivingHis2Ride[];
extern const u8 gText_ToMakeThingsFairYoullBe[];
extern const u8 gText_Time[];
extern const u8 gText_YouHave5LapsToBeatHis[];
extern const u8 gText_Seconds[];
extern const u8 gText_HeSetALapTimeOf2683[];
extern const u8 gText_InternationalRaceway[];
extern const u8 gText_QualifyingRecordAtPhoenix[];
extern const u8 gText_RustyWallaceHoldsThe[];
extern const u8 gText_Victory2[];
extern const u8 gText_SeeIfYouCanLeadRuddTo[];
extern const u8 gText_With10LapsToGo[];
extern const u8 gText_YouAreInRickyRudds28[];
extern const u8 gText_ReWriteHistory[];
extern const u8 gText_HereIsYourChanceTo[];
extern const u8 gText_WithTheVictoryOnThatDay[];
extern const u8 gText_30thJeffGordonWalkedAway[];
extern const u8 gText_FirstMajorRaceOnSeptember[];
extern const u8 gText_KansasSpeedwayRanIts[];
extern const u8 gText_ThereForALap[];
extern const u8 gText_LeadFrom2ndPlaceAndStay[];
extern const u8 gText_WillNeedToGetIntoThe[];
extern const u8 gText_ToPassThisChallengeYou[];
extern const u8 gText_Frontrunners[];
extern const u8 gText_UnderpoweredComparedToThe[];
extern const u8 gText_CarWhichIsSlightly[];
extern const u8 gText_YouAreInControlOfThe102[];
extern const u8 gText_4Seconds[];
extern const u8 gText_HooleyDownsInLessThan[];
extern const u8 gText_First2RightHandTurnsOn[];
extern const u8 gText_YouNeedToNegotiateThe[];
extern const u8 gText_GoForIt[];
extern const u8 gText_StillFinishIn1st[];
extern const u8 gText_CanYouMakeAPitStopAnd[];
extern const u8 gText_VisitedThePits[];
extern const u8 gText_TheOtherDriversHaveAlready[];
extern const u8 gText_CrawfishRaceway2[];
extern const u8 gText_10LapsRemainingAt[];
extern const u8 gText_YouAreIn1stPlaceWith[];
extern const u8 gText_ToPassThisChallenge[];
extern const u8 gText_YouMustFinishInTheTop3[];
extern const u8 gText_Remaining[];
extern const u8 gText_InFirstPlaceWith5Laps[];
extern const u8 gText_YouAreAtKansasSpeedway[];
extern const u8 gText_OrQuicker[];
extern const u8 gText_ATimeOf32Seconds[];
extern const u8 gText_InfogramesSuperSpeedwayIn[];
extern const u8 gText_YouNeedToCompleteALapOf[];
extern const u8 gText_BlankRowChallengeGoal[];
extern const u8 gText_MoreThan9Seconds[];
extern const u8 gText_InternationalRacewayInNo[];
extern const u8 gText_3And4OfMichigan[];
extern const u8 gText_YouNeedToGetRoundTurns[];
extern const u8 gText_YouAreJimmyBly[];

// The credits scroller's script table (struct CreditLine, structs.h):
// one row per 8-pixel scroll step, run top to bottom by sub_08016330.
const struct CreditLine gCreditTexts[] = {
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_CrawfishInteractive, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_LeadProgrammer, 0 },
    { gText_EmptyCreditLine, 0x1 }, { gText_ChrisWalsh, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_AssistantProgrammer, 0 }, { gText_EmptyCreditLine, 0x1 },
    { gText_GianlucaCancelmi, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_GraphicArtist, 0 }, { gText_EmptyCreditLine, 0x1 }, { gText_TerryFord, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_AdditionalArt, 0 },
    { gText_EmptyCreditLine, 0x1 }, { gText_JoStearn, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_MusicSfx, 0 }, { gText_EmptyCreditLine, 0x1 },
    { gText_RockettMusic, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_ProducerDesigner, 0 }, { gText_EmptyCreditLine, 0x1 }, { gText_MitchellSlater, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_DirectorOfDevelopment, 0 },
    { gText_EmptyCreditLine, 0x1 }, { gText_MikeMerren, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_TechnicalManager, 0 }, { gText_EmptyCreditLine, 0x1 },
    { gText_ColinKendrick, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_DevelopmentAssistant, 0 }, { gText_EmptyCreditLine, 0x1 }, { gText_DaveMurphy, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_QualityAssurance, 0 },
    { gText_EmptyCreditLine, 0x1 }, { gText_TimCoode, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_WillGreenough, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_JonathanShearn, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_BamEntertainment, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_Producer, 0 },
    { gText_EmptyCreditLine, 0x1 }, { gText_AndrewWilliams, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_ExecutiveProducer, 0 }, { gText_EmptyCreditLine, 0x1 },
    { gText_JoeBooth, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_AaronEndo, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_DirectorOfEuropeanMarketing, 0 },
    { gText_EmptyCreditLine, 0x1 }, { gText_LisaCheneyBolcato, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_DirectorOfAmericanMarketing, 0 }, { gText_EmptyCreditLine, 0x1 },
    { gText_ScottSmith, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_ProductManager, 0 }, { gText_EmptyCreditLine, 0x1 }, { gText_DavidBlundell, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_DirectorOfAmericanPr, 0 },
    { gText_EmptyCreditLine, 0x1 }, { gText_SusanKramer, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EuropeanPrManager, 0 }, { gText_EmptyCreditLine, 0x1 },
    { gText_CatChannon, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_FranchisePictures, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_ExecutiveProducer, 0 }, { gText_EmptyCreditLine, 0x1 }, { gText_ElieSamaha, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_Producer, 0 },
    { gText_EmptyCreditLine, 0x1 }, { gText_LeezaMariaElkhazen, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_WorldWideMarketing, 0 }, { gText_EmptyCreditLine, 0x1 },
    { gText_LoriDrazen, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_SpecialThanks, 0 }, { gText_EmptyCreditLine, 0x1 }, { gText_CameronSheppard, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_LynneBradstock, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_RobWalkley, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_JohnTaylor, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_JonTrafford, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_MikeCartabianoAtSennari, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_BillHudson, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_ExtraSpecialThanks, 0 },
    { gText_EmptyCreditLine, 0x1 }, { gText_MichelleLamb, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_DanielWalsh, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_CherylSlater, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_MarinaCerra, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 },
    { gText_EmptyCreditLine, 0x1 }, { gText_EmptyCreditLine, 0x1 }
};
const u8 *const gGameTexts[] = {
    gText_SeasonOptions, gText_Practice2, gText_Qualify,
    gText_Race2, gText_TimETrial, gText_Retry,
    gText_ChangeTrack, gText_ChangeTeam, gText_Quit,
    gText_SingleRaceRetry, gText_ArcadeRetry, gText_StoryRetry,
    gText_ChooseNewStory, gText_BonusRoundRetry, gText_ChangeBonusStage,
    gText_PressStart, gText_ArcadeRaceResults, gText_ResultsSampleTimes,
    gText_TimETrialResults, gText_SingleRaceResults, gText_TeamChallengeResults,
    gText_YouFailedToQualifyFor, gText_TheTeam, gText_YouPassedTheChallengeAnd,
    gText_HaveNowBeenAcceptedOn, gText_TheTeam, gText_StoryOutlineTextA,
    gText_StoryOutlineTextB, gText_StoryOutlineTextC, gText_StoryOutlineTextD,
    gText_StoryObjective, gText_StoryObjectiveTextA, gText_StoryObjectiveTextB,
    gText_StoryObjectiveTextC, gText_StoryObjectiveTextD, gText_StoryRaceResults,
    gText_BonusStageSelect, gText_CityStage1, gText_CityStage2,
    gText_CityStage3, gText_CityStage4, gText_BonusScoreTally,
    gText_Manholes100Pct, gText_Trailers100Pct, gText_Newsstands100Pct,
    gText_WinLose100Pct, gText_Total100Pct, gText_RaceResults,
    gText_ChampPracticeResults, gText_QualifyResults, gText_SeasonResults,
    gText_PosDriverNamePoints, gText_Options, gText_GameDifficulty,
    gText_Handicap, gText_GhostCar, gText_Laps,
    gText_Transmission, gText_Music, gText_Sfx,
    gText_Controls, gText_Normal, gText_Hard2,
    gText_Easy2, gText_Expert, gText_Off,
    gText_On, gText_10, gText_15,
    gText_20, gText_30, gText_100,
    gText_ArcadeMode, gText_SingleRace, gText_BeatTheHeat,
    gText_Multiplayer, gText_TimeTrial, gText_CareerMode,
    gText_Options, gText_Options, gText_TopSecretCars,
    gText_MultiPakLink, gText_SinglePakLink, gText_Player1Link,
    gText_Player2Link, gText_Player3Link, gText_Player4Link,
    gText_OkLink, gText_Waiting, gText_MAinMEnu,
    gText_MUltiplayerMEnu, gText_RaceSumMAry, gText_Qualify,
    gText_RollingStart, gText_LoadGame, gText_NewGame,
    gText_SaveCareer, gText_SaveOk, gText_SaveError,
    gText_Saving, gText_Position, gText_Time2,
    gText_AreYouSure2, gText_Yes2, gText_No3,
    gText_RadioControlMenu, gText_RadioControlCar, gText_PasswordEntry,
    gText_PasswordRejected, gText_PasswordAccepted, gText_SelectDriver,
    gText_LanguageSelect, gText_SelectTeam, gText_MaxSpeed,
    gText_Handling, gText_SelectDriver, gText_LinkOk,
    gText_LinkFail, gText_PleaseWait, gText_Sending,
    gText_DoNotRemoveCableOrTurnPowerOff, gText_Mph, gText_Best,
    gText_Time2, gText_Lap2, gText_Position,
    gText_Timer2, gText_Zone, gText_Exit,
    gText_Continue, gText_DemoMode2, gText_Go,
    gText_GameOver, gText_Acceleration, gText_MaxSpeed,
    gText_Handling, gText_Speed, gText_Rev,
    gText_Replay, gText_Free, gText_Load,
    gText_Save, gText_YouDidIt, gText_SeasonComPleted,
    gText_YouCompletedArcadeMode, gText_YourRatingIs, gText_YouWonTheChampionship,
    gText_DoNotRemoveCable, gText_OrTurnPowerOff, gText_YouCompletedStoryMode,
    gText_Paused2, gText_RaceOver, gText_Checkpoint,
    gText_YouDidIt, gText_LapTimeLabel, gText_OutOfTime2,
    gText_SelectDriver, gText_ChangeDriver, gText_WarmupLap,
    gText_QualifyingLap2, gText_SplitLabel, gText_ChooseTrack,
    gText_LengthLabel, gText_BankLabel, gText_BeatTheHeat,
    gText_Easy, gText_Medium, gText_Hard,
    gText_Hardcore, gText_Congratulations2, gText_YouBeatTheHeat2,
    gText_NowTryMediumDifficulty, gText_NowTryHardDifficulty, gText_NowTryHardcoreDifficulty,
    gText_BeatTheHeatEasy, gText_BeatTheHeatMEdium, gText_BeatTheHeatHard,
    gText_BeatTheHeatHardcore, gText_YouBeatTheHeat, gText_YouCompletedBeatTheHeat,
    gText_ChooseChallenge, gText_ButYouAlreadyDidBetter, gText_5,
    gText_10, gText_15, gText_20,
    gText_30, gText_50, gText_100,
    gText_BadLuck2, gText_YouDidntBeatTheHeat, gText_SingleRacePits,
    gText_1st2, gText_2nd2, gText_3rd2,
    gText_4th2, gText_MUltiplayer, gText_YouHaveBeatenAllThe,
    gText_EasyChallenges, gText_MediumChallenges, gText_HardChallenges,
    gText_HardcoreChallenges
};
// Its users declare it as u8 *x[].
const u8 *const gChallengeNameTexts[] = {
    gText_Challenge1, gText_Challenge2, gText_Challenge3,
    gText_Challenge4, gText_Challenge5, gText_Challenge6,
    gText_Challenge7, gText_Challenge8, gText_Challenge9,
    gText_Challenge10, gText_Challenge11, gText_Challenge12,
    gText_Challenge13, gText_Challenge14, gText_Challenge15,
    gText_Challenge16
};
// Its users declare it as u8 *x[].
const u8 *const gChallengeGoalTexts[] = {
    gText_YouNeedToGetRoundTurns, gText_3And4OfMichigan, gText_InternationalRacewayInNo,
    gText_MoreThan9Seconds, gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal,
    gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal,
    gText_BlankRowChallengeGoal, gText_YouNeedToCompleteALapOf, gText_InfogramesSuperSpeedwayIn,
    gText_ATimeOf32Seconds, gText_OrQuicker, gText_BlankRowChallengeGoal,
    gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal,
    gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal, gText_YouAreAtKansasSpeedway,
    gText_InFirstPlaceWith5Laps, gText_Remaining, gText_YouMustFinishInTheTop3,
    gText_ToPassThisChallenge, gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal,
    gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal,
    gText_YouAreIn1stPlaceWith, gText_10LapsRemainingAt, gText_CrawfishRaceway2,
    gText_TheOtherDriversHaveAlready, gText_VisitedThePits, gText_BlankRowChallengeGoal,
    gText_BlankRowChallengeGoal, gText_CanYouMakeAPitStopAnd, gText_StillFinishIn1st,
    gText_GoForIt, gText_YouNeedToNegotiateThe, gText_First2RightHandTurnsOn,
    gText_HooleyDownsInLessThan, gText_4Seconds, gText_BlankRowChallengeGoal,
    gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal,
    gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal, gText_YouAreInControlOfThe102,
    gText_CarWhichIsSlightly, gText_UnderpoweredComparedToThe, gText_Frontrunners,
    gText_ToPassThisChallengeYou, gText_WillNeedToGetIntoThe, gText_LeadFrom2ndPlaceAndStay,
    gText_ThereForALap, gText_BlankRowChallengeGoal, gText_BlankRowChallengeGoal,
    gText_KansasSpeedwayRanIts, gText_FirstMajorRaceOnSeptember, gText_30thJeffGordonWalkedAway,
    gText_WithTheVictoryOnThatDay, gText_HereIsYourChanceTo, gText_ReWriteHistory,
    gText_YouAreInRickyRudds28, gText_With10LapsToGo, gText_SeeIfYouCanLeadRuddTo,
    gText_Victory2, gText_RustyWallaceHoldsThe, gText_QualifyingRecordAtPhoenix,
    gText_InternationalRaceway, gText_HeSetALapTimeOf2683, gText_Seconds,
    gText_YouHave5LapsToBeatHis, gText_Time, gText_ToMakeThingsFairYoullBe,
    gText_DrivingHis2Ride, gText_BlankRowChallengeGoal, gText_TheTrackRecordAt,
    gText_DarlingtonRacewayIsAn, gText_Amazing2829Second, gText_QualifyingLap,
    gText_BlankRowChallengeGoal, gText_CanYouTopThat, gText_BlankRowChallengeGoal,
    gText_YouHave3LapsToBeatThe, gText_RecordTime, gText_BlankRowChallengeGoal,
    gText_TheAverageLapTopSpeed, gText_RecordAtPhoenix, gText_InternationalRacewayIs,
    gText_118MphWereGoingToGive, gText_You3LapsToBreakThis, gText_Record,
    gText_ThinkYouCanDoIt, gText_LuckilyForYouSterling, gText_MarlinIsLendingYouHis40,
    gText_Ride, gText_OnJune10thJeffGordonHeld, gText_OffRickyRuddAtMichigan,
    gText_InternationalRacewayFor, gText_His100thCareerWinCould, gText_YouDriveGordonsDupont24,
    gText_ToVictoryWhileFightingOff, gText_AHardChargingRickyRudd, gText_YouHave10LapsToWinThe,
    gText_Race, gText_BlankRowChallengeGoal, gText_OnMarch182001StevePark,
    gText_LostAtDarlingtonRaceway, gText_AfterLeadingFor164Laps, gText_DaleJarrettUsedALightning,
    gText_QuickPitStopToTakeThe, gText_LeadAndWinTheRace, gText_SeeIfYouCanLeadParkToA,
    gText_VictoryYouveGot5LapsTo, gText_GoLetsSeeIfYouCanCatch, gText_AndPassDjToWin,
    gText_ThisIsTheLastRaceOfThe, gText_SeasonAtGreatCanyonYou, gText_AreIn4thPlaceWith15Laps,
    gText_ToGo, gText_BlankRowChallengeGoal, gText_GetInTo1stPlaceAndKeep,
    gText_TheLeadForALapInOrderTo, gText_BeatOutKevinHarvickFor, gText_TheChampionship,
    gText_BlankRowChallengeGoal, gText_GreenValleyIsTheSiteFor, gText_ThisChallengeYoureInDale,
    gText_Juniors8RideIn3rdPlace, gText_BehindRustyWallaceInThe, gText_No2,
    gText_UseYourTeamMateSteveParks, gText_DraftHesInThe1RideTo, gText_OvertakeRustyAndBringHome,
    gText_TheGold, gText_BlankRowChallengeGoal, gText_NascarCityRacesHaveNever,
    gText_BeenDoneSoWeveBuiltA, gText_CircuitInTheFictional, gText_AsphaltCityToGiveItATry,
    gText_TakeTheWheelOfDale, gText_EarnhardtJrs8RideWith, gText_15LapsToGo,
    gText_SeeIfYouCanGoFrom3rd, gText_To1stAndCaptureTheGold, gText_BlankRowChallengeGoal,
    gText_MichiganInternational, gText_RacewayIsTheSiteForThis, gText_ChallengeYoureInLast,
    gText_PlaceWith20LapsToGo, gText_CanYouPassTheEntireField, gText_AndHoldThemOffForThe,
    gText_Victory, gText_LetsSeeIfYouHaveWhatIt, gText_TakesToBeatThemAll,
    gText_BlankRowChallengeGoal
};
/* Dead data. Its only reader, sub_08016568, indexes it as [?][5][14],
 * but nothing calls that function, and only this one entry exists. */
const u8 *const gUnk_083FECAC[] = {
    gText_YouAreJimmyBly
};
/* Three-u16 pattern FormatSave repeats through the formatted save
 * block (a per-slot default), plus one trailing zero pad. */
const u16 gSaveFormatFillPattern[4] = {
    1, 30, 0, 0
};
/* Random AI finish-time range per track (struct AiFinishTimeRange,
 * structs.h): RandomizeAiFinishTimes rolls each AI finish time inside it. */
const struct AiFinishTimeRange gTrackAiFinishTimeRanges[12] = {
    { 26920, 28900 }, { 15280, 20200 }, { 37980, 39740 },
    { 27880, 29000 }, { 51140, 54200 }, { 38840, 41000 },
    { 21720, 22500 }, { 21720, 22500 }, { 23580, 24800 },
    { 43000, 45560 }, { 21320, 22250 }, { 29340, 31480 },
};
/* Lap length in lap-progress units, per track. */
const u32 gTrackLapLengths[12] = {
    500, 280, 500, 450, 800, 600,
    300, 0, 300, 620, 230, 450
};
