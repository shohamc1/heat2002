#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "variables.h"

void sub_083397C4(void);
void ModuleVBlankIntr(void);
void ModuleDummyIntr(void);
void ModuleClearVBlankFlag(void);
void ModuleAckVBlank(void);

void ModuleInitIntrHandlers(void)
{
    ModuleClearVBlankFlag();
    gModule_VBlankCallback = ModuleDummyIntr;
    DmaCopy16(3, (u32)sub_083397C4, EWRAM_START + 0x37620, 0x800);
    INTR_VECTOR = (void *)EWRAM_START + 0x37620;
    REG_WAITCNT = WAITCNT_SRAM_4 | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    gModule_IntrTable[1] = ModuleVBlankIntr;
    gModule_IntrTable[0] = ModuleDummyIntr;
    gModule_IntrTable[2] = ModuleDummyIntr;
    gModule_IntrTable[3] = ModuleDummyIntr;
    gModule_IntrTable[4] = ModuleDummyIntr;
    gModule_IntrTable[5] = ModuleDummyIntr;
    gModule_IntrTable[6] = ModuleDummyIntr;
    gModule_IntrTable[7] = ModuleDummyIntr;
    gModule_IntrTable[8] = ModuleDummyIntr;
    gModule_IntrTable[9] = ModuleDummyIntr;
    gModule_IntrTable[10] = ModuleDummyIntr;
    gModule_IntrTable[11] = ModuleDummyIntr;
    gModule_IntrTable[12] = ModuleDummyIntr;
    gModule_IntrTable[13] = ModuleDummyIntr;
}

void ModuleSetVBlankCallback(void (*callback)(void))
{
    gModule_VBlankCallback = callback;
    if (callback == NULL)
        gModule_VBlankCallback = ModuleDummyIntr;
}

void ModuleVBlankIntr(void)
{
    if (gModule_VBlankCallback != NULL)
        gModule_VBlankCallback();
    ModuleAckVBlank();
}

void ModuleDummyIntr(void)
{}

void ModuleClearVBlankFlag(void)
{ *(vu16 *)&gUnk_02037E20 &= ~1; }

void ModuleAckVBlank(void)
{
    *(volatile u16 *)0x04000202 = 1;
    gUnk_02037E20 = 1;
}

void ModuleWaitForVBlank(void)
{
    volatile u16 *flag;
    u16 value;
    u32 hit;
    u32 mask;

    ModuleClearVBlankFlag();
    flag = (volatile u16 *)&gUnk_02037E20;
    mask = 1;
    do {
        __asm__ volatile("swi 0x02");
        value = *flag;
        hit = mask & value;
    } while (hit == 0);
}
