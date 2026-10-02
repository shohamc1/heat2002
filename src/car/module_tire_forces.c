#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern s32 gModule_TireGrip;
extern s32 gModule_FrontTireGrip;
extern s32 gModule_CarHeadingAngle;
extern s32 gModule_YawContactSpeed;
extern s32 gModule_YawContactVelX;
extern s32 gModule_YawContactVelZ;

void ModuleUpdateTireForces(struct Car *car, u8 carIndex)
{
    s32 *frontGrip, *angle;
    s32 speedFactor, contactSpeed, contactVelX, contactVelZ;

    gModule_CurrentCarIndex = carIndex;
    ModuleSetTireGrip(car, carIndex);
    if (car == gModule_Cars && (car->tireWear0 > 0x7D000 || car->tireWear1 > 0x7D000 || car->tireWear2 > 0x7D000 ||
                                car->tireWear3 > 0x7D000)) {
        gModule_TireGrip = 0x40;
        gModule_FrontTireGrip = 0x80;
        gModule_TireSlipLimit = 0x11F40;
        frontGrip = &gModule_FrontTireGrip;
    } else {
        speedFactor = -car->speed >> 12;
        if (speedFactor < 0)
            speedFactor = 0;
        if (carIndex != 0 && gModule_IsLinkRace == 0) {
            gModule_TireGrip = gModule_TireGripFast;
            gModule_FrontTireGrip = gModule_FrontTireGripFast;
            gModule_TireSlipLimit = gModule_TireSlipLimitBase;
            frontGrip = &gModule_FrontTireGrip;
        } else {
            gModule_TireGrip = (gModule_TireGripSlow * (0xFF - speedFactor) + gModule_TireGripFast * speedFactor) >> 8;
            gModule_FrontTireGrip = (gModule_FrontTireGripSlow * (0xFF - speedFactor) + gModule_FrontTireGripFast * speedFactor) >> 8;
            gModule_TireSlipLimit = gModule_TireSlipLimitBase;
            frontGrip = &gModule_FrontTireGrip;
        }
    }
    if (car == gModule_Cars || gModule_IsLinkRace != 0) {
        if (car->onApron != 0) {
            gModule_TireGrip >>= 1;
            *frontGrip <<= 1;
            gModule_TireSlipLimit >>= 1;
        }
        if (car->onGrass != 0)
            *frontGrip >>= 1;
    }
    gModule_CarHeadingAngle = ((car->heading >> 8) - 0x40) & 0xFF;
    gModule_YawContactSpeed = contactSpeed = (s16)car->yawRate << 7;
    gModule_YawContactVelX = (contactVelX = contactSpeed * -gModule_SinTable[((car->heading >> 8) - 0x40) & 0xFF]) >> 8;
    gModule_YawContactVelZ = (contactVelZ = contactSpeed * gModule_SinTable[(((car->heading >> 8) - 0x40) & 0xFF) + 0x40]) >> 8;
    if (car->zoneGripFlag != 0) {
        gModule_TireContactVelX = car->velX + (contactVelX >> 9);
        gModule_TireContactVelZ = car->velZ + (contactVelZ >> 9);
    } else {
        gModule_TireContactVelX = car->velX + (contactVelX >> 8);
        gModule_TireContactVelZ = car->velZ + (contactVelZ >> 8);
    }
    gModule_AxleTireGrip = *frontGrip;
    gModule_AxleCarAngle = gModule_CarHeadingAngle;
    gModule_TireForceAngle = ((((car->steerHeading >> 8) - 0x40) & 0xFF) >> 2) << 2;
    ModuleComputeAxleTireForce(0, car);
    if (car->zoneGripFlag != 0) {
        gModule_TireContactVelX = car->velX - (gModule_YawContactVelX >> 1);
        gModule_TireContactVelZ = car->velZ - (gModule_YawContactVelZ >> 1);
    } else {
        gModule_TireContactVelX = car->velX - gModule_YawContactVelX;
        gModule_TireContactVelZ = car->velZ - gModule_YawContactVelZ;
    }
    gModule_AxleTireGrip = gModule_TireGrip;
    gModule_AxleCarAngle = (*(angle = &gModule_CarHeadingAngle) + 0x80) & 0xFF;
    gModule_TireForceAngle = *angle & 0xFF;
    ModuleComputeAxleTireForce(1, car);
    frontGrip = &car->engineForce;
    if (*frontGrip != 0) {
        car->forceX += (*frontGrip >> 8) * gModule_SinTable[*angle + 0x40];
        car->forceZ += (*frontGrip >> 8) * gModule_SinTable[*angle];
    }
    if (car->drag != 0) {
        car->forceX -= ((car->drag >> 8) * gModule_SinTable[*angle + 0x40]) >> 4;
        car->forceZ -= ((car->drag >> 8) * gModule_SinTable[*angle]) >> 4;
    }
}

void ModuleComputeAxleTireForce(u8 axle, struct Car *car)
{
    s32 cos;
    s32 sin;
    s32 lateralVel;
    s32 slipSpeed;
    s32 idx;
    register s32 m PIN(r2);
    register s32 mm PIN(r0);
    s32 armAngle;
    s32 t;
    s32 *forcePtr;

    cos = gModule_SinTable[((gModule_TireForceAngle + 0x40) & 0xFF) + 0x40];
    sin = gModule_SinTable[(gModule_TireForceAngle + 0x40) & 0xFF];
    lateralVel = cos * gModule_TireContactVelX + sin * gModule_TireContactVelZ;
    slipSpeed = lateralVel >> 8;
    if (axle != 0) {
        if (gModule_DamagePitsEnabled != 0) {
            car->tireWear0 += ABS2(lateralVel >> 17);
            car->tireWear1 += ABS2(lateralVel >> 17);
        }
        if (slipSpeed < -gModule_TireSlipLimit) {
            slipSpeed = -gModule_TireSlipLimit / 2;
            ModuleAddSkidSmokeTask(gModule_CurrentCarIndex, 2);
            if (gModule_IsLinkRace == 0) {
                if (gModule_CurrentCarIndex == 0)
                    goto e2check;
                goto tail;
            }
            if (gModule_CurrentCarIndex != gModule_LinkPlayerId)
                goto tail;
        } else if (slipSpeed > gModule_TireSlipLimit) {
            slipSpeed = gModule_TireSlipLimit / 2;
            ModuleAddSkidSmokeTask(gModule_CurrentCarIndex, 3);
            if (gModule_IsLinkRace == 0) {
                if (gModule_CurrentCarIndex == 0)
                    goto e2check;
                goto tail;
            }
            if (gModule_CurrentCarIndex != gModule_LinkPlayerId)
                goto tail;
        } else {
            goto tail;
        }
    e2check:
        if (gModule_Options[3] != 0 && gModule_IsDemo == 0 && gModule_RaceEndState == 0)
            ModuleM4aSongNumStart(11);
    } else {
        if (gModule_DamagePitsEnabled != 0) {
            car->tireWear2 += ABS2(lateralVel >> 17);
            car->tireWear3 += ABS2(lateralVel >> 17);
        }
    }
tail:
    m = slipSpeed * gModule_AxleTireGrip;
    m >>= 8;
    m = -m;
    forcePtr = &car->forceX;
    *forcePtr += (m * cos) >> 8;
    forcePtr = &car->forceZ;
    *forcePtr += (sin * m) >> 8;
    armAngle = gModule_TireForceAngle;
    armAngle += 0x40;
    armAngle -= gModule_AxleCarAngle;
    armAngle &= 0xFF;
    mm = gModule_SinTable[armAngle] * m;
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
