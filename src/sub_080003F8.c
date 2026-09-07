#include "global.h"

extern u32 gUnk_02000580[];

void sub_080003F8(u32 r0)
{
    gUnk_02000580[0] = r0;
    if (r0 == 0)
        gUnk_02000580[0] = (u32)0x0800042D;
}
