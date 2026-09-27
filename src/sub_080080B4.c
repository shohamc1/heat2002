#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_080080B4(void)
{
    sub_08007F44(gUnk_0202CBE0);
    gUnk_0202CBE0 = MenuMoveVerticalSilent(gKeysPressed, gUnk_0202CBE0, 0, 3);
    if (gUnk_0202CBE0 == 0)
        gUnk_0202CBC0[0] = MenuMoveHorizontalSilent(gKeysPressed, gUnk_0202CBC0[0], 0, 3);
    if (gUnk_0202CBE0 == 1)
        gUnk_0202CBC0[1] = MenuMoveHorizontalSilent(gKeysPressed, gUnk_0202CBC0[1], 0, 2);
    if (gUnk_0202CBE0 == 2)
        gUnk_0202CBC0[2] = MenuMoveHorizontalSilent(gKeysPressed, gUnk_0202CBC0[2], 0, 1);
    if (gUnk_0202CBE0 == 3 && (gKeysPressed & 1))
    {
        gUnk_0202CAD0 = 0;
        gUnk_0202A53C = 1;
        if (gUnk_0202CBC0[0] == 3 && gUnk_0202CBC0[1] == 2 && gUnk_0202CBC0[2] == 1)
            gUnk_0202A53C = 0;
        sub_08007EF8();
    }
}
