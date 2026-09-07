#include "global.h"

void sub_08003D3C(u32 a, u32 b);

void sub_08003D90(void)
{
    sub_08003D3C(0xC0 << 18, 0x0600E800);
    sub_08003D3C(0x03000800, 0x0600F000);
}
