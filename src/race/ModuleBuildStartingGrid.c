#include "global.h"
#include "functions.h"
#include "variables.h"

extern struct TrackGrid gModule_TrackStartGrids[]; /* one record (track 7's) */

void ModuleBuildStartingGrid(u8 idx)
{
    u32 *p;
    u32 x;
    u32 y;
    u8 j;

    x = gModule_TrackStartGrids[idx].originX;
    y = gModule_TrackStartGrids[idx].originY;
    p = gUnk_0203D4A0;
    j = 0;
    do {
        p[0] = x;
        p[1] = y;
        p[2] = gModule_TrackStartGrids[idx].direction;
        p += 3;
        p[0] = x + gModule_TrackStartGrids[idx].pairOffsetX;
        p[1] = y + gModule_TrackStartGrids[idx].pairOffsetY;
        p[2] = gModule_TrackStartGrids[idx].direction;
        p += 3;
        x += gModule_TrackStartGrids[idx].rowStepX;
        y += gModule_TrackStartGrids[idx].rowStepY;
        j++;
    } while (j != 12);
}
