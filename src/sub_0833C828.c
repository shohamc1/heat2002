#include "global.h"

extern u16 gUnk_02039180;

u8 sub_0833C828(u16 r0, u8 r1)
{
    u16 v0 = r0;

    if (r1 == 0) {
        if (v0 != gUnk_02039180)
            return 0;
    } else {
        if (v0 != ((gUnk_02039180 + 1) & 7))
            return 0;
    }
    return 1;
}
