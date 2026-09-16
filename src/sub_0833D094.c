#include "global.h"
#include "tilemap.h"
#include "gba/defines.h"

void sub_0833D040(u32 a, u32 b);

void sub_0833D094(void)
{
    sub_0833D040(TILEMAP_BUFFER(0), (u32)BG_SCREEN_ADDR(29));
    sub_0833D040(TILEMAP_BUFFER(1), (u32)BG_SCREEN_ADDR(30));
}
