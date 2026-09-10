#include "global.h"
extern u16 gUnk_0202F170[];
extern u16 gUnk_020253A0[];
extern u16 gUnk_02025200[];
extern u16 gUnk_02025380[];
extern void sub_08010074(void);
extern void sub_0801659C(u32 a, u32 b);
extern void sub_080100B0(void);
void sub_08016834(void)
{
    u16 *dst;
    s32 i;
    u16 *s4;
    u16 *s3;
    u16 *s2;
    sub_08010074();
    dst = gUnk_0202F170;
    i = 0;
    s4 = gUnk_020253A0;
    s3 = gUnk_02025200;
    s2 = gUnk_02025380;
    do {
        *dst++ = *s2;
        *dst++ = *s3;
        *dst++ = *s4;
        s4++;
        s3++;
        s2++;
        i++;
    } while (i != 0x0C);
    sub_0801659C(0x130, 0x48);
    sub_080100B0();
}
