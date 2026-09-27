#include "global.h"
#include "variables.h"

extern u32 gUnk_0203D490;

void _08344B80(u32 arg0, u32 arg1);

void sub_0833FFC4(void)
{
    u32 p;

    gUnk_0203D490 = 0;
    p = gUnk_0203C380;
    if (p != 0)
    {
        do {
            gUnk_0203D490 = gUnk_0203D490 + 1;
            _08344B80(p, *(u32 *)(p + 0x0C));
            p = *(u32 *)(p + 0x14);
        } while (p != 0);
    }
}
