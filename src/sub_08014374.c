#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18[];


void sub_08014374(void)
{
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    sub_080065A8((u8 *)(GetString(0x12)));
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 7, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 8, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 9, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xA, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xB, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xC, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xD, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xE, 1);
}
