#include "global.h"
#include "functions.h"


void DrawCachedSprite(u32 posX, u32 posY, u32 gfxId, u32 palette, u8 hflip)
{
    u32 *entry;
    u8 palIdx;
    u32 attr;
    u32 attr2;
    u32 oam;

    entry = RequestObjTiles64(gfxId, 1);
    if (entry == 0)
        return;
    palIdx = RequestObjPalette(palette);
    attr = (posY & 0xFF) | ((posX & 0x1FF) << 16) | 0xC0000000;
    attr2 = (palIdx << 12) | 0x800;
    oam = entry[4] | attr2;
    if (hflip != 0)
        attr |= 0x10000000;
    AddOamEntry(attr, oam);
}
