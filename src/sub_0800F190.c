#include "global.h"

extern u8 gUnk_0202EF20[]; /* 0x0202EF20 */

u32 sub_0800F190(void)
{
    u8 i;

    for (i = 0; i != 0x11; i++) {
        if (gUnk_0202EF20[i] != 0)
            return 1;
    }
    return 0;
}
