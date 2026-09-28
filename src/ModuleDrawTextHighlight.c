#include "global.h"
#include "variables.h"


void ModuleDrawTextHighlight(const u8 *text, u32 x, u32 y, u8 highlight)
{
    u16 *out;
    u32 off;
    u16 color;
    u8 t;
    u16 *e;
    u16 idx;
    u32 c;

        out = &(*(u16 **)&gModule_TextLayerMapPtr)[y * 0x20 + x];
    color = 0xE0 << 8; /* tilemap entry: palette bank 14 */
    if (highlight != 0)
        color = 0xF0 << 8; /* tilemap entry: palette bank 15 */
    c = *text++;
    while (c != 0) {
        t = c - ' ';
        idx = (u16)(((((t >> 5) << 22) + 0x600000u) >> 16));
        idx = idx + (t & 0x1F);
        e = &gUnk_0201F590[idx];
        out[0] = color | gModule_TextGlyphTileIndices[e[0]];
        out[1] = color | gModule_TextGlyphTileIndices[e[1]];
        out[0x20] = color | gModule_TextGlyphTileIndices[e[0x20]];
        out[0x21] = color | gModule_TextGlyphTileIndices[e[0x21]];
        out += 1;
        c = *text++;
    }
}
