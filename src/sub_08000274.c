#include "global.h"

extern volatile u32 gUnk_040000D4[];

void sub_08000274(void)
{
    u16 x;
    u16 *p = &x;
    *p = 0;
    gUnk_040000D4[0] = (u32)p;
    gUnk_040000D4[1] = 0x06000000;
    gUnk_040000D4[2] = 0x8100C000;
    (void)gUnk_040000D4[2];
}
