#include "global.h"

extern u32 gUnk_02039200[]; /* 0x02039200 */

u32 sub_08340168(u32 ptr)
{
    u32 *p = gUnk_02039200;
    u8 i;

    for (i = 0; i != 0x5; i++, p++) {
        if (*p == ptr)
            return i;
    }
    return 0x5;
}
