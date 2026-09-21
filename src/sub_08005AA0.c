#include "global.h"

extern u8 gUnk_02025250;
extern u8 gUnk_0806C744[];
extern u8 gUnk_0806C758[];

u8 sub_080079D0(void);
void sub_08006418(u32 a, u32 b, u32 c);

void sub_08005AA0(void)
{
    u32 p;

    if (sub_080079D0() != 0 && (gUnk_02025250 & 8) != 0)
    {
        p = (u32)gUnk_0806C744;
        sub_08006418(p, 6, 1);
    }
    else
    {
        p = (u32)gUnk_0806C758;
        sub_08006418(p, 6, 1);
    }
    gUnk_02025250 = gUnk_02025250 + 1;
}
