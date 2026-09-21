#include "global.h"

extern u16 *gUnk_020251B8;
extern u8 gUnk_0200D0B8[];
extern u32 gUnk_0203DD04;
extern u32 gUnk_0203DCFC;
extern u32 gUnk_0203D500;

void sub_0833EF0C(u8 *str, u32 a2, u32 a3);
void sub_0833E36C(u16 *dest, u32 val);
u32 sub_08344BB8(u32 a, u32 b);
s32 sub_08344C50(s32 a, s32 b);

void sub_08340D04(void)
{
    u16 *p;
    u32 *q;
    u32 *r;
    u16 *base;

    base = gUnk_020251B8;
    p = base + 0x128;
    sub_0833EF0C(gUnk_0200D0B8, 8, 8);
    sub_0833E36C(p, 0);
    p = base + 0x12A;
    sub_0833E36C(p, gUnk_0203DD04);
    p = base + 0x12D;
    q = &gUnk_0203DCFC;
    sub_0833E36C(p, sub_08344BB8(*q, 0xA));
    p = base + 0x12F;
    sub_0833E36C(p, sub_08344C50(*q, 0xA));
    p = base + 0x132;
    r = &gUnk_0203D500;
    q = r;
    sub_0833E36C(p, sub_08344C50(sub_08344BB8(*q, 0x64), 0xA));
    p = base + 0x134;
    sub_0833E36C(p, sub_08344C50(sub_08344BB8(*q, 0xA), 0xA));
}
