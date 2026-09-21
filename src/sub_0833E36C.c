#include "global.h"

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
extern u16 gUnk_02022254[];

void sub_0833E36C(u16 *dest, u8 idx)
{
    struct Unk *e = (struct Unk *)&gUnk_020215AA[idx];

    dest[0] = gUnk_02022254[e->a] | 0xE000;
    dest[1] = gUnk_02022254[e->b] | 0xE000;
    dest[0x20] = gUnk_02022254[e->c] | 0xE000;
    dest[0x21] = 0xE000 | gUnk_02022254[e->d];
}
