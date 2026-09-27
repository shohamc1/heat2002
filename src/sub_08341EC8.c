#include "global.h"
#include "variables.h"


void sub_08341EC8(u16 *p)
{
    u16 *q = p;
    u16 v1 = gModule_RaceMin[0];
    u32 i = 0x82;

    q[i] = v1;
    v1 = gModule_RaceSec[0];
    i += 1;
    q[i] = v1;
    v1 = gModule_RaceMs[0];
    i += 1;
    q[i] = v1;
    *(u8 *)((u32)p + 0x7D) = 1;
}
