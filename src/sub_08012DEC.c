#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18[];


void sub_08012DEC(u8 a)
{
    u32 v;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(8);
    ((void (*)(void))sub_080065A8)();
    v = GetString(0x66);
    DrawTextCenteredHighlight((u8 *)v, 7, 1);
    v = GetString(0x67);
    DrawTextCenteredHighlight((u8 *)v, 9, a == 0);
    v = GetString(0x68);
    DrawTextCenteredHighlight((u8 *)v, 0xB, a == 1);
}
