#include "global.h"

extern void gUnk_0200AE95(void);
u32 sub_080078E4(void);
void sub_0800793C(u32);

void sub_0800AF20(void)
{
    u32 r1 = sub_080078E4();

    if (r1 != 0) {
        *(u32 *)(r1 + 0x18) = 0xE1 << 2;
        *(u32 *)(r1 + 0x0C) = (u32)gUnk_0200AE95;
        sub_0800793C(r1);
    }
}
