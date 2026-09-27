#include "global.h"
#include "functions.h"

extern u32 gUnk_0829EF40[];
extern u32 gUnk_0829EF50[];
extern u32 gUnk_0829EF64[];


void sub_0800F1EC(u8 a)
{
    u32 p;

    /* sub_080065A8: this file's old prototype takes an argument the matched definition drops; call
       through a function pointer with the old signature. */
    ((void (*)(u32))sub_080065A8)((u32)gUnk_0829EF40);
    p = (u32)gUnk_0829EF50;
    DrawTextCenteredHighlight((u8 *)p, 8, a == 0);
    p = (u32)gUnk_0829EF64;
    DrawTextCenteredHighlight((u8 *)p, 0xA, a == 1);
}
