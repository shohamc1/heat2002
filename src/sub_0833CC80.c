#include "global.h"

void sub_0833CC80(u16 *src, u16 *dst, u16 count)
{
    u16 t = 0xFFFF;
    u16 *s = src;
    u16 value = *s++;
    u16 i;
    u16 *out = dst;

    for (i = 1; i < count; i++) {
        *out++ = value;
        if (value == t) {
            u16 run = *s++;
            i++;
            while (run != 0) {
                *out++ = value;
                run--;
            }
        }
        t = value;
        value = *s++;
    }
}
