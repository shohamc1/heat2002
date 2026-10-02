#include "global.h"
#include "functions.h"
#include "variables.h"

extern u32 gUnk_0202CC48;
extern const struct TrackWalls gTrackWallTables[];

u16 *GetWallListAt(s32 x, s32 y)
{
    s32 tx = x >> 7;
    s32 ty = y >> 7;

    if (tx > 48 || ty > 48 || tx < 0 || ty < 0)
        return &gUnk_0202CC6C[gUnk_0202CC68[0]];
    return &gUnk_0202CC6C[gUnk_0202CC68[ty * 48 + tx]];
}

void LoadTrackWalls(u32 idx)
{
    gWalls = gTrackWallTables[idx].walls;
    gWallVertices = gTrackWallTables[idx].vertices;
    gUnk_0202CC48 = gTrackWallTables[idx].wallCount;
    gUnk_0202CC6C = gTrackWallTables[idx].cellLists;
    gUnk_0202CC68 = gTrackWallTables[idx].cellGrid;
}
