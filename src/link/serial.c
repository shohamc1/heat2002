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

void SerialIntr(void)
{
    if ((REG_SIOCNT & 0x40) == 0) {
        gLinkRecvWords[0] = REG_SIOMULTI0;
        gLinkRecvWords[4] = REG_SIOMULTI1;
        gLinkRecvWords[8] = REG_SIOMULTI2;
        gLinkRecvWords[12] = REG_SIOMULTI3;
    } else {
        gLinkRecvWords[0] = 0;
        gLinkRecvWords[4] = 0;
        gLinkRecvWords[8] = 0;
        gLinkRecvWords[12] = 0;
    }
    REG_IME = 0;
    gIntrCheck |= 0x80;
    REG_IME = 1;
}
