#include "global.h"
#include "tilemap.h"
#include "gba/defines.h"
#include "functions.h"

void ModuleFlushTrackBgBuffers(void)
{
    ModuleFlushTilemapBuffer((u8 *)TILEMAP_BUFFER(0), BG_SCREEN_ADDR(29));
    ModuleFlushTilemapBuffer((u8 *)TILEMAP_BUFFER(1), BG_SCREEN_ADDR(30));
}
