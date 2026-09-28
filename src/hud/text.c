#include "global.h"
#include "data.h"

void DrawText(const u8 *text, u32 x, u32 y, u8 highlight)
{
    u16 *out = (u16 *)*(u32 *)&gTextLayerMapPtr;
    u16 color;
    u32 c;

    out += y * 32 + x; /* 32 tilemap entries per text row */
    color = 0xE0 << 8;   /* tilemap entry: palette bank 14 */
    if (highlight != 0)
        color = 0xF0 << 8; /* palette bank 15 */
    while ((c = *text++) != 0)
    {
        u16 idx = gTextCharMap[(u8)(c - ' ')];
        *out++ = color | gTextGlyphTileIndices[idx];
    }
}

void DrawTextCentered(const u8 *str, u32 y)
{
    const u8 *p;
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
    pad = (0x1E - len) / 2; /* center within the 30 visible columns */
    dest = (*(u16 **)&gTextLayerMapPtr);
    dest += y * 32 + pad;
    color = 0xE0 << 8;
    w = 0x47;
    c = *str++;
    while (c != 0) {
        if (c != ' ') {
            v = color;
            v |= gFontTileEntries[gFontCharToGlyphTable[(u8)(c - '!')]];
            *dest++ = v;
        } else {
            w = 0x47;
            *dest++ = w;
        }
        c = *str++;
    }
}

void DrawTextAt(const u8 *str, u32 x, u32 y)
{
    u16 *dest;
    u32 color;
    u32 ch;
    u32 entry;
    u32 blank;

    dest = *(u16 **)&gTextLayerMapPtr;
    dest += y * 32 + x;
    color = 0xE0 << 8;
    blank = 0x47;
    ch = *str++;
    while (ch != 0) {
        if (ch != ' ') {
            entry = color;
            entry |= gFontTileEntries[gFontCharToGlyphTable[(u8)(ch - '!')]];
            *dest++ = entry;
        } else {
            blank = 0x47;
            *dest++ = blank;
        }
        ch = *str++;
    }
}
