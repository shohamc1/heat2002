#include "global.h"
#include "functions.h"
#include "variables.h"

void ModuleDrawTextCenteredHighlight(u8 *str, u32 y, u32 z);

void ModuleRaceStartSplashTask(struct Task *task)
{
    if (++task->timer == 0x30) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
    ModuleDrawTextCenteredHighlight(gUnk_0200D118, 8, 1);
}

void ModuleLinkRaceStartSplashTask(struct Task *task)
{
    if (++task->timer == 0x4E) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
        gModule_RaceStarted = 1;
    }
}
