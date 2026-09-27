#include "global.h"
#include "data.h"

extern u16 gSmallDigitGlyphs[];

void DrawSmallDigit(u16 *dest, u8 idx)
{
    u16 v;

    v = *(idx + gSmallDigitGlyphs);
    *dest = (gFontTileEntries[v] & 0xFFF) | 0xE000;
}
