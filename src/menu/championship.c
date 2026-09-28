#include "global.h"
#include "data.h"

#include "variables.h"


u8 FindDriverByTeam(u8 teamId)
{
    u8 driverIdx;

    for (driverIdx = 0; driverIdx != 0x1E; driverIdx++) {
        if (gDriverRoster[driverIdx].teamId == teamId)
            return driverIdx;
    }
    return 0;
}


void UnlockChampionshipTier(u8 tier)
{
    u8 tierVal;
    register u8 tierReg asm("r3");

    tierVal = tier;
    tierReg = tierVal;
    if (tierVal == 0) {
        gChampionshipAvailable[0] = 1;
        gChampionshipAvailable[1] = 1;
        gChampionshipAvailable[2] = 1;
        gChampionshipAvailable[3] = 1;
        gChampionshipAvailable[4] = 1;
        gChampionshipAvailable[5] = 1;
        gChampionshipAvailable[6] = 1;
    }
    if (tierVal == 1) {
        gChampionshipAvailable[7] = tierVal;
        gChampionshipAvailable[8] = tierVal;
        gChampionshipAvailable[9] = tierVal;
        gChampionshipAvailable[10] = tierVal;
        gChampionshipAvailable[11] = tierVal;
    }
    if (tierReg == 2) {
        gChampionshipAvailable[12] = 1;
        gChampionshipAvailable[13] = 1;
        gChampionshipAvailable[14] = 1;
        gChampionshipAvailable[15] = 1;
        gChampionshipAvailable[16] = 1;
    }
}


u32 IsAnyChampionshipTeamAvailable(void)
{
    u8 teamIdx;

    for (teamIdx = 0; teamIdx != 0x11; teamIdx++) {
        if (gChampionshipAvailable[teamIdx] != 0)
            return 1;
    }
    return 0;
}

