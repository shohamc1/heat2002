#include "global.h"
#include "functions.h"
#include "variables.h"

void ModuleStartRace(void)
{
    struct Task *task;

    if (gModule_GameMode == 9)
        gModule_GameMode = 6;
    if (gModule_GameMode == 13)
        gModule_GameMode = 12;
    if (gModule_GameMode == 14)
        gModule_GameMode = 2;
    if (gModule_GameMode == 15)
        gModule_GameMode = 16;
    if (gModule_GameMode == 17)
        gModule_GameMode = 5;

    gModule_RaceStarted = 1;

    task = ModuleAllocTask();
    if (task != 0) {
        task->timer = 0;
        task->callback = ModuleRaceStartSplashTask;
        ModuleAddTask(task);
        gModule_RaceStartTaskPtr = task;
    }
}

void ModuleInitLinkRaceStart(void)
{
    u8 modeDiff;
    struct Task *task;

    gModule_RaceStarted = 0;
    gModule_RaceEndState = 0;
    modeDiff = gModule_GameMode - 3;
    if (modeDiff <= 1) {
        task = ModuleAllocTask();
        if (task != 0) {
            task->timer = 0;
            task->callback = ModuleLinkRaceStartSplashTask;
            ModuleAddTask(task);
            gModule_RaceStartTaskPtr = task;
        }
    }
}
