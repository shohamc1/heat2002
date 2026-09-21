#include "global.h"

extern u32 gUnk_020392D0[];
extern u32 gUnk_02039ED0[];
extern u16 gUnk_020392C8;
extern u8 gUnk_020392C4;

u32 sub_08344BB8(s32 a, u32 b);

void sub_0833D31C(u32 a, u16 *src)
{
    u32 *cam;
    u32 *out;
    u32 i;
    u16 v;
    s32 x;
    s32 y;
    s32 z;

    i = 0;
    cam = gUnk_020392D0;
    out = gUnk_02039ED0;
    for (; i != 0x100; i++)
    {
        v = *src;
        src++;
        x = v & 0x1F;
        y = (v >> 5) & 0x1F;
        z = (v >> 10) & 0x1F;
        x = x * 3 / 2;
        if (x > 0x1F)
            x = 0x1F;
        y = y * 3 / 2;
        if (y > 0x1F)
            y = 0x1F;
        z = z * 3 / 2;
        if (z > 0x1F)
            z = 0x1F;
        x = x << 0x10;
        y = y << 0x10;
        z = z << 0x10;
        out[0] = sub_08344BB8(x - cam[0], a);
        out[1] = sub_08344BB8(y - cam[1], a);
        out[2] = sub_08344BB8(z - cam[2], a);
        cam += 3;
        out += 3;
    }
    gUnk_020392C8 = a;
    gUnk_020392C4 = 1;
}
