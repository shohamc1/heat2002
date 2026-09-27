#include "global.h"
#include "variables.h"


u32 sub_080057E8(void)
{
    if ((*(u32 *)&gCountdownSeconds) != 0)
        return 1;
    if (gCountdownMs != 0)
        return 1;
    return 0;
}
