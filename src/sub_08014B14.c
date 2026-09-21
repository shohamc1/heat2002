#include "global.h"

extern u8 gUnk_0202EDB4;
extern u32 gUnk_0202EDC0;
extern u8 gUnk_0202EDE0;
extern u8 gUnk_0202EEF0;
extern u8 gUnk_0202EEE0;
extern u8 gUnk_0202F02C;
extern u8 gUnk_0202CDB0[];

void sub_08014B14(void)
{
    u8 *p;
    u8 *q0;
    u8 *q1;
    u8 *q2;
    u8 *q3;
    s32 r;

    gUnk_0202EDB4 = 0;
    gUnk_0202EDC0 = 0;
    q0 = &gUnk_0202F02C;
    q1 = &gUnk_0202EEE0;
    q2 = &gUnk_0202EEF0;
    q3 = &gUnk_0202EDE0;
    *q3 = 0;
    *q2 = 0;
    *q1 = 0;
    *q0 = 0;
    p = gUnk_0202CDB0;
    r = p[0] * 100 / p[1];
    p[2] = r;
    p[5] = p[3] * 100 / p[4];
    p[8] = p[6] * 100 / p[7];
    if ((u8)r > 100)
        p[2] = 100;
    *(s32 *)&p[0xC] = (p[2] + p[5] + p[8] + p[9]) >> 2;
}
