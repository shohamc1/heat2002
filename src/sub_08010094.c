#include "global.h"

void sub_080012D4(u32 index);

void sub_08010094(void)
{
    u8 i;

    for (i = 0; i != 100; i++)
        sub_080012D4(i);
}
