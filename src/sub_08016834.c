#include "global.h"
#include "functions.h"
#include "variables.h"
void SaveTrackRecords(void)
{
    u16 *dst;
    s32 i;
    u16 *s4;
    u16 *s3;
    u16 *s2;
    StopAllSongsAndVSyncOff();
    dst = gUnk_0202F170;
    i = 0;
    s4 = gTrackRecordMs;
    s3 = gTrackRecordSec;
    s2 = gTrackRecordMin;
    do {
        *dst++ = *s2;
        *dst++ = *s3;
        *dst++ = *s4;
        s4++;
        s3++;
        s2++;
        i++;
    } while (i != 0x0C);
    WriteSaveBlocks(0x130, 0x48);
    sub_080100B0();
}
