#include "global.h"
#include "functions.h"

struct Drv
{
    u8 filler0[0x7D];
    u8 unk7D;
    u8 filler7E[0x104 - 0x7E];
    u16 finishMin;
    u16 finishSec;
    u16 finishMs;
    u8 filler10A[400 - 0x10A];
};

extern struct Drv gCars[];
extern u8 gUnk_020253D4;
extern u8 gUnk_020253E0[];
extern u8 gIsLinkRace;
extern u8 gLinkPlayerId;
extern u32 gUnk_08364B08[];

void DrawTime(u32 a, u16 b, u16 c, u16 d);
void sub_08009FA0(u8 a, u32 b, u8 c);

void sub_0800545C(void)
{
    struct Drv *p;
    struct Drv *e;
    u32 base;
    u8 r7v;
    u8 r8v;
    u8 i;
    u8 n;

    if (gUnk_020253D4 == 0)
        return;
    p = gCars;
    if (gIsLinkRace != 0)
        p = &gCars[gLinkPlayerId];
    if (p->unk7D == 0)
        return;
    r7v = 5;
    if (gIsLinkRace != 0)
        r7v = 2;
    r8v = 1;
    for (i = 0; i != gUnk_020253D4; i++)
    {
        u32 *tbl = gUnk_08364B08;

        n = gUnk_020253E0[i];
        e = &gCars[n];
        if (gIsLinkRace != 0)
            base = (0x14 + tbl[0]) + r7v * 128;
        else
            base = (0x14 + tbl[0]) + r7v * 64;
        DrawSmallDigit((u16 *)base, r8v);
        DrawTime(base, e->finishMin, e->finishSec, e->finishMs);
        if (gIsLinkRace != 0)
            sub_08009FA0(0x40, r7v * 16, gUnk_020253E0[i]);
        r7v++;
        r8v++;
    }
}
