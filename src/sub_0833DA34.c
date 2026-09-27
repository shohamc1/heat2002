#include "global.h"
#include "variables.h"


u16 sub_0833DA34(void)
{
    u16 keys;
    u16 i;
    u32 count;
    u16 *newp;
    u16 *oldp;
    u16 *base;
    u32 mask;
    u32 j;
    register u8 *flag asm("r4") = &gUnk_0203B850[0];

    if (*flag == 0xFF) {
        keys = 0;
        i = 0;
        count = gUnk_020390BC[0];
        newp = &gUnk_0203B6FC;
        oldp = &gUnk_0203B848;
        if (keys != count) {
            base = gUnk_020390B0;
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
    }
    keys = gUnk_020390B0[*flag];
    gUnk_0203B6FC = keys & ~gUnk_0203B848;
    gUnk_0203B848 = keys;
    return gUnk_0203B6FC;
}
