#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"

void sub_08000224(void)
{
    DmaFill32(3, 0, EWRAM_START, 0x40000);
    DmaFill32(3, 0, IWRAM_START, 0x7E00);
}
