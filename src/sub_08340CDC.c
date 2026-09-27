#include "global.h"
#include "variables.h"


u32 sub_08340CDC(s32 arg0)
{
    if ((*(s32 *)&gUnk_0203DCFC) * 1000 + (*(s32 *)&gUnk_0203D500) <= arg0)
        return 1;
    return 0;
}
