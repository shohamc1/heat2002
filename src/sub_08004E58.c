#include "global.h"

extern u8 gUnk_020020AC;
extern u16 gUnk_02025258;
extern u16 gUnk_020253BC;
extern u16 gUnk_020020A0[];

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
    count = gUnk_020020AC;
    newp = &gUnk_02025258;
    oldp = &gUnk_020253BC;
    if (keys != count) {
        base = gUnk_020020A0;
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
