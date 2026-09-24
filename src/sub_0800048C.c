#include "global.h"
#include "gba/io_reg.h"

extern volatile u16 gKeysHeld;     /* 0x020005C8, defined in symbols.ld */
extern volatile u16 gKeysPressed;  /* 0x020005CC */

void ReadKeys(void)
{
    u16 keys = ~REG_KEYINPUT;
    gKeysPressed = keys & ~gKeysHeld;
    gKeysHeld = keys;
}
