#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"
#include "car.h"

extern u8 gText_BlankRow28_3[];

void DrawLinkRaceSummary(void)
{
    u8 timeText[0x28];
    u16 minutes, seconds, hundredths;
    struct Car **carOrder;
    struct Car *car;
    u8 i;
    u16 nameIdx;

    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x5B);
    ((void (*)(void))DrawBigText)();
    carOrder = gCarOrder;
    for (i = 0; i != gNumLinkPlayers[0]; i++) {
        car = *carOrder;
        SplitMilliseconds(car->finishTime, &minutes, &seconds, &hundredths);
        if (car == &gCars[gLinkPlayerId[0]] && (gMenuBlinkCounter & 0x10)) {
            DrawText(gText_BlankRow28_3, 4, 2 * i + 4, 1);
        } else {
            DrawText(GetString(i + 0xC0), 1, 2 * i + 4, 1);
            nameIdx = 0x53 + (car - gCars);
            DrawText(GetString(nameIdx), 6, 2 * i + 4, 1);
            timeText[0] = (u16)(minutes / 10) % 10 + 0x30;
            timeText[1] = minutes % 10 + 0x30;
            timeText[2] = 0x3A;
            timeText[3] = (u16)(seconds / 10) % 10 + 0x30;
            timeText[4] = seconds % 10 + 0x30;
            timeText[5] = 0x3A;
            timeText[6] = (u16)(hundredths / 100) % 10 + 0x30;
            timeText[7] = (u16)(hundredths / 10) % 10 + 0x30;
            timeText[8] = 0;
            DrawText(timeText, 0x12, 2 * i + 4, 1);
        }
        carOrder++;
    }
    gMenuBlinkCounter++;
}

u8 ShowLinkRaceSummary(void)
{
    u8 palette[0x200];
    s8 result;
    u16 keys;
    u8 zero;

    ResetLinkState();
    gLinkRecvWords[0] = 0;
    gLinkRecvWords[4] = 0;
    gLinkRecvWords[8] = 0;
    gLinkRecvWords[12] = 0;
    zero = 0;
    SortLinkCarsByTime();
    LoadMenuScreen(0, (u16 *)palette);
    DrawLinkRaceSummary();
    FadeToBrightenedPalette(palette, 0x0F);
    result = 0x40;
    do {
        keys = gPlayerKeys[0];
        if (ExchangeLinkInput() != 0) {
            result = 5;
        } else {
            keys = (keys ^ gPlayerKeys[0]) & gPlayerKeys[0];
            DrawLinkRaceSummary();
            if (gLinkPlayerId[0] != 0)
                DrawTextCenteredHighlight(GetString(0x58), 0x0E, 1);
            else
                DrawTextCenteredHighlight(GetString(0x0F), 0x0E, 1);
            if (keys & 9)
                result = zero;
            WaitForVBlank();
        }
    } while (result == 0x40);
    FadeToColor(0, 0x0F);
    return result;
}
