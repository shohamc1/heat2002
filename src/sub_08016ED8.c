#include "global.h"

extern u16 gUnk_020004A0;
extern volatile u8 gUnk_02000494;
extern u8 gUnk_02000498;
extern u16 gUnk_02000496;
extern u16 *volatile gUnk_0200049C;

void sub_08016ED8(u16 *a)
{
    u16 *p;
    /* A hard register can't be the ior's output, so regmove ties the IE
     * value chain to it instead of the mask chain (see parked.md). */
    register u32 mask asm("r2");

    gUnk_020004A0 = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000200 |= (mask = 8 << gUnk_02000494);
    *(volatile u16 *)0x04000208 = 1;
    gUnk_02000498 = 0;
    gUnk_02000496 = *a++;
    p = gUnk_0200049C;
    *p = *a;
    p++;
    gUnk_0200049C = p;
    *p = a[1];
    p--;
    gUnk_0200049C = p;
}
