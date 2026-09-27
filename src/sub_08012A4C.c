#include "global.h"
#include "functions.h"
#include "data.h"



void DrawMessageBox(u32 a, u32 b, u32 c)
{
    u32 x = a;
    u32 y = b;
    u32 z = c;
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    sub_080065A8((u8 *)x);
    DrawTextCenteredHighlight((u8 *)y, 6, 1);
    DrawTextCenteredHighlight((u8 *)z, 7, 1);
}
