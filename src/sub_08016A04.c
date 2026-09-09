#include "global.h"

extern u8 gUnk_0202EF00[];
extern u8 gUnk_0202F1B8[];

void sub_08010074(void);
void sub_0801659C(u32 a, u32 b);
void sub_080100B0(void);

void sub_08016A04(void)
{
    u32 i;
    u8 *dst;
    sub_08010074();
    dst = gUnk_0202F1B8;
    for (i = 0; i != 6; i++)
    {
        *dst = gUnk_0202EF00[i];
        dst++;
    }
    sub_0801659C(0xBC << 1, 8);
    sub_080100B0();
}
