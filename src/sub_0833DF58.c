#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u32 gUnk_020251B8[];

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

    if (gUnk_0203B864 == 0)
        return;
    p = gModule_Cars;
    if (gUnk_020390EC != 0)
        p = &gModule_Cars[gUnk_0203E1B0];
    if (p->unk7D == 0)
        return;
    r7v = 5;
    if (gUnk_020390EC != 0)
        r7v = 2;
    r8v = 1;
    for (i = 0; i != gUnk_0203B864; i++)
    {
        u32 *tbl = gUnk_020251B8;

        n = gUnk_0203B868[i];
        e = &gModule_Cars[n];
        if (gUnk_020390EC != 0)
            base = (0x14 + tbl[0]) + r7v * 128;
        else
            base = (0x14 + tbl[0]) + r7v * 64;
        sub_0833E3C8((u16 *)base, r8v);
        sub_0833DDB8(base, e->finishMin, e->finishSec, e->finishMs);
        if (gUnk_020390EC != 0)
            sub_08341A30(0x40, r7v * 16, gUnk_0203B868[i]);
        r7v++;
        r8v++;
    }
}
