#include "global.h"

extern u32 *sub_080074F8(u32 a, u8 b);
extern u8 sub_08007714(u32 a);
extern u32 sub_080044A4(u32 a, u32 b);

void sub_080100CC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4)
{
    u32 *v;
    u8 idx;
    u32 attr;
    u32 x;
    u32 oam;

    v = sub_080074F8(a2, 1);
    if (v == 0)
        return;
    idx = sub_08007714(a3);
    attr = (a1 & 0xFF) | ((a0 & 0x1FF) << 16) | 0xC0000000;
    x = (idx << 12) | 0x800;
    oam = v[4] | x;
    if (a4 != 0)
        attr |= 0x10000000;
    sub_080044A4(attr, oam);
}
