#include "global.h"
#include "functions.h"
#include "m4a.h"

struct Unk0202A550
{
    u8 filler0[0x7D];
    u8 unk7D;
    u8 filler7E[0x16C - 0x7E];
    u32 unk16C;
    u8 filler170[400 - 0x170];
};

extern u8 gNumLaps;
extern u32 gUnk_0202ED84;
extern u32 gUnk_083FDD48[];
extern u8 gUnk_0202EDD8;
extern u8 gTrackId;
extern u8 gUnk_083FDD34[];
extern u8 gUnk_0202EEE4;
extern struct Unk0202A550 gCars[];
extern u8 gUnk_0202CDA8[];
extern u8 gOptions[];


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
