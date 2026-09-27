#include "global.h"
#include "gba/io_reg.h"
#include "variables.h"


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
