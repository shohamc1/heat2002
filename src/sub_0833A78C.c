#include "global.h"

struct Unk10CC
{
    u8 filler0[0x4];
    s32 unk4;
};

extern const u8 gUnk_0200C6F8[];
extern const u32 gUnk_0200C7AC[];

extern s32 _08339B78(s32 a, s32 b);

s32 sub_0833A78C(struct Unk10CC *arg0, u8 arg1, u32 arg2)
{
    u8 idx;
    u32 packed;
    u32 t;
    u8 b;
    s32 next;
    u32 diff;

    idx = arg1;
    packed = arg2 << 24;
    if (idx > 0xB2)
    {
        idx = 0xB2;
        packed = 0xFF000000;
    }
    t = gUnk_0200C6F8[idx];
    t = gUnk_0200C7AC[t & 0xF] >> (t >> 4);
    b = gUnk_0200C6F8[idx + 1];
    diff = gUnk_0200C7AC[b & 0xF] >> (b >> 4);
    next = arg0->unk4;
    diff -= t;
    return _08339B78(next, t + _08339B78(diff, packed));
}
