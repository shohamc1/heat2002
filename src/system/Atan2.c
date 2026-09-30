#include "global.h"

extern u8 gAtan2Table[];

u8 Atan2(s32 x, s32 y)
{
    u8 *t;
    s32 a;

    a = x;
    for (;;) {
        if ((u32)(a + 0x7F) > 0xFE) {
            a = a / 2;
            y = y / 2;
            continue;
        }
        if (y < -0x7F) {
            a = a / 2;
            y = y / 2;
            continue;
        }
        if (y > 0x7F) {
            a = a / 2;
            y = y / 2;
            continue;
        }
        break;
    }
    if (y < -0x7F)
        goto zero;
    if (y <= 0x7F)
        goto table;
zero:
    return 0;
table:
    t = gAtan2Table;
    y = y + 0x80;
    y = y << 8;
    y = y + 0x80;
    return t[a + y];
}
