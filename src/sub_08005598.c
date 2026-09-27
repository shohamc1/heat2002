#include "global.h"
#include "variables.h"


void sub_08005598(u8 x)
{
    gUnk_0202521C = x;
    if (gUnk_0202521C > 0x63)
        gUnk_0202521C = 0x63;
}
