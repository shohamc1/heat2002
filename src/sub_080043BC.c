#include "global.h"
#include "variables.h"

extern u32 gCamera[];

void SmoothCamera(void)
{
    s32 x = gCamera[2] - gCamera[0];
    s32 y = gCamera[3] - gCamera[1];

    if (gIsDemo != 0) {
        gCamera[0] += x;
        gCamera[1] += y;
    } else {
        gCamera[0] += x >> 4;
        gCamera[1] += y >> 4;
    }
}
