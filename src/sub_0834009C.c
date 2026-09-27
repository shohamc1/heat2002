#include "global.h"
#include "car.h"

u32 sub_0834009C(u32 a0, u32 a1, u32 count)
{
    u32 p;
    u8 i;

    i = 0;
    p = (u32)gModule_Cars;
    while (i != 0x05) {
        if (*(u8 *)(p + 0x175) != 0)
            count = (u8)(count + 1);
        p += 0x190;
        i++;
        p += 0x190;
    }
    return count;
}
