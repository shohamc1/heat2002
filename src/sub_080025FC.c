#include "global.h"

extern u32 gUnk_020020D4; /* 0x020020D4 */

u8 sub_080025FC(void)
{
    gUnk_020020D4 = sub_080025BC(gUnk_020020D4);
    return gUnk_020020D4;
}
