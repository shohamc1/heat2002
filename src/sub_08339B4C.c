#include "global.h"

extern volatile u16 gUnk_02037618; /* 0x02037618 */
extern volatile u16 gUnk_0203761C; /* 0x0203761C */

void sub_08339B4C(void)
{
    u16 keys = ~*(volatile u16 *)0x04000130;
    gUnk_0203761C = keys & ~gUnk_02037618;
    gUnk_02037618 = keys;
}
