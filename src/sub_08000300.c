#include "global.h"

extern volatile u32 gUnk_040000D4[];

void sub_08000300(void)
{
    u16 v;
    u16 *p = &v;
    *p = 0;
    gUnk_040000D4[0] = (u32)&v;
    gUnk_040000D4[1] = 0xA0 << 19;
    gUnk_040000D4[2] = 0x81000200;
    (void)gUnk_040000D4[2];
}
