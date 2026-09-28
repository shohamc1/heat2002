#include "global.h"
#include "data.h"
#include "variables.h"

void sub_0800E734(void)
{
}

void sub_0800E738(void)
{
}

void sub_0800E73C(void)
{
}

void sub_0800E740(void)
{
}

void sub_0800E744(void)
{
}

void sub_0800E748(void)
{
}

void sub_0800E74C(void)
{
}

void sub_0800E750(void)
{
}

void sub_0800E754(void)
{
}

void sub_0800E758(void)
{
}

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

    gUnk_0202ED68 = FixedMul8(gSinTable[gUnk_02024F40 + 0x40], FixedInverse8(gUnk_0202E948));
    d2 = &gUnk_0202E91C;
    *d2 = FixedMul8(gSinTable[gUnk_02024F40], FixedInverse8(gUnk_0202E948));
    d3 = &gUnk_0202E950;
    *d3 = FixedMul8((s16)-*(u16 *)&gSinTable[gUnk_02024F40], FixedInverse8(gUnk_0202E930));
    d4 = &gUnk_0202E928;
    *d4 = FixedMul8(gSinTable[gUnk_02024F40 + 0x40], FixedInverse8(gUnk_0202E930));

    g = gOamBuffer;
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

extern u16 gUnk_0202E938;
extern u16 gUnk_0202CEF0;
extern u16 gUnk_0202E918;
extern u16 gUnk_0202E924;
extern u16 gUnk_0202E900;


void sub_0800E8A0(void)
{
    s16 *g;
    u16 *d2;
    u16 *d3;
    u16 *d4;
    u32 v;
    u32 t;

    gUnk_0202CEF0 = FixedMul8(gSinTable[gUnk_0202E938 + 0x40], FixedInverse8(gUnk_0202E948));
    d2 = &gUnk_0202E918;
    *d2 = FixedMul8(gSinTable[gUnk_0202E938], FixedInverse8(gUnk_0202E948));
    d3 = &gUnk_0202E924;
    *d3 = FixedMul8((s16)-*(u16 *)&gSinTable[gUnk_0202E938], FixedInverse8(gUnk_0202E930));
    d4 = &gUnk_0202E900;
    *d4 = FixedMul8(gSinTable[gUnk_0202E938 + 0x40], FixedInverse8(gUnk_0202E930));

    g = gOamBuffer;
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

void sub_0800E9E8(void)
{
}

void sub_0800E9EC(void)
{
}

void sub_0800E9F0(void)
{
}

void sub_0800E9F4(void)
{
}

void sub_0800E9F8(void)
{
}

void sub_0800E9FC(void)
{
}

void sub_0800EA00(void)
{
}

void sub_0800EA04(void)
{
}

void sub_0800EA08(void)
{
}

void sub_0800EA0C(void)
{
}

void sub_0800EA10(void)
{
}

void sub_0800EA14(void)
{
}

void sub_0800EA18(void)
{
}

void sub_0800EA1C(void)
{
}

void sub_0800EA20(void)
{
}

void sub_0800EA24(void)
{
}

void sub_0800EA28(void)
{
}

void sub_0800EA2C(void)
{
}

void sub_0800EA30(void)
{
}

void sub_0800EA34(void)
{
}

void sub_0800EA38(void)
{
}

extern u8 gUnk_0202E94C;

void sub_0800EA3C(void)
{
    gIntrCheck = 2;
    gUnk_0202E94C++;
}

void sub_0800EA54(void)
{
}

void sub_0800EA58(void)
{
}

void sub_0800EA5C(void)
{
}

void sub_0800EA60(void)
{
}
