#include "global.h"

extern u8 gUnk_0202EF00[];

void sub_08001208(u32 a);
void sub_0800184C(void);

void sub_080100B0(void)
{
    if (gUnk_0202EF00[2] != 0)
        sub_08001208(2);
    sub_0800184C();
}
