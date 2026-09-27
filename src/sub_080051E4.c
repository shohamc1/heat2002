#include "global.h"
#include "functions.h"
#include "variables.h"


extern u8 gText_Player1[];
extern u8 gText_Player2[];
extern u8 gText_Player3[];
extern u8 gText_Player4[];


void sub_080051E4(void)
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
