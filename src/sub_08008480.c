#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern s32 gTireGrip;
extern s32 gUnk_0202CAEC;
extern s32 gUnk_0202CBE4;
extern s32 gUnk_0202CAD8;
extern s32 gUnk_0202CBE8;
extern s32 gUnk_0202CBEC;


void sub_08008480(struct Car *car, u8 b)
{
    s32 *caec, *cbe4;
    s32 t, spd, v1, v2;

    gCurrentCarIndex = b;
    sub_080083C0((u32)car, b);
    if (car == gCars
        && (car->tireWear0 > 0x7D000 || car->tireWear1 > 0x7D000
            || car->tireWear2 > 0x7D000 || car->tireWear3 > 0x7D000)) {
        gTireGrip = 0x40;
        gUnk_0202CAEC = 0x80;
        gTireSlipLimit = 0x11F40;
        caec = &gUnk_0202CAEC;
    } else {
        t = -car->speed >> 12;
        if (t < 0)
            t = 0;
        if (b != 0 && gIsLinkRace == 0) {
            gTireGrip = gTireGripFast;
            gUnk_0202CAEC = gFrontTireGripFast;
            gTireSlipLimit = gTireSlipLimitBase;
            caec = &gUnk_0202CAEC;
        } else {
            gTireGrip = (gTireGripSlow * (0xFF - t) + gTireGripFast * t) >> 8;
            gUnk_0202CAEC = (gFrontTireGripSlow * (0xFF - t) + gFrontTireGripFast * t) >> 8;
            gTireSlipLimit = gTireSlipLimitBase;
            caec = &gUnk_0202CAEC;
        }
    }
    if (car == gCars || gIsLinkRace != 0) {
        if (car->onApron != 0) {
            gTireGrip >>= 1;
            *caec <<= 1;
            gTireSlipLimit >>= 1;
        }
        if (car->onGrass != 0)
            *caec >>= 1;
    }
    gUnk_0202CBE4 = ((car->heading >> 8) - 0x40) & 0xFF;
    gUnk_0202CAD8 = spd = (*(s16 *)&car->yawRate) << 7;
    gUnk_0202CBE8 = (v1 = spd * -gSinTable[((car->heading >> 8) - 0x40) & 0xFF]) >> 8;
    gUnk_0202CBEC = (v2 = spd * gSinTable[(((car->heading >> 8) - 0x40) & 0xFF) + 0x40]) >> 8;
    if (car->zoneGripFlag != 0) {
        gTireContactVelX = car->velX + (v1 >> 9);
        gTireContactVelZ = car->velZ + (v2 >> 9);
    } else {
        gTireContactVelX = car->velX + (v1 >> 8);
        gTireContactVelZ = car->velZ + (v2 >> 8);
    }
    gUnk_0202CBD4 = *caec;
    gUnk_0202CB0C = gUnk_0202CBE4;
    gTireForceAngle = ((((car->steerHeading >> 8) - 0x40) & 0xFF) >> 2) << 2;
    sub_080087F4(0,(struct Unk080087F4 *)car);
    if (car->zoneGripFlag != 0) {
        gTireContactVelX = car->velX - (gUnk_0202CBE8 >> 1);
        gTireContactVelZ = car->velZ - (gUnk_0202CBEC >> 1);
    } else {
        gTireContactVelX = car->velX - gUnk_0202CBE8;
        gTireContactVelZ = car->velZ - gUnk_0202CBEC;
    }
    gUnk_0202CBD4 = gTireGrip;
    gUnk_0202CB0C = (*(cbe4 = &gUnk_0202CBE4) + 0x80) & 0xFF;
    gTireForceAngle = *cbe4 & 0xFF;
    sub_080087F4(1,(struct Unk080087F4 *)car);
    caec = &car->engineForce;
    if (*caec != 0) {
        car->forceX += (*caec >> 8) * gSinTable[*cbe4 + 0x40];
        car->forceZ += (*caec >> 8) * gSinTable[*cbe4];
    }
    if (car->drag != 0) {
        car->forceX -= ((car->drag >> 8) * gSinTable[*cbe4 + 0x40]) >> 4;
        car->forceZ -= ((car->drag >> 8) * gSinTable[*cbe4]) >> 4;
    }
}
