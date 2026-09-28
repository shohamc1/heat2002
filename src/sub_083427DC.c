#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_DemoMode[];
extern u8 gModule_OutOfTime[];


void sub_083427DC(u32 a)
{
    if (*(u32 *)(a + 0x18) & 0x10)
        ModuleDrawText(gModule_DemoMode, 0xB, 0xA);
    else
        ModuleDrawText(gModule_OutOfTime, 0xB, 0xA);
    --*(u32 *)(a + 0x18);
    ModuleReadKeys();
    if ((gUnk_02037618 & 0x3FF) != 0 || *(u32 *)(a + 0x18) == 0)
    {
        ModuleBeginFadeToColor(0xA, 0);
        ModuleWaitForVBlank();
        REG_DISPCNT &= ~DISPCNT_OBJ_ON;
        gModule_RaceEndState = 2;
        ModuleRemoveTask(a);
        ModuleFreeTask(a);
    }
}
