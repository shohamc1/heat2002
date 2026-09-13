#include "global.h"

extern u8 gUnk_0202EEFC;
extern u32 gUnk_083FDE18[];
extern u16 gUnk_083FDE5E[];

extern u8 sub_0800E730(void);
extern void sub_08006734(u32 a);
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_08006950(u32 a, u32 b, u32 c);

void sub_0801060C(u8 a)
{
    u8 *d;
    u32 i;
    u16 *p;
    u32 j;

    d = &gUnk_0202EEFC;
    *d = sub_0800E730();
    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x59);
    sub_080065A8();
    i = 0;
    j = 5;
    p = gUnk_083FDE5E;
    do {
        sub_08006950(sub_08016558(*p), j, a == i);
        j += 2;
        p++;
        i++;
    } while (i != 7);
}
