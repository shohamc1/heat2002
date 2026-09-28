#include "global.h"

void ModuleInitCarSteering(u32 *steer, u32 heading)
{
    steer[1] = heading;
    steer[0] = heading;
}
