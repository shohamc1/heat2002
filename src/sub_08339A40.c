#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"

extern u32 gUnk_020375D0;
extern u32 gUnk_03007FFC;
extern u32 gUnk_020375E0[];

void sub_08339AF0(void);

void sub_08339A40(void)
{
    sub_08339AF0();
    gUnk_020375D0 = EWRAM_START + 0x106D;
    DmaCopy16(3, EWRAM_START + 0xD44, EWRAM_START + 0x37620, 0x800);
    INTR_VECTOR = (void *)EWRAM_START + 0x37620;
    REG_WAITCNT = WAITCNT_SRAM_4 | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    gUnk_020375E0[1] = EWRAM_START + 0x1051;
    gUnk_020375E0[0] = EWRAM_START + 0x106D;
    gUnk_020375E0[2] = EWRAM_START + 0x106D;
    gUnk_020375E0[3] = EWRAM_START + 0x106D;
    gUnk_020375E0[4] = EWRAM_START + 0x106D;
    gUnk_020375E0[5] = EWRAM_START + 0x106D;
    gUnk_020375E0[6] = EWRAM_START + 0x106D;
    gUnk_020375E0[7] = EWRAM_START + 0x106D;
    gUnk_020375E0[8] = EWRAM_START + 0x106D;
    gUnk_020375E0[9] = EWRAM_START + 0x106D;
    gUnk_020375E0[10] = EWRAM_START + 0x106D;
    gUnk_020375E0[11] = EWRAM_START + 0x106D;
    gUnk_020375E0[12] = EWRAM_START + 0x106D;
    gUnk_020375E0[13] = EWRAM_START + 0x106D;
}
