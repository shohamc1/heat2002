#include "global.h"
#include "functions.h"
#include "gba/io_reg.h"

void ModuleEnableRaceDisplay(void)
{ REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON; }
