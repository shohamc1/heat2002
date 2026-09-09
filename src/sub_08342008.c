#include "global.h"

void sub_08342008(u32 arg)
{
    u32 zero = 0;
    u32 off = 0xA4 << 1;

    *(u32 *)(arg + 0x0C) = zero;
    *(u32 *)(arg + 0x14) = zero;
    *(u16 *)(arg + 0x3C) = zero;
    *(u32 *)(arg + off) = zero;
    *(u16 *)(arg + 0x40) = zero;
    *(u8 *)(arg + 0x3E) = 0;
}
