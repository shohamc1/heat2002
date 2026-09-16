#include "global.h"
#include "gba/io_reg.h"

extern u32 gUnk_0202F240;

void sub_08016F80(u32 src, u32 dst, u16 cnt)
{
    u16 saved;
    volatile u16 *disp;
    register volatile u16 *p asm("r1");
    register u16 v asm("r4");
    register u32 temp asm("r2");
    register u16 spinMask asm("r1");
    register u32 test asm("r0");

    saved = REG_IME;
    REG_IME = 0;
    disp = &REG_WAITCNT;
    v = *disp;
    v &= 0xF8FF;
    *disp = ((u16 *)gUnk_0202F240)[3] | v;
    REG_DMA3SAD = src;
    REG_DMA3DAD = dst;
    p = &REG_DMA3CNT_L;
    *(volatile u32 *)p = 0x80000000 | cnt;
    p++;
    temp = 0x8000;
    test = temp;
    __asm__ volatile ("" : "+r" (temp), "+r" (test));
    test &= *p;
    if (test) {
        temp = (u32)&REG_DMA3CNT_H;
        spinMask = 0x8000;
    spin:
        if (*(volatile u16 *)temp & spinMask)
            goto spin;
    }
    REG_IME = saved;
}
