#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_08342A14(struct Task *task)
{
    s32 t;

    if (gModule_PaletteFadeActive == 0)
    {
        t = task->timer;
        if (t > 0x2D)
        {
            if (gModule_GameMode == 9)
                gModule_GameMode = 6;
            if (gModule_GameMode == 0xD)
                gModule_GameMode = 0xC;
            if (gModule_GameMode == 0xE)
                gModule_GameMode = 2;
            if (gModule_GameMode == 0xF)
                gModule_GameMode = 0x10;
            if (gModule_GameMode == 0x11)
                gModule_GameMode = 5;
            gModule_RaceStarted = 1;
        }
        task->timer = t + 1;
        if (t + 1 == 0x7A)
        {
            ModuleRemoveTask(task);
            ModuleFreeTask(task);
        }
        if (gModule_RaceStarted == 0)
            ModuleWaitForVBlank();
    }
}
