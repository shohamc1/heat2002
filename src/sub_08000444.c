#include "global.h"
#include "variables.h"


void AckVBlank(void)
{
    *(volatile u16 *)0x04000202 = 1;
    gUnk_02000DD0 = 1;
}
