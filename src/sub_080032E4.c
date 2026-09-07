#include "global.h"

extern u16 gUnk_02002170; /* 0x02002170 */

u32 sub_080032E4(u16 a, u8 b)
{
    if (b == 0)
    {
        if (a != gUnk_02002170)
            return 0;
    }
    else
    {
        if (a != (gUnk_02002170 + 1 & 7))
            return 0;
    }
    return 1;
}
