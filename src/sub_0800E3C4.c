#include "global.h"
#include "gba/compat.h"

extern u32 gUnk_0202CDD0[];

void sub_0800E3C4(u32 a1, u32 a2)
{
    u32 sum = 0;
    register u32 one __asm__("r8");
    u32 fill;
    register u32 *g __asm__("r4");

    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    one = 1;
    REG_IME = 1;
    fill = 0;
    g = gUnk_0202CDD0;
    CpuSet((u32)&fill, (u32)g, CPU_SET_32BIT | CPU_SET_SRC_FIXED | 6);
    *(volatile u32 *)REG_ADDR_SIOCNT = 0x2003;
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
        REG_SIOCNT = SIO_32BIT_MODE;
        REG_SIOCNT = SIO_32BIT_MODE + 1;
    }
}
