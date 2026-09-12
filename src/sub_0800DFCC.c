#include "global.h"

extern u32 gUnk_083FDE18[];
extern u16 *gUnk_08364B08;

void sub_08006734(u32 a);
u32 sub_08016558(u16 idx);
void sub_080065A8(void);

void sub_0800DFCC(void)
{
    u32 i;
    u32 *p;

    i = 0;
    p = gUnk_083FDE18;
    do {
        gUnk_08364B08[i] = 0;
        i++;
    } while (i != 0x380);
    sub_08006734(p[0]);
    sub_08016558(0x52);
    sub_080065A8();
}
