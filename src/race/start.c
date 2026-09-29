#include "global.h"
#include "variables.h"

void RaceStartSplashTask(void);
u32 AllocTask(void);
void AddTask(u32 a);
void LinkRaceStartSplashTask(void);

void StartRace(void)
{
    u32 task;

    if (gGameMode[0] == 9)
        gGameMode[0] = 6;
    if (gGameMode[0] == 0x0D)
        gGameMode[0] = 0x0C;
    if (gGameMode[0] == 0x0E)
        gGameMode[0] = 2;
    if (gGameMode[0] == 0x0F)
        gGameMode[0] = 0x10;
    if (gGameMode[0] == 0x11)
        gGameMode[0] = 5;
    gRaceStarted = 1;
    task = AllocTask();
    if (task != 0) {
        *(u32 *)(task + 0x18) = 0;
        *(u32 *)(task + 0x0C) = (u32)RaceStartSplashTask;
        AddTask(task);
        gRaceStartTaskPtr = task;
    }
}

void InitLinkRaceStart(void)
{
    u32 task;

    gRaceStarted = 0;
    gRaceEndState = 0;
    if (gGameMode[0] == 3 || gGameMode[0] == 4) {
        task = AllocTask();
        if (task != 0) {
            *(u32 *)(task + 0x18) = 0;
            *(u32 *)(task + 0x0C) = (u32)LinkRaceStartSplashTask;
            AddTask(task);
            gRaceStartTaskPtr = task;
        }
    }
}
