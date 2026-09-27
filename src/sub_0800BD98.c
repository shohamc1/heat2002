#include "global.h"
#include "functions.h"


struct OutBD98 {
    s32 x;
    s32 y;
};

void sub_0800BD98(s32 x, struct OutBD98 *out, u16 *a3, void *a4)
{
    register struct OutBD98 *result asm("r8") = out;
    register u16 *points asm("r6") = a3;
    register u8 *track asm("r4") = a4;
    s32 scale;
    s32 lower;

    if (((u16 *)track)[3] < x) {
        do {
            track += 0x14;
        } while (((u16 *)track)[3] < x);
    }
    lower = ((u16 *)track)[2];
    scale = sub_08017230((x - lower) << 16,
                         ((u16 *)track)[3] - lower);
    {
        register u16 *p1 asm("r2");
        register u16 *p0 asm("r1");
        s32 x0;
        s32 x1;
        s32 y1;
        s32 y0;
        s32 dx;
        s32 dy;
        register s32 outY asm("r0");

        x1 = track[1];
        p1 = (u16 *)(x1 * 4 + (u32)points);
        p0 = (u16 *)(track[0] * 4 + (u32)points);
        x0 = p0[0];
        x1 = p1[0];
        dx = x1 - x0;
        y1 = p1[1];
        y0 = p0[1];
        dy = y1 - y0;
        dx = dx * scale >> 16;
        dy = dy * scale >> 16;
        x0 += dx;
        result->x = x0;
        outY = points[track[0] * 2 + 1] + dy;
        result->y = outY;
    }
}
