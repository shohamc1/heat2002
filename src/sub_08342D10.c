#include "global.h"
#include "variables.h"

void sub_08342C3C(void);

void *sub_0833FF44(void);
void sub_0833FF94(u32 a);

void sub_08342D10(void)
{
    u32 *r;

    r = (u32 *)sub_0833FF44();
    if (r != 0) {
        r[6] = 0x40;
        r[3] = (u32)sub_08342C3C;
        sub_0833FF94((u32)r);
        gUnk_0203DE28[0] = gUnk_0203B6C8[0];
        gUnk_0203DE3C[0] = gUnk_0203B6A8[0];
        gUnk_0203DE20[0] = gUnk_0203B858[0];
    }
}
