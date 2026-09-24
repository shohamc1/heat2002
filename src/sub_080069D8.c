#include "global.h"

void sub_0800C21C(s32 x, s32 y, u8 c);

void sub_080069D8(s32 x1, s32 y1, s32 x2, s32 y2)
{
    s32 x = x1 << 16;
    s32 y = y1 << 16;
    s32 dx;
    s32 dy;
    u8 i;

    x2 <<= 16;
    y2 <<= 16;
    dx = (x2 - x) >> 4;
    dy = (y2 - y) >> 4;

    i = 0;
    do {
        sub_0800C21C(x, y, 2);
        x += dx;
        y += dy;
        i++;
    } while (i != 16);
}
