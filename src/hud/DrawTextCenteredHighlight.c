#include "global.h"
#include "data.h"


void DrawTextCenteredHighlight(const u8 *text, u32 y, u8 highlight)
{
    const u8 *s = text;
    u8 len = 0;
    u32 c = *text;
    u16 **v = (u16 **)&gTextLayerMapPtr;
    u8 pad;
    u16 *out;
    u16 color;

    while (c != 0)
    {
        s++;
        len++;
        c = *s;
    }
    pad = (u8)((0x1E - len) / 2);
    out = *v;
    out += y * 0x20 + pad;
    color = 0xE0 << 8;
    if (highlight != 0)
        color = 0xF0 << 8;
    while ((c = *text++) != 0)
    {
        u16 idx = gTextCharMap[(u8)(c - 0x20)];
        *out++ = color | gTextGlyphTileIndices[idx];
    }
}
