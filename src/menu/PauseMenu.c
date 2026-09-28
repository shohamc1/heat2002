#include "global.h"
#include "functions.h"
#include "variables.h"


u8 PauseConfirmMenu(void)
{
    u8 unused[0x200];
    u16 startMask;
    u32 aMask;
    gPauseMenuCursor = 0;
    ReadKeys();
    while (1) {

    if (gKeysPressed & 0xC0)
        gPauseMenuCursor ^= 1;
    startMask = gKeysPressed & 8;
    if (startMask != 0) {
        gMenuBlinkCounter = 0;
        DrawPauseConfirmMenu(3);
        return 0;
    }
    aMask = gKeysPressed & 1;
    if (aMask != 0) {
        gMenuBlinkCounter = startMask;
        DrawPauseConfirmMenu(3);
        return gPauseMenuCursor + 1;
    }
    if (gKeysPressed & 2) {
        gMenuBlinkCounter = aMask;
        DrawPauseConfirmMenu(3);
        gPauseMenuCursor = aMask;
        return 1;
    }
    DrawPauseConfirmMenu(gPauseMenuCursor);
    WaitForVBlank();
        gMenuBlinkCounter++;
        ReadKeys();
    }
}


u8 PauseMenu(void)
{
    u8 unused[0x200];
    u16 *kp;
    u8 *p248;
    u8 *p39c;
    register u16 k asm("r1");
    u16 t;
    u8 bit1;
    u8 *p248b;

    gPauseMenuCursor = 0;
    if (gKeysPressed & 8) {
        ClearPitMenu();
        ClearPauseMenuBox();
        StopAllSongs();
        ReadKeys();
        kp = &gKeysPressed;
        p248 = &gPauseMenuCursor;
        p39c = &gMenuBlinkCounter;
        while (1) {
            if (*kp & 0xC0)
                *p248 ^= 1;
            k = *(volatile u16 *)kp;
            t = k & 8;
            if (t != 0) {
                *p39c = 0;
                DrawPauseMenu(3);
                ClearPauseMenuBox();
                return 1;
            }
            bit1 = k & 1;
            if (bit1 != 0) {
                *p39c = t;
                DrawPauseMenu(3);
                p248b = &gPauseMenuCursor;
                if (*p248b != 0)
                    PauseConfirmMenu();
                ClearPauseMenuBox();
                return (u8)(*p248b + 1);
            }
            if (k & 2) {
                *p39c = bit1;
                DrawPauseMenu(3);
                *p248 = bit1;
                ClearPauseMenuBox();
                return (u8)(*p248 + 1);
            }
            DrawPauseMenu(*p248);
            WaitForVBlank();
            *p39c = (u8)(*p39c + 1);
            ReadKeys();
        }
    }
    return 0;
}

