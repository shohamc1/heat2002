#include "global.h"
#include "variables.h"

extern u8 gUnk_020390A8;
void sub_0834288C(void);

void *ModuleAllocTask(void);
void ModuleAddTask(u32);

void sub_08342908(void)
{
    if (gModule_RaceEndState == 0)
    {
        u32 p = (u32)ModuleAllocTask();
        if (p != 0)
        {
            *(u32 *)(p + 0x1C) = gUnk_020390A8;
            *(u32 *)(p + 0x18) = 100;
            *(u32 *)(p + 0x0C) = (u32)sub_0834288C;
            ModuleAddTask(p);
        }
        gModule_RaceEndState = 1;
    }
}
