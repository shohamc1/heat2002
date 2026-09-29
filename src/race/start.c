#include "global.h"
#include "functions.h"
#include "variables.h"

void StartRace(void)
{
    struct Task *task;

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
        task->timer = 0;
        task->callback = RaceStartSplashTask;
        AddTask(task);
        gRaceStartTaskPtr = task;
    }
}

void InitLinkRaceStart(void)
{
    struct Task *task;

    gRaceStarted = 0;
    gRaceEndState = 0;
    if (gGameMode[0] == 3 || gGameMode[0] == 4) {
        task = AllocTask();
        if (task != 0) {
            task->timer = 0;
            task->callback = LinkRaceStartSplashTask;
            AddTask(task);
            gRaceStartTaskPtr = task;
        }
    }
}
