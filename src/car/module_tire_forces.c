#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern s32 gUnk_0203DD4C;
extern s32 gUnk_0203DD0C;
extern s32 gUnk_0203DE04;
extern s32 gUnk_0203DCF8;
extern s32 gUnk_0203DE08;
extern s32 gUnk_0203DE0C;
void ModuleAddSkidSmokeTask(u8 a, u8 b);
void ModuleM4aSongNumStart(u16 idx);

void ModuleUpdateTireForces(struct Car *car, u8 carIndex)
{
    s32 *frontGrip, *angle;
    s32 speedFactor, contactSpeed, contactVelX, contactVelZ;

    gUnk_0203DD38 = carIndex;
    ModuleSetTireGrip((u32)car, carIndex);
    if (car == gModule_Cars && (car->tireWear0 > 0x7D000 || car->tireWear1 > 0x7D000 || car->tireWear2 > 0x7D000 ||
                                car->tireWear3 > 0x7D000)) {
        gUnk_0203DD4C = 0x40;
        gUnk_0203DD0C = 0x80;
        gUnk_0203D4E4 = 0x11F40;
        frontGrip = &gUnk_0203DD0C;
    } else {
        speedFactor = -car->speed >> 12;
        if (speedFactor < 0)
            speedFactor = 0;
        if (carIndex != 0 && gModule_IsLinkRace == 0) {
            gUnk_0203DD4C = gUnk_0203D4E0;
            gUnk_0203DD0C = gUnk_0203DDFC;
            gUnk_0203D4E4 = gUnk_0203D4DC;
            frontGrip = &gUnk_0203DD0C;
        } else {
            gUnk_0203DD4C = (gUnk_0203DCF4 * (0xFF - speedFactor) + gUnk_0203D4E0 * speedFactor) >> 8;
            gUnk_0203DD0C = (gUnk_0203DDE4 * (0xFF - speedFactor) + gUnk_0203DDFC * speedFactor) >> 8;
            gUnk_0203D4E4 = gUnk_0203D4DC;
            frontGrip = &gUnk_0203DD0C;
        }
    }
    if (car == gModule_Cars || gModule_IsLinkRace != 0) {
        if (car->onApron != 0) {
            gUnk_0203DD4C >>= 1;
            *frontGrip <<= 1;
            gUnk_0203D4E4 >>= 1;
        }
        if (car->onGrass != 0)
            *frontGrip >>= 1;
    }
    gUnk_0203DE04 = ((car->heading >> 8) - 0x40) & 0xFF;
    gUnk_0203DCF8 = contactSpeed = (*(s16 *)&car->yawRate) << 7;
    gUnk_0203DE08 = (contactVelX = contactSpeed * -gModule_SinTable[((car->heading >> 8) - 0x40) & 0xFF]) >> 8;
    gUnk_0203DE0C = (contactVelZ = contactSpeed * gModule_SinTable[(((car->heading >> 8) - 0x40) & 0xFF) + 0x40]) >> 8;
    if (car->zoneGripFlag != 0) {
        gUnk_0203D51C = car->velX + (contactVelX >> 9);
        gUnk_0203D4F4 = car->velZ + (contactVelZ >> 9);
    } else {
        gUnk_0203D51C = car->velX + (contactVelX >> 8);
        gUnk_0203D4F4 = car->velZ + (contactVelZ >> 8);
    }
    gUnk_0203DDF4 = *frontGrip;
    gUnk_0203DD2C = gUnk_0203DE04;
    gUnk_0203DE10 = ((((car->steerHeading >> 8) - 0x40) & 0xFF) >> 2) << 2;
    ModuleComputeAxleTireForce(0, car);
    if (car->zoneGripFlag != 0) {
        gUnk_0203D51C = car->velX - (gUnk_0203DE08 >> 1);
        gUnk_0203D4F4 = car->velZ - (gUnk_0203DE0C >> 1);
    } else {
        gUnk_0203D51C = car->velX - gUnk_0203DE08;
        gUnk_0203D4F4 = car->velZ - gUnk_0203DE0C;
    }
    gUnk_0203DDF4 = gUnk_0203DD4C;
    gUnk_0203DD2C = (*(angle = &gUnk_0203DE04) + 0x80) & 0xFF;
    gUnk_0203DE10 = *angle & 0xFF;
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
    register s32 m asm("r2");
    register s32 mm asm("r0");
    s32 armAngle;
    s32 t;
    s32 *forcePtr;

    cos = gModule_SinTable[((gUnk_0203DE10 + 0x40) & 0xFF) + 0x40];
    sin = gModule_SinTable[(gUnk_0203DE10 + 0x40) & 0xFF];
    lateralVel = cos * gUnk_0203D51C + sin * gUnk_0203D4F4;
    slipSpeed = lateralVel >> 8;
    if (axle != 0) {
        if (gModule_DamagePitsEnabled != 0) {
            car->tireWear0 += ((lateralVel >> 17) < 0 ? -(lateralVel >> 17) : (lateralVel >> 17));
            car->tireWear1 += ((lateralVel >> 17) < 0 ? -(lateralVel >> 17) : (lateralVel >> 17));
        }
        if (slipSpeed < -gUnk_0203D4E4) {
            slipSpeed = -gUnk_0203D4E4 / 2;
            ModuleAddSkidSmokeTask(gUnk_0203DD38, 2);
            if (gModule_IsLinkRace == 0) {
                if (gUnk_0203DD38 == 0)
                    goto e2check;
                goto tail;
            }
            if (gUnk_0203DD38 != gModule_LinkPlayerId)
                goto tail;
        } else if (slipSpeed > gUnk_0203D4E4) {
            slipSpeed = gUnk_0203D4E4 / 2;
            ModuleAddSkidSmokeTask(gUnk_0203DD38, 3);
            if (gModule_IsLinkRace == 0) {
                if (gUnk_0203DD38 == 0)
                    goto e2check;
                goto tail;
            }
            if (gUnk_0203DD38 != gModule_LinkPlayerId)
                goto tail;
        } else {
            goto tail;
        }
    e2check:
        if (gModule_Options[3] != 0 && gModule_IsDemo[0] == 0 && gModule_RaceEndState == 0)
            ModuleM4aSongNumStart(0xB);
    } else {
        if (gModule_DamagePitsEnabled != 0) {
            car->tireWear2 += ((lateralVel >> 17) < 0 ? -(lateralVel >> 17) : (lateralVel >> 17));
            car->tireWear3 += ((lateralVel >> 17) < 0 ? -(lateralVel >> 17) : (lateralVel >> 17));
        }
    }
tail:
    m = slipSpeed * gUnk_0203DDF4;
    m >>= 8;
    m = -m;
    forcePtr = &car->forceX;
    *forcePtr += (m * cos) >> 8;
    forcePtr = &car->forceZ;
    *forcePtr += (sin * m) >> 8;
    armAngle = gUnk_0203DE10;
    armAngle += 0x40;
    armAngle -= gUnk_0203DD2C;
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
