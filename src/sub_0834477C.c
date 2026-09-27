#include "global.h"
#include "functions.h"
#include "variables.h"
extern u8 gUnk_0202B089[];
extern u8 gUnk_0202B078[];
u8 sub_0834477C(u8 a, u8 b)
{
    u8 i;
    if (b >= gUnk_0202B089[a] - 1) {
        sub_08344730();
        gUnk_0203E140[a] = 0;
        return 1;
    }
    i = 0;
    do {
        if (b < gUnk_0202B089[i])
            gUnk_0203E140[i] = 1;
        i++;
    } while (i != 0x11);
    sub_08344734();
    sub_083446C8(gUnk_0202B078[a]);
    return 0;
}
