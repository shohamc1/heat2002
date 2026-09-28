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
#include "data.h"
struct EntEFA0 {
    u8 f0;
    u8 f1;
    s8 f2;
    u8 f3;
};
/* gLinkPlayerSlots is u8[] in variables.h; the wrapper keeps the array
   subscript expansion for the order-sensitive uses below. */
struct LinkLobbySlots {
    struct EntEFA0 r[4];
};
extern u8 gText_EmptySlot[];
#include "m4a.h"
extern u16 gUnk_020020B8;


s32 UpdateLinkLobby(void)
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

void DrawLinkLobby(void)
{
    u8 unused[0x28];
    u8 i;
    u8 flag;
    s8 v;

    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0xC4);
    ((void (*)(void))DrawBigText)();
    for (i = 0; i != 4; i++) {
        flag = ((struct LinkLobbySlots *)gLinkPlayerSlots)->r[i].f2 != -1;
        DrawText(GetString(i + 0x53), 1, 2 * i + 7, flag);
        v = ((struct LinkLobbySlots *)gLinkPlayerSlots)->r[i].f2;
        if (v == 0) {
            DrawText(GetString(0x58), 0x14, 2 * i + 7, flag);
        } else if (v == 1) {
            DrawText(GetString(0x57), 0x14, 2 * i + 7, flag);
        } else {
            DrawText(gText_EmptySlot, 0x14, 2 * i + 7, flag);
        }
    }
}

u8 LinkLobby(void)
{
    u8 buf[0x200];
    u8 v;
    u8 sel;
    s8 r;

    v = 0;
    sel = 0x40;
    ResetLinkState();
    ZeroTextLayer();
    LoadMenuBackdrop();
    BuildScreenPalette((u32)gMenuPalette, (u16 *)buf);
    /* DrawLinkLobby: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8))DrawLinkLobby)(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    gUnk_020020B8 = v;
    do
    {
        ReadKeys();
        ((void (*)(u8))DrawLinkLobby)(v);
        r = UpdateLinkLobby();
        switch (r)
        {
        case 1:
            sel = 1;
            break;
        case -1:
            sel = 0;
            break;
        }
        if (gKeysPressed & 2)
            sel = 0;
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
