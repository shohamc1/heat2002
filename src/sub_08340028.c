#include "global.h"

extern u8 gUnk_0203D520[];

u32 sub_08340028(u32 a)
{
    s32 r;
    s32 v;
    s32 c;

    if (a != (u32)gUnk_0203D520)
    {
        r = 0;
        if (*(s32 *)(a + 0x9C) <= 0xA0 << 6)
            r = 1;
        v = *(s32 *)(a + 0x8C);
        c = 0x3E7FF;
    }
    else
    {
        r = 0;
        if (*(s32 *)(a + 0x9C) <= 0xA0 << 6)
            r = 1;
        v = *(s32 *)(a + 0x8C);
        c = 0x5DBFF;
    }
    if (v > c
        || *(s32 *)(a + 0x90) > c
        || *(s32 *)(a + 0x94) > c
        || *(s32 *)(a + 0x98) > c)
        r = 1;
    return r;
}
