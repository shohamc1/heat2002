#include "global.h"
#include "functions.h"
#include "variables.h"



u8 sub_08004EA4(void)
{
    u8 unused[0x200];
    u16 v;
    u32 w;
    gPauseMenuCursor = 0;
    ReadKeys();
    while (1) {

    if (gKeysPressed & 0xC0)
        gPauseMenuCursor ^= 1;
    v = gKeysPressed & 8;
    if (v != 0) {
        gMenuBlinkCounter = 0;
        DrawPauseConfirmMenu(3);
        return 0;
    }
    w = gKeysPressed & 1;
    if (w != 0) {
        gMenuBlinkCounter = v;
        DrawPauseConfirmMenu(3);
        return gPauseMenuCursor + 1;
    }
    if (gKeysPressed & 2) {
        gMenuBlinkCounter = w;
        DrawPauseConfirmMenu(3);
        gPauseMenuCursor = w;
        return 1;
    }
    DrawPauseConfirmMenu(gPauseMenuCursor);
    WaitForVBlank();
        gMenuBlinkCounter++;
        ReadKeys();
    }
}
