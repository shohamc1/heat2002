#include "global.h"

extern u32 gUnk_083FDE18[];

void sub_08006734(u32 a);
void sub_080065A8(u32 a);
void sub_08006950(u32 a, u32 b, u32 c);

void sub_08012A4C(u32 a, u32 b, u32 c)
{
    u32 x = a;
    u32 y = b;
    u32 z = c;
    sub_08006734(gUnk_083FDE18[0]);
    sub_080065A8(x);
    sub_08006950(y, 6, 1);
    sub_08006950(z, 7, 1);
}
