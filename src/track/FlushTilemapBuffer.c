#include "global.h"
#include "tilemap.h"
#include "gba/compat.h"
#include "variables.h"


void FlushTilemapBuffer(u8 *src, u8 *dest)
{
    s32 row;

    if (gUnk_02002218 != 0)
        src += 4;
    for (row = 0; row != TILEMAP_ROWS; row++) {
        CpuFastCopy(src, dest, TILEMAP_DST_STRIDE);
        src += TILEMAP_SRC_STRIDE;
        dest += TILEMAP_DST_STRIDE;
    }
}
