#include "global.h"
#include "variables.h"


void sub_0833D57C(void)
{
    s32 x = gModule_Camera[0];
    s32 y = gModule_Camera[1];
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
    gModule_Camera[6] = dx + 0x78;
    gModule_Camera[7] = sx + 0x50;
}
