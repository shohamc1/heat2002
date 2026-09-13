#include "global.h"

struct UnkStruct0800BBFC {
    u8 a;
    u8 b;
    u16 c;
    u16 d;
    u16 e;
    s32 f;
    s32 g;
    s32 h;
};

s32 sub_0800BBFC(s32 x, s32 y, u16 *p, struct UnkStruct0800BBFC *s)
{
    s32 x1;
    s32 x2;
    s32 y1;
    s32 y2;
    s32 dx;
    s32 dy;
    s32 t;
    s32 m;

    x1 = p[2 * s->a];
    x2 = p[2 * s->b];
    y1 = p[2 * s->a + 1];
    y2 = p[2 * s->b + 1];
    dx = x2 - x1;
    if (dx < 0)
        dx = -dx;
    dy = y2 - y1;
    if (dy < 0)
        dy = -dy;
    if (dx > dy) {
        t = x - x1;
        m = s->g;
    } else {
        t = y - y1;
        m = s->h;
    }
    dx = t * m;
    return s->d + (s32)((dx * (s->e - s->d)) >> 16);
}
