#include "global.h"
#include "m4a.h"
#include "functions.h"
#include "variables.h"


void StopAllSongsAndVSyncOff(void)
{
    u8 r4;
    for (r4 = 0; r4 != 100; r4 = (u8)(r4 + 1))
        m4aSongNumStop(r4);
    m4aSoundVSyncOff();
}

void StopAllSongs(void)
{
    u8 i;

    for (i = 0; i != 100; i++)
        m4aSongNumStop(i);
}

void StartMenuMusic(void)
{
    if (gOptions[2] != 0)
        m4aSongNumStart(2);
    m4aSoundVSyncOn();
}
