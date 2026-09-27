#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/syscall.h"
#include "functions.h"
#include "variables.h"



void DetectLinkPlayers(void)
{
    u8 *edd0;
    u8 i;
    u16 v;
    vu16 *ed;

    ResetLinkState();
    i = 0;
    /* Through a pointer: a store to a volatile array element by name
       compiles to a read-modify-write. */
    ed = gUnk_0202ED78;
    do {
        if ((*(u8 *)REG_ADDR_SIOCNT & 0x30) == 0)
            VBlankIntrWait();
        else
            IntrWait(1, INTR_FLAG_SERIAL);
        ReadKeys();
        /* edd0 is a variable so its pseudo predates the SIOCNT address
           temp: they tie on allocation priority, and the older one gets
           r6. */
        ed[0] = ((u16)((((*(vu32 *)REG_ADDR_SIOCNT << 26) >> 30) + 1) << 12)
                 | 0x100)
              | ((*(edd0 = &gUnk_0202EDD0) + 1) & 0xFF);
        SioSendWord(ed[0]);
        gUnk_0202EFA0[2] |= 0xFF;
        gUnk_0202EFA0[6] |= 0xFF;
        gUnk_0202EFA0[10] |= 0xFF;
        gUnk_0202EFA0[14] |= 0xFF;
        gUnk_0202EEF4 = 0;
        v = gUnk_0202EF40[0];
        if ((v >> 12) == 1) {
            gUnk_0202EFA0[2] = 1;
            gUnk_0202EEF4 = 1;
            if (*(u8 *)REG_ADDR_SIOCNT & 0x30)
                *edd0 = v - 1;
            if ((gUnk_0202EF40[4] >> 12) == 2) {
                gUnk_0202EFA0[6] = 1;
                gUnk_0202EEF4 = 2;
                if ((gUnk_0202EF40[8] >> 12) == 3) {
                    gUnk_0202EFA0[10] = 1;
                    gUnk_0202EEF4 = 3;
                    if ((gUnk_0202EF40[12] >> 12) == 4) {
                        gUnk_0202EFA0[14] = 1;
                        gUnk_0202EEF4 = 4;
                    }
                }
            }
        }
        *(u8 *)&gLinkPlayerId = (*(vu32 *)REG_ADDR_SIOCNT << 26) >> 30;
        *(u8 *)&gNumLinkPlayers = gUnk_0202EEF4;
        if (*(u8 *)&gNumLinkPlayers <= 1)
            i--;
        gUnk_0202EF40[0] = 0;
        gUnk_0202EF40[4] = 0;
        gUnk_0202EF40[8] = 0;
        gUnk_0202EF40[12] = 0;
        i++;
    } while (i != 5);
}
