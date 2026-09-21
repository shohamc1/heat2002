#include "global.h"

extern u32 *gUnk_08364B08;
extern u8 gUnk_0806C8EC[];

void sub_08005870(u32 *dest, u32 idx);
void sub_0800649C(u32 r0, u32 r1, u32 r2);

void sub_08008C48(s32 x)
{
    u32 *base;
    u32 *p;
    u32 s;

    base = gUnk_08364B08;
    p = base + 0xE5;
    sub_08005870(p, x / 100 % 10);
    p = base + 0xE6;
    sub_08005870(p, x / 10 % 10);
    p = base + 0xE7;
    sub_08005870(p, x % 10);
    s = (u32)gUnk_0806C8EC;
    sub_0800649C(s, 0x10, 0x0F);
}
