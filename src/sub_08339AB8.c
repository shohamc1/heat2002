#include "global.h"

extern u32 gUnk_020375D0;   /* 0x020375D0 */
extern u8 gUnk_0200106D;    /* 0x0200106D */

void sub_08339AB8(void *func)
{
    gUnk_020375D0 = (u32)func;
    if (func == NULL)
        gUnk_020375D0 = (u32)&gUnk_0200106D;
}
