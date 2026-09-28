#include "global.h"
#include "variables.h"
u32 ParkMillerNext(u32 a);

u32 ParkMillerNext(u32 a)
{
    u32 lo = (a & 0xFFFF) * 0x41A7;
    u32 hi = (a >> 16) * 0x41A7;
    u32 v = lo + ((hi & 0x7FFF) << 16);
    if ((s32)v < 0)
        v &= 0x7FFFFFFF, v++;
    v += hi >> 15;
    if ((s32)v < 0)
        v &= 0x7FFFFFFF, v++;
    return v;
}

u8 Random8(void)
{
    gRngState = ParkMillerNext(gRngState);
    return gRngState;
}
