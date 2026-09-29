#include "global.h"
#include "functions.h"
#include "variables.h"

struct Task
{
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 timer;
};

void ModuleDrawTextCenteredHighlight(u8 *str, u32 y, u32 z);

void ModuleRaceStartSplashTask(u32 task)
{
    if (++((struct Task *)task)->timer == 0x30) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
    ModuleDrawTextCenteredHighlight(gUnk_0200D118, 8, 1);
}

void ModuleLinkRaceStartSplashTask(u32 task)
{
    if (++((struct Task *)task)->timer == 0x4E) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
        gModule_RaceStarted = 1;
    }
}
