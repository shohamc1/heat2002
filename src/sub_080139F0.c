#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18[];


void sub_080139F0(void)
{
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x30);
    ((void (*)(void))sub_080065A8)();
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 7, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 8, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 9, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 10, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 11, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 12, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 13, 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x11)), 14, 1);
}
