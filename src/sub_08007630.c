#include "global.h"
#include "variables.h"


u32 *sub_08007630(u32 p)
{
    u32 i;
    u32 *q;

    q = gUnk_02025C70;
    i = 0;
    do {
        if (q[2] == p) {
            q[0] = 1;
            return q;
        }
        i++;
        q += 5;
    } while (i != 16);
    q = gUnk_02025C70;
    for (i = 0; i != 16; i++, q += 5) {
        if (q[0] == 0) {
            q[0] = 1;
            *(u8 *)(q + 1) = 1;
            q[2] = p;
            return q;
        }
    }
    return 0;
}
