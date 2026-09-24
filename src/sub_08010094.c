#include "global.h"

void m4aSongNumStop(u32 index);

void StopAllSongs(void)
{
    u8 i;

    for (i = 0; i != 100; i++)
        m4aSongNumStop(i);
}
