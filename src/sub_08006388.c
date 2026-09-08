#include "global.h"

extern void sub_080062BC(void);
extern u8 gUnk_0202F030;
extern u8 gUnk_0806C78C[];

void sub_0800649C(u8 *src, u32 x, u32 y);

void sub_08006388(void)
{
    sub_080062BC();
    if (gUnk_0202F030 != 0)
    {
        sub_0800649C(gUnk_0806C78C, 0, 0x12);
    }
}
