#include "global.h"
#include "functions.h"
#include "variables.h"
void LoadProgress(void)
{
    u8 *p;
    s32 i;
    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0x10, 0x30);
    p = gUnk_0202F050;
    i = 0;
    do { gUnk_0202EF80[i] = *p++; i++; } while (i != 0x0A);
    i = 0;
    do { gUnk_0202EF08[i] = *p++; i++; } while (i != 0x04);
    i = 0;
    do { gUnk_0202EF60[i] = *p++; i++; } while (i != 0x10);
    i = 0;
    do { gUnk_0202EEC0[i] = *p++; i++; } while (i != 0x08);
    i = 0;
    do { gUnk_0202EDC8[i] = *p++; i++; } while (i != 0x04);
    i = 0;
    do { gUnk_0202ED80[i] = *p++; i++; } while (i != 0x04);
    sub_080100B0();
}
