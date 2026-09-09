#include "global.h"

extern u32 gUnk_0829EF40[];
extern u32 gUnk_0829EF50[];
extern u32 gUnk_0829EF64[];

void sub_080065A8(u32 a);
void sub_08006950(u32 a, u32 b, u32 c);

void sub_0800F1EC(u8 a)
{
    sub_080065A8((u32)gUnk_0829EF40);
    sub_08006950((u32)gUnk_0829EF50, 8, a == 0);
    sub_08006950((u32)gUnk_0829EF64, 0xA, a == 1);
}
