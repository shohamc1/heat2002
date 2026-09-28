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
void sub_08008338(void);
u8 sub_0800F120(u8 value);
u8 sub_0800F190(void);
u8 sub_0800F22C(void);
u8 sub_0800F2BC(u8 a, u8 b);
void sub_0800F560(void);
void SetupChallenge(u8 value, u8 *unused);
void sub_080102F0(void);
void sub_08010334(void);
u8 TitleScreen(void);
s8 LinkTrackSelect(void);
u8 sub_08010EA0(void);
u8 sub_08010CD0(void);
u8 sub_08011FC4(void);
u8 sub_08011528(void);
s8 sub_0801164C(void);
s16 LinkDriverSelect(void);
/* This caller narrows the result to s8. */
s8 sub_080122B4(void);
void InitNewSaveData(void);
u8 OptionsMenu(void);
u8 sub_080129E8(u8 value);
u8 sub_080128E0(u8 value);
u8 sub_08012B50(u8 a, u8 b);
u8 sub_08012BBC(u8 value);
u32 sub_08012C20(void);
u8 sub_08012D34(u8 value);
u8 sub_080136F8(u8 a, u8 b);
u8 sub_08013570(u8 a, u8 b);
u8 sub_08013D5C(void);
void sub_08013964(void);
u8 sub_08014004(void);
u32 AwardAllRacePoints(void);
u8 StandingsScreen(void);
u8 sub_080144F4(void);
u8 sub_0801465C(void);
u8 sub_08014874(u8 a, u8 b);
u8 sub_08014A84(void);
u8 sub_08014E28(void);
u8 sub_08014F5C(void);
void SaveTrackRecords(void);
void LoadTrackRecords(void);
void LoadProgress(void);
void LoadOptions(void);
void SaveOptions(void);
void FormatSave(void);
void sub_08016CB0(void);
u8 IsSaveValid(void);
void sub_080164A8(void);
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

    sub_0800F560();
    sub_08010334();
    sub_080102F0();
    m4aSoundInit();
    FillFadePalette(0x7FFF);

    gLinkSyncByte = 0;
    gTireGripFast = 0x60;
    gFrontTireGripFast = 0xB6;
    gTireGripSlow = 0xA0;
    gFrontTireGripSlow = 0xFF;
    *(u32 *)&gTireSlipLimitBase = 0x8950;
    sub_08008338();
    gRngState = 0x009F9AC4;

    while (TitleScreen() == 1) {
        gCars[0].finishTime = 0;
        gCars[0].finished = 1;
        sub_08016D28(1);
        AssignRandomDrivers();
        SortCarsByTime();
        gNumLaps = 3;
        gDamagePitsEnabled = 0;
        /* RunRace: this file's old local prototype differs from
           functions.h; call through the old signature (solved-walls 31). */
        ((void (*)(u32, u8, void *))RunRace)(1, 0, gUnk_0202CDA8);
        ResetBgScroll();
    }

    for (i = 0; i != 0x18; i++)
        gCars[i].driverId = i % 0x0C;

    ZeroTextLayer();
    sub_08010664(0);
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    sub_08011C9C(1, frame);
    if (gOptions[2] != 0)
        m4aSongNumStart(2);
    sub_08010664(gMainMenuCursor);
    FadeToBrightenedPalette((u32)frame, 0x0F);

    redraw = 0;
    quit = 0;

    do {
    if (redraw != 0) {
        redraw = 0;
        REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
        sub_08011C9C(1, frame);
        ZeroTextLayer();
        sub_08010664(gMainMenuCursor);
        FadeToBrightenedPalette((u32)frame, 0x0F);
    }

    ReadKeys();
    keys = gKeysHeld;
    keys &= gKeysPressed;
    if ((keys & DPAD_UP) != 0) {
        if (--gMainMenuCursor < 0)
            gMainMenuCursor = 6;
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        sub_08010664(gMainMenuCursor);
    }
    if ((keys & DPAD_DOWN) != 0) {
        if (++gMainMenuCursor > 6)
            gMainMenuCursor = 0;
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        sub_08010664(gMainMenuCursor);
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
        state = sub_08011FC4();
        if (state == 1) {
            result = sub_080122B4();
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
            if (((u8 (*)(u32, u8, void *))RunRace)(0, 3, gUnk_0202CDC0) != 0) {
                FadeToColor(0, 0x0F);
state3_accept:
                sub_080164A8();
                goto state3_done;
            }

            m4aSongNumStart(2);
            ResetBgScroll();
            if (gRaceAborted == 0 && sub_08011528() == 5)
                goto state3_accept;

            result = sub_0801164C();
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
                sub_080100B0();
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

        *(u8 *)a6b2 = sub_08010EA0();
        AssignRandomDrivers();
        FadeToColor(0, 0x0F);
        if ((gKeysPressed & B_BUTTON) != 0)
            goto state0_done;

        gQualifyingDone = 0;
        gPracticeDone = 0;
        gSeasonRaceIncomplete = 0;
        (*(u8 *)&gSeasonRaceIndex) = 0;

state0_menu:
        choice = sub_080136F8(
            gQualifyingDone | gSeasonRaceIncomplete,
            gSeasonRaceIncomplete | gPracticeDone);
        if ((gKeysPressed & B_BUTTON) != 0 || choice == 3)
            goto state0_done;

        gSeasonSession = choice;
        gTrackId = gChampionshipTrackOrder[(*(u8 *)&gSeasonRaceIndex)];
        switch (gSeasonSession) {
        case 0:
            gNumLaps = 10;
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            sub_08016D28(1);
            SortCarsByTime();
            (*(u32 *)&gCarOrder) = (u32)gCars;
            gDamagePitsEnabled = 0;
            TrackSelectMenu(0, gTrackId);
            ((void (*)(u32, u8, void *))RunRace)(0, 0x0E, gUnk_0202CD9C);
            if (gOptions[2] != 0)
                m4aSongNumStart(2);
            ResetBgScroll();
            if (gNewTrackRecord != 0)
                SaveTrackRecords();
            gPracticeDone = 1;
            break;
        case 1:
            gNumLaps = 2;
            (*(u32 *)&gCarOrder) = (u32)gCars;
            gCars[0].finishTime = 0x0002BF20;
            TrackSelectMenu(0, gTrackId);
            ((void (*)(u32, u8, void *))RunRace)(0, 0x11, gUnk_0202CDA8);
            if (gOptions[2] != 0)
                m4aSongNumStart(3);
            ResetBgScroll();
            sub_08016CB0();
            if (gNewTrackRecord != 0)
                SaveTrackRecords();
            gQualifyingDone = 1;
            sub_08013D5C();
            break;
        case 2:
            if (gQualifyingDone == 0 || gSeasonRaceIncomplete == 1) {
                gCars[0].finishTime = 0x0002BF20;
                sub_08016CB0();
            }
            SortCarsByTime();
            gNumLaps = 3;
            gNumLaps = gLapsPerOption[gOptions[1]];
            TrackSelectMenu(0, gTrackId);
            ((void (*)(u32, u8, void *))RunRace)(0, 9, gUnk_0202CDA8);
            if (gOptions[2] != 0)
                m4aSongNumStart(2);
            ResetBgScroll();
            if (gRaceAborted == 0) {
                gQualifyingDone = 0;
                gPracticeDone = 0;
                gSeasonRaceIncomplete = 0;
                if (gNewTrackRecord != 0)
                    SaveTrackRecords();
                sub_08014004();
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
        sub_08012D34(sub_08012C20());

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
        *(u8 *)a6b2 = sub_08010EA0();
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
        sub_08016D28(1);
        for (i = 0; i != 0x18; i++)
            gCars[i].finishTime = i;
        gCars[0].finishTime = 0x0002CAD8;
        SortCarsByTime();
        ((void (*)(u32, u8, void *))RunRace)(0, 9, gUnk_0202CDA8);
        if (gNewTrackRecord != 0)
            SaveTrackRecords();
        if (gOptions[2] != 0)
            m4aSongNumStart(2);
        ResetBgScroll();
        if (gRaceAborted == 0)
            sub_08014E28();

        result = sub_08014F5C();
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
        *(u8 *)a6b2 = sub_08010EA0();
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
        sub_08016D28(1);
        SortCarsByTime();
        (*(u32 *)&gCarOrder) = (u32)gCars;
        gIsTimeTrial = 1;
        ((void (*)(u32, u8, void *))RunRace)(0, 0x0E, gUnk_0202CD9C);
        gIsTimeTrial = 0;
        if (gOptions[2] != 0)
            m4aSongNumStart(2);
        ResetBgScroll();
        if (gNewTrackRecord != 0)
            SaveTrackRecords();

        result = sub_080144F4();
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
        track = sub_0801465C();
        if ((gKeysPressed & B_BUTTON) != 0)
            goto state2_done;
        gChallengeIndex = track << 2;

state2_track:
        if ((s8)gChallengeStatus[gChallengeIndex] == -1) {
            gChallengeStatus[gChallengeIndex] = 0;
            SaveProgress();
        }
        gChallengeIndex = sub_08014874(track, gChallengeIndex);
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
        ((void (*)(u32, u8, void *))RunRace)(0, 0x0F, gUnk_0202CDA8);
        gChallengeScore = gChallengeResult;
        if (gOptions[2] != 0)
            m4aSongNumStart(2);
        ResetBgScroll();

        if (gChallengeScore == 0)
            goto state2_no_score;

        sub_08012B50(
            gChallengeIndex,
            (s8)gChallengeStatus[gChallengeIndex] >= gChallengeScore);
        if (gChallengeScore > (s8)gChallengeStatus[gChallengeIndex]) {
            gChallengeStatus[gChallengeIndex] = gChallengeScore;
            SaveProgress();
        }

        gChallengeIndex++;
        if (gChallengeIndex == 4) {
            if (gChallengeCategoryUnlocked[1] != 0)
                goto state2_select;
            gChallengeCategoryUnlocked[1] = 1;
            sub_080129E8(1);
            SaveProgress();
            goto state2_select;
        }
        if (gChallengeIndex == 8) {
            if (gChallengeCategoryUnlocked[2] != 0)
                goto state2_select;
            gChallengeCategoryUnlocked[2] = 1;
            sub_080129E8(2);
            SaveProgress();
            goto state2_select;
        }
        if (gChallengeIndex == 12) {
            if (gChallengeCategoryUnlocked[3] != 0)
                goto state2_select;
            gChallengeCategoryUnlocked[3] = 1;
            sub_080129E8(3);
            SaveProgress();
            goto state2_select;
        }
        if (gChallengeIndex == 16) {
            if (gChallengeCategoryUnlocked[4] != 0)
                goto state2_select;
            gChallengeCategoryUnlocked[4] = 1;
            sub_080129E8(4);
            SaveProgress();
            goto state2_select;
        }
        goto state2_after_unlock;

state2_no_score:
        sub_08012BBC(gChallengeIndex);
        goto state2_track;

state2_after_unlock:
        if (gChallengeScore == 0)
            goto state2_done;
        if (gChallengeIndex == 4 || gChallengeIndex == 8 ||
            gChallengeIndex == 12 || gChallengeIndex == 16) {
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

        /* sub_08016634: this file's old prototype returns u8; the matched definition returns u32 */
        if (((u8 (*)(void))sub_08016634)() != 0) {
            result = sub_08014A84();
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
        if (sub_0800F190() == 0) {
            MessageBox(gText_YouLose, gText_YourCareerIsOverAs, gText_NoTeamsWillTakeYou);
            goto state5_done;
        }

        gChampionshipIndex = sub_08010CD0();
        if ((gKeysPressed & B_BUTTON) != 0)
            goto state5_done;
        *(u8 *)a6b2 = sub_0800F120(gChampionshipIndex);
        if (sub_080128E0(*(u8 *)a6b2) == 0)
            goto state5_setup;

state5_load:
        *(u8 *)a6b2 = sub_0800F120(gChampionshipIndex);
        AssignRandomDrivers();
        FadeToColor(0, 0x0F);
        if ((gKeysPressed & B_BUTTON) != 0)
            goto state5_done;

        gQualifyingDone = 0;
        gPracticeDone = 0;
        gSeasonRaceIncomplete = 0;
        (*(u8 *)&gSeasonRaceIndex) = 0;

state5_menu:
        choice = sub_08013570(
            gQualifyingDone | gSeasonRaceIncomplete,
            gSeasonRaceIncomplete | gPracticeDone);
        if ((gKeysPressed & B_BUTTON) != 0 || choice == 4)
            goto state5_done;

        gSeasonSession = choice;
        gTrackId = gChampionshipTrackOrder[(*(u8 *)&gSeasonRaceIndex)];
        switch (gSeasonSession) {
        case 0:
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            sub_08016D28(1);
            SortCarsByTime();
            (*(u32 *)&gCarOrder) = (u32)gCars;
            gDamagePitsEnabled = 0;
            TrackSelectMenu(0, gTrackId);
            ((void (*)(u32, u8, void *))RunRace)(0, 0x0E, gUnk_0202CD9C);
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
            (*(u32 *)&gCarOrder) = (u32)gCars;
            gCars[0].finishTime = 0x0002BF20;
            TrackSelectMenu(0, gTrackId);
            ((void (*)(u32, u8, void *))RunRace)(0, 0x11, gUnk_0202CDA8);
            if (gOptions[2] != 0)
                m4aSongNumStart(2);
            ResetBgScroll();
            sub_08016CB0();
            if (gNewTrackRecord != 0)
                SaveTrackRecords();
            gQualifyingDone = 1;
            sub_08013D5C();
            break;
        case 2:
            if (gQualifyingDone == 0 || gSeasonRaceIncomplete == 1) {
                gCars[0].finishTime = 0x0002BF20;
                sub_08016CB0();
            }
            SortCarsByTime();
            gNumLaps = gSeasonNumLaps;
            TrackSelectMenu(0, gTrackId);
            ((void (*)(u32, u8, void *))RunRace)(0, 9, gUnk_0202CDA8);
            if (gOptions[2] != 0)
                m4aSongNumStart(2);
            ResetBgScroll();
            if (gRaceAborted == 0) {
                gQualifyingDone = 0;
                gPracticeDone = 0;
                gSeasonRaceIncomplete = 0;
                if (gNewTrackRecord != 0)
                    SaveTrackRecords();
                sub_08014004();
                AwardAllRacePoints();
                StandingsScreen();
                (*(u8 *)&gSeasonRaceIndex)++;
            } else {
                gSeasonRaceIncomplete = 1;
            }
            break;
        case 3:
            sub_08013964();
            break;
        }

        if ((*(u8 *)&gSeasonRaceIndex) != 0x0B)
            goto state5_menu;
        score = sub_08012C20();
        sub_08012D34(score);
        if (sub_0800F2BC(gChampionshipIndex, score) != 0)
            goto state5_setup;
        if (sub_0800F22C() != 0)
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
