#include "global.h"
#include "functions.h"
#include "data.h"

void DrawBigText(const u8 *text)
{
    u16 *dest;
    const u8 *p;
    const u8 *q;
    s32 len;
    u8 i;
    u16 color;
    u32 idx;
    u8 t;
    const u16 *e;
    u32 c;
    dest = (u16 *)(gTextLayerMapPtr[0] + 2 * 32); /* start of text row 2 */
    do {
        color = 0xF0 << 8; /* tilemap entry: palette bank 15 */
    } while (0);
    i = 0;
    q = text;
    len = 0;
    while ((*q) != 0) {
        q++;
        len++;
    }

    for (; i < ((30 - len) / 2); i++, dest++) {
        c = (*gTextPadCharPtr) - ' '; /* gTextPadCharPtr points at a space */
        t = c;
        /* font atlas walk: row = t / 32, base 0x60, row stride 64 entries */
        idx = (((t >> 5) << 22) + 0x600000u) >> 16;
        e = &gTextCharMap[idx + (t & 0x1F)];
        dest[0] = color | gTextGlyphTileIndices[e[0]];
        dest[32] = color | gTextGlyphTileIndices[e[0x20]];
    }

    c = *text;
    p = text + 1;
    if (c != 0) {
        do {
            t = c - 0x20;
            /* font atlas walk: row = t / 32, base 0x60, row stride 64 entries */
            idx = (((t >> 5) << 22) + 0x600000u) >> 16;
            e = &gTextCharMap[idx + (t & 0x1F)];
            dest[0] = color | gTextGlyphTileIndices[e[0]];
            dest[32] = color | gTextGlyphTileIndices[e[0x20]];
            dest++;
            i++;
            c = *p;
            p++;
        } while (c != 0);
    }
    for (; i < 0x20; i++, dest++) {
        t = (*gTextPadCharPtr) - 0x20;
        /* font atlas walk: row = t / 32, base 0x60, row stride 64 entries */
        idx = (((t >> 5) << 22) + 0x600000u) >> 16;
        e = &gTextCharMap[idx + (t & 0x1F)];
        dest[0] = color | gTextGlyphTileIndices[e[0]];
        dest[32] = color | gTextGlyphTileIndices[e[0x20]];
    }
}

// A stub in the retail build: callers still set up the argument
// (a string pointer from gUiFontTable), so it keeps an unused parameter.
void DummyUiFontLoad(const u8 *fontRow)
{}
