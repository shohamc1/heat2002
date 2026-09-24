#include "global.h"

void sub_08003EF0(u32 *dst, u32 *src)
{
    u32 i;

    i = 0;
    do {
        *dst++ += *src++;
        i++;
    } while (i != 0x30);
}
