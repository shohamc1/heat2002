#include "global.h"

extern u8 gUnk_02000494;
extern u32 gUnk_0200049C;
extern u8 gUnk_08016E7D;

u32 sub_08016EA0(u32 arg0, u32 arg1)
{
    u32 *r2 = (u32 *)arg1;
    u8 r1 = arg0;

    if (r1 > 3)
        return 1;
    gUnk_02000494 = r1;
    gUnk_0200049C = 0x04000100 + (gUnk_02000494 << 2);
    *r2 = (u32)&gUnk_08016E7D;
    return 0;
}
