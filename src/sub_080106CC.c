#include "global.h"
#include "gba/defines.h"

void sub_080106CC(u16 *src, u16 *tiles)
{
    u16 *dest;
    u16 *t;
    u16 v;
    u32 i;
    u32 j;

    dest = (u16 *)BG_SCREEN_ADDR(31);
    for (i = 0; i != 10; i++) {
        for (j = 0; j != 15; j++) {
            v = *src++;
            t = tiles + v * 4;
            dest[0] = t[0];
            t++;
            dest[1] = t[0];
            t++;
            dest[32] = t[0];
            dest[33] = t[1];
            dest += 2;
        }
        dest += 0x22;
    }
}
