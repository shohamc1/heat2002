#include "global.h"

extern u8 gUnk_020253C4;
extern u8 gNumLinkPlayers;
extern u16 gUnk_02025258;
extern u16 gUnk_020253BC;
extern u16 gUnk_020020A0[];

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
    register u8 *flag asm("r4") = &gUnk_020253C4;

    if (*flag == 0xFF) {
        keys = 0;
        i = 0;
        count = gNumLinkPlayers;
        newp = &gUnk_02025258;
        oldp = &gUnk_020253BC;
        if (keys != count) {
            base = gUnk_020020A0;
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
        keys = gUnk_020020A0[*flag];
        gUnk_02025258 = keys & ~gUnk_020253BC;
        gUnk_020253BC = keys;
        return gUnk_02025258;
    }
}
