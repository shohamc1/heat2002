#include "global.h"

extern u32 gUnk_0202CC24[];
extern u32 gUnk_0202CC38[];

u32 sub_0800C2CC(s32 a, s32 b, u16 *p, u8 *e)
{
    u16 *q;
    s32 x0;
    s32 y0;
    s32 dx;
    s32 dy;
    s32 v;
    s32 px;
    s32 py;

    x0 = p[2 * e[0]];
    y0 = p[(2 * e[0]) + 1];
    q = (u16 *)(4 * e[1] + (u32)p);
    v = (a - x0) * (*q - x0);
    px = q[1];
    dx = b - y0;
    v = v + dx * (px - y0);
    v *= e[2];
    if (v < 0)
        v = 0;
    if (v > 0xFFFF)
        v = 0xFFFF;
    dx = *q - x0;
    dy = q[1] - y0;
    px = x0 + ((dx * v) >> 16);
    py = y0 + ((dy * v) >> 16);
    gUnk_0202CC24[0] = px;
    gUnk_0202CC38[0] = py;
    px = (a - px) >> 2;
    py = (b - py) >> 2;
    v = px * px + py * py;
    return v;
}
