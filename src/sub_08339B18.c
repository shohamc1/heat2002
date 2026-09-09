#include "global.h"

extern u16 gUnk_02037E20; /* 0x02037E20 */

void sub_08339AF0(void);

void sub_08339B18(void)
{
    volatile u16 *r2;
    u16 r1;
    u32 r0;
    u32 r3;

    sub_08339AF0();
    r2 = (volatile u16 *)&gUnk_02037E20;
    r3 = 1;
    do {
        __asm__ volatile("swi 2");
        r1 = *r2;
        r0 = r3 & r1;
    } while (r0 == 0);
}
