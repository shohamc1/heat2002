#include "global.h"
#include "data.h"

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

extern struct BigDigitGlyphRow gBigDigitGlyphs[];

extern u16 gSmallDigitGlyphs[];

void DrawBigDigit(u16 *dest, u8 idx)
{
    struct BigDigitGlyph *e = (struct BigDigitGlyph *)&gBigDigitGlyphs[idx];

    dest[0] = gFontTileEntries[e->topLeft] | 0xE000;
    dest[1] = gFontTileEntries[e->topRight] | 0xE000;
    dest[0x20] = gFontTileEntries[e->bottomLeft] | 0xE000;
    dest[0x21] = 0xE000 | gFontTileEntries[e->bottomRight];
}

void DrawSmallDigit(u16 *dest, u8 idx)
{
    u16 v;

    v = *(idx + gSmallDigitGlyphs);
    *dest = (gFontTileEntries[v] & 0xFFF) | 0xE000;
}
