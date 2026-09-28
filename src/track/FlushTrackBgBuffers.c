#include "global.h"
#include "tilemap.h"
#include "gba/defines.h"

void FlushTilemapBuffer(u32 a, u32 b);

void FlushTrackBgBuffers(void)
{
    FlushTilemapBuffer(TILEMAP_BUFFER(0), BG_SCREEN_ADDR(29));
    FlushTilemapBuffer(TILEMAP_BUFFER(1), BG_SCREEN_ADDR(30));
}
