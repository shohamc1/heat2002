#include "global.h"
#include "functions.h"
#include "variables.h"

// Surface code for world position (x, y), at quarter-cell resolution.
//
// gCellMapPtr points at the track's u16 cell map (RLE-decoded into
// EWRAM at track load); gTrackMapWidth is its width in cells. One cell
// covers a 4x4 area and holds an index into the per-track surface table at
// gSurfaceTablePtr (gTrackData[idx].surfaceTable): 16 bytes per cell value, one
// byte per 4x4 sub-position. Callers read the result as a surface code:
// bit 0 = draw behind the background, 2/3 = apron.
// The r3/r2 pins, the inX = inY copy, and the operand order of the last
// three statements are load-bearing: they make old_agbcc emit the ROM bytes.
u8 GetTrackTileType(s32 x, s32 y)
{
    s32 cellX; // map cell holding (x, y)
    s32 cellY;
    register s32 inX PIN(r3); // position inside the cell, 0-3
    register s32 inY PIN(r2);
    s32 row; // cellY's row offset, in map entries
    u8 *mapBase; // the u16 map's base
    u16 *cell;   // the map entry for (cellX, cellY)
    s32 subIdx;  // byte within the cell's 16 surface bytes

    cellX = (x - 1) >> 2;
    cellY = (y - 1) >> 2;
    inY = 3;
    inX = inY; // compiles to the ROM's `add r3, r2, #0`
    inX &= x - 1;
    inY &= y - 1;
    asm volatile("" : "+r"(inY)); // keeps the AND up here, not sunk past the map math
    row = gTrackMapWidth * cellY;
    mapBase = gCellMapPtr;
    cell = (u16 *)(cellX * 2 + (row * 2 + ADDR_WORD(mapBase)));
    subIdx = inX + inY * 4;

    return *(u8 *)(*cell * 16 + ADDR_WORD(gSurfaceTablePtr) + subIdx);
}
