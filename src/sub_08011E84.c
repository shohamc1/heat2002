#include "global.h"

extern u8 gUnk_0202EFB0;

s16 sub_08011E84(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & 0x20)
    {
        gUnk_0202EFB0 = 1;
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & 0x10)
    {
        gUnk_0202EFB0 = 1;
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}
