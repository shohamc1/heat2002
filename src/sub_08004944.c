#include "global.h"
#include "variables.h"

extern u32 gUnk_0836524C[];
extern s8 gUnk_0202524C;

void sub_08004944(u8 a)
{
    gUnk_02025244 = 1;
    gUnk_020253B8 = gUnk_0836524C[a];
    gUnk_0202524C = -1;
    if (gUnk_020253B8 == 0)
        gUnk_02025244 = gUnk_020253B8;
}
