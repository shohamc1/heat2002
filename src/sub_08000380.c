#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"

extern u32 gUnk_02000580;
extern u32 gUnk_03007FFC;
extern u32 gUnk_02000590[];

void ClearVBlankFlag(void);

void InitIntrHandlers(void)
{
    ClearVBlankFlag();
    gUnk_02000580 = 0x0800042D;
    DmaCopy16(3, 0x08000104, 0x020005D0, 0x800);
    INTR_VECTOR = (void *)0x020005D0;
    REG_WAITCNT = WAITCNT_SRAM_4 | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    gUnk_02000590[1] = 0x08000411;
    gUnk_02000590[0] = 0x0800042D;
    gUnk_02000590[2] = 0x0800042D;
    gUnk_02000590[3] = 0x0800042D;
    gUnk_02000590[4] = 0x0800042D;
    gUnk_02000590[5] = 0x0800042D;
    gUnk_02000590[6] = 0x0800042D;
    gUnk_02000590[7] = 0x0800042D;
    gUnk_02000590[8] = 0x0800042D;
    gUnk_02000590[9] = 0x0800042D;
    gUnk_02000590[10] = 0x0800042D;
    gUnk_02000590[11] = 0x0800042D;
    gUnk_02000590[12] = 0x0800042D;
    gUnk_02000590[13] = 0x0800042D;
}
