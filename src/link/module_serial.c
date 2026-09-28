#include "global.h"
#include "gba/io_reg.h"

#include "variables.h"


void ModuleInitMultiplayerSio(void)
{
    REG_RCNT = 0;
    REG_SIOCNT = 0x6003;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = 1;
}


void ModuleSioSendWord(u16 data)
{
    REG_SIODATA8 = data;
    REG_IME = 0;
    gIntrCheck = gIntrCheck & 0xFF7F;
    REG_IME = 1;
    if ((*(u8 *)0x04000128 & 0x30) == 0)
        REG_SIOCNT |= 0x80;
}


void ModuleSerialIntr(void)
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

