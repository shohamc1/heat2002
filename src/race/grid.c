#include "global.h"
#include "car.h"
extern u8 gRacePointsTable[];
void UpdateRacePosition(u8 idx);
u32 sub_08007B10(u32 ptr);
#include "variables.h"
/* The 0x1C-byte starting-grid record gUnk_08367A14 holds (origin, step,
   extent). It shared the struct Track tag name with the 0x64-byte track
   record that now lives in include/structs.h, but its layout and stride
   differ, so it keeps a local tag; nothing else uses the array. */
struct TrackGrid {
    /* +0x00 */ u32 unk00;
    /* +0x04 */ u32 unk04;
    /* +0x08 */ u32 unk08;
    /* +0x0C */ u32 unk0C;
    /* +0x10 */ u32 unk10;
    /* +0x14 */ u32 unk14;
    /* +0x18 */ u32 unk18;
};
extern struct TrackGrid gUnk_08367A14[];

void AwardRacePoints(struct Car *a1, u32 a2)
{
    u8 i;
    u8 flag;
    s32 t;

    UpdateRacePosition((u8)a2);
    t = sub_08007B10((u32)a1);
    a1->points = a1->points + gRacePointsTable[(u8)t];
    if (a1->lapsLed != 0)
        a1->points += 5;
    flag = 1;
    for (i = 0; i != 24; i++) {
        if (a1 == &gCars[i])
            continue;
        if (gCars[i].lapsLed <= a1->lapsLed)
            continue;
        flag = 0;
    }
    if (flag != 0)
        a1->points += 10;
}

void BuildStartingGrid(u8 a1)
{
    u32 x = gUnk_08367A14[a1].unk00;
    u32 y = gUnk_08367A14[a1].unk04;
    u32 *p = gUnk_0202A3F0;
    u8 j;

    for (j = 0; j != 12; j++) {
        p[0] = x;
        p[1] = y;
        p[2] = gUnk_08367A14[a1].unk18;
        p += 3;
        p[0] = x + gUnk_08367A14[a1].unk10;
        p[1] = y + gUnk_08367A14[a1].unk14;
        p[2] = gUnk_08367A14[a1].unk18;
        p += 3;
        x += gUnk_08367A14[a1].unk08;
        y += gUnk_08367A14[a1].unk0C;
    }
}
