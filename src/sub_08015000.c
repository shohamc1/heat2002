#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08015000(u8 a)
{
    u32 v;
    u8 b;

    b = a;
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x0A);
    ((void (*)(void))sub_080065A8)();
    v = GetString(0x05);
    DrawTextCenteredHighlight((u8 *)v, 7, a == 0);
    v = GetString(0x07);
    DrawTextCenteredHighlight((u8 *)v, 9, a == 1);
    v = GetString(0x08);
    DrawTextCenteredHighlight((u8 *)v, 0xB, b == 2);
}
