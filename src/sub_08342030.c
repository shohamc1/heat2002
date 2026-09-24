#include "global.h"

struct Ent42030 {
    u8 pad00[0x34];
    u16 unk34;
    u8 pad36[0x12C - 0x36];
    s32 unk12C;
};

void sub_08342030(struct Ent42030 *p)
{
    int v;
    s32 w;
    int lo, hi;

    v = p->unk34 >> 8;
    w = p->unk12C >> 8;
    lo = v - 0x30;
    hi = v + 0x30;
    if (w > v && w < v + 0x80) {
        if (w > hi)
            p->unk12C = hi << 8;
    } else if (w < lo)
        p->unk12C = lo << 8;
}
