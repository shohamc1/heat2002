#include "global.h"

extern u32 gUnk_0202CC40;
extern u32 gUnk_0202CC44;
extern u32 gUnk_0202CC48;
extern u32 gUnk_0202CC6C;
extern u32 gUnk_0202CC68;

struct tbl_0800CCE0
{
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
};

extern struct tbl_0800CCE0 gUnk_083FD91C[];

void LoadTrackWalls(u32 idx)
{
    gUnk_0202CC40 = gUnk_083FD91C[idx].f4;
    gUnk_0202CC44 = gUnk_083FD91C[idx].f0;
    gUnk_0202CC48 = gUnk_083FD91C[idx].f8;
    gUnk_0202CC6C = gUnk_083FD91C[idx].fC;
    gUnk_0202CC68 = gUnk_083FD91C[idx].f10;
}
