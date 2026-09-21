#include "global.h"

extern u8 gUnk_0203916C;
extern u16 gUnk_0203B830[];
extern u16 gUnk_0203B6B0[];
extern u16 gUnk_0203B810[];
extern u8 gUnk_020390DC;

void sub_0833E110(u32 a, u32 b, u32 c)
{
    u8 t;

    t = gUnk_0203916C - 3;
    if (t > 1)
    {
        gUnk_0203B830[gUnk_020390DC] = c;
        gUnk_0203B6B0[gUnk_020390DC] = b;
        gUnk_0203B810[gUnk_020390DC] = a;
    }
}
