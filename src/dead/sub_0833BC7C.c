#include "global.h"

s32 sub_0833BC7C(u32 seed)
{
    s32 a = (seed & 0xFFFF) * 0x41A7;
    s32 b = (seed >> 16) * 0x41A7;
    s32 c = a + ((b & 0x7FFF) << 16);

    if (c < 0) {
        c &= 0x7FFFFFFF;
        c++;
    }
    c += (u32)b >> 15;
    if (c < 0) {
        c &= 0x7FFFFFFF;
        c++;
    }
    return c;
}
