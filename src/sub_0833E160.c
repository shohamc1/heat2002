#include "global.h"

extern u16 gUnk_0203B810[];
extern u8 gUnk_020390DC;
extern u16 gUnk_0203B6B0[];
extern u16 gUnk_0203B830[];
extern u8 gUnk_0203916C[];
extern u8 gUnk_02039100;

void sub_0833E110(u32 a, u32 b, u32 c);
void sub_08342D64(void);

void sub_0833E160(u16 a, u16 b, u16 c)
{
    s32 total;
    s32 best;

    total = a * 60000 + b * 1000 + c;
    best = 60000 * gUnk_0203B810[gUnk_020390DC] + gUnk_0203B6B0[gUnk_020390DC] * 1000 + gUnk_0203B830[gUnk_020390DC];
    if (total > best)
        return;
    if ((u8)(gUnk_0203916C[0] - 3) <= 1)
        return;
    sub_0833E110(a, b, c);
    gUnk_02039100 = 1;
    sub_08342D64();
}
