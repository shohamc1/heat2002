#include "global.h"

extern u32 gUnk_02025FD0;
extern u8 gUnk_02025ED0[];

void sub_080078B8(void)
{
    u32 i = 0;
    do {
        gUnk_02025ED0[i] = 0;
        i++;
    } while (i != 0x100);
    gUnk_02025FD0 = 0;
}
