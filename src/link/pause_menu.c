#include "global.h"
#include "functions.h"
#include "variables.h"
#include "data.h"
#include "m4a.h"

extern u8 gText_Player1[];
extern u8 gText_Player2[];
extern u8 gText_Player3[];
extern u8 gText_Player4[];
void ClearPausedPlayerText(void);
void DrawPausedPlayerText(void);

u8 LinkPauseConfirmMenu(void)
{
    u8 unused[0x200];
    u8 *cursor;
    u8 *blink;
    register u16 keys PIN(r1);
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
#if PORTABLE
        /* The GBA's VBlank interrupt arrives from hardware mid-spin; the
           hosted build dispatches it only from the frame pump, so pump
           one VBlank here - the same instant the hardware would. */
        if (gVBlankWorkDone == 0)
        {
            VBlankIntrWait();
            goto spin;
        }
#else
        if (gVBlankWorkDone == 0)
            goto spin;
#endif
        *blink = (u8)(*blink + 1);
        ReadKeys();
    }
#if PORTABLE
    /* The ROM falls off the end with linkState still in r0. */
    return linkState;
#endif
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
#if PORTABLE
        /* The GBA's VBlank interrupt arrives from hardware mid-spin; the
           hosted build dispatches it only from the frame pump, so pump
           one VBlank here - the same instant the hardware would. */
        if (gVBlankWorkDone == 0)
        {
            VBlankIntrWait();
            goto poll;
        }
#else
        if (gVBlankWorkDone == 0)
            goto poll;
#endif
        }
    }
    return 0;
}

void DrawPausedPlayerText(void)
{
    DrawTextCentered(GetString(150), 8, 1);
    switch (gLinkMenuPlayerIndex) {
        case 0:
            DrawTextCentered(gText_Player1, 9, 1);
            break;
        case 1:
            DrawTextCentered(gText_Player2, 9, 1);
            break;
        case 2:
            DrawTextCentered(gText_Player3, 9, 1);
            break;
        case 3:
            DrawTextCentered(gText_Player4, 9, 1);
            break;
    }
}

void ClearPausedPlayerText(void)
{
    u8 col;

    for (col = 0; col != 27; col++) {
#if PORTABLE
        u16 *map = (u16 *)(*(u8 *volatile *)&gTextLayerMapPtr[0]);
#else
        u16 *map = (u16 *)(*(volatile u32 *)&gTextLayerMapPtr[0]);
#endif
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
                        playerId = gLinkPlayerId;
                        if (playerId == 0)
                            return 0x27;
                        /* The ROM passes playerId in r0, which VBlankIntrWait
                           ignores. */
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
