#include "global.h"

extern u32 gUnk_083FDE18;
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_08006950(u8 *p, u32 a1, u8 a2);
extern void sub_08006734(u32 a);

void sub_08014EE8(u8 a)
{
    u8 b;

    b = a;
    sub_08006734(gUnk_083FDE18);
    sub_08016558(9);
    sub_080065A8();
    sub_08006950(sub_08016558(5), 7, a == 0);
    sub_08006950(sub_08016558(6), 9, a == 1);
    sub_08006950(sub_08016558(0x9D), 0xB, a == 2);
    sub_08006950(sub_08016558(8), 0xD, b == 3);
}
