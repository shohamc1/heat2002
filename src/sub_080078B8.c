#include "global.h"
#include "variables.h"

extern u32 gUnk_02025FD0;

void InitTasks(void)
{
    u32 i = 0;
    do {
        gUnk_02025ED0[i] = 0;
        i++;
    } while (i != 0x100);
    gUnk_02025FD0 = 0;
}
