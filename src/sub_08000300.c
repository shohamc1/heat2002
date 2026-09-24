#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"

void ClearPalette(void)
{
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
}
