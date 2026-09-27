#include "global.h"
#include "variables.h"

extern u16 gKeysHeld;    /* 0x020005C8 */

void sub_08000478(void)
{
    gKeysHeld = 0;
    gKeysPressed = 0;
}
