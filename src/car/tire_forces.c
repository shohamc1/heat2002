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
#include "m4a.h"
void AddSkidSmokeTask(u8 a, u8 b);


void UpdateTireForces(struct Car *car, u8 carIndex)
{
    s32 *frontGrip, *angle;
    s32 speedFactor, contactSpeed, contactVelX, contactVelZ;

    gCurrentCarIndex = carIndex;
    SetTireGrip(car, carIndex);
    if (car == gCars
        && (car->tireWear0 > 0x7D000 || car->tireWear1 > 0x7D000
            || car->tireWear2 > 0x7D000 || car->tireWear3 > 0x7D000)) {
        gTireGrip = 0x40;
        gUnk_0202CAEC = 0x80;
        gTireSlipLimit = 0x11F40;
        frontGrip = &gUnk_0202CAEC;
    } else {
        speedFactor = -car->speed >> 12;
        if (speedFactor < 0)
            speedFactor = 0;
        if (carIndex != 0 && gIsLinkRace == 0) {
            gTireGrip = gTireGripFast;
            gUnk_0202CAEC = gFrontTireGripFast;
            gTireSlipLimit = gTireSlipLimitBase;
            frontGrip = &gUnk_0202CAEC;
        } else {
            gTireGrip = (gTireGripSlow * (0xFF - speedFactor) + gTireGripFast * speedFactor) >> 8;
            gUnk_0202CAEC = (gFrontTireGripSlow * (0xFF - speedFactor) + gFrontTireGripFast * speedFactor) >> 8;
            gTireSlipLimit = gTireSlipLimitBase;
            frontGrip = &gUnk_0202CAEC;
        }
    }
    if (car == gCars || gIsLinkRace != 0) {
        if (car->onApron != 0) {
            gTireGrip >>= 1;
            *frontGrip <<= 1;
            gTireSlipLimit >>= 1;
        }
        if (car->onGrass != 0)
            *frontGrip >>= 1;
    }
    gUnk_0202CBE4 = ((car->heading >> 8) - 0x40) & 0xFF;
    gUnk_0202CAD8 = contactSpeed = (*(s16 *)&car->yawRate) << 7;
    gUnk_0202CBE8 = (contactVelX = contactSpeed * -gSinTable[((car->heading >> 8) - 0x40) & 0xFF]) >> 8;
    gUnk_0202CBEC = (contactVelZ = contactSpeed * gSinTable[(((car->heading >> 8) - 0x40) & 0xFF) + 0x40]) >> 8;
    if (car->zoneGripFlag != 0) {
        gTireContactVelX = car->velX + (contactVelX >> 9);
        gTireContactVelZ = car->velZ + (contactVelZ >> 9);
    } else {
        gTireContactVelX = car->velX + (contactVelX >> 8);
        gTireContactVelZ = car->velZ + (contactVelZ >> 8);
    }
    gUnk_0202CBD4 = *frontGrip;
    gUnk_0202CB0C = gUnk_0202CBE4;
    gTireForceAngle = ((((car->steerHeading >> 8) - 0x40) & 0xFF) >> 2) << 2;
    ComputeAxleTireForce(0, car);
    if (car->zoneGripFlag != 0) {
        gTireContactVelX = car->velX - (gUnk_0202CBE8 >> 1);
        gTireContactVelZ = car->velZ - (gUnk_0202CBEC >> 1);
    } else {
        gTireContactVelX = car->velX - gUnk_0202CBE8;
        gTireContactVelZ = car->velZ - gUnk_0202CBEC;
    }
    gUnk_0202CBD4 = gTireGrip;
    gUnk_0202CB0C = (*(angle = &gUnk_0202CBE4) + 0x80) & 0xFF;
    gTireForceAngle = *angle & 0xFF;
    ComputeAxleTireForce(1, car);
    frontGrip = &car->engineForce;
    if (*frontGrip != 0) {
        car->forceX += (*frontGrip >> 8) * gSinTable[*angle + 0x40];
        car->forceZ += (*frontGrip >> 8) * gSinTable[*angle];
    }
    if (car->drag != 0) {
        car->forceX -= ((car->drag >> 8) * gSinTable[*angle + 0x40]) >> 4;
        car->forceZ -= ((car->drag >> 8) * gSinTable[*angle]) >> 4;
    }
}


void ComputeAxleTireForce(u8 axle, struct Car *car)
{
    s32 cos;
    s32 sin;
    s32 lateralVel;
    s32 slipSpeed;
    s32 idx;
    register s32 m asm("r2");
    register s32 mm asm("r0");
    s32 armAngle;
    s32 t;
    s32 *forcePtr;

    cos = gSinTable[((gTireForceAngle + 0x40) & 0xFF) + 0x40];
    sin = gSinTable[(gTireForceAngle + 0x40) & 0xFF];
    lateralVel = cos * gTireContactVelX + sin * gTireContactVelZ;
    slipSpeed = lateralVel >> 8;
    if (axle != 0) {
        if (gDamagePitsEnabled != 0) {
            car->tireWear0 += ((lateralVel >> 17) < 0 ? -(lateralVel >> 17) : (lateralVel >> 17));
            car->tireWear1 += ((lateralVel >> 17) < 0 ? -(lateralVel >> 17) : (lateralVel >> 17));
        }
        if (slipSpeed < -gTireSlipLimit) {
            slipSpeed = -gTireSlipLimit / 2;
            AddSkidSmokeTask(gCurrentCarIndex, 2);
            if (gIsLinkRace == 0) {
                if (gCurrentCarIndex == 0)
                    goto e2check;
                goto tail;
            }
            if (gCurrentCarIndex != gLinkPlayerId[0])
                goto tail;
        } else if (slipSpeed > gTireSlipLimit) {
            slipSpeed = gTireSlipLimit / 2;
            AddSkidSmokeTask(gCurrentCarIndex, 3);
            if (gIsLinkRace == 0) {
                if (gCurrentCarIndex == 0)
                    goto e2check;
                goto tail;
            }
            if (gCurrentCarIndex != gLinkPlayerId[0])
                goto tail;
        } else {
            goto tail;
        }
e2check:
        if (gOptions[3] != 0 && gIsDemo == 0 && gRaceEndState == 0)
            m4aSongNumStart(0xB);
    } else {
        if (gDamagePitsEnabled != 0) {
            car->tireWear2 += ((lateralVel >> 17) < 0 ? -(lateralVel >> 17) : (lateralVel >> 17));
            car->tireWear3 += ((lateralVel >> 17) < 0 ? -(lateralVel >> 17) : (lateralVel >> 17));
        }
    }
tail:
    m = slipSpeed * gUnk_0202CBD4;
    m >>= 8;
    m = -m;
    forcePtr = &car->forceX;
    *forcePtr += (m * cos) >> 8;
    forcePtr = &car->forceZ;
    *forcePtr += (sin * m) >> 8;
    armAngle = gTireForceAngle;
    armAngle += 0x40;
    armAngle -= gUnk_0202CB0C;
    armAngle &= 0xFF;
    mm = gSinTable[armAngle] * m;
    m = mm >> 8;
    m <<= 7;
    t = m;
    if (m < 0)
        t = m + 0x7FFF;
    m = t >> 15;
    if (car->torqueDampTimer != 0) {
        car->torqueDampTimer--;
        car->torque += t >> 16;
    } else {
        car->torque += m;
    }
}

