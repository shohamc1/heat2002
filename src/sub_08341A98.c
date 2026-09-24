#include "global.h"

s32 sub_08341A98(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    s32 t;

    if (a2 > a1)
        return a4;
    t = a2 - a0;
    if (t < 0)
        return a3;
    return ((0x4000 - t) * a3 + t * a4) >> 14;
}
