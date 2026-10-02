#include "global.h"
#include "functions.h"
#include "m4a.h"

void sub_0833A488(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void ModuleFadeOutBody(struct MusicPlayerInfo *mplayInfo)
{
    s32 i;
    s32 fadeOV;
    struct MusicPlayerTrack *track;
    unsigned long long mask;
    if (mplayInfo->fadeOI != 0) {
        if ((--mplayInfo->fadeOC) == 0) {
            mask = 0xFFFF;
            fadeOV = (mplayInfo->fadeOV = (mplayInfo->fadeOV - 16) & mask);
            if (((s16)fadeOV) <= 0) {
                for (i = mplayInfo->trackCount, track = mplayInfo->tracks; i > 0; i--, track++) {
                    sub_0833A488(mplayInfo, track);
                    track->flags = 0;
                }

            } else {
                mplayInfo->fadeOC = mplayInfo->fadeOI;
                for (i = mplayInfo->trackCount, track = mplayInfo->tracks; i > 0; i--, track++) {
                    if (track->flags & 0x80) {
                        track->volX = mplayInfo->fadeOV >> 2;
                        track->flags |= 3;
                    }
                }
            }
        }
    }
}
