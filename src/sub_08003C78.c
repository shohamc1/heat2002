#include "global.h"
#include "gba/defines.h"

extern volatile u32 gUnk_0200BC30;

void sub_08003C78(u32 x, u32 y, u8 *map, u16 *dest, u8 *charBase)
{
    u8 *src;
    u16 *s;
    u16 *d;
    u16 *d2;
    u16 *d3;
    u16 *d4;
    u32 t;
    u32 row;
    u32 j;

    src = map + y * gUnk_0200BC30 + x;
    d = dest;
    row = 0;
    do {
        j = 0;
        d3 = d + 0x48;
        d4 = d + 0x6C;
        d2 = d + 0x24;
        do {
            t = *src++;
            s = (u16 *)(charBase + t * TILE_SIZE_4BPP);
            d[0] = *s++;
            d[1] = *s++;
            d[2] = *s++;
            d[3] = *s++;
            d2[0] = *s++;
            d2[1] = *s++;
            d2[2] = *s++;
            d2[3] = *s++;
            d3[0] = *s++;
            d3[1] = *s++;
            d3[2] = *s++;
            d3[3] = *s++;
            d4[0] = *s++;
            d4[1] = *s++;
            d4[2] = *s++;
            d4[3] = *s;
            d3 += 4;
            d4 += 4;
            d2 += 4;
            d += 4;
            j++;
        } while (j != 9);
        d += 0x6C;
        src += gUnk_0200BC30 - 9;
        row += 4;
    } while (row != 24);
}
