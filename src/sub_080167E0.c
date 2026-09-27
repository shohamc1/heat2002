#include "global.h"
#include "functions.h"
#include "variables.h"
void LoadTrackRecords(void)
{
    u16 *src;
    s32 i;
    u16 *d4;
    u16 *d3;
    u16 *d2;
    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0x130, 0x48);
    src = gUnk_0202F170;
    i = 0;
    d4 = gUnk_020253A0;
    d3 = gUnk_02025200;
    d2 = gUnk_02025380;
    do {
        *d2 = *src++;
        *d3 = *src++;
        *d4 = *src++;
        d4++;
        d3++;
        d2++;
        i++;
    } while (i != 0x0C);
    sub_080100B0();
}
