#include "global.h"

extern u32 gUnk_02024828; /* 0x02024828: current queue write pointer */
extern u8 gUnk_02025150;  /* 0x02025150: queue entry counter */

u32 sub_080044A4(u32 a, u32 b)
{
    u32 *p;

    if ((s8)gUnk_02025150 < 0)
        return 0;
    p = *(u32 **)&gUnk_02024828;
    p[0] = a;
    p[1] = b;
    *(u32 *)&gUnk_02024828 = p + 2;
    gUnk_02025150 = gUnk_02025150 + 1;
    return 1;
}
