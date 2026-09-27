#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "variables.h"

void SioSendWord(u16 data)
{
    REG_SIODATA8 = data;
    REG_IME = 0;
    INTR_CHECK &= 0xFF7F;
    REG_IME = 1;
    if ((*(u8 *)REG_ADDR_SIOCNT & 0x30) == 0)
        REG_SIOCNT |= SIO_START;
}
