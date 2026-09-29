#include "global.h"
#include "variables.h"

struct Task
{
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 callback;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 timer;
};

void RaceStartSplashTask(void);
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
    task = (u32)AllocTask();
    if (task != 0) {
        ((struct Task *)task)->timer = 0;
        ((struct Task *)task)->callback = (u32)RaceStartSplashTask;
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
        task = (u32)AllocTask();
        if (task != 0) {
            ((struct Task *)task)->timer = 0;
            ((struct Task *)task)->callback = (u32)LinkRaceStartSplashTask;
            AddTask(task);
            gRaceStartTaskPtr = task;
        }
    }
}
