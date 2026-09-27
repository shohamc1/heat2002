#include "global.h"
#include "gba/io_reg.h"
#include "variables.h"


void sub_083448F4(void)
{
    if ((REG_SIOCNT & 0x40) == 0) {
        gModule_LinkRecvWords[0] = REG_SIOMULTI0;
        gModule_LinkRecvWords[4] = REG_SIOMULTI1;
        gModule_LinkRecvWords[8] = REG_SIOMULTI2;
        gModule_LinkRecvWords[12] = REG_SIOMULTI3;
    } else {
        gModule_LinkRecvWords[0] = 0;
        gModule_LinkRecvWords[4] = 0;
        gModule_LinkRecvWords[8] = 0;
        gModule_LinkRecvWords[12] = 0;
    }
    REG_IME = 0;
    gIntrCheck |= 0x80;
    REG_IME = 1;
}
