#include "global.h"
#include "variables.h"

extern u32 gUnk_0203DE68;
extern struct TrackWalls gModule_TrackWallTables[];

u16 *ModuleGetWallListAt(s32 xIn, s32 yIn)
{
    s32 tx;
    s32 ty;

    tx = xIn >> 7;
    ty = yIn >> 7;
    if (tx > 0x30 || ty > 0x30 || tx < 0 || ty < 0)
        return gUnk_0203DE8C + *gUnk_0203DE88;
    return gUnk_0203DE8C + gUnk_0203DE88[ty * 0x30 + tx];
}

void ModuleLoadTrackWalls(u32 idx)
{
    gModule_Walls = gModule_TrackWallTables[idx].walls;
    gModule_WallVertices = gModule_TrackWallTables[idx].vertices;
    gUnk_0203DE68 = gModule_TrackWallTables[idx].wallCount;
    gUnk_0203DE8C = gModule_TrackWallTables[idx].cellLists;
    gUnk_0203DE88 = gModule_TrackWallTables[idx].cellGrid;
}
