#include "global.h"

extern u32 gUnk_02000580;

void sub_08000444(void);

void sub_08000410(void)
{
    if (gUnk_02000580 != 0)
        ((void (*)(void))gUnk_02000580)();
    sub_08000444();
}
