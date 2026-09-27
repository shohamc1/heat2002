#include "global.h"
#include "variables.h"

extern u32 gUnk_0200BC50[];

u8 GetTrackTileType(s32 x, s32 y)
{
    s32 a;
    register s32 b asm("r5");
    register s32 c asm("r3");
    register s32 d asm("r2");
    s32 m;
    s32 base;
    u16 *t;
    s32 v;

    a = (x - 1) >> 2;
    b = (y - 1) >> 2;
    d = 3;
    c = d;
    c &= x - 1;
    d &= y - 1;
    asm volatile("" : "+r"(d));
    m = gUnk_02002200[0] * b;
    base = gUnk_0200BC50[0];
    t = (u16 *)(a * 2 + (m * 2 + base));
    v = c + d * 4;

    return *(u8 *)(*t * 16 + gUnk_02022DEC[0] + v);
}
