#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

extern u16 gUnk_0202EF40[];
extern s8 gUnk_0202EF8C;
extern u8 gUnk_083FDE78[];

u8 LinkTrackSelect(void)
{
    u8 buf[0x200];
    s32 sel;
    u16 k;
    u16 prev;

    ResetLinkState();
    gUnk_0202EF40[0] = 0;
    gUnk_0202EF40[4] = 0;
    gUnk_0202EF40[8] = 0;
    gUnk_0202EF40[12] = 0;
    WaitForVBlank();
    sub_080045D8();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    sub_080047DC();
    gUnk_020020C0 = 0;
    WaitForVBlank();
    ZeroTextLayer();
    sub_0800F4FC();
    sub_0800F328((u32)gUnk_082E4328, (u16 *)buf);
    DrawTrackSelect(0, 1);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    gUnk_0202EF8C = 0;
    prev = 0;
    do {
        ClearOamBuffer();
        AgeGfxCaches();
        k = gUnk_020020A0[0];
        if (ExchangeLinkInput() != 0) {
            sel = 3;
            continue;
        }
        k = (k ^ gUnk_020020A0[0]) & gUnk_020020A0[0];
        if (k & DPAD_RIGHT) {
            gUnk_0202EF8C++;
            if (gUnk_0202EF8C == 7)
                gUnk_0202EF8C = 8;
            if (gUnk_0202EF8C > 0x0B)
                gUnk_0202EF8C = 0x0B;
        }
        if (k & DPAD_LEFT) {
            gUnk_0202EF8C--;
            if (gUnk_0202EF8C == 7)
                gUnk_0202EF8C = 6;
            if (gUnk_0202EF8C == -1)
                gUnk_0202EF8C = 0;
        }
        if (gUnk_0202EF8C != prev) {
            m4aSongNumStart(8);
            prev = gUnk_0202EF8C;
        }
        WaitForVBlank();
        if (gLinkPlayerId[0] == 0)
/* old prototype u8 DrawTrackSelect(s8, u8): the s8 parameter keeps the
             sign-extending ldrsb of gUnk_0202EF8C */
            ((u8 (*)(s8, u8))DrawTrackSelect)((s8)gUnk_0202EF8C, 1);
        else
            ((u8 (*)(s8, u8))DrawTrackSelect)((s8)gUnk_0202EF8C, 1);
        if (k & A_BUTTON) {
            m4aSongNumStart(9);
            gUnk_0202EF8C = gUnk_083FDE78[gUnk_0202EF8C];
            sel = 1;
        }
        if (k & B_BUTTON)
            sel = 2;
        sub_080047DC();
        gUnk_020020C0 = 0;
    spin:
        if (gUnk_020020C0 == 0)
            goto spin;
        WaitForVBlank();
    } while (sel == 0x40);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    if (sel == 2)
        return 0;
    if (sel == 3)
        return 2;
    return 1;
}
