#include "global.h"

extern u16 *gUnk_020251B8;
extern u8 gUnk_0200D0C0[];

u32 sub_08344BB8(u32 a, u32 b);
s32 sub_08344C50(s32 a, s32 b);
void sub_0833E36C(u16 *dest, u32 val);
void sub_0833EF0C(u8 *str, u32 a2, u32 a3);

void sub_08340DB8(u32 a1)
{
    u16 *base;
    u16 *p;

    base = gUnk_020251B8;
    p = base + 0x1CA;
    sub_0833E36C(p, sub_08344C50(sub_08344BB8(a1, 0x64), 0x0A));
    p = base + 0x1CC;
    sub_0833E36C(p, sub_08344C50(sub_08344BB8(a1, 0x0A), 0x0A));
    p = base + 0x1CE;
    sub_0833E36C(p, sub_08344C50(a1, 0x0A));
    sub_0833EF0C(gUnk_0200D0C0, 0x10, 0x0F);
}
