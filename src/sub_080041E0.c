#include "global.h"

extern u8 gUnk_02022E10; /* 0x02022E10 */
extern u32 gUnk_02024620[]; /* 0x02024620 */

void sub_080041E0(void)
{
    if (gUnk_02022E10 != 0)
    {
        sub_08016E10(gUnk_02024620, 0xA0 << 19, 0x80 << 1);
        gUnk_02022E10 = 0;
    }
}
