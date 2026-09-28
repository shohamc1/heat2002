#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_083429E8(u32 a)
{
    if (++*(u32 *)(a + 0x18) == 0x4E)
    {
        ModuleRemoveTask(a);
        ModuleFreeTask(a);
        gModule_RaceStarted = 1;
    }
}
