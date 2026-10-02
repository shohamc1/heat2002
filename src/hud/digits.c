#include "global.h"
#include "functions.h"
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

#if PLATFORM_GBA
extern struct BigDigitGlyphRow gBigDigitGlyphs[];
#else
// symbols.ld alias gBigDigitGlyphs = gFontGlyphGrid + 0x16, viewed here as
// rows; the port has no linker script, so the alias becomes a constant.
#define gBigDigitGlyphs ((struct BigDigitGlyphRow *)((u8 *)gFontGlyphGrid + 0x16))
#endif

#if PLATFORM_GBA
extern u16 gSmallDigitGlyphs[];
#else
// symbols.ld alias gSmallDigitGlyphs = gFontGlyphGrid + 0x3E.
#define gSmallDigitGlyphs ((u16 *)((u8 *)gFontGlyphGrid + 0x3E))
#endif

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
