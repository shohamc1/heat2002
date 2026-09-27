#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_083429E8(u32 a)
{
    if (++*(u32 *)(a + 0x18) == 0x4E)
    {
        sub_0833FFA8(a);
        sub_0833FF84(a);
        gModule_RaceStarted = 1;
    }
}
