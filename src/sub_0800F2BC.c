#include "global.h"
#include "functions.h"
#include "variables.h"
extern u8 gChampionshipRequiredFinish[];
extern u8 gChampionshipTeamTiers[];
u8 sub_0800F2BC(u8 a, u8 b)
{
    u8 i;
    if (b >= gChampionshipRequiredFinish[a] - 1) {
        sub_0800F1B4();
        gChampionshipAvailable[a] = 0;
        return 1;
    }
    i = 0;
    do {
        if (b < gChampionshipRequiredFinish[i])
            gChampionshipAvailable[i] = 1;
        i++;
    } while (i != 0x11);
    sub_0800F1D0();
    sub_0800F14C(gChampionshipTeamTiers[a]);
    return 0;
}
