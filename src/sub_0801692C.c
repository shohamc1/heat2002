#include "global.h"
#include "functions.h"
#include "variables.h"
extern u8 gUnk_0202EF60[];
void SaveProgress(void)
{
    u8 *p;
    s32 i;
    StopAllSongsAndVSyncOff();
    p = gUnk_0202F050;
    i = 0;
    do { *p++ = gUnk_0202EF80[i]; i++; } while (i != 0x0A);
    i = 0;
    do { *p++ = gUnk_0202EF08[i]; i++; } while (i != 0x04);
    i = 0;
    do { *p++ = gUnk_0202EF60[i]; i++; } while (i != 0x10);
    i = 0;
    do { *p++ = gUnk_0202EEC0[i]; i++; } while (i != 0x08);
    i = 0;
    do { *p++ = gUnk_0202EDC8[i]; i++; } while (i != 0x04);
    i = 0;
    do { *p++ = gUnk_0202ED80[i]; i++; } while (i != 0x04);
    WriteSaveBlocks(0x10, 0x30);
    sub_080100B0();
}
