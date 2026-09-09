#include "global.h"

u32 sub_080025FC(void);

u32 sub_08016C30(u32 a, u32 b)
{
    u32 r4 = a;
    u32 r5 = b;
    u8 t;

    t = sub_080025FC();
    r5 = r5 - r4;
    r5 = r5 * t;
    r5 = ((s32)r5) >> 8;
    return r4 + r5;
}
