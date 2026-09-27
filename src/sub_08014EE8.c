#include "global.h"
#include "functions.h"

extern u32 gUnk_083FDE18;

void sub_08014EE8(u8 a)
{
    u8 b;

    b = a;
    /* sub_08006734: this file's old prototype takes an argument the matched definition drops; call
       through a function pointer with the old signature. */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18);
    GetString(9);
    ((void (*)(void))sub_080065A8)();
    DrawTextCenteredHighlight((u8 *)(GetString(5)), 7, a == 0);
    DrawTextCenteredHighlight((u8 *)(GetString(6)), 9, a == 1);
    DrawTextCenteredHighlight((u8 *)(GetString(0x9D)), 0xB, a == 2);
    DrawTextCenteredHighlight((u8 *)(GetString(8)), 0xD, b == 3);
}
