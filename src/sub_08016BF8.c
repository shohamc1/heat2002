#include "global.h"
extern u16 gUnk_0202F040[];
extern void sub_0801661C(void);
extern void sub_080165E0(u32 a, u32 b);
u32 sub_08016BF8(void)
{
    sub_0801661C();
    sub_080165E0(0, 8);
    if (gUnk_0202F040[0] == 0xA482 && gUnk_0202F040[1] == 0x7674)
        return 1;
    return 0;
}
