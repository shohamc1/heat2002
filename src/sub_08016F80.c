#include "global.h"

extern u32 gUnk_0202F240;
extern volatile u32 gUnk_040000D4[];
extern volatile u32 gUnk_040000D8;
extern volatile u16 gUnk_040000DC_16[];
extern volatile u16 gUnk_040000DE;

void sub_08016F80(u32 src, u32 dst, u16 cnt)
{
    u16 saved;
    volatile u16 *disp;
    register volatile u16 *p asm("r1");
    register u16 v asm("r4");
    register u32 temp asm("r2");
    register u16 spinMask asm("r1");
    register u32 test asm("r0");

    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    disp = (volatile u16 *)0x04000204;
    v = *disp;
    v &= 0xF8FF;
    *disp = ((u16 *)gUnk_0202F240)[3] | v;
    gUnk_040000D4[0] = src;
    gUnk_040000D8 = dst;
    p = gUnk_040000DC_16;
    *(volatile u32 *)p = 0x80000000 | cnt;
    p++;
    temp = 0x8000;
    test = temp;
    __asm__ volatile ("" : "+r" (temp), "+r" (test));
    test &= *p;
    if (test) {
        temp = (u32)&gUnk_040000DE;
        spinMask = 0x8000;
    spin:
        if (*(volatile u16 *)temp & spinMask)
            goto spin;
    }
    *(volatile u16 *)0x04000208 = saved;
}
