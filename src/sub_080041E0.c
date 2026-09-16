#include "global.h"
#include "gba/compat.h"

extern u8 gUnk_02022E10; /* 0x02022E10 */
extern u32 gUnk_02024620[]; /* 0x02024620 */

void sub_080041E0(void)
{
    u32 p;

    if (gUnk_02022E10 != 0)
    {
        p = (u32)gUnk_02024620;
        CpuCopy16(p, PLTT, PLTT_SIZE / 2);
        gUnk_02022E10 = 0;
    }
}
