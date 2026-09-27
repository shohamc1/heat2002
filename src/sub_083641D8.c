#include "global.h"
#include "variables.h"


void sub_083641D8(u16 x, u16 y)
{
    s16 *g = (s16 *)gUnk_03000800;
    s16 *gg;
    u16 *p;
    u16 *q;
    s32 m1, m2, a1, a2;
    u8 *e;
    u16 i;
    s32 t2;
    s32 tile;
    u16 tile16;

    p = &g[0x25];
    m1 = ~0x1FF;
    *p &= m1;
    ((u8 *)g)[0x48] = y;
    ((u8 *)g)[0x4B] = (((u8 *)g)[0x4B] & 0x3F) | 0x80;
    ((u8 *)g)[0x4D] &= 0x0F;
    q = &g[0x26];
    m2 = ~0x3FF;
    *q = (*q & m2) | 0x10;

    for (i = 0, gg = g, a1 = m1, a2 = m2; i < 8; i++) {
        e = (u8 *)((i + 10) * 8 + (u32)gg);
        t2 = i * 32 + 32;
        tile16 = t2 & 0x1FF;
        tile = tile16;
        *(u16 *)&e[2] = (*(u16 *)&e[2] & a1) | tile;
        e[0] = y;
        e[3] = (e[3] & 0x3F) | 0x80;
        e[5] &= 0x0F;
        if (x < t2)
            *(u16 *)&e[4] = (*(u16 *)&e[4] & a2) | 0x20;
        else
            *(u16 *)&e[4] = (*(u16 *)&e[4] & a2) | 0x10;
    }

    g[0x41] = (g[0x41] & ~0x1FF) | 0xD0;
    ((u8 *)g)[0x80] = y;
    ((u8 *)g)[0x83] = (((u8 *)g)[0x83] & 0x3F) | 0x80;
    ((u8 *)g)[0x85] &= 0x0F;
    g[0x42] = (g[0x42] & ~0x3FF) | 0x20;
}
