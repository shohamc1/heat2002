#include "global.h"

extern u32 gUnk_02039110[];

void sub_0833D57C(void)
{
    s32 x = gUnk_02039110[0];
    s32 y = gUnk_02039110[1];
    s32 dx;
    s32 sx;

    x = x + 0x02580000;
    y = y + 0xFA8A0000;
    dx = (x - y) * 2;
    sx = x + y;
    dx = dx + 0xFF110000;
    sx = sx + 0xFF610000;
    dx = dx >> 17;
    sx = sx >> 17;
    gUnk_02039110[6] = dx + 0x78;
    gUnk_02039110[7] = sx + 0x50;
}
