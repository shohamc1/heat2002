#include "global.h"

void sub_08016E10(u32 a, u32 b, u32 c);

void sub_080017D0(void)
{
    u32 sp[1];
    u32 *r2 = *(u32 **)0x03007FF0;
    u32 r1 = *r2;
    if (r1 - 0x68736D53 <= 1)
    {
        *r2 = r1 + 10;
        if (*(volatile u32 *)0x040000C4 & 0x02000000)
            *(volatile u32 *)0x040000C4 = 0x84400004;
        if (*(volatile u32 *)0x040000D0 & 0x02000000)
            *(volatile u32 *)0x040000D0 = 0x84400004;
        *(volatile u16 *)0x040000C6 = 0x400;
        *(volatile u16 *)0x040000D2 = 0x400;
        sp[0] = 0;
        sub_08016E10((u32)sp, (u32)r2 + 0x350, 0x05000318);
    }
}
