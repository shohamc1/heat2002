#include "global.h"

extern u8 gUnk_0200215C;
extern u8 gUnk_0202A550[][0x190];
extern u8 gUnk_0202CBD0;
extern u8 gUnk_083681BC[];
extern u8 gUnk_020020CC;
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202CBC8[];

void sub_0800BE00(void *base, s32 arg);
void sub_08008090(void);

void sub_0800930C(u8 *r4, u8 r5)
{
    u8 *r1;
    u32 r0;

    if (gUnk_0200215C == 3)
        return;
    if (r4[0x175] != 0)
        return;

    if (r4 == (u8 *)gUnk_0202A550) {
        r1 = &gUnk_0202CBD0;
        r0 = 1;
        r1[0] = r0;
    } else {
        *(u32 *)&r4[0x178] = *(u32 *)&r4[0xF0];
        r0 = 0x18F;
        r1 = &r4[r0];
        r0 = 1;
        r1[0] = r0;
    }
    r4[0x175] = 1;
    sub_0800BE00(r4, gUnk_083681BC[gUnk_020020CC] << 8);
    if (r4 == (u8 *)gUnk_0202A550 && gUnk_0202EEB0 != 0)
        sub_08008090();
    r4[0x181] = r5;
    gUnk_0202CBC8[r5] = 1;
}
