#include "global.h"
#include "tilemap.h"
#include "variables.h"


void sub_08344B60(u32 a, u32 b, u32 c);

void sub_0833D040(u32 a, u32 b)
{
    u32 i;
    u32 p = a;
    u32 q = b;

    if (gUnk_02039234[0] != 0)
        p += 4;
    for (i = 0; i != TILEMAP_ROWS; i++) {
        sub_08344B60(p, q, TILEMAP_DST_STRIDE / 4);
        p += TILEMAP_SRC_STRIDE;
        q += TILEMAP_DST_STRIDE;
    }
}
