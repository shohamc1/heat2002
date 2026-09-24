#include "global.h"

extern volatile u16 gUnk_02000DD0; /* 0x02000DD0 */

void ClearVBlankFlag(void)
{
    gUnk_02000DD0 &= 0xFFFE;
}
