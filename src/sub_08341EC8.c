#include "global.h"

extern u16 gUnk_0203B704[];
extern u16 gUnk_0203B6D0[];
extern u16 gUnk_0203B6D4[];

void sub_08341EC8(u16 *p)
{
    u16 *q = p;
    u16 v1 = gUnk_0203B704[0];
    u32 i = 0x82;

    q[i] = v1;
    v1 = gUnk_0203B6D0[0];
    i += 1;
    q[i] = v1;
    v1 = gUnk_0203B6D4[0];
    i += 1;
    q[i] = v1;
    *(u8 *)((u32)p + 0x7D) = 1;
}
