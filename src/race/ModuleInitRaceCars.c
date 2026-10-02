#include "global.h"
#include "car.h"
#include "variables.h"
#include "functions.h"

extern u8 gUnk_0203E0F8;

void ModuleInitRaceCars(u32 trackIdx)
{
    u32 extra;
    struct Car **order;
    u32 *grid;
    u32 i;

    ModuleLoadTrackCues(trackIdx);
    ModuleBuildStartingGrid(trackIdx);
    gUnk_0203DD10 = 0;
    extra = gUnk_0203E0F8;
    ModuleClearWaypointSpeedSamples();
    if (gModule_GameMode == 0) {
        order = gModule_CarOrder;
        grid = gUnk_0203D4A0;
        for (i = 0; i != 5; i++) {
            /* Unsequenced, as the ROM has it: agbcc reads *order for the
               second argument before the increment. */
            ModuleInitCar(i, *order, grid[0] << 16, grid[1] << 16, grid[2] << 8, *order++ - gModule_Cars + extra);
            grid += 3;
        }
    } else {
        grid = gUnk_0203D4A0;
        for (i = 0; i != 5; i++) {
            ModuleInitCar(i, &gModule_Cars[i], grid[0] << 16, grid[1] << 16, grid[2] << 8, i + extra);
            grid += 3;
        }
    }
}
