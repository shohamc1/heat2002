#include "global.h"

extern u16 *volatile gUnk_0200049C;
extern volatile u8 gUnk_02000494;
extern u16 gUnk_020004A0;

void sub_08016F3C(void)
{
    u16 *p = gUnk_0200049C;

    *p = 0;
    p++;
    gUnk_0200049C = p;
    *p = 0;
    p--;
    gUnk_0200049C = p;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000200 &= ~(8 << gUnk_02000494);
    *(volatile u16 *)0x04000208 = gUnk_020004A0;
}
