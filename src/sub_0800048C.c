#include "global.h"
#include "gba/io_reg.h"
#include "variables.h"

extern u16 gKeysHeld;     /* 0x020005C8, defined in symbols.ld */

void ReadKeys(void)
{
    u16 keys = ~REG_KEYINPUT;
    *(vu16 *)&gKeysPressed = keys & ~*(vu16 *)&gKeysHeld;
    *(vu16 *)&gKeysHeld = keys;
}
