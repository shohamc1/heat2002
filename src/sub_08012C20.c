#include "global.h"

extern u32 gUnk_0202EFC0[0x18];
extern u32 gUnk_0202A550;

u32 sub_08012C20(void)
{
    u32 i;
    for (i = 0; i != 0x18; i = (u8)(i + 1)) {
        if (gUnk_0202EFC0[i] == (u32)&gUnk_0202A550)
            return i;
    }
    return 0x17;
}
