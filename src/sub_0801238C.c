#include "global.h"
#include "variables.h"
extern u8 gUnk_0202EF60[];
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
        gUnk_0202EF80[i] = 1;
        i++;
    } while (i != 0x0A);
    gUnk_0202EF08[0] = 1;
    gUnk_0202EF08[1] = 0;
    gUnk_0202EF08[2] = 0;
    gUnk_0202EF08[3] = 0;
    gUnk_0202EF08[4] = 0;
    i = 0;
    do {
        gUnk_0202EF60[i] |= 0xFF;
        i++;
    } while (i != 0x10);
    gUnk_0202EF80[5] = 0;
    gUnk_0202EF80[3] = 1;
}
