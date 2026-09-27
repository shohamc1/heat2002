#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_08004BCC(void)
{
    u8 v;
    u16 start;

    if (gKeysPressed & 4) {
        v = 0;
        sub_080047DC();
loop:
        ReadKeys();
        start = gKeysPressed & 4;
        if (start == 0) {
            v = MenuMoveVertical(gKeysPressed, v, 0, 9);
            sub_08004B1C(v);
            AgeGfxCaches();
            ClearOamBuffer();
            sub_08004A7C(v);
            sub_080047DC();
            gUnk_020020C0 = start;
            gUnk_02025370++;
            WaitForVBlank();
            goto loop;
        }
    }
}
