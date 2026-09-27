#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"


extern u8 gText_BlankRowPauseConfirm[];


void sub_08004D1C(u8 arg)
{
    u8 r4 = arg;

    if (r4 != 3) {
        /* DrawTextCentered: the ROM callers pass a third argument the matched definition drops; call
           through a function pointer with the old prototype. */
        ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x66), 6, 1);
    } else {
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_BlankRowPauseConfirm, 6, 1);
    }
    if (r4 == 1 || (gMenuBlinkCounter & 8)) {
        ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x68), 8, 1);
    } else {
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_BlankRowPauseMenu, 8, 1);
    }
    if (r4 == 0 || (gMenuBlinkCounter & 8)) {
        ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x67), 0xA, 1);
    } else {
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_BlankRowPauseMenu, 0xA, 1);
    }
}
