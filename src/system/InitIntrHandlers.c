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
    gVBlankCallback[0] = (u32)DummyIntr;
    DmaCopy16(3, (u32)IntrMain, 0x020005D0, 0x800);
    INTR_VECTOR = (void *)0x020005D0;
    REG_WAITCNT = WAITCNT_SRAM_4 | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    gIntrTable[1] = (u32)VBlankIntr;
    gIntrTable[0] = (u32)DummyIntr;
    gIntrTable[2] = (u32)DummyIntr;
    gIntrTable[3] = (u32)DummyIntr;
    gIntrTable[4] = (u32)DummyIntr;
    gIntrTable[5] = (u32)DummyIntr;
    gIntrTable[6] = (u32)DummyIntr;
    gIntrTable[7] = (u32)DummyIntr;
    gIntrTable[8] = (u32)DummyIntr;
    gIntrTable[9] = (u32)DummyIntr;
    gIntrTable[10] = (u32)DummyIntr;
    gIntrTable[11] = (u32)DummyIntr;
    gIntrTable[12] = (u32)DummyIntr;
    gIntrTable[13] = (u32)DummyIntr;
}
