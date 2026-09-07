#include "global.h"

extern u16 gUnk_02000DD0; /* 0x02000DD0 */

void sub_08000430(void)
{
    gUnk_02000DD0 &= 0xFFFE;
}
