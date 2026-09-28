#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_DemoMode[];
extern u8 gModule_OutOfTime[];
void ModuleDemoEndTask(u32 task);
void *ModuleAllocTask(void);
void ModuleAddTask(u32);
extern u8 gUnk_020390A8;
void ModuleRaceEndTask(u32 task);


void ModuleDemoEndTask(u32 task)
{
    if (*(u32 *)(task + 0x18) & 0x10)
        ModuleDrawText(gModule_DemoMode, 0xB, 0xA);
    else
        ModuleDrawText(gModule_OutOfTime, 0xB, 0xA);
    --*(u32 *)(task + 0x18);
    ModuleReadKeys();
    if ((gUnk_02037618 & 0x3FF) != 0 || *(u32 *)(task + 0x18) == 0)
    {
        ModuleBeginFadeToColor(0xA, 0);
        ModuleWaitForVBlank();
        REG_DISPCNT &= ~DISPCNT_OBJ_ON;
        gModule_RaceEndState = 2;
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
}


void ModuleAddDemoEndTask(void)
{
    u32 task = (u32)ModuleAllocTask();

    if (task != 0) {
        *(u32 *)(task + 0x18) = 0xE1 << 2;
        *(u32 *)(task + 0x0C) = (u32)ModuleDemoEndTask;
        ModuleAddTask(task);
    }
}


void ModuleRaceEndTask(u32 task)
{
    if (gModule_PaletteFadeActive == 0)
    {
        if (gModule_IsLinkRace == 0)
            /* ModuleDrawText: this file's old local prototype differs from
               functions.h; call through the old signature (solved-walls 31). */
            ((void (*)(u32, u32, u32, u32))ModuleDrawText)(ModuleGetString(MODULE_MSG_RACE_OVER), 0xA, 3, 1);
        if (--*(u32 *)(task + 0x18) == 0)
        {
            ModuleRemoveTask(task);
            ModuleFreeTask(task);
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


void ModuleEndRace(void)
{
    if (gModule_RaceEndState == 0)
    {
        u32 task = (u32)ModuleAllocTask();
        if (task != 0)
        {
            *(u32 *)(task + 0x1C) = gUnk_020390A8;
            *(u32 *)(task + 0x18) = 100;
            *(u32 *)(task + 0x0C) = (u32)ModuleRaceEndTask;
            ModuleAddTask(task);
        }
        gModule_RaceEndState = 1;
    }
}

