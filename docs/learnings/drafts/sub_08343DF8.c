#include "global.h"

extern s16 gUnk_0200C3E8[];

void sub_08343DF8(u32 a, u32 b)
{
    u32 idx;
    s32 x;
    s32 y;
    register u32 m asm("r12");

    idx = -(*(u16 *)(a + 0x34) >> 8) & (m = 0xFF);
    *(s32 *)(b + 0x00) = gUnk_0200C3E8[idx];
    *(s32 *)(b + 0x04) = gUnk_0200C3E8[idx + 0x40];
    x = *(s32 *)(a + 0x00);
    *(s32 *)(b + 0x10) = x >> 8;
    y = *(s32 *)(a + 0x08);
    *(s32 *)(b + 0x14) = y >> 8;
    idx = -((*(s16 *)(a + 0x3C) + *(u16 *)(a + 0x34)) >> 8) & m;
    *(s32 *)(b + 0x08) = gUnk_0200C3E8[idx];
    *(s32 *)(b + 0x0C) = gUnk_0200C3E8[idx + 0x40];
    *(s32 *)(b + 0x18) = (x + *(s32 *)(a + 0x0C)) >> 8;
    *(s32 *)(b + 0x1C) = (y + *(s32 *)(a + 0x14)) >> 8;
}
