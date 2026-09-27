#include "global.h"
#include "variables.h"


void sub_08005598(u8 x)
{
    gCountdownSeconds = x;
    if (gCountdownSeconds > 0x63)
        gCountdownSeconds = 0x63;
}
