#include "global.h"
#include "data.h"


const u8 *GetDriverName(u8 driverId)
{
    return gDriverRoster[driverId].name;
}
