#include "global.h"

void sub_0800F7E0(void)
{
    volatile u16 *ie;

    *(volatile u16 *)0x04000134 = 0;
    *(volatile u16 *)0x04000128 = 0x6003;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000200 = *(volatile u16 *)0x04000200 | 0x80;
    *(volatile u16 *)0x04000208 = 1;
}
