#include "global.h"
#include "data.h"
#include "variables.h"

extern u16 gUnk_02024F40;
extern u16 gUnk_0202ED68;
extern u16 gUnk_0202E91C;
extern u16 gUnk_0202E950;
extern u16 gUnk_0202E928;

s16 FixedInverse8(s16 r0);
s32 FixedMul8(s16 a, s16 b);

void sub_0800E75C(void)
{
    s16 *g;
    u16 *d2;
    u16 *d3;
    u16 *d4;
    u32 v;
    u32 t;

    gUnk_0202ED68 = FixedMul8(gUnk_0801CD08[gUnk_02024F40 + 0x40], FixedInverse8(gUnk_0202E948));
    d2 = &gUnk_0202E91C;
    *d2 = FixedMul8(gUnk_0801CD08[gUnk_02024F40], FixedInverse8(gUnk_0202E948));
    d3 = &gUnk_0202E950;
    *d3 = FixedMul8((s16)-*(u16 *)&gUnk_0801CD08[gUnk_02024F40], FixedInverse8(gUnk_0202E930));
    d4 = &gUnk_0202E928;
    *d4 = FixedMul8(gUnk_0801CD08[gUnk_02024F40 + 0x40], FixedInverse8(gUnk_0202E930));

    g = gUnk_0202E960;
    g[3] = gUnk_0202ED68;
    g[7] = *d2;
    g[11] = *d3;
    g[15] = gUnk_0202E928;

    g[9] = (g[9] & ~0x1FF) | 0x20;
    ((u8 *)g)[0x10] = 0x54;
    v = 0xC0;
    v |= ((u8 *)g)[0x13];
    ((u8 *)g)[0x15] = (((u8 *)g)[0x15] & 0x0F) | 0x30;
    g[10] = (g[10] & ~0x3FF) | 0x2E2;
    t = ((u8 *)g)[0x11];
    t = (t & ~3) | 1;
    ((u8 *)g)[0x11] = t;
    v &= ~0x0E;
    ((u8 *)g)[0x13] = v;
}
