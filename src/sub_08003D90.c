#include "global.h"
#include "tilemap.h"
#include "gba/defines.h"

void sub_08003D3C(u32 a, u32 b);

void FlushTrackBgBuffers(void)
{
    sub_08003D3C(TILEMAP_BUFFER(0), BG_SCREEN_ADDR(29));
    sub_08003D3C(TILEMAP_BUFFER(1), BG_SCREEN_ADDR(30));
}
