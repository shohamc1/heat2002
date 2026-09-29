#include "global.h"
#include "variables.h"

struct BigDigitGlyphRow
{
    u16 topLeft;
    u16 topRight;
};
/* One big digit's 2x2 glyph block: the bottom row sits one font-grid row
   (0x88 bytes) below the top row. */
struct BigDigitGlyph
{
    u16 topLeft;
    u16 topRight;
    u8 pad04[0x88 - 0x04];
    u16 bottomLeft;
    u16 bottomRight;
};
extern struct BigDigitGlyphRow gModule_BigDigitGlyphs[];
extern u16 gUnk_020215D2[];

void ModuleDrawBigDigit(u16 *dest, u8 idx)
{
    struct BigDigitGlyph *e = (struct BigDigitGlyph *)&gModule_BigDigitGlyphs[idx];

    dest[0] = gModule_FontTileEntries[e->topLeft] | 0xE000;
    dest[1] = gModule_FontTileEntries[e->topRight] | 0xE000;
    dest[0x20] = gModule_FontTileEntries[e->bottomLeft] | 0xE000;
    dest[0x21] = 0xE000 | gModule_FontTileEntries[e->bottomRight];
}

void ModuleDrawSmallDigit(u16 *dest, s32 idx)
{
    u32 glyphAddr;
    u16 tile;

    glyphAddr = (u8)idx * 2 + (u32)gUnk_020215D2;
    tile = (gModule_FontTileEntries[*(u16 *)glyphAddr] & 0xFFF) | 0xE000;
    *dest = tile;
}
