#include "global.h"
#include "gba/io_reg.h"

void sub_08016E10(u32 a, u32 b, u32 c);

void sub_080017D0(void)
{
    u32 sp[1];
    u32 *r2 = *(u32 **)0x03007FF0;
    u32 r1 = *r2;
    if (r1 - 0x68736D53 <= 1)
    {
        *r2 = r1 + 10;
        if (REG_DMA1CNT & 0x02000000)
            REG_DMA1CNT = 0x84400004;
        if (REG_DMA2CNT & 0x02000000)
            REG_DMA2CNT = 0x84400004;
        REG_DMA1CNT_H = 0x400;
        REG_DMA2CNT_H = 0x400;
        sp[0] = 0;
        sub_08016E10((u32)sp, (u32)r2 + 0x350, 0x05000318);
    }
}
