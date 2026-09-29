#include "global.h"
#include "gba/m4a_internal.h"

void TrkVolPitSet(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 trackPtr = (u32)track;
    u32 isPitchSet;
    u32 flags;
    u32 envFactor;
    u32 type;
    s32 pan;
    u8 flagsAfter;

    flags = ((struct MusicPlayerTrack *)trackPtr)->flags;
    if (flags & 1) {
        envFactor = (u32)(((struct MusicPlayerTrack *)trackPtr)->vol * ((struct MusicPlayerTrack *)trackPtr)->volX) >> 5;
        type = ((struct MusicPlayerTrack *)trackPtr)->modT;
        if (type == 1) {
            envFactor = (u32)((((struct MusicPlayerTrack *)trackPtr)->modM + 0x80) * envFactor) >> 7;
        }
        pan = (((struct MusicPlayerTrack *)trackPtr)->pan << 1) + ((struct MusicPlayerTrack *)trackPtr)->panX;
        if (type == 2) {
            pan += ((struct MusicPlayerTrack *)trackPtr)->modM;
        }
        if (pan < -0x80) {
            pan = -0x80;
        } else if (pan > 0x7F) {
            pan = 0x7F;
        }
        ((struct MusicPlayerTrack *)trackPtr)->volMR = (u8)(((pan + 0x80) * envFactor) >> 8);
        ((struct MusicPlayerTrack *)trackPtr)->volML = (u8)(((0x7F - pan) * envFactor) >> 3 >> 5);
    }

    flags = ((struct MusicPlayerTrack *)trackPtr)->flags;
    isPitchSet = flags & 4;
    flagsAfter = flags;
    if (isPitchSet) {
        s32 bend = ((struct MusicPlayerTrack *)trackPtr)->bend * ((struct MusicPlayerTrack *)trackPtr)->bendRange;
        s32 x = ((((struct MusicPlayerTrack *)trackPtr)->tune + bend) * 4) + (((struct MusicPlayerTrack *)trackPtr)->keyShift << 8) +
                (((struct MusicPlayerTrack *)trackPtr)->keyShiftX << 8) + ((struct MusicPlayerTrack *)trackPtr)->pitX;
        if (((struct MusicPlayerTrack *)trackPtr)->modT == 0) {
            x += ((struct MusicPlayerTrack *)trackPtr)->modM << 4;
        }
        ((struct MusicPlayerTrack *)trackPtr)->keyM = (u8)(x >> 8);
        ((struct MusicPlayerTrack *)trackPtr)->pitM = (u8)x;
    }

    ((struct MusicPlayerTrack *)trackPtr)->flags = flagsAfter & 0xFA;
}
