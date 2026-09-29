#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gText_Player1[];
extern u8 gText_Player2[];
extern u8 gText_Player3[];
extern u8 gText_Player4[];
#include "data.h"
#include "m4a.h"
void m4aSoundVSyncOff(void);
void ClearPausedPlayerText(void);
void DrawPausedPlayerText(void);

u8 LinkPauseConfirmMenu(void)
{
    u8 unused[0x200];
    u8 *cursor;
    u8 *blink;
    register u16 keys asm("r1");
    u16 startMask;
    u16 bMask;
    u8 bit1;
    s32 linkState;

    gPauseMenuCursor = 0;
    ReadKeys();
    ReadLinkMenuKeys();
    cursor = &gPauseMenuCursor;
    blink = &gMenuBlinkCounter;
    while ((linkState = ExchangeLinkInput()) == 0) {
        ReadLinkMenuKeys();
        if (gLinkMenuKeysPressed & 0xC0)
            *cursor ^= 1;
        keys = *(volatile u16 *)&gLinkMenuKeysPressed;
        startMask = keys & 8;
        if (startMask != 0) {
            *blink = linkState;
            DrawPauseConfirmMenu(3);
            return 0;
        }
        bit1 = keys & 1;
        if (bit1 != 0) {
            *blink = startMask;
            DrawPauseConfirmMenu(3);
            return (u8)(*cursor + 1);
        }
        bMask = keys & 2;
        if (bMask != 0) {
            *blink = bit1;
            DrawPauseConfirmMenu(3);
            *cursor = bit1;
            return 1;
        }
        DrawPauseConfirmMenu(*cursor);
        gVBlankWorkDone = bMask;
    spin:
        if (gVBlankWorkDone == 0)
            goto spin;
        *blink = (u8)(*blink + 1);
        ReadKeys();
    }
}

u8 LinkPauseMenu(void)
{
    u8 unused[0x200];
    u8 *cursor;
    u8 *blink;
    u16 startMask;
    u32 aMask;
    u16 bMask;
    u32 linkState;

    gLinkMenuPlayerIndex = 0xFF;
    gPauseMenuCursor = 0;
    ReadLinkMenuKeys();
    if ((gLinkMenuKeysPressed & 8) != 0) {
        StopAllSongs();
        cursor = &gPauseMenuCursor;
        blink = &gMenuBlinkCounter;
        while ((linkState = ExchangeLinkInput()) == 0) {
            ReadLinkMenuKeys();
            if ((gLinkMenuKeysPressed & 0xC0) != 0)
                *cursor ^= 1;
            startMask = gLinkMenuKeysPressed & 8;
            if (startMask != 0) {
                *blink = linkState;
                DrawPauseMenu(3);
                return 1;
            }
            aMask = gLinkMenuKeysPressed & 1;
            if (aMask != 0) {
                *blink = startMask;
                DrawPauseMenu(3);
                if (gPauseMenuCursor != 0)
                    LinkPauseConfirmMenu();
                return (u8)(gPauseMenuCursor + 1);
            }
            bMask = gLinkMenuKeysPressed & 2;
            if (bMask != 0) {
                *blink = aMask;
                DrawPauseMenu(3);
                *cursor = aMask;
                return 1;
            }
            DrawPauseMenu(*cursor);
            *blink = *blink + 1;
            gVBlankWorkDone = bMask;
        poll:
            if (gVBlankWorkDone == 0)
                goto poll;
        }
    }
    return 0;
}

void DrawPausedPlayerText(void)
{
    /* DrawTextCentered: the ROM callers pass a third argument the matched definition drops; call
       through a function pointer with the old prototype. */
    ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x96), 8, 1);
    switch (gLinkMenuPlayerIndex) {
        case 0:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_Player1, 9, 1);
            break;
        case 1:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_Player2, 9, 1);
            break;
        case 2:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_Player3, 9, 1);
            break;
        case 3:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_Player4, 9, 1);
            break;
    }
}

void ClearPausedPlayerText(void)
{
    u8 col;

    for (col = 0; col != 0x1B; col++) {
        u16 *map = (u16 *)(*(volatile u32 *)&gTextLayerMapPtr[0]);
        map[col + 0x100] = 0x47;
        map[col + 0x120] = 0x47;
    }
}

u8 SinglePakPauseMenu(void)
{
    u8 unused[0x200];
    u8 done;
    u16 startMask;
    u32 playerId;

    gLinkMenuPlayerIndex = 0xFF;
    ReadLinkMenuKeys();
    if (gLinkMenuKeysPressed & 8) {
        StopAllSongs();
        {
            volatile u8 *vblankFlag = &gVBlankWorkDone;

            while (1) {
                gVBlankCounter = 0;
                if (ExchangeLinkInput() != 0) {
                    m4aSoundVSyncOff();
                    done = 0;
                    do {
                        playerId = gLinkPlayerId[0];
                        if (playerId == 0)
                            return 0x27;
                        /* VBlankIntrWait: this file's old local prototype differs from
                           functions.h; call through the old signature (solved-walls 31). */
                        ((void (*)(u32))VBlankIntrWait)(playerId);
                    } while (done == 0);
                }
                ReadLinkMenuKeys();
                startMask = gLinkMenuKeysPressed & 8;
                if (startMask != 0) {
                    ClearPausedPlayerText();
                    return 1;
                }
                DrawPausedPlayerText();
                gFrameCounter++;
                *vblankFlag = startMask;
            poll:
                if (*vblankFlag == 0)
                    goto poll;
            }
        }
    }
    return 0;
}
