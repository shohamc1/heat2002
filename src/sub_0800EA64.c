#include "global.h"
void sub_0800EA64(u8 *a)
{
    u8 z;
    u8 *p;
    u8 *q;
    z = 0;
    a[0x1E] = z;
    a[0x18] = z;
    a[0x1D] = z;
    p = a + 0x4A;
    p[0] = 0x0F;
    q = a + 0x48;
    q[0] = z;
    *(u16 *)(a + 0x16) = z;
    *(volatile u16 *)0x04000134 = z;
    *(volatile u16 *)0x04000128 = 0x2003;
    *(volatile u16 *)0x0400012A = z;
}
