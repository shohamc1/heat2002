#include "global.h"
#include "data.h"
#include "variables.h"

extern u16 gUnk_0202E938;
extern u16 gUnk_0202CEF0;
extern u16 gUnk_0202E918;
extern u16 gUnk_0202E924;
extern u16 gUnk_0202E900;
extern s16 gUnk_0202E960[];

s16 FixedInverse8(s16 r0);
s32 FixedMul8(s16 a, s16 b);

void sub_0800E8A0(void)
{
    s16 *g;
    u16 *d2;
    u16 *d3;
    u16 *d4;
    u32 v;
    u32 t;

    gUnk_0202CEF0 = FixedMul8(gUnk_0801CD08[gUnk_0202E938 + 0x40], FixedInverse8(gUnk_0202E948));
    d2 = &gUnk_0202E918;
    *d2 = FixedMul8(gUnk_0801CD08[gUnk_0202E938], FixedInverse8(gUnk_0202E948));
    d3 = &gUnk_0202E924;
    *d3 = FixedMul8((s16)-*(u16 *)&gUnk_0801CD08[gUnk_0202E938], FixedInverse8(gUnk_0202E930));
    d4 = &gUnk_0202E900;
    *d4 = FixedMul8(gUnk_0801CD08[gUnk_0202E938 + 0x40], FixedInverse8(gUnk_0202E930));

    g = gUnk_0202E960;
    g[0x13] = gUnk_0202CEF0;
    g[0x17] = *d2;
    g[0x1B] = *d3;
    g[0x1F] = gUnk_0202E900;

    g[0xD] = (g[0xD] & ~0x1FF) | 0x90;
    ((u8 *)g)[0x18] = 0x54;
    v = 0xC0;
    v |= ((u8 *)g)[0x1B];
    ((u8 *)g)[0x1D] = (((u8 *)g)[0x1D] & 0x0F) | 0x30;
    g[0xE] = (g[0xE] & ~0x3FF) | 0x2E2;
    t = ((u8 *)g)[0x19];
    t = (t & ~3) | 1;
    ((u8 *)g)[0x19] = t;
    v &= ~0x0E;
    v |= 2;
    ((u8 *)g)[0x1B] = v;
}
