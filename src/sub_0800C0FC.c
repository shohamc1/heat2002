#include "global.h"

extern s16 gUnk_0801CD08[];

void sub_0800C0FC(s32 *a, s32 b, s32 c, s32 *d)
{
    u16 i;
    s32 dx;
    s32 dy;
    s32 relx;
    s32 rely;

    i = ((-(a[0x96 >> 1] >> 11)) & 0x1F) << 3;
    dx = gUnk_0801CD08[i];
    dy = gUnk_0801CD08[i + 0x40];
    relx = (b - a[0]) >> 16;
    rely = (c - a[2]) >> 16;
    d[0] = (relx * dy - dx * rely) >> 8;
    d[1] = (dx * relx + rely * dy) >> 8;
}
