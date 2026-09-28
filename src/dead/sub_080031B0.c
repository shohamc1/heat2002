#include "global.h"

u32 sub_080031B0(u16 arg0)
{
    if ((arg0 & 0x7F) == 0x7F)
        return 0;
    return 1;
}
