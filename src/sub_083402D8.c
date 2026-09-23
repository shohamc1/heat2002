#include "global.h"

extern u8 gUnk_0200D058[];
extern u8 gUnk_0200D064[];
extern u8 gUnk_0200D07C[];

void sub_0833EF0C(u32 r0, u32 r1, u32 r2);

void sub_083402D8(void)
{
    u32 p;

    sub_0833EF0C((u32)gUnk_0200D058, 0x0B, 0x07);
    p = (u32)gUnk_0200D064;
    sub_0833EF0C(p, 0x06, 0x09);
    sub_0833EF0C(p, 0x06, 0x0A);
    p = (u32)gUnk_0200D07C;
    sub_0833EF0C(p, 0x06, 0x0B);
    sub_0833EF0C(p, 0x0A, 0x0C);
}
