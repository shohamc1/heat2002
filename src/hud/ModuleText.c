#include "global.h"
#include "variables.h"
#include "data.h"

/* The high module's text renderers, ROM order:
 * ModuleDrawTextCenteredHighlight, ModuleDrawText, ModuleDrawBigText
 * (0x0833EE88-0x0833F1DC). */

void ModuleDrawTextCenteredHighlight(u8 *str, u32 y)
{
    u8 *cursor;
    u8 len;
    u8 w;
    u16 *dest;
    u32 e;
    u32 c;
    u32 v;
    u32 t;

    cursor = str;
    len = 0;
    while (*cursor != 0) {
        cursor++;
        len++;
    }
    w = (u8)((30 - len) / 2);
    dest = (u16 *)gModule_TextLayerMapPtr[0];
    dest = (u16 *)((u32)dest + (((y << 5) + w) << 1));
    e = 0xE0 << 8;
    t = 0x47;
    c = *str++;
    while (c != 0) {
        if (c != 0x20) {
            v = e;
            v |= gModule_FontTileEntries[gModule_FontCharToGlyphTable[(u8)(c - '!')]];
            *dest++ = v;
        } else {
            t = 0x47;
            *dest++ = t;
        }
        c = *str++;
    }
}

void ModuleDrawText(const u8 *text, u32 x, u32 y)
{
    u16 *dest;
    u32 color;
    u32 c;
    u32 v;
    u32 w;

    dest = (u16 *)gModule_TextLayerMapPtr[0];
    dest += y * 32 + x;
    color = 0xE0 << 8; /* tilemap entry: palette bank 14 */
    w = 0x47;
    c = *text++;
    while (c != 0) {
        if (c != ' ') {
            v = color;
            v |= gModule_FontTileEntries[gModule_FontCharToGlyphTable[(u8)(c - '!')]];
            *dest++ = v;
        } else {
            w = 0x47;
            *dest++ = w;
        }
        c = *text++;
    }
}
