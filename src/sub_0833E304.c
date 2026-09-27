#include "global.h"
#include "variables.h"

extern s32 gUnk_0203B84C;
extern s32 gUnk_0203B6CC;

void sub_083429B4(void);

void sub_0833E304(void)
{
    u32 v;

    if (gUnk_020390D4 == 0)
        return;
    v = gUnk_020391F0;
    if (v != 0)
        return;
    gUnk_0203B84C -= 0x18;
    if (gUnk_0203B84C >= 0)
        return;
    gUnk_0203B84C += 0x3E8;
    gUnk_0203B6CC -= 1;
    gUnk_0203B6E8 = 1;
    if (gUnk_0203B6CC >= 0)
        return;
    gUnk_0203B6CC = v;
    gUnk_0203B84C = v;
    if (gUnk_0203916C[0] != 0)
        return;
    sub_083429B4();
}
