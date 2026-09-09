#include "global.h"

u32 sub_0833C858(u32 arg0)
{
    u32 tmp = arg0 << 16;
    if (((tmp >> 21) & 3) == 3)
        return 0;
    if (((tmp >> 19) & 3) == 3)
        return 0;
    return 1;
}
