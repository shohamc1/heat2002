#include "global.h"
#include "variables.h"

struct WallRec;
struct Pt;
extern u32 gUnk_0203DE68;
extern u8 gUnk_0202AED4[];

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
    u32 four;
    u32 eight;
    u8 *wallTableCopy;
    u32 twelve;
    u8 *wallTable;
    u32 sixteen;
    u8 **wallTablePtr;
    wallTablePtr = &wallTable;
    if (1) {
        four = 4;
        eight = 8;
        twelve = 0xC;
        sixteen = 0x10;
        gUnk_0203DE60 = (struct WallRec *)*((u32 *)((idx * 20) + ((wallTable = gUnk_0202AED4) + four)));
        wallTableCopy = wallTable;
        gUnk_0203DE64 = (struct Pt *)*((u32 *)((*wallTablePtr) + ((idx * 2) * 10)));
        gUnk_0203DE68 = *((u32 *)((idx * 20) + (wallTable + eight)));
    }
    gUnk_0203DE8C = (u16 *)*((u32 *)((idx * 20) + ((*wallTablePtr) + twelve)));
    gUnk_0203DE88 = (u16 *)*((u32 *)((idx * 20) + (wallTableCopy + sixteen)));
}
