#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

extern u32 gUnk_083FDD48[];
extern u8 gUnk_083FDD34[];


u8 sub_080128E0(void)
{
    u8 *p;

    gNumLaps = 2;
    gUnk_0202ED84 = gUnk_083FDD48[gUnk_0202EDD8];
    gTrackId = gUnk_083FDD34[gUnk_0202EDD8];
    gUnk_0202EEE4 = 0;
    gCars[0].unk16C = 0;
    gCars[0].unk7D = 1;
    AssignRandomDrivers();
    sub_08016D28(1);
    SortCarsByTime();
    TrackSelectMenu(0, gTrackId);
    p = gUnk_0202CDA8;
    /* RunRace: the ROM caller passes a third argument the matched definition drops; call
       through a function pointer with the old prototype. */
    ((u8 (*)(u8, u8, void *))RunRace)(0, 0x0D, p);
    if (gOptions[2] != 0)
        m4aSongNumStart(3);
    ResetBgScroll();
    /* sub_08012874: old prototype took u8; the matched definition takes s8 */
    ((void (*)(u8))sub_08012874)(gUnk_0202EEE4);
    return gUnk_0202EEE4;
}
