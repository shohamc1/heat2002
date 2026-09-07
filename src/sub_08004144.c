#include "global.h"

void sub_080041A0(void);

void sub_08004144(void)
{
    u32 v = *(s16 *)0x02022E18;
    u8 *p = (u8 *)0x02022E14;
    if (v == 0)
        *p = v;
    if (*p != 0)
    {
        u32 i;
        u32 n;
        u32 *r3;
        u32 *r4;
        sub_080041A0();
        i = 0;
        n = 0x300;
        r3 = (u32 *)0x02022E20;
        r4 = (u32 *)0x02023A20;
        while (i != n)
        {
            *r3++ += *r4++;
            i++;
        }
        *(u16 *)0x02022E18 = *(u16 *)0x02022E18 - 1;
    }
    *(u8 *)0x02022E10 = 1;
}
