#include "global.h"
#include "functions.h"

extern u8 gText_Overwrite[];
extern u8 gText_YouWillLoseThe[];
extern u8 gText_PreviouslySavedCareer[];
extern u8 gText_AreYouSure[];
extern u8 gText_No[];
extern u8 gText_Yes[];


void sub_0801380C(u8 a)
{
    u32 v;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)((u32)gText_Overwrite);
    DrawTextCenteredHighlight((u8 *)((u32)gText_YouWillLoseThe), 7, 1);
    DrawTextCenteredHighlight((u8 *)((u32)gText_PreviouslySavedCareer), 8, 1);
    DrawTextCenteredHighlight((u8 *)((u32)gText_AreYouSure), 0xA, 1);
    v = (u32)gText_No;
    DrawTextCenteredHighlight((u8 *)v, 0xC, a == 0);
    v = (u32)gText_Yes;
    DrawTextCenteredHighlight((u8 *)v, 0xE, a == 1);
}
