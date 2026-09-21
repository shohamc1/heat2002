#include "global.h"

extern u32 gUnk_083FDE18[];

extern void sub_08006734(u32 a);
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_08006950(u32 a, u32 b, u32 c);

void sub_080139F0(void)
{
    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x30);
    sub_080065A8();
    sub_08006950(sub_08016558(0x11), 7, 1);
    sub_08006950(sub_08016558(0x11), 8, 1);
    sub_08006950(sub_08016558(0x11), 9, 1);
    sub_08006950(sub_08016558(0x11), 10, 1);
    sub_08006950(sub_08016558(0x11), 11, 1);
    sub_08006950(sub_08016558(0x11), 12, 1);
    sub_08006950(sub_08016558(0x11), 13, 1);
    sub_08006950(sub_08016558(0x11), 14, 1);
}
