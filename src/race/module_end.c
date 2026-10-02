#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_DemoMode[];
extern u8 gModule_OutOfTime[];
void ModuleDemoEndTask(struct Task *task);
extern u8 gUnk_020390A8;
void ModuleRaceEndTask(struct Task *task);

void ModuleDemoEndTask(struct Task *task)
{
    if (task->timer & 0x10)
        ModuleDrawText(gModule_DemoMode, 11, 10);
    else
        ModuleDrawText(gModule_OutOfTime, 11, 10);
    --task->timer;
    ModuleReadKeys();
    if ((gUnk_02037618 & 0x3FF) != 0 || task->timer == 0) {
        ModuleBeginFadeToColor(10, 0);
        ModuleWaitForVBlank();
        REG_DISPCNT &= ~DISPCNT_OBJ_ON;
        gModule_RaceEndState = 2;
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
}

void ModuleAddDemoEndTask(void)
{
    struct Task *task = ModuleAllocTask();

    if (task != 0) {
        task->timer = 0xE1 << 2;
        task->callback = ModuleDemoEndTask;
        ModuleAddTask(task);
    }
}

void ModuleRaceEndTask(struct Task *task)
{
    if (gModule_PaletteFadeActive == 0) {
        if (gModule_IsLinkRace == 0)
            /* The ROM passes a fourth argument (1, DrawText's highlight
               flag in the main program) that ModuleDrawText ignores. */
            ((void (*)(const u8 *, u32, u32, u32))ModuleDrawText)(ModuleGetString(MODULE_MSG_RACE_OVER), 10, 3, 1);
        if (--task->timer == 0) {
            ModuleRemoveTask(task);
            ModuleFreeTask(task);
            if (gModule_GameMode != 4) {
                ModuleBeginFadeToColor(10, 0);
                ModuleWaitForVBlank();
                REG_DISPCNT &= 0xEFFF;
            }
            gModule_RaceEndState = 2;
        }
    }
}

void ModuleEndRace(void)
{
    if (gModule_RaceEndState == 0) {
        struct Task *task = ModuleAllocTask();
        if (task != 0) {
            task->unk1C = gUnk_020390A8;
            task->timer = 100;
            task->callback = ModuleRaceEndTask;
            ModuleAddTask(task);
        }
        gModule_RaceEndState = 1;
    }
}
