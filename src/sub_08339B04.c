#include "global.h"
#include "variables.h"


void sub_08339B04(void)
{
    *(volatile u16 *)0x04000202 = 1;
    gUnk_02037E20 = 1;
}
