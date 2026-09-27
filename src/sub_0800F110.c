#include "global.h"
#include "data.h"


u32 GetDriverName(u8 r0)
{
    return gDriverRoster[r0][0];
}
