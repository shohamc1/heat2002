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

void sub_0833E36C(u16 *dest, u8 idx)
{
    struct Unk *e = (struct Unk *)&gUnk_020215AA[idx];

    dest[0] = gModule_FontTileEntries[e->a] | 0xE000;
    dest[1] = gModule_FontTileEntries[e->b] | 0xE000;
    dest[0x20] = gModule_FontTileEntries[e->c] | 0xE000;
    dest[0x21] = 0xE000 | gModule_FontTileEntries[e->d];
}
