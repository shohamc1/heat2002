#include "global.h"

extern u16 gUnk_02025380[];
extern u16 gUnk_02025200[];
extern u16 gUnk_020253A0[];
extern u8 gUnk_020020CC;
extern u8 gUnk_0200215C;
extern u8 gUnk_020020F0;

void sub_08005614(u32 a, u32 b, u32 c);
void sub_0800B594(void);

void sub_08005664(u16 a1, u16 a2, u16 a3)
{
    if (a1 * 60000 + a2 * 1000 + a3 <= gUnk_02025380[gUnk_020020CC] * 60000
        + gUnk_02025200[gUnk_020020CC] * 1000 + gUnk_020253A0[gUnk_020020CC]) {
        if (gUnk_0200215C == 3 || gUnk_0200215C == 4)
            return;
        sub_08005614(a1, a2, a3);
        gUnk_020020F0 = 1;
        sub_0800B594();
    }
}
