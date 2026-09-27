#include "global.h"
#include "functions.h"
#include "data.h"


void sub_08014614(u32 a)
{
    u8 i;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0xA4);
    ((void (*)(void))sub_080065A8)();
    i = 0;
    do {
        DrawTextCenteredHighlight((u8 *)(GetString(i + 0xA5)), i * 2 + 6, a == i);
        i++;
    } while (i != 4);
}
