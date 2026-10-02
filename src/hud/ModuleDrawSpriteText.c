#include "global.h"
#include "variables.h"
#include "functions.h"

extern u16 gModule_SpriteTextControlCharCodes[];
extern u8 gModule_TextLayerTiles[];

void ModuleDrawSpriteText(const u8 *text, u32 startX, u32 pal)
{
    u16 ctrlCode;
    u16 glyphTile;
    u8 ch;
    const u8 *str;
    u32 xPos;
    u32 palBits;
    u32 attr;
    u32 palIdx;
    struct ObjTileCacheEntry *sprite;

    xPos = startX;
    str = text;
    ch = *str;
    str++;
    if (ch != 0) {
        palBits = 0xFF;
        palBits = palBits & pal;
        do {
            if (ch != 0x20) {
                ctrlCode = *(u16 *)((ch << 1) + (u32)gModule_SpriteTextControlCharCodes);
                glyphTile = gModule_TextGlyphTileIndices[ctrlCode];
                sprite = ModuleRequestObjTiles1((GfxSrc)&gModule_TextLayerTiles[glyphTile << 5]);
                if (sprite != 0) {
                    attr = (xPos & 0x1FF) << 16;
                    attr = attr | palBits;
                    palIdx = (u32)(ModuleRequestObjPalette(gModule_FontPalette) << 24) >> 12;
                    ModuleAddOamEntry(attr, sprite->tileIndex | palIdx);
                }
            }
            xPos += 8;
            ch = *str;
            str++;
        } while (ch != 0);
    }
}
