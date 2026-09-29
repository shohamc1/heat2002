#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

struct ObjTileCacheEntry
{
    u8 pad00[0x10]; /* age, pending, unk05-07, gfx, vramDest */
    u32 tileIndex;  /* OAM attr2 base: tile number, OR'd with palette/priority at each use */
};

void DrawLinkMarker(u32 x, u32 y, u32 carIdx)
{
    u32 *frames = (u32 *)gLinkMarkerFrameLists[carIdx];
    u32 attr;
    u32 *sprite;
    u32 attr2;

    frames += sub_080172C8(gFrameCounter >> 1, 7);
    attr = (y & 0xFF) | ((x & 0x1FF) << 16) | 0x40000000;
    sprite = RequestObjTiles4(*frames);
    if (sprite != 0) {
        attr2 = ((struct ObjTileCacheEntry *)sprite)->tileIndex;
        attr2 |= (u8)RequestObjPalette((u32)gLinkMarkerPalette) << 12;
        AddOamEntry(attr, attr2);
    }
}
