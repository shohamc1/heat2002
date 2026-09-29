#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

extern u8 gLinkTrackSelectTrackIds[];

u8 LinkTrackSelect(void)
{
    u8 buf[0x200];
    s32 sel;
    u16 k;
    u16 prev;

    ResetLinkState();
    gLinkRecvWords[0] = 0;
    gLinkRecvWords[4] = 0;
    gLinkRecvWords[8] = 0;
    gLinkRecvWords[12] = 0;
    WaitForVBlank();
    ResetSpriteOrderTable();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    UpdateSprites();
    gVBlankWorkDone = 0;
    WaitForVBlank();
    ZeroTextLayer();
    LoadMenuBackdrop();
    BuildScreenPalette(gMenuPalette, (u16 *)buf);
    DrawTrackSelect(0, 1);
    FadeToBrightenedPalette(buf, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    gTrackSelectCursor = 0;
    prev = 0;
    do {
        ClearOamBuffer();
        AgeGfxCaches();
        k = gPlayerKeys[0];
        if (ExchangeLinkInput() != 0) {
            sel = 3;
            continue;
        }
        k = (k ^ gPlayerKeys[0]) & gPlayerKeys[0];
        if (k & DPAD_RIGHT) {
            gTrackSelectCursor++;
            if (gTrackSelectCursor == 7)
                gTrackSelectCursor = 8;
            if (gTrackSelectCursor > 0x0B)
                gTrackSelectCursor = 0x0B;
        }
        if (k & DPAD_LEFT) {
            gTrackSelectCursor--;
            if (gTrackSelectCursor == 7)
                gTrackSelectCursor = 6;
            if (gTrackSelectCursor == -1)
                gTrackSelectCursor = 0;
        }
        if (gTrackSelectCursor != prev) {
            m4aSongNumStart(8);
            prev = gTrackSelectCursor;
        }
        WaitForVBlank();
        if (gLinkPlayerId[0] == 0)
            /* old prototype u8 DrawTrackSelect(s8, u8): the s8 parameter keeps the
                         sign-extending ldrsb of gTrackSelectCursor */
            ((u8 (*)(s8, u8))DrawTrackSelect)(gTrackSelectCursor, 1);
        else
            ((u8 (*)(s8, u8))DrawTrackSelect)(gTrackSelectCursor, 1);
        if (k & A_BUTTON) {
            m4aSongNumStart(9);
            gTrackSelectCursor = gLinkTrackSelectTrackIds[gTrackSelectCursor];
            sel = 1;
        }
        if (k & B_BUTTON)
            sel = 2;
        UpdateSprites();
        gVBlankWorkDone = 0;
    spin:
        if (gVBlankWorkDone == 0)
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
