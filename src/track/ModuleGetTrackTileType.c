#include "global.h"
#include "functions.h"
#include "variables.h"

extern u16 *gModule_CellMapPtr;

u8 ModuleGetTrackTileType(s32 x, s32 y)
{
    s32 cellValue;
    s32 subIdx;
    s32 cellX;
    s32 cellY;
    u32 inX;
    u32 inY;

    /* The block (and its empty statement) is load-bearing: without it the
       subtractions schedule differently. */
    do {
        cellX = (x - 1) >> 2;
        cellY = (y - 1) >> 2;
        inX = (x - 1) & 3;
        inY = (y - 1) & 3;
        ;
    } while (0);
    cellValue = (gModule_CellMapPtr + (gModule_TrackMapWidth * cellY))[cellX];
    subIdx = inX + (inY * 4);
    return (gModule_SurfaceTablePtr + (cellValue * 0x10))[subIdx];
}
