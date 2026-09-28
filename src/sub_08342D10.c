#include "global.h"
#include "variables.h"

void sub_08342C3C(void);

void *ModuleAllocTask(void);
void ModuleAddTask(u32 a);

void sub_08342D10(void)
{
    u32 *r;

    r = (u32 *)ModuleAllocTask();
    if (r != 0) {
        r[6] = 0x40;
        r[3] = (u32)sub_08342C3C;
        ModuleAddTask((u32)r);
        gUnk_0203DE28[0] = gModule_LapMin[0];
        gUnk_0203DE3C[0] = gModule_LapSec[0];
        gUnk_0203DE20[0] = gModule_LapMs[0];
    }
}
