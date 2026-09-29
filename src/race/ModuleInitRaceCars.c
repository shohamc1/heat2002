#include "global.h"
#include "variables.h"
#include "car.h"

extern u8 gUnk_0203E0F8;

void ModuleLoadTrackCues(void);
void ModuleBuildStartingGrid(u8 a);
void ModuleClearWaypointSpeedSamples(void);
void ModuleInitCar(u8 a, u32 b, u32 c, u32 d, u32 e, u32 f);

void ModuleInitRaceCars(u32 trackIdx)
{
    u32 extra;
    u32 *order;
    u32 *grid;
    u32 i;
    u32 off;

    ModuleLoadTrackCues();
    ModuleBuildStartingGrid(trackIdx);
    gUnk_0203DD10 = 0;
    extra = gUnk_0203E0F8;
    ModuleClearWaypointSpeedSamples();
    if (gModule_GameMode[0] == 0) {
        order = (u32 *)gUnk_02039200;
        grid = gUnk_0203D4A0;
        for (i = 0; i != 5; i++) {
            ModuleInitCar(i, *order, grid[0] << 16, grid[1] << 16, grid[2] << 8,
                          ((((s32)(*order++ - (u32)gModule_Cars)) * (s32)0xC28F5C29) >> 4) + extra);
            grid += 3;
        }
    } else {
        grid = gUnk_0203D4A0;
        i = 0;
        off = 0;
        for (; i != 5; i++) {
            ModuleInitCar(i, off + (u32)gModule_Cars, grid[0] << 16, grid[1] << 16, grid[2] << 8, i + extra);
            grid += 3;
            off += 0x190;
        }
    }
}
