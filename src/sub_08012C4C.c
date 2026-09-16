#include "global.h"

extern u32 gUnk_083FDE18[];
extern u32 gUnk_083FEF00;
extern u8 gUnk_0829F374[];
extern u8 gUnk_0829F388[];
extern u8 gUnk_08310160[];
extern u8 gUnk_0830EC58[];
extern u8 gUnk_08310140[];
extern u8 gUnk_0829F3A4[];
extern u8 gUnk_0829F3AC[];
extern u8 gUnk_0829F3B4[];

extern void sub_08006734(u32 a);
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_08006950(u32 a, u32 b, u32 c);
extern void sub_08016E28(u32 a, u32 b);
extern void sub_080100CC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4);

void sub_08012C4C(u32 a)
{
    u32 t;

    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x8F);
    sub_080065A8();
    if (a <= 2) {
        sub_08006950(sub_08016558(0x91), 4, 1);
    } else {
        sub_08006950((u32)gUnk_0829F374, 6, 1);
        sub_08006950((u32)gUnk_0829F388, 0xA, 1);
    }
    if (a <= 2)
        sub_08016E28(gUnk_083FEF00, 0x06010000);
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
        sub_08006950((u32)gUnk_0829F3A4, 0x12, 1);
    if (a == 1)
        sub_08006950((u32)gUnk_0829F3AC, 0x12, 1);
    if (a == 2)
        sub_08006950((u32)gUnk_0829F3B4, 0x12, 1);
}
