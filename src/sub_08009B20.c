#include "global.h"

extern u8 gNumCars[];
extern u8 gIsLinkRace;
extern u8 gNumLinkPlayers[];

struct Standing {
    u8 pad0[0x50];
    s32 progress;
    u8 pad54[0xFC];
    u8 racePosition;
    u8 pad151[0x3F];
};

extern struct Standing gCars[];

void UpdateRacePosition(u8 idx)
{
    u8 n = gNumCars[0];
    u8 count;
    s32 threshold;
    u32 j;

    if (gIsLinkRace != 0)
        n = gNumLinkPlayers[0];
    count = 0;
    threshold = gCars[idx].progress;
    for (j = 0; j != n; j++) {
        if (j != idx && gCars[j].progress > threshold)
            count++;
    }
    gCars[idx].racePosition = count;
}
