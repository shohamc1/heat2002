#include "global.h"

extern u32 gUnk_020004B8[];

s32 sub_0801B014(u32 r0)
{
    s32 i;
    for (i = 0; i <= 0x13; i++) {
        if (gUnk_020004B8[i * 2] == r0)
            break;
    }
    return i;
}
