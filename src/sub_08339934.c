#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"

void sub_08339934(void)
{
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
}
