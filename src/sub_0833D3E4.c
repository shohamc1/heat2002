#include "global.h"

extern s32 gUnk_02039ED0[];
extern s32 gUnk_020392D0[];

s32 sub_08344BB8(s32 a, s32 b);

void sub_0833D3E4(s32 x)
{
    u32 c;
    s32 *d;
    s32 *s;
    s32 *bd;
    s32 *bs;
    s32 i;
    u32 off;

    i = 240;
    bd = gUnk_02039ED0;
    bs = gUnk_020392D0;
    off = 0xB40;
    s = (s32 *)((u32)bs + off);
    d = (s32 *)((u32)bd + off);
    do {
loop:
        c = 0x1F0000;
        d[0] = sub_08344BB8(c - s[0], x);
        d[1] = sub_08344BB8(c - s[1], x);
        d[2] = sub_08344BB8(c - s[2], x);
        s += 3;
        d += 3;
        i++;
    } while (0);
    if (i != 256) {
        if (1) {
            goto loop;
        }
    }
}
