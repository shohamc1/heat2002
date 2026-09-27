#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18[];


void sub_080115D8(u8 a)
{
    u8 b = a;
    u32 v;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x5A);
    ((void (*)(void))sub_080065A8)();
    v = GetString(0x05);
    DrawTextCenteredHighlight((u8 *)v, 7, a == 0);
    v = GetString(0x06);
    DrawTextCenteredHighlight((u8 *)v, 9, a == 1);
    v = GetString(0x07);
    DrawTextCenteredHighlight((u8 *)v, 0xB, a == 2);
    v = GetString(0x08);
    DrawTextCenteredHighlight((u8 *)v, 0xD, b == 3);
}
