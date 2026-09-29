#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
#include "gba/io_reg.h"
#include "m4a.h"

void DrawSingleRaceResultsPage(u8 page)
{
    u8 timeText[0x28];
    u16 min, sec, ms;
    struct Car **orderEntry;
    struct Car *car;
    u8 i;

    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x13);
    ((void (*)(void))DrawBigText)();
    orderEntry = gCarOrder + (u8)(page * 15);
    i = 0;
    do {
        DrawText(gText_BlankRow36, 1, i + 4, 1);
        if (orderEntry < gSeasonRaceIndex) {
            car = *orderEntry;
            SplitMilliseconds(car->finishTime, &min, &sec, &ms);
            if (car == gCars && (gMenuBlinkCounter & 0x10) != 0) {
                DrawText(gText_BlankRow36, 1, i + 4, 1);
            } else {
                DrawText(GetDriverName(car->driverId), 1, i + 4, 1);
                timeText[0] = (min / 10) % 10 + 0x30;
                timeText[1] = min % 10 + 0x30;
                timeText[2] = 0x3A;
                timeText[3] = (sec / 10) % 10 + 0x30;
                timeText[4] = sec % 10 + 0x30;
                timeText[5] = 0x3A;
                timeText[6] = (ms / 100) % 10 + 0x30;
                timeText[7] = (ms / 10) % 10 + 0x30;
                timeText[8] = 0;
                DrawText(timeText, 0x14, i + 4, 1);
            }
            orderEntry++;
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

u8 SingleRaceResultsScreen(void)
{
    u8 fadePalette[0x200];
    s8 confirm;
    s8 page;
    s8 selection;
    confirm = 0;
    page = 0;
    SortCarsByTime();
    LoadMenuScreen(1, (u16 *)fadePalette);
    DrawSingleRaceResultsPage(0);
    FadeToBrightenedPalette(fadePalette, 0x0F);
    selection = 0x40;
    do {
        ReadKeys();
        DrawSingleRaceResultsPage(page);
        if (gKeysPressed & A_BUTTON)
            selection = confirm;
        if ((gKeysPressed & DPAD_UP) && page != 0) {
            page = 0;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && page == 0) {
            page = 1;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        WaitForVBlank();
    } while (selection != 0);
    FadeToColor(0, 0x0F);
    return selection;
}
