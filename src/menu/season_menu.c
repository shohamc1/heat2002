#include "global.h"
#include "functions.h"
#include "data.h"

extern u8 gText_Practice[];
#include "m4a.h"
#include "variables.h"
extern u8 gText_Overwrite[];
extern u8 gText_YouWillLoseThe[];
extern u8 gText_PreviouslySavedCareer[];
extern u8 gText_AreYouSure[];
extern u8 gText_No[];
extern u8 gText_Yes[];

void DrawCareerSessionMenu(u8 cursor)
{
    u8 sel = cursor;
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x00);
    ((void (*)(void))DrawBigText)();
    text = (u32)gText_Practice;
    DrawTextCenteredHighlight(text, 6, cursor == 0);
    text = GetString(0x02);
    DrawTextCenteredHighlight(text, 8, cursor == 1);
    text = GetString(0x03);
    DrawTextCenteredHighlight(text, 0xA, cursor == 2);
    text = GetString(0x60);
    DrawTextCenteredHighlight(text, 0xC, cursor == 3);
    text = GetString(0x08);
    DrawTextCenteredHighlight(text, 0xE, sel == 4);
}

s8 CareerSessionMenu(u8 qualifyDone, u8 practiceDone)
{
    u8 buf[0x200];
    s8 cursor;
    s8 sel;
    cursor = 0;
    LoadMenuScreen(6, (u16 *)buf);
    /* DrawCareerSessionMenu: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8, u8, u8))DrawCareerSessionMenu)(0, qualifyDone, practiceDone | qualifyDone);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8, u8, u8))DrawCareerSessionMenu)(cursor, qualifyDone, practiceDone);
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
                cursor = MenuMoveVertical(0x80, cursor, 0, 4);
            goto again;
        }
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

void DrawSeasonSessionMenu(u8 cursor)
{
    u8 sel = cursor;
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x00);
    ((void (*)(void))DrawBigText)();
    text = GetString(0x01);
    DrawTextCenteredHighlight(text, 6, cursor == 0);
    text = GetString(0x02);
    DrawTextCenteredHighlight(text, 8, cursor == 1);
    text = GetString(0x03);
    DrawTextCenteredHighlight(text, 0xA, cursor == 2);
    text = GetString(0x08);
    DrawTextCenteredHighlight(text, 0xC, sel == 3);
}

s8 SeasonSessionMenu(u8 qualifyDone, u8 practiceDone)
{
    u8 buf[0x200];
    s8 cursor;
    s8 sel;
    cursor = 0;
    LoadMenuScreen(6, (u16 *)buf);
    /* DrawSeasonSessionMenu: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8, u8, u8))DrawSeasonSessionMenu)(0, qualifyDone, practiceDone);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8, u8, u8))DrawSeasonSessionMenu)(cursor, qualifyDone, practiceDone);
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
                cursor = MenuMoveVertical(0x80, cursor, 0, 3);
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
    u32 text;

    DummyUiFontLoad((u32)gText_Overwrite);
    DrawTextCenteredHighlight(gText_YouWillLoseThe, 7, 1);
    DrawTextCenteredHighlight(gText_PreviouslySavedCareer, 8, 1);
    DrawTextCenteredHighlight(gText_AreYouSure, 0xA, 1);
    text = (u32)gText_No;
    DrawTextCenteredHighlight(text, 0xC, cursor == 0);
    text = (u32)gText_Yes;
    DrawTextCenteredHighlight(text, 0xE, cursor == 1);
}

u8 CareerOverwriteConfirm(void)
{
    u8 buf[0x200];
    s8 cursor;
    s8 sel;

    cursor = 0;
    LoadMenuScreen(6, (u16 *)buf);
    DrawCareerOverwriteConfirm(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
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
    GetString(0x60);
    ((void (*)(void))DrawBigText)();
    if (status == 0)
        DrawTextCenteredHighlight(GetString(0x63), 9, 1);
    if (status == 1)
        DrawTextCenteredHighlight(GetString(0x61), 9, 1);
    if (state == 2)
        DrawTextCenteredHighlight(GetString(0x62), 9, 1);
}

s8 SaveCareerScreen(void)
{
    u8 buf[0x200];
    s8 sel;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 done = 0;
    /* IsSeasonSaved: this file's old prototypes return s8; the matched definitions return wider types */
    if (((s8 (*)(void))IsSeasonSaved)() != 0) {
        if (((s8 (*)(void))CareerOverwriteConfirm)() == 0)
            return;
    }
    LoadMenuScreen(6, (u16 *)buf);
    DrawSaveCareerStatus(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    SaveSeason();
    DrawSaveCareerStatus(1);
    sel = 0x40;
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
