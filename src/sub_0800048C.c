#include "global.h"
#include "gba/io_reg.h"

extern u16 gKeysHeld;     /* 0x020005C8, defined in symbols.ld */
extern u16 gKeysPressed;  /* 0x020005CC */

void ReadKeys(void)
{
    u16 keys = ~REG_KEYINPUT;
    *(vu16 *)&gKeysPressed = keys & ~*(vu16 *)&gKeysHeld;
    *(vu16 *)&gKeysHeld = keys;
}
