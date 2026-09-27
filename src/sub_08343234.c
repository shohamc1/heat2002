#include "global.h"
#include "variables.h"
#include "car.h"

void sub_083431CC(u32 a, u32 b, u32 c, void *d);

u8 sub_08343234(u8 *a)
{
    struct Out08343234
    {
        s32 f0;
        s32 f4;
    };
    struct Out08343234 out1;
    struct Out08343234 out2;
    u8 i;
    u8 *p;
    u32 count;

    count = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0)
        count = gModule_NumLinkPlayers[0];
    p = (u8 *)gModule_Cars;
    for (i = 0; i != count; i++, p += 0x190)
    {
        if (p == a)
            continue;
        sub_083431CC((u32)a, *(u32 *)(p + 0), *(u32 *)(p + 8), &out1);
        if ((u32)(out1.f4 + 100) > 100)
            continue;
        if (out1.f0 < -16)
            continue;
        if (out1.f0 > 16)
            continue;
        sub_083431CC((u32)p, *(u32 *)(a + 0), *(u32 *)(a + 8), &out2);
        if (out2.f4 < 0)
            continue;
        if (out2.f0 < -16)
            continue;
        if (out2.f0 > 16)
            continue;
        a[0x176] = 15;
        return 1;
    }
    return 0;
}
