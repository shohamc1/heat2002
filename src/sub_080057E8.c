#include "global.h"

extern u32 gUnk_0202521C; /* 0x0202521C */
extern u32 gUnk_020253C0; /* 0x020253C0 */

u32 sub_080057E8(void)
{
    if (gUnk_0202521C != 0)
        return 1;
    if (gUnk_020253C0 != 0)
        return 1;
    return 0;
}
