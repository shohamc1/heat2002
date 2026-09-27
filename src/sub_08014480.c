#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18;

void sub_08014480(u8 a)
{
    u8 b;

    b = a;
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18);
    GetString(4);
    ((void (*)(void))sub_080065A8)();
    DrawTextCenteredHighlight((u8 *)(GetString(5)), 7, a == 0);
    DrawTextCenteredHighlight((u8 *)(GetString(6)), 9, a == 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x9D)), 0xB, a == 2);
    DrawTextCenteredHighlight((u8 *)(GetString(8)), 0xD, b == 3);
}
