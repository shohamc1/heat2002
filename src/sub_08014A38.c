#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08014A38(u8 a)
{
    u32 v;

    /* sub_08006734: this file's old prototype takes an argument the matched definition drops; call
       through a function pointer with the old signature. */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x4E);
    ((void (*)(void))sub_080065A8)();
    v = GetString(0x5F);
    DrawTextCenteredHighlight((u8 *)v, 8, a == 0);
    v = GetString(0x5E);
    DrawTextCenteredHighlight((u8 *)v, 0xA, a == 1);
}
