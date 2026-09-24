#include "global.h"
#include "gba/io_reg.h"

s16 MenuMoveVerticalSilent(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_UP)
    {
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_DOWN)
    {
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}
