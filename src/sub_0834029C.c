#include "global.h"

void sub_0834029C(u8 *arg0)
{
    u32 r3 = (u32)arg0;
    u8 r0v;
    u32 sp[0x0A];

    (void)sp;
    *(u8 *)(r3 + (0xB8 << 1)) = 0;
    r0v = *(u8 *)(r3 + 0x171);
    *(u8 *)(r3 + 0x173) = r0v;
    *(u8 *)(r3 + 0x171) = 0;
    *(u8 *)(r3 + 0x172) = 0;
}
