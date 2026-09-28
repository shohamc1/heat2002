#include "global.h"
#include "tilemap.h"
#include "gba/defines.h"

void ModuleFlushTilemapBuffer(u32 a, u32 b);

void ModuleFlushTrackBgBuffers(void)
{
    ModuleFlushTilemapBuffer(TILEMAP_BUFFER(0), (u32)BG_SCREEN_ADDR(29));
    ModuleFlushTilemapBuffer(TILEMAP_BUFFER(1), (u32)BG_SCREEN_ADDR(30));
}
