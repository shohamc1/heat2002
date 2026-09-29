#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "variables.h"

void sub_083397C4(void);
void ModuleVBlankIntr(void);
void ModuleDummyIntr(void);
void ModuleClearVBlankFlag(void);
/* The high module's _call_via_r0 stub (0x08344B7C): _08344B7C(target) jumps
   to target with it in r0, the shape the module's own copy of the libgcc
   stub provides where the low program emits bl _call_via_r0. */
void _08344B7C(u32 arg0);
void ModuleAckVBlank(void);

void ModuleInitIntrHandlers(void)
{
    ModuleClearVBlankFlag();
    gUnk_020375D0 = (u32)ModuleDummyIntr;
    DmaCopy16(3, (u32)sub_083397C4, EWRAM_START + 0x37620, 0x800);
    INTR_VECTOR = (void *)EWRAM_START + 0x37620;
    REG_WAITCNT = WAITCNT_SRAM_4 | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    gModule_IntrTable[1] = (u32)ModuleVBlankIntr;
    gModule_IntrTable[0] = (u32)ModuleDummyIntr;
    gModule_IntrTable[2] = (u32)ModuleDummyIntr;
    gModule_IntrTable[3] = (u32)ModuleDummyIntr;
    gModule_IntrTable[4] = (u32)ModuleDummyIntr;
    gModule_IntrTable[5] = (u32)ModuleDummyIntr;
    gModule_IntrTable[6] = (u32)ModuleDummyIntr;
    gModule_IntrTable[7] = (u32)ModuleDummyIntr;
    gModule_IntrTable[8] = (u32)ModuleDummyIntr;
    gModule_IntrTable[9] = (u32)ModuleDummyIntr;
    gModule_IntrTable[10] = (u32)ModuleDummyIntr;
    gModule_IntrTable[11] = (u32)ModuleDummyIntr;
    gModule_IntrTable[12] = (u32)ModuleDummyIntr;
    gModule_IntrTable[13] = (u32)ModuleDummyIntr;
}

void ModuleSetVBlankCallback(void (*callback)(void))
{
    gUnk_020375D0 = (u32)callback;
    if (callback == NULL)
        gUnk_020375D0 = (u32)ModuleDummyIntr;
}

void ModuleVBlankIntr(void)
{
    if (gUnk_020375D0 != 0)
        _08344B7C(gUnk_020375D0);
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
