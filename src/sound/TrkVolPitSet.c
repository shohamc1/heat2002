#include "global.h"
#include "gba/m4a_internal.h"

void TrkVolPitSet(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct MusicPlayerTrack *trackPtr = track;
    u32 isPitchSet;
    u32 flags;
    u32 envFactor;
    u32 type;
    s32 pan;
    u8 flagsAfter;

    flags = trackPtr->flags;
    if (flags & 1) {
        envFactor = (u32)(trackPtr->vol * trackPtr->volX) >> 5;
        type = trackPtr->modT;
        if (type == 1) {
            envFactor = (u32)((trackPtr->modM + 0x80) * envFactor) >> 7;
        }
        pan = (trackPtr->pan << 1) + trackPtr->panX;
        if (type == 2) {
            pan += trackPtr->modM;
        }
        if (pan < -0x80) {
            pan = -0x80;
        } else if (pan > 0x7F) {
            pan = 0x7F;
        }
        trackPtr->volMR = (u8)(((pan + 0x80) * envFactor) >> 8);
        trackPtr->volML = (u8)(((0x7F - pan) * envFactor) >> 3 >> 5);
    }

    flags = trackPtr->flags;
    isPitchSet = flags & 4;
    flagsAfter = flags;
    if (isPitchSet) {
        s32 bend = trackPtr->bend * trackPtr->bendRange;
        s32 x = ((trackPtr->tune + bend) * 4) + (trackPtr->keyShift << 8) +
                (trackPtr->keyShiftX << 8) + trackPtr->pitX;
        if (trackPtr->modT == 0) {
            x += trackPtr->modM << 4;
        }
        trackPtr->keyM = (u8)(x >> 8);
        trackPtr->pitM = (u8)x;
    }

    trackPtr->flags = flagsAfter & 0xFA;
}
