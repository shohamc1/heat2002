#include "global.h"
extern u16 gUnk_0203D510[];
extern u16 gUnk_0203DD40[];
extern u16 gUnk_0203DD20[];
extern u16 gUnk_020270C6[];
extern u16 gUnk_020270D0[];
extern void sub_0834047C(u16 *a, u16 *b);
void sub_083404A8(void)
{
    u16 *dst;
    u16 *src;
    u8 i = 0;
    do {
        gUnk_0203D510[i] = gUnk_020270C6[i];
        gUnk_0203DD40[i] = gUnk_020270D0[i];
        i++;
    } while (i != 5);
    dst = gUnk_0203DD40;
    src = gUnk_0203DD20;
    sub_0834047C(dst, src);
}
