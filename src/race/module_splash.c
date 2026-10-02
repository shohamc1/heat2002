#include "global.h"
#include "functions.h"
#include "variables.h"


void ModuleRaceStartSplashTask(struct Task *task)
{
    if (++task->timer == 48) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
    ModuleDrawTextCenteredHighlight(gUnk_0200D118, 8, 1);
}

void ModuleLinkRaceStartSplashTask(struct Task *task)
{
    if (++task->timer == 78) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
        gModule_RaceStarted = 1;
    }
}
