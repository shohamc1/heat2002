#include "global.h"
#include "functions.h"

void DrawTime(u16 *dest, s32 a, s32 b, s32 c)
{
    u32 i;
    s32 digits[8];

    if (a > 0x63) {
        a = 0x63;
        b = 0x3B;
        c = 0;
    }
    digits[2] = 10;
    digits[5] = 10;
    digits[0] = a / 10;
    digits[1] = a % 10;
    digits[3] = b / 10;
    digits[4] = b % 10;
    digits[7] = c % 100 / 10;
    digits[6] = c / 100;
    for (i = 0; i != 8; dest++, i++) {
        DrawSmallDigit(dest + 2, digits[i]);
    }
}
