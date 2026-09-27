#include "global.h"
#include "gba/io_reg.h"
#include "m4a.h"
#include "variables.h"


s16 MenuMoveHorizontal(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_LEFT)
    {
        gUnk_0202EFB0 = 1;
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_RIGHT)
    {
        gUnk_0202EFB0 = 1;
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}
