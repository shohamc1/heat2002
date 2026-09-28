#include "global.h"
#include "functions.h"


u32 RandomInRange(u32 a, u32 b)
{
    u32 r4 = a;
    u32 r5 = b;
    u8 t;

    t = Random8();
    r5 = r5 - r4;
    r5 = r5 * t;
    r5 = ((s32)r5) >> 8;
    return r4 + r5;
}
