#include "global.h"

extern u32 gUnk_0202EFC0[]; /* 0x0202EFC0 */

u32 sub_08007B10(u32 ptr)
{
    u32 *p = gUnk_0202EFC0;
    u8 i;

    for (i = 0; i != 0x18; i++, p++) {
        if (*p == ptr)
            return i;
    }
    return 0x18;
}
