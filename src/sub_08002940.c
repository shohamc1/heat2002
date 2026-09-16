#include "global.h"
#include "gba/io_reg.h"

void sub_08002940(void)
{
    REG_DISPCNT = 0xEA << 5;
}
