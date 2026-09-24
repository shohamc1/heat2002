#include "global.h"

extern u32 gUnk_020375D0;   /* 0x020375D0 */

void sub_08339AEC(void);

void sub_08339AB8(void *func)
{
    gUnk_020375D0 = (u32)func;
    if (func == NULL)
        gUnk_020375D0 = (u32)sub_08339AEC;
}
