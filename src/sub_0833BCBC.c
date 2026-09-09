#include "global.h"

extern u32 gUnk_020390E4; /* 0x020390E4 */

u32 sub_0833BC7C(u32 seed);

u8 sub_0833BCBC(void)
{
    u32 v = sub_0833BC7C(gUnk_020390E4);

    gUnk_020390E4 = v;
    return v;
}
