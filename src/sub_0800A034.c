#include "global.h"

s32 sub_0800A034(u8 *a, s32 b)
{
    u16 *arr;
    u16 j;
    s16 i;
    s32 v;

    j = 0;
    arr = *(u16 **)(a + 0xEC);
    do {
        i = j;
        v = (-(s32)arr[i] * b) >> 8;
        if ((u32)(v - 2001) <= 0x2326)
            return i;
        j = i + 1;
    } while ((s16)j != 5);
    if (b > -150000)
        return 0;
    return 4;
}
