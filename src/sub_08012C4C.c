#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "gba/syscall.h"
#include "data.h"

extern u32 gUnk_083FEF00;
extern u8 gUnk_0829F374[];
extern u8 gUnk_0829F388[];
extern u8 gUnk_08310160[];
extern u8 gUnk_0830EC58[];
extern u8 gUnk_08310140[];
extern u8 gUnk_0829F3A4[];
extern u8 gUnk_0829F3AC[];
extern u8 gUnk_0829F3B4[];


void sub_08012C4C(u32 a)
{
    u32 t;

    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    GetString(0x8F);
    ((void (*)(void))sub_080065A8)();
    if (a <= 2) {
        DrawTextCenteredHighlight((u8 *)(GetString(0x91)), 4, 1);
    } else {
        DrawTextCenteredHighlight((u8 *)((u32)gUnk_0829F374), 6, 1);
        DrawTextCenteredHighlight((u8 *)((u32)gUnk_0829F388), 0xA, 1);
    }
    if (a <= 2)
        RLUnCompVram(gUnk_083FEF00, OBJ_VRAM0);
    if (a == 0) {
        t = (u32)gUnk_08310160;
        sub_080100CC(0x58, 0x40, 0, t, a);
    }
    if (a == 1) {
        t = (u32)gUnk_0830EC58;
        sub_080100CC(0x58, 0x40, 0, t, 0);
    }
    if (a == 2) {
        t = (u32)gUnk_08310140;
        sub_080100CC(0x58, 0x40, 0, t, 0);
    }
    if (a == 0)
        DrawTextCenteredHighlight((u8 *)((u32)gUnk_0829F3A4), 0x12, 1);
    if (a == 1)
        DrawTextCenteredHighlight((u8 *)((u32)gUnk_0829F3AC), 0x12, 1);
    if (a == 2)
        DrawTextCenteredHighlight((u8 *)((u32)gUnk_0829F3B4), 0x12, 1);
}
