#include "global.h"

s16 sub_08017230(u32 a, s16 b);

void sub_0800BD98(u16 x, s16 *out, u16 *a3, void *a4)
{
    u8 *r4;
    u32 dx;
    s16 dy;
    s32 v;
    u16 *pa;
    u16 *pb;
    s16 x0;
    s16 y0;

    r4 = (u8 *)a4;
    if (r4[6] < x) {
        do {
            r4 += 0x14;
        } while (((u16 *)r4)[3] < x);
    }
    dx = sub_08017230((x - ((u16 *)r4)[2]) << 16,
                      ((u16 *)r4)[3] - ((u16 *)r4)[2]);
    pa = (u16 *)(a3 + r4[0]);
    pb = (u16 *)(a3 + r4[1]);
    x0 = pa[0];
    y0 = pb[0];
    v = y0 - x0;
    dy = pb[1] - pa[1];
    out[0] = x0 + (v * dx >> 16);
    out[1] = pa[1] + (dy * dx >> 16);
}
