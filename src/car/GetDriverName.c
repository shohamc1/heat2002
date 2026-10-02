#include "global.h"
#include "functions.h"
#include "data.h"

const u8 *GetDriverName(u8 driverId)
{ return gDriverRoster[driverId].name; }
