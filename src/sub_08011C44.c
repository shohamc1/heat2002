#include "global.h"

u16 sub_08011C44(u16 a, u16 b, u16 c)
{
    u32 t1, t2, t3, x, y, z;

    t1 = a * 255 / 100;
    t1 <<= 16;
    t2 = b * 255 / 100;
    t2 <<= 16;
    t3 = c * 255 / 100;
    t3 <<= 16;
    x = t1 >> 19;
    y = t2 >> 19;
    z = t3 >> 19;
    return x | ((z << 10) | (y << 5));
}
