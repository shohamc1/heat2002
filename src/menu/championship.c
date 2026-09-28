#include "global.h"
#include "data.h"

#include "variables.h"
#include "functions.h"
extern const u8 gText_BadLuck[];
extern const u8 gText_YouVeBeenKicked[];
extern const u8 gText_OffTheTeam[];
extern const u8 gText_Congratulations[];
extern const u8 gText_YouAreAllowedTo[];
extern const u8 gText_StayOnThisTeam[];
extern const u8 gText_CareerDecision[];
extern const u8 gText_StayOnThisTeam_2[];
extern const u8 gText_ChooseANewTeam[];
#include "m4a.h"
extern u8 gChampionshipRequiredFinish[];
extern u8 gChampionshipTeamTiers[];


u8 FindDriverByTeam(u8 teamId)
{
    u8 driverIdx;

    for (driverIdx = 0; driverIdx != 0x1E; driverIdx++) {
        if (gDriverRoster[driverIdx].teamId == teamId)
            return driverIdx;
    }
    return 0;
}


void UnlockChampionshipTier(u8 tier)
{
    u8 tierVal;
    register u8 tierReg asm("r3");

    tierVal = tier;
    tierReg = tierVal;
    if (tierVal == 0) {
        gChampionshipAvailable[0] = 1;
        gChampionshipAvailable[1] = 1;
        gChampionshipAvailable[2] = 1;
        gChampionshipAvailable[3] = 1;
        gChampionshipAvailable[4] = 1;
        gChampionshipAvailable[5] = 1;
        gChampionshipAvailable[6] = 1;
    }
    if (tierVal == 1) {
        gChampionshipAvailable[7] = tierVal;
        gChampionshipAvailable[8] = tierVal;
        gChampionshipAvailable[9] = tierVal;
        gChampionshipAvailable[10] = tierVal;
        gChampionshipAvailable[11] = tierVal;
    }
    if (tierReg == 2) {
        gChampionshipAvailable[12] = 1;
        gChampionshipAvailable[13] = 1;
        gChampionshipAvailable[14] = 1;
        gChampionshipAvailable[15] = 1;
        gChampionshipAvailable[16] = 1;
    }
}


u32 IsAnyChampionshipTeamAvailable(void)
{
    u8 teamIdx;

    for (teamIdx = 0; teamIdx != 0x11; teamIdx++) {
        if (gChampionshipAvailable[teamIdx] != 0)
            return 1;
    }
    return 0;
}


void ShowKickedFromTeamMessage(void)
{
    MessageBox(gText_BadLuck, gText_YouVeBeenKicked, gText_OffTheTeam);
}


void ShowStayOnTeamMessage(void)
{
    MessageBox(gText_Congratulations, gText_YouAreAllowedTo, gText_StayOnThisTeam);
}


void DrawCareerDecision(u8 selected)
{
    const u8 *text;

    DrawBigText(gText_CareerDecision);
    text = gText_StayOnThisTeam_2;
    DrawTextCenteredHighlight(text, 8, selected == 0);
    text = gText_ChooseANewTeam;
    DrawTextCenteredHighlight(text, 0xA, selected == 1);
}


u8 CareerDecisionMenu(void)
{
    u8 palette[0x200];
    s8 cursor;
    s8 choice;
    cursor = 0;
    LoadMenuScreen(6, (u16 *)palette);
    DrawCareerDecision(0);
    FadeToBrightenedPalette((u32)palette, 0x0F);
    choice = 0x40;
    do {
        ReadKeys();
        DrawCareerDecision(cursor);
        if (gKeysPressed & 1)
            choice = cursor;
        if (gKeysPressed & 2)
            choice = 0x0A;
        cursor = MenuMoveVertical(gKeysPressed, cursor, 0, 1);
        WaitForVBlank();
    } while (choice == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return choice;
}


u8 ResolveSeasonResult(u8 championshipIndex, u8 finishPos)
{
    u8 team;
    if (finishPos >= gChampionshipRequiredFinish[championshipIndex] - 1) {
        ShowKickedFromTeamMessage();
        gChampionshipAvailable[championshipIndex] = 0;
        return 1;
    }
    team = 0;
    do {
        if (finishPos < gChampionshipRequiredFinish[team])
            gChampionshipAvailable[team] = 1;
        team++;
    } while (team != 0x11);
    ShowStayOnTeamMessage();
    UnlockChampionshipTier(gChampionshipTeamTiers[championshipIndex]);
    return 0;
}

