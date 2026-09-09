#include "global.h"

extern u32 gUnk_0202CB40[];

void sub_08008D70(void)
{
    u8 i;

    i = 0;
    do {
        gUnk_0202CB40[i] = 0;
        i++;
    } while (i != 13);
}
