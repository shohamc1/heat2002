#include "global.h"
#include "variables.h"

struct WallRec;
struct Pt;
struct TrackWalls
{
    u32 vertices;  /* 0x00: struct Pt[] wall vertices */
    u32 walls;     /* 0x04: struct WallRec[] records */
    u32 wallCount; /* 0x08 */
    u32 cellLists; /* 0x0C: 0xFFFF-terminated wall-index lists */
    u32 cellGrid;  /* 0x10: u16[48*48] grid of list offsets */
};

extern u32 gUnk_0202CC48;
extern struct TrackWalls gTrackWallTables[];

u16 *GetWallListAt(s32 x, s32 y)
{
    s32 tx = x >> 7;
    s32 ty = y >> 7;

    if (tx > 0x30 || ty > 0x30 || tx < 0 || ty < 0)
        return &gUnk_0202CC6C[gUnk_0202CC68[0]];
    return &gUnk_0202CC6C[gUnk_0202CC68[ty * 48 + tx]];
}

void LoadTrackWalls(u32 idx)
{
    gWalls = (struct WallRec *)gTrackWallTables[idx].walls;
    gWallVertices = (struct Pt *)gTrackWallTables[idx].vertices;
    gUnk_0202CC48 = gTrackWallTables[idx].wallCount;
    gUnk_0202CC6C = (u16 *)gTrackWallTables[idx].cellLists;
    gUnk_0202CC68 = (u16 *)gTrackWallTables[idx].cellGrid;
}
