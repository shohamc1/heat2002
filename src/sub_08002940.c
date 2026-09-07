#include "global.h"

void sub_08002940(void)
{
    *(volatile u16 *)0x04000000 = 0xEA << 5;
}
