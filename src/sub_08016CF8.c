#include "global.h"

u8 Random8(void);

u32 sub_08016CF8(void)
{
    return Random8() * 2;
}
