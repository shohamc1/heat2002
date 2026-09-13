#include "global.h"

extern s16 gUnk_0801CD08[];

void sub_0800A2D4(s32 *a)
{
    u32 ang;
    u16 i;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    ang = ((u16 *)a)[0x1A];
    i = (-(ang >> 11) & 0x1F) << 3;
    dx = gUnk_0801CD08[i];
    dy = gUnk_0801CD08[i + 0x40];
    x = a[3];
    y = a[5];
    a[0xB] = (x * dx + y * dy) >> 8;
}
