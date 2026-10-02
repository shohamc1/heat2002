#include "global.h"
#include "functions.h"
#include "gba/m4a_internal.h"

void ModuleTrkVolPitSet(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    u32 envFactor;
    s32 pan;
    s32 type;

    if (track->flags & 1) {
        envFactor = (u32)(track->vol * track->volX) >> 5;
        type = track->modT;
        if (type == 1)
            envFactor = ((u32)(track->modM + 0x80) * envFactor) >> 7;
        pan = track->pan * 2 + track->panX;
        if (type == 2)
            pan = pan + track->modM;
        if (pan < -0x80)
            pan = -0x80;
        else if (pan > 0x7F)
            pan = 0x7F;
        track->volMR = ((pan + 0x80) * envFactor) >> 8;
        track->volML = ((0x7F - pan) * envFactor) >> 8;
    }
    if (track->flags & 4) {
        s32 bend = track->bend * track->bendRange;
        s32 x = (track->tune + bend) * 4 + (track->keyShift << 8) + (track->keyShiftX << 8) + track->pitX;
        if (track->modT == 0)
            x += track->modM << 4;
        track->keyM = x >> 8;
        track->pitM = x;
    }
    track->flags = track->flags & 0xFA;
}
