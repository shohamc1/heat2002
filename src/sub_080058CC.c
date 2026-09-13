#include "global.h"

extern u16 gUnk_08334E0A[];
extern u16 gUnk_08335A8C[];

void sub_080058CC(u16 *dest, u8 idx)
{
    u16 v;

    v = *(idx + gUnk_08334E0A);
    *dest = (gUnk_08335A8C[v] & 0xFFF) | 0xE000;
}
