#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u8 gPitLaneIndices[];

void sub_08008090(void);

void EnterPit(u8 *r4, u8 r5)
{
    u8 *r1;
    u32 r0;

    if (gGameMode[0] == 3)
        return;
    if (r4[0x175] != 0)
        return;

    if (r4 == (u8 *)gCars) {
        r1 = &gPlayerPittedFlag;
        r0 = 1;
        r1[0] = r0;
    } else {
        *(u32 *)&r4[0x178] = *(u32 *)&r4[0xF0];
        r0 = 0x18F;
        r1 = &r4[r0];
        r0 = (r1[0] = 1);
    }
    r4[0x175] = 1;
    sub_0800BE00(r4, gPitLaneIndices[gTrackId] << 8);
    if (r4 == (u8 *)gCars && gDamagePitsEnabled != 0)
        sub_08008090();
    r4[0x181] = r5;
    gPitStallOccupied[r5] = 1;
}
