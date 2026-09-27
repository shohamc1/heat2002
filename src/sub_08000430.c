#include "global.h"
#include "variables.h"


void ClearVBlankFlag(void)
{
    *(vu16 *)&gUnk_02000DD0 &= 0xFFFE;
}
