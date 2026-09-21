#include "global.h"

extern u16 gUnk_082B751C[]; /* 0x082B751C */
extern u16 gUnk_082B7648[][4]; /* 0x082B7648 */

void sub_08010714(void)
{
    u16 *dst;
    u16 *src;
    u32 i;
    u32 j;
    u32 idx;
    u16 *t;

    dst = (u16 *)0x06008000;
    src = gUnk_082B751C;
    for (i = 0; i != 10; i++)
    {
        j = 0;
        do {
            idx = *src++;
            t = gUnk_082B7648[idx];
            dst[0] = *t++;
            dst[1] = *t++;
            dst[0x20] = *t++;
            dst[0x21] = *t++;
            dst += 2;
            j++;
        } while (j != 15);
        dst += 0x22;
    }
}
