#include "global.h"

extern u32 gUnk_083FDE18[];

void sub_08006734(u32 a);
u32 sub_08016558(u16 idx);
void sub_080065A8(void);
void sub_08006950(u32 a, u32 b, u32 c);

void sub_08015000(u8 a)
{
    u32 v;
    u8 b;

    b = a;
    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x0A);
    sub_080065A8();
    v = sub_08016558(0x05);
    sub_08006950(v, 7, a == 0);
    v = sub_08016558(0x07);
    sub_08006950(v, 9, a == 1);
    v = sub_08016558(0x08);
    sub_08006950(v, 0xB, b == 2);
}
