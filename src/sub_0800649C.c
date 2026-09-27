#include "global.h"
#include "data.h"


void sub_0800649C(u8 *str, u32 x, u32 y)
{
    u16 *dest;
    u32 color;
    u32 c;
    u32 v;
    u32 w;

    dest = *(u16 **)&gTextLayerMapPtr;
    dest += (y << 5) + x;
    color = 0xE0 << 8;
    w = 0x47;
    c = *str++;
    while (c != 0) {
        if (c != 0x20) {
            v = color;
            v |= gFontTileEntries[gFontCharToGlyphTable[(u8)(c - 0x21)]];
            *dest++ = v;
        } else {
            w = 0x47;
            *dest++ = w;
        }
        c = *str++;
    }
}
