#include "global.h"
#include "variables.h"

extern u32 gUnk_0203B860;
extern u32 gUnk_020269C0[];

void sub_0833F448(u32 r0)
{
    gUnk_0203B860 = gUnk_020269C0[r0];
    gUnk_0203B6F0 = 0x14;
}
