#include "global.h"
#include "gba/io_reg.h"

void sub_08344878(void)
{
    REG_RCNT = 0;
    REG_SIOCNT = 0x6003;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = 1;
}
