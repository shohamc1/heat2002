#include "global.h"
#include "variables.h"


void sub_0800F14C(u8 param)
{
    u8 v;
    register u8 w asm("r3");

    v = param;
    w = v;
    if (v == 0) {
        gChampionshipAvailable[0] = 1;
        gChampionshipAvailable[1] = 1;
        gChampionshipAvailable[2] = 1;
        gChampionshipAvailable[3] = 1;
        gChampionshipAvailable[4] = 1;
        gChampionshipAvailable[5] = 1;
        gChampionshipAvailable[6] = 1;
    }
    if (v == 1) {
        gChampionshipAvailable[7] = v;
        gChampionshipAvailable[8] = v;
        gChampionshipAvailable[9] = v;
        gChampionshipAvailable[10] = v;
        gChampionshipAvailable[11] = v;
    }
    if (w == 2) {
        gChampionshipAvailable[12] = 1;
        gChampionshipAvailable[13] = 1;
        gChampionshipAvailable[14] = 1;
        gChampionshipAvailable[15] = 1;
        gChampionshipAvailable[16] = 1;
    }
}
