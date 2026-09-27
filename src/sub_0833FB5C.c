#include "global.h"
#include "variables.h"


u32 *sub_0833FB5C(u32 a, u8 b)
{
    u32 *p;
    u32 *q;
    u32 i;

    p = (u32 *)gUnk_0203C220;
    i = 0;
    q = p;
    for (; i != 4; i++, p += 5) {
        if (p[2] == a) {
            p[0] = 1;
            *((u8 *)p + 5) = b;
            return p;
        }
    }
    p = q;
    for (i = 0; i != 4; i++, p += 5) {
        if (p[0] == 0) {
            p[0] = 1;
            *((u8 *)p + 5) = b;
            *((u8 *)p + 4) = 1;
            p[2] = a;
            return p;
        }
    }
    return 0;
}
