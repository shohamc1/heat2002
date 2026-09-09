#include "global.h"

s32 sub_0801A380(u32 r0, u32 *r1, u8 *r2, u32 r3)
{
    u32 buf[1];

    if (r1 == 0)
        r1 = buf;
    if (r2 != 0) {
        if (r3 == 0)
            return -1;
        r1[0] = r2[0];
        if (r2[0] != 0)
            return 1;
    }
    return 0;
}
