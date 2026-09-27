#include "global.h"
#include "variables.h"


u32 ParkMillerNext(u32 a);

u8 Random8(void)
{
    gRngState = ParkMillerNext(gRngState);
    return gRngState;
}
