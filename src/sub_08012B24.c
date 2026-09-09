#include "global.h"

extern u32 gUnk_083FDE18[];
void sub_08006734(u32 a);
u32 sub_08016558(u16 idx);
void sub_080065A8(void);
void sub_08006950(u32 a, u32 b, u32 c);

void sub_08012B24(void)
{
    u32 v;

    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0xBD);
    sub_080065A8();
    v = sub_08016558(0xBE);
    sub_08006950(v, 6, 1);
}
