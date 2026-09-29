#include "global.h"
#include "tilemap.h"
#include "gba/defines.h"

void FlushTilemapBuffer(u8 *src, u8 *dest);

void FlushTrackBgBuffers(void)
{
    FlushTilemapBuffer((u8 *)TILEMAP_BUFFER(0), BG_SCREEN_ADDR(29));
    FlushTilemapBuffer((u8 *)TILEMAP_BUFFER(1), BG_SCREEN_ADDR(30));
}
