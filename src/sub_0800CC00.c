#include "global.h"

extern u8 gTrackId; /* 0x020020CC */

u32 sub_0800CB70(u8 *a1, s32 a2, s32 a3);
u32 GetTrackTileType(s32 x, s32 y);

u32 sub_0800CC00(u8 *a1, s32 a2, s32 a3)
{
    register u32 t asm("r1");

    if (gTrackId == 3)
        return 0xC0 << 4;
    a2 -= 0x400000;
    a3 -= 0x380000;
    t = sub_0800CB70(a1, a2, a3);
    asm volatile("" : "+r"(t));
    t = t << 24;
    asm volatile("" : "+r"(t));
    t = t + 0xFF000000;
    asm volatile("" : "+r"(t));
    return ((((0x3000000 & t) >> 24 & 1) | 2) << 10);
}

u32 sub_0800CC4C(s32 x, s32 y)
{
    register u32 t asm("r1");

    if (gTrackId == 3)
        return 0xC0 << 4;
    t = GetTrackTileType(x - 0x400000, y - 0x600000);
    asm volatile("" : "+r"(t));
    t = t << 24;
    asm volatile("" : "+r"(t));
    t = t + 0xFF000000;
    asm volatile("" : "+r"(t));
    return ((((0x3000000 & t) >> 24 & 1) | 2) << 10);
}
