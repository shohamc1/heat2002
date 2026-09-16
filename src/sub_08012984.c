#include "global.h"

extern u32 gUnk_083FDE18[];

extern void sub_08006734(u32 a);
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_08006950(u32 a, u32 b, u32 c);

void sub_08012984(u8 a)
{
    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0xA9);
    sub_080065A8();
    sub_08006950(sub_08016558(0xC5), 6, 1);
    sub_08006950(sub_08016558(a + 0xC5), 7, 1);
    if (a != 4)
        sub_08006950(sub_08016558(a + 0xAA), 0xA, 1);
    else
        sub_08006950(sub_08016558(0xB3), 0xA, 1);
}
