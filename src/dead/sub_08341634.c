#include "global.h"

void sub_08341634(s32 arg0, s32 arg1, s32 *arg2)
{
    s32 sum = arg1 + arg0 / 2;
    s32 diff = arg1 - arg0 / 2;

    arg2[0] = sum;
    arg2[1] = diff;
}
