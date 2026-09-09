#include "global.h"

extern u32 gUnk_0202CC00[];
extern u32 gUnk_0202CC08[];
extern u32 gUnk_0202CC1C[];
extern u16 gUnk_02025218[];
extern u16 gUnk_020251FC[];
extern u16 gUnk_020253CC[];
extern u32 gUnk_0800B46D[];

u32 sub_080078E4(void);
void sub_0800793C(u32 a);

void sub_0800B540(void)
{
    u32 *r;

    r = (u32 *)sub_080078E4();
    if (r != 0) {
        r[6] = 0x40;
        r[3] = (u32)gUnk_0800B46D;
        sub_0800793C(r);
        gUnk_0202CC08[0] = gUnk_02025218[0];
        gUnk_0202CC1C[0] = gUnk_020251FC[0];
        gUnk_0202CC00[0] = gUnk_020253CC[0];
    }
}
