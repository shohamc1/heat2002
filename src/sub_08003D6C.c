#include "global.h"

void sub_08016E0C(u32 a, u32 b, u32 c);

void sub_08003D6C(u32 a, u32 b)
{
    u32 i;

    for (i = 0; i != 0x1C; i++) {
        sub_08016E0C(a, b, 0x10);
        a += 0x40;
        b += 0x40;
    }
}
