#include "global.h"
#include "variables.h"

void sub_083429B8(void);

void *ModuleAllocTask(void);
void ModuleAddTask(u32);

void sub_08342A94(void)
{
    u32 r4;

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

    r4 = (u32)ModuleAllocTask();
    if (r4 != 0)
    {
        *(u32 *)(r4 + 0x18) = 0;
        *(u32 *)(r4 + 0x0C) = (u32)sub_083429B8;
        ModuleAddTask(r4);
        gUnk_0203DE24 = r4;
    }
}
