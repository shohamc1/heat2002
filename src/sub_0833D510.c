#include "global.h"

void sub_0833D288(u32 r0, u32 r1);
void sub_08339B18(void);
void sub_0833D448(void);

void sub_0833D510(u32 r0, u32 r1)
{
    u16 r2 = (u16)r0;
    u32 i;

    sub_0833D288(r1, r2);
    for (i = 0; i != r1; i++)
    {
        sub_08339B18();
        sub_0833D448();
    }
}
