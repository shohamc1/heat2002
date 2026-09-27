#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18[];


void sub_08013908(u8 a)
{
    u8 v;

    v = a;
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x60);
    ((void (*)(void))sub_080065A8)();
    if (a == 0)
        DrawTextCenteredHighlight((u8 *)(GetString(0x63)), 9, 1);
    if (a == 1)
        DrawTextCenteredHighlight((u8 *)(GetString(0x61)), 9, 1);
    if (v == 2)
        DrawTextCenteredHighlight((u8 *)(GetString(0x62)), 9, 1);
}
