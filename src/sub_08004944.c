#include "global.h"
#include "variables.h"

extern u32 gUnk_0836524C[];

void sub_08004944(u8 a)
{
    gUnk_02025244 = 1;
    gTrackCueList = gUnk_0836524C[a];
    (*(s8 *)&gTrackCueId) = -1;
    if (gTrackCueList == 0)
        gUnk_02025244 = gTrackCueList;
}
