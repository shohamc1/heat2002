#include "global.h"
#include "functions.h"
#include "tilemap.h"
#include "gba/compat.h"
#include "variables.h"

void FlushTilemapBuffer(u8 *src, u8 *dest)
{
    s32 row;

    if (gMapScrollHalfMetatile != 0)
        src += 4;
    for (row = 0; row != TILEMAP_ROWS; row++) {
        CpuFastCopy(src, dest, TILEMAP_DST_STRIDE);
        src += TILEMAP_SRC_STRIDE;
        dest += TILEMAP_DST_STRIDE;
    }
}
