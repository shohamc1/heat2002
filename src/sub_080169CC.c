#include "global.h"
#include "functions.h"

extern u8 gOptions[];
extern u8 gUnk_0202F1B8[];


void LoadOptions(void)
{
    u8 *src;
    u32 i;

    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0xBC * 2, 8);
    src = gUnk_0202F1B8;
    for (i = 0; i != 6; i++) {
        gOptions[i] = *src++;
    }
    sub_080100B0();
}
