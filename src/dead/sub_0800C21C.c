#include "global.h"
#include "functions.h"
#include "variables.h"

extern const u8 *const gLineMarkerSpriteGfxTable[];

u8 WorldToScreen(s32 x, s32 y, s32 *out);

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
    p = sub_0800767C((u32)gLineMarkerSpriteGfxTable);
    if (p == 0)
        return;
    if ((*(s32 *)&gUnk_02002148) > 0xFF) {
        a = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x100;
        b = p[4] | (c << 12);
    }
    AddOamEntry(a, b);
}

void sub_0800C288(void)
{
}
