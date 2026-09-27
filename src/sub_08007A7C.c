#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_08007A7C(s32 a1, s32 a2, u32 a3, u32 a4, u8 a5)
{
    u32 dx;
    s32 dy;
    u32 *q;
    u32 attr;
    u32 t;
    u32 v;

    dx = (a1 >> 16) - gCamera[6];
    dy = (a2 >> 16) - gCamera[7];
    dy += 0x40;
    dx += 0x70;
    if (dx + 0x10 <= 0x100 && dy <= 0xA0 && dy >= -0x10) {
        q = sub_08007630(a3);
        if (q != 0) {
            v = RequestObjPalette(a4) << 24;
            attr = (dy & 0xFF) | ((dx & 0x1FF) << 16) | 0x40000000;
            v = v >> 12;
            v = v | 0x800;
            t = *(u32 *)((u32)q + 0x10) | v;
            if (a5 != 0)
                attr |= 0x10000000;
            AddOamEntry(attr, t);
        }
    }
}
