#include "global.h"
#include "functions.h"
#include "variables.h"
extern u8 gUnk_083FDCDD[];
extern u8 gUnk_083FDCCC[];
u8 sub_0800F2BC(u8 a, u8 b)
{
    u8 i;
    if (b >= gUnk_083FDCDD[a] - 1) {
        sub_0800F1B4();
        gUnk_0202EF20[a] = 0;
        return 1;
    }
    i = 0;
    do {
        if (b < gUnk_083FDCDD[i])
            gUnk_0202EF20[i] = 1;
        i++;
    } while (i != 0x11);
    sub_0800F1D0();
    sub_0800F14C(gUnk_083FDCCC[a]);
    return 0;
}
