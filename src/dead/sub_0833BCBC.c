#include "global.h"
#include "variables.h"

u32 sub_0833BC7C(u32 seed);

u8 sub_0833BCBC(void)
{
    u32 v = sub_0833BC7C(gUnk_020390E4);

    gUnk_020390E4 = v;
    return v;
}

void sub_0833BCD8(u32 seed)
{
    register u32 s asm("r1") = seed;
    u32 *p = &gUnk_020390E4;
    u32 v;

    if (s != 0)
        v = 0x7FFFFFFF & s;
    else
        v = 1;
    *p = v;
}
