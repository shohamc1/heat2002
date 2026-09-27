#include "global.h"
#include "variables.h"
void InitNewSaveData(void)
{
    u8 i;
    gOptions[0] = 0;
    gOptions[1] = 1;
    gOptions[2] = 1;
    gOptions[3] = 1;
    gOptions[5] = 1;
    gOptions[4] = 0;
    i = 0;
    do {
        gProgressFlags[i] = 1;
        i++;
    } while (i != 0x0A);
    gChallengeCategoryUnlocked[0] = 1;
    gChallengeCategoryUnlocked[1] = 0;
    gChallengeCategoryUnlocked[2] = 0;
    gChallengeCategoryUnlocked[3] = 0;
    gChallengeCategoryUnlocked[4] = 0;
    i = 0;
    do {
        gChallengeStatus[i] |= 0xFF;
        i++;
    } while (i != 0x10);
    gProgressFlags[5] = 0;
    gProgressFlags[3] = 1;
}
