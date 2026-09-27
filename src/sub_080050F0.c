#include "global.h"
#include "functions.h"
#include "variables.h"



u8 sub_080050F0(void)
{
    u8 unused[0x200];
    u8 *sel;
    u8 *v;
    u16 a;
    u32 b;
    u16 c;
    u32 r;

    gLinkMenuPlayerIndex = 0xFF;
    gPauseMenuCursor = 0;
    sub_08004DB4();
    if ((gLinkMenuKeysPressed & 8) != 0) {
        StopAllSongs();
        sel = &gPauseMenuCursor;
        v = &gMenuBlinkCounter;
        while ((r = ExchangeLinkInput()) == 0) {
            sub_08004DB4();
            if ((gLinkMenuKeysPressed & 0xC0) != 0)
                *sel ^= 1;
            a = gLinkMenuKeysPressed & 8;
            if (a != 0) {
                *v = r;
                sub_08004C44(3);
                return 1;
            }
            b = gLinkMenuKeysPressed & 1;
            if (b != 0) {
                *v = a;
                sub_08004C44(3);
                if (gPauseMenuCursor != 0)
                    sub_08005024();
                return (u8)(gPauseMenuCursor + 1);
            }
            c = gLinkMenuKeysPressed & 2;
            if (c != 0) {
                *v = b;
                sub_08004C44(3);
                *sel = b;
                return 1;
            }
            sub_08004C44(*sel);
            *v = *v + 1;
            gVBlankWorkDone = c;
poll:
            if (gVBlankWorkDone == 0)
                goto poll;
        }
    }
    return 0;
}
