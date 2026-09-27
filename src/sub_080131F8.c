#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"


void sub_080064F8(u32 r0, u32 r1, u32 r2, u32 r3);

void sub_080131F8(u8 arg)
{
    u8 buf[0x12];
    u8 *p;

    p = &buf[0x10];
    p[1] = 0;
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x6B);
    ((void (*)(void))sub_080065A8)();
    p[0] = (gUnk_0202EF78[0] << 1) - 0x80;
    sub_080064F8((u32)p, 4, 7, arg == 0);
    p[0] = (gUnk_0202EF78[1] << 1) - 0x80;
    sub_080064F8((u32)p, 9, 7, arg == 1);
    p[0] = (gUnk_0202EF78[2] << 1) - 0x80;
    sub_080064F8((u32)p, 0xE, 7, arg == 2);
    p[0] = (gUnk_0202EF78[3] << 1) - 0x80;
    sub_080064F8((u32)p, 0x13, 7, arg == 3);
    p[0] = (gUnk_0202EF78[4] << 1) - 0x80;
    sub_080064F8((u32)p, 0x18, 7, arg == 4);
    if (gUnk_0202EEB4 != 0) {
        if (gUnk_0202EEB4 & 0x10) {
            DrawTextCenteredHighlight((u8 *)(GetString((u32)(gUnk_0202EDB0 + 0x6C))), 0xF, 1);
        } else {
            DrawText((u8 *)((u32)gUnk_0829F2AC), 0, 0xF, 0);
        }
        gUnk_0202EEB4--;
    }
}
