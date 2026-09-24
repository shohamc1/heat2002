#include "global.h"

extern u32 gUnk_020020D4; /* 0x020020D4 */

u32 ParkMillerNext(u32 a);

u8 Random8(void)
{
    gUnk_020020D4 = ParkMillerNext(gUnk_020020D4);
    return gUnk_020020D4;
}
