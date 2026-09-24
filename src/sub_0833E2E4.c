#include "global.h"

extern u32 gUnk_0203B6CC; /* 0x0203B6CC */
extern u32 gUnk_0203B84C; /* 0x0203B84C */

u32 sub_0833E2E4(void)
{
    if (gUnk_0203B6CC != 0)
        return 1;
    if (gUnk_0203B84C != 0)
        return 1;
    return 0;
}
