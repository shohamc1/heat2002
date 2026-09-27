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
    ed = gLinkSendWords;
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
              | ((*(edd0 = &gLinkSyncByte) + 1) & 0xFF);
        SioSendWord(ed[0]);
        gLinkPlayerSlots[2] |= 0xFF;
        gLinkPlayerSlots[6] |= 0xFF;
        gLinkPlayerSlots[10] |= 0xFF;
        gLinkPlayerSlots[14] |= 0xFF;
        gLinkPlayerCount = 0;
        v = gLinkRecvWords[0];
        if ((v >> 12) == 1) {
            gLinkPlayerSlots[2] = 1;
            gLinkPlayerCount = 1;
            if (*(u8 *)REG_ADDR_SIOCNT & 0x30)
                *edd0 = v - 1;
            if ((gLinkRecvWords[4] >> 12) == 2) {
                gLinkPlayerSlots[6] = 1;
                gLinkPlayerCount = 2;
                if ((gLinkRecvWords[8] >> 12) == 3) {
                    gLinkPlayerSlots[10] = 1;
                    gLinkPlayerCount = 3;
                    if ((gLinkRecvWords[12] >> 12) == 4) {
                        gLinkPlayerSlots[14] = 1;
                        gLinkPlayerCount = 4;
                    }
                }
            }
        }
        *(u8 *)&gLinkPlayerId = (*(vu32 *)REG_ADDR_SIOCNT << 26) >> 30;
        *(u8 *)&gNumLinkPlayers = gLinkPlayerCount;
        if (*(u8 *)&gNumLinkPlayers <= 1)
            i--;
        gLinkRecvWords[0] = 0;
        gLinkRecvWords[4] = 0;
        gLinkRecvWords[8] = 0;
        gLinkRecvWords[12] = 0;
        i++;
    } while (i != 5);
}
