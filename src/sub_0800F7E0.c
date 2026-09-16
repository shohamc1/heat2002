#include "global.h"
#include "gba/io_reg.h"

void sub_0800F7E0(void)
{
    volatile u16 *ie;

    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE | SIO_INTR_ENABLE | 3;
    REG_IME = 0;
    REG_IE = REG_IE | INTR_FLAG_SERIAL;
    REG_IME = 1;
}
