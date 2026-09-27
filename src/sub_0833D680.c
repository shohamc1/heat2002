#include "global.h"
#include "variables.h"

void sub_0833D638(void);

void sub_0833D680(void)
{
    u32 i = 0;
    u32 v = 0xAA;
    u32 *p = (u32 *)gUnk_0203ACE0;

    do {
        *p = v;
        p += 2;
        i++;
    } while (i != 0x80);
    sub_0833D638();
}
