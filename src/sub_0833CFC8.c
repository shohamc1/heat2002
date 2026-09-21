#include "global.h"

extern u32 gUnk_02039244;

void sub_0833CFC8(u32 a0, u32 a1, u8 *a2, u32 *a3, u32 *table)
{
    u8 *p;
    u32 *d1;
    u32 *d2;
    u32 *src;
    u32 i;
    u32 k;
    u32 idx;

    p = a2 + a1 * gUnk_02039244 + a0;
    d1 = a3;
    for (i = 0; i != 0x18; i += 4)
    {
        d2 = d1 + 36;
        for (k = 0; k != 9; k++)
        {
            idx = *p++;
            src = &table[idx * 8];
            d1[0] = *src++;
            d1[1] = *src++;
            d1[18] = *src++;
            d1[19] = *src++;
            d2[0] = *src++;
            d2[1] = *src++;
            d2[18] = *src++;
            d2[19] = *src;
            d2 += 2;
            d1 += 2;
        }
        d1 += 54;
        p += gUnk_02039244 - 9;
    }
}
