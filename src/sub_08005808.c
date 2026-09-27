#include "global.h"

extern u8 gUnk_020020C4;
extern u8 gUnk_020021E0;
extern s32 gUnk_020253C0;
extern s32 gUnk_0202521C;
extern u8 gUnk_02025238;
extern u8 gUnk_0200215C[];

void sub_0800B09C(void);

void sub_08005808(void)
{
    u32 v;

    if (gUnk_020020C4 == 0)
        return;
    v = gUnk_020021E0;
    if (v != 0)
        return;
    gUnk_020253C0 -= 0x18;
    if (gUnk_020253C0 >= 0)
        return;
    gUnk_020253C0 += 0x3E8;
    gUnk_0202521C -= 1;
    gUnk_02025238 = 1;
    if (gUnk_0202521C >= 0)
        return;
    gUnk_0202521C = v;
    gUnk_020253C0 = v;
    if (gUnk_0200215C[0] != 0)
        return;
    sub_0800B09C();
}
