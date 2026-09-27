#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"


extern u8 gText_P1Paused[];
extern u8 gText_P2Paused[];
extern u8 gText_P3Paused[];
extern u8 gText_P4Paused[];
extern u8 gText_Paused[];


void sub_08004C44(u8 arg)
{
    u8 r4 = arg;

    if (gIsLinkRace != 0) {
        switch (gLinkMenuPlayerIndex) {
        case 0:
            /* DrawTextCentered: the ROM callers pass a third argument the matched definition drops; call
               through a function pointer with the old prototype. */
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_P1Paused, 6, 1);
            break;
        case 1:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_P2Paused, 6, 1);
            break;
        case 2:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_P3Paused, 6, 1);
            break;
        case 3:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_P4Paused, 6, 1);
            break;
        }
    } else {
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_Paused, 6, 1);
    }
    if (r4 == 1 || (gMenuBlinkCounter & 8)) {
        ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x81), 8, 1);
    } else {
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_BlankRowPauseMenu, 8, 1);
    }
    if (r4 == 0 || (gMenuBlinkCounter & 8)) {
        ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x80), 0xA, 1);
    } else {
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_BlankRowPauseMenu, 0xA, 1);
    }
}
