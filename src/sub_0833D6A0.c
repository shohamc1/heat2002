#include "global.h"
#include "variables.h"

extern u32 *gUnk_0203ACD8;

u32 sub_0833D6A0(u32 a, u32 b)
{
    u32 *ptr;

    if ((s8)gUnk_0203B600 < 0)
        return 0;
    ptr = gUnk_0203ACD8;
    ptr[0] = a;
    ptr[1] = b;
    gUnk_0203ACD8 = ptr + 2;
    gUnk_0203B600 = gUnk_0203B600 + 1;
    return 1;
}
