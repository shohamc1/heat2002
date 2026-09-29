#include "global.h"

/* NEAR-MISS (score 45): register-only diff — target homes the f12/f0F load
 * temps in r1 (reusing the dead flags reg); this agbcc picks r4, adding one
 * `adds r1, r4` copy in part 2. mode-local, u32 vol, operand orders all set. */

struct Chan
{
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
    u8 type;
};

void ModuleTrkVolPitSet(u32 mplayInfo, struct Chan *track)
{
    u32 envFactor;
    s32 pan;
    s32 type;

    if (track->flags & 1) {
        envFactor = (u32)(track->f12 * track->f13) >> 5;
        type = track->type;
        if (type == 1)
            envFactor = ((u32)(track->f16 + 0x80) * envFactor) >> 7;
        pan = track->f14 * 2 + track->f15;
        if (type == 2)
            pan = pan + track->f16;
        if (pan < -0x80)
            pan = -0x80;
        else if (pan > 0x7F)
            pan = 0x7F;
        track->f10 = ((pan + 0x80) * envFactor) >> 8;
        track->f11 = ((0x7F - pan) * envFactor) >> 8;
    }
    if (track->flags & 4) {
        s32 bend = track->f0E * track->f0F;
        s32 x = (track->f0C + bend) * 4 + (track->f0A << 8) + (track->f0B << 8) + track->f0D;
        if (track->type == 0)
            x += track->f16 << 4;
        track->f08 = x >> 8;
        track->f09 = x;
    }
    track->flags = track->flags & 0xFA;
}
