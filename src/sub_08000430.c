#include "global.h"

extern u16 gUnk_02000DD0; /* 0x02000DD0 */

void ClearVBlankFlag(void)
{
    *(vu16 *)&gUnk_02000DD0 &= 0xFFFE;
}
