#include "global.h"
#include "data.h"

extern u32 gUnk_083681E8[];
extern s32 gUnk_0200209C;

s32 sub_080172C8(s32 a, s32 b);
u32 *sub_08007630(u32 p);
s32 RequestObjPalette(u32 a);
u32 AddOamEntry(u32 a, u32 b);

void sub_08009FA0(u32 a1, u32 a2, u32 a3)
{
    u32 *p = (u32 *)gUnk_083681E8[a3];
    u32 attr;
    u32 *q;
    u32 t;

    p += sub_080172C8(gUnk_0200209C >> 1, 7);
    attr = (a2 & 0xFF) | ((a1 & 0x1FF) << 16) | 0x40000000;
    q = sub_08007630(*p);
    if (q != 0) {
        t = *(u32 *)((u32)q + 0x10);
        t |= (u8)RequestObjPalette((u32)gUnk_08337C20) << 12;
        AddOamEntry(attr, t);
    }
}
