#include "global.h"

extern u8 gUnk_0202EF00[];
extern u8 gUnk_0202EFB0;
extern void sub_08001208(u16 a);

s16 sub_08011E00(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & 0x20)
    {
        gUnk_0202EFB0 = 1;
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(8);
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & 0x10)
    {
        gUnk_0202EFB0 = 1;
        if (gUnk_0202EF00[3] != 0)
            sub_08001208(8);
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}
