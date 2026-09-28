#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_Player1[];
extern u8 gModule_Player2[];
extern u8 gModule_Player3[];
extern u8 gModule_Player4[];

void sub_0833EE88(u8 *s, u32 a, u32 b);

void sub_0833DC14(void)
{
    sub_0833EE88(sub_0833BD94(3), 8, 1);

    switch (gUnk_0203B850[0]) {
    case 0:
        sub_0833EE88(gModule_Player1, 9, 1);
        break;
    case 1:
        sub_0833EE88(gModule_Player2, 9, 1);
        break;
    case 2:
        sub_0833EE88(gModule_Player3, 9, 1);
        break;
    case 3:
        sub_0833EE88(gModule_Player4, 9, 1);
        break;
    }
}
