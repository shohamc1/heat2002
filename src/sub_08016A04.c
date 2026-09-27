#include "global.h"
#include "functions.h"

extern u8 gOptions[];
extern u8 gUnk_0202F1B8[];


void SaveOptions(void)
{
    u32 i;
    u8 *dst;
    StopAllSongsAndVSyncOff();
    dst = gUnk_0202F1B8;
    for (i = 0; i != 6; i++)
    {
        *dst = gOptions[i];
        dst++;
    }
    WriteSaveBlocks(0xBC << 1, 8);
    sub_080100B0();
}
