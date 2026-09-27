#include "global.h"
#include "gba/io_reg.h"
#include "m4a.h"

extern u8 gUnk_0202EFB0;
extern u8 gLinkPlayerId;
extern u8 gOptions[];

s16 sub_080116D4(u16 keys, s16 v, s16 lo, s16 hi, u8 f, u8 e)
{
    if (keys & DPAD_LEFT)
    {
        gUnk_0202EFB0 = 1;
        if (gLinkPlayerId == e && gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v - 1;
        if (v < lo)
            v = hi;
    }
    if (keys & DPAD_RIGHT)
    {
        gUnk_0202EFB0 = 1;
        if (gLinkPlayerId == e && gOptions[3] != 0)
            m4aSongNumStart(8);
        v = v + 1;
        if (v > hi)
            v = lo;
    }
    return v;
}
