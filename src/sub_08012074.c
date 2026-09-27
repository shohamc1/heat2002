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
extern u8 gUnk_0829F32C[];

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
    ed = &gUnk_0202ED78[0];
    t = ((((*(u32 *)REG_ADDR_SIOCNT << 26) >> 30) + 1) << 12) | 0x100;
    t |= (*(u8 *)&gKeysHeld);
    z = 0;
    *ed = t;
    SioSendWord(*ed);
    ((struct EFA0s4 *)gUnk_0202EFA0)->r[0].unk2 |= 0xFF;
    ((struct EFA0s4 *)gUnk_0202EFA0)->r[1].unk2 |= 0xFF;
    ((struct EFA0s4 *)gUnk_0202EFA0)->r[2].unk2 |= 0xFF;
    ((struct EFA0s4 *)gUnk_0202EFA0)->r[3].unk2 |= 0xFF;
    gUnk_0202EEF4 = z;
    i = 0;
    do {
        buf[i] = *(u16 *)((u8 *)gUnk_0202EF40 + i * 8);
        i++;
    } while (i < 4);
    if (((buf[0] >> 8) & 0xF) == 1) {
        if ((buf[0] >> 12) == 1) {
            ((struct EFA0s4 *)gUnk_0202EFA0)->r[0].unk2 = buf[0] >> 12;
            gUnk_0202EEF4++;
            if ((buf[1] >> 12) == 2) {
                ((struct EFA0s4 *)gUnk_0202EFA0)->r[1].unk2 = buf[0] >> 12;
                gUnk_0202EEF4++;
                if ((buf[2] >> 12) == 3) {
                    ((struct EFA0s4 *)gUnk_0202EFA0)->r[2].unk2 = buf[0] >> 12;
                    gUnk_0202EEF4++;
                    if ((buf[3] >> 12) == 4) {
                        ((struct EFA0s4 *)gUnk_0202EFA0)->r[3].unk2 = buf[0] >> 12;
                        gUnk_0202EEF4++;
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
        if (gUnk_0202EEF4 > 1 && gUnk_0202EEF4 == count)
            DrawTextCenteredHighlight((u8 *)GetString(0xF), 0xF, 1);
        else
            DrawTextCenteredHighlight(gUnk_0829F32C, 0xF, 1);
    }
    if (*(u16 *)gUnk_0202EF40 == 0x1108 && gUnk_0202EEF4 > 1 && gUnk_0202EEF4 == count)
        return 1;
    return 0;
}
