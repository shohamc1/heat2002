#include "global.h"

void sub_0800EA64(void *a1);

s32 sub_0800EE8C(void *a1, u16 a2)
{
    s32 local;

    local = *(volatile u16 *)0x04000128 & 0x8C;
    if (local != 8)
    {
        sub_0800EA64(a1);
        return local ^ 8;
    }
    else
    {
        *(volatile u16 *)0x0400012A = a2;
        *(volatile u16 *)0x04000128 = 0x2083;
        *(u8 *)((u32)a1 + 0x48) = 1;
        return 0;
    }
}
