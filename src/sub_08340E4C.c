#include "global.h"
#include "variables.h"


void sub_08340E4C(void)
{
    u32 v = gUnk_0203D500 + 40;

    gUnk_0203D500 = v;
    if ((s32)v <= 999)
        return;
    gUnk_0203D500 -= 1000;
    v = ++(*(s32 *)&gUnk_0203DCFC);
    if ((s32)v > 59) {
        (*(s32 *)&gUnk_0203DCFC) = v - 60;
        gUnk_0203DD04++;
    }
}
