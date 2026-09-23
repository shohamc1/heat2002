#include "global.h"

extern u16 *gUnk_020251B8;
extern u16 gUnk_0201F9D0[];
extern u16 gUnk_0201F590[];

void sub_0833EF68(u8 *p, u32 a2, u32 a3, u8 a4)
{
    u16 *out;
    u32 off;
    u16 color;
    u8 t;
    u16 *e;
    u16 idx;
    u32 c;

        out = &gUnk_020251B8[a3 * 0x20 + a2];
    color = 0xE0 << 8;
    if (a4 != 0)
        color = 0xF0 << 8;
    c = *p++;
    while (c != 0) {
        t = c - 0x20;
        idx = (u16)(((((t >> 5) << 22) + 0x600000u) >> 16));
        idx = idx + (t & 0x1F);
        e = &gUnk_0201F590[idx];
        out[0] = color | gUnk_0201F9D0[e[0]];
        out[1] = color | gUnk_0201F9D0[e[1]];
        out[0x20] = color | gUnk_0201F9D0[e[0x20]];
        out[0x21] = color | gUnk_0201F9D0[e[0x21]];
        out += 1;
        c = *p++;
    }
}
