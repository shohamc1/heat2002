#include "global.h"
#include "gba/io_reg.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

#include "car.h"

void DrawStandings(u8 page)
{
    u8 buf[0x28];
    u32 *walk;
    u8 *ptr;
    u16 *points;
    u8 base;
    u8 i;
    u8 zero;
    u8 *digits;

    base = page * 15;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x32);
    ((void (*)(void))DrawBigText)();
    walk = (u32 *)((u8 *)gCarOrder + base * 4);
    i = 0;
    digits = buf;
    zero = 0;
    do {
        DrawText(gText_BlankRow36, 1, i + 4, 1);
        if (walk < gSeasonRaceIndex) {
            ptr = (u8 *)*walk;
            if (ptr == (u8 *)gCars && (gMenuBlinkCounter & 0x10) != 0) {
                DrawText(gText_BlankRowMenu, 1, i + 4, 1);
            } else {
                DrawText(GetDriverName(ptr[0x162]), 1, i + 4, 1);
                points = (u16 *)(ptr + 0x164);
                digits[0] = (*points / 1000) % 10 + 0x30;
                digits[1] = (*points / 100) % 10 + 0x30;
                digits[2] = (*points / 10) % 10 + 0x30;
                digits[3] = *points % 10 + 0x30;
                digits[4] = zero;
                DrawText(buf, 0x1A, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    gMenuBlinkCounter++;
    if (gMenuBlinkCounter & 8) {
        if (page == 0)
            DrawText(gText_PageNextArrow, 0x1A, 0x13, 1);
        else
            DrawText(gText_PagePrevArrow, 0x1A, 0x13, 1);
    } else {
        DrawText(gText_PageNoArrowBlank, 0x1A, 0x13, 1);
    }
}

u8 StandingsScreen(void)
{
    void *p;
    u8 buf[0x200];
    u8 mode;
    s8 v;
    s8 sel;
    mode = 0;
    SortCarsByPoints();
    v = 0;
    ZeroTextLayer();
    LoadResultsScreenBackdrop();
    p = gResultsScreenPalette;
    BuildScreenPalette((u32)p, (u16 *)buf);
    DrawStandings(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawStandings(mode);
        if (gKeysPressed & A_BUTTON)
            sel = v;
        if ((gKeysPressed & DPAD_UP) && mode == 1) {
            mode = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && mode == 0) {
            mode = 1;
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
