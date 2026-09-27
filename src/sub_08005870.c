#include "global.h"
#include "data.h"

struct Entry
{
    u16 a;
    u16 b;
};

struct Unk
{
    u16 a;
    u16 b;
    u8 pad[0x84];
    u16 c;
    u16 d;
};

extern struct Entry gBigDigitGlyphs[];

void DrawBigDigit(u16 *dest, u8 idx)
{
    struct Unk *e = (struct Unk *)&gBigDigitGlyphs[idx];

    dest[0] = gFontTileEntries[e->a] | 0xE000;
    dest[1] = gFontTileEntries[e->b] | 0xE000;
    dest[0x20] = gFontTileEntries[e->c] | 0xE000;
    dest[0x21] = 0xE000 | gFontTileEntries[e->d];
}
