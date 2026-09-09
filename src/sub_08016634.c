#include "global.h"

extern u16 gUnk_0202F040[];
u32 sub_080165E0(u32 r0, u32 r1);

u32 sub_08016634(void)
{
    u32 r0 = 8;
    u32 r1 = 8;

    sub_080165E0(r0, r1);
    if (gUnk_0202F040[5] != 0)
        return 1;
    return 0;
}
