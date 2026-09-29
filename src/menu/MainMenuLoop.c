#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

extern const u8 gText_YouLose[];
extern const u8 gText_YourCareerIsOverAs[];
extern const u8 gText_NoTeamsWillTakeYou[];

extern u8 gUnk_0202A6B2;
extern u8 gUnk_0202CD9C[];
extern u8 gUnk_0202CDC0[];
extern s32 gMainMenuCursor;
extern u8 gUnk_0202EED4;
extern u8 gSeasonSession;
extern u8 gLapsPerOption[];
extern u8 gChampionshipTrackOrder[];
extern u8 gUnk_083FDE2D[];

u8 StartSinglePakLink(void);
void FillFadePalette(u16 color);
void InitTuneSettings(void);
u8 FindDriverByTeam(u8 value);
u8 IsAnyChampionshipTeamAvailable(void);
u8 CareerDecisionMenu(void);
u8 ResolveSeasonResult(u8 a, u8 b);
void ShowBootSplash1(void);
void SetupChallenge(u8 value, u8 *unused);
void ShowBootSplash3(void);
void ShowBootSplash2(void);
u8 TitleScreen(void);
s8 LinkTrackSelect(void);
u8 DriverSelectMenu(void);
u8 TeamSelectMenu(void);
u8 MultiplayerMenu(void);
u8 ShowLinkRaceSummary(void);
s8 LinkPostRaceMenu(void);
s16 LinkDriverSelect(void);
/* This caller narrows the result to s8. */
s8 LinkLobby(void);
void InitNewSaveData(void);
u8 OptionsMenu(void);
u8 ShowChallengeCategoryComplete(u8 value);
u8 RunChampionshipQualifyTest(u8 value);
u8 ShowChallengePassed(u8 a, u8 b);
u8 ChallengeFailedScreen(u8 value);
u32 GetPlayerStanding(void);
u8 TrophyScreen(u8 value);
u8 SeasonSessionMenu(u8 a, u8 b);
u8 CareerSessionMenu(u8 a, u8 b);
u8 QualifyResultsScreen(void);
void SaveCareerScreen(void);
u8 RaceResultsScreen(void);
u32 AwardAllRacePoints(void);
u8 StandingsScreen(void);
u8 TimeTrialMenu(void);
u8 ChallengeCategorySelect(void);
u8 ChallengeSelect(u8 a, u8 b);
u8 NewGameLoadMenu(void);
u8 SingleRaceResultsScreen(void);
u8 SingleRaceRetryMenu(void);
void SaveTrackRecords(void);
void LoadTrackRecords(void);
void LoadProgress(void);
void LoadOptions(void);
void SaveOptions(void);
void FormatSave(void);
void RandomizeAiFinishTimes(void);
u8 IsSaveValid(void);
void LinkFailScreen(void);
void LoadSeason(void);

