#include "global.h"
#include "functions.h"

extern u8 gUnk_0202EED0;
extern u32 gUnk_0202EDE4;
extern u16 gUnk_0202EDF0[];
extern u16 gUnk_0500013C;


void sub_08010768(s32 a)
{
    s32 r;
    u16 *p;
    register s32 n asm("r1") = -a;

    r = sub_080172C8(n, 6);
    if (r < 0)
        r += 6;
    gUnk_0202EED0 = r;
    p = gUnk_0202EDF0;
    LoadFadePalette(p);
    sub_08016E10((u32)p, 0x05000000, 0x40);
}

void sub_080107A4(void)
{
    u32 idx;
    u16 color;

    idx = (gUnk_0202EDE4 + 1) & 0x1F;
    gUnk_0202EDE4 = idx;
    color = 0x6800 | (idx << 5);
    sub_08016E10((u32)&color, (u32)&gUnk_0500013C, 1);
}
