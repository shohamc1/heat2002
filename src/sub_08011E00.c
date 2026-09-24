#include "global.h"
#include "gba/io_reg.h"

extern u8 gOptions[];
extern u8 gUnk_0202EFB0;
extern void m4aSongNumStart(u16 a);

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
