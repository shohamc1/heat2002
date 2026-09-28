#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

struct UnkEFA0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};
struct EFA0s4 {
    struct UnkEFA0 r[4];
};
extern u8 gText_BlankRowLinkLobby[];

s32 sub_08012074(void)
{
    u8 unused[0x14];
    u16 buf[4];
    u8 count;
    u8 i;
    u8 z;
    u16 t;
    volatile u16 *ed;

    if ((*(u8 *)REG_ADDR_SIOCNT & 0x30) == 0) {
        VBlankIntrWait();
    } else {
        do {
            ReadKeys();
            if (gKeysPressed & 2)
                return -1;
        } while ((INTR_CHECK & 0x80) == 0);
    }
    ReadKeys();
    ed = &gLinkSendWords[0];
    t = ((((*(u32 *)REG_ADDR_SIOCNT << 26) >> 30) + 1) << 12) | 0x100;
    t |= (*(u8 *)&gKeysHeld);
    z = 0;
    *ed = t;
    SioSendWord(*ed);
    ((struct EFA0s4 *)gLinkPlayerSlots)->r[0].unk2 |= 0xFF;
    ((struct EFA0s4 *)gLinkPlayerSlots)->r[1].unk2 |= 0xFF;
    ((struct EFA0s4 *)gLinkPlayerSlots)->r[2].unk2 |= 0xFF;
    ((struct EFA0s4 *)gLinkPlayerSlots)->r[3].unk2 |= 0xFF;
    gLinkPlayerCount = z;
    i = 0;
    do {
        buf[i] = *(u16 *)((u8 *)gLinkRecvWords + i * 8);
        i++;
    } while (i < 4);
    if (((buf[0] >> 8) & 0xF) == 1) {
        if ((buf[0] >> 12) == 1) {
            ((struct EFA0s4 *)gLinkPlayerSlots)->r[0].unk2 = buf[0] >> 12;
            gLinkPlayerCount++;
            if ((buf[1] >> 12) == 2) {
                ((struct EFA0s4 *)gLinkPlayerSlots)->r[1].unk2 = buf[0] >> 12;
                gLinkPlayerCount++;
                if ((buf[2] >> 12) == 3) {
                    ((struct EFA0s4 *)gLinkPlayerSlots)->r[2].unk2 = buf[0] >> 12;
                    gLinkPlayerCount++;
                    if ((buf[3] >> 12) == 4) {
                        ((struct EFA0s4 *)gLinkPlayerSlots)->r[3].unk2 = buf[0] >> 12;
                        gLinkPlayerCount++;
                    }
                }
            }
        }
    }
    count = 0;
    i = 0;
    do {
        if ((buf[i] >> 12) == i + 1 && ((buf[i] >> 8) & 0xF) == 1)
            count++;
        i++;
    } while (i < 4);
    gLinkPlayerId[0] = (*(u32 *)REG_ADDR_SIOCNT << 26) >> 30;
    if ((*(u8 *)REG_ADDR_SIOCNT & 0x30) == 0) {
        if (gLinkPlayerCount > 1 && gLinkPlayerCount == count)
            DrawTextCenteredHighlight(GetString(0xF), 0xF, 1);
        else
            DrawTextCenteredHighlight(gText_BlankRowLinkLobby, 0xF, 1);
    }
    if (*(u16 *)gLinkRecvWords == 0x1108 && gLinkPlayerCount > 1 && gLinkPlayerCount == count)
        return 1;
    return 0;
}
