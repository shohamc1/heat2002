#include "global.h"

struct E3D160 {
    s32 f00;
    s16 f04;
    s16 f06;
    s16 f08;
    s16 f0A;
};

void sub_0833D160(struct E3D160 *e, u16 *out)
{
    s32 *p;
    s32 a;
    s32 b;
    s32 c;

    p = &e->f00;
    a = *p++ >> 16;
    b = e->f06;
    c = ((s16 *)p)[3];
    a &= 0x1F;
    b &= 0x1F;
    c &= 0x1F;
    *out = a | (b << 5) | (c << 10);
}
