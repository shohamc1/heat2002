#include "global.h"
#define GBA_CPUSET sub_08344B64
#include "gba/compat.h"

void sub_0833AE90(void)
{
    u32 *r2 = (u32 *)SOUND_INFO_PTR;
    u32 r1 = *r2;
    if (r1 - 0x68736D53 <= 1)
    {
        *r2 = r1 + 10;
        if (REG_DMA1CNT & (DMA_REPEAT << 16))
            REG_DMA1CNT = 0x84400004;
        if (REG_DMA2CNT & (DMA_REPEAT << 16))
            REG_DMA2CNT = 0x84400004;
        REG_DMA1CNT_H = DMA_32BIT;
        REG_DMA2CNT_H = DMA_32BIT;
        CpuFill32(0, (u32)r2 + 0x350, 0xC60);
    }
}
