#include "global.h"

s16 sub_08000328(s16 arg0, s16 arg1)
{
    s32 prod = arg0 * arg1;

    prod /= 256;
    return prod;
}
