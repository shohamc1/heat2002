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

extern struct Entry gUnk_08334DE2[];
extern u16 gUnk_08335A8C[];

void sub_08005870(u16 *dest, u8 idx)
{
    struct Unk *e = (struct Unk *)&gUnk_08334DE2[idx];

    dest[0] = gUnk_08335A8C[e->a] | 0xE000;
    dest[1] = gUnk_08335A8C[e->b] | 0xE000;
    dest[0x20] = gUnk_08335A8C[e->c] | 0xE000;
    dest[0x21] = 0xE000 | gUnk_08335A8C[e->d];
}
