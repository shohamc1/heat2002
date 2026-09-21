#include "global.h"

/* NEAR-MISS (score 45): register-only diff — target homes the f12/f0F load
 * temps in r1 (reusing the dead flags reg); this agbcc picks r4, adding one
 * `adds r1, r4` copy in part 2. mode-local, u32 vol, operand orders all set. */

struct Chan {
    u8 flags;
    u8 pad0[7];
    u8 f08;
    u8 f09;
    s8 f0A;
    s8 f0B;
    s8 f0C;
    u8 f0D;
    s8 f0E;
    u8 f0F;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    s8 f14;
    s8 f15;
    s8 f16;
    u8 pad17;
    u8 mode;
};

void sub_0833B134(u32 a, struct Chan *chan)
{
    u32 vol;
    s32 pan;
    s32 mode;

    if (chan->flags & 1) {
        vol = (u32)(chan->f12 * chan->f13) >> 5;
        mode = chan->mode;
        if (mode == 1)
            vol = ((u32)(chan->f16 + 0x80) * vol) >> 7;
        pan = chan->f14 * 2 + chan->f15;
        if (mode == 2)
            pan = pan + chan->f16;
        if (pan < -0x80)
            pan = -0x80;
        else if (pan > 0x7F)
            pan = 0x7F;
        chan->f10 = ((pan + 0x80) * vol) >> 8;
        chan->f11 = ((0x7F - pan) * vol) >> 8;
    }
    if (chan->flags & 4) {
        s32 bend = chan->f0E * chan->f0F;
        s32 x = (chan->f0C + bend) * 4
              + (chan->f0A << 8)
              + (chan->f0B << 8)
              + chan->f0D;
        if (chan->mode == 0)
            x += chan->f16 << 4;
        chan->f08 = x >> 8;
        chan->f09 = x;
    }
    chan->flags = chan->flags & 0xFA;
}
