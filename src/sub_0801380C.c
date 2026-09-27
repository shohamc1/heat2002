#include "global.h"
#include "functions.h"

extern u8 gUnk_0829F3C8[];
extern u8 gUnk_0829F3D4[];
extern u8 gUnk_0829F3E8[];
extern u8 gUnk_0829F404[];
extern u8 gUnk_0829F414[];
extern u8 gUnk_0829F418[];


void sub_0801380C(u8 a)
{
    u32 v;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)((u32)gUnk_0829F3C8);
    DrawTextCenteredHighlight((u8 *)((u32)gUnk_0829F3D4), 7, 1);
    DrawTextCenteredHighlight((u8 *)((u32)gUnk_0829F3E8), 8, 1);
    DrawTextCenteredHighlight((u8 *)((u32)gUnk_0829F404), 0xA, 1);
    v = (u32)gUnk_0829F414;
    DrawTextCenteredHighlight((u8 *)v, 0xC, a == 0);
    v = (u32)gUnk_0829F418;
    DrawTextCenteredHighlight((u8 *)v, 0xE, a == 1);
}
