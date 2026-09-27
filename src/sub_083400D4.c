#include "global.h"
#include "variables.h"


u32 *sub_0833FC94(u32 p);
s32 sub_0833FD78(u32 a);
u32 sub_0833D6A0(u32 a, u32 b);

void sub_083400D4(s32 a1, s32 a2, u32 a3, u32 a4, u8 a5)
{
    u32 dx;
    s32 dy;
    u32 *q;
    u32 attr;
    u32 t;
    u32 v;

    dx = (a1 >> 16) - gModule_Camera[6];
    dy = (a2 >> 16) - gModule_Camera[7];
    dy += 0x40;
    dx += 0x70;
    if (dx + 0x10 <= 0x100 && dy <= 0xA0 && dy >= -0x10) {
        q = sub_0833FC94(a3);
        if (q != 0) {
            v = sub_0833FD78(a4) << 24;
            attr = (dy & 0xFF) | ((dx & 0x1FF) << 16) | 0x40000000;
            v = v >> 12;
            v = v | 0x800;
            t = *(u32 *)((u32)q + 0x10) | v;
            if (a5 != 0)
                attr |= 0x10000000;
            sub_0833D6A0(attr, t);
        }
    }
}
