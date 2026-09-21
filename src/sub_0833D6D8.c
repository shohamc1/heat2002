#include "global.h"

extern u32 *gUnk_0203ACD0;
extern u8 gUnk_0203ACD4;

u32 sub_0833D6D8(u32 a, u32 b, u16 c)
{
    u32 *ptr;
    u32 v;

    ptr = gUnk_0203ACD0;
    ptr[0] = a;
    ptr[1] = b;
    ((u16 *)ptr)[4] = c;
    gUnk_0203ACD0 = ptr + 3;
    v = gUnk_0203ACD4 + 1;
    gUnk_0203ACD4 = v;
    return v;
}
