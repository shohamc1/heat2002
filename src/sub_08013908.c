#include "global.h"

extern u32 gUnk_083FDE18[];

extern void sub_08006734(u32 a);
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_08006950(u32 a, u32 b, u32 c);

void sub_08013908(u8 a)
{
    u8 v;

    v = a;
    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x60);
    sub_080065A8();
    if (a == 0)
        sub_08006950(sub_08016558(0x63), 9, 1);
    if (a == 1)
        sub_08006950(sub_08016558(0x61), 9, 1);
    if (v == 2)
        sub_08006950(sub_08016558(0x62), 9, 1);
}
