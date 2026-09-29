#include "global.h"
#include "variables.h"

struct Task
{
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 callback;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 timer;
};

void ModuleRaceStartSplashTask(void);
void ModuleLinkRaceStartSplashTask(void);

void ModuleStartRace(void)
{
    u32 task;

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

    task = (u32)ModuleAllocTask();
    if (task != 0) {
        ((struct Task *)task)->timer = 0;
        ((struct Task *)task)->callback = (u32)ModuleRaceStartSplashTask;
        ModuleAddTask(task);
        gUnk_0203DE24 = task;
    }
}

void ModuleInitLinkRaceStart(void)
{
    u8 modeDiff;
    u32 task;

    gModule_RaceStarted = 0;
    gModule_RaceEndState = 0;
    modeDiff = gModule_GameMode[0] - 3;
    if (modeDiff <= 1) {
        task = (u32)ModuleAllocTask();
        if (task != 0) {
            ((struct Task *)task)->timer = 0;
            ((struct Task *)task)->callback = (u32)ModuleLinkRaceStartSplashTask;
            ModuleAddTask(task);
            gUnk_0203DE24 = task;
        }
    }
}
