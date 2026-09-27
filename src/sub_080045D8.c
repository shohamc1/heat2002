#include "global.h"
#include "variables.h"


void sub_080045D8(void)
{
    u32 r0 = 0;
    u16 *r1 = gUnk_02025160;

    while (r0 != 0x40)
    {
        *r1 = r0;
        r1 += 1;
        r0++;
    }
}
