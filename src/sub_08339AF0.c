#include "global.h"

extern volatile u16 gUnk_02037E20; /* 0x02037E20 */

void sub_08339AF0(void)
{
    gUnk_02037E20 &= ~1;
}
