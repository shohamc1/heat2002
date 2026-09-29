#include "global.h"
#include "functions.h"
#include "variables.h"

void ModuleStartRace(void)
{
    struct Task *task;

    if (gModule_GameMode[0] == 9)
        gModule_GameMode[0] = 6;
    if (gModule_GameMode[0] == 0xD)
        gModule_GameMode[0] = 0xC;
    if (gModule_GameMode[0] == 0xE)
        gModule_GameMode[0] = 2;
    if (gModule_GameMode[0] == 0xF)
        gModule_GameMode[0] = 0x10;
    if (gModule_GameMode[0] == 0x11)
        gModule_GameMode[0] = 5;

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
    modeDiff = gModule_GameMode[0] - 3;
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
