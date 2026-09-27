#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18[];


void sub_08013684(u8 a)
{
    u8 b = a;
    u32 v;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x00);
    ((void (*)(void))sub_080065A8)();
    v = GetString(0x01);
    DrawTextCenteredHighlight((u8 *)v, 6, a == 0);
    v = GetString(0x02);
    DrawTextCenteredHighlight((u8 *)v, 8, a == 1);
    v = GetString(0x03);
    DrawTextCenteredHighlight((u8 *)v, 0xA, a == 2);
    v = GetString(0x08);
    DrawTextCenteredHighlight((u8 *)v, 0xC, b == 3);
}
