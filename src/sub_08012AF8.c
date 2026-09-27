#include "global.h"
#include "functions.h"
#include "data.h"


void sub_08012AF8(void)
{
    u32 v;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0xA9);
    ((void (*)(void))sub_080065A8)();
    v = GetString(0xAA);
    DrawTextCenteredHighlight((u8 *)v, 6, 1);
}
