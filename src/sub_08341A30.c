#include "global.h"
#include "functions.h"
#include "variables.h"

struct Unk08341A30Ent
{
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
};

extern s32 gUnk_020390AC;
extern u32 gUnk_020243E8[];

struct Unk08341A30Ent *sub_0833FC94(u32 a);
u32 sub_0833FD78(u32 a);
void sub_0833D6A0(u32 a, u32 b);

void sub_08341A30(u32 a1, u32 a2, u32 a3)
{
    u32 *ptr;
    struct Unk08341A30Ent *ret;
    u32 bits;

    ptr = gUnk_0202772C[a3];
    ptr += sub_08344C50(gUnk_020390AC >> 1, 7);
    a2 &= 0xFF;
    a2 |= (a1 & 0x1FF) << 16;
    a2 |= 0x40000000;
    ret = sub_0833FC94(*ptr);
    if (ret == 0)
        return;
    bits = ret->field_10;
    bits |= (sub_0833FD78(gUnk_020243E8) << 24) >> 12;
    sub_0833D6A0(a2, bits);
}
