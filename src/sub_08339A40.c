#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "variables.h"


void sub_083397C4(void);
void sub_08339AD0(void);
void sub_08339AEC(void);
void sub_08339AF0(void);

void sub_08339A40(void)
{
    sub_08339AF0();
    gUnk_020375D0 = (u32)sub_08339AEC;
    DmaCopy16(3, (u32)sub_083397C4, EWRAM_START + 0x37620, 0x800);
    INTR_VECTOR = (void *)EWRAM_START + 0x37620;
    REG_WAITCNT = WAITCNT_SRAM_4 | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    gModule_IntrTable[1] = (u32)sub_08339AD0;
    gModule_IntrTable[0] = (u32)sub_08339AEC;
    gModule_IntrTable[2] = (u32)sub_08339AEC;
    gModule_IntrTable[3] = (u32)sub_08339AEC;
    gModule_IntrTable[4] = (u32)sub_08339AEC;
    gModule_IntrTable[5] = (u32)sub_08339AEC;
    gModule_IntrTable[6] = (u32)sub_08339AEC;
    gModule_IntrTable[7] = (u32)sub_08339AEC;
    gModule_IntrTable[8] = (u32)sub_08339AEC;
    gModule_IntrTable[9] = (u32)sub_08339AEC;
    gModule_IntrTable[10] = (u32)sub_08339AEC;
    gModule_IntrTable[11] = (u32)sub_08339AEC;
    gModule_IntrTable[12] = (u32)sub_08339AEC;
    gModule_IntrTable[13] = (u32)sub_08339AEC;
}
