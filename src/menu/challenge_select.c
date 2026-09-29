#include "global.h"
#include "functions.h"
#include "data.h"

#include "m4a.h"
#include "variables.h"
extern u8 gChallengeCategorySelected;
extern const u8 *const gChallengeNameTexts[];
extern u8 gText_ChallengeStatusBeat[];
extern u8 gText_ChallengeStatusNA[];
extern u8 gText_ChallengeStatusOpen[];
extern const u8 *const gChallengeGoalTexts[];

void DrawChallengeCategorySelect(u32 cursor)
{
    u8 i;

    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0xA4);
    ((void (*)(void))DrawBigText)();
    i = 0;
    do {
        DrawTextCenteredHighlight(GetString(i + 0xA5), i * 2 + 6, cursor == i);
        i++;
    } while (i != 4);
}

u8 ChallengeCategorySelect(void)
{
    u8 buf[0x200];
    s8 cursor;
    s8 sel;
    cursor = 0;
    LoadMenuScreen(5, (u16 *)buf);
    DrawChallengeCategorySelect(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawChallengeCategorySelect(cursor);
        if (gKeysPressed & 1) {
            sel = cursor;
            gChallengeCategorySelected = cursor;
        }
    retry:
        /* old prototype u8 MenuMoveVertical(...): the s16 return shuffles the
                r5/r6 allocation for v and sel */
        cursor = ((u8 (*)(u16, s8, u32, u32))MenuMoveVertical)(gKeysPressed, cursor, 0, 3);
        if (gChallengeCategoryUnlocked[cursor] == 0)
            goto retry;
        if (gKeysPressed & 2)
            sel = 0;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

void DrawChallengeSelect(u8 category, u8 challengeIdx)
{
    u8 y;
    u8 i;
    u8 base;
    s8 status;

    DummyUiFontLoad(gUiFontTable[0]);
    GetString(category + 0xAE);
    ((void (*)(void))DrawBigText)();
    base = (u8)(category * 4);
    y = 3;
    i = 0;
    do {
        DrawText(gChallengeNameTexts[base + i], 0, y, i == (challengeIdx & 3));
        if (gChallengeStatus[base + i] == 1) {
            u8 *statusText = gText_ChallengeStatusBeat;
            DrawText(statusText, 0x16, y, i == (challengeIdx & 3));
        }
        if (gChallengeStatus[base + i] == 2) {
            u8 *statusText = gText_ChallengeStatusBeat;
            DrawText(statusText, 0x16, y, i == (challengeIdx & 3));
        }
        status = ((s8 *)gChallengeStatus)[base + i];
        if (status == 3) {
            u8 *statusText = gText_ChallengeStatusBeat;
            DrawText(statusText, 0x16, y, i == (status & challengeIdx));
        }
        if (((s8 *)gChallengeStatus)[base + i] == -1) {
            u8 *statusText = gText_ChallengeStatusNA;
            DrawText(statusText, 0x16, y, i == (challengeIdx & 3));
        }
        if ((s8)gChallengeStatus[base + i] == 0) {
            u8 *statusText = gText_ChallengeStatusOpen;
            DrawText(statusText, 0x16, y, i == (challengeIdx & 3));
        }
        y++;
        i++;
    } while (i != 4);
    y = 8;
    base = (u8)(challengeIdx * 5) * 2;
    i = base;
    while (i != base + 10) {
        DrawText(gChallengeGoalTexts[i], 0, y, 1);
        y++;
        i++;
    }
}

u8 ChallengeSelect(u8 category, u8 challengeIdx)
{
    u8 buf[0x200];
    s8 cursor;
    s32 sel;
    cursor = challengeIdx;
    LoadMenuScreen(5, (u16 *)buf);
    DrawChallengeSelect(category, cursor);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawChallengeSelect(category, cursor);
    retry:
        cursor = MenuMoveVertical(gKeysPressed, cursor, (challengeIdx >> 2) * 4, (challengeIdx >> 2) * 4 + 3);
        if ((s8)gChallengeStatus[cursor] == -1)
            goto retry;
        if (gKeysPressed & 3)
            sel = 1;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return cursor;
}
