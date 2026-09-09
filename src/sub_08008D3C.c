#include "global.h"

extern u32 gUnk_0202CB40[];
extern s32 sub_08017230(s32 a, s32 b);

s32 sub_08008D3C(void)
{
    u8 i;
    u32 v;
    u32 sum;

    sum = 0;
    for (i = 0; i != 13; i = (u8)(i + 1))
    {
        v = gUnk_0202CB40[i];
        sum += v;
        if (v == 0)
            return 0;
    }
    return sub_08017230(sum, 13) - 1;
}
