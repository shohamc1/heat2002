#include "global.h"
#include "variables.h"


void sub_0833CFC8(s32 a, s32 b, u32 c, u32 d, u32 e, u16 f);

void sub_0833CF10(void)
{
    s32 x;
    s32 y;

    x = gUnk_02039110[6] - 0x78;
    y = gUnk_02039110[7] - 0x50;
    gUnk_0203925C = x & 0xF;
    gUnk_02039260 = y & 0x1F;
    gUnk_020392A8 = x & 0xF;
    gUnk_02039240 = y & 0x1F;
    gUnk_02039290 = x & 0xF;
    gUnk_02039298 = y & 0x1F;
    gUnk_02039234[0] = x & 0x10;
    x = x >> 5;
    y = y >> 5;
    sub_0833CFC8(x, y, (*(u32 *)&gUnk_02039228), 0x03000000, (*(u32 *)&gUnk_02039238), gUnk_02039248);
    sub_0833CFC8(x, y, (*(u32 *)&gUnk_02039268), 0x03000800, (*(u32 *)&gUnk_0203922C), gUnk_020392A4);
}
