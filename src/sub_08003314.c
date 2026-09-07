#include "global.h"

u32 sub_08003314(u16 a)
{
    if ((a >> 5 & 3) == 3)
        return 0;
    if ((a >> 3 & 3) == 3)
        return 0;
    return 1;
}
