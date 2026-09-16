#include "global.h"
#include "gba/io_reg.h"

void sub_08002940(void)
{
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON;
}
