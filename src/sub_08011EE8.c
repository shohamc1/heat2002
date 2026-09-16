#include "global.h"
#include "gba/io_reg.h"

extern u8 gUnk_0202EF00[];
extern u8 gUnk_0202EFB0;
extern void sub_08001208(u16 a);

s16 sub_08011EE8(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_LEFT)
    {
        gUnk_0202EFB0 = 1;
        v = v - 1;
        if (v < lo)
            v = lo;
        else if (gUnk_0202EF00[3] != 0)
            sub_08001208(8);
    }
    if (keys & DPAD_RIGHT)
    {
        gUnk_0202EFB0 = 1;
        v = v + 1;
        if (v > hi)
            v = hi;
        else if (gUnk_0202EF00[3] != 0)
            sub_08001208(8);
    }
    return v;
}
