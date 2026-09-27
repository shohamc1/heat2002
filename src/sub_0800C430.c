/*
 * PARKED (wave 4): rebuild diverges from the ROM (first diff at ROM
 * 0x0800C430: ours pushes {r4,r5,r6,lr} vs ROM {r4-r7,lr}). Dead-agent
 * mid-edit state whose rebuild diverges while a stale .o once matched.
 * Needs re-derivation from the asm before extracting.
 */
#include "global.h"
#include "variables.h"
#include "car.h"


void WorldToCarLocal(s32 *a, s32 b, s32 c, s32 *d);

void sub_0800C430(struct Car *a)
{
    s32 out[2];
    s32 i;
    s32 d;
    struct Car *e = gCars;
    u8 *hitp = &gAiCarAheadSide;
    u8 *hit;

    *hitp = 0;
    gUnk_0202CC2C = 0;
    i = 0;
    if (i == gNumCars[0])
        return;
    hit = hitp;
    do {
        if (a == e)
            continue;
        d = e->posX - a->posX;
        if (d < 0)
            d = -d;
        if (d > 0xFA0000)
            continue;
        d = e->posZ - a->posZ;
        if (d < 0)
            d = -d;
        if (d > 0xFA0000)
            continue;
        WorldToCarLocal(a, e->posX, e->posZ, out);
        if (out[1] > -16)
            continue;
        if (out[0] < -16)
            continue;
        if (out[0] > 16)
            continue;
        if (out[1] > -128)
            gUnk_0202CC2C = 1;
        if (out[1] < -64)
            continue;
        if (out[0] < 0)
            *hit = 1;
        else
            *hit = 2;
    } while (++i, e++, i != gNumCars[0]);
}
