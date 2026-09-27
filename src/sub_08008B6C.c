#include "global.h"
#include "variables.h"


u32 sub_08008B6C(s32 arg0)
{
    if ((*(s32 *)&gUnk_0202CADC) * 1000 + (*(s32 *)&gUnk_0202A534) <= arg0)
        return 1;
    return 0;
}
