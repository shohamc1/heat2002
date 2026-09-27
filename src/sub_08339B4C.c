#include "global.h"
#include "gba/io_reg.h"

extern u16 gUnk_02037618; /* 0x02037618 */
extern u16 gUnk_0203761C; /* 0x0203761C */

void sub_08339B4C(void)
{
    u16 keys = ~REG_KEYINPUT;
    *(vu16 *)&gUnk_0203761C = keys & ~*(vu16 *)&gUnk_02037618;
    *(vu16 *)&gUnk_02037618 = keys;
}
