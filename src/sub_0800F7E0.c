#include "global.h"
#include "gba/io_reg.h"

void sub_0800F7E0(void)
{
    volatile u16 *ie;

    REG_RCNT = 0;
    REG_SIOCNT = 0x6003;
    REG_IME = 0;
    REG_IE = REG_IE | 0x80;
    REG_IME = 1;
}
