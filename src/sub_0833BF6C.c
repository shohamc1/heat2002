#include "global.h"
#include "gba/io_reg.h"

void sub_0833BF6C(void)
{
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON;
}
