#include "global.h"

s16 sub_08011DAC(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & 0x40)
    {
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & 0x80)
    {
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}
