#include "global.h"
#include "variables.h"


u16 sub_08004E58(void)
{
    u16 keys;
    u16 i;
    u8 count;
    u16 *newp;
    u16 *oldp;
    u16 *base;
    u32 j;

    keys = 0;
    i = 0;
    count = gNumLinkPlayers[0];
    newp = &gLinkMenuKeysPressed;
    oldp = &gLinkMenuKeysPrev;
    if (keys != count) {
        base = gPlayerKeys;
        j = count;
        do {
            keys |= base[i];
            i++;
        } while (i != j);
    }
    *newp = keys & ~*oldp;
    *oldp = keys;
    return *newp;
}
