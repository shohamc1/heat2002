#include "global.h"
#include "gba/io_reg.h"

extern void sub_08016E10(u32 src, u32 dest, u32 control);

extern u32 gUnk_0202CDD0[];

void sub_0800E3C4(u32 a1, u32 a2)
{
    u32 sum = 0;
    register u32 one __asm__("r8");
    u32 fill;
    register u32 *g __asm__("r4");

    REG_IME = 0;
    REG_IE &= 0xFF3F;
    one = 1;
    REG_IME = 1;
    fill = 0;
    g = gUnk_0202CDD0;
    sub_08016E10((u32)&fill, (u32)g, 0x05000006);
    *(volatile u32 *)0x04000128 = 0x2003;
    g[1] = a2;
    g[2] = -1;
    if (a1 != 0)
    {
        REG_TM3CNT = 0;
        *(u8 *)g = one;
        {
            u32 *p = (u32 *)a2;
            u32 count = 0x80 << 6;
            do {
                sum += *p++;
                count = count - 1;
            } while (count > 0);
        }
        g[3] = ~sum;
        REG_SIOCNT = 0x80 << 5;
        REG_SIOCNT = (0x80 << 5) + 1;
    }
}
