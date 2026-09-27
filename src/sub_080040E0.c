#include "global.h"
#include "functions.h"

extern u32 gUnk_02022E20[];
extern u32 gUnk_02023A20[];


void sub_080040E0(u32 a)
{
    register u32 *s asm("r1");
    register u32 *d asm("r2");
    register u32 *src asm("r6");
    register u32 i asm("r8");
    u32 *dst;
    u32 k;

    i = 0xF0;
    d = gUnk_02023A20;
    s = gUnk_02022E20;
    src = s + 0x2D0;
    dst = d + 0x2D0;
loop:
    k = 0xF8 << 0xD;
    dst[0] = sub_08017230(k - src[0], a);
    dst[1] = sub_08017230(k - src[1], a);
    dst[2] = sub_08017230(k - src[2], a);
    src += 3;
    dst += 3;
    i++;
    if (i != 0x100)
        goto loop;
}
