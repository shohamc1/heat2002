#include "global.h"
#include "functions.h"
#include "variables.h"

void StartRace(void)
{
    struct Task *task;

    if (gGameMode == 9)
        gGameMode = 6;
    if (gGameMode == 13)
        gGameMode = 12;
    if (gGameMode == 14)
        gGameMode = 2;
    if (gGameMode == 15)
        gGameMode = 16;
    if (gGameMode == 17)
        gGameMode = 5;
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
    if (gGameMode == 3 || gGameMode == 4) {
        task = AllocTask();
        if (task != 0) {
            task->timer = 0;
            task->callback = LinkRaceStartSplashTask;
            AddTask(task);
            gRaceStartTaskPtr = task;
        }
    }
}
