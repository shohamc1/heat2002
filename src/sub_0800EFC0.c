#include "global.h"

u32 sub_0800EFC0(u8 *ptr)
{
    if (ptr[0x18] == 0xE9)
        return 1;
    else
        return 0;
}
