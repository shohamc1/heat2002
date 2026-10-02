#include "global.h"
#include "functions.h"
#include "variables.h"

void ModuleDrawLinkMarker(u32 x, u32 y, u32 carIdx)
{
    const GfxSrc *frames;
    struct ObjTileCacheEntry *sprite;
    u32 attr2;

    frames = gModule_LinkMarkerFrameLists[carIdx];
    frames += sub_08344C50(gModule_FrameCounter >> 1, 7);
    y &= 0xFF;
    y |= (x & 0x1FF) << 16;
    y |= 0x40000000;
    sprite = ModuleRequestObjTiles4(*frames);
    if (sprite == 0)
        return;
    attr2 = sprite->tileIndex;
    attr2 |= (u32)(ModuleRequestObjPalette(gModule_LinkMarkerPalette) << 24) >> 12;
    ModuleAddOamEntry(y, attr2);
}
