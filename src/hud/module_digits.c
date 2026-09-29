#include "global.h"
#include "variables.h"

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
extern struct Entry gUnk_020215AA[];
extern u16 gUnk_020215D2[];

void ModuleDrawBigDigit(u16 *dest, u8 idx)
{
    struct Unk *e = (struct Unk *)&gUnk_020215AA[idx];

    dest[0] = gModule_FontTileEntries[e->a] | 0xE000;
    dest[1] = gModule_FontTileEntries[e->b] | 0xE000;
    dest[0x20] = gModule_FontTileEntries[e->c] | 0xE000;
    dest[0x21] = 0xE000 | gModule_FontTileEntries[e->d];
}

void ModuleDrawSmallDigit(u16 *dest, s32 idx)
{
    u32 glyphAddr;
    u16 tile;

    glyphAddr = (u8)idx * 2 + (u32)gUnk_020215D2;
    tile = (gModule_FontTileEntries[*(u16 *)glyphAddr] & 0xFFF) | 0xE000;
    *dest = tile;
}
