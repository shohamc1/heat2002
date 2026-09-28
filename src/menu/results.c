#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u8 gText_BlankRow[];
#include "gba/io_reg.h"
#include "m4a.h"


void DrawQualifyResults(u8 page)
{
    u8 buf[0x28];
    u16 minutes, seconds, ms;
    u8 i;
        u32 *walk;
        u8 *ptr;
        u8 base;

    base = page * 15;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x31);
    ((void (*)(void))DrawBigText)();
    walk = (u32 *)((u8 *)gCarOrder + base * 4);
    i = 0;
    do {
        ptr = (u8 *)*walk;
        DrawText(gText_BlankRow, 0, i + 4, 1);
        if (walk < gSeasonRaceIndex) {
            SplitMilliseconds(*(u32 *)(ptr + 0x16C), &minutes, &seconds, &ms);
            if (ptr != (u8 *)gCars || (gMenuBlinkCounter & 0x10) == 0) {
                buf[0] = ((i + base + 1) / 10) % 10 + 0x30;
                buf[1] = (i + base + 1) % 10 + 0x30;
                buf[2] = 0x2E;
                buf[3] = 0;
                DrawText(buf, 0, i + 4, 1);
                DrawText(GetDriverName(ptr[0x162]), 3, i + 4, 1);
                buf[0] = (minutes / 10) % 10 + 0x30;
                buf[1] = minutes % 10 + 0x30;
                buf[2] = 0x3A;
                buf[3] = (seconds / 10) % 10 + 0x30;
                buf[4] = seconds % 10 + 0x30;
                buf[5] = 0x3A;
                buf[6] = (ms / 100) % 10 + 0x30;
                buf[7] = (ms / 10) % 10 + 0x30;
                buf[8] = 0;
                DrawText(buf, 0x16, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    if ((gMenuBlinkCounter & 8) != 0) {
        if (page == 0)
            DrawText(gText_PageNextArrow, 0x1A, 0x13, 1);
        else
            DrawText(gText_PagePrevArrow, 0x1A, 0x13, 1);
    } else {
        DrawText(gText_PageNoArrowBlank, 0x1A, 0x13, 1);
    }
    gMenuBlinkCounter++;
}


u8 QualifyResultsScreen(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    u8 page;
    page = v = 0;
    ZeroTextLayer();
    LoadResultsScreenBackdrop();
    BuildScreenPalette((u32)gResultsScreenPalette, (u16 *)buf);
    SortCarsByTime();
    DrawQualifyResults(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawQualifyResults(page);
        if (gKeysPressed & A_BUTTON)
            sel = v;
        if ((gKeysPressed & DPAD_UP) && page == 1) {
            page = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && page == 0) {
            page = 1;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        v = MenuMoveVertical(gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}


void DrawRaceResults(u8 page)
{
    u8 buf[0x28];
    u16 minutes, seconds, ms;
    u32 *walk;
    u8 *ptr;
    u8 base;
    u8 i;

    base = page * 15;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x2F);
    ((void (*)(void))DrawBigText)();
    walk = (u32 *)((u8 *)gCarOrder + base * 4);
    i = 0;
    do {
        DrawText(gText_BlankRow36, 1, i + 4, 1);
        if (walk < gSeasonRaceIndex) {
            ptr = (u8 *)*walk;
            SplitMilliseconds(*(u32 *)(ptr + 0x16C), &minutes, &seconds, &ms);
            if (ptr == (u8 *)gCars && (gMenuBlinkCounter & 0x10) != 0) {
                DrawText(gText_BlankRow36, 1, i + 4, 1);
            } else {
                DrawText(GetDriverName(ptr[0x162]), 1, i + 4, 1);
                buf[0] = (minutes / 10) % 10 + 0x30;
                buf[1] = minutes % 10 + 0x30;
                buf[2] = 0x3A;
                buf[3] = (seconds / 10) % 10 + 0x30;
                buf[4] = seconds % 10 + 0x30;
                buf[5] = 0x3A;
                buf[6] = (ms / 100) % 10 + 0x30;
                buf[7] = (ms / 10) % 10 + 0x30;
                buf[8] = 0;
                DrawText(buf, 0x14, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    if ((gMenuBlinkCounter & 8) != 0) {
        if (page == 0)
            DrawText(gText_PageNextArrow, 0x1A, 0x13, 1);
        else
            DrawText(gText_PagePrevArrow, 0x1A, 0x13, 1);
    } else {
        DrawText(gText_PageNoArrowBlank, 0x1A, 0x13, 1);
    }
    gMenuBlinkCounter++;
}


u8 RaceResultsScreen(void)
{
    u8 buf[0x200];
    s8 v;
    s32 page;
    s8 sel;
    /* The copy and narrowed test below preserve initialization/register order. */
    page = 0;
    v = page;
    SortCarsByTime();
    LoadMenuScreen(6, (u16 *)buf);
    /* DrawRaceResults: this file's old prototype differs from the matched definition; call through the old one */
    ((void (*)(s32))DrawRaceResults)(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(s32))DrawRaceResults)(page);
        if (gKeysPressed & A_BUTTON)
            sel = v;
        if ((gKeysPressed & DPAD_UP) && page == 1) {
            page = 0;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && (u8)page == 0) {
            page = 1;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        v = MenuMoveVertical(gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

