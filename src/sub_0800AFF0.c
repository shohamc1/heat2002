#include "global.h"

extern u8 gUnk_020021E0;
extern u8 gUnk_02002098;
extern u32 gCallback_0800AF45[];

u32 sub_080078E4(void);
void sub_0800793C(u32 a);

void sub_0800AFF0(void)
{
    u8 *p = &gUnk_020021E0;
    if (*p == 0)
    {
        u32 *r = (u32 *)sub_080078E4();
        if (r != 0)
        {
            r[7] = gUnk_02002098;
            r[6] = 0x64;
            r[3] = (u32)gCallback_0800AF45;
            sub_0800793C((u32)r);
        }
        *p = 1;
    }
}
