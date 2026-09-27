#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
#include "data.h"


void DrawTime(u32 a, u16 b, u16 c, u16 d);
void sub_08009FA0(u8 a, u32 b, u8 c);

void sub_0800545C(void)
{
    struct Car *p;
    struct Car *e;
    u32 base;
    u8 r7v;
    u8 r8v;
    u8 i;
    u8 n;

    if (gNumFinishedCars == 0)
        return;
    p = gCars;
    if (gIsLinkRace != 0)
        p = &gCars[gLinkPlayerId[0]];
    if (p->finished == 0)
        return;
    r7v = 5;
    if (gIsLinkRace != 0)
        r7v = 2;
    r8v = 1;
    for (i = 0; i != gNumFinishedCars; i++)
    {
        u32 *tbl = gTextLayerMapPtr;

        n = gFinishedCarOrder[i];
        e = &gCars[n];
        if (gIsLinkRace != 0)
            base = (0x14 + tbl[0]) + r7v * 128;
        else
            base = (0x14 + tbl[0]) + r7v * 64;
        DrawSmallDigit((u16 *)base, r8v);
        DrawTime(base, e->finishMin, e->finishSec, e->finishMs);
        if (gIsLinkRace != 0)
            sub_08009FA0(0x40, r7v * 16, gFinishedCarOrder[i]);
        r7v++;
        r8v++;
    }
}
