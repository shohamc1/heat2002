#include "global.h"

extern u16 gUnk_02000DD0; /* 0x02000DD0 */

void sub_08000430(void);

void sub_08000458(void)
{
    volatile u16 *r2;
    u16 r1;
    u32 r0;
    u32 r3;

    sub_08000430();
    r2 = (volatile u16 *)&gUnk_02000DD0;
    r3 = 1;
    do {
        __asm__ volatile("swi 0x02");
        r1 = *r2;
        r0 = r3 & r1;
    } while (r0 == 0);
}
