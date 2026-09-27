#include "global.h"
#include "variables.h"


u32 sub_0833E2E4(void)
{
    if (gModule_CountdownSeconds != 0)
        return 1;
    if (gModule_CountdownMs != 0)
        return 1;
    return 0;
}
