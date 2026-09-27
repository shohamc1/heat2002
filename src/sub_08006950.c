#include "global.h"
#include "data.h"


void DrawTextCenteredHighlight(u8 *p, u32 a1, u8 a2)
{
    u8 *s = p;
    u8 len = 0;
    u32 c = *p;
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
    out += a1 * 0x20 + pad;
    color = 0xE0 << 8;
    if (a2 != 0)
        color = 0xF0 << 8;
    while ((c = *p++) != 0)
    {
        u16 idx = gTextCharMap[(u8)(c - 0x20)];
        *out++ = color | gTextGlyphTileIndices[idx];
    }
}
