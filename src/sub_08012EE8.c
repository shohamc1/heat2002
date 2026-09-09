#include "global.h"

extern u32 gUnk_083FDE18[];

void sub_08006734(u32 a);
u32 sub_08016558(u16 idx);
void sub_080065A8(void);
void sub_08006950(u32 a, u32 b, u32 c);

void sub_08012EE8(u32 unused, u8 v)
{
    u32 r;

    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x1E);
    sub_080065A8();
    r = sub_08016558(v + 0x1F);
    sub_08006950(r, 8, 1);
}
