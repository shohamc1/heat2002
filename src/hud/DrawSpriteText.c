#include "global.h"
#include "gba/defines.h"
#include "data.h"
#include "functions.h"

extern u16 gSpriteTextControlCharCodes[];


void DrawSpriteText(u8 *a, u32 b, u32 c)
{
    u32 *p;
    u32 pal;
    u32 x;
    u16 *q;
    register u8 *pa asm("r6");
    register u32 v asm("r1");

    pa = a;
    v = *pa++;
    if (v == 0)
        return;
    pal = 0xFF;
    pal = c & 0xFF;
loop:
    if (v != 0x20) {
        q = v + gSpriteTextControlCharCodes;
        p = sub_0800767C((u32)((u8 *)gTextLayerTiles + gTextGlyphTileIndices[*q] * TILE_SIZE_4BPP));
        if (p != 0) {
            x = ((b & 0x1FF) << 0x10) | pal;
            AddOamEntry(x, p[4] | (RequestObjPalette((u32)((u8 *)gFontPalette)) << 12));
        }
    }
    b += 8;
    v = *pa++;
    if (v != 0)
        goto loop;
}
