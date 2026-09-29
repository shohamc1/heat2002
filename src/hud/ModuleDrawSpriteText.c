#include "global.h"
#include "variables.h"

extern u16 gUnk_0201F550[];
extern u8 gUnk_0201FB54[];
extern u8 gUnk_0201F390[];

struct ObjTileCacheEntry
{
    /* +0x00 */ u32 age;
    /* +0x04 */ u8 pending;
    /* +0x05 */ u8 unk05[3];
    /* +0x08 */ void *gfx;
    /* +0x0C */ u32 vramDest;
    /* +0x10 */ u32 tileIndex;
};

struct ObjTileCacheEntry *ModuleRequestObjTiles1(void *a);
u32 ModuleRequestObjPalette(u32 a);
void ModuleAddOamEntry(u32 a, u32 b);

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
                ctrlCode = *(u16 *)((ch << 1) + (u32)gUnk_0201F550);
                glyphTile = gModule_TextGlyphTileIndices[ctrlCode];
                sprite = ModuleRequestObjTiles1(&gUnk_0201FB54[glyphTile << 5]);
                if (sprite != 0) {
                    attr = (xPos & 0x1FF) << 16;
                    attr = attr | palBits;
                    palIdx = (ModuleRequestObjPalette((u32)gUnk_0201F390) << 24) >> 12;
                    ModuleAddOamEntry(attr, sprite->tileIndex | palIdx);
                }
            }
            xPos += 8;
            ch = *str;
            str++;
        } while (ch != 0);
    }
}
