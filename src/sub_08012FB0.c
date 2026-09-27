#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08012FB0(void)
{
    /* sub_08006734: this file's old prototype takes an argument the matched definition drops; call
       through a function pointer with the old signature. */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x23);
    ((void (*)(void))sub_080065A8)();
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 7, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 8, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 9, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 0xA, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 0xB, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 0xC, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 0xD, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 0xE, 1);
}
