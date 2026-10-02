#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
#include "gba/io_reg.h"
#include "m4a.h"

extern u8 gText_BlankRow[];

void DrawQualifyResults(u8 page)
{
    u8 buf[0x28];
    u16 minutes, seconds, ms;
    u8 i;
    struct Car **walk;
    struct Car *ptr;
    u8 base;

    base = page * 15;
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(49));
    walk = gCarOrder + base;
    i = 0;
    do {
#if !PORTABLE
        ptr = *walk;
#endif
        DrawText(gText_BlankRow, 0, i + 4, 1);
        if (walk < &gCarOrder[24]) {
#if PORTABLE
            ptr = *walk;
#endif
            SplitMilliseconds(ptr->finishTime, &minutes, &seconds, &ms);
            if (ptr != gCars || (gMenuBlinkCounter & 0x10) == 0) {
                buf[0] = ((i + base + 1) / 10) % 10 + 0x30;
                buf[1] = (i + base + 1) % 10 + 0x30;
                buf[2] = 0x2E;
                buf[3] = 0;
                DrawText(buf, 0, i + 4, 1);
                DrawText(GetDriverName(ptr->driverId), 3, i + 4, 1);
                buf[0] = (minutes / 10) % 10 + 0x30;
                buf[1] = minutes % 10 + 0x30;
                buf[2] = 0x3A;
                buf[3] = (seconds / 10) % 10 + 0x30;
                buf[4] = seconds % 10 + 0x30;
                buf[5] = 0x3A;
                buf[6] = (ms / 100) % 10 + 0x30;
                buf[7] = (ms / 10) % 10 + 0x30;
                buf[8] = 0;
                DrawText(buf, 22, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    if ((gMenuBlinkCounter & 8) != 0) {
        if (page == 0)
            DrawText(gText_PageNextArrow, 26, 19, 1);
        else
            DrawText(gText_PagePrevArrow, 26, 19, 1);
    } else {
        DrawText(gText_PageNoArrowBlank, 26, 19, 1);
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
    BuildScreenPalette(gResultsScreenPalette, (u16 *)buf);
    SortCarsByTime();
    DrawQualifyResults(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 64;
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
    struct Car **walk;
    struct Car *ptr;
    u8 base;
    u8 i;

    base = page * 15;
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(47));
    walk = gCarOrder + base;
    i = 0;
    do {
        DrawText(gText_BlankRow36, 1, i + 4, 1);
        if (walk < &gCarOrder[24]) {
            ptr = *walk;
            SplitMilliseconds(ptr->finishTime, &minutes, &seconds, &ms);
            if (ptr == gCars && (gMenuBlinkCounter & 0x10) != 0) {
                DrawText(gText_BlankRow36, 1, i + 4, 1);
            } else {
                DrawText(GetDriverName(ptr->driverId), 1, i + 4, 1);
                buf[0] = (minutes / 10) % 10 + 0x30;
                buf[1] = minutes % 10 + 0x30;
                buf[2] = 0x3A;
                buf[3] = (seconds / 10) % 10 + 0x30;
                buf[4] = seconds % 10 + 0x30;
                buf[5] = 0x3A;
                buf[6] = (ms / 100) % 10 + 0x30;
                buf[7] = (ms / 10) % 10 + 0x30;
                buf[8] = 0;
                DrawText(buf, 20, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    if ((gMenuBlinkCounter & 8) != 0) {
        if (page == 0)
            DrawText(gText_PageNextArrow, 26, 19, 1);
        else
            DrawText(gText_PagePrevArrow, 26, 19, 1);
    } else {
        DrawText(gText_PageNoArrowBlank, 26, 19, 1);
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
    /* Both calls pass the page unnarrowed; DrawRaceResults narrows it to u8
       itself. */
    ((void (*)(s32))DrawRaceResults)(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 64;
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
