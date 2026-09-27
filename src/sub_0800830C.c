#include "global.h"
#include "functions.h"


void sub_0800830C(u16 *a1, u16 *a2)
{
    u8 i = 0;

    do {
        u16 *q = (u16 *)(2 * i + (u32)a2);
        *q = sub_08017230(0x10000, *(u16 *)(2 * i + (u32)a1));
        i++;
    } while (i != 5);
}
