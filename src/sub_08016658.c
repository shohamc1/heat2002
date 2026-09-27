#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_0202F020;
extern u16 gUnk_0202F04A[];

struct Car {
    u8 filler0[0x162];
    u8 driverId;
    u16 points;
    u8 filler166[0x16C - 0x166];
    u32 unk16C;
    u8 filler170[400 - 0x170];
};
extern struct Car gCars[];

void SaveSeason(void)
{
    u16 *p;
    s32 i;
    struct Car *q;
    u32 t;

    StopAllSongsAndVSyncOff();
    p = gUnk_0202F04A;
    *p = 1;
    p += 27;
    *p++ = gUnk_0202F020;
    *p++ = (gUnk_0202F024 << 8) | gUnk_0202EEC8;
    *p++ = gUnk_0202F034;
    *p++ = gUnk_0202EDD8;
    q = gCars;
    i = 0;
    do {
        *p++ = q->driverId;
        *p++ = q->points;
        t = q->unk16C;
        *p++ = t >> 16;
        *p++ = t;
        i++;
        q++;
    } while (i != 0x18);
    i = 0;
    do {
        *p++ = gUnk_0202EF20[i];
        i++;
    } while (i != 0x11);
    *p = gUnk_0202EF10;
    WriteSaveBlocks(0x40, 0xF0);
    WriteSaveBlocks(8, 8);
    sub_080100B0();
}
