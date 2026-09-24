#include "global.h"

extern u32 gUnk_083FEF04[];
extern s32 gUnk_02002148;

u8 WorldToScreen(s32 x, s32 y, s32 *out);
extern u32 *sub_0800767C(void *a);
u32 AddOamEntry(u32 a, u32 b);

void sub_0800C21C(s32 x, s32 y, u8 c)
{
    s32 out[2];
    u32 *p;
    u32 a;
    u32 b;

    if (WorldToScreen(x, y, out) == 0)
        return;
    out[0] = out[0] - 0x10;
    out[1] = out[1] - 0x10;
    p = sub_0800767C(gUnk_083FEF04);
    if (p == 0)
        return;
    if (gUnk_02002148 > 0xFF) {
        a = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x100;
        b = p[4] | (c << 12);
    }
    AddOamEntry(a, b);
}
