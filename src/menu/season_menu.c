#include "global.h"
#include "functions.h"
#include "data.h"
#include "m4a.h"
#include "variables.h"

extern u8 gText_Practice[];
extern u8 gText_Overwrite[];
extern u8 gText_YouWillLoseThe[];
extern u8 gText_PreviouslySavedCareer[];
extern u8 gText_AreYouSure[];
extern u8 gText_No[];
extern u8 gText_Yes[];

void DrawCareerSessionMenu(u8 cursor, u8 unused0, u8 unused1)
{
    u8 sel = cursor;
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(0));
    text = gText_Practice;
    DrawTextCenteredHighlight(text, 6, cursor == 0);
    text = GetString(2);
    DrawTextCenteredHighlight(text, 8, cursor == 1);
    text = GetString(3);
    DrawTextCenteredHighlight(text, 10, cursor == 2);
    text = GetString(96);
    DrawTextCenteredHighlight(text, 12, cursor == 3);
    text = GetString(8);
    DrawTextCenteredHighlight(text, 14, sel == 4);
}

s8 CareerSessionMenu(u8 qualifyDone, u8 practiceDone)
{
    u8 buf[0x200];
    s8 cursor;
    s8 sel;
    cursor = 0;
    LoadMenuScreen(6, (u16 *)buf);
    DrawCareerSessionMenu(0, qualifyDone, practiceDone | qualifyDone);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 64;
    do {
        ReadKeys();
        DrawCareerSessionMenu(cursor, qualifyDone, practiceDone);
        if ((gKeysPressed & 9) && (practiceDone == 0 || cursor != 0) && (qualifyDone == 0 || cursor != 1))
            sel = cursor;
        if (gKeysPressed & 2)
            sel = 0xFF;
        cursor = MenuMoveVertical(gKeysPressed, cursor, 0, 4);
    again:
        if ((cursor == 0 && (qualifyDone != 0 || practiceDone != 0)) || (cursor == 1 && qualifyDone != 0)) {
            if (gKeysPressed & 0xC0)
                cursor = MenuMoveVertical(gKeysPressed, cursor, 0, 4);
            else
                cursor = MenuMoveVertical(128, cursor, 0, 4);
            goto again;
        }
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

void DrawSeasonSessionMenu(u8 cursor, u8 unused0, u8 unused1)
{
    u8 sel = cursor;
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(0));
    text = GetString(1);
    DrawTextCenteredHighlight(text, 6, cursor == 0);
    text = GetString(2);
    DrawTextCenteredHighlight(text, 8, cursor == 1);
    text = GetString(3);
    DrawTextCenteredHighlight(text, 10, cursor == 2);
    text = GetString(8);
    DrawTextCenteredHighlight(text, 12, sel == 3);
}

s8 SeasonSessionMenu(u8 qualifyDone, u8 practiceDone)
{
    u8 buf[0x200];
    s8 cursor;
    s8 sel;
    cursor = 0;
    LoadMenuScreen(6, (u16 *)buf);
    DrawSeasonSessionMenu(0, qualifyDone, practiceDone);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 64;
    do {
        ReadKeys();
        DrawSeasonSessionMenu(cursor, qualifyDone, practiceDone);
        if ((gKeysPressed & 9) && (practiceDone == 0 || cursor != 0) && (qualifyDone == 0 || cursor != 1))
            sel = cursor;
        if (gKeysPressed & 2)
            sel = 0xFF;
        cursor = MenuMoveVertical(gKeysPressed, cursor, 0, 3);
    again:
        if ((cursor == 0 && (qualifyDone != 0 || practiceDone != 0)) || (cursor == 1 && qualifyDone != 0)) {
            if (gKeysPressed & 0xC0)
                cursor = MenuMoveVertical(gKeysPressed, cursor, 0, 3);
            else
                cursor = MenuMoveVertical(128, cursor, 0, 3);
            goto again;
        }
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

void DrawCareerOverwriteConfirm(u8 cursor)
{
    const u8 *text;

    DummyUiFontLoad(gText_Overwrite);
    DrawTextCenteredHighlight(gText_YouWillLoseThe, 7, 1);
    DrawTextCenteredHighlight(gText_PreviouslySavedCareer, 8, 1);
    DrawTextCenteredHighlight(gText_AreYouSure, 10, 1);
    text = gText_No;
    DrawTextCenteredHighlight(text, 12, cursor == 0);
    text = gText_Yes;
    DrawTextCenteredHighlight(text, 14, cursor == 1);
}

u8 CareerOverwriteConfirm(void)
{
    u8 buf[0x200];
    s8 cursor;
    s8 sel;

    cursor = 0;
    LoadMenuScreen(6, (u16 *)buf);
    DrawCareerOverwriteConfirm(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 64;
    do {
        ReadKeys();
        if (gKeysPressed & 9)
            sel = cursor;
        if (gKeysPressed & 2)
            sel = 0;
        cursor = MenuMoveVertical(gKeysPressed, cursor, 0, 1);
        DrawCareerOverwriteConfirm(cursor);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

void DrawSaveCareerStatus(u8 status)
{
    u8 state;

    state = status;
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(96));
    if (status == 0)
        DrawTextCenteredHighlight(GetString(99), 9, 1);
    if (status == 1)
        DrawTextCenteredHighlight(GetString(97), 9, 1);
    if (state == 2)
        DrawTextCenteredHighlight(GetString(98), 9, 1);
}

s8 SaveCareerScreen(void)
{
    u8 buf[0x200];
    s8 sel;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 done = 0;
    /* The ROM narrows the result to s8 before the test. */
    if ((s8)IsSeasonSaved() != 0) {
        if (CareerOverwriteConfirm() == 0)
            return;
    }
    LoadMenuScreen(6, (u16 *)buf);
    DrawSaveCareerStatus(0);
    FadeToBrightenedPalette(buf, 0x0F);
    SaveSeason();
    DrawSaveCareerStatus(1);
    sel = 64;
    do {
        ReadKeys();
        if (gKeysPressed & 9)
            sel = done;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
