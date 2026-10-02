#include "global.h"
#include "functions.h"
#include "gba/io_reg.h"
#include "variables.h"

void ModuleReadKeys(void)
{
    u16 keys = ~REG_KEYINPUT;
    *(vu16 *)&gUnk_0203761C = keys & ~*(vu16 *)&gUnk_02037618;
    *(vu16 *)&gUnk_02037618 = keys;
}
