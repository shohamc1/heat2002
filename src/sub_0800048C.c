#include "global.h"

extern volatile u16 gKeysHeld;     /* 0x020005C8, defined in symbols.ld */
extern volatile u16 gKeysPressed;  /* 0x020005CC */

void sub_0800048C(void)
{
    u16 keys = ~*(volatile u16 *)0x04000130;
    gKeysPressed = keys & ~gKeysHeld;
    gKeysHeld = keys;
}
