#include "global.h"
extern u16 gUnk_03007FF8;
void sub_0800F818(u16 data)
{
    *(volatile u16 *)0x0400012A = data;
    *(volatile u16 *)0x04000208 = 0;
    gUnk_03007FF8 &= 0xFF7F;
    *(volatile u16 *)0x04000208 = 1;
    if ((*(u8 *)0x04000128 & 0x30) == 0)
        *(volatile u16 *)0x04000128 |= 0x80;
}
