#include "global.h"
#include "variables.h"


void sub_08339AEC(void);

void sub_08339AB8(void *func)
{
    gUnk_020375D0 = (u32)func;
    if (func == NULL)
        gUnk_020375D0 = (u32)sub_08339AEC;
}
