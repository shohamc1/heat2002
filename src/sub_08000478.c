#include "global.h"

extern u16 gKeysHeld;    /* 0x020005C8 */
extern u16 gKeysPressed; /* 0x020005CC */

void sub_08000478(void)
{
    gKeysHeld = 0;
    gKeysPressed = 0;
}
