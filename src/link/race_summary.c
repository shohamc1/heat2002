#include "global.h"
#include "variables.h"
#include "car.h"
#include "functions.h"
#include "data.h"

extern u8 gText_BlankRow28_3[];

void SortLinkCarsByTime(void)
{
    u8 i;
    u32 swapped;
    register u8 *countTemp asm("r2");
    register u8 *count asm("r10");
    register struct Car **base asm("r9");

    i = 0;
    countTemp = &gNumLinkPlayers[0];
    count = countTemp;
    base = gCarOrder;
    {
        register u8 n asm("r1") = *countTemp;
        if (i != n) {
            register struct Car **dst asm("r4") = base;
            register u8 current asm("r0");
            do {
                register struct Car **slot asm("r0") = (struct Car **)(((u32)i << 2) + (u32)dst);
                *slot = (struct Car *)&((u8(*)[0x190])gCars)[i][0];
                i++;
                current = *countTemp;
            } while (i != current);
        }
    }

    do {
        register struct Car **p asm("r6") = base;
        i = 0;
        swapped = 0;
        {
            register u8 *guard asm("r1") = count;
            if (*guard != 1) {
                register u32 half asm("r2") = 0xB6;
                register u32 off asm("ip");
                register u8 *innerCount asm("r8");
                register u8 *loopCount asm("r2");
                asm volatile("" : "+r"(half));
                off = half << 1;
                innerCount = count;
                do {
                    struct Car *a = p[0];
                    struct Car *b = p[1];
                    if (*(u32 *)((u32)a + off) > *(u32 *)((u32)b + off)) {
                        p[0] = b;
                        p[1] = a;
                        swapped = 1;
                    }
                    p++;
                    i++;
                    loopCount = innerCount;
                } while (i != (u32)*loopCount - 1);
            }
        }
    } while (swapped);
}

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
