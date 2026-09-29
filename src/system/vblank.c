#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "variables.h"

void DummyIntr(void);
void IntrMain(void);
void VBlankIntr(void);
void ClearVBlankFlag(void);
void AckVBlank(void);

void InitIntrHandlers(void)
{
    ClearVBlankFlag();
    gVBlankCallback = DummyIntr;
    DmaCopy16(3, (u32)IntrMain, 0x020005D0, 0x800);
    INTR_VECTOR = (void *)0x020005D0;
    REG_WAITCNT = WAITCNT_SRAM_4 | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    gIntrTable[1] = VBlankIntr;
    gIntrTable[0] = DummyIntr;
    gIntrTable[2] = DummyIntr;
    gIntrTable[3] = DummyIntr;
    gIntrTable[4] = DummyIntr;
    gIntrTable[5] = DummyIntr;
    gIntrTable[6] = DummyIntr;
    gIntrTable[7] = DummyIntr;
    gIntrTable[8] = DummyIntr;
    gIntrTable[9] = DummyIntr;
    gIntrTable[10] = DummyIntr;
    gIntrTable[11] = DummyIntr;
    gIntrTable[12] = DummyIntr;
    gIntrTable[13] = DummyIntr;
}

void SetVBlankCallback(void (*callback)(void))
{
    gVBlankCallback = callback;
    if (callback == NULL)
        gVBlankCallback = DummyIntr;
}

void VBlankIntr(void)
{
    if (gVBlankCallback != NULL)
        gVBlankCallback();
    AckVBlank();
}

void DummyIntr(void)
{}

void ClearVBlankFlag(void)
{ *(vu16 *)&gUnk_02000DD0 &= 0xFFFE; }

void AckVBlank(void)
{
    *(volatile u16 *)0x04000202 = 1;
    gUnk_02000DD0 = 1;
}

void WaitForVBlank(void)
{
    volatile u16 *r2;
    u16 r1;
    u32 r0;
    u32 r3;

    ClearVBlankFlag();
    r2 = (volatile u16 *)&gUnk_02000DD0;
    r3 = 1;
    do {
        __asm__ volatile("swi 0x02");
        r1 = *r2;
        r0 = r3 & r1;
    } while (r0 == 0);
}
