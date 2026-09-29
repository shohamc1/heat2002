#include "global.h"

struct Track
{
    u8 flags;
    u8 pad1[0x13 - 1];
    u8 volX;
    u8 pad2[0x50 - 0x14];
};
struct MPlayInfo
{
    u8 pad0[8];
    u8 trackCount;
    u8 pad9[0x24 - 9];
    u16 fadeOI;
    u16 fadeOC;
    u16 fadeOV;
    struct Track *tracks;
};
void sub_0833A488(struct MPlayInfo *mplayInfo, struct Track *track);
void ModuleFadeOutBody(struct MPlayInfo *mplayInfo)
{
    s32 i;
    s32 fadeOV;
    struct Track *track;
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
