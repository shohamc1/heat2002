#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xcmd, high-module copy. Its xcmd table lives at 0x0200C910 and the
 * indirect call goes through the high module's _call_via_r2 stub at
 * 0x08344B84: calling _08344B84(a, b, target) leaves a in r0, b in r1 and
 * jumps to the address in r2. */

extern MPlayFunc gUnk_0200C910[];

void _08344B84(u32 arg0, u32 arg1, u32 arg2);

void sub_0833BB58(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 n = *track->cmdPtr;
    track->cmdPtr++;

    _08344B84(mplayInfo, track, gUnk_0200C910[n]);
}
