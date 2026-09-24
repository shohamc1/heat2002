#include "global.h"

extern u16 gUnk_02000DD0; /* 0x02000DD0 */

void sub_08000444(void)
{
    *(volatile u16 *)0x04000202 = 1;
    gUnk_02000DD0 = 1;
}
