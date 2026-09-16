#include "global.h"

extern u32 gUnk_083FDE18[];
extern u8 gUnk_0829F3BC[];

extern void sub_08006734(u32 a);
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_08006950(u32 a, u32 b, u32 c);

void sub_080134E8(u8 a)
{
    u8 b = a;
    u32 v;

    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x00);
    sub_080065A8();
    v = (u32)gUnk_0829F3BC;
    sub_08006950(v, 6, a == 0);
    v = sub_08016558(0x02);
    sub_08006950(v, 8, a == 1);
    v = sub_08016558(0x03);
    sub_08006950(v, 0xA, a == 2);
    v = sub_08016558(0x60);
    sub_08006950(v, 0xC, a == 3);
    v = sub_08016558(0x08);
    sub_08006950(v, 0xE, b == 4);
}
