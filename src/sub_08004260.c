#include "global.h"
#include "variables.h"


void SetCameraPos(u32 x, u32 y)
{
    gCamera[0] = x;
    gCamera[1] = y;
    gCamera[2] = x;
    gCamera[3] = y;
    gCamera[4] = 0;
    gCamera[5] = 0;
}
