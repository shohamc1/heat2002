#include "global.h"
#include "data.h"

void DrawText(u8 *p, u32 a1, u32 a2, u8 a3)
{
    u16 *out = (u16 *)*(u32 *)&gTextLayerMapPtr;
    u16 color;
    u32 c;

    out += a2 * 0x20 + a1;
    color = 0xE0 << 8;
    if (a3 != 0)
        color = 0xF0 << 8;
    while ((c = *p++) != 0)
    {
        u16 idx = gTextCharMap[(u8)(c - 0x20)];
        *out++ = color | gTextGlyphTileIndices[idx];
    }
}

void DrawTextCentered(u8 *str, u32 y)
{
    u8 *p;
    u8 len;
    u8 pad;
    u16 *dest;
    u32 color;
    u32 c;
    u32 v;
    u32 w;

    p = str;
    len = 0;
    c = *p;
    while (c != 0) {
        p++;
        len++;
        c = *p;
    }
    pad = (u8)((0x1E - len) / 2);
    dest = (*(u16 **)&gTextLayerMapPtr);
    dest += (y << 5) + pad;
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
