#include "global.h"
#include "data.h"


const u8 *GetDriverName(u8 driverId)
{
    return (const u8 *)gDriverRoster[driverId][0];
}
