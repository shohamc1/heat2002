#include "global.h"

extern u8 gUnk_0829F3C8[];
extern u8 gUnk_0829F3D4[];
extern u8 gUnk_0829F3E8[];
extern u8 gUnk_0829F404[];
extern u8 gUnk_0829F414[];
extern u8 gUnk_0829F418[];

extern void sub_08006734(u32 a);
extern void sub_08006950(u32 a, u32 b, u32 c);

void sub_0801380C(u8 a)
{
    u32 v;

    sub_08006734((u32)gUnk_0829F3C8);
    sub_08006950((u32)gUnk_0829F3D4, 7, 1);
    sub_08006950((u32)gUnk_0829F3E8, 8, 1);
    sub_08006950((u32)gUnk_0829F404, 0xA, 1);
    v = (u32)gUnk_0829F414;
    sub_08006950(v, 0xC, a == 0);
    v = (u32)gUnk_0829F418;
    sub_08006950(v, 0xE, a == 1);
}
