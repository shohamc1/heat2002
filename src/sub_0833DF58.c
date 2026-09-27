#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"


void sub_0833DDB8(u32 a, u16 b, u16 c, u16 d);
void sub_08341A30(u8 a, u32 b, u8 c);

void sub_0833DF58(void)
{
    struct Car *p;
    struct Car *e;
    u32 base;
    u8 r7v;
    u8 r8v;
    u8 i;
    u8 n;

    if (gModule_NumFinishedCars == 0)
        return;
    p = gModule_Cars;
    if (gModule_IsLinkRace != 0)
        p = &gModule_Cars[gModule_LinkPlayerId];
    if (p->finished == 0)
        return;
    r7v = 5;
    if (gModule_IsLinkRace != 0)
        r7v = 2;
    r8v = 1;
    for (i = 0; i != gModule_NumFinishedCars; i++)
    {
        u32 *tbl = gModule_TextLayerMapPtr;

        n = gModule_FinishedCarOrder[i];
        e = &gModule_Cars[n];
        if (gModule_IsLinkRace != 0)
            base = (0x14 + tbl[0]) + r7v * 128;
        else
            base = (0x14 + tbl[0]) + r7v * 64;
        sub_0833E3C8((u16 *)base, r8v);
        sub_0833DDB8(base, e->finishMin, e->finishSec, e->finishMs);
        if (gModule_IsLinkRace != 0)
            sub_08341A30(0x40, r7v * 16, gModule_FinishedCarOrder[i]);
        r7v++;
        r8v++;
    }
}
