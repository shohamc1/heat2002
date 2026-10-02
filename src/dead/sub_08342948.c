#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_0203E000;


void sub_08342948(struct Task *task)
{
    gUnk_0203E000 = 1;
    if (gModule_PaletteFadeActive == 0)
    {
        ModuleDrawSpriteText((u8 *)(ModuleGetString(MODULE_MSG_OUT_OF_TIME)), 0x4C, 0x18);
        if (--task->timer == 0)
        {
            ModuleRemoveTask(task);
            ModuleFreeTask(task);
            ModuleBeginFadeToColor(0xA, 0);
            ModuleWaitForVBlank();
            REG_DISPCNT &= ~DISPCNT_OBJ_ON;
            gModule_RaceEndState = 2;
        }
    }
}

void sub_083429B4(void)
{
}
