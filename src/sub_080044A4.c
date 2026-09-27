#include "global.h"
#include "variables.h"


u32 AddOamEntry(u32 a, u32 b)
{
    u32 *p;

    if ((s8)gOamEntryCount < 0)
        return 0;
    p = *(u32 **)&gUnk_02024828;
    p[0] = a;
    p[1] = b;
    *(u32 *)&gUnk_02024828 = p + 2;
    gOamEntryCount = gOamEntryCount + 1;
    return 1;
}
