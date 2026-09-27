#include "global.h"
#include "variables.h"

extern u8 gUnk_0203D520[]; /* 0x0203D520 */

void sub_083416DC(u8 *a, u8 b);

void sub_083419D8(void)
{
    u32 i;
    u32 limit;
    u8 *p;

    limit = gUnk_020390A0[0];
    if (gUnk_020390EC != 0)
        limit = gUnk_020390BC[0];
    p = gUnk_0203D520;
    for (i = 0; i != limit; i++, p += 0x190)
    {
        if (gUnk_0203916C[0] != 2 || i == 0)
            sub_083416DC(p, i);
    }
}
