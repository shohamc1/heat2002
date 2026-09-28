#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_0834288C(u32 a)
{
    if (gModule_PaletteFadeActive == 0)
    {
        if (gModule_IsLinkRace == 0)
            /* ModuleDrawText: this file's old local prototype differs from
               functions.h; call through the old signature (solved-walls 31). */
            ((void (*)(u32, u32, u32, u32))ModuleDrawText)(ModuleGetString(MODULE_MSG_RACE_OVER), 0xA, 3, 1);
        if (--*(u32 *)(a + 0x18) == 0)
        {
            ModuleRemoveTask(a);
            ModuleFreeTask(a);
            if (gModule_GameMode[0] != 4)
            {
                ModuleBeginFadeToColor(0xA, 0);
                ModuleWaitForVBlank();
                *(volatile u16 *)0x04000000 &= 0xEFFF;
            }
            gModule_RaceEndState = 2;
        }
    }
}
