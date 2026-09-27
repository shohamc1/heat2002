#include "global.h"
#include "variables.h"
#include "car.h"

void sub_083415B0(u8 idx)
{
    u32 count;
    u8 result;
    s32 mykey;
    u8 *p;
    u8 *t;
    u8 *q;
    u32 off;
    u32 j;

    count = gUnk_020390A0[0];
    if (gUnk_020390EC != 0)
        count = gUnk_020390BC[0];
    result = 0;
    p = (u8 *)gModule_Cars;
    off = idx * 400;
    t = p + 0x50;
    mykey = *(s32 *)(off + t);
    for (j = 0, q = (u8 *)gModule_Cars; j != count; j++) {
        if (j != idx && *(s32 *)(t + j * 400) > mykey)
            result++;
    }
    *(q + idx * 400 + 0x150) = result;
}
