#include "global.h"

void m4aSongNumStop(u16 a);
void sub_080017D0(void);

void StopAllSongsAndVSyncOff(void)
{
    u8 r4;
    for (r4 = 0; r4 != 0x64; r4 = (u8)(r4 + 1))
        m4aSongNumStop(r4);
    sub_080017D0();
}

void StopAllSongs(void)
{
    u8 i;

    for (i = 0; i != 100; i++)
        m4aSongNumStop(i);
}
