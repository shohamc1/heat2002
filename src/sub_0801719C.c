#include "global.h"

struct UnkF240 {
    u8 filler0[4];
    u16 unk4;
    u8 filler6[8 - 6];
    u8 unk8;
};

extern struct UnkF240 *gUnk_0202F240;
extern u16 sub_08017000(u16 a, u16 *b);

u16 sub_0801719C(u16 a, u16 *b)
{
    u16 buf[4];
    u8 i;
    u16 ret;
    u16 *q;

    ret = 0;
    if (a >= gUnk_0202F240->unk4)
        return 0x80FF;
    sub_08017000(a, buf);
    q = buf;
    for (i = 0; i < 4; i++) {
        if (*b++ != *q++) {
            ret = 0x8000;
            break;
        }
    }
    return ret;
}
