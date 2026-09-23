#include "global.h"

extern u8 gUnk_0203E140[]; /* 0x0203E140 */

u32 sub_0834470C(void)
{
    u8 i;

    for (i = 0; i != 0x11; i++) {
        if (gUnk_0203E140[i] != 0)
            return 1;
    }
    return 0;
}
