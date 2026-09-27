#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18[];


void sub_08012EE8(u32 unused, u8 v)
{
    u32 r;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x1E);
    ((void (*)(void))sub_080065A8)();
    r = GetString(v + 0x1F);
    DrawTextCenteredHighlight((u8 *)r, 8, 1);
}
