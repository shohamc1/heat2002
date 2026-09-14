#include "global.h"

extern u8 gUnk_02002090;
extern u8 gUnk_020020DC;
extern u8 gUnk_020020AC;
extern u8 gUnk_0202A550[][0x190];

void sub_0800C0FC(s32 *a, s32 b, s32 c, s32 *d);

u8 sub_0800C164(u8 *a)
{
    s32 d1[2];
    s32 d2[2];
    u8 count;
    u8 i;
    u8 *e;

    count = gUnk_02002090;
    if (gUnk_020020DC != 0)
        count = gUnk_020020AC;
    e = gUnk_0202A550;
    for (i = 0; i != count; i++, e += 0x190) {
        if (e == a)
            continue;
        sub_0800C0FC((s32 *)a, *(s32 *)&e[0], *(s32 *)&e[8], d1);
        if ((u32)(d1[1] + 100) > 100)
            continue;
        {
            s32 dx = d1[0];
            s32 lim = -16;

            if (dx < lim || dx > 16)
                continue;
            sub_0800C0FC((s32 *)e, *(s32 *)&a[0], *(s32 *)&a[8], d2);
            if (d2[1] < 0)
                continue;
            if (d2[0] < lim || d2[0] > 16)
                continue;
        }
        a[0x176] = 15;
        return 1;
    }
    return 0;
}
