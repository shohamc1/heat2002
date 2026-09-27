#include "global.h"
#include "variables.h"


void sub_0833D7D4(void)
{
    u32 i;
    u16 *p;

    i = 0;
    p = gUnk_0203B610;
    do {
        *p++ = i;
        i++;
    } while (i != 0x40);
}
