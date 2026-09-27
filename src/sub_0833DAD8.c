#include "global.h"
#include "variables.h"


u16 sub_0833DAD8(void)
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
    count = gUnk_020390BC[0];
    newp = &gUnk_0203B6FC;
    oldp = &gUnk_0203B848;
    if (keys != count) {
        base = gUnk_020390B0;
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
