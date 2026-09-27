#include "global.h"
#include "functions.h"

extern u8 gUnk_020253C4;

extern u8 gUnk_0806C714[];
extern u8 gUnk_0806C720[];
extern u8 gUnk_0806C72C[];
extern u8 gUnk_0806C738[];


void sub_080051E4(void)
{
    /* DrawTextCentered: the ROM callers pass a third argument the matched definition drops; call
       through a function pointer with the old prototype. */
    ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x96), 8, 1);
    switch (gUnk_020253C4) {
    case 0:
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C714, 9, 1);
        break;
    case 1:
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C720, 9, 1);
        break;
    case 2:
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C72C, 9, 1);
        break;
    case 3:
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C738, 9, 1);
        break;
    }
}
