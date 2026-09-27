#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "variables.h"

void DummyIntr(void);
void IntrMain(void);
void VBlankIntr(void);


void ClearVBlankFlag(void);

void InitIntrHandlers(void)
{
    ClearVBlankFlag();
    gUnk_02000580[0] = (u32)DummyIntr;
    DmaCopy16(3, (u32)IntrMain, 0x020005D0, 0x800);
    INTR_VECTOR = (void *)0x020005D0;
    REG_WAITCNT = WAITCNT_SRAM_4 | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    gUnk_02000590[1] = (u32)VBlankIntr;
    gUnk_02000590[0] = (u32)DummyIntr;
    gUnk_02000590[2] = (u32)DummyIntr;
    gUnk_02000590[3] = (u32)DummyIntr;
    gUnk_02000590[4] = (u32)DummyIntr;
    gUnk_02000590[5] = (u32)DummyIntr;
    gUnk_02000590[6] = (u32)DummyIntr;
    gUnk_02000590[7] = (u32)DummyIntr;
    gUnk_02000590[8] = (u32)DummyIntr;
    gUnk_02000590[9] = (u32)DummyIntr;
    gUnk_02000590[10] = (u32)DummyIntr;
    gUnk_02000590[11] = (u32)DummyIntr;
    gUnk_02000590[12] = (u32)DummyIntr;
    gUnk_02000590[13] = (u32)DummyIntr;
}
