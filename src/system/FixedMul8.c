#include "global.h"

s16 FixedMul8(s16 arg0, s16 arg1)
{
    s32 prod = arg0 * arg1;

    prod /= 256;
    return prod;
}
