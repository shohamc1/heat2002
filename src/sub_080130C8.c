#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18;


void sub_080130C8(u8 a)
{
    u32 p;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18);
    p = GetString(0x0B);
    sub_080065A8((u8 *)p);
    p = GetString(0x05);
    DrawTextCenteredHighlight((u8 *)p, 8, a == 0);
    p = GetString(0x08);
    DrawTextCenteredHighlight((u8 *)p, 0x0B, a == 1);
}
