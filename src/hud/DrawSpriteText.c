#include "global.h"
#include "gba/defines.h"
#include "data.h"
#include "functions.h"

extern u16 gSpriteTextControlCharCodes[];

void DrawSpriteText(u8 *a, u32 b, u32 c)
{
    struct ObjTileCacheEntry *p;
    u32 pal;
    u32 x;
    u16 *q;
    register u8 *pa PIN(r6);
    register u32 v PIN(r1);

    pa = a;
    v = *pa++;
    if (v == 0)
        return;
    pal = 0xFF;
    pal = c & 0xFF;
loop:
    if (v != 0x20) {
        q = v + gSpriteTextControlCharCodes;
        p = RequestObjTiles1((GfxSrc)((u8 *)gTextLayerTiles + gTextGlyphTileIndices[*q] * TILE_SIZE_4BPP));
        if (p != 0) {
            x = ((b & 0x1FF) << 0x10) | pal;
            AddOamEntry(x, p->tileIndex | (RequestObjPalette(gFontPalette) << 12));
        }
    }
    b += 8;
    v = *pa++;
    if (v != 0)
        goto loop;
}
