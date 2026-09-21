#include "global.h"

u32 sub_08341AC4(u8 *a1, s32 a2)
{
    u16 *arr;
    s16 i;
    s32 v;

    i = 0;
    arr = *(u16 **)(a1 + 0xEC);
    do
    {
        v = -(s32)arr[i] * a2 >> 8;
        if ((u32)(v - 2001) <= 8998)
            return i;
        i++;
    } while (i != 5);
    if (a2 > -150000)
        return 0;
    return 4;
}
