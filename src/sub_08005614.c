#include "global.h"
#include "variables.h"


void SetTrackRecord(u32 a, u32 b, u32 c)
{
    if ((u8)(gUnk_0200215C[0] - 3) <= 1)
        return;
    gUnk_020253A0[gTrackId] = c;
    gUnk_02025200[gTrackId] = b;
    gUnk_02025380[gTrackId] = a;
}
