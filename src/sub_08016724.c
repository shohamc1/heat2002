#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
extern u16 gUnk_0202F080[];
extern u8 gUnk_0202F020;
void LoadSeason(void)
{
    struct Car *q;
    u16 *p;
    u32 t;
    s32 i;
    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0x40, 0xF0);
    p = gUnk_0202F080;
    gUnk_0202F020 = *p++;
    gUnk_0202F024 = *p >> 8;
    gUnk_0202EEC8 = *p++;
    gUnk_0202F034 = *p++;
    gUnk_0202EDD8 = *p++;
    q = gCars;
    i = 0;
    do {
        q->driverId = *p++;
        q->points = *p++;
        q->unk16C = (*p++ << 16);
        q->unk16C |= *p++;
        i++;
        q++;
    } while (i != 0x18);
    i = 0;
    do {
        gUnk_0202EF20[i] = *p++;
        i++;
    } while (i != 0x11);
    gUnk_0202EF10 = *p;
    sub_080100B0();
}
