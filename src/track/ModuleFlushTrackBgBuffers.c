#include "global.h"
#include "tilemap.h"
#include "gba/defines.h"

void ModuleFlushTilemapBuffer(u8 *src, u8 *dest);

void ModuleFlushTrackBgBuffers(void)
{
    ModuleFlushTilemapBuffer((u8 *)TILEMAP_BUFFER(0), BG_SCREEN_ADDR(29));
    ModuleFlushTilemapBuffer((u8 *)TILEMAP_BUFFER(1), BG_SCREEN_ADDR(30));
}