u32 MainMenuLoop(void)
{
    u16 frame[0x100];
    u32 keys;
    u32 a6b2 = (u32)&gUnk_0202A6B2;
    u8 zero;
    u8 quit;
    s32 i;
    u8 redraw;
    u8 state;
    s8 result;
    s16 result16;
    u8 score;
    u8 choice;
    u8 track;
    u8 *p;
    u8 *dst;
    s8 one;

    one = 1;
    gIsTimeTrial = 0;
    zero = 0;
    gBgScrollUpdateEnabled = zero;
    gIsLinkRace = zero;
    ResetBgScroll();

    for (i = 0; i != 0x11; i++)
        gChampionshipAvailable[i] = 0;
    gChampionshipAvailable[0x0C] = 1;
    gChampionshipAvailable[0x0D] = 1;
    gChampionshipAvailable[0x0E] = 1;
    gChampionshipAvailable[0x0F] = 1;
    gChampionshipAvailable[0x10] = 1;

    ResetLinkState();
    if (IsSaveValid() == 0) {
        InitNewSaveData();
        FormatSave();
        SaveProgress();
        SaveOptions();
    }
    if (IsSaveValid() != 0) {
        LoadTrackRecords();
        LoadProgress();
        LoadOptions();
    }

    REG_BG2PA = 0x0100;
    REG_BG2PC = 0;
    REG_BG2PD = 0x0100;
    REG_BG3PA = 0x0100;
    REG_BG3PB = 0x0100;
    *(volatile s16 *)REG_ADDR_BG3PC = -0x100;
    REG_BG3PD = 0x0100;
    REG_BG2X_L = 0;
    REG_BG2X_H = 0;
    REG_BG2Y_L = 0;
    REG_BG2Y_H = 0;
    REG_BG3X_L = 0;
    REG_BG3X_H = 0;
    REG_BG3Y_L = 0;
    REG_BG3Y_H = 0;

    ShowBootSplash1();
    ShowBootSplash2();
    ShowBootSplash3();
    m4aSoundInit();
    FillFadePalette(0x7FFF);

    gLinkSyncByte = 0;
    gTireGripFast = 0x60;
    gFrontTireGripFast = 0xB6;
    gTireGripSlow = 0xA0;
    gFrontTireGripSlow = 0xFF;
    *(u32 *)&gTireSlipLimitBase = 0x8950;
    InitTuneSettings();
    gRngState = 0x009F9AC4;

    while (TitleScreen() == 1) {
        gCars[0].finishTime = 0;
        gCars[0].finished = 1;
        FinishAllCars(1);
        AssignRandomDrivers();
        SortCarsByTime();
        gNumLaps = 3;
        gDamagePitsEnabled = 0;
        RunRace(1, 0, gUnk_0202CDA8);
        ResetBgScroll();
    }

    for (i = 0; i != 0x18; i++)
        gCars[i].driverId = i % 0x0C;

    ZeroTextLayer();
    DrawMainMenu(0);
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    LoadMenuScreen(1, frame);
    if (gOptions[2] != 0)
        m4aSongNumStart(2);
    DrawMainMenu(gMainMenuCursor);
    FadeToBrightenedPalette(frame, 0x0F);

    redraw = 0;
    quit = 0;

    do {
        if (redraw != 0) {
            redraw = 0;
            REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
            LoadMenuScreen(1, frame);
            ZeroTextLayer();
            DrawMainMenu(gMainMenuCursor);
            FadeToBrightenedPalette(frame, 0x0F);
        }

        ReadKeys();
        keys = gKeysHeld;
        keys &= gKeysPressed;
        if ((keys & DPAD_UP) != 0) {
            if (--gMainMenuCursor < 0)
                gMainMenuCursor = 6;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
            DrawMainMenu(gMainMenuCursor);
        }
        if ((keys & DPAD_DOWN) != 0) {
            if (++gMainMenuCursor > 6)
                gMainMenuCursor = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
            DrawMainMenu(gMainMenuCursor);
        }

        if ((*(u8 *)REG_ADDR_SIOCNT & 0x30) == 0) {
            *(u16 *)&gLinkSendWords = (((*(u32 *)REG_ADDR_SIOCNT << 26) >> 30) + 1) << 12 | 1;
            SioSendWord(*(u16 *)&gLinkSendWords);
        }

        if (gMainMenuCursor == 3 && (keys & 9) != 0) {
            gDamagePitsEnabled = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(9);
            FadeToColor(0, 0x0F);
            gUnk_0202EED4 = 0;
            state = MultiplayerMenu();
            if (state == 1) {
                result = LinkLobby();
                if (result == 0)
                    goto state3_cleanup;

                *(u8 *)&gNumLinkPlayers = gLinkPlayerCount;
                gIsLinkRace = 1;
                gTrackId = 0;

            state3_prompt:
                result16 = LinkDriverSelect();
                FadeToColor(0, 0x0F);
                if (result16 == -2)
                    goto state3_done;
                if (result16 == -1)
                    goto state3_accept;

                FadeToColor(0, 0x0F);
            state3_menu:
                result = LinkTrackSelect();
                switch (result) {
                    case 1:
                        gTrackId = gTrackSelectCursor;
                        break;
                    case 0:
                        WaitForVBlank();
                        goto state3_prompt;
                    case 2:
                        goto state3_accept;
                }

            state3_launch:
                WaitForVBlank();
                gNumLaps = 3;
                gRngState = 0x009F9AC4;
                FadeToColor(0, 0x0F);
                if (RunRace(0, 3, gUnk_0202CDC0) != 0) {
                    FadeToColor(0, 0x0F);
                state3_accept:
                    LinkFailScreen();
                    goto state3_done;
                }

                m4aSongNumStart(2);
                ResetBgScroll();
                if (gRaceAborted == 0 && ShowLinkRaceSummary() == 5)
                    goto state3_accept;

                result = LinkPostRaceMenu();
                if (result == 0)
                    goto state3_launch;
                if (result == 1)
                    goto state3_menu;
                if (result == 2)
                    goto state3_prompt;
                if (result == 4)
                    return 0;
                if (result != 5)
                    goto state3_menu_done;
                goto state3_accept;

            state3_cleanup:
                if (gOptions[2] != 0)
                    m4aSongNumStart(2);
                ResetBgScroll();
                gIsLinkRace = 0;
                ClearOamBuffer();
                UpdateSprites();
                gVBlankWorkDone = 0;
                gBgScrollUpdateEnabled = 0;

            state3_menu_done:
                if (gOptions[2] != 0)
                    m4aSongNumStart(2);
            } else if (state == 2) {
                StopAllSongsAndVSyncOff();
                WaitForVBlank();
                if (StartSinglePakLink() != 0) {
                    FadeToColor(0, 0x0F);
                    StartMenuMusic();
                }
            }

        state3_done:
            if (gOptions[2] != 0)
                m4aSongNumStart(2);
            gIsLinkRace = 0;
            redraw = 1;
        }

        if (gMainMenuCursor == 0 && (keys & 9) != 0) {
            gDamagePitsEnabled = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(9);
            FadeToColor(0, 0x0F);

            for (i = 0; i != 0x18; i++)
                gCars[i].points = 0;

            *(u8 *)a6b2 = DriverSelectMenu();
            AssignRandomDrivers();
            FadeToColor(0, 0x0F);
            if ((gKeysPressed & B_BUTTON) != 0)
                goto state0_done;

            gQualifyingDone = 0;
            gPracticeDone = 0;
            gSeasonRaceIncomplete = 0;
            (*(u8 *)&gSeasonRaceIndex) = 0;

        state0_menu:
            choice = SeasonSessionMenu(gQualifyingDone | gSeasonRaceIncomplete, gSeasonRaceIncomplete | gPracticeDone);
            if ((gKeysPressed & B_BUTTON) != 0 || choice == 3)
                goto state0_done;

            gSeasonSession = choice;
            gTrackId = gChampionshipTrackOrder[(*(u8 *)&gSeasonRaceIndex)];
            switch (gSeasonSession) {
                case 0:
                    gNumLaps = 10;
                    gCars[0].finishTime = 0;
                    gCars[0].finished = 1;
                    FinishAllCars(1);
                    SortCarsByTime();
                    gCarOrder[0] = gCars;
                    gDamagePitsEnabled = 0;
                    TrackSelectMenu(0, gTrackId);
                    RunRace(0, 0x0E, gUnk_0202CD9C);
                    if (gOptions[2] != 0)
                        m4aSongNumStart(2);
                    ResetBgScroll();
                    if (gNewTrackRecord != 0)
                        SaveTrackRecords();
                    gPracticeDone = 1;
                    break;
                case 1:
                    gNumLaps = 2;
                    gCarOrder[0] = gCars;
                    gCars[0].finishTime = 0x0002BF20;
                    TrackSelectMenu(0, gTrackId);
                    RunRace(0, 0x11, gUnk_0202CDA8);
                    if (gOptions[2] != 0)
                        m4aSongNumStart(3);
                    ResetBgScroll();
                    RandomizeAiFinishTimes();
                    if (gNewTrackRecord != 0)
                        SaveTrackRecords();
                    gQualifyingDone = 1;
                    QualifyResultsScreen();
                    break;
                case 2:
                    if (gQualifyingDone == 0 || gSeasonRaceIncomplete == 1) {
                        gCars[0].finishTime = 0x0002BF20;
                        RandomizeAiFinishTimes();
                    }
                    SortCarsByTime();
                    gNumLaps = 3;
                    gNumLaps = gLapsPerOption[gOptions[1]];
                    TrackSelectMenu(0, gTrackId);
                    RunRace(0, 9, gUnk_0202CDA8);
                    if (gOptions[2] != 0)
                        m4aSongNumStart(2);
                    ResetBgScroll();
                    if (gRaceAborted == 0) {
                        gQualifyingDone = 0;
                        gPracticeDone = 0;
                        gSeasonRaceIncomplete = 0;
                        if (gNewTrackRecord != 0)
                            SaveTrackRecords();
                        RaceResultsScreen();
                        AwardAllRacePoints();
                        StandingsScreen();
                        (*(u8 *)&gSeasonRaceIndex)++;
                    } else {
                        gSeasonRaceIncomplete = 1;
                    }
                    break;
            }

            if ((*(u8 *)&gSeasonRaceIndex) != 0x0B)
                goto state0_menu;
            TrophyScreen(GetPlayerStanding());

        state0_done:
            redraw = 1;
        }

        if (gMainMenuCursor == 1 && (keys & 9) != 0) {
            gDamagePitsEnabled = 0;
            if (gOptions[4] != 0)
                gDamagePitsEnabled = 1;

            for (i = 0; i != 0x18; i++)
                gCars[i].driverId = i % 0x0C;

            if (gOptions[3] != 0)
                m4aSongNumStart(9);
            FadeToColor(0, 0x0F);

        state1_load:
            *(u8 *)a6b2 = DriverSelectMenu();
            AssignRandomDrivers();
            FadeToColor(0, 0x0F);
            if ((gKeysPressed & B_BUTTON) != 0)
                goto state1_done;

        state1_config:
            TrackSelectMenu(1, 0);
            FadeToColor(0, 0x0F);
            if ((gKeysPressed & B_BUTTON) != 0)
                goto state1_done;
            gTrackId = gTrackSelectCursor;
            gNumLaps = gLapsPerOption[gOptions[1]];

        state1_race:
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            FinishAllCars(1);
            for (i = 0; i != 0x18; i++)
                gCars[i].finishTime = i;
            gCars[0].finishTime = 0x0002CAD8;
            SortCarsByTime();
            RunRace(0, 9, gUnk_0202CDA8);
            if (gNewTrackRecord != 0)
                SaveTrackRecords();
            if (gOptions[2] != 0)
                m4aSongNumStart(2);
            ResetBgScroll();
            if (gRaceAborted == 0)
                SingleRaceResultsScreen();

            result = SingleRaceRetryMenu();
            if (result == 0)
                goto state1_race;
            if (result == 1)
                goto state1_config;
            if (result == 2)
                goto state1_load;

        state1_done:
            redraw = 1;
        }

        if (gMainMenuCursor == 4 && (keys & 9) != 0) {
            gDamagePitsEnabled = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(9);
            FadeToColor(0, 0x0F);

        state4_load:
            *(u8 *)a6b2 = DriverSelectMenu();
            AssignRandomDrivers();
            FadeToColor(0, 0x0F);
            if ((gKeysPressed & B_BUTTON) != 0)
                goto state4_done;

        state4_config:
            TrackSelectMenu(1, 0);
            gTrackId = gTrackSelectCursor;
            FadeToColor(0, 0x0F);
            if ((gKeysPressed & B_BUTTON) != 0)
                goto state4_done;
            gTrackId = gTrackSelectCursor;
            gNumLaps = 3;

        state4_race:
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            FinishAllCars(1);
            SortCarsByTime();
            gCarOrder[0] = gCars;
            gIsTimeTrial = 1;
            RunRace(0, 0x0E, gUnk_0202CD9C);
            gIsTimeTrial = 0;
            if (gOptions[2] != 0)
                m4aSongNumStart(2);
            ResetBgScroll();
            if (gNewTrackRecord != 0)
                SaveTrackRecords();

            result = TimeTrialMenu();
            if (result == 0)
                goto state4_race;
            if (result == 1)
                goto state4_config;
            if (result == 2)
                goto state4_load;

        state4_done:
            redraw = 1;
        }

        if (gMainMenuCursor == 2 && (keys & 9) != 0) {
            if (gOptions[3] != 0)
                m4aSongNumStart(9);
            FadeToColor(0, 0x0F);

        state2_select:
            track = ChallengeCategorySelect();
            if ((gKeysPressed & B_BUTTON) != 0)
                goto state2_done;
            gChallengeIndex = track << 2;

        state2_track:
            if ((s8)gChallengeStatus[gChallengeIndex] == -1) {
                gChallengeStatus[gChallengeIndex] = 0;
                SaveProgress();
            }
            gChallengeIndex = ChallengeSelect(track, gChallengeIndex);
            if ((gKeysPressed & B_BUTTON) != 0)
                goto state2_select;

            gChallengeScore = 0;
            dst = &gTrackId;
            p = gUnk_083FDE2D;
            p += *(volatile u8 *)&gChallengeIndex;
            *dst = *p;
            SetupChallenge(gChallengeIndex, dst);
            gDamagePitsEnabled = one;
            if (gChallengeIndex == 1)
                gDamagePitsEnabled = 0;
            if (gChallengeIndex == 6)
                gDamagePitsEnabled = 0;
            if (gChallengeIndex == 10)
                gDamagePitsEnabled = 0;
            if (gChallengeIndex == 14)
                gDamagePitsEnabled = 0;
            RunRace(0, 0x0F, gUnk_0202CDA8);
            gChallengeScore = gChallengeResult;
            if (gOptions[2] != 0)
                m4aSongNumStart(2);
            ResetBgScroll();

            if (gChallengeScore == 0)
                goto state2_no_score;

            ShowChallengePassed(gChallengeIndex, (s8)gChallengeStatus[gChallengeIndex] >= gChallengeScore);
            if (gChallengeScore > (s8)gChallengeStatus[gChallengeIndex]) {
                gChallengeStatus[gChallengeIndex] = gChallengeScore;
                SaveProgress();
            }

            gChallengeIndex++;
            if (gChallengeIndex == 4) {
                if (gChallengeCategoryUnlocked[1] != 0)
                    goto state2_select;
                gChallengeCategoryUnlocked[1] = 1;
                ShowChallengeCategoryComplete(1);
                SaveProgress();
                goto state2_select;
            }
            if (gChallengeIndex == 8) {
                if (gChallengeCategoryUnlocked[2] != 0)
                    goto state2_select;
                gChallengeCategoryUnlocked[2] = 1;
                ShowChallengeCategoryComplete(2);
                SaveProgress();
                goto state2_select;
            }
            if (gChallengeIndex == 12) {
                if (gChallengeCategoryUnlocked[3] != 0)
                    goto state2_select;
                gChallengeCategoryUnlocked[3] = 1;
                ShowChallengeCategoryComplete(3);
                SaveProgress();
                goto state2_select;
            }
            if (gChallengeIndex == 16) {
                if (gChallengeCategoryUnlocked[4] != 0)
                    goto state2_select;
                gChallengeCategoryUnlocked[4] = 1;
                ShowChallengeCategoryComplete(4);
                SaveProgress();
                goto state2_select;
            }
            goto state2_after_unlock;

        state2_no_score:
            ChallengeFailedScreen(gChallengeIndex);
            goto state2_track;

        state2_after_unlock:
            if (gChallengeScore == 0)
                goto state2_done;
            if (gChallengeIndex == 4 || gChallengeIndex == 8 || gChallengeIndex == 12 || gChallengeIndex == 16) {
                gChallengeCategoryUnlocked[gChallengeIndex >> 2] = 1;
                SaveOptions();
                goto state2_done;
            }
            goto state2_track;

        state2_done:
            redraw = 1;
        }

        if (gMainMenuCursor == 5 && (keys & 9) != 0) {
            gSeasonNumLaps = gLapsPerOption[gOptions[1]];
            gDamagePitsEnabled = 1;
            if (gOptions[3] != 0)
                m4aSongNumStart(9);
            FadeToColor(0, 0x0F);

            for (i = 0; i != 0x18; i++)
                gCars[i].points = 0;

            /* IsSeasonSaved: this file's old prototype returns u8; the matched definition returns u32 */
            if (((u8 (*)(void))IsSeasonSaved)() != 0) {
                result = NewGameLoadMenu();
                if ((gKeysPressed & B_BUTTON) != 0)
                    goto state5_done;
                if (result == 1) {
                    LoadSeason();
                    goto state5_menu;
                }
            }

        state5_setup:
            for (i = 0; i != 0x18; i++)
                gCars[i].points = 0;
            if (IsAnyChampionshipTeamAvailable() == 0) {
                MessageBox(gText_YouLose, gText_YourCareerIsOverAs, gText_NoTeamsWillTakeYou);
                goto state5_done;
            }

            gChampionshipIndex = TeamSelectMenu();
            if ((gKeysPressed & B_BUTTON) != 0)
                goto state5_done;
            *(u8 *)a6b2 = FindDriverByTeam(gChampionshipIndex);
            if (RunChampionshipQualifyTest(*(u8 *)a6b2) == 0)
                goto state5_setup;

        state5_load:
            *(u8 *)a6b2 = FindDriverByTeam(gChampionshipIndex);
            AssignRandomDrivers();
            FadeToColor(0, 0x0F);
            if ((gKeysPressed & B_BUTTON) != 0)
                goto state5_done;

            gQualifyingDone = 0;
            gPracticeDone = 0;
            gSeasonRaceIncomplete = 0;
            (*(u8 *)&gSeasonRaceIndex) = 0;

        state5_menu:
            choice = CareerSessionMenu(gQualifyingDone | gSeasonRaceIncomplete, gSeasonRaceIncomplete | gPracticeDone);
            if ((gKeysPressed & B_BUTTON) != 0 || choice == 4)
                goto state5_done;

            gSeasonSession = choice;
            gTrackId = gChampionshipTrackOrder[(*(u8 *)&gSeasonRaceIndex)];
            switch (gSeasonSession) {
                case 0:
                    gCars[0].finishTime = 0;
                    gCars[0].finished = 1;
                    FinishAllCars(1);
                    SortCarsByTime();
                    gCarOrder[0] = gCars;
                    gDamagePitsEnabled = 0;
                    TrackSelectMenu(0, gTrackId);
                    RunRace(0, 0x0E, gUnk_0202CD9C);
                    gDamagePitsEnabled = 1;
                    if (gOptions[2] != 0)
                        m4aSongNumStart(2);
                    ResetBgScroll();
                    if (gNewTrackRecord != 0)
                        SaveTrackRecords();
                    gPracticeDone = 1;
                    break;
                case 1:
                    gNumLaps = 2;
                    gCarOrder[0] = gCars;
                    gCars[0].finishTime = 0x0002BF20;
                    TrackSelectMenu(0, gTrackId);
                    RunRace(0, 0x11, gUnk_0202CDA8);
                    if (gOptions[2] != 0)
                        m4aSongNumStart(2);
                    ResetBgScroll();
                    RandomizeAiFinishTimes();
                    if (gNewTrackRecord != 0)
                        SaveTrackRecords();
                    gQualifyingDone = 1;
                    QualifyResultsScreen();
                    break;
                case 2:
                    if (gQualifyingDone == 0 || gSeasonRaceIncomplete == 1) {
                        gCars[0].finishTime = 0x0002BF20;
                        RandomizeAiFinishTimes();
                    }
                    SortCarsByTime();
                    gNumLaps = gSeasonNumLaps;
                    TrackSelectMenu(0, gTrackId);
                    RunRace(0, 9, gUnk_0202CDA8);
                    if (gOptions[2] != 0)
                        m4aSongNumStart(2);
                    ResetBgScroll();
                    if (gRaceAborted == 0) {
                        gQualifyingDone = 0;
                        gPracticeDone = 0;
                        gSeasonRaceIncomplete = 0;
                        if (gNewTrackRecord != 0)
                            SaveTrackRecords();
                        RaceResultsScreen();
                        AwardAllRacePoints();
                        StandingsScreen();
                        (*(u8 *)&gSeasonRaceIndex)++;
                    } else {
                        gSeasonRaceIncomplete = 1;
                    }
                    break;
                case 3:
                    SaveCareerScreen();
                    break;
            }

            if ((*(u8 *)&gSeasonRaceIndex) != 0x0B)
                goto state5_menu;
            score = GetPlayerStanding();
            TrophyScreen(score);
            if (ResolveSeasonResult(gChampionshipIndex, score) != 0)
                goto state5_setup;
            if (CareerDecisionMenu() != 0)
                goto state5_setup;
            goto state5_load;

        state5_done:
            redraw = 1;
        }

        if (gMainMenuCursor == 6 && (keys & 9) != 0) {
            if (gOptions[3] != 0)
                m4aSongNumStart(9);
            gMenuValueChanged = 0;
            FadeToColor(0, 0x0F);
            OptionsMenu();
            redraw = 1;
            if (gMenuValueChanged != 0)
                SaveOptions();
        }

        WaitForVBlank();
    } while (quit == 0);
    return 0;
}
