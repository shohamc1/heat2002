#include "global.h"
#include "variables.h"


u16 sub_08004DB4(void)
{
    u16 keys;
    u16 i;
    u32 count;
    u16 *newp;
    u16 *oldp;
    u16 *base;
    u32 mask;
    u32 j;
    register u8 *flag asm("r4") = &gLinkMenuPlayerIndex;

    if (*flag == 0xFF) {
        keys = 0;
        i = 0;
        count = gNumLinkPlayers[0];
        newp = &gLinkMenuKeysPressed;
        oldp = &gLinkMenuKeysPrev;
        if (keys != count) {
            base = gPlayerKeys;
            mask = 8;
            j = count;
            do {
                if (base[i] & mask) {
                    *flag = i;
                    keys = base[i];
                }
                i++;
            } while (i != j);
        }
        *newp = keys & ~*oldp;
        *oldp = keys;
        return *newp;
    } else {
        keys = gPlayerKeys[*flag];
        gLinkMenuKeysPressed = keys & ~gLinkMenuKeysPrev;
        gLinkMenuKeysPrev = keys;
        return gLinkMenuKeysPressed;
    }
}
