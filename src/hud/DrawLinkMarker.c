#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

void DrawLinkMarker(u32 x, u32 y, u32 carIdx)
{
    u32 *frames = (u32 *)gLinkMarkerFrameLists[carIdx];
    u32 attr;
    struct ObjTileCacheEntry *sprite;
    u32 attr2;

    frames += sub_080172C8(gFrameCounter >> 1, 7);
    attr = (y & 0xFF) | ((x & 0x1FF) << 16) | 0x40000000;
    sprite = RequestObjTiles4(*frames);
    if (sprite != 0) {
        attr2 = sprite->tileIndex;
        attr2 |= (u8)RequestObjPalette((u32)gLinkMarkerPalette) << 12;
        AddOamEntry(attr, attr2);
    }
}
