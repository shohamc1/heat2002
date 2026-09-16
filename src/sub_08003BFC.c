#include "global.h"
#include "gba/defines.h"

extern volatile u32 gUnk_0200BC30;

void sub_08003BFC(u32 x, u32 y, u8 *map, u32 *dest, u8 *charBase)
{
    u8 *src;
    u32 *d2;
    u32 *s;
    u32 t;
    u32 row;
    u32 j;

    src = map + y * gUnk_0200BC30 * 2 + x * 2;
    row = 0;
    do {
        d2 = dest + 0x24;
        j = 0;
        do {
            t = *(u16 *)src;
            src += 2;
            s = (u32 *)(charBase + t * TILE_SIZE_4BPP);
            dest[0] = *s++;
            dest[1] = *s++;
            dest[0x12] = *s++;
            dest[0x13] = *s++;
            d2[0] = *s++;
            d2[1] = *s++;
            d2[0x12] = *s++;
            d2[0x13] = *s;
            d2 += 2;
            dest += 2;
            j++;
        } while (j != 9);
        dest += 0x36;
        src += gUnk_0200BC30 * 2 - 0x12;
        row += 4;
    } while (row != 24);
}
