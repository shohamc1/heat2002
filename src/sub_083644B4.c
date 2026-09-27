#include "global.h"
#include "variables.h"


void sub_083647FC(u32 src, u32 dest, u32 control);

void sub_083644B4(u32 a1, u32 a2)
{
    register u32 one asm("r8");
    register u32 *g asm("r4");
    u32 sum;
    u32 cmd;
    u32 *p;
    u32 i;

    sum = 0;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000200 &= 0xFF3F;
    one = 1;
    *(volatile u16 *)0x04000208 = 1;
    cmd = 0;
    g = (u32 *)&gIsland_SioTransfer;
    sub_083647FC((u32)&cmd, (u32)g, 0x05000006);
    *(volatile u32 *)0x04000128 = 0x2003;
    g[1] = a2;
    g[2] = -1;
    if (a1 != 0) {
        *(volatile u32 *)0x0400010C = 0;
        *(u8 *)g = one;
        p = (u32 *)a2;
        i = 0x2000;
        do {
            sum += *p++;
            i--;
        } while (i != 0);
        g[3] = ~sum;
        *(volatile u16 *)0x04000128 = 0x1000;
        *(volatile u16 *)0x04000128 = 0x1001;
    }
}
