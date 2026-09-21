#include "global.h"

extern u8 gUnk_02025244;
extern u8 gUnk_0202524C;
extern u8 gUnk_020021E0;
extern u16 gUnk_020251F8;
extern u16 gUnk_02025254;

void sub_080047E8(u8 a, u16 b);

void sub_08004980(u32 a1)
{
    u8 pad[0x28];
    u8 *p;
    u32 v;
    u32 w;

    if (gUnk_02025244 == 0)
        return;
    p = *(u8 **)(a1 + 0x17C);
    v = *(u32 *)(a1 + 0x50) & 0xFFFF;
    w = gUnk_02025254;
    if (v <= w || w == 0) {
        if (*(s8 *)&gUnk_0202524C != -1 && gUnk_020021E0 == 0)
            sub_080047E8(gUnk_0202524C, gUnk_020251F8);
    }
    v = *(u32 *)(a1 + 0x50) & 0xFFFF;
    if (v >= *(u16 *)p) {
        do {
            gUnk_0202524C = p[2];
            gUnk_020251F8 = *(u16 *)(p + 4);
            gUnk_02025254 = *(u16 *)(p + 6);
            p += 8;
            *(u32 *)(a1 + 0x17C) = p;
        } while (v >= *(u16 *)p);
    }
}
