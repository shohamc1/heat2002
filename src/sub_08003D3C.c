#include "global.h"
#include "tilemap.h"
#include "gba/compat.h"
#include "variables.h"


void sub_08003D3C(u8 *a, u8 *b)
{
    s32 i;

    if (gUnk_02002218 != 0)
        a += 4;
    for (i = 0; i != TILEMAP_ROWS; i++) {
        CpuFastCopy(a, b, TILEMAP_DST_STRIDE);
        a += TILEMAP_SRC_STRIDE;
        b += TILEMAP_DST_STRIDE;
    }
}
