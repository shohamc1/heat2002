#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"


extern u8 gUnk_0806C6B0[];
extern u8 gUnk_0806C6BC[];
extern u8 gUnk_0806C6C8[];
extern u8 gUnk_0806C6D4[];
extern u8 gUnk_0806C6E0[];


void sub_08004C44(u8 arg)
{
    u8 r4 = arg;

    if (gIsLinkRace != 0) {
        switch (gUnk_020253C4) {
        case 0:
            /* DrawTextCentered: the ROM callers pass a third argument the matched definition drops; call
               through a function pointer with the old prototype. */
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C6B0, 6, 1);
            break;
        case 1:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C6BC, 6, 1);
            break;
        case 2:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C6C8, 6, 1);
            break;
        case 3:
            ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C6D4, 6, 1);
            break;
        }
    } else {
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C6E0, 6, 1);
    }
    if (r4 == 1 || (gUnk_0202539C & 8)) {
        ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x81), 8, 1);
    } else {
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C6E8, 8, 1);
    }
    if (r4 == 0 || (gUnk_0202539C & 8)) {
        ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x80), 0xA, 1);
    } else {
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gUnk_0806C6E8, 0xA, 1);
    }
}
