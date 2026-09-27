#include "global.h"
#include "gba/io_reg.h"
#include "m4a.h"

extern u8 gOptions[];

s16 MenuMoveVertical(u16 keys, s16 v, s16 lo, s16 hi)
{
    if (keys & DPAD_UP)
    {
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_DOWN)
    {
        if (gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}
