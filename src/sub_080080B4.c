#include "global.h"

extern u8 gUnk_0202CBE0;
extern u8 gUnk_0202CBC0[];
extern u16 gKeysPressed;
extern u8 gUnk_0202CAD0;
extern u8 gUnk_0202A53C;

extern void sub_08007F44(u8 a);
extern s16 sub_08011DAC(u16 keys, s16 v, s16 lo, s16 hi);
extern s16 sub_08011E84(u16 keys, s16 v, s16 lo, s16 hi);
extern void sub_08007EF8(void);

void sub_080080B4(void)
{
    sub_08007F44(gUnk_0202CBE0);
    gUnk_0202CBE0 = sub_08011DAC(gKeysPressed, gUnk_0202CBE0, 0, 3);
    if (gUnk_0202CBE0 == 0)
        gUnk_0202CBC0[0] = sub_08011E84(gKeysPressed, gUnk_0202CBC0[0], 0, 3);
    if (gUnk_0202CBE0 == 1)
        gUnk_0202CBC0[1] = sub_08011E84(gKeysPressed, gUnk_0202CBC0[1], 0, 2);
    if (gUnk_0202CBE0 == 2)
        gUnk_0202CBC0[2] = sub_08011E84(gKeysPressed, gUnk_0202CBC0[2], 0, 1);
    if (gUnk_0202CBE0 == 3 && (gKeysPressed & 1))
    {
        gUnk_0202CAD0 = 0;
        gUnk_0202A53C = 1;
        if (gUnk_0202CBC0[0] == 3 && gUnk_0202CBC0[1] == 2 && gUnk_0202CBC0[2] == 1)
            gUnk_0202A53C = 0;
        sub_08007EF8();
    }
}
