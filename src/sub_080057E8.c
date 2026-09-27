#include "global.h"
#include "variables.h"


u32 sub_080057E8(void)
{
    if ((*(u32 *)&gUnk_0202521C) != 0)
        return 1;
    if (gUnk_020253C0 != 0)
        return 1;
    return 0;
}
