#include "global.h"
#include "variables.h"
struct WallRec;
struct Pt;
extern u32 gUnk_0202CC48;
struct tbl_0800CCE0
{
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
};
extern struct tbl_0800CCE0 gUnk_083FD91C[];

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
    gUnk_0202CC40 = (struct WallRec *)gUnk_083FD91C[idx].f4;
    gWallVertices = (struct Pt *)gUnk_083FD91C[idx].f0;
    gUnk_0202CC48 = gUnk_083FD91C[idx].f8;
    gUnk_0202CC6C = (u16 *)gUnk_083FD91C[idx].fC;
    gUnk_0202CC68 = (u16 *)gUnk_083FD91C[idx].f10;
}
