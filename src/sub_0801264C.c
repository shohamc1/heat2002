#include "global.h"
#include "functions.h"
#include "data.h"


void sub_0801264C(u32 x)
{
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x14);
    ((void (*)(void))sub_080065A8)();
    DrawTextCenteredHighlight((u8 *)(GetString(0x15)), 8, x == 0);
    DrawTextCenteredHighlight((u8 *)(GetString(0x16)), 0xA, x == 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x17)), 0xC, x == 2);
    DrawTextCenteredHighlight((u8 *)(GetString(0x18)), 0xE, x == 3);
}
