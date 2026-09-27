#include "global.h"
#include "gba/io_reg.h"
#include "variables.h"


s16 MenuMoveHorizontalSilent(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_LEFT)
    {
        gUnk_0202EFB0 = 1;
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_RIGHT)
    {
        gUnk_0202EFB0 = 1;
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}
